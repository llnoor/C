// Copyright 2022 TEAM41

#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>

int fun_Graphics(int, int, int, int, int, int);
void refresh_ball();
void field();
int absn(int);
int catch_keys();

const int WINNING_SCORE = 21;
int ball_x = 40;
int ball_y = 12;
int racket1 = 12;
int racket2 = 12;
int score1 = 0;
int score2 = 0;
int ball_direction = 1;
int time_ms = 170000;
// 1 - diagonally down, 2 - horizontally,
// 3 - diagonally up, the sign determines the direction
int main() {
    char key = 'c';
    while (1) {
        usleep(time_ms);
        if ( catch_keys()==1 ) {
            key = getchar();
        }
        if ( key == '0' ) {
            return 0;
        }
        if ( (key == 'a' || key == 'A') && racket1 > 1 ) racket1--;
        if ( (key == 'z' || key == 'Z') && racket1 < 23 ) racket1++;
        if ( (key == 'k' || key == 'K') && racket2 > 1 ) racket2--;
        if ( (key == 'm' || key == 'M') && racket2 < 23 ) racket2++;
        refresh_ball();
        fun_Graphics(ball_x, ball_y, racket1, racket2, score1, score2);
        if (score1 == WINNING_SCORE) {
          printf("Player 1 won! Congratulations!");
          return 0;
        }
        if (score2 == WINNING_SCORE) {
          printf("Player 2 won! Congratulations!");
          return 0;
        }
        key = 'c';
    }
    return 0;
}

int catch_keys() {
    struct termios old_termios, new_termios;
    int check;
    int old_function;
    tcgetattr(STDIN_FILENO, &old_termios);
    new_termios = old_termios;
    new_termios.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_termios);
    old_function = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, old_function | O_NONBLOCK);
    check = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_termios);
    fcntl(STDIN_FILENO, F_SETFL, old_function);

    if (check != EOF) {
        ungetc(check, stdin);
        return 1;
    }
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
