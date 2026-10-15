#ifndef OPERACOES_ALTO_NIVEL_H
#define OPERACOES_ALTO_NIVEL_H

/**
 * A biblioteca "operacoes_alto_nivel" traduz operações
 * de alto nível (como adição, subtração e manipulação de variáveis) em 
 * sequências de instruções e opcodes executáveis pelo simulador
 */

#include "log.h"
#include "cpu.h"

/**
 * Funções para simular operações matemáticas em alto nível
 */
void somar(CPU *cpu, RAM *ram, int add1, int add2);
void subtrair(CPU *cpu, RAM *ram, int add1, int add2);
void multiplicar(CPU *cpu, RAM *ram, int multiplicando, int multiplicador);
void mod(CPU *cpu, RAM *ram, int dividendo, int divisor);
void dividir(CPU *cpu, RAM *ram, int dividendo, int divisor);
void exponenciar(CPU *cpu, RAM *ram, int base, int expoente);
void raiz_quadrada(CPU *cpu, RAM *ram, int radicando);
void fatorial(CPU *cpu, RAM *ram, int n);
void bhaskara(CPU *cpu, RAM *ram, int a, int b, int c);
void decimal_para_binario(CPU *cpu, RAM *ram, int decimal);
void determinante(CPU *cpu, RAM *ram, int n);

int get_valor(CPU *cpu, RAM *ram, int add1);
void set_valor(CPU *cpu, RAM *ram, int valor, int add1);

#endif