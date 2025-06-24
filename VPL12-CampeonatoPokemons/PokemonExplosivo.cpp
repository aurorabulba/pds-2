#include <iostream>
#include <string>
#include "Pokemon.hpp"
#include "PokemonExplosivo.hpp"

PokemonExplosivo::PokemonExplosivo(std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao) : Pokemon(nome, tipo_ataque, forca_ataque){
    this->_temperatura_explosao = temperatura_explosao;
}

void PokemonExplosivo::falar_tipo_ataque(){
    Pokemon::falar_tipo_ataque();
    std::cout << "Boom!" << std::endl;
}

double PokemonExplosivo::calcular_dano(){
    return ataque_explosivo();
}

double PokemonExplosivo::ataque_explosivo(){
    return(this->_forca_ataque / this->_temperatura_explosao);
}
