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

int procura_valor(int, arv *, int);

/*Libera memoria alocada pela arvore */
arv *libera_arv(arv *);

/*Retira uma folha da arvore binaria */
arv *retira_folha(arv *);

arv *retira(arv *, int);
int main(void)
{
    arv *p;

    p = cria_vazia();

    p = chama_insere(p);

    imprime_arv(p);

    procura_arv(p);

    p = retira_folha(p);

    imprime_arv(p);

    p = libera_arv(p);

    imprime_arv(p);

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
    int valor, teste = 9, aux = 0, teste_proc = 0;

    do
    {
        printf("\n---------------------------------------------------------------------\n");
        printf("\n Digite o valor que deseja procurar:");
        scanf("%d", &valor);
        aux = procura_valor(valor, a, teste_proc);
        if (aux == 0)
        {
            printf("\nValor nao pertente a arvore.\n");
        }
        aux = 0;
        printf("\nDigite 1 para procurar outro valor ou outro numero para sair.");
        scanf("%d", &teste);

    } while (teste == 1);
}

int procura_valor(int valor, arv *a, int teste)
{

    if (a != NULL)
    {
        if (valor == a->info)
        {
            teste = 1;
            printf("\n Valor pertence a arvore.\n");
            return teste;
        }
        else
        {

            if (valor < a->info)
                teste += procura_valor(valor, a->esq, teste);
            else
                teste += procura_valor(valor, a->dir, teste);
            return teste;
        }
    }

    return 0;
}

arv *libera_arv(arv *a)
{
    if (a == NULL)
    {
        return NULL;
    }
    else
    {
        libera_arv(a->esq);
        libera_arv(a->dir);
        free(a);
    }

    return NULL;
}

arv *retira_folha(arv *a)
{
    int valor, teste = 0;

    do
    {
        printf("--------------------------------------------------------------------------");
        printf("\n Digite o valor a ser retirado da arvore : ");
        scanf("%d", &valor);
        a = retira(a, valor);
        printf("\n Se deseja retirar outro valor digiti 1 ou qualquer numero para sair : ");
    } while (teste == 1);

    return a;
}

arv *retira(arv *a, int valor)
{
    arv *aux;
    if (a == NULL)
    {
        printf("\n Valor nao pertence a arvore \n");
        return NULL;
    }
    else
    {
        if (valor < a->info)
        {
            a->esq = retira(a->esq, valor);
        }
        else
        {
            if (valor > a->info)
            {
                a->dir = retira(a->dir, valor);
            }
            else
            {
                if (a->esq == NULL && a->dir == NULL)
                {
                    free(a);
                    return NULL;
                }
                else
                {
                    if (a->esq == NULL)
                    {
                        aux = a;
                        a = a->dir;
                        free(aux);
                    }
                    else
                    {
                        if (a->dir == NULL)
                        {
                            aux = a;
                            a = a->esq;
                            free(aux);
                        }
                        else
                        {
                            aux = a->esq;
                            while (aux->dir != NULL)
                            {
                                aux = aux->dir;
                            }
                            a->info = aux->info;
                            aux->info = valor;
                            a->esq = retira(a->esq, valor);
                        }
                    }
                }
            }
        }
    }

    return a;
}
