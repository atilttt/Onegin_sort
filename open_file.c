#include <stdio.h>
  
int main(void)
{
    
    char c;
    char * filename = "onegin.txt";
 
    FILE * fp = fopen(filename, "r");
    if(fp != NULL)
    {

        while((c=getc(fp))!= EOF)
        {
            printf("%c", c);
        }
        fclose(fp);
    }
}