#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

typedef struct no_ {
    string chave;
    string modelo;
    string marca;
    string tipo;
    short ano;
    int km;
    string potencia;
    string combustivel;
    string cambio;
    string direcao;
    string cor;
    int portas;

    struct no_ * prox; 
} no;

typedef struct noSublista_ {
    no* item;
    struct noSublista_ *prox; 
} noSublista;

typedef struct sublistas_ {
    string valor;                  
    noSublista* primeiro;
    noSublista* ultimo;
    struct sublistas_ *prox;
} sublistas;

sublistas* inicia_sublistas(int opcao) {
    sublistas* nova = new (sublistas);
    switch (opcao) {
    case 1:
        nova->valor="Tipo";
        break;
    case 2:
        nova->valor="Potencia";
        break;
    case 3:
        nova->valor="Combustivel";
        break;
    case 4:
        nova->valor="Cambio";
        break;
    case 5:
        nova->valor="Direcao";
        break;
    }
    nova->prox = NULL;
    return nova;
}

no* inicia_lista() {
    no* tmp = new (no);
    tmp->prox = NULL;

    cout << "Lista iniciada"<<endl;
    return tmp;
}

no * encerra_lista(no * ptlista) {
    no * ant = ptlista;
    no * pont = ant->prox;

    while(pont != NULL) {
        delete(ant);
        ant = pont;
        pont = pont->prox;
    }
    delete(ant);
    cout << "Lista removida."<<endl;
    return NULL;
}

bool busca_enc(no * ptlista, string chave,  no** ant) {
    *ant = ptlista;
    no * ptr = ptlista->prox;

    while (ptr != NULL && ptr->chave < chave) {
        *ant = ptr;
        ptr = ptr->prox;
    }
    return ptr != NULL && ptr->chave == chave;
}

bool ins_enc(no * ptlista, string chave, no valor) {
    no* ant;

    if(busca_enc(ptlista, chave, &ant))
        return false;

    no * ptr = new(no);
    ptr->chave = chave;
    ptr->modelo = valor.modelo;
    ptr->marca = valor.marca;
    ptr->tipo = valor.tipo;
    ptr->ano = valor.ano;
    ptr->km = valor.km;
    ptr->potencia = valor.potencia;
    ptr->combustivel = valor.combustivel;
    ptr->cambio = valor.cambio;
    ptr->direcao = valor.direcao;
    ptr->cor = valor.cor;
    ptr->portas = valor.portas;
    ptr->prox = ant->prox;
    ant->prox = ptr;
    return true;
}

bool insere_no(no* ptlista) {
    no valor;

    cout << "Digite Modelo: ";
    cin >> valor.modelo;
    cout << "Digite Marca: ";
    cin >> valor.marca;
    cout << "Digite Tipo: ";
    cin >> valor.tipo;
    cout << "Digite Ano: ";
    cin >> valor.ano;
    cout << "Digite km: ";
    cin >> valor.km;
    cout << "Digite potencia: ";
    cin >> valor.potencia;
    cout << "Digite Combustivel: ";
    cin >> valor.combustivel;
    cout << "Digite Cambio: ";
    cin >> valor.cambio;
    cout << "Digite Direcao: ";
    cin >> valor.direcao;
    cout << "Digite cor: ";
    cin >> valor.cor;
    cout << "Digite Numero de portas: ";
    cin >> valor.portas;
    cout << "Digite Placa: ";
    cin >> valor.chave;

    return ins_enc(ptlista,valor.chave,valor);
}

no * remove_enc(no * ptlista, string chave) {
    no* ant, *ptr;

    if(!busca_enc(ptlista, chave, &ant))
        return NULL;

    ptr = ant->prox;
    ant->prox = ptr->prox;
    ptr->prox = NULL;
    return ptr;
}

void imprimir(no* ptlista) {
    no * ptr = ptlista->prox;

    int cont=1;
    cout << "---Estado atual da lista:";
    while(ptr != NULL) {
        cout << "Veiculo " << cont++ << ": " << endl;
        cout << ptr->modelo << endl;
        cout << ptr->marca << endl;
        cout << ptr->tipo << endl;
        cout << ptr->ano << endl;
        cout << ptr->km << endl;
        cout << ptr->potencia << endl;
        cout << ptr->combustivel << endl;
        cout << ptr->cambio << endl;
        cout << ptr->direcao << endl;
        cout << ptr->cor << endl;
        cout << ptr->portas << endl;
        cout << ptr->chave << endl;
        cout << endl;
        ptr = ptr->prox;
    }
    cout << endl;
}

//Leitura do arquivo com os dados
int leitura(no* ptlista) {
    ifstream arquivo;
    string linha;
    no valor;
    int cont;

    arquivo.open("BD.txt");
    if (!arquivo) {
        cout << "Arquivo BD.txt não encontrado" << endl;
        return 0;
    }
    cont=0;
    getline(arquivo, linha);
    getline(arquivo, linha);
    while (!arquivo.eof()) {
        arquivo >> valor.modelo;
        arquivo >> valor.marca;
        arquivo >> valor.tipo;
        arquivo >> valor.ano;
        arquivo >> valor.km;
        arquivo >> valor.potencia;
        arquivo >> valor.combustivel;
        arquivo >> valor.cambio;
        arquivo >> valor.direcao;
        arquivo >> valor.cor;
        arquivo >> valor.portas;
        arquivo >> valor.chave;
        ins_enc(ptlista,valor.chave,valor);
        cont++;
    }
    cout << "Veiculos lidos com sucesso"<<endl;
    
    arquivo.close();
    return 0;
}

void cria_listas(no *ptrlista, sublistas *lista, int opcao) {

    noSublista* novo;
    sublistas* nova;
    int cont=0;
    string valor;
    no* ptr = ptrlista->prox;
    sublistas *ptrSub;
    sublistas *antSub;

    while (ptr != NULL) {
        switch (opcao) {
        case 1:
            valor=ptr->tipo;
            break;
        case 2:
            valor=ptr->potencia;
            break;
        case 3:
            valor=ptr->combustivel;
            break;
        case 4:
            valor=ptr->cambio;
            break;
        case 5:
            valor=ptr->direcao;
            break;
        }
        antSub=lista;
        ptrSub = lista->prox;
        while (ptrSub!=NULL && ptrSub->valor!=valor) {
            antSub=ptrSub;
            ptrSub=ptrSub->prox;
        }
        novo = new noSublista();
        novo->item = ptr;
        novo->prox = NULL;
        if (ptrSub!=NULL) {
            ptrSub->ultimo->prox = novo;
            ptrSub->ultimo = novo;
        } else {
            nova = new(sublistas);
            nova->valor=valor;
            nova->prox = NULL;
            nova->primeiro = novo;
            nova->ultimo = novo;
            antSub->prox = nova;
            cont++;
        }
        ptr = ptr->prox;
    }
    cout << "Sublistas criadas" << endl << endl;
}

void apagaSublistas(sublistas* lista) {
    sublistas* ptr;
    sublistas* apaga;
    noSublista* apagaS;
    noSublista* ptrSub;

    ptr = lista->prox;
    while (ptr!=NULL) {
        ptrSub = ptr->primeiro;
        while (ptrSub!=NULL) {
            apagaS=ptrSub;
            ptrSub=ptrSub->prox;
            delete(apagaS);
        }
        apaga=ptr;
        ptr=ptr->prox;
        delete(apaga);
    }
    cout << "-Sublistas apagadas" << endl;
    delete lista;
}

/**
 * Imprime todas as sublistas geradas
 */
void imprimirSublistas(sublistas* lista) {
    noSublista* ptrSub;
		sublistas* ptr;

    ptr = lista->prox;
    cout << "-O criterio é: " << lista->valor << endl;
    while (ptr!=NULL) {
        cout << "Categoria: " << ptr->valor << endl;
        cout << "Placas: ";
        ptrSub = ptr->primeiro;
        while (ptrSub!=NULL) {
            cout << ptrSub->item->chave << " ";
            ptrSub = ptrSub->prox;
        }
        cout << endl;
        ptr = ptr->prox;
    }
}
