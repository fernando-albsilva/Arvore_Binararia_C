#include <stdio.h>
#include <stdlib.h>

/* Estrutura da Arvore Binaria*/
struct arvbin
{
    char info;
    struct arvbin *esq;
    struct arvbin *dir;
};

typedef struct arvbin arv;

/* Função que retorna NULL para a estrutura. */
arv *cria_vazia();

/* Função que aloca memoria para cada folha da arvore binaria. */
arv *cria(char, arv *, arv *);

/* Função que imprime todas as folhas da arvore binaria. */
void imprime_arv(arv *);

/* Função que verifica se a arvore está vazia. Retorna True se estiver vazia */
int arv_vazia(arv *);

/* Função que retorna a quantidade total de folhas da arvore binaria. */
int total_folhas(arv *);

int main(void)
{
    /* Cria um ponteiro para o tipo de estrutura arvbin */
    arv *a;
    int *cont, total;
    cont = &total;
    /*Verifica se a arvore está vazia. */
    if (arv_vazia(a))
    {
        printf("\n Arvore está vazia.\n");
    }
    else
    {
        printf("\nArvore nao está vazia.\n");
    }

    /* Utiliza  as Funçoes cria(char,arv*,arv*) e cria_vazia() para criar a arvore binaria. */
    a = cria('A',
             cria('B',
                  cria_vazia(),
                  cria('D',
                       cria('F',
                            cria('G',
                                 cria_vazia(),
                                 cria_vazia()),
                            cria_vazia()),
                       cria_vazia())

                      ),
             cria('C',
                  cria_vazia(),
                  cria('E',
                       cria_vazia(),
                       cria_vazia())));

    /*imprime as folhas da arvore binaria*/
    imprime_arv(a);

    /*Verifica se a arvore está vazia. */
    if (arv_vazia(a))
    {
        printf("\n Arvore está vazia.\n");
    }
    else
    {
        printf("\nArvore nao está vazia.\n");
    }
    
    /* Função total_folhas() calcula quantas folhas além da raiz a arvore binaria possui */ 
    printf("\nA Arvore possui 1 raiz e %d de folhas", total_folhas(a)-1);


    return 0;
}

arv *cria_vazia()
{
    return NULL;
}

arv *cria(char info, arv *sae, arv *sad)
{
    arv *p = (arv *)malloc(sizeof(arv));
    if (p == NULL)
    {
        printf("\n Não ha memória suficiente.");
        free(p);
        exit(1);
    }
    p->info = info;
    p->esq = sae;
    p->dir = sad;

    return p;
}

void imprime_arv(arv *p)
{
    if (p != NULL)
    {
        printf("%c\n", p->info);
        imprime_arv(p->esq);
        imprime_arv(p->dir);
    }
}

int arv_vazia(arv *p)
{
    return p == NULL;
}

int total_folhas(arv *a)
{
    if (a == NULL)
        return (0);
    else
    {  
        
        return  1+ total_folhas(a->esq) + total_folhas(a->dir);
        
    }


}
