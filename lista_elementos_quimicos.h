#ifndef LISTA_ELEMENTOS_QUIMICOS_H_INCLUDED
#define LISTA_ELEMENTOS_QUIMICOS_H_INCLUDED

#define MAX 100
#include <string.h>

struct lista_elementos_quimicos
{
    int num_elemento;
    TElementoQuimico elementos[MAX];
};
typedef struct lista_elementos_quimicos TListaElementos;

//struct lista_vn
//{
//    int num_ele;
//    TValorNutr valores[50];
//};
//typedef struct lista_vn TListaVN;

void insere_ele_quimico(TListaElementos *lista, TElementoQuimico elem)
{
    lista->elementos[lista->num_elemento] = elem;
    lista->num_elemento++;
}

//void insere_lis_vn(TListaVN *lis, TValorNutr val)
//{
//    lis->valores[lis->num_ele] = val;
//    lis->num_ele++;
//}

void mostrar_lista_elementos(TListaElementos lista)
{
    int i;
    for (i = 0; i < lista.num_elemento; i++)
    {
        mostrar_elemento_quimico(lista.elementos[i]);
    }
}

//void mostre_lis_vn(TListaVN lis)
//{
//    int i;
//    for(i=0; i<lis.num_ele; i++)
//        mostre_valor_nutr(lis.valores[i]);
//}

int buscar_ele_quimico(TListaElementos lista, char *nome)
{
    int i;
    for (i = 0; i < lista.num_elemento; i++)
    {
        if (strcmp(nome, lista.elementos[i].nome) == 0)
        {
            return i;
        }
        return -1;
    }
}

int buscar_num_atomico(TListaElementos lista, int valor)
{
    int i;
    for (i = 0; i < lista.num_elemento; i++)
    {
        if (lista.elementos[i].numero_atomico == valor)
        {
            return i;
        }
        return -1;
    }
}

//int busca_lis_vn(TListaVN lis, char *fru)
//{
//    int i;
//    for(i=0; i<lis.num_ele; i++)
//        if(strcmp(fru, lis.valores[i].fruta) == 0)
//            return i;
//    return -1;
//}

TElementoQuimico remove_ele_quimico(TListaElementos *lista, int indice)
{
    int i;
    TElementoQuimico r = lista->elementos[indice];
    for(i = indice; i < lista->num_elemento-1; i++)
    {
        lista->elementos[i] = lista->elementos[i+1];
    }
    lista->num_elemento--;
    return r;
}

//TValorNutr remove_lis_vn(TListaVN *lis, int ind)
//{
//    int i;
//    TValorNutr res = lis->valores[ind];
//    for(i=ind; i<lis->num_ele-1; i++)
//        lis->valores[i] = lis->valores[i+1];
//    lis->num_ele--;
//    return res;
//}

void alterar_lista_elementos(TListaElementos *lista, int indice, TElementoQuimico novo)
{
    lista->elementos[indice] = novo;
}


void salvar_lista_elementos(TListaElementos lista)
{
    FILE *fp = fopen("tabela_ele_quimicos.txt", "wb");
    fwrite(&lista.num_elemento, sizeof(int), 1, fp);
    fwrite(lista.elementos, sizeof(TElementoQuimico), lista.num_elemento, fp);
    fclose(fp);
}

//void salva_lis_vn(TListaVN lis)
//{
//    FILE *fp = fopen("tabelaVN.arq", "wb");
//    fwrite(&lis.num_ele, sizeof(int), 1, fp);
//    fwrite(lis.valores, sizeof(TValorNutr), lis.num_ele, fp);
//    fclose(fp);
//}

void carregar_arq_elementos(TListaElementos *lista)
{
    FILE *fp = fopen("tabela_ele_quimicos.txt", "rb");
    fread(&lista->num_elemento, sizeof(int), 1, fp);
    fread(lista->elementos, sizeof(TElementoQuimico), lista->num_elemento, fp);
    fclose(fp);
}

//void carrega_lis_vn(TListaVN *lis)
//{
//    FILE *fp = fopen("tabelaVN.arq", "rb");
//    fread(&lis->num_ele, sizeof(int), 1, fp);
//    fread(lis->valores, sizeof(TValorNutr), lis->num_ele, fp);
//    fclose(fp);
//}

#endif // LISTA_ELEMENTOS_QUIMICOS_H_INCLUDED
