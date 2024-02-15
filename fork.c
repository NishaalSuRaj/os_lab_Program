/*
 * Program To Create Child Process using Fork System Call to
        Find The count of vowels and Consonants in a String
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
int main()
{
        int i,count=0;
        char str[200];
        char ch;
        printf("Enter the Input String : ");
        scanf("%[^\n]s",&str);
        int vowels=0,consonants=0;
        for (i = 0;str[i] != '\0';i++)
        {
                count++;

        }
        printf("\nCount = %d\n",count);
        int p = fork();
        if (p == 0)
        {

                for (i=0;i<count;i++)
                {
                        ch=str[i];
                        if (ch == 'a'|| ch == 'A'
                              || ch == 'e'|| ch=='E'
                              || ch == 'i' || ch == 'I'
                              ||  ch == 'o' || ch == 'O'
                              || ch == 'u' || ch == 'U')
                        {
                                vowels++;
                        }
                }
                printf ("\nchild process..\n");
                printf ("\nvowels = %d\n",vowels);
        }
        else if (p!=0)
        {
                 for (i = 0; i < count; i++)
                 {
                        ch=str[i];
                        if (ch != 'a' && ch != 'A'
                              && ch != 'e' && ch !='E'
                              && ch != 'i' && ch != 'I'
                              && ch != 'o' && ch != 'O'
                              && ch != 'u' && ch != 'U' &&
                              ch != ' ')
                        {
                                consonants++;

                        }
                 }
                 printf ("\nparent process..\n");
                 printf ("\nConsonants = %d\n",consonants);


        }
}
