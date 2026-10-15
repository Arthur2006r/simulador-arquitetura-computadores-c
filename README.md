# Simulador Arquitetura Computadores em C

Simulador completo de arquitetura de computadores desenvolvido em C como Trabalho Prático da disciplina de Organização de Computadores (BCC136) na Universidade Federal de Ouro Preto (UFOP).

O objetivo do projeto é recriar em software os componentes essenciais de um computador e simular o ciclo completo de Busca (*Fetch*), Decodificação (*Decode*) e Execução (*Execute*) de instruções em baixo nível.

---

## Funcionalidades e Componentes

- **Módulo de CPU e Registradores:** Controle do ciclo de instrução e gerenciamento do estado dos registradores internos (como *Program Counter* / PC e Registrador de Instrução / IR).
- **Memória RAM Simulada:** Leitura e escrita de dados e instruções com endereçamento direto em posições de memória.
- **Mapeamento de Operações de Alto Nível:** Resolução de cálculos complexos construídos exclusivamente a partir de instruções primitivas de máquina e desvios.
- **Sistema Rastreável de Logs (`log.txt`):** Gravação detalhada do estado dos registradores e da RAM a cada ciclo simulado para depuração e verificação do comportamento "por baixo dos panos".

---

## Operações Mapeadas no Simulador

O sistema possui um menu interativo que permite testar diversos níveis de complexidade de cálculo:

| Opção | Operação | Descrição |
| :---: | :--- | :--- |
| `1` | **Soma** | Operação aritmética direta entre registradores |
| `2` | **Subtração** | Subtração direta de valores em memória |
| `3` | **Mod** | Resto da divisão inteira |
| `4` | **Divisão** | Divisão inteira via instruções de máquina |
| `5` | **Multiplicação** | Multiplicação construída sobre somas/desvios |
| `6` | **Exponenciação** | Potenciação $a^b$ por repetição de operações |
| `7` | **Raiz Quadrada** | Cálculo aproximado de raiz |
| `8` | **Fatorial** | Resolução vetorial/acumulativa em memória |
| `9` | **Bhaskara** | Resolução da equação de 2º grau ($ax^2 + bx + c = 0$) |
| `10` | **Decimal para Binário** | Conversão de base com manipulação de bits |
| `11` | **Determinante de Matriz 4x4** | Processamento matricial complexo em RAM |
| `-1` | **Sair** | Finaliza a execução do simulador |

---

## Como Compilar e Executar

### Pré-requisitos
- Compilador C instalado (`gcc` ou `clang`).
- Ambiente Linux/Unix ou WSL (Windows Subsystem for Linux).

### Passos para execução

1. **Clone o repositório:**
   ```bash
   git clone [https://github.com/seu-usuario/simulador-arquitetura-computadores.git](https://github.com/seu-usuario/simulador-arquitetura-computadores.git)
   cd simulador-arquitetura-computadores
