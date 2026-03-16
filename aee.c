#include <stdio.h>
#include <stdlib.h>

int mcdExtendido(int a, int b, int *x, int *y) {
    if (a == 0) {
        *x = 0;
        *y = 1;
        return b;
    }
    int x1, y1;
    int mcd = mcdExtendido(b % a, a, &x1, &y1);
    *x = y1 - (b / a) * x1;
    *y = x1;
    return mcd;
}

int main(int argc, char *argv[]) {
    // Verificamos que se pasen a y m como argumentos
    if (argc < 3) {
        printf("Uso: %s <a> <m>\n", argv[0]);
        return 1;
    }

    int a = atoi(argv[1]);
    int m = atoi(argv[2]);
    int x, y;

    int g = mcdExtendido(a, m, &x, &y);

    if (g != 1) {
        // Si no hay inverso, imprimimos un mensaje o código de error
        printf("No existe el inverso\n");
    } else {
        // Aseguramos que el resultado sea positivo
        int inverso = (x % m + m) % m;
        printf("%d\n", inverso);
    }

    return 0;
}