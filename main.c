#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "auxiliares.h"
#include "elementos_quimicos.h"
#include "lista_elementos_quimicos.h"

int menu_principal()
{
    caracteres(66, '='); printf("\n");
    printc("Tabela de Elementos Qu\xA1micos", 66);  printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Mostrar tabela de elementos\n");
    printf("  2 - Inserir novo elemento qu\xA1mico\n");
    printf("  3 - Buscar elemento qu\xA1mico \n");
    printf("  4 - Excluir elemento qu\xA1mico\n");
    printf("  ----------------------\n");
    printf("  0 - Sair do Aplicativo\n");
    printf("\n  Escolha uma op\x87\xC6o: ", 135, 198);
    fflush(stdin);
    return getchar();
}

int submenu()
{
    caracteres(66, '='); printf("\n");
    printc("Tabela de elementos qu\xA1micos", 66); printf("\n");
    caracteres(66, '='); printf("\n");
    printf("  1 - Ordenadas pelo nome\n");
    printf("  2 - Ordenadas pelo calorias\n");
    printf("  3 - Ordenadas pela quantidade de prote%cnas\n", 161);
    printf("  ----------------------------\n");
    printf("  0 - Voltar ao menu principal\n");
    printf("\n  Escolha uma op%c%co: ", 135, 198);
    fflush(stdin);
    return getchar();
}

void insere_ele_quimico(TListaElementos *lista)
{
    TElementoQuimico elemento;
    printc("  Nome do elemento: ");
    fflush(stdin);
    gets(elemento.nome);
    printf(   "S\xA1mbolo: ");
    gets(elemento.simbolo);
    printf("  N\xA3mero at\x93mico: ");
    elemento.numero_atomico = le_inteiro();
}

//void inserir_fruta(TListaVN *lis)
//{
//    TValorNutr vn;
//    printf("  Nome da fruta: ");
//    fflush(stdin);
//    gets(vn.fruta);
//    printf("  Quantidade de calorias: ");
//    vn.calorias = le_inteiro();
//    printf("  Quantidade de prote%cnas: ", 161);
//    //vn.proteinas = le_real();
//    scanf("%f", &vn.proteinas);
//    insere_lis_vn(lis, vn);
//}

void buscar_pelo_nome(TListaElementos lista)
{
    int n;
    char nome[21];
    printf("  Nome da fruta: ");
    fflush(stdin);
    gets(nome);
    n = buscar_ele_quimico(lista, nome);
    if (n < 0)
    {
        printf("  Elemento qu\xA1mico n\xC6o cadastrado\n");
    } else {
        mostrar_elemento_quimico(lista.elementos[n]);
    }
}

void buscar_pelo_num_atomico(TListaElementos lista)
{
    int n;
    int v;
    printf("  N\xA3mero at\x93mico do elemento: ");
    n = le_inteiro();
    if (n < 0)
    {
        printf("  Elemento qu\xA1mico n\xC6o cadastrado\n");
    }
    else
    {
        mostrar_elemento_quimico(lista.elementos[n]);
    }
}

//void buscar_fruta(TListaVN lis)
//{
//    int rb;
//    char nome[21];
//    printf("  Nome da fruta: ");
//    fflush(stdin);
//    gets(nome);
//    rb = busca_lis_vn(lis, nome);
//    if(rb < 0)
//        printf("  Fruta n%co cadastrada\n", 198);
//    else {
//        mostre_valor_nutr(lis.valores[rb]);
//    }
//}

void excluir_ele_quimico(TListaElementos *lista)
{
    int n;
    char nome[21];
    printf("  Nome do elemento qu\xA1mico: ");
    fflush(stdin);
    gets(nome);
    n = buscar_ele_quimico(*lista, nome)
    if(n < 0)
        printf("  Elemento qu\xA1mico n\xC6o cadastrado\n", 198);
    else {
        remove_ele_quimico(lista, n);
        remove_lis_vn(lis, rb);
    }
}

//void excluir_fruta(TListaVN *lis)
//{
//    int rb;
//    char nome[21];
//    printf("  Nome da fruta: ");
//    fflush(stdin);
//    gets(nome);
//    rb = busca_lis_vn(*lis, nome);
//    if(rb < 0)
//        printf("  Fruta n%co cadastrada\n", 198);
//    else {
//        remove_lis_vn(lis, rb);
//    }
//}

// AQUI //

int main()
{
    TListaElementos lista_elementos;
    carregar_arq_elementos(&lista_elementos);

    char op, op2;
    while(1)
    {
        op = menu_principal();
        if (op == '0')
        {
            salva_lis_vn(lis_vn);
            printf("\n  ** Fim do aplicativo **");
            sleep(3);
            break;
        }
        switch(op)
        {
            case '1':
                while(1)
                {
                    op2 = submenu();
                    if (op2 == '0')
                    {
                        break;
                    }
                    switch(op2)
                    {
                        case '1':
                            caracteres(66, '-'); printf("\n");
                            printc("Ordenadas pelo nome",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            qsort(lis_vn.valores, lis_vn.num_ele, sizeof(TValorNutr), cmp_nome);
                            mostre_lis_vn(lis_vn);
                            break;
                        case '2':
                            caracteres(66, '-'); printf("\n");
                            printc("Ordenadas pela quantidade de calorias",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            qsort(lis_vn.valores, lis_vn.num_ele, sizeof(TValorNutr), cmp_caloria);
                            mostre_lis_vn(lis_vn);
                            break;
                        case '3':
                            caracteres(66, '-'); printf("\n");
                            printc("Ordenadas pela quantidade de prote\xa1nas",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            qsort(lis_vn.valores, lis_vn.num_ele, sizeof(TValorNutr), cmp_proteina);
                            mostre_lis_vn(lis_vn);
                            break;
                        case '4':
                            caracteres(66, '-'); printf("\n");
                            printc("Op\x87\xc6o 4 do Submenu",66); printf("\n");
                            caracteres(66, '-'); printf("\n");
                            // Insira seu código aqui
                            break;
                        default:
                            printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
                    }
                }
                break;
            case '2':
                caracteres(66, '-'); printf("\n");
                printc("T\xa1tulo da Op\x87\xc6o 2", 66); printf("\n");
                caracteres(66, '-'); printf("\n");
                inserir_fruta(&lis_vn);
                break;
            case '3':
                caracteres(66, '-'); printf("\n");
                printc("T\xa1tulo da Op\x87\xc6o 3", 66); printf("\n");
                caracteres(66, '-'); printf("\n");
                buscar_fruta(lis_vn);
                break;
            case '4':
                caracteres(66, '-'); printf("\n");
                printc("T\xa1tulo da Op\x87\xc6o 4", 66); printf("\n");
                caracteres(66, '-'); printf("\n");
                excluir_fruta(&lis_vn);
                break;
            default:
                printf("\n\n  *** Op%c%co inv%clida ***\n\n",135,198,160);
        }
    }
    return 0;
}
