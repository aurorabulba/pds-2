#ifndef PESSOA_H
#define PESSOA_H

#include <string>
#include <map>
#include "caracteristica.hpp"

class Pessoa {
  public:
    std::string nome; 
    int id, idade;
    CaractFis* caract;
    static void format_str(std::string &str);
    Pessoa(int id, std::string nom, int ida, char sex, char pel, char tpf);
    Pessoa() = default;
    void print();
};

#endif