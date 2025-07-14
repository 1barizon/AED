#include "../include/ListaDuplamenteEncadeada.h"
#include <iostream>

ListaDuplamenteEncadeada::ListaDuplamenteEncadeada() : tamanhoAtual(0)
{
    head = nullptr;
    tail = nullptr;
}

void ListaDuplamenteEncadeada::InserirNoInicio(Elemento* item) {
    No* novo = new No(item);
    novo->proximo = head;
    novo->anterior = nullptr;

    if (head != nullptr) {
        head->anterior = novo; //verifica se o cabeca é nulo, se essa informação for verdadeira a cauda assume o valor de novo, se não for, o anterior do cabeça assume esse papel
    } else {

        tail = novo;
    }

    head = novo;
    tamanhoAtual++;
}

void ListaDuplamenteEncadeada::InserirNoFinal(Elemento* item) {
    No* novo = new No(item);
    novo->proximo = nullptr;
    novo->anterior = tail;

    if (tail != nullptr) {
        tail->proximo = novo; //logica semelhante a da função anterior mas invertendo a ordem de cabeça e cauda
    } else {
        
        head = novo;
    }

    tail = novo;
    tamanhoAtual++;
}


Elemento* ListaDuplamenteEncadeada::RemoverPrimeiro() {
    if (head == nullptr) {
        throw std::out_of_range("A lista está vazia"); //se a lista estiver vazia indica impossibilidade de remoção
    }

    No* removido = head; //guarda o ponteiro para o nó a ser removido
    Elemento* dado = removido->dado; //pega o valor que sera retornado

    head = head->proximo; //avança o cabeca para o seu posterior

    if (head != nullptr) {
        head->anterior = nullptr; //se o cabeca n se tornar nulo, atualiza seu anterior
    } else {
        tail = nullptr;//se a lista ficou vazia torna a cauda nula
    }

    delete removido;//deleta o no removido
    tamanhoAtual--;//reduz o tamanho da lista

    return dado;//retorna o valor removido
}


Elemento* ListaDuplamenteEncadeada::RemoverUltimo() { //no geral, segue a mesma ideia do RemoverPrimeiro mas retrocede a cauda o inves de avançar o cabeca
    if (tail == nullptr) {
        throw std::out_of_range("A lista está vazia");
    }

    No* removido = tail;
    Elemento* dado = removido->dado;

    tail = tail->anterior;

    if (tail != nullptr) {
        tail->proximo = nullptr;
    } else {
        head = nullptr;
    }

    delete removido;
    tamanhoAtual--;

    return dado;
}

Elemento* ListaDuplamenteEncadeada::RemoverPeloId(int id) {
    if (head == nullptr) {
        throw std::out_of_range("Lista vazia");
    }

    No* atual = head;

    while (atual != nullptr) {//percorre do cabeca ate a cauda enquanto n for nulo
        if (atual->dado->getID() == id) { //se achou
            Elemento* dadoRemovido = atual->dado; //salva o valor em dado

            if (atual->anterior != nullptr) {
                atual->anterior->proximo = atual->proximo; //se tinha um anterior estabelece que o proximo do anterior é o proximo do atual (como se removesse um meio)
            } else {
                head = atual->proximo; //se n tinha anterior o cabeca é o proximo do que foi removido
            }

            if (atual->proximo != nullptr) {
                atual->proximo->anterior = atual->anterior; // no geral a mesma ideia que em cima
            } else {
                tail = atual->anterior;
            }

            delete atual;
            tamanhoAtual--;

            return dadoRemovido;
        }

        atual = atual->proximo;
    }

    throw std::runtime_error("Elemento com id não encontrado");
}

Elemento* ListaDuplamenteEncadeada::BuscarPeloId(int id) const {
    No* atual = head;

    while (atual != nullptr) { //percorre toda lista 
        if (atual->dado->getID() == id) {
            return atual->dado; //retorna o dado quando achou o id
        }
        atual = atual->proximo; 
    }

    throw std::runtime_error("Elemento com o id não encontrado");
}

void ListaDuplamenteEncadeada::AlterarPeloId(int id, Elemento* novoItem) {
    No* atual = head;

    while (atual != nullptr) {
        if (atual->dado->getID() == id) { // Encontrou o nó a ser alterado
            delete atual->dado;           // Apaga o objeto antigo
            atual->dado = novoItem;       // Substitui pelo novo objeto
            return;                       // Sai do método
        }
        atual = atual->proximo;
    }

    throw std::runtime_error("Elemento com id nao encontrado para alteracao");
}

bool ListaDuplamenteEncadeada::estaVazia() const {
    return tamanhoAtual == 0;
}

int ListaDuplamenteEncadeada::getTamanho() const {
    return tamanhoAtual;
}

Elemento* ListaDuplamenteEncadeada::getPrimeiro() const {
    if (head == nullptr)
        throw std::out_of_range("Lista vazia");
    return head->dado;
}


Elemento* ListaDuplamenteEncadeada::getUltimo() const {
    if (tail == nullptr)
        throw std::out_of_range("Lista vazia");
    return tail->dado;
}

void ListaDuplamenteEncadeada::imprimirLista() const {
    No* atual = head;
    while (atual != nullptr) {
        atual->dado->imprimirInfo();
        std::cout << " -> ";
        atual = atual->proximo;
    }
    std::cout << "null\n";
}

ListaDuplamenteEncadeada::~ListaDuplamenteEncadeada() {
    No* atual = head;
    while (atual != nullptr) {
        No* proximo = atual->proximo;
        delete atual->dado;
        delete atual;
        atual = proximo;
    }
    head = nullptr;
    tail = nullptr;
    tamanhoAtual = 0;
}