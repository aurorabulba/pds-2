#include <iostream>
#include <string>
#include "Pokemon.hpp"
#include "PokemonAquatico.hpp"

PokemonAquatico::PokemonAquatico(std::string nome, std::string tipo_ataque, double forca_ataque, double litros_jato) : Pokemon(nome, tipo_ataque, forca_ataque){
    this->_litros_jato = litros_jato;
}

void PokemonAquatico::falar_tipo_ataque(){
    Pokemon::falar_tipo_ataque();
    std::cout << "Splash!" << std::endl;
}

double PokemonAquatico::calcular_dano(){
    return ataque_aquatico();
}

double PokemonAquatico::ataque_aquatico(){
    return(this->_forca_ataque + this->_litros_jato);
}