#ifndef ALUNO_H
#define ALUNO_H

#include <iostream>
#include <string>
#include <vector>

class Aluno{
    public:
    std::string nome;
    int matricula;
    std::vector<int> notas;

    Aluno();
    Aluno(std::string, int);
    float calcularMedia();
    int getMaiorNota();
    int getMenorNota();
    std::string getNome();
    int getMatricula();
    int imprimirNotas();
    void adcionarNotas();

};

#endif