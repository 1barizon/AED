#ifndef PILHA_ENCAPSULADA_H
#define PILHA_ENCAPSULADA_H

class PilhaEncapsulada {
private:
    class No {
    public:
        int dado;
        No* proximo;
        No(int valor);
    };

    No* topo;
    int tamanho;

public:
    PilhaEncapsulada();
    ~PilhaEncapsulada();

    void push(int valor);
    int pop();
    int peek() const;
    bool vazia() const;
    int getTamanho() const;
    void imprimir() const;
};

#endif