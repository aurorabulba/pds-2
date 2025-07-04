#include "Cnpd.hpp"
#include "Pessoa.hpp"
#include <iostream>

Cnpd::Cnpd(int n){
  
};

Cnpd::Cnpd(){
  
};


int Cnpd::buscar(string nome, string sobrenome){
    for(Pessoa p: lista){
            if(p.comparar(nome, sobrenome)){
                return p.num;
            }
    }

    return -1;
}

void Cnpd::inserir(Pessoa pessoa){
    lista.push_back(pessoa);
    pessoa.imprimir();
}

void Cnpd::imprimirDesaparecido(int n){
    lista[n].imprimirNome();
    std::cout << ", ";
    lista[n].dataNascimento.imprimir();
}