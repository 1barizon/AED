#ifndef LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H
#define LISTA_DUPLAMENTE_ENCADEADA_CIRCULAR_H

#include "Elemento.h" 

class ListaDuplamenteEncadeadaCircular {
private:
    class No {
    private:
        Elemento* dado;
        No* proximo;
        No* anterior;

    public:
        No(Elemento* elemento) : dado(elemento), proximo(nullptr), anterior(nullptr) {}

        ~No() {
            delete dado;
            dado = nullptr;
        }

        Elemento* getDado() const { return dado; }
        No* getProximo() const { return proximo; }
        No* getAnterior() const { return anterior; }

        void setProximo(No* proximoNo) { proximo = proximoNo; }
        void setAnterior(No* anteriorNo) { anterior = anteriorNo; }
    };

    No* cabeca;
    int tamanho;

public:
    ListaDuplamenteEncadeadaCircular();

    ~ListaDuplamenteEncadeadaCircular();

    bool estaVazia() const;
    int getTamanho() const;
    void inserirNoInicio(Elemento* elemento);
    void inserirNoFinal(Elemento* elemento);
    bool remover(int id);
    Elemento* buscar(int id) const; 
    void exibirParaFrente() const;
    void exibirParaTras() const;
};

#endif