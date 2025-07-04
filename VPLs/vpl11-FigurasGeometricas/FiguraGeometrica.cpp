#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <iomanip>

class Ponto{
    private: 
        int x, y;
    public:
        Ponto(){};

        Ponto(int x, int y){
            this->x = x;
            this->y = y;
        }

        int getX(){
            return this->x;
        }

        void setX(int x){
            this->x = x;
        }

        int getY(){
            return this->x;
        }

        void setY(int y){
            this->y = y;
        }

};

class FiguraGeometrica{
    protected: 
        Ponto centro;

    public: 
        virtual void desenha(){
            std::cout << this->centro.getX() << " " << this->centro.getY() << " ";
        }

        FiguraGeometrica(int x, int y){
            this->centro = Ponto(x,y);
        }

        virtual float calcularArea() = 0;
        

};

class Triangulo : public FiguraGeometrica{
    private: 
        int base, altura;
    public: 
        Triangulo(int x, int y, int b, int h) : FiguraGeometrica(x,y), base(b), altura(h){ }
 
        void desenha() override{
            FiguraGeometrica::desenha();
            std::cout << "TRIANGULO" << std::endl;
        }

        float calcularArea(){
            return ((this->base * this->altura)/2);
        }
};

class Retangulo : public FiguraGeometrica{
    private:
        int lado1, lado2;

    public: 
        Retangulo(int x, int y, int ladoA, int ladoB): 
            FiguraGeometrica(x,y), lado1(ladoA), lado2(ladoB){}

        void desenha() override{
            FiguraGeometrica::desenha();
            std::cout << "RETANGULO" << std::endl;
        }

        float calcularArea(){
            return (this->lado1 * this->lado2);
        }

};

class Circulo : public FiguraGeometrica{
    private: 
        int raio;
    
        public:
            Circulo(int x, int y, int r) : FiguraGeometrica(x,y), raio(r){}

            float calcularArea() override{
                return (M_PI*this->raio*this->raio);
            }

            void desenha() override{
                FiguraGeometrica::desenha();
                std::cout << "CIRCULO" << std::endl;
            }
};

int main(){
    std::vector<FiguraGeometrica*> formas;
    char opcao;
    int c1, c2, l1, l2, raio, base, altura;
    float area;

    do{
        std::cin >> opcao;
    switch (opcao){
    case 'R':
        std::cin >> c1 >> c2 >> l1 >> l2;
        formas.push_back(new Retangulo(c1, c2, l1, l2));
        break;
    case 'C':
        std::cin >> c1 >> c2 >> raio;
        formas.push_back(new Circulo(c1, c2, raio));
        break;
    case 'T':
        std::cin >> c1 >> c2 >> base >> altura;
        formas.push_back(new Triangulo(c1, c2, base, altura));
        break;
    case 'D':
        for(auto f : formas){
            f->desenha();
        }
        break;
    case 'A':
        area = 0.00;
        for(auto f : formas){
            area += f->calcularArea(); 
        }
        std::cout << std::fixed<< std::setprecision(2) << area << std::endl;
        break;
    case 'E':
        break;
    }

    }while(opcao != 'E');

    return 0;
}