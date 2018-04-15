#include<cs50.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void input(void);
void process(void);
void output(void);

float n;
int sum = 0;

int main(void)
{
    input();
    process();
    output();
}

void input(void)
{
    printf("O hai! ");
    label : printf("How much change is owed?\n");
    n = get_float();
    if(n < 0)
    goto label;
}

void process(void)
{
    int d;
    d = (int)round(n * 100);
    while(d != 0)
    {
        if(d >= 25)
        {
            sum = (d / 25);
            d = d % 25;
        }
        else if((d >= 10) && (d < 25))
        {
            sum += (d / 10);
            d = d % 10;
        }
        else if((d >= 5) && (d < 10))
        {
            sum += (d / 5);
            d = d % 5;
        }
        else
        {
            sum += d;
            d = d % 1;
        }
    }
}

void output(void)
{
    printf("%i\n", sum);
}