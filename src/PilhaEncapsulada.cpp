#include "pilhaComNo.h"
#include <iostream>

Pilha::No::No(int valor) {
    dado = valor;
    proximo = nullptr;
}

Pilha::Pilha() {
    topo = nullptr;
    tamanho = 0;
}

Pilha::~Pilha() {
    while (!vazia()) {
        pop();
    }
}

void Pilha::push(int valor) {
    No* novo = new No(valor);
    novo->proximo = topo;
    topo = novo;
    tamanho++;
}

int Pilha::pop() {
    if (vazia()) throw std::runtime_error("Pilha vazia");
    int valor = topo->dado;
    No* temp = topo;
    topo = topo->proximo;
    delete temp;
    tamanho--;
    return valor;
}

int Pilha::peek() const {
    if (vazia()) throw std::runtime_error("Pilha vazia");
    return topo->dado;
}

bool Pilha::vazia() const {
    return topo == nullptr;
}

int Pilha::getTamanho() const {
    return tamanho;
}

void Pilha::imprimir() const {
    No* atual = topo;
    std::cout << "Topo -> ";
    while (atual != nullptr) {
        std::cout << atual->dado << " ";
        atual = atual->proximo;
    }
    std::cout << std::endl;
}