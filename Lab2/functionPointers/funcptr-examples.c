#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// setarch `uname -m` -R $SHELL # to disable ASLR

/* Functions that return an int */
int func1(int a, int b) {
    return a;
}

int func2(int a, int b) {
    return b;
}

/* Functions that return a pointer to an int */
int *funcp1(int *a, int *b) {
    return a;
}

int *funcp2(int *a, int *b) {
    return b;
}


int main(int argc, char **argv) {
    /* Pointer to a function that returns an int */
    int (*func)(int a, int b);

    /* Pointer to a function that returns a pointer to an int */
    int *(*funcp)(int *a, int *b);

    if (argc < 2) {
        perror("PROVIDE AN ARGUMENT!!!!!!!");
        return -1;
    }

    int x = 3;
    int y = 7;

    if (strcmp(argv[1], "1") == 0) {
        /* Func and funcp are set to point at the memory addresses of func1 and funcp1 respectively */
        func = func1;
        funcp = funcp1;
    } else {
        /* Func and funcp are set to point at the memory addresses of func2 and funcp2 respectively */
        func = func2;
        funcp = funcp2;
    }

    /* This will call the functions located at the memory addresses pointed to by func and funcp */
    int ans = func(x, y);
    int *ansp = funcp(&x, &y);

    /* Print out the value of ans and the memory address pointed to by ansp */
    printf("ans: %d\n", ans);
    printf("ansp: %p\n", ansp);

    return 0;
}
