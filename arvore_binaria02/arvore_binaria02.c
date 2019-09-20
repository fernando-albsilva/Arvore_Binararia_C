#include <stdio.h>
#include <stdlib.h>

/* cria uma strutura do tipo arvbin */

struct arvbin
{
    int info;
    struct arvbin *esq;
    struct arvbin *dir;
};

/*Define "arv" como uma strutura arvbin */
typedef struct arvbin arv;

/* Cria uma arvore vazia retornando NULL */
arv *cria_vazia(void);

/* Pergunta para o usuario se quer inserir uma folha na arvore e qual valor */
arv *chama_insere(arv *);

/*insere uma folha na arvore , se for maior que seu antecessor é jogada para o ramo da direita e se for 
menor para o ramo da esquerda */
arv *insere_folha(arv *, int);

/*imprime a arvore */
void imprime_arv(arv *);

/*Procura se um valor pertence a arvore */
void procura_arv(arv *);

int procura_valor(int, arv *);

int main(void)
{
    arv *p;
    p = cria_vazia();

    p = chama_insere(p);

    imprime_arv(p);

    procura_arv(p);

    return 0;
}

arv *cria_vazia(void)
{
    return NULL;
}
arv *chama_insere(arv *p)
{
    int valor, teste = 9;
    do
    {

        printf("\n------------------------------------------------------------------\n");
        printf("\n Digite o valor a ser inserido na arvore: ");
        scanf("%d", &valor);
        p = insere_folha(p, valor);
        printf("\n Digite 1 para inserir novamente ou qualquer numero para encerrar: ");
        scanf("%d", &teste);
        printf("\n------------------------------------------------------------------\n");

    } while (teste == 1);

    return p;
}
arv *insere_folha(arv *a, int info)
{
    arv *p, *inicio;
    int teste = 0;
    if (a == NULL)
    {
        a = (arv *)malloc(sizeof(arv));
        a->info = info;
        a->esq = NULL;
        a->dir = NULL;

        return a;
    }
    else
    {
        inicio = a;
        while (a != NULL)
        {
            if (info >= a->info)
            {
                p = a;
                a = a->dir;
                teste = 2;
            }
            else
            {
                p = a;
                a = a->esq;
                teste = 1;
            }
        }

        a = (arv *)malloc(sizeof(arv));
        a->info = info;
        a->esq = NULL;
        a->dir = NULL;
        if (teste == 1)
        {
            p->esq = a;
        }
        if (teste == 2)
        {
            p->dir = a;
        }
    }

    return inicio;
}

void imprime_arv(arv *a)
{
    if (a != NULL)
    {
        imprime_arv(a->esq);
        imprime_arv(a->dir);
        printf("\n%d\n", a->info);
    }
}

void procura_arv(arv *a)
{
    int valor, teste = 9, aux;

    do
    {
        printf("\n---------------------------------------------------------------------\n");
        printf("\n Digite o valor que deseja procurar:");
        scanf("%d", &valor);
        aux = procura_valor(valor, a);
        if (aux == 0)
        {
            printf("\nValor nao pertente a arvore.\n");
        }
        aux = 0;
        printf("\nDigite 1 para procurar outro valor ou outro numero para sair.");
        scanf("%d", &teste);
        printf("\n---------------------------------------------------------------------\n");
    } while (teste == 1);
}

int procura_valor(int valor, arv *a)
{
    int teste = 0;
    if (a != NULL)
    {
        if (valor == a->info)
        {
            teste = 1;
            printf("\n Valor pertence a arvore.");
            return teste;
        }
        else
        {
            procura_valor(valor, a->esq);
            procura_valor(valor, a->dir);
        }
    }

    return teste;
}