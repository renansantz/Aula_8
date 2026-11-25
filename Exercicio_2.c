#include <stdio.h>

#define TOTAL 10

void ordenarCrescente(int vetor[], int tamanho) {
    int i, j, tmp;

    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - 1 - i; j++) {
            if (vetor[j] > vetor[j + 1]) {
                tmp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = tmp;
            }
        }
    }
}

void exibirVetor(int vetor[], int tamanho) {
    int i;

    if (tamanho == 0) {
        printf("Nenhum valor.\n");
        return;
    }

    for (i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int valores[TOTAL];
    int positivosPares[TOTAL], negativosImpares[TOTAL];
    int qtdPP = 0, qtdNI = 0;
    int i;

    for (i = 0; i < TOTAL; i++) {
        printf("Digite o valor %d: ", i + 1);
        scanf("%d", &valores[i]);
    }

    for (i = 0; i < TOTAL; i++) {
        if (valores[i] > 0 && valores[i] % 2 == 0) {
            positivosPares[qtdPP] = valores[i];
            qtdPP++;
        } else if (valores[i] < 0 && valores[i] % 2 != 0) {
            negativosImpares[qtdNI] = valores[i];
            qtdNI++;
        }
    }

    ordenarCrescente(positivosPares, qtdPP);
    ordenarCrescente(negativosImpares, qtdNI);

    printf("\nPositivos e pares (ordem crescente):\n");
    exibirVetor(positivosPares, qtdPP);

    printf("\nNegativos e impares (ordem crescente):\n");
    exibirVetor(negativosImpares, qtdNI);

    return 0;
}
