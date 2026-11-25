#include <stdio.h>

#define APOSTADORES 5
#define LIMITE_MAX 60


long long somaFibonacci(int n) {
    long long a = 1, b = 1, soma = 0, prox;
    int i;

    for (i = 1; i <= n; i++) {
        soma += a;
        prox = a + b;
        a = b;
        b = prox;
    }

    return soma;
}

int ehPrimo(long long n) {
    long long i;

    if (n < 2) {
        return 0;
    }
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    char nomes[APOSTADORES][50];
    int valores[APOSTADORES];
    long long resultados[APOSTADORES];
    int premiado[APOSTADORES] = {0};
    int primeiro = -1, segundo = -1, terceiro = -1;
    double media, soma = 0;
    int i;

    
    for (i = 0; i < APOSTADORES; i++) {
        printf("Apostador %d - Nome: ", i + 1);
        scanf(" %49[^\n]", nomes[i]);

        do {
            printf("Apostador %d - Valor inteiro positivo (1 a %d): ", i + 1, LIMITE_MAX);
            scanf("%d", &valores[i]);
        } while (valores[i] < 1 || valores[i] > LIMITE_MAX);

        resultados[i] = somaFibonacci(valores[i]);
        soma += resultados[i];
    }

    media = soma / APOSTADORES;


    for (i = 0; i < APOSTADORES; i++) {
        if (ehPrimo(resultados[i])) {
            if (primeiro == -1 || resultados[i] > resultados[primeiro]) {
                primeiro = i;
            }
        }
    }
    if (primeiro != -1) {
        premiado[primeiro] = 1;
    }


    for (i = 0; i < APOSTADORES; i++) {
        if (!premiado[i] && resultados[i] % 2 == 0) {
            if (segundo == -1 || resultados[i] > resultados[segundo]) {
                segundo = i;
            }
        }
    }
    if (segundo != -1) {
        premiado[segundo] = 1;
    }


    for (i = 0; i < APOSTADORES; i++) {
        if (!premiado[i] && resultados[i] > media) {
            if (terceiro == -1 || resultados[i] > resultados[terceiro]) {
                terceiro = i;
            }
        }
    }
    if (terceiro != -1) {
        premiado[terceiro] = 1;
    }


    printf("\n===== VENCEDORES =====\n");

    if (primeiro != -1) {
        printf("1o lugar: %s\n", nomes[primeiro]);
    } else {
        printf("1o lugar: sem vencedor\n");
    }

    if (segundo != -1) {
        printf("2o lugar: %s\n", nomes[segundo]);
    } else {
        printf("2o lugar: sem vencedor\n");
    }

    if (terceiro != -1) {
        printf("3o lugar: %s\n", nomes[terceiro]);
    } else {
        printf("3o lugar: sem vencedor\n");
    }

    return 0;
}
