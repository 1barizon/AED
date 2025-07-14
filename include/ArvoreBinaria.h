#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H

#include <iostream>
#include "elemento.h"

template <typename T>
class ArvoreBinaria 
{
    private:
     
        class No 
        {
            public:
                T dado;
                No* direita;
                No* esquerda;

                No(t val) : dado(val), direita(nullptr), esquerda(nullptr) {}
        };

        No* raiz;
        No* InserirAux(No* no, const T& elemento); //função recurssiva auxiliar de inserção
        No* RemoverAux(No* no, T elemento); //função recurssiva auxiliar de remoção
        void limpar(No* no);
        int alturaAux(No* no) const;
    
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();

        void InserirValor(T elemento);
        void RemoverValor(T elemento);
        T BuscarValor(const T& elemento) const;
        int altura() const;


};


#endif