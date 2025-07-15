#include "FilaEncapsulada.h"
#include <iostream>

FilaEncapsulada::No::No(int valor) {
    dado = valor;
    proximo = nullptr;
}

FilaEncapsulada::FilaEncapsulada() {
    frente = nullptr;
    tras = nullptr;
    tamanho = 0;
}

FilaEncapsulada::~FilaEncapsulada() {
    while (!vazia()) {
        desenfileirar();
    }
}

void FilaEncapsulada::enfileirar(int valor) {
    No* novo = new No(valor);
    if (vazia()) {
        frente = tras = novo;
    } else {
        tras->proximo = novo;
        tras = novo;
    }
    tamanho++;
}

int FilaEncapsulada::desenfileirar() {
    if (vazia()) throw std::runtime_error("Fila vazia");
    int valor = frente->dado;
    No* temp = frente;
    frente = frente->proximo;
    delete temp;
    if (frente == nullptr) tras = nullptr;
    tamanho--;
    return valor;
}

int FilaEncapsulada::frenteValor() const {
    if (vazia()) throw std::runtime_error("Fila vazia");
    return frente->dado;
}

bool FilaEncapsulada::vazia() const {
    return frente == nullptr;
}

int FilaEncapsulada::getTamanho() const {
    return tamanho;
}

void FilaEncapsulada::imprimir() const {
    No* atual = frente;
    std::cout << "Frente -> ";
    while (atual != nullptr) {
        std::cout << atual->dado << " ";
        atual = atual->proximo;
    }
    std::cout << "<- Trás" << std::endl;
}