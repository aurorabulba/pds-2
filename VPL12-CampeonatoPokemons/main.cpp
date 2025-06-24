// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_pokemon.hpp"
#include "Pokemon.hpp"
#include "PokemonAquatico.hpp"
#include "PokemonEletrico.hpp"
#include "PokemonExplosivo.hpp"
#include "Treinador.hpp"
#include "Campeonato.hpp"

int main() {
    Campeonato c = Campeonato();
    char opcao;
    std::string nome, tipo_ataque;
    double forca_ataque, litros_jato, temperatura_explosao_jato, potencia_raio;
    int id, idt1, idpk1, idt2, idpk2;

    do{
        std::cin >> opcao;
        switch (opcao){
        case 't':
        //'t nome': comando para cadastrar um treinador no campeonato. 
            std::cin >> nome;
            c.cadastrar_treinador(nome);
            break;
        case 'i':
        //'i idt': comando para imprimir as informações de um treinador de acordo com o id.
            std::cin >> id;
            c.imprimir_informacoes_treinador(id);
            break;
        case 'e':
        //comando para adicionar um PokemonEletrico ao treinador informado. 
            std::cin >> id >> nome >> tipo_ataque >> forca_ataque >> potencia_raio;
            c.cadastrar_pokemon_eletrico(id, nome, tipo_ataque, forca_ataque, potencia_raio);
            break;
        case 'q':
            std::cin >> id >> nome >> tipo_ataque >> forca_ataque >> litros_jato;
            c.cadastrar_pokemon_aquatico(id, nome, tipo_ataque, forca_ataque, litros_jato);
            break;
        case 'x':
            std::cin >> id >> nome >> tipo_ataque >> forca_ataque >> temperatura_explosao_jato;
            c.cadastrar_pokemon_explosivo(id, nome, tipo_ataque, forca_ataque, temperatura_explosao_jato);
         break;
        case 'h':
            std::cin >> idt1 >> idpk1 >> idt2 >> idpk2;
            c.executar_batalha(idt1, idpk1, idt2, idpk2);
            break;
        case 'b':
            avaliacao_basica();
            break;
        default:
            break;
        }
    }while(opcao != 'i');
    return 0;
}