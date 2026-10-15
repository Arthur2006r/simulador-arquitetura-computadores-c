#include "programa.h"

#include <stdio.h>
#include <stdlib.h>

void print_matriz(int *matriz, int n);
void print_opcoes();

int main() {
    RAM *ram = NULL;
    CPU *cpu = cria_CPU();

    int op, nro_1, nro_2, nro_3, x1, x2, resultado, n;
    
    printf("[CALCULADORA]\n");
    
    do {
        print_opcoes();
        printf("Digite a opção: ");
        scanf("%d", &op);

        printf("\n");

        switch(op) {
            case 1:
                printf("[SOMA] a + b = ?\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                printf("Digite o valor de b: ");
                scanf("%d", &nro_2);

                resultado = executar_soma(ram, cpu, nro_1, nro_2);

                printf("\n[RESULTADO]: %d + %d = %d\n", nro_1, nro_2, resultado);
                break;
            
            case 2:
                printf("[SUBTRAÇÃO] a - b = ?\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                printf("Digite o valor de b: ");
                scanf("%d", &nro_2);

                resultado = executar_subtracao(ram, cpu, nro_1, nro_2);

                printf("\n[RESULTADO]: %d - %d = %d\n", nro_1, nro_2, resultado);
                break; 
            
            case 3:
                printf("[MOD] a %% b = ?\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                printf("Digite o valor de b: ");
                scanf("%d", &nro_2);

                resultado = executar_mod(ram, cpu, nro_1, nro_2);

                printf("\n[RESULTADO]: %d %% %d = %d\n", nro_1, nro_2, resultado);
                break;
            
            case 4:
                printf("[DIVISÃO] a / b = ?\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                printf("Digite o valor de b: ");
                scanf("%d", &nro_2);

                resultado = executar_divisao(ram, cpu, nro_1, nro_2);

                printf("\n[RESULTADO]: %d / %d = %d\n", nro_1, nro_2, resultado);
                break;

            case 5:
                printf("[MULTIPLICAÇÃO] a x b = ?\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                printf("Digite o valor de b: ");
                scanf("%d", &nro_2);

                resultado = executar_multiplicacao(ram, cpu, nro_1, nro_2);

                printf("\n[RESULTADO]: %d x %d = %d\n", nro_1, nro_2, resultado);
                break;

            case 6:
                printf("[EXPONENCIAÇÃO] a^(b) = ?\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                printf("Digite o valor de b: ");
                scanf("%d", &nro_2);

                resultado = executar_exponenciacao(ram, cpu, nro_1, nro_2);

                printf("\n[RESULTADO]: %d^(%d) = %d\n", nro_1, nro_2, resultado);
                break;

            case 7:
                printf("[RAIZ QUADRADA] a^(1/2) = ?\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                resultado = executar_raiz_quadrada(ram, cpu, nro_1);

                printf("\n[RESULTADO]: %d^(1/2) = %d\n", nro_1, resultado);
                break;
            
            case 8:
                printf("[FATORIAL] n! = ?\n\n");

                printf("Digite o valor de n: ");
                scanf("%d", &nro_1);

                resultado = executar_fatorial(ram, cpu, nro_1);

                if(resultado == -1)
                    printf("\n[ERRO]: n deve estar entre 0 e 12.\n");
                else
                    printf("\n[RESULTADO]: %d! = %d\n", nro_1, resultado);
                break;

            case 9:
                printf("[BHASKARA] ax^2 + bx + c = 0\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                printf("Digite o valor de b: ");
                scanf("%d", &nro_2);

                printf("Digite o valor de c: ");
                scanf("%d", &nro_3);

                resultado = executar_bhaskara(ram, cpu, nro_1, nro_2, nro_3, &x1, &x2);

                if(resultado == -1)
                    printf("\n[ERRO]: o valor de a nao pode ser zero.\n");
                else if(resultado == 0)
                    printf("\n[RESULTADO]: delta negativo, nao existem raizes reais.\n");
                else if(resultado == 1)
                    printf("\n[RESULTADO]: raiz unica x = %d\n", x1);
                else
                    printf("\n[RESULTADO]: x1 = %d e x2 = %d\n", x1, x2);
                break;

            case 10:
                printf("[DECIMAL PARA BINÁRIO] a(10) = ?(2))\n\n");

                printf("Digite o valor de a: ");
                scanf("%d", &nro_1);

                resultado = executar_decimal_para_binario(ram, cpu, nro_1);

                printf("\n[RESULTADO]: %d(10) = %d(2)\n", nro_1, resultado);
                break;

            case 11:
                printf("[DETERMINANTE] Matriz NxN\n\n");
                
                printf("Digite a ordem N da matriz: ");
                scanf("%d", &n);

                if (n <= 0) {
                    printf("\n[ERRO]: A ordem da matriz deve ser maior que zero.\n");
                    break;
                }

                int *matriz = (int *)malloc(n * n * sizeof(int));

                printf("Digite os elementos da matriz %dx%d:\n", n, n);
                for(int i = 0; i < n; i++) {
                    for(int j = 0; j < n; j++) {
                        printf("Matriz[%d][%d]: ", i, j);
                        scanf("%d", &matriz[i * n + j]);
                    }
                }

                resultado = executar_determinante(ram, cpu, matriz, n);

                print_matriz(matriz, n);

                printf("\n[RESULTADO]: Determinante = %d\n", resultado);

                free(matriz); 
                break;

            case -1:
                break;

            default:
                printf("!!! OPERAÇÃO INVÁLIDA !!!\n");
        }

    } while(op != -1);

    printf("[PROGRAMA FINALIZADO]\n");

    return 0;
}

void print_matriz(int *matriz, int n) {
    printf("\nMatriz %dx%d inserida:\n", n, n);
    for (int i = 0; i < n; i++) {
        printf("|  ");
        for (int j = 0; j < n; j++) {
            printf("%d  ", matriz[i * n + j]); 
        }
        printf("|\n");
    }
    printf("\n");
}

void print_opcoes() {
    printf("\n\n====== OPERAÇÕES ======\n");
    printf("1 -> Soma\n");
    printf("2 -> Subtração\n");
    printf("3 -> Mod\n");
    printf("4 -> Divisão\n");
    printf("5 -> Multiplicação\n");
    printf("6 -> Exponenciação\n");
    printf("7 -> Raiz quadrada\n");
    printf("8 -> Fatorial\n");
    printf("9 -> Bhaskara\n");
    printf("10 -> Decimal para Binário\n");
    printf("11 -> Determinante de Matriz NxN\n");
    printf("-1 -> Sair\n");
    printf("=======================\n");
}