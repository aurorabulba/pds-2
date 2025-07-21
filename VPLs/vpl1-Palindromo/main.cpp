#include <iostream>
#include <string>
#include <algorithm>

std::string removeSpaces(std::string str) 
{ 
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); 
    return str; 
} 

int main() {
    std::string frase;
    std::getline (std::cin, frase);
    
    frase = removeSpaces(frase);
    int tamanho = frase.length() - 1;
    int aux = 0;
    for(int i = 0; i < tamanho/2; i++){
        if(frase[tamanho - i] == frase[i]){
            continue;
        } else{
            aux++;
            std::cout << "NAO";
            break;
        }
    }

    if(aux == 0){
        std::cout << "SIM";
    }

  return 0;
}