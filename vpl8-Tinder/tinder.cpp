// Includes
#include <map>
#include <iostream>
#include <string>
#include "tinder.hpp"
#include "pessoa.hpp"
#include "caracteristica.hpp"


// Constructor 
Tinder::Tinder(Pessoa const& usuario){
    this->usuario = usuario;
}

// Destructor
Tinder::~Tinder() {

};

// addPessoa
// Adiciona uma nova pessoa à lista de pessoas
void Tinder::addPessoa(int id, std::string nome, int idade, char sexo, char pele, char tipoFisico){
    Pessoa p(id, nome, idade, sexo, pele, tipoFisico);
    lp.push_back(p);
}

// curtir
// Adiciona um par perfeito à lista de matches
void Tinder::curtir(Pessoa const& par){
    matches[par.id].push_back(par.id);
}


// addPares
// Percorre a lista de pessoas e Adiciona os pares perfeitos à lista de matches
void Tinder::addPares(){
    for(Pessoa& p : lp){
        if(p.caract->sexo == this->parPerfeito.sexo &&
           p.caract->pele == this->parPerfeito.pele &&
           p.caract->tipoFisico == this->parPerfeito.tipoFisico){
            curtir(p);
        }
    }
}

// addPreferencias
// Adiciona as preferências do usuário e chama a função addPares
void Tinder::addPreferencias(char sexo, char pele, char tipoFisico){
    this->parPerfeito = CaractFis(sexo, pele, tipoFisico);

    addPares();
}

// listarMatches
// Lista os matches do usuário
// Se não houver matches, informa que não deu match
// Se houver matches, lista os matches
void Tinder::listarMatches(){
    if(this->matches.empty()){
        std::cout << usuario.nome << ", infelizmente não deu match." << std::endl;
        return;
    }

    std::cout<< usuario.nome << ", aqui estão seus pares perfeitos:\n";
    for(const auto& m : matches){
        
        for(int id : m.second){
            Pessoa* p = findById(id);
            std::cout << "* ";
            p->print();
            if(id = m.second.size() - 1){
                std::cout << std::endl;
            }
        }
    }
}

// findById
// Busca uma pessoa pelo ID
// Retorna um ponteiro para a pessoa encontrada ou nullptr se não encontrado
Pessoa* Tinder::findById(int id){
    for(Pessoa& p : lp){ 
        if(p.id == id){
            return &p;
        }
    }
    return nullptr;  
}