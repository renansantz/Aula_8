#include <stdio.h>
#include <string.h>

#define TOTAL 12

typedef struct {
    char nome[50];
    float preco;
    int quantidade;
} Produto;

int main() {
    int numeros[TOTAL];
    int distintos[TOTAL], contagem[TOTAL];
    int pares[TOTAL];
    Produto produtos[TOTAL], tmpProd;
    int qtdDistintos = 0, qtdPares = 0, qtdProdutos = 0;
    int i, j, achou, tmp;

    /* Leitura dos 12 numeros */
    for (i = 0; i < TOTAL; i++) {
        printf("Digite o numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    /* a) Contagem de ocorrencias de cada numero distinto */
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
            qtdDistintos++;
        }
    }

    /* b) e c) Separa ocorrencias impares (produtos) e pares (segundo vetor) */
    for (i = 0; i < qtdDistintos; i++) {
        if (contagem[i] % 2 != 0) {
            /* d) Cadastro do produto: o numero e a quantidade a comprar */
            printf("\nO numero %d aparece %d vez(es) (impar).\n", distintos[i], contagem[i]);
            printf("Cadastro do produto (quantidade a comprar: %d)\n", distintos[i]);
            printf("Nome: ");
            scanf(" %49[^\n]", produtos[qtdProdutos].nome);
            printf("Preco unitario: ");
            scanf("%f", &produtos[qtdProdutos].preco);
            produtos[qtdProdutos].quantidade = distintos[i];
            qtdProdutos++;
        } else {
            pares[qtdPares] = distintos[i];
            qtdPares++;
        }
    }

    /* c) Segundo vetor em ordem decrescente */
    for (i = 0; i < qtdPares - 1; i++) {
        for (j = 0; j < qtdPares - 1 - i; j++) {
            if (pares[j] < pares[j + 1]) {
                tmp = pares[j];
                pares[j] = pares[j + 1];
                pares[j + 1] = tmp;
            }
        }
    }

    /* e) Produtos em ordem alfabetica pelo nome */
    for (i = 0; i < qtdProdutos - 1; i++) {
        for (j = 0; j < qtdProdutos - 1 - i; j++) {
            if (strcmp(produtos[j].nome, produtos[j + 1].nome) > 0) {
                tmpProd = produtos[j];
                produtos[j] = produtos[j + 1];
                produtos[j + 1] = tmpProd;
            }
        }
    }

    /* Resultados finais */
    printf("\n===== RESULTADOS =====\n");

    printf("\na) Numeros informados:\n");
    for (i = 0; i < TOTAL; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    printf("\nb) Numeros distintos e ocorrencias:\n");
    for (i = 0; i < qtdDistintos; i++) {
        printf("Numero %d: %d vez(es)\n", distintos[i], contagem[i]);
    }

    printf("\nc) Produtos para compra (ordem alfabetica):\n");
    if (qtdProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
    }
    for (i = 0; i < qtdProdutos; i++) {
        printf("%s - Quantidade: %d - Preco unitario: R$ %.2f\n",
               produtos[i].nome, produtos[i].quantidade, produtos[i].preco);
    }

    printf("\nd) Numeros com ocorrencias pares (ordem decrescente):\n");
    if (qtdPares == 0) {
        printf("Nenhum numero com ocorrencias pares.\n");
    }
    for (i = 0; i < qtdPares; i++) {
        printf("%d ", pares[i]);
    }
    printf("\n");

    return 0;
}
