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
}clienta;
//ClientB
struct clientB
{
  char nom[31];
  char prenom[31];
  char datenaiss[11];
}clientb;
//Prototype
//Non faite

struct clientB encodenouvclientB();
void clientsCommuns();/*Cette fonction verifie si un fichier clientA et clientB existe,
                       si il existe il recherche les clients communs aux 2 fichiers*/
void trinum();
void ecrireFichierB(char *chemin_fichier,int tailleSourceB,struct clientA *sourceB);
void lectureFichierB(char *chemin_fichier);
struct clientB encodenouvclientB()
{
}
void clientsCommuns()
{
}
void trinum()
{
}
void ecrireFichierB(char *chemin_fichier,int tailleSourceB,struct clientA *sourceB)
{
}
void lectureFichierB(char *chemin_fichier)
{
}

//Manuel 
int getsPerso(char *destination,int size,char *fonctionverif);
int verifdatenaiss(char *chaine);
int compatibildatenaissregnat(char *datenaiss,char *num_reg_nat);
struct clientA encodenouvclientA();
void banqueA(int tailleSourceA,struct clientA *sourceA,struct clientA *trinomA,struct clientA *trinumA);
void banqueB(int tailleSourceB,struct clientB *sourceB);
void afficherClientA(struct clientA *source);
void afficherClientsB(int tailleSourceB,struct clientB *sourceB);
void ecrireFichierA(char *chemin_fichier,int tailleSourceA,struct clientA *sourceA);
void lectureFichierA(char *chemin_fichier);
//Axel
int verifprenom(char *chaine);
int stringcomp(char *chaineA,char *chaineB);
void trinom(); 
//Jean-michel
int verifnumregnat (char* chaine); 
int verifnumcompte (char* chaine);
int verifstrformat (char* format, char* chaine);
//Patrick
int verifnom(char* chaine);
void structclientAcopy (struct clientA source,struct clientA *destination);
void structclientBcopy (struct clientB source,struct clientB *destination);
//William
void stringcopy (char* source, char* destination);
void afficherClientB(struct clientB *source);
void afficherClientsA(int tailleSourceA,struct clientA *source);

//Fonction
//William
//Modificer par Manuel :  j'ai modifier ta fonction, pour utiliser un pointeur a la place d'un nom de tableau car on n'utiliser plus de variables globales                
void afficherClientsA(int tailleSourceA,struct clientA *source)
{
  int x=0;
  printf("Liste des clients de la banque A\n");
  for(x=0;x<tailleSourceA;x++)
  {
   printf("Informations sur le client %d)\n",x+1);//x+1 permet de commencer au client 1 meme si ses donnÃ©es correspondent au 0
   afficherClientA(&source[x]);
  }
}
void afficherClientB(struct clientB *source)
{
    int x=0;
    for(x=0;x<80;x++)
    {
      printf("*");
    }
    printf("\nPrenom : %s\n",source->prenom);
    printf("Nom : %s\n",source->nom);
    printf("Date de naissance : %s\n",source->datenaiss);
    for(x=0;x<80;x++)
    {
      printf("*");
    }
} 
void stringcopy (char* source, char* destination) 
{ 
   int i = 0;
   do 
   { 
       destination[i] = source[i]; 
       i++; 
    } 
    while (source[i] != '\0');
    destination[i] = '\0';
} 
//Axel
void trinom(int tailleSourceA,struct clientA *trinomA)
{
  int i,limite=tailleSourceA-1,pos,trier=0;
  if(tailleSourceA >1)
  {
      while(trier==0)
      {
        trier = 1;
        for(i=0;i<limite;i++)
        {
              if (stringcomp(trinomA[i].nom,trinomA[i+1].nom)==-1)
              {
                  struct clientA temp = trinomA[i];
                  trinomA[i] = trinomA[i+1];
                  trinomA[i+1] = temp;
                  trier=0;
                  pos=i;
              }
        }
        limite=pos;
      }
  }
}

int stringcomp(char *chaineA,char *chaineB)//fonction de comparaison de 2 chaÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â®nes de caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨res
/*
   La fonction renvoie la valeur 0 si les chaine A et B sont identiques.
   La fonction renvoie la valeur 1 si la chaine A prÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de la chaine B dans l'ordre lexicographique.
   La fonction renvoie la valeur -1 si la chaine A succÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de la chaine B dans l'ordre lexicographique.
*/
{
    int i=0;
    while(chaineA[i]!='\0'&&chaineB[i]!='\0')//tant que l'on n'est pas arrivÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© au caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨re de fin de chaÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â®ne dans la chaine A et dans la chaine B.
    {
        if((int)chaineA[i]<(int)chaineB[i])//si le caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨re en cours de la chaine A prÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de le caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨re en cours de la chaine B.
            return 1; //on renvoie 1 car la chaine A prÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de la chaine B.
        else
        {
            if((int)chaineA[i]>(int)chaineB[i])//si le caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨re en cours de la chaine B prÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de le caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨re en cours de la chaine A.
                return -1;//on renvoie 1 car la chaine A succÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de la chaine B.
            else
                i++; //jusqu'ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  prÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©sent les caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨res sont identique -> on passe au caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨re suivant
        }
    }
    // on a quittÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© la boucle while car on est tombÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© sur une marque de fin de chaÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â®ne, soit dans la chaine A, soit dans la chaine B, soit dans les 2.
    if(chaineA[i]==chaineB[i])//si les caractÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨res sont identiques, alors il s'agit forcÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©ment de la marque de fin de chaÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â®ne
        return 0;//on renvoie 0 car les 2 chaÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â®nes sont identiques
    else
    {
        if(chaineA[i]=='\0')// on est arrivÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  la fin de la chaine A mais pas ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  la fin de la chaine B -> la chaine A prÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de la chaine B.
            return 1;
        else
            return -1; // sinon on est arrivÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â© ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  la fin de la chaine B mais pas ÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â  la fin de la chaine A-> la chaine B prÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â©cÃƒÆ’Ã†â€™Ãƒâ€šÃ‚Â¨de la chaine A.
    }
}
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
void structclientAcopy (struct clientA source,struct clientA *destination)
{
	destination->numero = source.numero;
	stringcopy(source.nom, destination->nom);
	stringcopy(source.prenom, destination->prenom);
	stringcopy(source.datenaiss, destination->datenaiss);
	stringcopy(source.num_compte, destination->num_compte);
	stringcopy(source.num_reg_nat, destination->num_reg_nat);
}
void structclientBcopy (struct clientB source,struct clientB *destination)
{
	stringcopy(source.nom, destination->nom);
	stringcopy(source.prenom, destination->prenom);
	stringcopy(source.datenaiss, destination->datenaiss);

}
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

//Manuel
void afficherClientsB(int tailleSourceB,struct clientB *sourceB)
{
   int i ;
   for(i=0;i<tailleSourceB;i++)
   {
     afficherClientB(&sourceB[i]);
   }
}
void lectureFichierA(char *chemin_fichier)
{
  FILE *fichier = NULL;
  fichier = fopen(chemin_fichier,"r");
  if(fichier == NULL)
  {
    printf("Ouverture impossible !\n");
  }
  else
  {
    fseek(fichier,0,SEEK_END);
    int nbclients = ftell(fichier)/sizeof(clienta),i;
    fseek(fichier,0,SEEK_SET);
    struct clientA clients[nbclients];
    fread(clients,sizeof(clienta),nbclients,fichier);
    for(i=0;i<nbclients;i++)
    {
      afficherClientA(&clients[i]);
    }
  }
}
void ecrireFichierA(char *chemin_fichier,int tailleSourceA,struct clientA *source)
{
  FILE *fichier = NULL;
  fichier = fopen(chemin_fichier,"wb+");
  if(fichier == NULL)
  {
    printf("Ouverture impossible !\n");
  }
  else
  {
    fwrite(source,sizeof(clienta),tailleSourceA,fichier);
    fclose(fichier);
  }
}
int verifdatenaiss(char *chaine)
{
       int jour,mois,annee;
       //On vÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©rifie si la date comporte un caractere autre qu'un chiffre ou le slash '/'.
       int i;
    for(i=0;i<sizeof(clienta.datenaiss);i++)
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
        //On converti chaque caractÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¨res en entier en soutrayant avec le caractere 0 '0'.
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
void afficherClientA(struct clientA *source)
{
     int i;
     for(i=0;i<80;i++)
     {
      printf("*");
     }
     printf("\nNum%cro de client : %d",130,source ->numero);  
     printf("\nNom : %s",source ->nom);
     printf("\nPr%cnom : %s",130,source ->prenom);
     printf("\nDate de naissance : %s",source->datenaiss);
     printf("\nNum%cro de compte : %s",130,source->num_compte);  
     printf("\nNum%cro de registre national : %s",130,source->num_reg_nat);
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
   struct clientA nouveauclient;
   do
   {
     printf("Veuillez entre le num%cro de client : ",130);
     fflush(stdin);
     scanf("%d",&nouveauclient.numero);
     if(nouveauclient.numero<=0)
     {
      printf("Num%cro client incorrect !\n",130);
     }
   }
   while(nouveauclient.numero<=0);
   do
   {
     printf("\n30 caract%cres maximum.",138);
     printf("\nVeuillez entrez le nom : ");
     fflush(stdin);
   }
   while(getsPerso(nouveauclient.nom,sizeof(nouveauclient.nom),"verifnom")==0);
   do
   {
     printf("\n30 caract%cres maximum.",138);
     printf("\nVeuillez entrez le pr%cnom : ",130);
     fflush(stdin);
   }
   while(getsPerso(nouveauclient.prenom,sizeof(nouveauclient.prenom),"verifprenom")==0); 
   do
   {
     printf("\n19 caract%cres maximum sous cette forme BEXX XXXX XXXX XXXX.",138);
     printf("\nVeuillez entrez le num%cro de compte : ",130);
     fflush(stdin);
   }
   while(getsPerso(nouveauclient.num_compte,sizeof(nouveauclient.num_compte),"verifnumcompte")==0); 
   while(registreCorrect==0)
   {
       do
       {
         printf("\n10 caract%cres maximum sous cette forme JJ/MM/AAAA.",138);
         printf("\nVeuillez entrez la date de naissance : ");
         fflush(stdin);
       }
       while(getsPerso(nouveauclient.datenaiss,sizeof(nouveauclient.datenaiss),"verifdatenaiss")==0);
       do
       {
         printf("\n13 caract%cres maximum sous cette forme XXXXXX-XXX-XX",138);
         printf("\nVeuillez entrez le num%cro de registre national : ",130);
         fflush(stdin);
       }
       while(getsPerso(nouveauclient.num_reg_nat,sizeof(nouveauclient.num_reg_nat),"verifnumregnat")==0);
       if(compatibildatenaissregnat(nouveauclient.datenaiss,nouveauclient.num_reg_nat)==1)
       {
          registreCorrect=1;                                                                                
       }
   }
   while(encoder!=1)
   {
     int choix =-1;
     system("cls");
     printf("Voici les informations concernant le client\n");
     afficherClientA(&nouveauclient);
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
                     scanf("%d",&nouveauclient.numero);
                     if(nouveauclient.numero<=0)
                     {
                      printf("Num%cro client incorrect !\n",130);
                     }
                  }
                  while(nouveauclient.numero<=0);
                  break;
       case 1:   do
                 {
                     printf("\n30 caract%cres maximum.",138);
                     printf("\nVeuillez entrez le nom : ");
                     fflush(stdin);
                 }
                 while(getsPerso(nouveauclient.nom,sizeof(nouveauclient.nom),"verifnom")==0);
                 break;
       case 2: do
               {
                 printf("\n30 caract%cres maximum.",138);
                 printf("\nVeuillez entrez le pr%cnom : ",130);
                 fflush(stdin);
               }
               while(getsPerso(nouveauclient.prenom,sizeof(nouveauclient.prenom),"verifprenom")==0);
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
                       while(getsPerso(nouveauclient.datenaiss,sizeof(nouveauclient.datenaiss),"verifdatenaiss")==0);
                       do
                       {
                         printf("\n13 caract%cres maximum sous cette forme XXXXXX-XXX-XX",138);
                         printf("\nVeuillez entrez le num%cro de registre national : ",130);
                         fflush(stdin);
                       }
                       while(getsPerso(nouveauclient.num_reg_nat,sizeof(nouveauclient.num_reg_nat),"verifnumregnat")==0);
                       if(compatibildatenaissregnat(nouveauclient.datenaiss,nouveauclient.num_reg_nat)==1)
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
               while(getsPerso(nouveauclient.num_compte,sizeof(nouveauclient.num_compte),"verifnumcompte")==0); 
            break;
       case 5: encoder=1;
            break;
     }
   }
   return nouveauclient;
}
int getsPerso(char *destination,int size,char *fonctionverif)
{
 fflush(stdin);
 //Retourn 0 si le nombre de caractÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¨res est dÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©passÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Â ÃƒÂ¢Ã¢â€šÂ¬Ã¢â€žÂ¢ÃƒÆ’Ã†â€™ÃƒÂ¢Ã¢â€šÂ¬Ã…Â¡ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©
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
   stringcopy(temp,destination);
   return 1;
 }
 else if(fonctionverif=="verifprenom"&&verifprenom(temp)==1)
 {
   stringcopy(temp,destination);
   return 1;
 }
 else if(fonctionverif=="verifdatenaiss"&&verifdatenaiss(temp)==1)
 {
   stringcopy(temp,destination);
   return 1;
 }
 else if(fonctionverif=="verifnumcompte"&&verifnumcompte(temp)==1)
 {
  stringcopy(temp,destination);
  return 1;
 }
 else if(fonctionverif=="verifnumregnat"&&verifnumregnat(temp)==1)
 {
   stringcopy(temp,destination);
   return 1;
 }
 return 0;
}

//Fonction banqueA
void banqueA(int tailleSourceA,struct clientA *sourceA,struct clientA *trinomA,struct clientA *trinumA)
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
      structclientAcopy(encodenouvclientA(),&sourceA[i]);
      structclientAcopy(sourceA[i],&trinomA[i]);
      structclientAcopy(sourceA[i],&trinumA[i]);
    }
    system("cls");
    //Affichage des diffÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©rents tableau de la banqueA
    int choix;
    while(choix!=0)
    {
     if(tailleSourceA<=1)
     {
       printf("Afficher les clients 1)\n");
       printf("Continuer            0)\n");
       fflush(stdin);
       printf("Votre choix : ");
       scanf("%d",&choix);
       switch(choix)
       {
        case 0 :system("cls");
                break;
        case 1 :system("cls");
                afficherClientsA(tailleSourceA,sourceA);
                break;
        default : printf("Code incorrect !\n");
                  system("pause");
                  system("cls");
               break; 
       }
     }
     
     else
     {
         //Appel des fonctions trinom et trinum seulement si le tableau sourceA possÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â¨de plus de 1 client
         trinom(tailleSourceA,trinomA);
         trinum();
         printf("Afficher les clients                       1)\n");
         printf("Afficher les clients par nom               2)\n");
         printf("Afficher les clients par num%cro de client  3)\n",130);
         printf("Continuer                                  0)\n");
         printf("Votre choix : ");
         fflush(stdin);
         scanf("%d",&choix);
         system("cls");
         switch(choix)
         {
           case 0 : 
                    break;
           case 1 : afficherClientsA(tailleSourceA,sourceA);
                    break;
           case 2 : afficherClientsA(tailleSourceA,trinomA);
                    break;
           case 3 : afficherClientsA(tailleSourceA,trinumA);
                    break;
           default : printf("Code incorrect !\n");
                     system("pause");
                     system("cls");
               break;
           }
     }
    }
    
    //Debut de l'ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©criture des fichiers de la banqueA
     ecrireFichierA("sourceA",tailleSourceA,sourceA);
     ecrireFichierA("trinumA",tailleSourceA,trinumA);
     ecrireFichierA("trinomA",tailleSourceA,trinomA);
    //Debut de la lecture et affichage des fichiers de la banqueA
     choix =-1;
     while(choix!=4)
     {
      printf("\nLire et afficher le fichier de la banque A sans tri.                      1)\n");
      printf("Lire et afficher le fichier de la banque A avec tri par nom                 2)\n");
      printf("Lire et afficher le fichier de la banque A avec tri par num%cro de client   3)\n",130);
      printf("Continuer                                                                   4)\n");
      printf("Votre choix : ");
      fflush(stdin);
      scanf("%d",&choix);
      system("cls");
      switch(choix)
      {
        case 1 : lectureFichierA("sourceA");
             break;
        case 2 : lectureFichierA("trinomA");
             break;
        case 3 :lectureFichierA("trinumA");
             break;
        case 4 : system("cls");
             break;
        default : printf("choix incorrect !\n");
                  system("pause");
                  system("cls");
             break;
      }
     }
}
void banqueB(int tailleSourceB,struct clientB *sourceB)
{
 //Debut du programme de la banqueB
    int i;
    system("cls");
    printf("Encodage des clients de la banque B\n");
    do
    {
     printf("Nombre de clients %c encoder : ",133);
     fflush(stdin);
     scanf("%d",&tailleSourceB);
     if(tailleSourceB<=0)
     {
      printf("Nombre incorrect !\n");
     }
     else if(tailleSourceB>P)
     {
       printf("D%cpassement de la limite autoris%ce !\n",130,130);
     }
    }
    while(tailleSourceB>P||tailleSourceB<=0);
    //Debut de l'encodage de la banqueB
    system("cls");
    for(i=0;i<tailleSourceB;i++)
    {
      printf("Cient %d)\n",i+1);
      structclientBcopy(encodenouvclientB(),&sourceB[i]);
    }
    //Affichage du tableau de la banqueB
    afficherClientsB(tailleSourceB,sourceB);
    system("pause");
    system("cls");
    /*
    //Debut de l'ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©criture du fichier de la banqueB
    ecrireFichier("BanqueB.bin",sourceB);
    //Debut de la lecture et affichage du fichier de la banqueB
    lectureFichier("BanqueB.bin");
    //Recherche, affiche et ÃƒÆ’Ã†â€™Ãƒâ€ Ã¢â‚¬â„¢ÃƒÆ’Ã¢â‚¬Å¡Ãƒâ€šÃ‚Â©crit les client communs
    clientsCommuns();
    system("pause");
    system("cls");*/
}
main()
{
    struct clientA nouveauClientA;
    struct clientA sourceA[M];
    struct clientA trinumA[M];
    struct clientA trinomA[M];
    int tailleSourceB;
    int tailleClientsCommuns;
    struct clientB sourceB[P];
    struct clientB clients_communs[0];
    struct clientB nouveauClientB;
    int tailleSourceA;
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
       case 1 :
            banqueA(tailleSourceA,sourceA,trinomA,trinumA); 
            banqueB(tailleSourceB,sourceB);
            break;
       case 2 : 
            printf("Ordre de lecture des fichiers.\n");
            printf("1)Fichiers de la banqueA.\n");
            printf("2)Fichier de la banqueB.\n");
            printf("3)Fichier des clients communs.\n\n");
            system("pause");
            system("cls");
            choix =-1;
             while(choix!=4)
             {
              printf("\n1)Lire et afficher le fichier de la banque A sans tri.\n");
              printf("2)Lire et afficher le fichier de la banque A avec tri par nom.\n");
              printf("3)Lire et afficher le fichier de la banque A avec tri par num%cro de client.\n",130);
              printf("4)Continuer.\n");
              printf("Votre choix : ");
              fflush(stdin);
              scanf("%d",&choix);
              system("cls");
              switch(choix)
              {
                case 1 : lectureFichierA("sourceA");
                     break;
                case 2 : lectureFichierA("trinomA");
                     break;
                case 3 :lectureFichierA("trinumA");
                     break;
                case 4 : system("cls");
                     break;
                default : printf("choix incorrect !\n");
                          system("pause");
                          system("cls");
                     break;
              }
             }
            lectureFichierB("sourceB");
            system("pause");
            system("cls");
            lectureFichierB("clients_commun");
            system("pause");
            system("cls");
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
