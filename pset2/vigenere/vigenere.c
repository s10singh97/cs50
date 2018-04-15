#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int i = 0, j = 0, n = 0;
char c[70];

int main( int argc, string argv[])
{
    if (argc != 2)                                         //Checking argument count for 2
    {
        printf("Usage: %s k\n", argv[0]);
        return 1;
    }
    for(i = 0; i < strlen(argv[1]); i++)                   //If the 2nd argument has non - alphabetical elements, program will end
    {
        if(isalpha(argv[1][i]) == 0)
        {
            printf("Usage: %s k\n", argv[0]);
            return 1;
        }
    }
    printf("plaintext: ");
    string a = get_string();                               //Getting input from user
    printf("ciphertext: ");
    string b = argv[1];
    for(i = 0, j = 0; i < strlen(a); i++, j++)
    {
        if(isalpha(a[i]))
        {
            c[i] = b[j];                                   //Making 'key' string as per string 'a' to directly add them both
            if(j == (strlen(b) - 1))
                j = -1;
        }
        else
        {
            c[i] = a[i];
            j -= 1;
        }
    }
    for(i = 0, n = strlen(a); i < n; i++)
    {
        if(isalpha(a[i]))                                  //Checking if plaintext contains alphabet
        {
            if(a[i] >= 'a' && a[i] <= 'z')
            {
                a[i] = toupper(a[i]);                      //Avoiding conditions of overflow in signed char
                c[i] = toupper(c[i]);
                a[i] = a[i] + c[i] - 65;                   //Shifting plaintext by desired amount
                if(a[i] > 90)                              //Wrapping from Z to A
                {
                    int d = a[i] - 90;
                    a[i] = d + 65 - 1;
                }
                a[i] = tolower(a[i]);                      //Converting uppercase to lowercase, as the input was in lowercase
                printf("%c", a[i]);                        //Printing Output
            }
            if(a[i] >= 'A' && a[i] <= 'Z')
            {
                c[i] = toupper(c[i]);
                a[i] = a[i] + c[i] - 65;                   //Shifting Plaintext by desired amount
                if(a[i] > 90)                              //Wrapping from Z to A
                {
                    int d = a[i] - 90;
                    a[i] = d + 65 - 1;
                }
                printf("%c", a[i]);                        //Printing Output
            }
        }
        else
            printf("%c", a[i]);                            //Printing output as it is if the element is a non - alphabet element
    }
    printf("\n");
    return 0;
}