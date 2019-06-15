#ifndef ELEMENTOS_QUIMICOS_H_INCLUDED
#define ELEMENTOS_QUIMICOS_H_INCLUDED

struct elementos_quimicos
{
    char nome[21];
    char simbolo[3];
    int numero_atomico;
};
typedef struct elementos_quimicos TElementoQuimico;

void mostrar_elemento_quimico(TElementoQuimico elemento)
{
    printf(" %-20s   %-2s   %d \n", elemento.nome, elemento.simbolo, elemento.numero_atomico);
}

int cmp_nome(const void *elemento_a, const void *elemento_b)
{
    TElementoQuimico *a = (TElementoQuimico *) elemento_a;
    TElementoQuimico *b = (TElementoQuimico *) elemento_b;
    return strcmp(a->nome, b->nome);
}

int cmp_simbolo(const void *elemento_a, const void *elemento_b)
{
    TElementoQuimico *a = (TElementoQuimico *) elemento_a;
    TElementoQuimico *b = (TElementoQuimico *) elemento_b;
    return strcmp(a->simbolo, b->simbolo);
}

int cmp_num_atomico(const void *elemento_a, const void *elemento_b)
{
    TElementoQuimico *a = (TElementoQuimico *) elemento_a;
    TElementoQuimico *b = (TElementoQuimico *) elemento_b;
    int num_atm_a = a->numero_atomico;
    int num_atm_b = b->numero_atomico;
    return num_atm_a - num_atm_b;
}

#endif // ELEMENTOS_QUIMICOS_H_INCLUDED
