#include "../include/ArvoreBinaria.h"
#include <iostream>

template<typename T>
ArvoreBinaria<T>::ArvoreBinaria() : NdeElementos(0)
{
    raiz = nullptr;
}

template<typename T>
void ArvoreBinaria<T>::InserirValor(T elemento) {
    raiz = InserirAux(raiz, elemento);
}

template<typename T>
typename ArvoreBinaria<T>::No* ArvoreBinaria<T>::InserirAux(No* no,const T& elemento) {
    if (no == nullptr) {            //se a raiz for nula insere na propria raiz
        return new No(elemento);                 
    }

    if (elemento < no->dado)
        no->esquerda = InserirAux(no->esquerda, elemento); //se for menor que a raiz insere na esquerda se for maior na direita
    else if (elemento > no->dado)
        no->direita = InserirAux(no->direita, elemento);

    return no;
}

template<typename T>
void ArvoreBinaria<T>::RemoverValor(T elemento) {
    raiz = RemoverAux(raiz, elemento);
}

template<typename T>
typename ArvoreBinaria<T>::No* ArvoreBinaria<T>::RemoverAux(No* no, T elemento) {
    if (no == nullptr)
        throw std::runtime_error("Elemento não encontrado");

    if (elemento < no->dado) {
        no->esquerda = RemoverAux(no->esquerda, elemento);
    } else if (elemento > no->dado) {
        no->direita = RemoverAux(no->direita, elemento);
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
            no->esquerda = RemoverAux(no->esquerda, substituto->dado);
}
    }

    return no;
}

template<typename T>
T ArvoreBinaria<T>::BuscarValor(const T& elemento) const {
    No* atual = raiz;

    while (atual != nullptr) {
        if (elemento == atual->dado) {
            return atual->dado;
        } else if (elemento < atual->dado) { //busca simples por maior e menor
            atual = atual->esquerda; 
        } else {
            atual = atual->direita;
        }
    }

    throw std::runtime_error("Elemento não encontrado");
}

template<typename T>
int ArvoreBinaria<T>::altura() const {
    return alturaAux(raiz);
}

template<typename T>
int ArvoreBinaria<T>::alturaAux(No* no) const {
    if (no == nullptr) {
        return 0;                   //função que calcula a altura da árvore
    }

    int alturaEsq = alturaAux(no->esquerda);
    int alturaDir = alturaAux(no->direita);

    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

template<typename T>
ArvoreBinaria<T>::~ArvoreBinaria() {
    limpar(raiz);
    raiz = nullptr;
    NdeElementos = 0;
}

template<typename T>
void ArvoreBinaria<T>::limpar(No* no) {
    if (no != nullptr) {
        limpar(no->esquerda);
        limpar(no->direita);
        delete no;
    }
}