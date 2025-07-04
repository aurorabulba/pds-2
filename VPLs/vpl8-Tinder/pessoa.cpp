/* Includes */
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>
#include <string>
#include "pessoa.hpp"
#include "caracteristica.hpp"

//format_str
// Converte a primeira letra para maiúscula e o restante para minúscula
void Pessoa::format_str(std::string &str) {
  // Converte a primeira letra para maiúscula e o restante para minúscula
  // std::transform(str.begin(), str.begin()+1, str.begin(), ::toupper);
  //continua ...
  if (!str.empty()) {
    str[0] = std::toupper(str[0]);
  }

  std::transform(str.begin() + 1, str.end(), str.begin() + 1, ::tolower);
}

// Construtor de Pessoa
// Não esqueça de inicializar o ponteiro caract com o operador new
// e de formatar o nome
Pessoa::Pessoa(int id, std::string nom, int ida, char sex, char pel, char tpf){
  format_str(nom);

  this->id = id;
  this->nome = nom;
  this->idade = ida;
  this->caract = new CaractFis(sex, pel, tpf);
}

// print
// Impressão dos dados da pessoa
// Utilize o map para converter os valores de pele e tipoFisico
void Pessoa::print(){

    std::map<char, std::string> mapTipoBase = {
        {'E', "esbelt"},   // base sem gênero
        {'M', "magr"},
        {'O', "obes"}
    };

    std::map<char, std::string> mapPele = {
        {'M', "moren"},   // base sem gênero
        {'L', "loir"},
        {'R', "ruiv"},
    };

     std::string sufixo = (caract->sexo == 'M' || caract->sexo == 'm') ? "o" : "a";

     std::cout << this->nome << ", " << mapPele[this->caract->pele] << sufixo << ", " << this->idade << " anos, " << mapTipoBase[this->caract->tipoFisico] << sufixo << std::endl;
}

