#include <bits/stdc++.h>
using namespace std;


typedef struct nodo{
    int *chaves;
    int *filhos;
    int num_chaves;
    bool folha;
    int pos;

   nodo(int n) {
       num_chaves = 0;
       chaves = new int[n+1];
       filhos = new int[n+2];
   } 
}nodo;

void ler_arquivo() {

}

void constroiArvore(const char *grau, const char *arquivo) {
    
    FILE *arq = fopen(arquivo, "r");
    if(!arq) printf("Erro ao abrir arequivo de entrada\n");
    FILE *indice = fopen("indice", "w+");
    int grau_min, grau_max;
    sscanf(grau, "%d", &grau_min);
    char nome[256];

    pair<int, int> Tree;
    Tree.first = 0;
    Tree.second = 0;

    grau_max= grau_min * 2;
    while(1){

        nodo folha(grau_max);

        for(int i=1; i < grau_max; ++i) {
            long long p = ftell(arq);
            if(fscanf(arq, "%d %s", &folha.chaves[i], nome) == 2) {
                folha.filhos[i-1] = p;
                folha.num_chaves++;
            }

            else break;
        }

        if(folha.num_chaves > 0)
        {
            folha.pos = ++Tree.second;
            fseek(indice, sizeof(nodo) * folha.pos, SEEK_SET);
            fwrite(&folha, sizeof(nodo), 1, indice);
        }

        else break;

    }

}

int main(int argc, const char *argv[]) {
    if(argc != 3) {
        printf("Erro 0X1\n");
    }

    else {
        constroiArvore(argv[1], argv[2]);
    }

    return 0;
}
