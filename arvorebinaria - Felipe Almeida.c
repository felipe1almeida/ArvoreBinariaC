#include <stdio.h>
#include <stdlib.h>

void inicializa_arvore(int valor);

struct no{
	int dado;
	struct no *esq, *dir;
};

struct no *p, *q, *arvore;

int main(int argc, char *argv[]) {
	int valordaraiz, valorAInserir;
	arvore = NULL;	//Inicializar árvore vazia (sem nós)
	printf("Insira o valor do no raiz:  ");
	scanf("%d", &valordaraiz);

	inicializa_arvore(valordaraiz);

	do{
	printf("Informe o numero que deseja inserir na arvore ou 0 para sair: ");
	scanf("%d", &valorAInserir);

    if(valorAInserir != 0)
    {
        Inserir_Na_Arvore(&arvore, valorAInserir);
    }


	}while(valorAInserir != 0);
    Imprimir(arvore);


}

void inicializa_arvore(int valor){
	p = malloc(sizeof(struct no));
	p->dado = valor;
	p->dir = NULL;
	p->esq = NULL;
	arvore = p;
}

void Inserir_Na_Arvore(struct no **p,int Valor)
{
    if((*p)==NULL)
    {
        //printf("Criado um novo no");
        (*p)=malloc(sizeof(struct no));
        (*p)->esq = NULL;
        (*p)->dir = NULL;
        (*p)->dado = Valor;
        return;
    }
    else
    {
        if(Valor==(*p)->dado)
        {
            printf("\nValor ja existe na arvore\n");
            return;
        }
        if(Valor < (*p)->dado)
        {
            //printf("\nAdicionado a esquerda da arvore\n");
            Inserir_Na_Arvore(&((*p)->esq), Valor);
            return;
        }
        else
        {
            //printf("Adicionado a direita da arvore.\n");
            Inserir_Na_Arvore(&((*p)->dir), Valor);
            return;
        }
    }
    return;
}


void Imprimir(struct no *p)
{
    if(p!=NULL)
    {
        Imprimir(p->esq);
        printf(" %d ",p->dado);
        Imprimir(p->dir);
    }
    else
    return;
}







