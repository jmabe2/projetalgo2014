#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define M 4  //Nb clients max Banque A
#define P 4  //Nb clients max Banque B

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

struct clientB
{
  char nom[31];
  char prenom[31];
  char datenaiss[11];
};

//Manuel
struct clientA nouveauClientA;
struct clientA encodenouvclientA();
int verifdatenaiss(char *chaine);
void afficherClientA(struct clientA *source);
int compatibildatenaissregnat(char *datenaiss,char *num_reg_nat);
int getsPerso(char *destination,int size,char *fonctionverif);
void banqueA(struct clientA *sourceA,struct clientA *trinomA,struct clientA *trinumA,int *tailleSourceA);
void banqueB(struct clientB *sourceB,int *tailleSourceB);
//Axel
int stringcomp(char *chaineA,char *chaineB);
int verifprenom(char *chaine);
void trinom(struct clientA *trinomA, int tailleSourceA);
//Jean-michel
int verifnumregnat (char* chaine);
void montreerreur(char*chaine, int pos);
int verifstrformat (char* format, char* chaine);
int verifnumcompte (char* chaine);
void clientsCommuns();
int lectureFichierClientsA(char *nom_fichier,struct clientA *destination,int *tailleSourceA);
int ecritureFichierClientsA(char *nom_fichier,struct clientA *source,int *tailleSourceA);
int lectureFichierClientsB(char *nom_fichier,struct clientB *destination,int *tailleSourceB);
int ecritureFichierClientsB(char *nom_fichier,struct clientB *source,int *tailleSourceB);
void rechercheClientsCommuns(struct clientA *trinomA,int *tailleSourceA,struct clientB *sourceB,int *tailleSourceB,struct clientB *clients_communs,int *tailleClientsCommuns);
void soustringcopy(char *source, char *destination, int posdepart, int nbpos);
int datevalide(char *chaine);
//Jean-Michel et Axel
void sousmenuAffichageBanque(char banque);
struct clientB encodenouvclientB();
void trinum(struct clientA *trinumA, int tailleSourceA);
//Patrick
int verifnom(char* chaine);
void structclientAcopy (struct clientA source,struct clientA *destination);
void structclientBcopy (struct clientB source,struct clientB *destination);
//William
void stringcopy (char* source, char* destination);
void afficherClientB(struct clientB *source);
void afficherClientsA(struct clientA *sourceA,int *tailleSourceA);
void afficherClientsB(struct clientB *sourceB,int *tailleSourceB);
// Mr Bury ;-)
int charlong (char *tab);

int charlong (char *tab)
//Cette fonction renvoie le nbre de caractères (sans le \0) du tableau de caractères dont tab contient l'adresse
{
    int cpt =0;
    while ( tab[cpt] != '\0')//tant que l'on est pas au caractère de fin de chaîne
          cpt++;//on incrémente cpt
    return cpt;//cpt est donc égal au nombre de caractères (sans le \0)
}

int verifnom (char *chaine)
/*Cette fontion vérifie si un nom est valide.
  La longueur de la chaine doit être de 1 à 30 caractères
  et les caractères sont des lettres de l'alphabet en majuscule
*/ 
{
	int i;
	if ((charlong(chaine) > 0) && (charlong(chaine) <= 30) && (chaine[0] !=32))
	{
		for (i=0;i<charlong(chaine);i++)
		{
			if (((chaine[i] < 65) || (chaine[i] > 90)) && (chaine[i] != 32))
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int verifprenom (char *chaine)
/*Cette fontion vérifie si un nom est valide.
  La longueur de la chaine doit être de 1 à 30 caractères
  et les caractères sont des lettres de l'alphabet en majuscule
  ou des tirets ou des espaces.
  La chaine ne peut pas commencer par un tiret ou un espace
*/ 
{
	int i;
	if ((charlong(chaine) > 0) && (charlong(chaine) <= 30) && (chaine[0] !=32) && (chaine[0] != 45))
	{
		for (i=0;i<charlong(chaine);i++)
		{
			if (((chaine[i] < 65) || (chaine[i] > 90)) && (chaine[i] != 32) && (chaine[i] != 45))
			{
				return 0;
			}
		}
		return 1;
	}
	else
	{
		return 0;
	}
	
}

int estbisextile(int annee)
/* Cette fontion retourne 1 si l'année est bisextile et 0 si elle ne l'est pas
   Les années bisextiles sont:
   soit divisibles par 4 mais pas par 100
   soit divisibles par 400
*/
{
	if (((annee % 4 == 0) && (annee % 100 != 0)) || (annee % 400 == 0))
		return 1;
	else
		return 0;

	
}

int nbjoursmois(int mois,int annee)
// Cette fonction renvoie le nombre de jours que contient un mois
{
	int joursparmois[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if (estbisextile(annee) && (mois == 2))
	{
		return 29;
	}
	else
	{
		return joursparmois[mois-1];
	}
}

void soustringcopy(char *source, char *destination, int posdepart, int nbpos)
/*Cette fonction copie le nombre de caractères définis par nbpos de la chaine de caractères source dans
la chaine de caractère destination à partir de la position de départ.
exemple:
si source = "BONJOUR"
et que l'on fait soustringcopy(source,destination,3,4)
alors destination = "JOUR"
*/
{
	int i;
	for (i=posdepart;i<posdepart+nbpos;i++)
	{
		destination[i-posdepart] = source[i];
	}
	destination[i-posdepart] = '\0';
	
}

int strtoint(char *chaine)
/*Convertit une chaine de caractère représentant un nombre entier en int*/
{
	int i, resultat;
	resultat = 0;
	for (i=0;i<charlong(chaine);i++)
	{
		resultat = resultat + ((chaine[i] - '0') * pow(10,charlong(chaine)-1-i));
	}
	return resultat;
}

int datevalide(char *chaine)
/*Vérifie que la chaine de caractère est une date valide*/
{
	char strtmp[5];
	int jour;
	int mois;
	int annee;
	if (verifstrformat("##/##/####", chaine)) //On vérifie si le format est correct
	{
		//On extrait jours, mois et année et on les convertit en entier
		soustringcopy(chaine,strtmp,0,2); 
		jour=strtoint(strtmp);
		soustringcopy(chaine,strtmp,3,2);
		mois=strtoint(strtmp);
		soustringcopy(chaine,strtmp,6,4);
		annee=strtoint(strtmp);
		//On vérifie si jour mois et année sont dans les bonnes plages de valeurs
		if ((annee > 0) && (mois > 0) && (mois <= 12) && (jour > 0) && (jour <= nbjoursmois(mois, annee)))
			return 1;
		else
			return 0;
	}
	else
	{
		return 0;
	}

}

int verifdatenaiss (char *chaine)
/*Cette fonction vérifie si la date de naissance est valide.
  La date doit être valide et doit être > 31/12/1904 et inférieure au 01/01/1997
*/
{	
	char strtmp[5];
	int annee;
	if (datevalide(chaine)) //On vérifie si la date est valide
	{
		soustringcopy(chaine,strtmp,6,4); //On extrait l'année
		annee=strtoint(strtmp);
		if ((annee > 1904) && (annee < 1997) ) //On vérifie si l'année est bien dans la plage de dates correctes
			return 1;
		else
			return 0;
    }
    else
    {
        return 0;
    }
}

void montreerreur(char *chaine, int pos)
{
//Cette fonction montre à l'utilisateur où est située l'erreur trouvée par la fonction verifstrformat
	int i;
	printf("\n%s\n",chaine);
	for (i=0;i<pos;i++)
	{
		printf(" ");
	}
	printf("^\n");
}

//Jean-michel
int verifstrformat (char* format, char* chaine)
/*
Cette fonction vérifie si la chaine correspond au format donné.
La longeur du format doit correspondre.
Les chiffres dans le format sont représentés par #.
Tous les autres caractères doivent être identiques.
*/
{
 int i;
 if (charlong(format) == charlong(chaine))
 {
	for (i=0;i<charlong(chaine);i++)
	{
		switch(format[i])
			{
				case '#' : if ((chaine[i] < 48) || (chaine[i] > 57))
				           {
				             printf("Erreur: Veuillez entrer un chiffre à cet endroit:\n");	
							 montreerreur(chaine,i);
				             return 0;
				           }
			                   break;
			        default : if (chaine[i] != format[i])
			                  {
			                     printf("Erreur: Valeur entr%ce incorrecte à cet endroit:\n",130);
			                     montreerreur(chaine,i);
			                     return 0;
				          }
				          break;
			}
        }
 }
 else
 {
    printf("Erreur: la taille de la valeur entrée est incorrecte\n La taille doit être de %d caractères\n",charlong(format));
    return 0;
 }
    return 1;
}

struct clientB encodenouvclientB()
// Cette fonction permet d'encoder les clients de la banque B
{
   int encoder = 0;
   struct clientB nouveauclient;

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
      printf("\n10 caract%cres maximum sous cette forme JJ/MM/AAAA.",138);
      printf("\nVeuillez entrez la date de naissance : ");
      fflush(stdin);
   }
   while(getsPerso(nouveauclient.datenaiss,sizeof(nouveauclient.datenaiss),"verifdatenaiss")==0);


   while(encoder!=1)
   {
     int choix =-1;
     system("cls");
     printf("Voici les informations concernant le client\n");
     afficherClientB(&nouveauclient);
     printf("\n\n");
     printf("1) Modifier le nom.\n");
     printf("2) Modifier le pr%cnom.\n",130);
     printf("3) Modifier la date de naissance\n");
     printf("4) Valider ce client.\n");
     printf("Votre choix : ");
     fflush(stdin);
     scanf("%d",&choix);
     system("cls");
     switch(choix)
     {
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
       case 3: do
               {
                  printf("\n10 caract%cres maximum sous cette forme JJ/MM/AAAA.",138);
                  printf("\nVeuillez entrez la date de naissance : ");
                  fflush(stdin);
               }
               while(getsPerso(nouveauclient.datenaiss,sizeof(nouveauclient.datenaiss),"verifdatenaiss")==0);
            break;
       case 4: encoder=1;
            break;
     }
   }
   return nouveauclient;
} //Axel et JM



void trinum(struct clientA *trinumA, int tailleSourceA)
// Cette fonction trie les clients par numéro de client
{
  int i,limite=tailleSourceA-1,pos,trier=0;
  if(tailleSourceA >1)
  {
      while(trier==0)
      {
        trier = 1;
        for(i=0;i<limite;i++)
        {
              if (trinumA[i].numero > trinumA[i+1].numero)
              {
                  struct clientA temp = trinumA[i];
                  trinumA[i] = trinumA[i+1];
                  trinumA[i+1] = temp;
                  trier=0;
                  pos=i;
              }
        }
        limite=pos;
      }
  }
}


int lectureFichierClientsA(char *nom_fichier,struct clientA *destination,int *tailleSourceA)
// Cette fonction permet de lire des fichiers dont les données sont formatées suivant la structure des cliets de la banque A
{
	int i;
	FILE *fp;
	struct clientA clientTmp;
		

    /* lecture dans le fichier*/
    if (!(fp = fopen(nom_fichier,"rb")))
        printf("erreur ouverture fichier!\n");
    else
    {
    	i=0;
        while( !feof( fp ) )  //On lit jusqu'à ce que le pointeur de fichier soit à la fin de celui-ci
        {
        	fread( &destination[i] , sizeof(struct clientA) , 1 , fp );
        	i++;
        }
        *tailleSourceA=i-1;

   }
}

int ecritureFichierClientsA(char *nom_fichier,struct clientA *source,int *tailleSourceA)
// Cette fonction permet d'écrire des fichiers dont les données sont formatées suivant la structure des cliets de la banque A
{
	FILE *fp;
	if (!(fp = fopen(nom_fichier,"wb")))
    	printf("erreur ouverture fichier!\n");
    else
    {
    	int i;    	
    	for (i=0;i<*tailleSourceA;i++)
    	{
        	fwrite( &source[i] , sizeof(struct clientA) , 1 , fp);
    	}
    	fclose(fp);

   }
	
	
}

int lectureFichierClientsB(char *nom_fichier,struct clientB *destination,int *tailleSourceB)
// Cette fonction permet de lire des fichiers dont les données sont formatées suivant la structure des cliets de la banque B
{
	int i;
	FILE *fp;
	struct clientB clientTmp;
		

    /* lecture dans le fichier*/
    if (!(fp = fopen(nom_fichier,"rb")))
        printf("erreur ouverture fichier!\n");
    else
    {
    	i=0;
        while( !feof( fp ) )
        {
        	fread( &destination[i] , sizeof(struct clientB) , 1 , fp );
        	i++;
        }
        *tailleSourceB=i-1;

   }
}

int ecritureFichierClientsB(char *nom_fichier,struct clientB *source,int *tailleSourceB)
// Cette fonction permet d'écrire des fichiers dont les données sont formatées suivant la structure des cliets de la banque B
{
	FILE *fp;
	if (!(fp = fopen(nom_fichier,"wb")))
    	printf("erreur ouverture fichier!\n");
    else
    {
    	int i;    	
    	for (i=0;i<*tailleSourceB;i++)
    	{
        	fwrite( &source[i] , sizeof(struct clientB) , 1 , fp);
    	}
    	fclose(fp);

   }
	
	
}

//Fonction
//William
void stringcopy (char* source, char* destination)
//Cette fonction copie la chaine de caractères source dans la chaine de caractères destination
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
void trinom(struct clientA *trinomA, int tailleSourceA)
// Cette fonction trie les clients par nom de client
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

int stringcomp(char *chaineA,char *chaineB)//fonction de comparaison de 2 chaÃƒÆ’Ã‚Â®nes de caractÃƒÆ’Ã‚Â¨res
/*
   La fonction renvoie la valeur 0 si les chaine A et B sont identiques.
   La fonction renvoie la valeur 1 si la chaine A précède la chaine B dans l'ordre lexicographique.
   La fonction renvoie la valeur -1 si la chaine A succède la chaine B dans l'ordre lexicographique.
*/
{
    int i=0;
    while(chaineA[i]!='\0'&&chaineB[i]!='\0')//tant que l'on n'est pas arrivé au caractère de fin de chaîne dans la chaine A et dans la chaine B.
    {
        if((int)chaineA[i]<(int)chaineB[i])//si le caractère en cours de la chaine A précède le caractère en cours de la chaine B.
            return 1; //on renvoie 1 car la chaine A précède la chaine B.
        else
        {
            if((int)chaineA[i]>(int)chaineB[i])//si le caractère en cours de la chaine B précède le caractère en cours de la chaine A.
                return -1;//on renvoie 1 car la chaine A succède la chaine B.
            else
                i++; //jusqu'à  présent les caractères sont identique -> on passe au caractère suivant
        }
    }
    // on a quitté la boucle while car on est tombé sur une marque de fin de chaîne, soit dans la chaine A, soit dans la chaine B, soit dans les 2.
    if(chaineA[i]==chaineB[i])//si les caractères sont identiques, alors il s'agit forcément de la marque de fin de chaîne
        return 0;//on renvoie 0 car les 2 chaînes sont identiques
    else
    {
        if(chaineA[i]=='\0')// on est arrivé  la fin de la chaine A mais pas à la fin de la chaine B -> la chaine A précède la chaine B.
            return 1;
        else
            return -1; // sinon on est arrivé à la fin de la chaine B mais pas à  la fin de la chaine A-> la chaine B précède la chaine A.
    }
}



int verifnumregnat (char* chaine)
//Cette fonction vérifie la validité du n° de registre national
{
  return verifstrformat("######-###-##", chaine);
}
int verifnumcompte (char* chaine)
//Cette fonction vérifie la validité du numéro de compte
{
	return verifstrformat("BE## #### #### ####", chaine);
}

//Patrick
void structclientAcopy (struct clientA source,struct clientA *destination)
//Cette fonction copie la structure source client A dans la structure destination client A
{
	destination->numero = source.numero;
	stringcopy(source.nom, destination->nom);
	stringcopy(source.prenom, destination->prenom);
	stringcopy(source.datenaiss, destination->datenaiss);
	stringcopy(source.num_compte, destination->num_compte);
	stringcopy(source.num_reg_nat, destination->num_reg_nat);
}

void structclientBcopy (struct clientB source,struct clientB *destination)
//Cette fonction copie la structure source client B dans la structure destination client B
{
	stringcopy(source.nom, destination->nom);
	stringcopy(source.prenom, destination->prenom);
	stringcopy(source.datenaiss, destination->datenaiss);

}


void afficherClientA(struct clientA *source)
//Affiche les données d'un client de la banque A
{
     int i;
     for(i=0;i<80;i++)
     {
      printf("*");
     }
     printf("Num%cro de client : %d",130,source ->numero);
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
//Cette fonction vérifie si la date de naissance correspond à celle stockée dans le numéro de registre national
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
//Cette fonction permet d'encoder un nouveau client de la banque A
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
     printf("5) Valider ce client.\n");
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
void banqueA(struct clientA *sourceA,struct clientA *trinomA,struct clientA *trinumA,int *tailleSourceA)
//Cette fonction permet d'encoder les clients de la banque A
{
    int i;
    printf("Encodage des clients de la banque A\n");
    do
    {
     printf("Nombre de clients %c encoder : ",133);
     fflush(stdin);
     scanf("%d",tailleSourceA);
     if(tailleSourceA<=0)
     {
      printf("Nombre incorrect !\n");
     }
     else if(*tailleSourceA>M)
     {
       printf("D%cpassement de la limite autoris%ce !\n",130,130);
     }
    }
    while(*tailleSourceA>M||tailleSourceA<=0);
    //Debut de l'encodage de la banqueA
    system("cls");
    for(i=0;i<*tailleSourceA;i++)
    {
      printf("Cient %d)\n",i+1);
      structclientAcopy(encodenouvclientA(),&sourceA[i]);
      structclientAcopy(sourceA[i],&trinomA[i]);
      structclientAcopy(sourceA[i],&trinumA[i]);
    }
    trinom(trinomA,*tailleSourceA);
    trinum(trinumA,*tailleSourceA);
    system("cls");
}

void banqueB(struct clientB *sourceB,int *tailleSourceB)
//Cette fonction permet d'encoder les clients de la banque A
{
    int i;
    system("cls");
    printf("Encodage des clients de la banque B\n");
    do
    {
     printf("Nombre de clients %c encoder : ",133);
     fflush(stdin);
     scanf("%d",tailleSourceB);
     if(tailleSourceB<=0)
     {
      printf("Nombre incorrect !\n");
     }
     else if(*tailleSourceB>P)
     {
       printf("D%cpassement de la limite autoris%ce !\n",130,130);
     }
    }
    while(*tailleSourceB>P||tailleSourceB<=0);
    //Debut de l'encodage de la banqueB
    system("cls");
    for(i=0;i<*tailleSourceB;i++)
    {
      printf("Cient %d)\n",i+1);
      structclientBcopy(encodenouvclientB(),&sourceB[i]);
    }
}



void afficherClientB(struct clientB *source)
//Affiche les données d'un client de la banque B
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

} //William

void afficherClientsB(struct clientB *sourceB,int *tailleSourceB)
//Affiche les données des clients de la banque B
{
int x=0;
for(x=0;x<*tailleSourceB;x++)
{
printf("Informations sur le client numero %d)\n",x+1);
afficherClientB(&sourceB[x]);
}
system("pause");
} //William

void afficherClientsA(struct clientA *sourceA,int *tailleSourceA)
{
int x=0;

for(x=0;x<*tailleSourceA;x++)
{
printf("Informations sur le client %d)\n",x+1);//x+1 permet de commencer au client 1 meme si ses données correspondent au 0//
afficherClientA(&sourceA[x]);
}
system("pause");
}

void sousmenuAffichageBanqueA(struct clientA *sourceA,struct clientA *trinomA,struct clientA *trinumA,int *tailleSourceA)
//Cette fonction affiche un menu permettant à l'utilisateur de choisir le tableau de données à afficher suivant le critère de tri choisi
{
	int choix=-1;
    while(choix!=0)
    {
		system("cls");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("XX                                  XX\n");
		printf("XX         Options de tri           XX\n");
		printf("XX                                  XX\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
		printf("1) Pas de tri\n");
		printf("2) Tri par numero de client\n");
		printf("3) Tri par nom de client\n");
		printf("0) Retour au menu principal\n");
		scanf("%d",&choix);
		system("cls");
     	switch(choix)
      	{
       		case 0  : break;
       		case 1  : afficherClientsA(sourceA,tailleSourceA);
       				  break;
       		case 2  : afficherClientsA(trinumA,tailleSourceA);
       		          break;
			case 3  : afficherClientsA(trinomA,tailleSourceA);
			          break;
       		default :
            	printf("choix incorrect !\n");
            	system("pause");
            	system("cls");
            		break;
        }
	}
}

void rechercheClientsCommuns(struct clientA *trinomA,int *tailleSourceA,struct clientB *sourceB,int *tailleSourceB,struct clientB *clients_communs,int *tailleClientsCommuns)
/*Cette fonction permet de rechercher les clients communs entre la banque A et la banque B
Les clients communs sont ceux qui ont les mêmes nom, prénom et date de naissance
*/
{
	int i,j,trouve;
	*tailleClientsCommuns = 0;
	for (i=0;i<*tailleSourceB;i++)
	{
		j=0;
		trouve=0;
		while ((trouve==0) && (j < *tailleSourceA))
		{
			if (stringcomp(sourceB[i].nom,trinomA[j].nom)==0) //On cherche d'abord sur le nom (attribut principal) afin de na pas tester sur tous les critères à chaque fois
			{
				if ((stringcomp(sourceB[i].prenom,trinomA[j].prenom)==0) && (stringcomp(sourceB[i].datenaiss,trinomA[j].datenaiss)==0))
				{
					structclientBcopy (sourceB[i],&clients_communs[*tailleClientsCommuns]);
					*tailleClientsCommuns=*tailleClientsCommuns+1;
					trouve=1;					
				}
			}
			j++;
		} 
		
	}
}

void test_verifnom()
{
	int erreur = 0;
	//valeur correcte
	if (verifnom("AAAAA") != 1)
	{
		printf("Erreur de fonctionnement avec la valeur AAAAA\n");
		erreur = 1;
	}
	//valeur nulle
	if (verifnom("") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur nulle\n");
		erreur = 1;
	}
	//valeur commencant par un espace
	if (verifnom(" AAAAA") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur commencant par un espace\n");
		erreur = 1;
	}
	//valeur trop longue
	if (verifnom("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur de 31 caractères\n");
		erreur = 1;
	}
	//valeur contenant des caractères non autorisés
	if (verifnom("aaAAAAAAAAAAAAAAAA") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur autre que les caractères autorisés\n");
		erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");	
}

void test_verifprenom()
{
	int erreur = 0;
	//valeur correcte
	if (verifprenom("AA-A AA") != 1)
	{
		printf("Erreur de fonctionnement avec la valeur AA-A AA\n");
		erreur = 1;
	}
	//valeur nulle
	if (verifprenom("") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur nulle\n");
		erreur = 1;
	}
	//valeur commencant par un espace
	if (verifprenom(" AAAAA") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur commencant par un espace\n");
		erreur = 1;
	}
	//valeur commencant par un tiret
	if (verifprenom("-AAAAA") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur commencant par un tiret\n");
		erreur = 1;
	}
	//valeur trop longue
	if (verifprenom("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur de 31 caractères\n");
		erreur = 1;
	}
	//valeur contenant des caractères non autorisés
	if (verifprenom("aaAAAAAAAAAAAAAAAA") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur autre que les caractères autorisés\n");
		erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");	
}

void test_verifdatenaiss()
{
	int erreur = 0;
	//valeur correcte
	if (verifdatenaiss("29/01/1988") != 1)
	{
		printf("Erreur de fonctionnement avec 29/01/1988\n");
		erreur = 1;
	}
	//valeur correcte au 19/02 année bisextile
	if (verifdatenaiss("29/02/1988") != 1)
	{
		printf("Erreur de fonctionnement 29/02/1988 (ann%ce bisextile)\n");
		erreur = 1;
	}
	//valeur nulle
	if (verifdatenaiss("") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur nulle\n");
		erreur = 1;
	}
	//valeur incorecte nbr de jours
	if (verifdatenaiss("31/04/1988") != 0)
	{
		printf("Erreur de fonctionnement 31/04/1988\n");
		erreur = 1;
	}
	//valeur incorecte nbr de jours
	if (verifdatenaiss("32/12/1988") != 0)
	{
		printf("Erreur de fonctionnement 32/12/1988\n");
		erreur = 1;
	}
	//valeur incorecte nbr de jours
	if (verifdatenaiss("00/12/1988") != 0)
	{
		printf("Erreur de fonctionnement 00/12/1988\n");
		erreur = 1;
	}
	//valeur incorecte nbr de mois
	if (verifdatenaiss("31/13/1988") != 0)
	{
		printf("Erreur de fonctionnement 31/13/1988\n");
		erreur = 1;
	}
	//valeur incorecte nbr de mois
	if (verifdatenaiss("31/00/1988") != 0)
	{
		printf("Erreur de fonctionnement 31/00/1988\n");
		erreur = 1;
	}
	//valeur incorecte année
	if (verifdatenaiss("31/03/88") != 0)
	{
		printf("Erreur de fonctionnement 31/03/88\n");
		erreur = 1;
	}
	//date avant 1905
	if (verifdatenaiss("30/12/1904") != 0)
	{
		printf("Erreur de fonctionnement 30/12/1904\n");
		erreur = 1;
	}
	//date après 1996
	if (verifdatenaiss("01/01/1997") != 0)
	{
		printf("Erreur de fonctionnement 01/01/1997\n");
		erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

void test_verifnumcompte()
{
	int erreur = 0;
	//valeur correcte
	if (verifnumcompte("BE45 1254 1254 1254") != 1)
	{
		printf("Erreur de fonctionnement avec BE45 1254 1254 1254\n");
		erreur = 1;
	}
	//un tiret en trop
	if (verifnumcompte("BE45-1254 1254 1254") != 0)
	{
		printf("Erreur de fonctionnement avec BE45-1254 1254 1254\n");
		erreur = 1;
	}
	//FR au lieu de BE
	if (verifnumcompte("FR45 1254 1254 1254") != 0)
	{
		printf("Erreur de fonctionnement avec FR45-1254 1254 1254\n");
		erreur = 1;
	}
	//trop long
	if (verifnumcompte("BE45 1254 1254 12544") != 0)
	{
		printf("Erreur de fonctionnement avec BE45 1254 1254 12544\n");
		erreur = 1;
	}
	//valeur nulle
	if (verifnumcompte("") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur nulle\n");
		erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");

}

void test_verifnumregnat()
{
	int erreur = 0;
	//valeur correcte
	if (verifnumregnat("760713-123-10") != 1)
	{
		printf("Erreur de fonctionnement avec 760713-123-10\n");
		erreur = 1;
	}
	//manque un tiret
	if (verifnumregnat("760713 123-10") != 0)
	{
		printf("Erreur de fonctionnement avec 760713 123-10\n");
		erreur = 1;
	}
	//caractère incorrect
	if (verifnumregnat("A60713-123-10") != 0)
	{
		printf("Erreur de fonctionnement avec 760713 123-10\n");
		erreur = 1;
	}
	//trop long
	if (verifnumregnat("760713-123-102") != 0)
	{
		printf("Erreur de fonctionnement avec 760713-123-102\n");
		erreur = 1;
	}
	if (verifnumregnat("") != 0)
	{
		printf("Erreur de fonctionnement avec une valeur nulle\n");
		erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");

}

void test_compatibildatenaissregnat()
{
	int erreur = 0;
	//valeurs correctes
	if (compatibildatenaissregnat("31/07/1976","760731-123-10") != 1)
	{
		printf("Erreur de fonctionnement avec 31/07/1976 760731-123-10\n");
		erreur = 1;
	}
	//dates qui ne correspondent pas
	if (compatibildatenaissregnat("31/07/1976","760720-123-10") != 0)
	{
		printf("Erreur de fonctionnement avec 31/07/1976 760720-123-10\n");
		erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

void test_structclientAcopy()
{
	struct clientA source, destination;
	source.numero=1;
	stringcopy("NOMTEST",source.nom);
	stringcopy("PRENOMTEST",source.prenom);
	stringcopy("31/07/1976",source.datenaiss);
	stringcopy("760731-123-10",source.num_reg_nat);
	stringcopy("BE45 1224 4555 4785",source.num_compte);
	structclientAcopy (source,&destination);
	if ((source.numero==destination.numero) && !stringcomp(source.nom,destination.nom) && !stringcomp(source.prenom,destination.prenom) && !stringcomp(source.datenaiss,destination.datenaiss) && !stringcomp(source.num_reg_nat,destination.num_reg_nat) && !stringcomp(source.num_compte,destination.num_compte))
		printf("Test r%cussi!\n",130);
	else
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	system("pause");
}

void donneesTestsBanqueA(struct clientA *donneesTest,int *tailleDonneesTest)
{
	donneesTest[0].numero=3;
	stringcopy("NOMTEST3",donneesTest[0].nom);
	stringcopy("PRENOMTEST3",donneesTest[0].prenom);
	stringcopy("30/09/1976",donneesTest[0].datenaiss);
	stringcopy("760930-123-10",donneesTest[0].num_reg_nat);
	stringcopy("BE45 1324 4555 4785",donneesTest[0].num_compte);
	donneesTest[1].numero=2;
	stringcopy("NOMTEST2",donneesTest[1].nom);
	stringcopy("PRENOMTEST2",donneesTest[1].prenom);
	stringcopy("30/10/1979",donneesTest[1].datenaiss);
	stringcopy("791030-123-10",donneesTest[1].num_reg_nat);
	stringcopy("BE45 4524 4555 4785",donneesTest[1].num_compte);
	donneesTest[2].numero=4;
	stringcopy("NOMTEST4",donneesTest[2].nom);
	stringcopy("PRENOMTEST4",donneesTest[2].prenom);
	stringcopy("30/06/1975",donneesTest[2].datenaiss);
	stringcopy("750630-123-10",donneesTest[2].num_reg_nat);
	stringcopy("BE45 4524 4855 4785",donneesTest[2].num_compte);
	donneesTest[3].numero=1;
	stringcopy("NOMTEST1",donneesTest[3].nom);
	stringcopy("PRENOMTEST1",donneesTest[3].prenom);
	stringcopy("30/11/1982",donneesTest[3].datenaiss);
	stringcopy("821130-123-10",donneesTest[3].num_reg_nat);
	stringcopy("BE78 4524 4555 4785",donneesTest[3].num_compte);
	*tailleDonneesTest=4;
}

void test_trinum()
{
	struct clientA donneesTest[M];
	struct clientA donneesTriees[M];
	int tailleDonneesTest = M;
	int i;
	int erreur = 0;
	donneesTestsBanqueA(donneesTest,&tailleDonneesTest);
	trinum(donneesTest,tailleDonneesTest);
	for (i=0;i<tailleDonneesTest-1;i++)
	{
		if (donneesTest[i].numero > donneesTest[i+1].numero )
			erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

void test_trinom()
{
	struct clientA donneesTest[M];
	struct clientA donneesTriees[M];
	int tailleDonneesTest = M;
	int i;
	int erreur = 0;
	donneesTestsBanqueA(donneesTest,&tailleDonneesTest);
	trinom(donneesTest,tailleDonneesTest);
	for (i=0;i<tailleDonneesTest-1;i++)
	{
		if (stringcomp(donneesTest[i].nom,donneesTest[i+1].nom) < 0)
			erreur = 1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

test_fichiersBanqueA()
{
	struct clientA donneesTest[M];
	int tailleDonneesTest;
	struct clientA donneesFichier[M];
	int tailleDonneesFichier;
	int i;
	int erreur = 0;
	donneesTestsBanqueA(donneesTest,&tailleDonneesTest);
	ecritureFichierClientsA("donneesTestA.dat",donneesTest,&tailleDonneesTest);
	lectureFichierClientsA("donneesTestA.dat",donneesFichier,&tailleDonneesFichier);
	if (tailleDonneesTest == tailleDonneesFichier)
	{
		for (i=0;i<tailleDonneesTest;i++)
		{
			if ((donneesTest[i].numero!=donneesFichier[i].numero) || stringcomp(donneesTest[i].nom,donneesFichier[i].nom) || stringcomp(donneesTest[i].prenom,donneesFichier[i].prenom) || stringcomp(donneesTest[i].datenaiss,donneesFichier[i].datenaiss) || stringcomp(donneesTest[i].num_reg_nat,donneesFichier[i].num_reg_nat) || stringcomp(donneesTest[i].num_compte,donneesFichier[i].num_compte))
			{
				printf("Donnees du fichier != des donnees de test");
				erreur=1;
			}
		}
	} 
	else
	{
		printf("Taille des donnees de test != de la taille des donnees du fichier");
		erreur=1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

void test_structclientBcopy()
{
	struct clientB source, destination;
	stringcopy("NOMTEST",source.nom);
	stringcopy("PRENOMTEST",source.prenom);
	stringcopy("31/07/1976",source.datenaiss);
	structclientBcopy (source,&destination);
	if (!stringcomp(source.nom,destination.nom) && !stringcomp(source.prenom,destination.prenom) && !stringcomp(source.datenaiss,destination.datenaiss))
		printf("Test r%cussi!\n",130);
	else
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	system("pause");
}

void donneesTestsBanqueB(struct clientB *donneesTest,int *tailleDonneesTest)
{
	stringcopy("NOMTEST3",donneesTest[0].nom);
	stringcopy("PRENOMTEST3",donneesTest[0].prenom);
	stringcopy("30/09/1976",donneesTest[0].datenaiss);
	stringcopy("NOMTEST2",donneesTest[1].nom);
	stringcopy("PRENOMTEST2",donneesTest[1].prenom);
	stringcopy("30/10/1979",donneesTest[1].datenaiss);
	stringcopy("NOMTEST5",donneesTest[2].nom);
	stringcopy("PRENOMTEST5",donneesTest[2].prenom);
	stringcopy("30/08/1985",donneesTest[2].datenaiss);
	stringcopy("NOMTEST1",donneesTest[3].nom);
	stringcopy("PRENOMTEST1",donneesTest[3].prenom);
	stringcopy("30/11/1982",donneesTest[3].datenaiss);
	*tailleDonneesTest=4;
}

void donneesTestsCientsCommuns(struct clientB *donneesTest,int *tailleDonneesTest)
{
	stringcopy("NOMTEST3",donneesTest[0].nom);
	stringcopy("PRENOMTEST3",donneesTest[0].prenom);
	stringcopy("30/09/1976",donneesTest[0].datenaiss);
	stringcopy("NOMTEST2",donneesTest[1].nom);
	stringcopy("PRENOMTEST2",donneesTest[1].prenom);
	stringcopy("30/10/1979",donneesTest[1].datenaiss);
	stringcopy("NOMTEST1",donneesTest[2].nom);
	stringcopy("PRENOMTEST1",donneesTest[2].prenom);
	stringcopy("30/11/1982",donneesTest[2].datenaiss);
	*tailleDonneesTest=3;
}

test_fichiersBanqueB()
{
	struct clientB donneesTest[P];
	int tailleDonneesTest;
	struct clientB donneesFichier[P];
	int tailleDonneesFichier;
	int i;
	int erreur = 0;
	donneesTestsBanqueB(donneesTest,&tailleDonneesTest);
	ecritureFichierClientsB("donneesTestB.dat",donneesTest,&tailleDonneesTest);
	lectureFichierClientsB("donneesTestB.dat",donneesFichier,&tailleDonneesFichier);
	if (tailleDonneesTest == tailleDonneesFichier)
	{
		for (i=0;i<tailleDonneesTest;i++)
		{
			if (stringcomp(donneesTest[i].nom,donneesFichier[i].nom) || stringcomp(donneesTest[i].prenom,donneesFichier[i].prenom) || stringcomp(donneesTest[i].datenaiss,donneesFichier[i].datenaiss))
			{
				printf("Donnees du fichier != des donnees de test");
				erreur=1;
			}
		}
	} 
	else
	{
		printf("Taille des donnees de test != de la taille des donnees du fichier");
		erreur=1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

void test_rechercheClientsCommuns()
{
	struct clientA donneesTestA[M];
	int tailleDonneesTestA;
	struct clientB donneesTestB[P];
	int tailleDonneesTestB;
	struct clientB donneesTestsCommuns[P];
	int tailleDonneesTestsCommuns;
	struct clientB clientsCommuns[P];
	int tailleClientsCommuns;
	int erreur=0;
	int i;
	donneesTestsBanqueA(donneesTestA,&tailleDonneesTestA);
	donneesTestsBanqueB(donneesTestB,&tailleDonneesTestB);
	donneesTestsCientsCommuns(donneesTestsCommuns,&tailleDonneesTestsCommuns);
	trinom(donneesTestA,tailleDonneesTestA);
	rechercheClientsCommuns(donneesTestA,&tailleDonneesTestA,donneesTestB,&tailleDonneesTestB,clientsCommuns,&tailleClientsCommuns);
	if (tailleClientsCommuns == tailleDonneesTestsCommuns)
	{
		for (i=0;i<tailleDonneesTestsCommuns;i++)
		{
			if (stringcomp(donneesTestsCommuns[i].nom,clientsCommuns[i].nom) || stringcomp(donneesTestsCommuns[i].prenom,clientsCommuns[i].prenom) || stringcomp(donneesTestsCommuns[i].datenaiss,clientsCommuns[i].datenaiss))
			{
				erreur=1;
			}
		}
	} 
	else
	{
		printf("Taille des donnees de test != de la taille des donnees de la fonction");
		erreur=1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

void test_fichiersClientsCommuns()
{
	struct clientB donneesTest[P];
	int tailleDonneesTest;
	struct clientB donneesFichier[P];
	int tailleDonneesFichier;
	int i;
	int erreur = 0;
	donneesTestsCientsCommuns(donneesTest,&tailleDonneesTest);
	ecritureFichierClientsB("donneesTestClientsCommuns.dat",donneesTest,&tailleDonneesTest);
	lectureFichierClientsB("donneesTestClientsCommuns.dat",donneesFichier,&tailleDonneesFichier);
	if (tailleDonneesTest == tailleDonneesFichier)
	{
		for (i=0;i<tailleDonneesTest;i++)
		{
			if (stringcomp(donneesTest[i].nom,donneesFichier[i].nom) || stringcomp(donneesTest[i].prenom,donneesFichier[i].prenom) || stringcomp(donneesTest[i].datenaiss,donneesFichier[i].datenaiss))
			{
				printf("Donnees du fichier != des donnees de test");
				erreur=1;
			}
		}
	} 
	else
	{
		printf("Taille des donnees de test != de la taille des donnees du fichier");
		erreur=1;
	}
	if (erreur != 0)
		printf("ATTENTION: Le test a %cchou%c!\n",130,130);
	else
		printf("Le test a r%cussi!\n",130);
	system("pause");
}

void autresTests()
{
    int choix=-1;
    while(choix!=0)
    {
		system("cls");
    	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("XX                                  XX\n");
		printf("XX       Autres tests               XX\n");
		printf("XX                                  XX\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
    	printf("1) Ecriture et lecture fichiers banqueA\n");
    	printf("2) structclientBcopy\n");
    	printf("3) Ecriture et lecture fichier banqueB\n");
    	printf("4) rechercheClientsCommuns\n");
    	printf("5) Ecriture et lecture fichier clients communs\n");
    	printf("0) Retour au menu\n");
      	printf("Votre choix : ");
      	scanf("%d",&choix);
      	system("cls");
      	switch(choix)
      	{
       	case 0 : break;
       	case 1 : test_fichiersBanqueA();
       			 break;
       	case 2 : test_structclientBcopy();
       			 break;
       	case 3 : test_fichiersBanqueB();
       			 break;
       	case 4 : test_rechercheClientsCommuns();
       			 break;
       	case 5 : test_fichiersClientsCommuns();
       			 break;
       default :
            printf("choix incorrect !\n");
            system("pause");
            system("cls");
            break;
      }
     }
}



void tests()
{
    int choix=-1;
    while(choix!=0)
    {
		system("cls");
    	printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
		printf("XX                                  XX\n");
		printf("XX              Tests               XX\n");
		printf("XX                                  XX\n");
		printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
    	printf("1) verifnom\n");
    	printf("2) verifprenom\n");
    	printf("3) verifdatenaiss\n");
    	printf("4) verifnumcompte\n");
    	printf("5) verifnumregnat\n");
    	printf("6) compatibldatenaissregnat\n");
    	printf("7) structclientAcopy\n");
    	printf("8) trinum\n");
    	printf("9) trinom\n");
    	printf("10) autresTests\n");
    	printf("0) Retour au menu\n");
      	printf("Votre choix : ");
      	scanf("%d",&choix);
      	system("cls");
      	switch(choix)
      	{
       	case 0 : break;
       	case 1 : test_verifnom();
       			 break;
       	case 2 : test_verifprenom();
       			 break;
       	case 3 : test_verifdatenaiss();
       			 break;
       	case 4 : test_verifnumcompte();
       			 break;
       	case 5 : test_verifnumregnat();
       			 break;
       	case 6 : test_compatibildatenaissregnat();
       			 break;
       	case 7 : test_structclientAcopy();
       			 break;
       	case 8 : test_trinum();
       			 break;
       	case 9 : test_trinom();
       			 break;
       	case 10: autresTests();
       			 break;
       default :
            printf("choix incorrect !\n");
            system("pause");
            system("cls");
            break;
      }
     }
}

main()
{
struct clientA sourceA[M];
struct clientA trinumA[M];
struct clientA trinomA[M];
int tailleSourceA;
int tailleSourceB;
int tailleClientsCommuns;
struct clientB sourceB[P];
struct clientB clients_communs[P];

int choix=-1;
     while(choix!=0)
     {
      system("cls");
      printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n");
	  printf("XX                                  XX\n");
	  printf("XX            Bienvenue             XX\n");
	  printf("XX                                  XX\n");
	  printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n");
      printf("1)  Encoder les clients banque A\n");
      printf("2)  Encoder les clients banque B\n");
      printf("3)  Affichage les clients banque A\n");
      printf("4)  Affichage les clients banque B\n");
      printf("5)  Ecrire les fichiers banque A\n");
      printf("6)  Ecrire le fichier banque B\n");
      printf("7)  Lire les fichiers banque A\n");
      printf("8)  Lire le fichier banque B\n");
      printf("9)  Recherche des clients communs\n");
      printf("10) Affichage des clients communs\n");
      printf("11) Ecrire le fichier des clients communs\n");
      printf("12) Lire le fichier des clients communs\n");
      printf("13) Test des fonctions\n");
      printf("0)  Quitter\n");
      printf("Votre choix : ");
      scanf("%d",&choix);
      system("cls");
      switch(choix)
      {
       case 0 : break;
       case 1 :
                banqueA(sourceA,trinomA,trinumA,&tailleSourceA);
                break;
       case 2 :
                banqueB(sourceB,&tailleSourceB);
                break;
       case 3 : sousmenuAffichageBanqueA(sourceA,trinomA,trinumA,&tailleSourceA);
       			break;
       case 4 : afficherClientsB(sourceB,&tailleSourceB);
       			break;
       case 5 : ecritureFichierClientsA("sourceA.dat",sourceA,&tailleSourceA);
           		ecritureFichierClientsA("trinomA.dat",trinomA,&tailleSourceA);
           		ecritureFichierClientsA("trinumA.dat",trinumA,&tailleSourceA);
           		break;
       case 6 : ecritureFichierClientsB("sourceB.dat",sourceB,&tailleSourceB);
       	    	break;
       case 7 : lectureFichierClientsA("sourceA.dat",sourceA,&tailleSourceA);
           		lectureFichierClientsA("trinomA.dat",trinomA,&tailleSourceA);
           		lectureFichierClientsA("trinumA.dat",trinumA,&tailleSourceA);
           		break;
       case 8 : lectureFichierClientsB("sourceB.dat",sourceB,&tailleSourceB);
       	    	break;
       case 9 : rechercheClientsCommuns(trinomA,&tailleSourceA,sourceB,&tailleSourceB,clients_communs,&tailleClientsCommuns);
	   			break;
       case 10: afficherClientsB(clients_communs,&tailleClientsCommuns);
	   			break;
       case 11: ecritureFichierClientsB("clients_communs.dat",clients_communs,&tailleClientsCommuns);
	   			break;
       case 12: lectureFichierClientsB("clients_communs.dat",clients_communs,&tailleClientsCommuns);
	   			break;
	   case 13: tests();
       			break;
       default :
            printf("choix incorrect !\n");
            system("pause");
            system("cls");
            break;
      }
     }
}
