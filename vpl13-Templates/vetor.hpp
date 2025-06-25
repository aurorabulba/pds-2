#ifndef VETOR_H
#define VETOR_H

#include <string>
#include <iostream>
#include <vector>

template<class T>
class Vetor{
    private: 
        std::vector<T> v;
        size_t numElementos = 0, tamanho;
    public:

    bool saoIguais(const T& a, const T& b) {
        if(a == b){
            return true; 
        } else{
            return false; // Usa o operador == para o tipo T
        }
    }

    Vetor(int n){
        tamanho = n;
        v.resize(tamanho);
    }

    //Vetor(const Vetor<T>& other){}

    ~Vetor(){

    }

    void SetElemento(int i, T x){
        v[i] = x;
        numElementos++;
    }

    T GetElemento(int i){
        return v.at(i);
    }

    void AdicionaElemento(T x){ 
        if(numElementos < tamanho){
            v[numElementos] = x;
            numElementos++;
        } else{
            v.push_back(x);
        }
    }

    void Imprime(){
        for(T t : v){
            std::cout << t << " ";
        }
    }
};

#endif