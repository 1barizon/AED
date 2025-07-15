#ifndef FILA_ENCAPSULADA_H
#define FILA_ENCAPSULADA_H

class FilaEncapsulada {
private:
    class No {
    public:
        int dado;
        No* proximo;
        No(int valor);
    };

    No* frente;
    No* tras;
    int tamanho;

public:
    FilaEncapsulada();
    ~FilaEncapsulada();

    void enfileirar(int valor);
    int desenfileirar();
    int frenteValor() const;
    bool vazia() const;
    int getTamanho() const;
    void imprimir() const;
};

#endif