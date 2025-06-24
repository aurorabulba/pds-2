#ifndef POKEMON_H
#define POKEMON_H

#include <string>

class Pokemon{
    protected: 
        std::string _nome, _tipo_ataque;
        double _forca_ataque, _energia = 100;

    public:
        Pokemon(std::string nome, std::string tipo_ataque, double forca_ataque);
        void falar_nome();
        void falar_tipo_ataque();
        void imprimir_status();
        void imprimir_informacoes();
        virtual double calcular_dano() = 0;
        void atacar(Pokemon* outro_pokemon);
        void receber_dano(double valor_dano);
};

#endif