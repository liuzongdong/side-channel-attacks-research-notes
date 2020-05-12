#include <stdio.h>
#include <stdlib.h>

void fooA() {
    float x = 5;
    float y = 2;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 10; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("A %f\n", x);
}

void fooB() {
    float x = 4;
    float y = 1;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 50; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("B %f\n", x);
}

void fooC() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 20; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("C %f\n", x);
}

void fooD() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooE() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooF() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooG() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooH() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

void fooI() {
    float x = 2;
    float y = 3;
    x += y;
    x += y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    x += y;
    x *= y;
    x *= y;
    x += y;
    x *= y;
    for (int i = 0; i < 15; i++) {
        x *= y;
        x += y;
        x *= y;
        x *= y;
    }
    x *= y;
    x += y;
    x *= y;
    x *= y;
    printf("D %f\n", x);
}

int main(int argc, char **argv)
{
    char input[16];
    for(int i = 0; i < 1000; i++) {
        printf("Enter either A, B, C, or D:\n");
        fgets(input, 16, stdin);
        if (input[0] == 'A') {
            fooA();
        } else if (input[0] == 'B') {
            fooB();
        } else if (input[0] == 'G') {
            fooG();
        } else if (input[0] == 'I') {
            fooI();
        } else if (input[0] == 'Q') {
            exit(0);
        } else {
            printf("Error\n");
        }
    }
}
