#ifndef ARVORE_BINARIA_H
#define ARVORE_BINARIA_H
#include "elemento.h"
#include <iostream>
class ArvoreBinaria 
{
    private:
     
        class No 
        {
            public:
                Elemento* dado;
                No* direita;
                No* esquerda;

                No(Elemento* item) : dado(item), direita(nullptr), esquerda(nullptr) {}
        };

        No* raiz;
        No* InserirAux(No* no,Elemento& item); //função recurssiva auxiliar de inserção
        No* RemoverAux(No* no,Elemento& item); //função recurssiva auxiliar de remoção
        void emOrdemAux(No* no) const;
        void preOrdemAux(No* no) const;
        void posOrdemAux(No* no) const;
        void limpar(No* no);
        int alturaAux(No* no) const;
    
    public:
        ArvoreBinaria();
        ~ArvoreBinaria();

        void Inserir(Elemento* item);
        void RemoverPeloID(Elemento* item);
        Elemento* BuscarPeloID(Elemento& item);
        int altura() const;
        void emOrdem() const;
        void preOrdem() const;
        void posOrdem() const;

};

class ElementoConcreto : public Elemento {
public:
    ElementoConcreto(int id) : Elemento(id) {}
    void imprimirInfo() const override {
        std::cout << "ID: " << ID << std::endl;
    }
};


#endif