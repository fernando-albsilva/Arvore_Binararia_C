#include <stdio.h>
#include <stdlib.h>

/* Estrutura da Arvore Binaria*/
struct arvbin{
    char info;
    struct arvbin *esq;
    struct arvbin *dir;
};

typedef struct arvbin arv;

/* Função que retorna NULL para a estrutura. */
arv* cria_vazia();

/* Função que aloca memoria para cada folha da arvore binaria. */
arv* cria(char,arv*,arv*);

/* Função que imprime todas as folhas da arvore binaria. */
void imprime_arv(arv*);

int main(void)
{
    /* Cria um ponteiro para o tipo de estrutura arvbin */
    arv *a;

    /* Utiliza  as Funçoes cria() e cria_vazia para criar a arvore binaria. */
    a=cria('A',
                cria('B',
                            cria_vazia(),
                            cria('D',
                                    cria('F',
                                        cria('G',
                                            cria_vazia(),
                                            cria_vazia()    
                                            ),
                                        cria_vazia()    
                                        ),
                                    cria_vazia()    
                                    )

                    ),
                   cria('C',
                        cria_vazia(),
                        cria('E',
                                cria_vazia(),
                                cria_vazia()
                            )
                        ) 
            );
    
    /*imprime as folhas da arvore binaria*/
    imprime_arv(a);
    
    return 0;
}


arv* cria_vazia()
{
    return NULL;
}

arv* cria(char info,arv* sae,arv* sad)
{
    arv *p=(arv*)malloc(sizeof(arv));
            if( p == NULL)
            {
                printf("\n Não ha memória suficiente.");
                free(p);
                exit(1);
            }
         p->info=info;
         p->esq=sae;
         p->dir=sad;

         return p;   
}

void imprime_arv(arv* p) 
{
    if( p != NULL)
    {
        printf("%c\n",p->info);
        imprime_arv(p->esq);
        imprime_arv(p->dir);
    }

    

}