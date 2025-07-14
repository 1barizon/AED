#include "../include/ArvoreBinaria.h"
#include <iostream>

int main() {
    ArvoreBinaria arvore;

     
    arvore.Inserir(new ElementoConcreto(10));
    arvore.Inserir(new ElementoConcreto(5));
    arvore.Inserir(new ElementoConcreto(15));
    arvore.Inserir(new ElementoConcreto(3));
    arvore.Inserir(new ElementoConcreto(7));
    arvore.Inserir(new ElementoConcreto(12));
    arvore.Inserir(new ElementoConcreto(17));

    std::cout << "Percurso em ordem: ";
    arvore.emOrdem();  

    std::cout << "Percurso pre-ordem: ";
    arvore.preOrdem();  

    std::cout << "Percurso pos-ordem: ";
    arvore.posOrdem();  

     
    ElementoConcreto procurado1(7);
    try {
        Elemento* encontrado = arvore.BuscarPeloID(procurado1);
        std::cout << "Elemento encontrado: ";
        encontrado->imprimirInfo();
    } catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

     
    ElementoConcreto procurado2(20);
    try {
        Elemento* encontrado = arvore.BuscarPeloID(procurado2);
        std::cout << "Elemento encontrado: ";
        encontrado->imprimirInfo();
    } catch (std::exception& e) {
        std::cout << "Erro: " << e.what() << std::endl;
    }

     
    std::cout << "\nRemovendo o elemento 10..." << std::endl;
    arvore.RemoverPeloID(&procurado1);  
    ElementoConcreto remover(10);
    arvore.RemoverPeloID(&remover);

    std::cout << "Percurso em ordem após remoção: ";
    arvore.emOrdem();  

    return 0;
}
