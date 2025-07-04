#ifndef TINDER_H
#define TINDER_H

#include <string>
#include <vector>
#include <string>
#include "pessoa.hpp"


class Tinder {
  public:
    Pessoa usuario;
    std::vector<Pessoa> lp;
    std::map<int,std::vector<int>> matches;
    CaractFis parPerfeito;
    Tinder(Pessoa const& usuario);
    ~Tinder();
    void addPessoa(int id, std::string nome, int idade, char sexo, char pele, char tipoFisico);
    void addPreferencias(char sexo, char pele, char tipoFisico);
    void addPares();
    void curtir(Pessoa const& par);
    Pessoa* findById(int id);
    void listarMatches();
};

#endif