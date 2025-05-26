#include <iostream>
#include "tinder.hpp"

int main() {
  std::cout << "Bem-vindo ao myTINDER!\n";
  std::string nome;
  int n, idade;
  char sexo, pele, tpf;

  // Usuário
  std::cin >> nome >> idade >> sexo >> pele >> tpf;
  Pessoa usu = Pessoa(1, nome, idade, sexo, pele, tpf);
  Tinder tdr = Tinder(usu);

  // Pessoas
  std::cin >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> nome >> idade >> sexo >> pele >> tpf;
    tdr.addPessoa(i+2, nome, idade, sexo, pele, tpf);
  }

  // Preferências
  std::cin >> sexo >> pele >> tpf;
  tdr.addPreferencias(sexo, pele, tpf);
  
  // Lista os Pares perfeitos
  tdr.listarMatches();
}