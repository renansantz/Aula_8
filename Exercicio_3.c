#include <stdio.h>

#define TOTAL 15
#define MAX_ANIMAIS 50

int ehPrimo(int n) {
    int i;

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
    int numeros[TOTAL];
    int distintos[TOTAL], contagem[TOTAL], primeiraPos[TOTAL];
    char animais[MAX_ANIMAIS][50];
    int qtdDistintos = 0, qtdAnimais = 0;
    int i, j, k, achou, total;


    for (i = 0; i < TOTAL; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }


    for (i = 0; i < TOTAL; i++) {
        achou = 0;
        for (j = 0; j < qtdDistintos; j++) {
            if (distintos[j] == numeros[i]) {
                contagem[j]++;
                achou = 1;
                break;
            }
        }
        if (!achou) {
            distintos[qtdDistintos] = numeros[i];
            contagem[qtdDistintos] = 1;
            primeiraPos[qtdDistintos] = i + 1;
            qtdDistintos++;
        }
    }

    
    printf("\n%-8s %-12s %s\n", "Numero", "Ocorrencias", "Classificacao");
    for (i = 0; i < qtdDistintos; i++) {
        printf("%-8d %-12d ", distintos[i], contagem[i]);
        if (contagem[i] == 1) {
            printf("Nao repetido\n");
        } else if (ehPrimo(distintos[i])) {
            printf("Primo - %s\n", contagem[i] % 2 == 0 ? "par" : "impar");
        } else {
            printf("%s\n", contagem[i] % 2 == 0 ? "Par" : "Impar");
        }
    }

   
    for (i = 0; i < qtdDistintos; i++) {
        if (contagem[i] > 1 && contagem[i] % 2 != 0 && ehPrimo(distintos[i])) {
            total = distintos[i] * 0 + contagem[i]; /* soma das ocorrencias do numero */
            printf("\nNumero primo %d com %d ocorrencias (impar).\n", distintos[i], contagem[i]);
            printf("Cadastre %d animal(is):\n", total);
            for (k = 0; k < total && qtdAnimais < MAX_ANIMAIS; k++) {
                printf("Animal %d: ", qtdAnimais + 1);
                scanf(" %49[^\n]", animais[qtdAnimais]);
                qtdAnimais++;
            }
        }
    }

    /* c) e d) Ocorrencias pares: posicao no vetor -> animal cadastrado */
    printf("\nSaida:\n");
    k = 1;
    for (i = 0; i < qtdDistintos; i++) {
        if (contagem[i] > 1 && contagem[i] % 2 == 0) {
            if (primeiraPos[i] <= qtdAnimais) {
                printf("%d. %s.\n", k, animais[primeiraPos[i] - 1]);
            } else {
                printf("%d. Nao existe correspondencia.\n", k);
            }
            k++;
        }
    }

    if (k == 1) {
        printf("Nenhum numero com ocorrencias pares.\n");
    }

    return 0;
}
