#include <string>
#include <vector>
#include <iostream>
#include "Pokemon.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonExplosivo.hpp"
#include "Treinador.hpp"

Treinador::Treinador(std::string nome){
    this->_nome = nome;
}

std::string Treinador::getNome(){
    return this->_nome;
}

void Treinador::cadastrar_pokemon_eletrico(std::string nome, std::string tipo_ataque, double forca_ataque, double potencia_raio){
    _pokemons.push_back(new PokemonEletrico(nome, tipo_ataque, forca_ataque, potencia_raio));
}

void Treinador::cadastrar_pokemon_aquatico(std::string nome, std::string tipo_ataque, double forca_ataque, double litros_jato){
    _pokemons.push_back(new PokemonAquatico(nome, tipo_ataque, forca_ataque, litros_jato));
}
void Treinador::cadastrar_pokemon_explosivo(std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao){
    _pokemons.push_back(new PokemonExplosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao));
}
Pokemon* Treinador::usar_pokemon(int idpk){
    return this->_pokemons[idpk];
}
void Treinador::imprimir_informacoes(){
    if(this->_pokemons.empty()){
        std::cout << "Nome: " << this->_nome << std::endl;
        std::cout << "----------" << std::endl << "Nenhum Pokemon cadastrado!" << std::endl << "----------";
    } else{
        std::cout << "Nome: " << this->_nome << std::endl;
        std::cout << "----------" << std::endl;
        for(auto p:_pokemons){
            p->imprimir_informacoes();
            std::cout << "----------" << std::endl;
        }
    }
}