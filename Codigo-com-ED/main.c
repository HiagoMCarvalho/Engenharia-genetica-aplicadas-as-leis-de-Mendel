/*Universidade Federal do Vale do São Francisco
Trabalho de Algoritimos e Estruturas de Dados
Engenharia genética aplicadas as leis de Mendel
Discentes: Hiago Moura Carvalho e Luiz Fernando Barbosa da Silva
Docente: Professor Marcelo Santos Linder*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct fila
{
    char inf;
    struct fila *next;

}NODO_F;
typedef struct
{
    NODO_F *inicio;
    NODO_F *fim;

}DESCRITOR;

typedef struct pilha
{
    char inf;
    struct pilha *next;
}NODO_P;

typedef DESCRITOR * fila_enc;
typedef NODO_P * pilha_enc;

void criar_fila(fila_enc *genoma)
{
    *genoma = (DESCRITOR *)malloc(sizeof(DESCRITOR));

    (*genoma)->fim = (*genoma)->inicio = NULL;
}

int vazio_fila(fila_enc genoma)
{
    return (genoma->inicio == NULL);
}

void inserir_fila(fila_enc genoma, char valor)
{
    NODO_F *Novo;

    Novo = (NODO_F *)malloc(sizeof(NODO_F));
    if(!Novo)
    {
        printf("\nMemoria insuficiente\n");
        exit(1);
    }

    Novo->inf = valor;
    Novo->next = NULL;

    if(vazio_fila(genoma))
    {
        genoma->inicio = Novo;
    }
    else
    {
        genoma->fim->next = Novo;
    }
    genoma->fim = Novo;
}

void remover_fila(fila_enc genoma)
{
    if(!genoma->inicio)
    {
        printf("fila vazia");
        exit(22);
    }
    NODO_F *aux = genoma->inicio;

    genoma->inicio = genoma->inicio->next;

    if(!genoma->inicio)
    {
        genoma->fim = NULL;

    }

    free(aux);
}

void criar_pilha(pilha_enc *pila)
{
    (*pila) = NULL;
}

void inserir_pilha(pilha_enc *pila, char valor)
{
    NODO_P *novo;

    novo = (NODO_P *)malloc(sizeof(NODO_P));

    novo->inf = valor;

    novo->next = *pila;
    *pila = novo;
}

char consultar_pilha(pilha_enc resultado)
{
    return (resultado->inf);
}

void remover_pilha(pilha_enc *resultado)
{
    if(!(*resultado))
    {
        printf("pilha vazia");
        exit(4);
    }

    NODO_P *aux = *resultado;
    *resultado = (*resultado)->next;

    free(aux);
}

void comparar(fila_enc genon_mae, fila_enc genon_pai, int tamanho)
{
    pilha_enc resultadosA;
    pilha_enc resultadosB;
    char alelo = 'a';

    int flag = 0;
    int flag2 = 0;

    criar_pilha(&resultadosA);
    criar_pilha(&resultadosB);

    inserir_pilha(&resultadosA, alelo);
    inserir_pilha(&resultadosB, alelo);

    //loop para o alelo A/a;
  while(genon_mae->inicio != NULL)
  {
    if(toupper(genon_mae->inicio->inf) == toupper(genon_pai->inicio->inf) && flag < 2)
    {
       if(genon_mae->inicio->inf < genon_pai->inicio->inf)
       {
           alelo = 'e';
           char recup = genon_pai->inicio->inf;

           inserir_pilha(&resultadosA, alelo);

           remover_fila(genon_pai);
           inserir_fila(genon_pai, recup);
       }
       else
       {
           if(genon_mae->inicio->inf == genon_pai->inicio->inf)
           {
               if(genon_mae->inicio->inf > 64 && genon_mae->inicio->inf < 91)
               {
                   alelo = 'o';
                   char recup = genon_pai->inicio->inf;

                   inserir_pilha(&resultadosA, alelo);

                   remover_fila(genon_pai);
                   inserir_fila(genon_pai, recup);
               }
               else
               {
                   if(genon_mae->inicio->inf > 96 && genon_mae->inicio->inf < 123)
                   {
                       alelo = 'r';
                       char recup = genon_pai->inicio->inf;

                       inserir_pilha(&resultadosA, alelo);

                       remover_fila(genon_pai);
                       inserir_fila(genon_pai, recup);
                   }
               }
           }
           else
           {
               alelo = 'e';
               char recup = genon_pai->inicio->inf;

               inserir_pilha(&resultadosA, alelo);

               remover_fila(genon_pai);
               inserir_fila(genon_pai, recup);

           }
       }

    }
    else
    {
        flag = -1;
      char recup = genon_pai->inicio->inf;

      remover_fila(genon_pai);
      inserir_fila(genon_pai, recup);
    }

    flag++;
    if(flag == 2)
    {
        flag = 0;
        flag2++;
        remover_fila(genon_mae);

        if(flag2 == 2)
        {
            break;
        }
    }

  }

    //loop para o alelo B/b
    while(genon_mae->inicio != NULL)
  {
    if(toupper(genon_mae->inicio->inf) == toupper(genon_pai->inicio->inf) && flag < 2)
    {
       if(genon_mae->inicio->inf < genon_pai->inicio->inf)
       {
           alelo = 'e';
           char recup = genon_pai->inicio->inf;

           inserir_pilha(&resultadosB, alelo);

           remover_fila(genon_pai);
           inserir_fila(genon_pai, recup);
       }
       else
       {
           if(genon_mae->inicio->inf == genon_pai->inicio->inf)
           {
               if(genon_mae->inicio->inf > 64 && genon_mae->inicio->inf < 91)
               {
                   alelo = 'o';
                   char recup = genon_pai->inicio->inf;

                   inserir_pilha(&resultadosB, alelo);

                   remover_fila(genon_pai);
                   inserir_fila(genon_pai, recup);
               }
               else
               {
                   if(genon_mae->inicio->inf > 96 && genon_mae->inicio->inf < 123)
                   {
                       alelo = 'r';
                       char recup = genon_pai->inicio->inf;

                       inserir_pilha(&resultadosB, alelo);

                       remover_fila(genon_pai);
                       inserir_fila(genon_pai, recup);
                   }
               }
           }
           else
           {
               alelo = 'e';
               char recup = genon_pai->inicio->inf;

               inserir_pilha(&resultadosB, alelo);

               remover_fila(genon_pai);
               inserir_fila(genon_pai, recup);

           }
       }

    }
    else
    {
      flag = -1;
      char recup = genon_pai->inicio->inf;

      remover_fila(genon_pai);
      inserir_fila(genon_pai, recup);
    }

    flag++;
    if(flag == 2)
    {
        flag = 0;
        flag2++;
        remover_fila(genon_mae);

        if(flag2 == 2)
        {
            break;
        }
    }

  }
  int rA = 0;
  int oA = 0;
  int eA = 0;

 while(resultadosA->next != NULL)
  {
    if(resultadosA->inf == 'r')
    {
        rA++;
        remover_pilha(&resultadosA);
    }

    if(resultadosA->inf == 'o')
    {

        oA++;
        remover_pilha(&resultadosA);
    }

    if(resultadosA->inf == 'e')
    {
        eA++;
        remover_pilha(&resultadosA);
    }
  }

   if(tamanho == 4)
   {
        printf("\nprobabilidade dominante homozigotico: %d por cento\n", (oA*100)/tamanho);

        printf("\nprobabilidade dominante heterozigotico: %d por cento\n", (eA*100)/tamanho);

        printf("\nprobabilidade recessivo: %d por cento\n", (rA*100)/tamanho);
   }

   else
   {
       if(tamanho == 16);
        {
            int rB = 0;
            int oB = 0;
            int eB = 0;

            while(resultadosB->next != NULL)
            {
                if(resultadosB->inf == 'r')
                {
                    rB++;
                    remover_pilha(&resultadosB);
                }

                if(resultadosB->inf == 'o')
                {

                    oB++;
                    remover_pilha(&resultadosB);
                }

                if(resultadosB->inf == 'e')
                {
                    eB++;
                    remover_pilha(&resultadosB);
                }
            }

            printf("\nProbabilidade AB: %d/%d\n", (eA+oA)*(eB+oB), tamanho);

            printf("\nProbabilidade Ab: %d/%d\n", (eA+oA)*(rB), tamanho);

            printf("\nProbabilidade aB: %d/%d\n", (eB+oB)*(rA), tamanho);

            printf("\nProbabilidade ab: %d/%d\n", (rA)*(rB), tamanho);
        }
   }

}

int main()
{
    fila_enc genon_mae;
    fila_enc genon_pai;

    char valor1[10];
    char valor2[10];
    int tamanho;

    criar_fila(&genon_mae);
    criar_fila(&genon_pai);

    printf("\ndigite o genoma da mae: ");
    scanf("%s", valor1);

    for(int i = 0; valor1[i] != '\0'; i++)
    {
        inserir_fila(genon_mae, valor1[i]);
    }

    if(strlen(valor1) < 2)
    {
        printf("gene invalido");
        exit(-1);
    }


    printf("\ndigite o genoma do pai: ");
    scanf("%s", valor2);

    for(int i = 0; valor2[i] != '\0'; i++)
    {
        inserir_fila(genon_pai, valor2[i]);
    }

     if(strlen(valor2) < 2)
    {
        printf("gene invalido");
        exit(-1);
    }

    tamanho = strlen(valor1)*strlen(valor2);

    comparar(genon_mae, genon_pai, tamanho);

    return 0;
}

