#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/time.h>

/* Сущности мира */
typedef enum _entity_t {
    entity_dead,
    entity_live,
    entity_was_live,
    entity_was_dead
} entity_t;

/* Типы очистки экрана */
typedef enum _clear_render_t {
    // Очистка терминала, без очистки истории прокрутки (не требует дополнительных разрешений).
    clear_render_screen,
    // Очистка терминала и истории прокрутки (требует дополнительные разрешения).
    clear_render_screen_and_scroll,
} clear_render_t;

/* Мир */
typedef entity_t** world_t;

bool is_keyof_quit(char c);
bool is_keyof_toggle_pause(char c);
bool is_keyof_toggle_clear_mode(char c);
bool is_keyof_speed_up(char c);
bool is_keyof_speed_down(char c);

long long current_timestamp();
int clamp(int value, int min, int max);
void repeatchar(char c, int count);
int is_whitespace(char c);

bool is_entity_dead(entity_t entity);
bool is_entity_live(entity_t entity);
int entity_live_around(world_t world, int width, int height, int x, int y);
void entity_step(world_t world, int width, int height, int x, int y);

void world_step_begin(world_t world, int width, int height);
int world_step_end(world_t world, int width, int height);

bool world_equals(world_t a, world_t b, int width, int height);
void world_copy(world_t src, world_t dist, int width, int height);
void world_fill_random(world_t world, int width, int height);
void world_fill(world_t world, int width, int height, entity_t entity);
int world_step_delay_calc(int percent, int min, int max);
bool is_world_empty(world_t world, int width, int height);

world_t alloc_world(int width, int height);

world_t *alloc_history(int width, int height, int length);
void free_history(world_t *history, int length);
world_t shift_history(world_t *history, int width, int height, int length);

void draw_entity(entity_t entity);
void draw_world(world_t world, int width, int height, char *game_ower_message);
void clear_render(clear_render_t method);

bool load_world(int argc, char **argv, world_t world, int width, int height);
bool load_world_from_file(FILE *fp, world_t world, int width, int height);

void kbhit_reset();
int kbhit();

int main(int argc, char **argv) {
    const int WORLD_WIDTH = 80;
    const int WORLD_HEIGHT = 25;
    const int WORLD_HISTORY_LENGTH = 11;
    const int WORLD_STEP_DELAY_MS_MIN = 10;
    const int WORLD_STEP_DELAY_MS_MAX = 1500;
    const int WORLD_HISTORY_COMPARE_COUNTER_MAX = 100;

    const int WORLD_EQUALS_COUNTER_MAX = clamp(WORLD_HISTORY_LENGTH / 3, 1, WORLD_HISTORY_LENGTH);
    const bool INTERACTIVE_ENABLED = !kbhit();
    if (!INTERACTIVE_ENABLED) kbhit_reset();

    bool game_live = true;
    bool game_paused = false;
    char *game_ower_message = NULL;

    bool need_render = true;
    bool need_world_step = false;
    clear_render_t render_clear_method = clear_render_screen;

    long long world_stepped_at = current_timestamp() + 500;
    int world_step_speed_percent = 92;
    int world_step_delay = world_step_delay_calc(
        world_step_speed_percent,
        WORLD_STEP_DELAY_MS_MIN,
        WORLD_STEP_DELAY_MS_MAX);

    world_t *history = NULL;
    world_t world = NULL;

    int history_compare_counter = WORLD_HISTORY_LENGTH * -2;

    // game_live = (WORLD_WIDTH >= 3 && WORLD_HEIGHT >= 3); // For dynamic size.

    if (game_live) {
        history = alloc_history(WORLD_WIDTH, WORLD_HEIGHT, WORLD_HISTORY_LENGTH);
        if (history != NULL) {
            world = history[0];
            if (!load_world(argc, argv, world, WORLD_WIDTH, WORLD_HEIGHT)) {
                world_fill_random(world, WORLD_WIDTH, WORLD_HEIGHT);
            }
        }
        game_live = (world != NULL);
    }

    srand(time(NULL));
    while (game_live) {
        if (current_timestamp() - world_stepped_at >= world_step_delay) {
            need_world_step = true;
        }

        if (!game_paused && need_world_step) {
            need_world_step = false;
            world_stepped_at = current_timestamp();
            world_step_begin(world, WORLD_WIDTH, WORLD_HEIGHT);
            world_step_end(world, WORLD_WIDTH, WORLD_HEIGHT);

            if (is_world_empty(world, WORLD_WIDTH, WORLD_HEIGHT)) {
                game_live = false;
                game_ower_message = "Game Over! All entities are dead.";
            } else if (history_compare_counter < 0) {
                history_compare_counter += 1;
            } else {
                int world_equals_counter = 0;
                for (int i = 1; i < WORLD_HISTORY_LENGTH; i++) {
                    if (world_equals(world, history[i], WORLD_WIDTH, WORLD_HEIGHT)) {
                        world_equals_counter += 1;
                    }
                }
                if (world_equals_counter > WORLD_EQUALS_COUNTER_MAX) {
                    history_compare_counter += 1;
                } else {
                    history_compare_counter = 0;
                }
            }

            world = shift_history(history, WORLD_WIDTH, WORLD_HEIGHT, WORLD_HISTORY_LENGTH);
            need_render = true;
        }

        if (game_live && history_compare_counter > WORLD_HISTORY_COMPARE_COUNTER_MAX) {
            game_live = false;
            game_ower_message = "Game Over! Life is cyclical.";
        }

        if (need_render) {
            need_render = false;
            clear_render(render_clear_method);

            printf(" Speed: %d%%  ", world_step_speed_percent);
            if (render_clear_method == clear_render_screen) {
                printf("Clear: Screen");
            } else if (render_clear_method == clear_render_screen_and_scroll) {
                printf("Clear: Screen & Scroll");
            } else {
                printf("Clear: ???");
            }

            putchar('\n');
            repeatchar('-', WORLD_WIDTH);
            putchar('\n');

            draw_world(world, WORLD_WIDTH, WORLD_HEIGHT, game_ower_message);

            putchar('\n');
            repeatchar('-', WORLD_WIDTH);
            putchar('\n');

            if (INTERACTIVE_ENABLED) {
                printf(" [Q] Quit  %s  [-/+] Speed Up/Down  [M] Clear Screen Method\n",
                    game_paused ? "[P] Resume" : "[P] Pause");
            } else {
                printf(" [Ctrl+C] Quit | Interactive disabled in input redirection mode! (Use args)\n");
            }
        }

        if (INTERACTIVE_ENABLED && kbhit()) {
            char c = getchar();
            if (is_keyof_quit(c)) {
                // Quit: Выход из игры
                game_live = 0;
            } else if (is_keyof_toggle_pause(c)) {
                // Pause: Пауза развития мира
                game_paused = !game_paused;
                need_render = true;
            } else if (is_keyof_toggle_clear_mode(c)) {
                // ToggleClearMethod: Изменение способа очистки экрана
                if (render_clear_method == clear_render_screen) {
                    render_clear_method = clear_render_screen_and_scroll;
                } else {
                    render_clear_method = clear_render_screen;
                }
                need_render = true;
            } else if (is_keyof_speed_up(c)) {
                // SpeedUp: Увеличени скорости мира
                world_step_speed_percent = clamp(world_step_speed_percent + 2, 1, 100);
                world_step_delay = world_step_delay_calc(
                    world_step_speed_percent, WORLD_STEP_DELAY_MS_MIN, WORLD_STEP_DELAY_MS_MAX);
                need_render = true;
            } else if (is_keyof_speed_down(c)) {
                // SpeedDown: Уменьшение скорости мира
                world_step_speed_percent = clamp(world_step_speed_percent - 2, 1, 100);
                world_step_delay = world_step_delay_calc(
                    world_step_speed_percent, WORLD_STEP_DELAY_MS_MIN, WORLD_STEP_DELAY_MS_MAX);
                need_render = true;
            }
        }
    }

    world = NULL;
    free_history(history, WORLD_HISTORY_LENGTH);
    history = NULL;

    return 0;
}

/**
 * Проверяет, является ли символ клавишей выхода (Q).
 */
bool is_keyof_quit(char c) {
    return c == 'q' || c == 'Q';
}

/**
 * Проверяет, является ли символ клавишей паузы (P).
 */
bool is_keyof_toggle_pause(char c) {
    return c == 'p' || c == 'P';
}

/**
 * Проверяет, является ли символ клавишей переключения режима очистки (M).
 */
bool is_keyof_toggle_clear_mode(char c) {
    return c == 'm' || c == 'M';
}

/**
 * Проверяет, является ли символ клавишей увеличения скорости (+).
 */
bool is_keyof_speed_up(char c) {
    return c == '=' || c == '+';
}

/**
 * Проверяет, является ли символ клавишей уменьшения скорости (-).
 */
bool is_keyof_speed_down(char c) {
    return c == '-' || c == '_';
}

/**
 * Возвращает текущее время в миллисекундах.
 */
long long current_timestamp() {
    struct timeval ctime;
    gettimeofday(&ctime, NULL);
    long long milliseconds = ctime.tv_sec * 1000LL + ctime.tv_usec / 1000;
    return milliseconds;
}

/**
 * Возвращает 'value', ограниченное диапазоном от 'min' до 'max' включительно.
 * Пример: clamp(-10, 1, 100) // result 1
 */
int clamp(int value, int min, int max) {
    return value < min ? min : (value > max ? max : value);
}

/**
 * Повторяет вывод символа указанное колличество раз.
 */
void repeatchar(char c, int count) {
    if (count > 0) while (count-- > 0) putchar(c);
}

/**
 * Проверяет, является ли символ пробелом (возвратом каретки, переносом строки,
 * обрывом страницы, табуляцией, вертикальной табуляцией).
 */
int is_whitespace(char c) {
    return (c == ' ' || c == '\r' || c == '\n' || c == '\f' || c == '\t' || c == '\v');
}

/**
 * Если сущность мертва или была мертва в текущем цикле (оживёт в конце цикла),
 * то возвращает 'true', иначе 'false'.
 */
bool is_entity_dead(entity_t entity) {
    return entity == entity_dead || entity == entity_was_dead;
}

/**
 * Если сущность жива или была жива в текущем цикле (умрёт в конце цикла),
 * то возвращает 'true', иначе 'false'.
 */
bool is_entity_live(entity_t entity) {
    return entity == entity_live || entity == entity_was_live;
}

/**
 * Возвращает количество живых сущностей вокруг заданной.
 * (Алгоритм с замкнутым/цикличным полем)
 */
int entity_live_around(world_t world, int width, int height, int x, int y) {
    int count = 0;
    for (int ty = y - 1, h = y + 1; ty <= h; ty++) {
        for (int tx = x - 1, w = x + 1; tx <= w; tx++) {
            int ry = ty < 0 ? height - 1 : (ty > height - 1 ? 0 : ty);
            int rx = tx < 0 ? width - 1 : (tx > width - 1 ? 0 : tx);
            if ((ry != y || rx != x) && is_entity_live(world[ry][rx])) {
                count += 1;
            }
        }
    }
    return count;
}

/**
 * Сущность совершает свой следующий шаг в жизненном цикле.
 * Если жизнь сущности изменилась, то ячейка помечается для изменений в конце цикла,
 * но всё ещё продолжает своё существование до окончания расчетов.
 */
void entity_step(world_t world, int width, int height, int x, int y) {
    int live_around = entity_live_around(world, width, height, x, y);
    entity_t entity = world[y][x];
    if (is_entity_live(entity)) {
        // - Любая живая клетка с двумя-тремя живыми соседями живет до следующего поколения.
        // - Любая живая клетка с более чем тремя живыми соседями умирает.
        // - Любая живая клетка с менее чем двумя живыми соседями умирает.
        if (live_around > 3 || live_around < 2) {
            world[y][x] = entity_was_live;
        }
    } else if (is_entity_dead(entity)) {
        // - Любая мертвая клетка, имеющая ровно три живых соседа, становится живой клеткой.
        if (live_around == 3) {
            world[y][x] = entity_was_dead;
        }
    }
}

/**
 * Начало очередного жизненного цикла мира.
 */
void world_step_begin(world_t world, int width, int height) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            entity_step(world, width, height, x, y);
        }
    }
}

/**
 * Завершение текущего жизненного цикла мира.
 * Перевод сущностей из временного состояния в постоянное.
 */
int world_step_end(world_t world, int width, int height) {
    int entities_changed = 0;
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            switch (world[y][x]) {
                case entity_was_live:
                    world[y][x] = entity_dead;
                    entities_changed++;
                    break;
                case entity_was_dead:
                    world[y][x] = entity_live;
                    entities_changed++;
                    break;
                default: break;
            }
        }
    }
    return entities_changed;
}

/**
 * Проверяет, равны ли миры друг другу (равны ли все сущности одного мира другому).
 */
bool world_equals(world_t a, world_t b, int width, int height) {
    int result = true;
    for (int y = 0; result && y < height; y++)
        for (int x = 0; result && x < width; x++)
            if (a[y][x] != b[y][x])
                result = false;
    return result;
}

/**
 * Копирует сущности мира 'src' в мир 'dist'.
 */
void world_copy(world_t src, world_t dist, int width, int height) {
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            dist[y][x] = src[y][x];
}

/**
 * Заполняет мир случайной жизнью.
 */
void world_fill_random(world_t world, int width, int height) {
    for (int y = 0; y < height; y++)
        for (int x = 0; x < width; x++)
            world[y][x] = rand() % 2 ? entity_live : entity_dead;
}

/**
 * Заполняет мир заданной сущностью.
 */
void world_fill(world_t world, int width, int height, entity_t entity) {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            world[y][x] = entity;
        }
    }
}

/**
 * Рассчитывает задержку в миллисекундах, относительно
 * процента от минимального и максимального значения.
 */
int world_step_delay_calc(int percent, int min, int max) {
    return min + ((max - min) * clamp(100 - percent, 0, 100) / 100);
}

/**
 * Если в мире нет жизни, возвращает 'true', иначе 'false'.
 */
bool is_world_empty(world_t world, int width, int height) {
    int result = true;
    for (int y = 0; result && y < height; y++)
        for (int x = 0; result && x < width; x++)
            result = !is_entity_live(world[y][x]);
    return result;
}

/**
 * Выделяет единый блок памяти на мир, размером 'width * height'.
 * В случае ошибки возвращает NULL.
 * Память освобождается одним вызовом free().
 */
world_t alloc_world(int width, int height) {
    world_t world = malloc(height * sizeof(entity_t*) + width * height * sizeof(entity_t));
    if (world != NULL) {
        entity_t *values = (entity_t*)(world + height);
        for (long int i = 0; i < height; i++)
            world[i] = values + i * width;
    }
    return world;
}

/**
 * Выделяет блок памяти размером 'length' с массивом миров 'width * height',
 * для хранения цикличной истории мира.
 * В случае ошибки возвращает NULL и освобождает занятую память.
 * Память освобождается одним вызовом free_history().
 */
world_t *alloc_history(int width, int height, int length) {
    world_t *history = NULL;
    if (length >= 1) {
        history = (world_t*)malloc(length * sizeof(world_t*));
        for (int i = 0; history != NULL && i < length; i++) {
            history[i] = alloc_world(width, height);
            if (history[i] != NULL) {
                world_fill(history[i], width, height, entity_dead);
            } else {
                for (int d = 0; d < i; d++)
                    free(history[d]);
                free(history);
                history = NULL;
            }
        }
    }
    return history;
}

/**
 * Освобождает память с массивом истории мира.
 */
void free_history(world_t *history, int length) {
    if (history != NULL) {
        for (int i = 0; i < length; i++) {
            free(history[i]);
            history[i] = NULL;
        }
        free(history);
    }
}

/**
 * Циклично смещает историю мира, сдвигая все элементы в сторону конца массива.
 * Перемещает последний элемент массива в начало (самое старое состояние мира).
 * Копирует предыдущее состояние мира в текущее, для продолжения жизни.
 */
world_t shift_history(world_t *history, int width, int height, int length) {
    if (length >= 2) {
        world_t last = history[length - 1];
        world_copy(history[0], last, width, height);
        for (int i = length - 1; i > 0; i--)
            history[i] = history[i - 1];
        history[0] = last;
    }
    return history[0];
}

/**
 * Выводит символ сущности в терминал (живой, мертвый (, переходные состояни равны новому циклу)).
 */
void draw_entity(entity_t entity) {
    const char entity_dead_char = ' ';
    const char entity_live_char = '0';
    switch (entity) {
        case entity_dead: putchar(entity_dead_char); break;
        case entity_live: putchar(entity_live_char); break;
        case entity_was_live: putchar(entity_dead_char); break;
        case entity_was_dead: putchar(entity_live_char); break;
        default: putchar(entity_dead_char); break;
    }
}

/**
 * Выводит символы мира 'width * height' в терминал.
 * Если передано сообщение 'message', то встраивает его
 * в центр экрана, по вертикали, вместо линии сущностей.
 */
void draw_world(world_t world, int width, int height, char *message) {
    int hc = height / 2;
    for (int y = 0; y < height; y++) {
        if (message != NULL && y == hc) {
            int wc = (width - strlen(message)) / 2;
            if (wc > 0)
                repeatchar(' ', wc);
            printf("%s", message);
        } else {
            for (int x = 0; x < width; x++) {
                draw_entity(world[y][x]);
            }
        }
        if (y < height - 1) putchar('\n');
    }
}

/**
 * Очищает терминал заданным методом.
 */
void clear_render(clear_render_t method) {
    switch (method) {
        case clear_render_screen_and_scroll:
            system("clear");
            printf("\e[3J");
            break;
        case clear_render_screen:
        default:
            printf("\e[H\e[2J");
            break;
    }
}

/**
 * Загрузка мира из 'stdin', либо из файла переданного первым аргументом программе.
 */
bool load_world(int argc, char **argv, world_t world, int width, int height) {
    bool loaded = false;

    // Загрузка мира из 'stdin', если 'stdin' не пуст (если мир не был загружен ранее).
    if (!loaded && kbhit()) {
        loaded = load_world_from_file(stdin, world, width, height);
    }

    // Загрузка мира из файла переданного 1-м аргументом программе (если мир не был загружен ранее).
    if (!loaded && argc >= 2 && argv != NULL) {
        FILE *fp = fopen(argv[1], "r");
        if (fp != NULL) {
            loaded = load_world_from_file(fp, world, width, height);
            fclose(fp);
        }
    }

    return loaded;
}

/**
 * Загружает мир из файла шаблона.
 * Первый встречный символ 'не пробел' файла шаблона
 * будет использован в качестве символа жизни сущности.
 * Прочие символы в первой строке будут пропущены.
 * Если символ сущности был найден, то будет загружен шаблон мира.
 * При загрузке игнорируются лишние пробелы и переносы строк,
 * для сохранения работоспособности в случае подобных ошибок.
 */
bool load_world_from_file(FILE *fp, world_t world, int width, int height) {
    char live_char = '\0';
    if (fp != NULL && !feof(fp)) {
        char c = fgetc(fp);
        if (c != '\n') {
            bool line_skiped = false;
            int x = 0, y = 0;
            do {
                if (live_char == '\0') {
                    if (!is_whitespace(c) && c != '\0') {
                        live_char = c;
                        while (!feof(fp) && (c = fgetc(fp)) != '\n') { }
                    }
                } else if (c == '\n') {
                    if (!line_skiped) {
                        line_skiped = true;
                        x = 0;
                        y += 1;
                    }
                } else if (!is_whitespace(c)) {
                    line_skiped = false;
                    x += 1;
                    if (c == live_char) {
                        if (x < width) {
                            world[y][x] = entity_live;
                        }
                    }
                }
            } while (y < height && !feof(fp) && (c = fgetc(fp)) != EOF);
        }
    }
    return (live_char != '\0');
}

/* Действие записи значения в хранилище. */
#define KBHIT_ATTR_IN 1
/* Действие чтения значения из хранилища. */
#define KBHIT_ATTR_OUT 2
/* Восстанавливает исходные атрибуты терминалу. */
#define KBHIT_ATTR_RESET 3
/* Проверяет, есть ли значение в хранилище. */
#define KBHIT_ATTR_HAS 4

/**
 * Хранилище исходных атрибутов терминала.
 * Хранит значение, после перехода в неканонический режим функцией 'kbhit'.
 *
 * Параметр action принимает значения:
 *   KBHIT_ATTR_IN - Записывает атрибуты из параметра 'tattr' в хранилище,
 *                   для дальнейшего восстановления их терминалу.
 *   KBHIT_ATTR_OUT - Чтение сохраненных атрибутов из хранилища в параметр 'tattr'.
 *   KBHIT_ATTR_RESET - Восстанавливает исходные атрибуты терминалу (параметр 'tattr' не используется).
 *   KBHIT_ATTR_HAS - Если в хранилище есть значение, то возвращает 1, иначе 0.
 */
int kbhit_storage(int action, struct termios *tattr) {
    static bool term_attr_src_assigned = false;
    static struct termios term_attr_src;
    int result = 0;
    switch (action) {
        case KBHIT_ATTR_IN:
            if (tattr != NULL) {
                term_attr_src = *tattr;
                term_attr_src_assigned = true;
                result = 1;
            }
            break;
        case KBHIT_ATTR_OUT:
            if (term_attr_src_assigned) {
                *tattr = term_attr_src;
                result = 1;
            }
            break;
        case KBHIT_ATTR_RESET:
            if (term_attr_src_assigned) {
                tcsetattr(STDIN_FILENO, TCSANOW, &term_attr_src);
                result = 1;
            }
            break;
        case KBHIT_ATTR_HAS:
            if (term_attr_src_assigned) {
                result = 1;
            }
            break;
    }
    return result;
}

/**
 * Восстанавливает исходные атрибуты терминала, если они были изменены функцией 'kbhit'.
 */
void kbhit_reset() {
    kbhit_storage(KBHIT_ATTR_RESET, NULL);
}

/**
 * Обработчик сигналов экстренного прекращения работы программы,
 * для восстановлением сохраненных исходных атребутов терминала.
 */
void kbhit_abort_signal_handler() {
    kbhit_storage(KBHIT_ATTR_RESET, NULL);
    exit(EXIT_FAILURE);
}

/**
 * Проверяет, содержит ли 'stdio' символы, которые можно считать.
 * Помогает отследить нажатие клавиш пользователем в терминале, без нажатия 'enter'.
 * Возвращает количество байт доступных для чтения.
 */
int kbhit() {
    if (!kbhit_storage(KBHIT_ATTR_HAS, NULL)) {
        struct termios term_attr = { 0 };
        tcgetattr(STDIN_FILENO, &term_attr);
        // Сохраняем копию для восстановления исходных атрибутов терминала.
        kbhit_storage(KBHIT_ATTR_IN, &term_attr);
        // Исключаем ICANON, для переключения в неканонический режим.
        // Исключаем ECHO, для отключения отображения вводимых символов.
        term_attr.c_lflag &= ~(ICANON|ECHO);
        // Устанавливаем изменённый режим работы терминала.
        tcsetattr(STDIN_FILENO, TCSANOW, &term_attr);
        // Подписываемся на сигналы завершения работы терминала,
        // для восстановления исходного режима работы терминала при выходе.
        signal(SIGABRT, kbhit_abort_signal_handler);
        signal(SIGKILL, kbhit_abort_signal_handler);
        signal(SIGQUIT, kbhit_abort_signal_handler);
        signal(SIGSTOP, kbhit_abort_signal_handler);
        signal(SIGTERM, kbhit_abort_signal_handler);
        signal(SIGINT, kbhit_abort_signal_handler);
        // Отключение буферизации потока.
        setbuf(stdin, NULL);
    }

    // Узнаём, какое количество байт доступно для чтения в 'stdin' (введено ли что-либо).
    int nbbytes;
    ioctl(STDIN_FILENO, FIONREAD, &nbbytes);
    return nbbytes;
}
