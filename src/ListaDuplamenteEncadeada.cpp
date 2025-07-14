#include "../include/ListaDuplamenteEncadeada.h"
#include <iostream>

template<typename T>
ListaDuplamenteEncadeada<T>::ListaDuplamenteEncadeada() : tamanhoAtual(0)
{
    head = nullptr;
    tail = nullptr;
}

template<typename T>
void ListaDuplamenteEncadeada<T>::xInserirNoInicio(T elemento) {
    No* novo = new No(elemento);
    novo->proximo = head;
    novo->anterior = nullptr;

    if (head != nullptr) {
        head->anterior = novo; //verifica se o cabeca é nulo, se essa informação for verdadeira a cauda assume o valor de novo, se não for, o anterior do cabeça assume esse papel
    } else {

        tail = novo;
    }

    head = novo;
    tamanhoAtual++;
}

template<typename T>
void ListaDuplamenteEncadeada<T>::xInserirNoFinal(T elemento) {
    No* novo = new No(elemento);
    novo->proximo = nullptr;
    novo->anterior = tail;

    if (tail != nullptr) {
        tail->proximo = novo; //logica semelhante a da função anterior mas invertendo a ordem de cabeça e cauda
    } else {
        
        head = novo;
    }

    tail = novo;
    tamanhoAtual++;
}

template<typename T>
T ListaDuplamenteEncadeada<T>::xRemoverPrimeiro() {
    if (head == nullptr) {
        throw std::out_of_range("A lista está vazia"); //se a lista estiver vazia indica impossibilidade de remoção
    }

    No* removido = head; //guarda o ponteiro para o nó a ser removido
    T dado = removido->dado; //pega o valor que sera retornado

    head = head->proximo; //avança o cabeca para o seu posterior

    if (head != nullptr) {
        head->anterior = nullptr; //se o cabeca n se tornar nulo, atualiza seu anterior
    } else {
        tail = nullptr;//se a lista ficou vazia torna a cauda nula
    }

    delete removido;//deleta o no removido
    tamanhoAtual--;//reduz o tamanho da lista

    return dado;//retorna o valor removido
}

template<typename T>
T ListaDuplamenteEncadeada<T>::xRemoverUltimo() { //no geral, segue a mesma ideia do RemoverPrimeiro mas retrocede a cauda o inves de avançar o cabeca
    if (tail == nullptr) {
        throw std::out_of_range("A lista está vazia");
    }

    No* removido = tail;
    T dado = removido->dado;

    tail = tail->anterior;

    if (tail != nullptr) {
        tail->proximo = nullptr;
    } else {
        head = nullptr;
    }

    delete removido;
    tamanhoAtual--;

    return dado;
}

template<typename T>
T ListaDuplamenteEncadeada<T>::xRemoverPeloId(int id) {
    if (head == nullptr) {
        throw std::out_of_range("Lista vazia");
    }

    No* atual = head;

    while (atual != nullptr) {//percorre do cabeca ate a cauda enquanto n for nulo
        if (atual->dado.getId() == id) { //se achou
            T dadoRemovido = atual->dado; //salva o valor em dado

            if (atual->anterior != nullptr) {
                atual->anterior->proximo = atual->proximo; //se tinha um anterior estabelece que o proximo do anterior é o proximo do atual (como se removesse um meio)
            } else {
                head = atual->proximo; //se n tinha anterior o cabeca é o proximo do que foi removido
            }

            if (atual->proximo != nullptr) {
                atual->proximo->anterior = atual->anterior; // no geral a mesma ideia que em cima
            } else {
                tail = atual->anterior;
            }

            delete atual;
            tamanhoAtual--;

            return dadoRemovido;
        }

        atual = atual->proximo;
    }

    throw std::runtime_error("Elemento com id não encontrado");
}

template<typename T>
T ListaDuplamenteEncadeada<T>::xBuscarPeloId(int id) const {
    No* atual = head;

    while (atual != nullptr) { //percorre toda lista 
        if (atual->dado.getId() == id) {
            return atual->dado; //retorna o dado quando achou o id
        }
        atual = atual->proximo; 
    }

    throw std::runtime_error("Elemento com o id não encontrado");
}

template<typename T>
bool ListaDuplamenteEncadeada<T>::estaVazia() const {
    return tamanhoAtual == 0;
}

template<typename T>
int ListaDuplamenteEncadeada<T>::getTamanho() const {
    return tamanhoAtual;
}

template<typename T>
T ListaDuplamenteEncadeada<T>::getPrimeiro() const {
    if (head == nullptr)
        throw std::out_of_range("Lista vazia");
    return head->dado;
}

template<typename T>
T ListaDuplamenteEncadeada<T>::getUltimo() const {
    if (tail == nullptr)
        throw std::out_of_range("Lista vazia");
    return tail->dado;
}

template<typename T>
void ListaDuplamenteEncadeada<T>::imprimirLista() const {
    No* atual = head;
    while (atual != nullptr) {
        std::cout << atual->dado << " -> ";
        atual = atual->proximo;
    }
    std::cout << "null\n";
}

template<typename T>
ListaDuplamenteEncadeada<T>::~ListaDuplamenteEncadeada() {
    No* atual = head;
    while (atual != nullptr) {
        No* proximo = atual->proximo;
        delete atual;
        atual = proximo;
    }
    head = nullptr;
    tail = nullptr;
    tamanhoAtual = 0;
}