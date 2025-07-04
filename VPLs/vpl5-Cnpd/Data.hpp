#ifndef DATA
#define DATA

/*No seu código, o #ifndef, #define e #endif servem para evitar que o arquivo de cabeçalho (Data.hpp) seja incluído mais de uma vez no mesmo projeto.

Vamos por partes:

#ifndef DATA → Significa "se não foi definido DATA ainda..."

#define DATA → Então define DATA.

(o código do arquivo vem aqui)

#endif → Fim do "se".

Ou seja: na primeira vez que Data.hpp for incluído, DATA ainda não existe, então o conteúdo entre #ifndef e #endif é processado normalmente. Na próxima vez, como DATA já foi definido, o compilador pula o conteúdo — evitando erros de "redefinição de struct", duplicações, etc.

Esse esquema é chamado de include guard.*/

struct Data{
    int dia;
    int mes;
    int ano;

    //Contrutor Default
    Data();

    //1.1) Construtor: inicializa uma nova data com os dados passados via parâmetro (dia, mes, ano).
    Data(int, int, int);

    //1.2) Imprime data no formato dd/mm/aa
    void imprimir();
};

#endif
