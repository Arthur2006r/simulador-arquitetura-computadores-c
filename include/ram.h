#ifndef RAM_H
#define RAM_H

/**
 * Implementação do Tipo Abstrato de Dados para a memória RAM
 */

typedef struct ram RAM;

/**
 * Funções de manipulação da estrutura RAM
 */
RAM * criar_RAM(int tamanho);
RAM * criar_RAM_vazia(int tamanho);
RAM * criar_RAM_aleatoria(int tamanho);

/**
 * Getters e Setters para a estrutura RAM
 */
int get_memoria(const RAM *ram, int posicao);
int *get_memoria_array(const RAM *ram);
int get_tamanho(const RAM *ram);

void set_memoria(RAM *ram, int posicao, int valor);

#endif
