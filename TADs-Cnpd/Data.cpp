#include "Data.hpp"
#include <iostream>

Data::Data(){
    
}

Data::Data(int dia, int mes, int ano){
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
};

void Data::imprimir(){
    std::cout << this->dia << "/" << this->mes << "/" << this-> ano;
};