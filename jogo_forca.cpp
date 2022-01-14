#include <iostream>
#include <cstdlib>
#include <time.h>
#include <string>

using namespace std;

int main () {
    char lista_palavras [51][12] = {{'c','o','b','r','a'}, {'l','a','g','a','r','t','o'},
                            {'l','e','a','o'}, {'t','a','r','t','a','r','u','g','a'},
                            {'a','b','e','l','h','a'}, {'z','e','b','r','a'}, 
                            {'c','a','m','u','n','d','o','n','g','o'}, {'g','i','r','a','f','a'}, 
                            {'t','u','b','a','r','a','o'}, {'b','a','l','e','i','a'},                            
                            {'j','a','c','a','r','e'}, {'c','r','o','c','o','d','i','l','o'}, 
                            {'a','v','e','s','t','r','u','z'}, {'c','a','p','i','v','a','r','a'}, 
                            {'r','a','p','o','s','a'}, {'t','i','g','r','e'}, 
                            {'l','e','o','p','a','r','d','o'}, {'p','i','n','g','u','i','m'}, 
                            {'a','r','a','n','h','a'}, {'b','u','f','a','l','o'},
                            {'c','a','r','n','e','i','r','o'}, {'c','o','r','u','j','a'}, 
                            {'t','o','u','r','o'}, {'v','e','s','p','a'}, 
                            {'c','a','s','c','a','v','e','l'}, {'m','a','c','a','c','o'}, 
                            {'g','o','r','i','l','a'}, {'c','h','i','m','p','a','n','z','e'},
                            {'t','i','l','a','p','i','a'}, {'s','e','r','p','e','n','t','e'},
                            {'i','g','u','a','n','a'}, {'d','r','o','m','e','d','a','r','i','o'},
                            {'l','e','s','m','a'}, {'c','a','r','a','n','g','u','e','j','o'}, 
                            {'j','u','m','e','n','t','o'}, {'p','i','r','a','n','h','a'}, 
                            {'l','e','m','u','r','e'}, {'h','i','p','o','p','o','t','a','m','o'},
                            {'a','g','u','i','a'}, {'f','a','l','c','a','o'},
                            {'g','a','l','i','n','h','a'}, {'h','i','e','n','a'}, 
                            {'c','a','c','h','o','r','r','o'}, {'p','a','p','a','g','u','a','i','o'}, 
                            {'r','i','n','o','c','e','r','o','n','t','e'}, {'t','o','u','r','o'}, 
                            {'a','n','d','o','r','i','n','h','a'}, {'b','a','b','u','i','n','o'},
                            {'e','l','e','f','a','n','t','e'}, {'c','a','m','a','l','e','a','o'}};

    string palavra, resposta; 
    char digitado = 'i', continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        srand(time(0));      
        palavra = lista_palavras[rand()%50];
        resposta = palavra; 
        int i, flag, tentativas = 6;
        for (i=0; i<palavra.size(); i++) {
            resposta [i] = '*';
        }
        cout << "\nVamos comecar o jogo!\n\nA palavra secreta eh um animal com " << 
                palavra.size() << " letras.\n";            
        while (tentativas > 0 && palavra != resposta) {
            flag = 0;
            cout << "Adivinhe uma letra, ou digite 1 para sair: ";
            cin >> digitado;
            if (digitado == '1'){
                cout << "\nSaindo do jogo.\n\n";
                return 0;
            }
            for (i=0; i<palavra.size(); i++){
                if (digitado == palavra[i]) {
                    resposta[i] = digitado;
                    flag = 1;
                }
            }
            if (flag) {
                cout << "\nVoce acertou!\n";
                if (resposta == palavra) {
                    cout << "\nParabens! Voce venceu o jogo!\nA palavra secreta era: " << 
                    palavra;
                    cout << "\nVoce deseja jogar novamente? (s/n)\n";
                    cin >> continuar;  
                } 
                else {
                    cout << "\nVeja como ficou a palavra secreta: \n\n" << 
                resposta << "\n\n";
                }
            }
            else {
                cout << "\nVoce errou! A palavra secreta ainda esta assim: \n\n" <<
                resposta << "\n";
                tentativas--;
                cout << "\nVoce tem " << tentativas << " tentativas. \n";
                if (tentativas == 0) {
                    cout << "\n\nSuas tentativas acabaram! Infelizmente voce perdeu o jogo." <<
                    "\nA palavra secreta era: " << palavra << 
                    "\nVoce deseja jogar novamente? (s/n)\n";
                    cin >> continuar;
                }
            }        
        }
    }
    cout << "\nSaindo do jogo...\n\n";
    return 0;
}