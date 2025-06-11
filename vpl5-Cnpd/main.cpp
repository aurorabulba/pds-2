#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // for std::transform
#include <cctype>    // for std::toupper and std::tolower
#include "Data.hpp"
#include "Pessoa.hpp"
#include "Cnpd.hpp"

/*O Objetivo desse projeto é praticar os conceitos de Tipos Abstratos de Dados (TAD) e Modularização.

    A realidade sobre casos de desaparecidos no Brasil ainda é um dado preocupante. 
    Segundo o Fórum Brasileiro de Segurança, cerca de 190 pessoas desaparecem por dia no país. 
    Quando o assunto é desaparecimento de pessoas em MG, os números também impressionam. 
    Em 2019, só em Minas Gerais foram mais de 700 casos por mês.

    Pensando nesta situação, vamos propor uma solução que ajude as pessoas a encontrarem seus entes 
    queridos, por meio da implementação de uma solução computacional baseada em programação.
    Vamos construir um banco de dado de pessoas desaparecidas, o CNPD (Cadastro Nacional de Pessoas Desaparecidas), contendo nome, sobrenome, data de nascimento, sigla do estado onde foi vista pela última vez e a data do desaparecimento.*/

std::string formatarNome(const std::string& str);

int main(){
    int n;
    std::cin >> n;

    string nome;
    string sobrenome;
    int dia, mes, ano;
    string estado;
    int diaDes, mesDes, anoDes;
    string nomeProcurado, sbprocurado;
    int indice;

    Cnpd lista;

    for(int i = 1; i <= n; i++){
        std::cin >> nome >> sobrenome >> dia >> mes >> ano >> estado >> diaDes >> mesDes >> anoDes;
        nome = formatarNome(nome);
        sobrenome = formatarNome(sobrenome);
        lista.inserir(Pessoa(i, nome, sobrenome, dia, mes, ano, estado, diaDes, mesDes, anoDes));
    }

    std::cin >> nomeProcurado >> sbprocurado;

    nomeProcurado = formatarNome(nomeProcurado);
    sbprocurado = formatarNome(sbprocurado);

    indice = lista.buscar(nomeProcurado,sbprocurado);

    if(indice != -1){
        std::cout << "Encontrado(a): ";
        lista.imprimirDesaparecido(indice - 1);
    }else{
        std::cout << "Nao Encontrado(a)";
    }

    return 0;
}

std::string formatarNome(const std::string& str) {
    if (str.empty()) return "";

    std::string formatado = str;
    
    // Transformar a string inteira em letra minúscula
    std::transform(formatado.begin(), formatado.end(), formatado.begin(), ::tolower);

    // Depois capitaliza a primeira letra
    formatado[0] = std::toupper(formatado[0]);

    return formatado;
}
