#ifndef PESSOA
#define PESSOA

#include <string>
#include "Data.hpp"

using namespace std;

struct Pessoa{
    int num;
    string nome;
    string sobrenome;
    Data dataNascimento;
    string estado;
    Data dataDesaparecimento;
    
    //2.1) Construtor: inicializa uma nova instancia de pessoa com os dados passados via parâmetro.
    Pessoa(int, string, string, int, int, int, string, int, int, int);

    //2.2) Um Método que recebe nume e último nome e verifica se é igual ao nome da pessoa, retornando um boolean. 
    //Deve retornar verdadeiro se o nome e sobrenome baterem com uma comparação do tipo case insensitive.
    bool comparar(string, string);

    //Imprime o número e o nome
    void imprimir();

    //Imprime nome, sobrenome e data de nascimento
    void imprimirNome();
};

#endif