#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <math.h>

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
            return (this->base * this->altura);
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

    return 0;
}