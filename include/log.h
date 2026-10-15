#ifndef LOG_H
#define LOG_H

/**
 * A biblioteca "log" é responsável pelo registro do histórico de execução,
 * salvando as operações do computador em um arquivo de texto de tipo de 
 * instrução para rastreamento e depuração
 */

#include "ram.h"

typedef enum {
    ERROR,
    HALT,
    ADD,
    SUB,
    DIV,
    MULT,    
    EXPO,
    SQRT, 
    FATORIAL,
    BHASKARA,   
    MOD,
    DECIMAL_BINARIO,
    MOV1,
    MOV2,
    RAM_LOG
} TIPO_LOG;

void criar_arquivo(void);
char *get_tipo_log_texto(TIPO_LOG tipo_log);

void gerar_log_ADD(int num1, int num2, int resultado);
void gerar_log_SUB(int num1, int num2, int resultado);
void gerar_log_MULT(int multiplicando, int multiplicador, int produto);
void gerar_log_MOD(int dividendo, int divisor, int resto);
void gerar_log_DIV(int dividendo, int divisor, int quociente);
void gerar_log_EXPO(int base, int expoente, int potencia);
void gerar_log_SQRT(int radicando, int raiz);
void gerar_log_FATORIAL(int n, int resultado);
void gerar_log_BHASKARA(int a, int b, int c, int delta, int x1, int x2);
void gerar_log_DECIMAL_BINARIO(int decimal, int binario);
void gerar_log_HALT(void);
void gerar_log_ERROR(char *mensagem);
void gerar_log_MOV1(int endereco, int valor);
void gerar_log_MOV2(int orig, int dest, int valor);
void gerar_log_RAM(const int *memoria, int tamanho);

#endif 