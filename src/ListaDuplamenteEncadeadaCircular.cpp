#include "ListaDuplamenteEncadeadaCircular.h"
#include <iostream> // Para std::cout, etc.

ListaDuplamenteEncadeadaCircular::ListaDuplamenteEncadeadaCircular() : cabeca(nullptr), tamanho(0) {}

ListaDuplamenteEncadeadaCircular::~ListaDuplamenteEncadeadaCircular() {
    if (cabeca == nullptr) {
        return;
    }

    No* atual = cabeca->proximo;
    while (atual != cabeca) {
        No* proximoNo = atual->proximo;
        delete atual;
        atual = proximoNo;
    }
    delete cabeca;
    cabeca = nullptr;
    tamanho = 0;
}

bool ListaDuplamenteEncadeadaCircular::estaVazia() const {
    return cabeca == nullptr;
}

int ListaDuplamenteEncadeadaCircular::getTamanho() const {
    return tamanho;
}

void ListaDuplamenteEncadeadaCircular::inserirNoInicio(Elemento* elemento) {
    if (elemento == nullptr) {
        std::cerr << "Erro: Tentativa de inserir elemento nulo." << std::endl;
        return;
    }
    No* novoNo = new No(elemento);
    if (estaVazia()) {
        cabeca = novoNo;
        cabeca->proximo = cabeca;
        cabeca->anterior = cabeca;
    } else {
        No* ultimo = cabeca->anterior;
        novoNo->proximo = cabeca;
        novoNo->anterior = ultimo;
        cabeca->anterior = novoNo;
        ultimo->proximo = novoNo;
        cabeca = novoNo;
    }
    tamanho++;
}

void ListaDuplamenteEncadeadaCircular::inserirNoFinal(Elemento* elemento) {
    if (elemento == nullptr) { // Verificação de segurança
        std::cerr << "Erro: Tentativa de inserir elemento nulo." << std::endl;
        return;
    }
    No* novoNo = new No(elemento);
    if (estaVazia()) {
        cabeca = novoNo;
        cabeca->proximo = cabeca;
        cabeca->anterior = cabeca;
    } else {
        No* ultimo = cabeca->anterior;
        novoNo->proximo = cabeca;
        novoNo->anterior = ultimo;
        cabeca->anterior = novoNo;
        ultimo->proximo = novoNo;
    }
    tamanho++;
}

bool ListaDuplamenteEncadeadaCircular::remover(int id) {
    if (estaVazia()) {
        return false;
    }

    No* atual = cabeca;
    do {
        if (atual->dado->getID() == id) {
            // Caso especial: remover o único nó
            if (tamanho == 1) {
                delete cabeca;
                cabeca = nullptr;
            } else {
                atual->anterior->proximo = atual->proximo;
                atual->proximo->anterior = atual->anterior;
                if (atual == cabeca) {
                    cabeca = atual->proximo;
                }
                delete atual; 
            }
            tamanho--;
            return true;
        }
        atual = atual->proximo;
    } while (atual != cabeca);

    return false;
}

Elemento* ListaDuplamenteEncadeadaCircular::buscar(int id) const {
    if (estaVazia()) {
        return nullptr;
    }

    No* atual = cabeca;
    do {
        if (atual->dado->getID() == id) {
            return atual->dado; // Retorna o ponteiro para o Elemento encontrado
        }
        atual = atual->proximo;
    } while (atual != cabeca);

    return nullptr;
}

void ListaDuplamenteEncadeadaCircular::exibirParaFrente() const {
    if (estaVazia()) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    No* atual = cabeca;
    std::cout << "Lista (para frente): ";
    do {
        atual->dado->imprimirInfo();
        std::cout << " ";
        atual = atual->proximo;
    } while (atual != cabeca);
    std::cout << std::endl;
}

void ListaDuplamenteEncadeadaCircular::exibirParaTras() const {
    if (estaVazia()) {
        std::cout << "Lista vazia." << std::endl;
        return;
    }

    No* atual = cabeca->anterior;
    std::cout << "Lista (para tras): ";
    do {
        atual->dado->imprimirInfo();
        std::cout << " ";
        atual = atual->anterior;
    } while (atual != cabeca->anterior);
    std::cout << std::endl;
}