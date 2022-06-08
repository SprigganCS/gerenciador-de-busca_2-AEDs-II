#include <iostream>
#include <cstdlib>
#include <clocale>
#include "lista.h"

using namespace std;

no * lista1;
sublistas *listas;

int main() {

    int opt,tipo;
    string chav;

    lista1=inicia_lista();
    leitura(lista1);
    listas = inicia_sublistas(1);
    cria_listas(lista1,listas,1);
    do {
        cout << "------ Menu de Opcoes ------" << endl;
        cout << "1 - Insercao de veiculo\n2 - Exclusao de veiculo\n3 - Gerar listas de busca\n4 - Imprimir listas de busca\n5 - Relatorio de veiculos\n6 - Sair\nEscolha uma opcao do menu: " << endl;
        scanf("%d",&opt);
        switch (opt) {
        case 1:
            if (insere_no(lista1))
                cout << "Veiculo inserido" << endl;
            else cout << "Veiculo já inserido" << endl;
            break;
        case 2:
            cout << "Digite a placa do veiculo a ser removido: ";
            cin >> chav;
            remove_enc(lista1,chav);
            break;
        case 3:
            apagaSublistas(listas);
            cout << "Escolha um campo para criar as listas\n1- Tipo\n2- Potencia\n3- Combustivel\n4- Cambio\n5- Direcao\nOpcao: " << endl;
            cin >> tipo;
            if (tipo>0 && tipo<6) {
                listas = inicia_sublistas(tipo);
                cria_listas(lista1,listas,tipo);
            }
            else cout << "Opcao invalida" << endl;
            break;
        case 4:
            imprimirSublistas(listas);
            break;
        case 5:
            imprimir(lista1);
            break;
        case 6:
            apagaSublistas(listas);
            lista1=encerra_lista(lista1);
            break;
        }
    } while (opt!=6);
    return (EXIT_SUCCESS);
}