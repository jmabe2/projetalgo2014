int verifstrformat (char* format, char* chaine)
{
	int i, res;
	res = 1;
	if (strlen(format) == strlen(chaine))
	{
		for (i=0;i<strlen(chaine);i++)
		{
			switch(format[i])
			{
				case '#' : if ((chaine[i] < 48) || (chaine[i] > 57))
				           {
							   res=0;
						   }
						   break;
			    default : if (chaine[i] != format[i])
			               {
							   res=0;
						   }
			}
		}
    }
    else
    {
		res=0;
    }
    return res;
}


int verifnumregnat (char* chaine)
{
	return verifstrformat("######-###-##", chaine);
} 

int verifnumcompte (char* chaine)
{
	return verifstrformat("BE## #### #### ####", chaine);
} 
