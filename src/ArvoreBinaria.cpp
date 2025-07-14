#include "../include/ArvoreBinaria.h"
#include <iostream>

ArvoreBinaria::ArvoreBinaria()
{
    raiz = nullptr;
}

void ArvoreBinaria::Inserir(Elemento* item) {
    raiz = InserirAux(raiz, *item);
}

typename ArvoreBinaria::No* ArvoreBinaria::InserirAux(No* no, Elemento  &item) {
    if (no == nullptr) {            //se a raiz for nula insere na propria raiz
        return new No(&item);                 
    }

    if (item.getID() < (no->dado)->getID())
        no->esquerda = InserirAux(no->esquerda, item); //se for menor que a raiz insere na esquerda se for maior na direita
    else if (item.getID() > (no->dado)->getID())
        no->direita = InserirAux(no->direita, item);

    return no;
}

void ArvoreBinaria::RemoverPeloID(Elemento* item) {
    raiz = RemoverAux(raiz, *item);
}

typename ArvoreBinaria::No* ArvoreBinaria::RemoverAux(No* no, Elemento& item) {
    if (no == nullptr)
        throw std::runtime_error("Elemento não encontrado");

    if (item.getID() < (no->dado)->getID()) {
        no->esquerda = RemoverAux(no->esquerda, item);
    } else if (item.getID() > (no->dado)->getID()) {
        no->direita = RemoverAux(no->direita, item);
    } else {
        if (no->esquerda == nullptr && no->direita == nullptr) {
            delete no;  //se a pagina não tem filhos so remove
            return nullptr;
        } else if (no->esquerda == nullptr) {
            No* temp = no->direita;
            delete no; //se a pagina tem filho na direita a pagina é excluida e o filho se realoca
            return temp; //filho retorna para o ponteiro do pai
        } else if (no->direita == nullptr) {
            No* temp = no->esquerda;
            delete no;
            return temp;
        }else {
    
            No* substituto = no->esquerda;
            while (substituto->direita != nullptr)
            substituto = substituto->direita;

            no->dado = substituto->dado;
            no->esquerda = RemoverAux(no->esquerda, *substituto->dado);
}
    }

    return no;
}

Elemento* ArvoreBinaria::BuscarPeloID( Elemento& item) {
    No* atual = raiz;

    while (atual != nullptr) {
        if (item.getID() == (atual->dado)->getID()) {
            return  atual->dado;
        } else if (item.getID() < (atual->dado)->getID()) { //busca simples por maior e menor
            atual = atual->esquerda; 
        } else {
            atual = atual->direita;
        }
    }

    throw std::runtime_error("Elemento não encontrado");
}


int ArvoreBinaria::altura() const {
    return alturaAux(raiz);
}


int ArvoreBinaria::alturaAux(No* no) const {
    if (no == nullptr) {
        return 0;                   //função que calcula a altura da árvore
    }

    int alturaEsq = alturaAux(no->esquerda);
    int alturaDir = alturaAux(no->direita);

    return 1 + std::max(alturaEsq, alturaDir);
}

void ArvoreBinaria::emOrdem() const {
    emOrdemAux(raiz);
    std::cout << std::endl;
}

void ArvoreBinaria::emOrdemAux(No* no) const {
    if (no != nullptr) {
        emOrdemAux(no->esquerda);
        std::cout << no->dado->getID() << " ";
        emOrdemAux(no->direita);
    }
}

void ArvoreBinaria::preOrdem() const {
    preOrdemAux(raiz);
    std::cout << std::endl;
}

void ArvoreBinaria::preOrdemAux(No* no) const {
    if (no != nullptr) {
        std::cout << no->dado->getID() << " ";
        preOrdemAux(no->esquerda);
        preOrdemAux(no->direita);
    }
}

void ArvoreBinaria::posOrdem() const {
    posOrdemAux(raiz);
    std::cout << std::endl;
}

void ArvoreBinaria::posOrdemAux(No* no) const {
    if (no != nullptr) {
        posOrdemAux(no->esquerda);
        posOrdemAux(no->direita);
        std::cout << no->dado->getID() << " ";
    }
}


ArvoreBinaria::~ArvoreBinaria() {
    limpar(raiz);
    raiz = nullptr;
}


void ArvoreBinaria::limpar(No* no) {
    if (no != nullptr) {
        limpar(no->esquerda);
        limpar(no->direita);
        delete no;
    }
}