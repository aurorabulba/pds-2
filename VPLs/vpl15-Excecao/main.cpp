#include <iostream> 
#include <vector>   
#include <exception> 
#include <stdexcept>

class NegativeResultException : public std::exception{
    private:
        int valor;
    public:
        NegativeResultException(int val) : valor(val) {}

        char* what() const noexcept override {
            return "Erro: Resultado Negativo.";
        }

        int getValor() const {
            return valor;
        }
};

int main(){
    std::vector<int> vetor = {-20, -10, 0, 10, 20};
    int i;

    try {
        std::cin >> i; 

        int conteudo = vetor.at(i); 

        if (conteudo < 0) {
            throw NegativeResultException(conteudo); 
        } else {
            std::cout << conteudo << std::endl;
        }
    } 

    catch (const NegativeResultException& e) {
        std::cout << e.what() << std::endl; 
        std::cout << e.getValor() << std::endl; 
    }

    catch (const std::exception& e) {

        std::cout << e.what() << std::endl; 
    }

    std::cout << "\nPrograma finalizado." << std::endl;

    return 0;

}