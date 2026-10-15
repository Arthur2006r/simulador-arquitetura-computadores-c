#include <stdio.h>
#include <stdlib.h>
#include "log.h"

// Cria/reseta o arquivo log.txt no início da execução
void criar_arquivo(void) {
    FILE *file = fopen("logs/log.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo de log!\n");
        return;
    }

    fclose(file);
}

// Retorna a string do tipo do log
char *get_tipo_log_texto(TIPO_LOG tipo_log) {
    switch (tipo_log) {
        case ERROR: return "ERROR";
        case HALT: return "HALT";
        case ADD: return "ADICAO";
        case SUB: return "SUBTRACAO";
        case DIV: return "DIVISAO";
        case MULT: return "MULTIPLICACAO";
        case EXPO: return "EXPONENCIACAO";
        case SQRT: return "RAIZ QUADRADA";
        case FATORIAL: return "FATORIAL";
        case BHASKARA: return "BHASKARA";
        case MOV1: return "MOV1";
        case MOV2: return "MOV2";
        case RAM_LOG: return "RAM";
        default: return "UNKNOW";
    }
}

// Log de Adição
void gerar_log_ADD(int num1, int num2, int resultado) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado de %d + %d = %d\n", 
                get_tipo_log_texto(ADD), num1, num2, resultado);
        fclose(file);
    }
}

// Log de Subtração
void gerar_log_SUB(int num1, int num2, int resultado) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado de %d - %d = %d\n", 
                get_tipo_log_texto(SUB), num1, num2, resultado);
        fclose(file);
    }
}

// Log de Multiplicação
void gerar_log_MULT(int multiplicando, int multiplicador, int produto) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado de %d x %d = %d\n", 
                get_tipo_log_texto(MULT), multiplicando, multiplicador, produto);
        fclose(file);
    }
}
 
void gerar_log_MOD(int dividendo, int divisor, int resto) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado mod de %d %% %d = %d\n", 
                get_tipo_log_texto(MOD), dividendo, divisor, resto);
        fclose(file);
    }
}

// Log de Divisão
void gerar_log_DIV(int dividendo, int divisor, int quociente) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado aproximado de %d / %d = %d\n", 
                get_tipo_log_texto(DIV), dividendo, divisor, quociente);
        fclose(file);
    }
}

// Log de Exponenciação
void gerar_log_EXPO(int base, int expoente, int potencia) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado de %d^%d = %d\n", 
                get_tipo_log_texto(EXPO), base, expoente, potencia);
        fclose(file);
    }
}

// Log de Raiz Quadrada
void gerar_log_SQRT(int radicando, int raiz) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado aproximado de %d^(1/2) = %d\n", 
                get_tipo_log_texto(SQRT), radicando, raiz);
        fclose(file);
    }
}

// Log de Fatorial
void gerar_log_FATORIAL(int n, int resultado) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado de %d! = %d\n",
                get_tipo_log_texto(FATORIAL), n, resultado);
        fclose(file);
    }
}

// Log de Bhaskara
void gerar_log_BHASKARA(int a, int b, int c, int delta, int x1, int x2) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: Para a=%d, b=%d, c=%d: delta = %d, x1 = %d, x2 = %d\n",
                get_tipo_log_texto(BHASKARA), a, b, c, delta, x1, x2);
        fclose(file);
    }
}

void gerar_log_DECIMAL_BINARIO(int decimal, int binario) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: O resultado da conversão de decimal para binário de %d = %d\n",
                get_tipo_log_texto(DECIMAL_BINARIO), decimal, binario);
        fclose(file);
    }
}

// Log de Término de Execução (HALT)
void gerar_log_HALT() {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: Execucao do programa finalizada.\n", 
                get_tipo_log_texto(HALT));
        fclose(file);
    }
}

// Log de Erro
void gerar_log_ERROR(char *mensagem) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: %s\n", 
                get_tipo_log_texto(ERROR), mensagem);
        fclose(file);
    }
}

// Log de MOV1 (Escrever valor na RAM/Registrador)
void gerar_log_MOV1(int endereco, int valor) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: Valor %d armazenado no endereco %d\n", 
                get_tipo_log_texto(MOV1), valor, endereco);
        fclose(file);
    }
}

// Log de MOV2 (Copiar valor de um endereço para outro)
void gerar_log_MOV2(int orig, int dest, int valor) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: Copiado valor %d do endereco %d para %d\n", 
                get_tipo_log_texto(MOV2), valor, orig, dest);
        fclose(file);
    }
}

void gerar_log_RAM(const int *memoria, int tamanho) {
    FILE *file = fopen("logs/log.txt", "a");
    if (file != NULL) {
        fprintf(file, "[%s]: ", get_tipo_log_texto(RAM_LOG));

        if (memoria != NULL && tamanho > 0) {
            fprintf(file, "[ ");
            for (int i = 0; i < tamanho; i++) {
                fprintf(file, "%d ", memoria[i]);
            }
            fprintf(file, "]\n");
        } else {
            fprintf(file, "[ Vazia ]\n");
        }

        fclose(file);
    }
}