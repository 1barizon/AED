
#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H 
#include "elemento.h"
#include <iostream>
class ListaDuplamenteEncadeada {
private:

    class No {
    public:
        Elemento* dado;  
        No* proximo;  
        No* anterior;  

        No(Elemento* item) : dado(item), proximo(nullptr), anterior(nullptr) {}
    };

    No* head;        
    No* tail;        
    int tamanhoAtual; 

public:
    // Construtor e Destrutor
    ListaDuplamenteEncadeada();
    ~ListaDuplamenteEncadeada();

    void InserirNoInicio(Elemento* item);
    void InserirNoFinal(Elemento* item);
    Elemento* RemoverPrimeiro();
    Elemento* RemoverUltimo();
    Elemento* RemoverPeloId(int id);
    Elemento* BuscarPeloId(int id) const;
    void AlterarPeloId(int id, Elemento* novoItem);

    bool estaVazia() const;
    int getTamanho() const;
    Elemento* getPrimeiro() const;
    Elemento* getUltimo() const;
    void imprimirLista() const; 
};
class ElementoConcreto : public Elemento {
public:
    ElementoConcreto(int id) : Elemento(id) {}
    void imprimirInfo() const override {
        std::cout << "ID: " << ID << std::endl;
    }
};

#endif 