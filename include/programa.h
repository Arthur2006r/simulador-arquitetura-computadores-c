#ifndef PROGRAMA_H
#define PROGRAMA_H

/**
 * A biblioteca "programa" conecta os componentes de computador definidos
 * no código à função main, possibilitando a execução de cálculos simples
 * a partir do algoritmo base de um computador
 */

#include "operacoes_alto_nivel.h"

/**
 * Funções da biblioteca a partir do uso dos compoenentes do computador
 */
void executar_programa_aleatorio(RAM *ram, CPU *cpu, int quantidade_instrucoes);

int executar_soma(RAM *ram, CPU *cpu, int num1, int num2);
int executar_subtracao(RAM *ram, CPU *cpu, int num1, int num2);
int executar_mod(RAM *ram, CPU *cpu, int dividendo, int divisor);
int executar_divisao(RAM *ram, CPU *cpu, int dividendo, int divisor);
int executar_multiplicacao(RAM *ram, CPU *cpu, int multiplicando, int multiplicador);
int executar_exponenciacao(RAM *ram, CPU *cpu, int base, int expoente);
int executar_raiz_quadrada(RAM *ram, CPU *cpu, int radicando);
int executar_fatorial(RAM *ram, CPU *cpu, int n);
int executar_bhaskara(RAM *ram, CPU *cpu, int a, int b, int c, int *x1, int *x2);
int executar_decimal_para_binario(RAM *ram, CPU *cpu, int decimal);
int executar_determinante(RAM *ram, CPU *cpu, int *matriz, int n);

#endif