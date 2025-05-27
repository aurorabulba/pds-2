#include <iostream>
#include <list>

int main(){
    std::list<Classe> lista;
    char opcao;

    do{
        std::cin >> opcao;

        //(A, C, R, N, P, L, E)
        switch (opcao)
        {
        case 'A':
            /*A: adiciona um novo objeto com id automático no final da lista. 
            Deve ser impresso o id e o endereço de memória do objeto criado.*/
            break;
        case 'C':
            /*C: adiciona um novo objeto com id fornecido no início da lista. 
            Deve ser impresso o id e o endereço de memória do objeto criado o "ERRO" caso o id não seja negativo.*/
            break;
        case 'R':
            /* R: remove (e deleta) um objeto da frente da lista. 
            Deve ser impresso o id e o endereço endereço de memória do objeto removido. 
            Caso a lista esteja vazia deve ser impresso "ERRO" */
            break;
        case 'N':
            /* N: imprime o valor do contador com número de objetos existentes.*/
            break;
        case 'P':
            /* P: imprime o id e o endereço de memória do i-ésimo elemento da lista. 
            Se i for um valor inválido (menor que 1 ou maior que o número de elementos) seu programa deverá imprimir "ERRO"*/
            break;
        case 'L':
            /*L: Imprime, para todos os elementos da lista, o id e o endereço de memória do objeto,
            sendo um elemento por linha com quebra de linha no final.*/
            break;
        case 'E':
            break;
        }

    }while(opcao != 'E');
    return 0;
}

class Classe{
    public: 
        int id;
        static int contador;

        Classe(int id){
            this->id = id;
            contador++;
        }

        Classe(){
            this->id = contador;
            contador++;
        }

        ~Classe(){
            contador--;
            
        }

        int getId(){
            return this->id;
        }

        int getNumObjetos(){
            return contador;
        }

        Classe* getEndereco(){
            
        }


};

int Classe::contador = 0;