#include "Pessoa.hpp"
#include "Data.hpp"
#include <string>
#include <iostream>

using namespace std;

//construtor para pessoa
Pessoa::Pessoa(int num, string nome, string sobrenome, int dia, int mes, int ano, string estado, int diaDes, int mesDes, int anoDes){
    this->num = num;
    this->nome = nome;
    this->sobrenome = sobrenome;
    this->dataNascimento = Data(dia, mes, ano);
    this->estado = estado;
    this->dataDesaparecimento = Data(diaDes, mesDes, anoDes);
};

bool Pessoa::comparar(string nome, string sobrenome){
    int i = 0;
    for(char c: nome){
        if(c != this->nome[i]){
            return 0;
        }
        i++;
    }

    i = 0;
    for(char c: sobrenome){
        if(c != this->sobrenome[i]){
            return 0;
        }
        i++;
    }

    return 1;
};

void Pessoa::imprimir(){
    cout << this->num << " " << this->nome << endl;
}

void Pessoa::imprimirNome(){
    cout<< this->nome << " "<< this->sobrenome;
}

