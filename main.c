#include <stdio.h>
#include <stdlib.h>

int Check(char *s);
void Take_componet();

char Data_Bank[][40] = { //     MATRIZ CONTENDOS OS CARGOS E EMPREGADOS
                            "Chefe"             ,"edson dos santos lomba",
                            "Direitor"          ,"Jailton santana Lomba" ,
                            "funcionario1"      ,"Antonio",
                            "funcionario2"      ,"Marcos",
                            "funcionario3"      ,"Paulo",
                            "funcionario4"      ,"Vanessa",
                            "funcionario5"      ,"Carla",
                            "funcionario6"      ,"Maria",
                        };

char Input[80];             //ENTRADA DE DADOS
char Component[80];         //PARAMETRO PARA FUNCAO
char *Ponteiro;             //PONTEIRO

int main()
{
    int indice;
    char option;            //opçao escolhida

    do{
            printf("\tInforme o cargo que deseja pesquisa: ");
            gets(Input);
            Ponteiro=Input;
            printf("\tNome do funcionario:");
            Take_componet();

            do{

                indice = Check(Component);

                if(indice != -1)
                {
                    printf("\t %s", Data_Bank[indice +1 ] );
                }
                else
                    printf("\t SEM REGISTRO NO BANCO DE DADO");

                Take_componet();

            }while(*Component);
            printf("\n\n");

            printf("\tDeseja realiza mais busca no banco de dado? s - sim | n - nao \n");
            scanf("%c", &option);
            getchar();

    }while(option=='s'  ||  option=='S');

    system("PAUSE");
    return 0;
}
//          DESENVOLVIMENTO DE FUNÇOES AUXILIARES

int Check(char *s)                      //retorna localizaçao correspondente
{
    int i;
    for(i=0; *Data_Bank[i] ; i++)       /*Varre a matriz Data_Bank  */
    {
        if(!strcmp (Data_Bank[i],s))     /* comparaçao das matrizes */
            break;
    }//end for

    if(*Data_Bank[i])                   //retorna indice correspondente
    {
        return ( i );
    }
    else
        return ( -1 );                  //retorna -1 se nao haver

} //end check

void Take_componet()
{

    char *q;    //ponteiro auxiliar
    /* RECARREGA O ENDEREÇO DO COMPONENTE (quando chamada)  */

    q= Component;

    /*PEGA PROXIMO COMPONENTE*/

    while(*Ponteiro && *Ponteiro != ' ')
    {
        *q=*Ponteiro;
        Ponteiro++;
        q++;

    }//end while

    if(*Ponteiro == ' ')
    {
        Ponteiro++;
    }
*q ='\0';       //TERMINADOR NULO
}//end Take_componet
