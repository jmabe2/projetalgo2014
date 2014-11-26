#include<stdio.h>

int verifprenom(char* chaine) ;

int verifprenom(char* chaine)

{
int i,erreur=0;

for (i=0;i<31;i++)
    {
    if (i==0&&chaine[i]<65||i==0&&chaine[i]>90)
       {
       return 0;
       }
    else if (!(chaine[i]>=65&&chaine[i]<=90||chaine[i]==32||chaine[i]==45||chaine[i]==0||chaine[i]==10))
       {
       return 0;
       }
    }
    return 1;
}

main()

{
 char prenom[31]="";     
 do
 {
      fflush(stdin);
      printf("Veuillez introduire un pr%cnom en majuscule : ",130);
      fgets(prenom,31,stdin);
 }
 while(verifprenom(prenom)==0);
          
system("pause");
}

