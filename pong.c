#include <stdio.h>

const int x_min = 0, y_min = 0, x_max = 80, y_max = 25;

void create_field(int x_min, int y_min, int x_max, int y_max, int x_p1, int y_p1, int x_p2, int y_p2, int x_ball, int y_ball, int count_p1, int count_p2);
void create_players_and_ball (int x_p1, int y_p1, int x_p2, int y_p2, int x_ball, int y_ball);

int main() {
    int x_p1 = 1, y_p1 = 13, x_p2 = 78, y_p2 = 13, x_ball = (x_max - 1 - x_min) / 2, y_ball = 13;
    int count_p1 = 0, count_p2 = 0;
    create_field(x_min, y_min, x_max, y_max, x_p1, y_p1, x_p2, y_p2, x_ball, y_ball, count_p1, count_p2);
}

void create_field(int x_min, int y_min, int x_max, int y_max, int x_p1, int y_p1, int x_p2, int y_p2, int x_ball, int y_ball, int count_p1, int count_p2) {
    //while (count_p1 != 21 || count_p2 != 21) {
        for (int i = y_max; i > y_min; i--) {
        for (int j = x_min; j < x_max; j++) {
            if (i == 25 || i == 1) {
                 printf("-");
            } else if (j == 0 || j == 79) {
                printf("|");
            } else if ((i == y_p1 && j == x_p1) || (i == y_p2 && j == x_p2) || (i == y_p1 + 1 && j == x_p1) ||
             (i == y_p2 + 1 && j == x_p2) || (i == y_p1 - 1 && j == x_p1) || (i == y_p2 - 1 && j == x_p2)) {
                printf("|");
            } else if (i == y_ball && j == x_ball) {
                printf("*");
            } else if (j == (x_max - 1 - x_min) / 2) {
                printf("|");
                } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    //}
}

void create_players_and_ball (int x_p1, int y_p1, int x_p2, int y_p2, int x_ball, int y_ball) {
    
}
