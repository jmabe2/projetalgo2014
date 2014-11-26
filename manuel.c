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
