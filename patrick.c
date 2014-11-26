#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// 1 = erreur
// 0= ok


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
			
			}
			
	if (chaine[i]<65 && chaine[i]!=32|| chaine[i]>90 )
		{
		
		j=1;
		break	;
		}
		
	
	i++;		
}
	

return printf("%d",j);
}



int main() {
	
    char chaine [100];
	printf("veuillez inserez votre nom en majuscule:\n");
	gets(chaine);
	
	verifnom(chaine);
	
	return 0;

system ("pause");
}
