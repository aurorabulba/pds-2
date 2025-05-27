#include <iostream>
#include <list>

class Classe{
    public: 
        int id;
        static int contador, numObjetos;

        Classe(int id){
            this->id = id;
            Classe::numObjetos++;
        }

        Classe(){
            this->id = Classe::contador;
            Classe::contador++;
            Classe::numObjetos++;
        }

        ~Classe(){
            Classe::numObjetos--;
        }

        int getId() const{
            //O const ao final da declaração do método getId() em C++ significa
            //que esse método não altera o estado interno do objeto.
            return this->id;
        }

        void getNumObjetos(){
            std::cout << Classe::numObjetos;
        }

        const void* getEndereco(){
            return static_cast<const void*>(this);
        }

        void imprimir(){
            std::cout << this->getId() << " " << this->getEndereco() << std::endl;
        }

};

int Classe::contador = 1;
int Classe::numObjetos = 0;

int main(){
    std::list<Classe> lista;
    std::list<Classe>::iterator it = lista.begin();
    char opcao;

    do{
        std::cin >> opcao;
        int id, i;

        //(A, C, R, N, P, L, E)
        switch (opcao){
        case 'A':

            /*A: adiciona um novo objeto com id automático no final da lista. 
            Deve ser impresso o id e o endereço de memória do objeto criado.*/
            if (lista.empty()){
                /* code */
            }
            
            lista.push_back(Classe());
            lista.back().imprimir();
            break;

        case 'C':

            /*C: adiciona um novo objeto com id fornecido no início da lista. 
            Deve ser impresso o id e o endereço de memória do objeto criado o "ERRO" caso o id não seja negativo.*/
            std::cin >> id;

            if(id < 0){
                lista.push_back(Classe(id));
                lista.back().imprimir();
            } else{
                std::cout << "ERRO" << std::endl;
            }
            
            break;

        case 'R':

            /* R: remove (e deleta) um objeto da frente da lista. 
            Deve ser impresso o id e o endereço endereço de memória do objeto removido. 
            Caso a lista esteja vazia deve ser impresso "ERRO" */
            lista.front().imprimir();
            lista.front().~Classe();
            lista.pop_front();
            break;

        case 'N':

            /* N: imprime o valor do contador com número de objetos existentes.*/
            lista.back().getNumObjetos();
            break;

        case 'P':

            /* P: imprime o id e o endereço de memória do i-ésimo elemento da lista. 
            Se i for um valor inválido (menor que 1 ou maior que o número de elementos) seu programa deverá imprimir "ERRO"*/
            std::cin >> i;

            if(i > 1 && i < lista.size()){
                std::advance(it, i);
                it->imprimir();
            } else{
                std::cout << "ERRO" << std::endl;
            }
            break;

        case 'L':
            /*L: Imprime, para todos os elementos da lista, o id e o endereço de memória do objeto,
            sendo um elemento por linha com quebra de linha no final.*/
            for (it = lista.begin(); it != lista.end(); ++it) {
                it->imprimir();
            }
            break;
        case 'E':
            break;
        }

    }while(opcao != 'E');

        for (it = lista.begin(); it != lista.end(); ++it) {
            it->~Classe();
        }

    return 0;
}