#include <stdio.h>
#include <stdlib.h>

#include "ram.h"

/**
 * Estrutura de RAM
 * 
 * Define uma estrutura que representa uma memória RAM, 
 * contendo o tamanho dessa memória (tamanho) e o array
 * com os dados (*memoria)
 */
struct ram {
    int tamanho;
    int *memoria; // defido como um ponteiro, pois o tamanho do array pode variar
};

/**
 * Funções de manipulação da estrutura RAM
 */

RAM * criar_RAM(int tamanho) {
    RAM *ram = malloc(sizeof(RAM));
    if(!ram)
        return NULL;

    ram->tamanho = tamanho;
    
    ram->memoria = malloc(sizeof(int) * tamanho);
    if(!ram->memoria) 
        return NULL;

    return ram;
}

RAM * criar_RAM_vazia(int tamanho) {
    RAM *ram = malloc(sizeof(RAM));
    if(!ram)
        return NULL;

    ram->tamanho = tamanho;

    ram->memoria = calloc(sizeof(int), tamanho); // inicializa array com zero em todas as posições
    if(!ram->memoria) 
        return NULL;

    return ram;
}

RAM * criar_RAM_aleatoria(int tamanho) {
    RAM *ram = malloc(sizeof(RAM));
    if(!ram)
        return NULL;

    ram->tamanho = tamanho;

    ram->memoria = malloc(sizeof(int) * tamanho); 
    if(!ram->memoria) 
        return NULL;

    // inicializa os elementos das posições do array com valores aleatórios
    for(int i = 0; i < tamanho; i++)
        ram->memoria[i] = rand();

    return ram;
}

/**
 * Getters e Setters para a estrutura RAM
 */

void set_memoria(RAM *ram, int posicao, int valor) {
    if(posicao < ram->tamanho) 
        ram->memoria[posicao] = valor;
}

int get_memoria(const RAM *ram, int posicao) {
    if(posicao < ram->tamanho)
        return ram->memoria[posicao];

    return 0;
}

int *get_memoria_array(const RAM *ram) {
    return ram->memoria;
}

int get_tamanho(const RAM *ram) {
    return ram->tamanho;
}