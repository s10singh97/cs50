#include<string.h>
#include<cs50.h>
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

int n = 0, i = 0, c = 0;
string a;

int main(int argc, string argv[])
{
    if(argc != 2)                                          //Checking argument count for 2
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }
    int k = atoi(argv[1]);                                 //Converting string argv[1] to integer
    int e = (k % 26);                                      //Obtaining Key for shifting plaintext
    printf("plaintext: ");
    a = get_string();                                      //Getting input from user
    printf("ciphertext: ");
    for(i = 0, n = strlen(a); i < n; i++)
    {
        if(isalpha(a[i]))                                  //Checking if the elemnets entered by user are alphabet
        {
            if((a[i] >= 'a') && (a[i] <= 'z'))
            {
                a[i] = toupper(a[i]);                      //To avoid the condition of overflow in signed char
                a[i] += e;                                 //Shifting plaintext by desired amount
                if(a[i] > 90)                              //Condition to wrap from Z to A
                {
                    int d = a[i] - 90;
                    a[i] = 65 + d - 1;
                }
                a[i] = tolower(a[i]);                      //Converting uppercase characters to lowercase characters
                printf("%c", a[i]);                        //Printing Output
            }
            if((a[i] >= 'A') && (a[i] <= 'Z'))
            {
                a[i] += e;                                 //Shifting plaintext by desired amount
                if(a[i] > 90)                              //Condition to wrap from Z to A
                {
                    int d = a[i] - 90;
                    a[i] = 65 + d - 1;
                }
                printf("%c", a[i]);                        //Printing Output
            }
            
        }
        else                                               //If the element is non - alphabetical
            printf("%c", a[i]);                            //Printing it as it is
    }
    printf("\n");
    return 0;
}