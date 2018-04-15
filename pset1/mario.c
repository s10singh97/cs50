#include<cs50.h>
#include<stdio.h>

void input(void);
void output(void);
int h;

int main(void)
{
    input();
    output();
}

void input(void)
{
    label: printf("Height : ");
    h = get_int();
    if((h>23) || (h<0))
    goto label;
}

void output(void)
{
    for(int i=0; i<h; i++)
    {
        for(int j = h-i-1; j > 0; j--)
        {
            printf(" ");
        }
        for(int k = 0; k < i+1; k++)
        {
            printf("#");
        }
        printf("  ");
        for(int l = 0; l < i+1; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}