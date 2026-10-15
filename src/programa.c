#include <stdlib.h>
#include <stdio.h>

#include "programa.h"

/**
 * Funções da biblioteca a partir do uso dos compoenentes do computador
 */

/*
void executar_programa_aleatorio(RAM *ram, CPU *cpu, int quantidade_instrucoes) {
    Instrucao *programa = aloca_instrucoes(quantidade_instrucoes);
    int random = rand(), tamanho_RAM = 1000;

    ram = criar_RAM_aleatoria(tamanho_RAM);
    
    for(int i = 0; i < (quantidade_instrucoes - 1); i++) {
        int opcode = rand() % 2, add1 = rand() % tamanho_RAM,
            add2 = rand() % tamanho_RAM, add3 = rand() % tamanho_RAM;
    
        set_instrucoes(programa, i, add1, add2, add3, opcode);
    }

    set_instrucoes(programa, quantidade_instrucoes - 1, -1, -1, -1, HALT);

    set_programa(cpu, programa);
    executar_programa(cpu, ram);
}
*/

int executar_soma(RAM *ram, CPU *cpu, int num1, int num2) {
    int soma;

    ram = criar_RAM_vazia(5);

    set_valor(cpu, ram, num1, 0);
    set_valor(cpu, ram, num2, 1);

    somar(cpu, ram, 0, 1);

    soma = get_valor(cpu, ram, 0);

    return soma;
}

int executar_subtracao(RAM *ram, CPU *cpu, int num1, int num2) {
    int subtracao;

    ram = criar_RAM_vazia(5);

    set_valor(cpu, ram, num1, 0);
    set_valor(cpu, ram, num2, 1);

    subtrair(cpu, ram, 0, 1);

    subtracao = get_valor(cpu, ram, 0);

    return subtracao;
}

int executar_mod(RAM *ram, CPU *cpu, int dividendo, int divisor) {
    int resto;

    ram = criar_RAM_vazia(5);

    mod(cpu, ram, dividendo, divisor);

    resto = get_valor(cpu, ram, 0);

    return resto;
}

int executar_divisao(RAM *ram, CPU *cpu, int dividendo, int divisor) {
    int quociente;

    ram = criar_RAM_vazia(5);

    dividir(cpu, ram, dividendo, divisor);

    quociente = get_valor(cpu, ram, 3);

    return quociente;
}

int executar_multiplicacao(RAM *ram, CPU *cpu, int multiplicando, int multiplicador) {
    int produto;
    
    ram = criar_RAM_vazia(5);

    multiplicar(cpu, ram, multiplicando, multiplicador);

    produto = get_valor(cpu, ram, 0);

    return produto;
}

int executar_exponenciacao(RAM *ram, CPU *cpu, int base, int expoente) {
    int potencia;
    
    ram = criar_RAM_vazia(5);

    exponenciar(cpu, ram, base, expoente);

    potencia = get_valor(cpu, ram, 0);

    return potencia;
}

int executar_raiz_quadrada(RAM *ram, CPU *cpu, int radicando) {
    int raiz;

    ram = criar_RAM_vazia(5);

    raiz_quadrada(cpu, ram, radicando);

    raiz = get_valor(cpu, ram, 4);

    return raiz;
}

int executar_fatorial(RAM *ram, CPU *cpu, int n) {
    int resultado;

    if(n < 0 || n > 12) {
        gerar_log_ERROR("Fatorial: n deve estar entre 0 e 12.");
        return -1;
    }

    ram = criar_RAM_vazia(5);

    fatorial(cpu, ram, n);

    resultado = get_valor(cpu, ram, 0);

    return resultado;
}

int executar_bhaskara(RAM *ram, CPU *cpu, int a, int b, int c, int *x1, int *x2) {
    if(a == 0) {
        gerar_log_ERROR("Bhaskara: o coeficiente a nao pode ser zero.");
        return -1;
    }

    ram = criar_RAM_vazia(10); // precisa de mais posições para guardar delta, x1 e x2

    bhaskara(cpu, ram, a, b, c);

    int delta = get_valor(cpu, ram, 7);

    if(delta < 0)
        return 0;

    *x1 = get_valor(cpu, ram, 5);
    *x2 = get_valor(cpu, ram, 6);

    if(delta == 0)
        return 1;

    return 2;
}

int executar_decimal_para_binario(RAM *ram, CPU *cpu, int decimal) {
    int binario; 

    ram = criar_RAM_vazia(5);

    decimal_para_binario(cpu, ram, decimal);

    binario = get_valor(cpu, ram, 0);

    return binario;
}

int executar_determinante(RAM *ram, CPU *cpu, int *matriz, int n) {
    int det, tamanho_RAM = (n * n) + 50; 

    ram = criar_RAM_vazia(tamanho_RAM);

    for(int i = 0; i < n * n; i++) {
        set_valor(cpu, ram, matriz[i], i);
    }

    determinante(cpu, ram, n);

    det = get_valor(cpu, ram, n * n);

    return det;
}