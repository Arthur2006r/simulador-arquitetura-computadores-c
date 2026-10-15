#include <stdlib.h>

#include "instrucao.h"

/**
 * Estrutura de Instrução
 * 
 * Define uma estrutura que representa uma instrução do
 * computador, contendo três endereços de memória (add1, add2, add3)
 * e um código de operação (opcode) que indica a operação a ser realizada
 */
struct instrucao {
    int add1;
    int add2;
    int add3;
    int opcode;
};

/**
 * Funções de manipulação da estrutura Intrucao
 */

Instrucao * aloca_instrucoes(int tamanho) {
    Instrucao *instrucao = malloc(tamanho * sizeof(Instrucao));
    if(!instrucao) 
        return NULL;

    return instrucao;
}

Instrucao cria_instrucao(int add1, int add2, int add3, enum OPCODE opcode) {
    Instrucao instrucao;

    instrucao.add1 = add1;
    instrucao.add2 = add2;
    instrucao.add3 = add3;
    instrucao.opcode = opcode;

    return instrucao;
}

/**
 * Getters e Setters para a estrutura Instrucao
 */

int get_add1(const Instrucao *instrucao) {
    return instrucao->add1;
}

int get_add2(const Instrucao *instrucao) {
    return instrucao->add2;
}

int get_add3(const Instrucao *instrucao) {
    return instrucao->add3;
}

int get_opcode(const Instrucao *instrucao) {
    return instrucao->opcode;
}

Instrucao *get_instrucao(Instrucao *instrucoes, int posicao) {
    return &instrucoes[posicao];
}

void set_instrucoes(Instrucao *programa, int posicao, int add1, int add2, int add3, enum OPCODE opcode) {
    programa[posicao] = cria_instrucao(add1, add2, add3, opcode);
}