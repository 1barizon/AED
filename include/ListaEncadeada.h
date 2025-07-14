#ifndef LISTAENCADEADA_H
#define LISTAENCADEADA_H
#include "elemento.h"

class ListaEncadeada
{
    private:
        class No{
            public:
                Elemento* dado;
                No* prox;
            
            No(Elemento* item) : dado(item), prox(nullptr){}
        };

        No* head;
        int size;
    public:
        ListaEncadeada();
        ~ListaEncadeada();

        void InserirIni(Elemento* item);
        void InserirFim(Elemento* item);
        void removerIni();
        void removerFim();
        void alterarID(int id, Elemento* item);
        void removerID(int id);
        Elemento* buscarID(int id);
        void PrintDados();




};

#endif 