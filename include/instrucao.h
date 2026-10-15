#ifndef INSTRUCAO_H
#define INSTRUCAO_H

/**
 * Implementação do Tipo Abstrato de Dados para a memória Instrucao
 */

/**
 * Enum do opcode de Instrucao
 * 
 * Representa cada tipo de execução da Instrução
 */
enum OPCODE {
    OP_HALT = -1, // Parada
    OP_ADD = 0, // Soma
    OP_SUB = 1, // Subtração
    OP_MOV1 = 2, // Movimentação do registrador para a RAM
    OP_MOV2 = 3 // Movimentação da RAM para o registrador
};

typedef struct instrucao Instrucao;

/**
 * Funções de manipulação da estrutura Intrucao
 */
Instrucao * aloca_instrucoes(int tamanho);
Instrucao cria_instrucao(int add1, int add2, int add3, enum OPCODE opcode);

/**
 * Getters e Setters para a estrutura Instrucao
 */
int get_add1(const Instrucao *instrucao);
int get_add2(const Instrucao *instrucao);
int get_add3(const Instrucao *instrucao);
int get_opcode(const Instrucao *instrucao);
Instrucao *get_instrucao(Instrucao *instrucoes, int posicao);

void set_instrucoes(Instrucao *programa, int posicao, int add1, int add2, int add3, enum OPCODE opcode);

#endif