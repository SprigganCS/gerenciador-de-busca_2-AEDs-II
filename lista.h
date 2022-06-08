#include <string>

using namespace std;

#ifndef LISTA_H
#define LISTA_H

typedef struct no_ no;
typedef struct sublistas_ sublistas;

no* inicia_lista();
sublistas* inicia_sublistas(int opcao);
no* encerra_lista(no * ptlista);
void busca_enc(no* ptlista, string chave, no** ant, no** pont);
int ins_enc(no* ptlista, string chave, no valor);
no* remove_enc(no* ptlista, string chave);
bool insere_no(no* ptlista);
int leitura(no* ptlista);
void cria_listas(no *ptrlista, sublistas *lista, int opcao);
void imprimir(no* ptlista);
sublistas* apagaSublistas(sublistas* lista);
void imprimirSublistas(sublistas* lista);

#endif /* LISTA_H */

