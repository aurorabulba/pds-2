#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <iomanip>
#include <algorithm>
#include "aluno.hpp"

int main(){
    std::string nome, flag = "END";
    int matricula;
    std::vector<Aluno> alunos;

    while(1){
        std::cin >> nome;

        if(strcmp(nome.c_str(), flag.c_str()) == 0){
            break;
        }

        std::cin >> matricula;
        Aluno aluno = Aluno(nome,matricula);
        aluno.adcionarNotas();
        alunos.push_back(aluno);
    }

std::sort(alunos.begin(), alunos.end(), [](Aluno& a, Aluno& b) {
    return a.getNome() < b.getNome();
});

    for(Aluno a: alunos){
        std::cout << a.getMatricula() << " ";
        std::cout << a.getNome() << " ";
        a.imprimirNotas();
        std::cout << std::endl << std::fixed<< std::setprecision(2); 
        std::cout << a.calcularMedia() << " " << a.getMaiorNota() << " " << a.getMenorNota(); 
        std::cout << std::endl;
    }

    return 0;
}