#include <stdio.h>
#include <stdbool.h>

const int x_min = 0, y_min = 0, x_max = 80, y_max = 25;

void create_field(int x_min, int y_min, int x_max, int y_max, int x_p1, int y_p1, int x_p2, int y_p2, int x_ball, int y_ball, int count_p1, int count_p2);
int Count_the_key();

int main() {
    int x_p1 = 1, y_p1 = 13, x_p2 = 78, y_p2 = 13, x_ball = (x_max - 1 - x_min) / 2, y_ball = 13;
    int count_p1 = 0, count_p2 = 0;
    create_field(x_min, y_min, x_max, y_max, x_p1, y_p1, x_p2, y_p2, x_ball, y_ball, count_p1, count_p2);
}

void create_field(int x_min, int y_min, int x_max, int y_max, int x_p1, int y_p1, int x_p2, int y_p2, int x_ball, int y_ball, int count_p1, int count_p2) {
    char key;
    int k = 0;
    bool vert = false, goriz = true;
    while (count_p1 != 1 && count_p2 != 1) {
        for (int i = y_max; i > y_min; i--) {
        for (int j = x_min; j < x_max; j++) {
            if (i == y_max && j == x_min) {
                printf("%d", count_p1);       
            } else if (i == y_max && j == x_max - 1) {
                printf("%d", count_p2); 
            } else if (i == 25 || i == 1) {
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
        key = Count_the_key ();
        if (key == 'a') {
            if (y_p1 + 1 == y_max - 1) {
                continue;
            } else {
                y_p1 += 1;
            }
        }
        if (key == 'z') {
            if (y_p1 - 3 == y_min) {
                continue;
            } else {
                y_p1 -= 1;
            }
        }
        if (key == 'm') {
            if (y_p2 - 3 == y_min) {
                continue;
            } else {
                y_p2 -= 1;
            }
        }
        if (key == 'k') {
            if (y_p2 + 1 == y_max - 1) {
                continue;
            } else {
                y_p2 += 1;
            }
        }
        //k++;
        if ((y_ball == y_p1 && x_ball - 1 == x_p1) || (y_ball == y_p1 + 1 && x_ball - 1 == x_p1) || (y_ball == y_p1 - 1 && x_ball -+ 1 == x_p1)) {
            if (vert == true) {
                vert = false;
            } else vert = true;
            goriz = true;
        }
        if ((y_ball == y_p2 && x_ball + 1 == x_p2) || (y_ball == y_p2 + 1 && x_ball + 1 == x_p2) || (y_ball == y_p2 - 1 && x_ball + 1 == x_p2)) {
            if (vert == true) {
                vert = false;
            } else vert = true;
            goriz = false;
        }
        if (y_ball == y_max) {
            vert = false;
        }
        if (y_ball - 1 == y_min) {
            vert = true;
        }
        if (vert == true && goriz == true) {
            y_ball++;
            x_ball++;
        }
        if (vert == true && goriz == false) {
            y_ball++;
            x_ball--;
        }
        if (vert == false && goriz == true) {
            y_ball--;
            x_ball++;
        }
        if (vert == false && goriz == false) {
            y_ball--;
            x_ball--;
        }
        if (x_ball == x_min) {
            count_p2++;
            x_ball = (x_max - 1 - x_min) / 2;
            y_ball = 13;
            vert = false;
            goriz = true;
            x_p1 = 1;
            y_p1 = 13;
            x_p2 = 78;
            y_p2 = 13;
        }
        if (x_ball == x_max - 1) {
            count_p1++;
            x_ball = (x_max - 1 - x_min) / 2;
            y_ball = 13;
            vert = false;
            goriz = false;
            x_p1 = 1;
            y_p1 = 13;
            x_p2 = 78;
            y_p2 = 13;
        }
        if (count_p1 == 1) {
            printf("First player winner!!! Score: %d:%d\n", count_p1, count_p2);
        }
        if (count_p1 == 2) {
            printf("Second player winner!!! Score: %d:%d\n", count_p1, count_p2);
        }
    }
}

int Count_the_key () {
    char step;
    step = getchar();
    switch (step)
    {
    case 97:
        return 'a';
    case 122:
        return 'z';
    case 109:
        return 'm';
    case 107:
        return 'k';
    case 32:
        return ' ';
    default:
        Count_the_key ();
    }
}