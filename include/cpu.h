#ifndef CPU_H
#define CPU_H

/**
 * Implementação do Tipo Abstrato de Dados para a memória CPU
 */

#include "instrucao.h"
#include "ram.h"

typedef struct cpu CPU;

/**
 * Funções de manipulação da estrutura CPU
 */
CPU * cria_CPU();

/**
 * Getters e Setters para a estrutura CPU
 */
int get_registrador_1(const CPU *cpu);
int get_registrador_2(CPU cpu);

void set_registrador_1(CPU *cpu, int registrador_1);
void set_registrador_2(CPU *cpu, int registrador_2);
void set_programa(CPU *cpu, Instrucao *programa);

/**
 * Funções de execução do CPU
 */
void executar_programa(CPU *cpu, RAM *ram);

#endif