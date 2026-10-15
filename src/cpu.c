#include <stdlib.h>
#include <limits.h>

#include "log.h"
#include "cpu.h"

/**
 * Estrutura de CPU
 * 
 * Define uma estrutura que representa uma CPU, 
 * contendo dois registradores (registrador_1 e registrador_2),
 * o contador de programa (PC) e o código de execução da CPU (opcode)
 */
struct cpu {
    int registrador_1;
    int registrador_2;
    int PC;
    int opcode;

    Instrucao *programa;
};

/**
 * Funções de manipulação da estrutura CPU
 */

CPU * cria_CPU() {
    CPU *cpu = malloc(sizeof(CPU));
    if(!cpu)
        return NULL;

    cpu->programa = NULL;

    return cpu;
}

/**
 * Funções utilitárias
 */

void executar_halt(RAM *ram) {
    gerar_log_RAM(get_memoria_array(ram), get_tamanho(ram));
}

void executar_add(CPU *cpu, RAM *ram, const Instrucao *instrucao) {
    cpu->registrador_1 = get_memoria(ram, get_add1(instrucao));
    cpu->registrador_2 = get_memoria(ram, get_add2(instrucao));
    cpu->registrador_1 += cpu->registrador_2;

    set_memoria(ram, get_add3(instrucao), cpu->registrador_1);
}

void executar_sub(CPU *cpu, RAM *ram, const Instrucao *instrucao) {
    cpu->registrador_1 = get_memoria(ram, get_add1(instrucao));
    cpu->registrador_2 = get_memoria(ram, get_add2(instrucao));
    cpu->registrador_1 -= cpu->registrador_2;

    set_memoria(ram, get_add3(instrucao), cpu->registrador_1);
}

void executar_mov1(CPU *cpu, RAM *ram, const Instrucao *instrucao) {
    int endereco_registrador = get_add1(instrucao), endereco_ram = get_add2(instrucao), valor;

    if(endereco_registrador == 1)
        valor = cpu->registrador_1;
    else if(endereco_registrador == 2)
        valor = cpu->registrador_2;

    set_memoria(ram, endereco_ram, valor);
}

void executar_mov2(CPU *cpu, RAM *ram, const Instrucao *instrucao) {
    int endereco_registrador = get_add1(instrucao), endereco_ram = get_add2(instrucao), valor;

    valor = get_memoria(ram, endereco_ram);

    if(endereco_registrador == 1)
        cpu->registrador_1 = valor;
    else if(endereco_registrador == 2)
        cpu->registrador_2 = valor;
}

/**
 * Getters e Setters para a estrutura CPU
 */

int get_registrador_1(const CPU *cpu) {
    return cpu->registrador_1;
}

int get_registrador_2(CPU cpu) {
    return cpu.registrador_2;
}

void set_registrador_1(CPU *cpu, int registrador_1) {
    cpu->registrador_1 = registrador_1;
}

void set_registrador_2(CPU *cpu, int registrador_2) {
    cpu->registrador_2 = registrador_2;
}

void set_programa(CPU *cpu, Instrucao *programa) {
    if(programa) 
        cpu->programa = programa;
}

/**
 * Funções de execução do CPU
 */

void executar_programa(CPU *cpu, RAM *ram) {
    if(!cpu->programa) {
        gerar_log_ERROR("Não há um programa definido na CPU!");
        return;
    }
    
    cpu->PC = 0;

    // Fluxo de repetição para a execução do programa presenta na CPU
    do {
        Instrucao *instrucao = get_instrucao(cpu->programa, cpu->PC); // Recupera instrução de acordo com a ordem do contador do computador (PC)
        cpu->opcode = get_opcode(instrucao);

        switch(cpu->opcode) {
            case OP_HALT:
                executar_halt(ram);

                break;
            
            case OP_ADD:
                executar_add(cpu, ram, instrucao);

                break;

            case OP_SUB:
                executar_sub(cpu, ram, instrucao);

                break;

            case OP_MOV1:
                executar_mov1(cpu, ram, instrucao);

                break;

            case OP_MOV2:
                executar_mov2(cpu, ram, instrucao);

                break;
        }

        cpu->PC++;
    } while(cpu->opcode != OP_HALT);
}
