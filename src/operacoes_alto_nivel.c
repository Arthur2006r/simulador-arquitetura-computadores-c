#include <stdio.h>

#include "operacoes_alto_nivel.h"

static int desenvolvimento_laplace(CPU *cpu, RAM *ram, int *matriz, int n) {
    if (n == 1) return matriz[0];

    if (n == 2) {
        multiplicar(cpu, ram, matriz[0], matriz[3]);
        int p1 = get_valor(cpu, ram, 0);

        multiplicar(cpu, ram, matriz[1], matriz[2]);
        int p2 = get_valor(cpu, ram, 0);

        set_valor(cpu, ram, p1, 0);
        set_valor(cpu, ram, p2, 1);
        subtrair(cpu, ram, 0, 1);
        return get_valor(cpu, ram, 0);
    }

    int det = 0;
    int sinal = 1;

    set_valor(cpu, ram, n, 0);
    set_valor(cpu, ram, 1, 1);
    subtrair(cpu, ram, 0, 1);
    int n_sub = get_valor(cpu, ram, 0);

    multiplicar(cpu, ram, n_sub, n_sub);
    int tam_submatriz = get_valor(cpu, ram, 0);

    for (int col = 0; col < n; col++) {
        int submatriz[tam_submatriz];
        int k = 0;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j == col) continue;

                multiplicar(cpu, ram, i, n);
                int in = get_valor(cpu, ram, 0);

                set_valor(cpu, ram, in, 0);
                set_valor(cpu, ram, j, 1);
                somar(cpu, ram, 0, 1);
                int pos = get_valor(cpu, ram, 0);

                submatriz[k] = matriz[pos];

                set_valor(cpu, ram, k, 0);
                set_valor(cpu, ram, 1, 1);
                somar(cpu, ram, 0, 1);
                k = get_valor(cpu, ram, 0);
            }
        }

        int sub_det = desenvolvimento_laplace(cpu, ram, submatriz, n_sub);

        multiplicar(cpu, ram, matriz[col], sub_det);
        int termo = get_valor(cpu, ram, 0);

        set_valor(cpu, ram, det, 0);
        set_valor(cpu, ram, termo, 1);

        if (sinal == 1) {
            somar(cpu, ram, 0, 1);
        } else {
            subtrair(cpu, ram, 0, 1);
        }

        det = get_valor(cpu, ram, 0);

        set_valor(cpu, ram, 0, 0);
        set_valor(cpu, ram, sinal, 1);
        subtrair(cpu, ram, 0, 1);
        sinal = get_valor(cpu, ram, 0);
    }

    return det;
}

/**
 * Funções para simular operações matemáticas em alto nível
 */

void somar(CPU *cpu, RAM *ram, int add1, int add2) {
    int num1 = get_valor(cpu, ram, add1);
    int num2 = get_valor(cpu, ram, add2);

    Instrucao *instrucoes = aloca_instrucoes(2);

    set_instrucoes(instrucoes, 0, add1, add2, add1, OP_ADD); // Instrucao 1: somar valores
    set_instrucoes(instrucoes, 1, -1, -1, -1, OP_HALT); // Instrucao 2: encerrar programa

    set_programa(cpu, instrucoes);
    executar_programa(cpu, ram);

    int resultado = get_valor(cpu, ram, add1);

    gerar_log_ADD(num1, num2, resultado);
} 

void subtrair(CPU *cpu, RAM *ram, int add1, int add2) {
    int num1 = get_valor(cpu, ram, add1);
    int num2 = get_valor(cpu, ram, add2);

    Instrucao *instrucoes = aloca_instrucoes(2);

    set_instrucoes(instrucoes, 0, add1, add2, add1, OP_SUB); // Instrucao 1: subtrair valores
    set_instrucoes(instrucoes, 1, -1, -1, -1, OP_HALT); // Instrucao 2: encerrar programa

    set_programa(cpu, instrucoes);
    executar_programa(cpu, ram);

    int resultado = get_valor(cpu, ram, add1);

    gerar_log_SUB(num1, num2, resultado);
}

void multiplicar(CPU *cpu, RAM *ram, int multiplicando, int multiplicador) {
    set_valor(cpu, ram, 0, 0);
    set_valor(cpu, ram, multiplicando, 1);

    if (multiplicador >= 0) {
        for (int i = 0; i < multiplicador; i++) {
            somar(cpu, ram, 0, 1);
        }
    } else {
        int limite = -multiplicador;
        for (int i = 0; i < limite; i++) {
            subtrair(cpu, ram, 0, 1);
        }
    }

    int produto = get_valor(cpu, ram, 0);

    gerar_log_MULT(multiplicando, multiplicador, produto);
}

void mod(CPU *cpu, RAM *ram, int dividendo, int divisor) {
    set_valor(cpu, ram, dividendo, 0);
    set_valor(cpu, ram, divisor, 1);
    
    while(dividendo >= divisor) {
        subtrair(cpu, ram, 0, 1);

        dividendo = get_valor(cpu, ram, 0);
    }

    int resto = dividendo;
    
    gerar_log_MOD(dividendo, divisor, resto);
}

void dividir(CPU *cpu, RAM *ram, int dividendo, int divisor) {
    set_valor(cpu, ram, dividendo, 0);
    set_valor(cpu, ram, divisor, 1);
    set_valor(cpu, ram, 1, 2);
    set_valor(cpu, ram, 0, 3);
    
    while(dividendo >= divisor) {
        subtrair(cpu, ram, 0, 1);
        somar(cpu, ram, 3, 2);

        dividendo = get_valor(cpu, ram, 0);
    }

    int quociente = get_valor(cpu, ram, 3);
    
    gerar_log_DIV(dividendo, divisor, quociente);
}

void exponenciar(CPU *cpu, RAM *ram, int base, int expoente) {
    int acumulador = 1;

    for(int i = 0; i < expoente; i++) {
        multiplicar(cpu, ram, acumulador, base);
        acumulador = get_valor(cpu, ram, 0);
    }

    set_valor(cpu, ram, acumulador, 0);

    gerar_log_EXPO(base, expoente, acumulador);
}

void raiz_quadrada(CPU *cpu, RAM *ram, int radicando) {
    set_valor(cpu, ram, radicando, 0);
    set_valor(cpu, ram, 1, 1);
    set_valor(cpu, ram, 2, 2);
    set_valor(cpu, ram, 1, 3);
    set_valor(cpu, ram, 0, 4);

    while(radicando > 0) {
        subtrair(cpu, ram, 0, 1);
        somar(cpu, ram, 1, 2);         
        somar(cpu, ram, 4, 3);

        radicando = get_valor(cpu, ram, 0);
    }

    int raiz = get_valor(cpu, ram, 4);

    gerar_log_SQRT(radicando, raiz); 
}

void fatorial(CPU *cpu, RAM *ram, int n) {
    int acumulador = 1;

    // n! = 1 x 2 x 3 x ... x n
    for(int i = 2; i <= n; i++) {
        multiplicar(cpu, ram, acumulador, i);
        acumulador = get_valor(cpu, ram, 0);
    }

    set_valor(cpu, ram, acumulador, 0);

    gerar_log_FATORIAL(n, acumulador);
}

void bhaskara(CPU *cpu, RAM *ram, int a, int b, int c) {
    // se a for negativo, multiplica a equação por -1 (as raízes continuam as mesmas)
    if(a < 0) {
        a = -a;
        b = -b;
        c = -c;
    }

    // valor absoluto de b (o multiplicar só aceita multiplicador positivo)
    int abs_b = b;
    if(abs_b < 0)
        abs_b = -abs_b;

    // delta = b^2 - 4ac
    multiplicar(cpu, ram, abs_b, abs_b);
    int b2 = get_valor(cpu, ram, 0);

    multiplicar(cpu, ram, 4, a);
    int quatro_a = get_valor(cpu, ram, 0);

    multiplicar(cpu, ram, c, quatro_a);
    int quatro_ac = get_valor(cpu, ram, 0);

    set_valor(cpu, ram, b2, 0);
    set_valor(cpu, ram, quatro_ac, 1);
    subtrair(cpu, ram, 0, 1);

    int delta = get_valor(cpu, ram, 0);

    set_valor(cpu, ram, delta, 7); // guarda o delta na RAM (posição 7)

    // delta negativo: não existem raízes reais
    if(delta < 0) {
        gerar_log_ERROR("Bhaskara: delta negativo, nao existem raizes reais.");
        return;
    }

    raiz_quadrada(cpu, ram, delta);
    int raiz = get_valor(cpu, ram, 4);

    multiplicar(cpu, ram, 2, a);
    int dois_a = get_valor(cpu, ram, 0);

    // numerador_1 = -b + raiz
    set_valor(cpu, ram, 0, 0);
    set_valor(cpu, ram, b, 1);
    set_valor(cpu, ram, raiz, 2);
    subtrair(cpu, ram, 0, 1);   // 0 - b
    somar(cpu, ram, 0, 2);      // + raiz
    int numerador_1 = get_valor(cpu, ram, 0);

    // numerador_2 = -b - raiz (tira a raiz duas vezes do numerador_1)
    subtrair(cpu, ram, 0, 2);
    subtrair(cpu, ram, 0, 2);
    int numerador_2 = get_valor(cpu, ram, 0);

    // o dividir só funciona com números positivos, então tratamos o sinal aqui
    int x1, x2;

    if(numerador_1 < 0) {
        dividir(cpu, ram, -numerador_1, dois_a);
        x1 = -get_valor(cpu, ram, 3);
    } else {
        dividir(cpu, ram, numerador_1, dois_a);
        x1 = get_valor(cpu, ram, 3);
    }

    if(numerador_2 < 0) {
        dividir(cpu, ram, -numerador_2, dois_a);
        x2 = -get_valor(cpu, ram, 3);
    } else {
        dividir(cpu, ram, numerador_2, dois_a);
        x2 = get_valor(cpu, ram, 3);
    }

    set_valor(cpu, ram, x1, 5); // x1 na posição 5 da RAM
    set_valor(cpu, ram, x2, 6); // x2 na posição 6 da RAM

    gerar_log_BHASKARA(a, b, c, delta, x1, x2);
}

void decimal_para_binario(CPU *cpu, RAM *ram, int decimal) {
    int resto, unidade = 1, binario = 0;

    while(decimal >= 1) {
        mod(cpu, ram, decimal, 2);
        resto = get_valor(cpu, ram, 0);

        dividir(cpu, ram, decimal, 2);
        decimal = get_valor(cpu, ram, 3);

        multiplicar(cpu, ram, resto, unidade);

        set_valor(cpu, ram, binario, 1);
        somar(cpu, ram, 1, 0);
        binario = get_valor(cpu, ram, 1);

        multiplicar(cpu, ram, unidade, 10);
        unidade = get_valor(cpu, ram, 0);
    }

    set_valor(cpu, ram, binario, 0);

    gerar_log_DECIMAL_BINARIO(decimal, binario);
}

int get_valor(CPU *cpu, RAM *ram, int add1) {
    Instrucao *instrucoes = aloca_instrucoes(2);

    set_instrucoes(instrucoes, 0, 1, add1, -1, OP_MOV2);
    set_instrucoes(instrucoes, 1, -1, -1, -1, OP_HALT);

    set_programa(cpu, instrucoes);
    executar_programa(cpu, ram);

    return get_registrador_1(cpu);
}

void set_valor(CPU *cpu, RAM *ram, int valor, int add1) {
    Instrucao *instrucoes = aloca_instrucoes(2);

    set_registrador_1(cpu, valor);

    set_instrucoes(instrucoes, 0, 1, add1, -1, OP_MOV1);
    set_instrucoes(instrucoes, 1, -1, -1, -1, OP_HALT);

    set_programa(cpu, instrucoes);
    executar_programa(cpu, ram);
}

void determinante(CPU *cpu, RAM *ram, int n) {
    int matriz[n * n];
    for (int i = 0; i < n * n; i++) {
        matriz[i] = get_valor(cpu, ram, i);
    }

    int res = desenvolvimento_laplace(cpu, ram, matriz, n);

    set_valor(cpu, ram, res, n * n);
}