#include <iostream>
#include <fstream>
#include <string>
#include <vector>


using namespace std;

bool temCaracter(char caracter, vector<char> &erros){
    for(char c : erros){
        if(caracter == c) return 1;
    }

    return 0;
}

string identificarChave(int n, fstream &Palavras){
    string linha;
    n += 1;
    int i = 0;
    if (!Palavras) {
        cout << "Deu ruim";
        return "Ruim";
    }

    while(getline(Palavras, linha)){
        i++;

        if(i == n){
            return linha;
        }
    }
    
    return "Ruim";
}

string comparar(string chave, string tentativa, vector<char> &erros){
    string saida = "*****";
    int aux;

    for(int i = 0; i < 5; i++){
        aux = 0;
        for(int j = 0; j < 5; j++){

            if(tentativa[i] == chave[j]){
                if(i == j){
                    saida[i] = tentativa[i];
                    aux++;
                }else{
                    saida[i] = tolower(tentativa[i]);
                    aux++;
                }

                break;
            }
        }

        if(aux == 0 && !(temCaracter(tentativa[i], erros))){
            erros.push_back(tentativa[i]);
        }

    }
    return saida;
}




void imprimirErros(const vector<char> &erros) {
    cout << " (";
    for (char c : erros) cout << c;
    cout << ")\n";
}
    

int main(){
    //ifstream in("palavras.txt", fstream::in);
    //ofstream out("saida.txt", fstream::out);
    string nomeArquivo = "palavras.txt", saida;
    fstream Palavras(nomeArquivo);
    if (!Palavras) {
        cerr << "Erro ao abrir o arquivo!" << endl;
        return 1;
    }
    
    vector<char> erros;

    int n, cont = 0;
    cin >> n;

    string tentativa, chave = identificarChave(n, Palavras);

    do{
        cin >> tentativa;
       
        saida = comparar(chave, tentativa, erros);
        cout << saida;
        imprimirErros(erros);
        cont++;

    }while((tentativa != chave) && (cont < 5));

    if(tentativa == chave){
        cout << "GANHOU!";
    } else{
        cout << "PERDEU! " << chave;
    }

    Palavras.close();

    return 0;
}