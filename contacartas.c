#include <stdio.h>
#include <string.h>  //bibliotecas do projeto

int main()
{

//programa que lê uma string de "x" cartas, subtrai de uma string "u0" com todas as cartas possíveis e retorna um número "z" de cartas com probabilidade 0<="y"<=1 de serem as próximas e reinicia

int i=0, x, j=0, u0[13][4], y[13], k;        //declara variável
float z;

//declarando a string com todas as cartas do jogo
char naipes[4] = ("Copas", "Ouro", "Paus", "Espadas");
char Cartas[1][13] = ("A","2","3","4","5","6","7","8","9","10","J","Q","K"); //produto char*char carta_naipe [Ex: ACopas = Às Copas];

while(i<=13)
{
    while(j<=4)
    {
        u0[i][j] = 8;
    }
}

i=1;


//mostra o código das cartas
while(i<=13)
{
     while(j<=4)
    {
        printf("Código de carta: %d%d =",&i,j);
        printf("%s", Cartas[i]);
    }
}


//lê a carta
while(i=1)
{
printf("Para adicionar mais cartas digite 1");
scanf("%d",&i);
printf("Qual é o código da carta?");
scanf("%d%d",&i,j);

               //localiza a carta e subtrai do vetor u0:
                //u0 - x = u0;
                u0[i][j]--;

                i=1;

}

i = 1;
j = 1;



for(i<=13)
{
for(j<=4)
{
if(u[i][j]!=0)
  {
    y[i]=y[i]+u[i][j];
    k = k + u[i][j];

  }
  i++;

z[i]=y[i]/k
printf("%f",&z[i]);

}}


i=1;

}
