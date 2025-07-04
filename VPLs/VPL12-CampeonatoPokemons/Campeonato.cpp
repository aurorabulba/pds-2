#include <string>
#include <vector>
#include <iostream>
#include "Pokemon.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonExplosivo.hpp"
#include "Treinador.hpp"
#include "Campeonato.hpp"

void Campeonato::cadastrar_treinador(std::string nome){
    this->_treinadores.push_back(new Treinador(nome));
}
void Campeonato::cadastrar_pokemon_eletrico(int idt,std::string nome, std::string tipo_ataque, double forca_ataque, double potencia_raio){
    this->_treinadores[idt]->cadastrar_pokemon_eletrico(nome, tipo_ataque, forca_ataque, potencia_raio);
}

void Campeonato::cadastrar_pokemon_aquatico(int idt, std::string nome, std::string tipo_ataque, double forca_ataque, double litros_jato){
    this->_treinadores[idt]->cadastrar_pokemon_aquatico(nome, tipo_ataque, forca_ataque, litros_jato);
}

void Campeonato::cadastrar_pokemon_explosivo(int idt, std::string nome, std::string tipo_ataque, double forca_ataque, double temperatura_explosao){
    this->_treinadores[idt]->cadastrar_pokemon_explosivo(nome, tipo_ataque, forca_ataque, temperatura_explosao);
}
void Campeonato::imprimir_informacoes_treinador(int idt){
    this->_treinadores[idt]->imprimir_informacoes();
}
void Campeonato::executar_batalha(int idt1, int idpk1, int idt2, int idpk2){

    std::cout << "### Batalha ###" << std::endl;
    std::cout << this->_treinadores[idt1]->getNome() << " (";
    this->_treinadores[idt1]->usar_pokemon(idpk1)->falar_nome();
    std::cout << ") vs. ";
    std::cout << this->_treinadores[idt2]->getNome() << " (";
    this->_treinadores[idt2]->usar_pokemon(idpk2)->falar_nome();
    std::cout << ")";

    this->_treinadores[idt1]->usar_pokemon(idpk1)->atacar(this->_treinadores[idt2]->usar_pokemon(idpk2));
    this->_treinadores[idt2]->usar_pokemon(idpk2)->imprimir_status();
}