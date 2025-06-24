#include <iostream>
#include <string>
#include "Pokemon.hpp"
#include "PokemonEletrico.hpp"

PokemonEletrico::PokemonEletrico(std::string nome, std::string tipo_ataque, double forca_ataque, double potencia_raio) : Pokemon(nome, tipo_ataque, forca_ataque){
    this->_potencia_raio = potencia_raio;
}

void PokemonEletrico::falar_tipo_ataque(){
    Pokemon::falar_tipo_ataque();
    std::cout << "Bzzzz!" << std::endl;
}

double PokemonEletrico::calcular_dano(){
    return ataque_eletrico();
}

double PokemonEletrico::ataque_eletrico(){
    return(this->_forca_ataque * _potencia_raio);
}
