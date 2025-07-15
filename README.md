# AED - Algoritmos e Estruturas de Dados

Projeto de Algoritmos e Estruturas de Dados desenvolvido em C++.



# Alunos.

João Victor Barizon - 202410067411  
Antônio Neto - 202410069311  
João Dias Stilben - 202410068111
Davi silvério - 202410069011


## Estrutura do Projeto

```
AED/
├── src/           # Arquivos fonte (.cpp)
├── include/       # Arquivos header (.h)
├── bin/           # Executáveis compilados
├── build/         # Arquivos objeto e temporários
├── tests/         # Testes unitários
├── Makefile       # Arquivo de build (Make)
├── CMakeLists.txt # Arquivo de build (CMake)
└── README.md      # Este arquivo
```

## Como Compilar

### Usando Make
```bash
make all       # Compila o projeto
make run       # Executa o programa
make test      # Compila e executa
make clean     # Limpa arquivos compilados
```

### Usando CMake
```bash
mkdir build
cd build
cmake ..
make
```

### Compilação Manual
```bash
g++ -std=c++17 -Wall -Wextra -Iinclude src/*.cpp -o bin/main
```

## Executar
```bash
./bin/main
```

## Contribuição
Este projeto segue as práticas de programação orientada a objetos e estruturas de dados.
