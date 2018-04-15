#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>

void input(void);
void output(void);
string s;

int main(void)
{
    input();
    output();
}

void input(void)
{
    s = get_string();                           //Getting string from the user
}

void output(void)
{
    int i = 0, j = 0, c;
    if(s[0] != ' ')                             //Checking Space in the first element
    {
        printf("%c", toupper(s[0]));
        for(i = 0; i < strlen(s); i++)
        {
            if(s[i] == ' ')                     //Checking Space in between the string
            {
                j = i;
                c = 0;
                while(s[j] == ' ')
                {
                    c++;                        //Variable to count number of spaces
                    j++;
                }
                
            }
            else                                //Jumping to next iteration
                continue;
            if(s[i + c] == '\0')                //Condition to check if the string ends with a Space
                goto l1;
            printf("%c", toupper(s[i + c]));    //Printing Output
        }
        l1 : printf("\n");
    }
    else                                        //If first element is Space
    {
        for(i = 0; i < strlen(s); i = (i + c))
        {
            if(s[i] == ' ')                     //Checking Space in between the String
            {
                j = i;
                c = 0;
                while(s[j] == ' ')
                {
                    c++;                        //Variable to count number of spaces
                    j++;
                }
            }
            else                                //Jumping to next iteration
                continue;
            if(s[i + c] == '\0')                //Condition to check if the string ends with a space
                goto l2;
            printf("%c", toupper(s[i + c]));    //Printing Output
        }
        l2 : printf("\n");
    }
}