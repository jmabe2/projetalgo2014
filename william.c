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
