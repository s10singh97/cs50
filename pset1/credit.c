#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>

void input(void);
void process(void);
void output(void);
long long n, s;
int f1 = 0, f2 = 0, f3 = 0, f5 =0, f6 = 0, f7 = 0;
int a[16], b[16], c[16], d[16];

int main(void)
{
    input();
    process();
    output();
}

void input(void)
{
    printf("Number : ");
    n = get_long_long();
}

void process(void)
{
    s = n;
    int i,j;
    
    for(i = 0; i < 16; i++)
    {
        int e = s % 10;
        a[i] = e;
        s = s / 10;
    }
        
    for(i = 0, j = 15; i < 16; i++, j--)
    {
        b[i] = a[j];
    }

    //Check
    int len=0;
    for(i = 0; i < 16;)
    {
        if(b[i] == 0)
            i++;
        else
        break;
    }
    for(j = i; j < 16; j++)
    {
        len++ ;
    }
    if(len == 13)
    goto l1;
    else if(len == 15)
    goto l1;
    else if(len == 16)
    goto l1;
    else
    {
        printf("INVALID\n");
        exit(0);
    }

l1 : if(b[0] == 0)
    {
        for(i = 0, j = 1; i < 16; i++, j++)
        {                                       //Final Array for 15 element
            if(i == 15)
            c[i] = 0;
            else
            c[i] = b[j];
            f5 = 1;
        }
        if((b[1] == 0) && (b[2] == 0))
        {
            for(i = 0, j = 3; i < 16; i++, j++)
            {
                if(i == 13)
                c[i] = 0;
                else if(i == 14)
                c[i] = 0;
                else if(i == 15)
                c[i] = 0;
                else
                c[i] = b[j];                                   //Final Array for 13 element
                f6 = 1;
            }
        }
    }
    if((f5 == 0) && (f6 == 0))
    {
        for(i = 0; i < 16; i++)
        {
            c[i] = b[i];                                   //Final Array for 16 element
        }
    }

    //Algorithm
    if(c[0] == 5)             //mastercard 16 digit
    {
        if((c[1] == 1) || (c[1] == 2) || (c[1] == 3) || (c[1] == 4) || (c[1] == 5))
        {
            f1 = 1;
        }
    }
    if(c[0] == 4)              //visa 16/13 digit
    {
        f2 = 1;
    }
    if(c[0] == 3)              //american express 15 digit
    {
        if((c[1] == 4) || (c[1] == 7))
        {
            f3 = 1;
        }
    }
    
    int sum1 = 0;                                              //Checksum
    for(i = 1, j = 0; i < 16; (i +=2), j++)
    {
        d[j] = c[i] * 2;
        if(d[j] > 9)
        {
            while(d[j] != 0)
            {
                int e = d[j] % 10;
                sum1 += e;
                d[j] = d[j] / 10;
            }
        }
        else
        sum1 += d[j];
        sum1 += c[i - 1];
    }

    if((sum1 % 10) == 0)
    {
        f7 = 1;
    }
}

void output(void)
{
    if(f7 == 1)
    {
        if(f3 == 1)
        printf("AMEX\n");
        if(f1 == 1)
        printf("MASTERCARD\n");
        if(f2 == 1)
        printf("VISA\n");
    }
    else
    printf("INVALID\n");
}