#include<stdlib.h>
#include<stdio.h>
#define M 4
#define P 4
//ClientA
struct clientA
{
   int numero;
   char nom[31];
   char prenom[31];
   char datenaiss[11];
   char num_compte[20];
   char num_reg_nat[14];
};
struct clientA nouveauClientA;
struct clientA sourceA[M];
struct clientA trinumA[M];
struct clientA trinomA[M];
int tailleSourceA;
//ClientB
struct clientB
{
  char nom[31];
  char prenom[31];
  char datenaiss[11];
};
int tailleSourceB;
int tailleClientsCommuns;
struct clientB sourceB[P];
struct clientB clients_communs[0];
struct clientB nouveauClientB;
//Prototype
//Manuel 
struct clientA encodenouvclientA();
int verifdatenaiss(char *chaine);
void afficherClientA(struct clientA source);
int compatibildatenaissregnat(char *datenaiss,char *num_reg_nat);
int getsPerso(char *destination,int size,char *fonctionverif);
//Axel
int verifprenom(char *chaine); 
//Jean-michel
int verifnumregnat (char* chaine); 
int verifstrformat (char* format, char* chaine);
int verifnumcompte (char* chaine);
//Patrick
int verifnom(char* chaine);
//William
void stringcopy (char* source, char* destination);

//Fonction

//Axel
int verifprenom(char *chaine) 
{ 
int i; 
for (i=0;i<31;i++) 
    { 
       if (i==0&&chaine[i]<65||i==0&&chaine[i]>90) 
       {
       	printf("pr%cnom incorrect !\n",130);
        return 0; 
       } 
       else if (!(chaine[i]>=65&&chaine[i]<=90||chaine[i]==32||chaine[i]==45||chaine[i]==0||chaine[i]==10)) 
       {
       	printf("pr%cnom incorrect !\n",130);
        return 0; 
       } 
    } 
    return 1; 
}
//Jean-michel
int verifstrformat (char* format, char* chaine) 
{ 
 int i;
 if (strlen(format) == strlen(chaine)) 
 { 
	for (i=0;i<strlen(chaine);i++) 
	{ 
		switch(format[i]) 
			{ 
				case '#' : if ((chaine[i] < 48) || (chaine[i] > 57)) 
				           { 
				             printf("Valeur entr%ce incorrecte !\n",130);
				             return 0;
				           } 
			                   break; 
			        default : if (chaine[i] != format[i]) 
			                  { 
			                     printf("Valeur entr%ce incorrecte !\n",130);
			                     return 0;
				          }
				          break;
			} 
        } 
 } 
 else 
 {
    printf("Valeur entr%ce incorrecte !\n",130);
    return 0;
 } 
    return 1; 
}
int verifnumregnat (char* chaine) 
{ 
  return verifstrformat("######-###-##", chaine); 
}  
int verifnumcompte (char* chaine) 
{ 
	return verifstrformat("BE## #### #### ####", chaine); 
}  
//Patrick  
//Fonction modifer par Manuel
int verifnom(char* chaine)
{
 int i=0;
 while (chaine[i] !='\0')
 {
  if((i==0)&&(chaine[i]<65||chaine[i]>90))
  {
   printf("Nom incorrect !\n");
   return 0;
  }
                                         //Ou exclusif
  else if((chaine[i]<65||chaine[i]>90)&&(chaine[i]==32^chaine[i]==0)==0)
  {
   printf("Nom incorrect !\n");
   return 0;
  }
  i++;
 }
 return 1;
}
//Ta fonction ne fonctionnait pas
/*
int verifnom(char* chaine) 
{  
  int i=0; 
  int j=0; 
while (chaine[i] !='\0' ) 
{ 
	 
	if(chaine[0]==32)	 
	{ 
			j=1; 
			break; 
	} 
	 
	if (chaine[i]>65 || chaine[i]<90) 
	{ 
			j=0;
            break;	 
	} 		 
	if (chaine[i]<65 && chaine[i]!=32|| chaine[i]>90 ) 
	{  
		j=1; 
		break; 
	} 
	i++;		 
}
return printf("%d",j); 
}
*/
//Manuel
int verifdatenaiss(char *chaine)
{
       int jour,mois,annee;
       //On vérifie si la date comporte un caractere autre qu'un chiffre ou le slash '/'.
       int i;
    for(i=0;i<sizeof(nouveauClientA.datenaiss);i++)
    {
       if((i==0||i==1||i==3||i==4||i==6||i==7||i==8||i==9)&&(chaine[i]<48||chaine[i]>57))
       {
          printf("Date de naissance incorrecte !\n");
          return 0;
       }
       else if((i==2||i==5)&&chaine[i]!=47)
       {
         printf("Date de naissance incorrecte !\n");
         return 0;
       }
    }
        //On converti chaque caractères en entier en soutrayant avec le caractere 0 '0'.
        jour = ((chaine[0]-'0')*10)+chaine[1]-'0' ;
        mois = ((chaine[3]-'0')*10)+chaine[4]-'0';
        annee = ((chaine[6]-'0')*1000)+((chaine[7]-'0')*100)+((chaine[8]-'0')*10)+chaine[9]-'0';
        if(annee>2014||annee<1900)
        {
         printf("Date de naissance incorrecte !\n");
         return 0;
        }
        switch(mois)
        {
            case 1 : if(jour>31||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 2 : if(annee%4==0&&annee%100!=0)
                     {
                       if(jour>29||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;;
                       }           
                     }
                     else
                     {
                       if(jour>28||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
                     }
            break;
            case 3 : if(jour>31||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 4 : if(jour>30||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 5 : if(jour>31||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 6 : if(jour>30||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 7 : if(jour>31||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 8 : if(jour>31||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 9 : if(jour>30||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 10 : if(jour>31||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 11 : if(jour>30||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            case 12 : if(jour>31||jour<=0)
                       {
                         printf("Date de naissance incorrecte !\n");
                         return 0;
                       }
            break;
            default : printf("Date de naissance incorrecte !\n");
                      return 0;
            break;
        }
        return 1;
}
void afficherClientA(struct clientA source)
{
     int i;
     for(i=0;i<80;i++)
     {
      printf("*");
     }
     printf("Num%cro de client : %d",130,source.numero);  
     printf("\nNom : %s",source.nom);
     printf("\nPr%cnom : %s",130,source.prenom);
     printf("\nDate de naissance : %s",source.datenaiss);
     printf("\nNum%cro de compte : %s",130,source.num_compte);  
     printf("\nNum%cro de registre national : %s",130,source.num_reg_nat);
     printf("\n");
     for(i=0;i<80;i++)
     {
      printf("*");
     }
}
int compatibildatenaissregnat(char *datenaiss,char *num_reg_nat)
{
  char datenaiss_temp[6];
  int i;
  datenaiss_temp[0]=datenaiss[8];
  datenaiss_temp[1]=datenaiss[9];
  datenaiss_temp[2]=datenaiss[3];
  datenaiss_temp[3]=datenaiss[4];
  datenaiss_temp[4]=datenaiss[0];
  datenaiss_temp[5]=datenaiss[1];
  for(i=0;i<6;i++)
  {
    if(num_reg_nat[i]!=datenaiss_temp[i])
    {
      printf("Date de naissance et num%cro de registre incompatible !\n",130);
      return 0;
    }
  }
  return 1;
}
struct clientA encodenouvclientA()
{
   int registreCorrect = 0,encoder = 0,i;
   nouveauClientA.numero=0;
   do
   {
     printf("Veuillez entre le num%cro de client : ",130);
     fflush(stdin);
     scanf("%d",&nouveauClientA.numero);
     if(nouveauClientA.numero<=0)
     {
      printf("Num%cro client incorrect !\n",130);
     }
   }
   while(nouveauClientA.numero<=0);
   do
   {
     printf("\n30 caract%cres maximum.",138);
     printf("\nVeuillez entrez le nom : ");
     fflush(stdin);
   }
   while(getsPerso(nouveauClientA.nom,sizeof(nouveauClientA.nom),"verifnom")==0);
   do
   {
     printf("\n30 caract%cres maximum.",138);
     printf("\nVeuillez entrez le pr%cnom : ",130);
     fflush(stdin);
   }
   while(getsPerso(nouveauClientA.prenom,sizeof(nouveauClientA.prenom),"verifprenom")==0); 
   do
   {
     printf("\n19 caract%cres maximum sous cette forme BEXX XXXX XXXX XXXX.",138);
     printf("\nVeuillez entrez le num%cro de compte : ",130);
     fflush(stdin);
   }
   while(getsPerso(nouveauClientA.num_compte,sizeof(nouveauClientA.num_compte),"verifnumcompte")==0); 
   while(registreCorrect==0)
   {
       do
       {
         printf("\n10 caract%cres maximum sous cette forme JJ/MM/AAAA.",138);
         printf("\nVeuillez entrez la date de naissance : ");
         fflush(stdin);
       }
       while(getsPerso(nouveauClientA.datenaiss,sizeof(nouveauClientA.datenaiss),"verifdatenaiss")==0);
       do
       {
         printf("\n13 caract%cres maximum sous cette forme XXXXXX-XXX-XX",138);
         printf("\nVeuillez entrez le num%cro de registre national : ",130);
         fflush(stdin);
       }
       while(getsPerso(nouveauClientA.num_reg_nat,sizeof(nouveauClientA.num_reg_nat),"verifnumregnat")==0);
       if(compatibildatenaissregnat(nouveauClientA.datenaiss,nouveauClientA.num_reg_nat)==1)
       {
          registreCorrect=1;                                                                                
       }
   }
   while(encoder!=1)
   {
     int choix =-1;
     system("cls");
     printf("Voici les informations concernant le client\n");
     afficherClientA(nouveauClientA);
     printf("\n\n");
     printf("0) Modifier le num%cro de client.\n",130);
     printf("1) Modifier le nom.\n");
     printf("2) Modifier le pr%cnom.\n",130);
     printf("3) Modifier la date de naissance et le registre national.\n");
     printf("4) Modifier le num%cro de compte.\n",130);
     printf("5) Encoder le client.\n");
     printf("Votre choix : "); 
     fflush(stdin);
     scanf("%d",&choix);
     system("cls");
     switch(choix)
     {
       case 0:    do
                  {
                     printf("Veuillez entre le num%cro de client : ",130);
                     fflush(stdin);
                     scanf("%d",&nouveauClientA.numero);
                     if(nouveauClientA.numero<=0)
                     {
                      printf("Num%cro client incorrect !\n",130);
                     }
                  }
                  while(nouveauClientA.numero==0);
                  break;
       case 1:   do
                 {
                     printf("\n30 caract%cres maximum.",138);
                     printf("\nVeuillez entrez le nom : ");
                     fflush(stdin);
                 }
                 while(getsPerso(nouveauClientA.nom,sizeof(nouveauClientA.nom),"verifnom")==0);
                 break;
       case 2: do
               {
                 printf("\n30 caract%cres maximum.",138);
                 printf("\nVeuillez entrez le pr%cnom : ",130);
                 fflush(stdin);
               }
               while(getsPerso(nouveauClientA.prenom,sizeof(nouveauClientA.prenom),"verifprenom")==0);
               break;
       case 3: registreCorrect = 0;
               while(registreCorrect==0)
                {
                       do
                       {
                         printf("\n10 caract%cres maximum sous cette forme JJ/MM/AAAA.",138);
                         printf("\nVeuillez entrez la date de naissance : ");
                         fflush(stdin);
                       }
                       while(getsPerso(nouveauClientA.datenaiss,sizeof(nouveauClientA.datenaiss),"verifdatenaiss")==0);
                       do
                       {
                         printf("\n13 caract%cres maximum sous cette forme XXXXXX-XXX-XX",138);
                         printf("\nVeuillez entrez le num%cro de registre national : ",130);
                         fflush(stdin);
                       }
                       while(getsPerso(nouveauClientA.num_reg_nat,sizeof(nouveauClientA.num_reg_nat),"verifnumregnat")==0);
                       if(compatibildatenaissregnat(nouveauClientA.datenaiss,nouveauClientA.num_reg_nat)==1)
                       {
                        registreCorrect=1;
                       }
                }
            break;
       case 4: do
               {
                 printf("\n19 caract%cres maximum sous cette forme BEXX XXXX XXXX XXXX.",138);
                 printf("\nVeuillez entrez le num%cro de compte : ",130);
                 fflush(stdin);
               }
               while(getsPerso(nouveauClientA.num_compte,sizeof(nouveauClientA.num_compte),"verifnumcompte")==0); 
            break;
       case 5: encoder=1;
            break;
     }
   }
   return nouveauClientA;
}
int getsPerso(char *destination,int size,char *fonctionverif)
{
 fflush(stdin);
 //Retourn 0 si le nombre de caractères est dépassé
 int caracteres = 0,i;
 char lettre,temp[size];
 //Initialisation de la chaine temporaire
 for(i=0;i<size;i++)
 {
  temp[i]=0;
 }
 temp[size-1]='\0';
 do
 {
  lettre = getchar();
  if(lettre!='\n')
  {
    temp[caracteres]=lettre;
    caracteres++;
  }
  if(caracteres>size-1)
  {
   printf("Nombre de caract%cres d%cpass%c\n",138,130,130);
   return 0;
  }
 }
 while(lettre!='\n');
 if(fonctionverif=="verifnom"&&verifnom(temp)==1)
 {
   for(i=0;i<size;i++)
   {
    destination[i] = temp[i];
   }
   return 1;
 }
 else if(fonctionverif=="verifprenom"&&verifprenom(temp)==1)
 {
   for(i=0;i<size;i++)
   {
    destination[i] = temp[i];
   }
   return 1;
 }
 else if(fonctionverif=="verifdatenaiss"&&verifdatenaiss(temp)==1)
 {
    for(i=0;i<size;i++)
   {
    destination[i] = temp[i];
   }
   return 1;
 }
 else if(fonctionverif=="verifnumcompte"&&verifnumcompte(temp)==1)
 {
   for(i=0;i<size;i++)
   {
    destination[i] = temp[i];
   }
  return 1;
 }
 else if(fonctionverif=="verifnumregnat"&&verifnumregnat(temp)==1)
 {
   for(i=0;i<size;i++)
   {
    destination[i] = temp[i];
   }
   return 1;
 }
 return 0;
}
//William
void stringcopy (char* source, char* destination) 
{ 
   int i = 0;
   do 
   { 
       destination[i] = source[i]; 
       i++; 
    } 
    while (source[i] != '\0');
} 
//Fonction banqueA
void banqueA()
{
    int i;
    printf("Encodage des clients de la banque A\n");
    do
    {
     printf("Nombre de clients %c encoder : ",133);
     fflush(stdin);
     scanf("%d",&tailleSourceA);
     if(tailleSourceA<=0)
     {
      printf("Nombre incorrect !\n");
     }
     else if(tailleSourceA>M)
     {
       printf("D%cpassement de la limite autoris%ce !\n",130,130);
     }
    }
    while(tailleSourceA>M||tailleSourceA<=0);
    //Debut de l'encodage de la banqueA
    system("cls");
    for(i=0;i<tailleSourceA;i++)
    {
      printf("Cient %d)\n",i+1);
      //Patrick doit faire la fonction
      //structclientAcopy(encodenouvclientA(),&sourceA[i]);
    }
}
main()
{
  int choix=-1;
     while(choix!=0)
     {
      printf("Encoder les clients 1)\n");
      printf("Lire les fichiers   2)\n");
      printf("Votre choix : ");
      scanf("%d",&choix);
      system("cls");
      switch(choix)
      {
       case 1 :banqueA();
            break;
       case 2 : printf("pas fait !!\n");
            break;
       default : 
            printf("choix incorrect !\n");
            system("pause");
            system("cls");
            break;
      }
     }
    system("pause");
}
