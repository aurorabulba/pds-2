#include "aluno.hpp"
#include <iostream>
#include <vector>
#include <string>

Aluno::Aluno(){}

Aluno::Aluno(std::string nome, int matricula){
    this->nome = nome;
    this->matricula = matricula;
}

void Aluno::adcionarNotas(){
    int nota = 0;
    std::cin >> nota;

    do{
        this->notas.push_back(nota);
        std::cin >> nota;
    }while(nota != - 1);
}

float Aluno::calcularMedia(){
    int soma = 0;
    float media;
    for(int i: this->notas ){
        soma += i;
    }
    media = (float)soma / (float)this->notas.size();
    return media;
}

int Aluno::getMaiorNota(){
    int maiorNota = this->notas[0];
    for(int i: this->notas){
        if(i > maiorNota){
            maiorNota = i;
        }
    }
    return maiorNota;
}

int Aluno::getMenorNota(){
    int menorNota = this->notas[0];
    for(int i: this->notas){
        if(i < menorNota){
            menorNota = i;
        }
    }
    return menorNota;
}

std::string Aluno::getNome(){
    return this->nome;

}

int Aluno::getMatricula(){
    return this->matricula;
}

int Aluno::imprimirNotas(){
    for(int i: this->notas){
        std::cout << i << " ";
    }
}