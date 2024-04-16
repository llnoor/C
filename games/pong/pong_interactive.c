#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>

int fun_Graphics(int, int, int, int, int, int);
void refresh_ball();
void field();
int absn(int);
void set_terminal_settings(void);
void reset_terminal_settings(void);

static struct termios old_terminal_settings;
const int WINNING_SCORE = 21;
int ball_x = 40;
int ball_y = 12;
int racket1 = 12;
int racket2 = 12;
int score1 = 0;
int score2 = 0;
int ball_direction = 1;
// 1 - diagonally down, 2 - horizontally,
// 3 - diagonally up, the sign determines the direction
int main() {
    char key;
    fd_set file_descriptors;
    struct timeval time_value;

    set_terminal_settings();
    fun_Graphics(ball_x, ball_y, racket1, racket2, score1, score2);
    while (1) {
        int key_received;
        FD_ZERO(&file_descriptors);
        FD_SET(0, &file_descriptors);

        time_value.tv_sec = 0;
        time_value.tv_usec = 0;
        key_received = select(2, &file_descriptors, NULL, NULL, &time_value);

        if (key_received) {
          key = getc(stdin);

          if (key == '0') return 0;
          if ( (key == 'a' || key == 'A') && racket1 > 1 ) racket1--;
          if ( (key == 'z' || key == 'Z') && racket1 < 23 ) racket1++;
          if ( (key == 'k' || key == 'K') && racket2 > 1 ) racket2--;
          if ( (key == 'm' || key == 'M') && racket2 < 23 ) racket2++;

          refresh_ball();
          fun_Graphics(ball_x, ball_y, racket1, racket2, score1, score2);

          if (score1 == WINNING_SCORE) {
            refresh_ball();
            fun_Graphics(ball_x, ball_y, racket1, racket2, score1, score2);
            printf("Player 1 won! Congratulations!");
            return 0;
          }
          if (score2 == WINNING_SCORE) {
            refresh_ball();
            fun_Graphics(ball_x, ball_y, racket1, racket2, score1, score2);
            printf("Player 2 won! Congratulations!");
            return 0;
          }
        } else {
          refresh_ball();
          fun_Graphics(ball_x, ball_y, racket1, racket2, score1, score2);
        }
        usleep(70000);
    }
    reset_terminal_settings();
    return 0;
}

void  refresh_ball() {
    if ( ball_x == 78 ) {
      score1++;
      ball_x = 75;
      ball_y = racket2;
      ball_direction = -ball_direction;
    }

    if ( ball_x == 1 ) {
      score2++;
      ball_x = 4;
      ball_y = racket1;
      ball_direction = -ball_direction;
    }

    if ( 1 == absn(ball_direction) ) {
        ball_y++;
    } else if ( 3 == absn(ball_direction) ) {
        ball_y--;
    }

    if ( ball_direction > 0 ) {
        ball_x++;
    } else {
        ball_x--;
    }

    if ( ball_x == 75 ) {
        if ( ball_y == racket2 || ball_y == (racket2 - 1) || ball_y == (racket2 + 1) ) {
            ball_direction = -ball_direction;
        } else if ( ball_y == (racket2 - 2) && 1 == ball_direction ) {
            ball_direction = -3;
        } else if ( ball_y == (racket2 + 2) && 3 == ball_direction ) {
            ball_direction = -1;
        }
    }

    if ( ball_x == 76 ) {
        if ( ball_y == (racket2 - 2) && 1 == ball_direction ) {
            ball_direction = 3;
        } else if ( ball_y == (racket2 + 2) && 3 == ball_direction ) {
            ball_direction = 1;
        }
    }

    if ( ball_x == 4 ) {
        if ( ball_y == racket1 || ball_y == (racket1 - 1) || ball_y == (racket1 + 1) ) {
            ball_direction = -ball_direction;
        } else if ( ball_y == (racket1 - 2) && -1 == ball_direction ) {
            ball_direction = 3;
        } else if ( ball_y == (racket1 + 2) && -3 == ball_direction ) {
            ball_direction = 1;
        }
    }

    if ( ball_x == 3 ) {
        if ( ball_y == (racket1 - 2) && -1 == ball_direction ) {
            ball_direction = -3;
        } else if ( ball_y == (racket1 + 2) && -3 == ball_direction ) {
            ball_direction = -1;
        }
    }

    if (ball_y == 0) {
        if ( ball_direction > 0 ) {
            ball_direction = 1;
        } else {
            ball_direction = -1;
        }
    }

    if (ball_y == 24) {
        if ( ball_direction > 0 ) {
            ball_direction = 3;
        } else {
            ball_direction = -3;
        }
    }
}

int fun_Graphics(int b_x, int b_y, int racket1, int racket2, int score1, int score2) {
    printf("\e[H\e[2J");  // \e - Escape, \e[H - перемещает курсор в верхний левый угол, \e[2J - очищает экран
    field();
    for (int y = 0; y < 25; y++) {
        for (int x = 0; x < 80; x++) {
            if ( x == 35 && y == 1 ) {
                if (score1 <= 9) {
                    printf("%d", score1);
                } else {
                    printf("\b%d", score1);
                }
            } else if ( x == 43 && y == 1 ) {
                if (score2 <= 9) {
                    printf("%d", score2);
                } else {
                    printf("\b%d", score2);
                }
            } else if ( b_x == x && b_y == y ) {
                printf("*");
            } else if ( 3 == x && ((racket1 == y || racket1 == (y-1)) || racket1 == (y+1)) ) {
                printf("|");
            } else if ( 76 == x && ((racket2 == y || racket2 == (y-1)) || racket2 == (y+1)) ) {
                printf("|");
            } else if ((x == 0 || x == 39) || (x == 79)) {
                printf("|");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    field();
    return 0;
}

void field() {
    printf("+");
    for (int x = 0; x < 78; x++) {
        printf("-");
    }
    printf("+\n");
}

int absn(int a) {
    if (a > 0) {
        return a;
    } else {
        return (-1*a);
    }
}

void set_terminal_settings(void) {
  struct termios new_terminal_settings;
  tcgetattr(0, &old_terminal_settings);
  new_terminal_settings = old_terminal_settings;
  new_terminal_settings.c_cc[VMIN] = 1;
  new_terminal_settings.c_cc[VTIME] = 0;
  new_terminal_settings.c_lflag &= (~ICANON & ~ECHO);
  tcsetattr(0, TCSANOW, &new_terminal_settings);
  return;
}

void reset_terminal_settings(void) {
  tcsetattr(0, TCSANOW, &old_terminal_settings);
  return;
}
