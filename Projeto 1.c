/*Nome: Felipe Camargos Ribeiro
Matricula: 1571
Nome: Cleverson Silva Alves
Matricula: 1608
Sistemas de Informação Noturno*/

/*----------------------------------------------------------------------------*/

/*Este programa consiste na solução de um problema para um pequena empresa de
telemarketing, o programa deve criar uma fila para facilitar o atendimento e 
organizar as ligações*/

/*----------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

/*----------------------------------------------------------------------------*/

typedef struct scliente 
{
    int cpf;
    char cliente_ou_ncliente[3];        
}clientes;

/*----------------------------------------------------------------------------*/

typedef struct satendente
{
    char nome[20];        
}atendente;

/*----------------------------------------------------------------------------*/

typedef struct cell
{
    clientes info;
    struct cell* next; 
}CELULA;

/*----------------------------------------------------------------------------*/

typedef struct sfila
{
    CELULA* inicio;
    CELULA* fim;        
}fila;

/*----------------------------------------------------------------------------*/

void inicializa (fila* f)
{
    
    f->fim=NULL;
    f->inicio=NULL;
    return;
}

/*----------------------------------------------------------------------------*/

int fila_vazia(fila* f)
{
     if(f->fim==NULL && f->inicio==NULL)
     {
         return 1;                
     }
     return 0;    
}

/*----------------------------------------------------------------------------*/

void enfileirar (fila* f, clientes x)
{
    
    CELULA *q;
    q=(CELULA*)malloc(sizeof (CELULA));
    if(q==NULL)
    {
        printf("Alocacao de memoria falhou."); 
        exit(1);          
    }
    q->next=NULL;
    q->info=x;
    if(fila_vazia(f))
    {
        f->inicio=q;
        f->fim=q;                 
    }
    else
    {
        (f->fim)->next=q;
        f->fim=q;
         
    }
}

/*----------------------------------------------------------------------------*/

void desenfileirar (fila* f)
{
    CELULA* aux;
    if(fila_vazia(f))
    {
        printf("Fila vazia, nao e possivel retirar nenhum elemento.");              
    }
    else
    {
        aux=f->inicio;
        f->inicio=aux->next;
        free(aux);    
    }
}
/*----------------------------------------------------------------------------*/

void exibir_fila(fila* f)
{
    CELULA* aux;
    int cont=1;
    aux=f->inicio;
    while(aux != NULL)
    {
        printf("%d - %d |", cont, (aux->info).cpf);
        aux=aux->next; 
        cont++;          
    }         
}

/*----------------------------------------------------------------------------*/


/*----------------------------------------------------------------------------*/


