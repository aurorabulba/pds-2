#ifndef CNPD
#define CNPD
#include "Pessoa.hpp"
#include <vector>

struct Cnpd{
    int n;
    vector <Pessoa> lista;

    Cnpd();

    //3.1) Constructor que recebe a qtde de pessoas que serão inseridas no sistema.
    Cnpd(int);

    //3.2) Método para Inserir uma pessoa desaparecida, retorna a pessoa inserida
    void inserir(Pessoa);

    //3.3) Método para buscar uma pessoa: Deve receber nome e sobrenome, buscar a pessoa na lista usando o método 2.2 (do TAD Pessoa). 
    //Se encontrar retorna o indice da pessoa no array, ou -1 caso contrário.
    int buscar(string, string);

    //Imprime desaparecido
    void imprimirDesaparecido(int);

};

#endif
