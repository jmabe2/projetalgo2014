void stringcopy (char* source, char* destination) ;

{
    int i = 0;
 
    do
    {
        destination[i] = source[i];
        i++;
    }
    while (source[i] != '\0');
 
    return ();
}

________________________________________________________________________________________
AFFICHAGE DEMARRAGE :

Dans le int :

    int choix;
    char flag=0

 Cadre(); Titre(); Sleep(2000);

    do
    {
    clrscr(); MenuGeneral();
    choix = GetChoix();

        switch (choix)
        {
            case 1 : ; 
                     retourMenu();
                     break;

            case 2 : ;
                     retourMenu();
                     break;

            case 3 : ;
                     retourMenu();
                     break;

            case 4 : ;
                     break;

            case 5 : flag='Y';
                     break;

        }
    } while (flag!='Y');
    return(0);
}







void Cadre(void)
{
    int x,y;
    y=0;
    for(x=80;x>0;x--)
    {
        gotoxy(y,x);
        printf("*");
    }
    x=wherex();
    for(y=wherey();y<26;y++)
    {
        gotoxy(x,y);
        printf("*");
    }
    y=wherey();
    for(x=wherex();x<80;x++)
    {
        gotoxy(x,y);
        printf("*");
    }
    x=wherex();
    for(y=wherey();y>0;y--)
    {
        gotoxy(x,y);
        printf("*");
    }
    return;
}




void Titre(void)
{
    int x,y;
    x=23;
    y=10;
    gotoxy(x,y); printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");y++;
    gotoxy(x,y); printf("XX                                  XX");y++;
    gotoxy(x,y); printf("XX            Bienvenue             XX");y++;
    gotoxy(x,y); printf("XX                                  XX");y++;
    gotoxy(x,y); printf("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    x=wherex(); gotoxy(x-1,y);

    return;
}




void MenuGeneral(void)
{
    int x,y;
    x=32;
    y=2;
    gotoxy(x,y); printf("XXXXXXXXXXXXXXXXXXXX");y++;
    gotoxy(x,y); printf("XX                XX");y++;
    gotoxy(x,y); printf("XX  Menu General  XX");y++;
    gotoxy(x,y); printf("XX                XX");y++;
    gotoxy(x,y); printf("XXXXXXXXXXXXXXXXXXXX");

    x=30;
    y=wherey()+5;
    gotoxy(x,y); printf("1 : à completer");y++;
    gotoxy(x,y); printf("2 : à completer");y++;
    gotoxy(x,y); printf("3 : à completer selon nbr d options");y++;
    gotoxy(x,y); printf("4 : à completer");y++;
    gotoxy(x,y); printf("5 : Quitter");

    return;
}


int GetChoix(void)
{
    int x,y;
    char a;

    x=35;
    y=wherey();
    gotoxy(x,y+3); printf("Votre choix : ");
    x=wherex(); y=wherey();
    do
    {
        gotoxy(x,y);clreol();gotoxy(x,y); scanf("%c", &a);
    } while(a<'1' || a>'5');

    return(a-'0');
}



void retourMenu(void)
{
    gotoxy(20,18);
    printf("Vous allez etre redirige vers le menu principal");
    Sleep(8000);
    return;
}
________________________________________________________________________________________________________________




void afficherClientB(struct clientB *source)
{
int x=0;
     
 for(x=0;x<80);x++)
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





void AfficherClientsB()
{
 int x=0;
 printf("Liste des clients de la banque B\n");
 
 for(x=1;x<tailleSourceB;x++)
 {
 printf("Informations sur le client numero %d)\n",x);
 AfficherClientB(&sourceB[x]);
 }
}

______________________________________________________________________
attention nom des tableaux 

void AfficherClientsA(char *nomtableau)
{
int x=0;

printf("Liste des client de la banque A\n");

 if(NomTableau=="")
 {
  for(x=0;x<tailleSourceA;x++)
  {
  printf("Informations sur le client %d)\n",x+1);//x+1 permet de commencer au client 1 meme si ses données correspondent au 0//
  AfficherClientA(&sourceA[x]);
  }
 }

 else if(NomTableau=="TriParNum")
 {
  for(x=0;x<tailleSourceA;x++)
  {
  printf("Informations sur le client %d)\n",x+1);
  AfficherClientA(TriParNumA[x]);
  }
 }

 else if(NomTableau=="TriParNom")
 {
  for(x=0;x<tailleSourceA;x++)
  {
  printf("Informations sur le client %d)\n",x+1);
  AfficherClientA(TriParNomA[x]);
  }
 }
 
}






