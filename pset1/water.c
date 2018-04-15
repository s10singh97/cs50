#include<cs50.h>
#include<stdio.h>

void convert(void);

int main(void)
{
    convert();
}

void convert(void)
{
    printf("Minutes : ");
    int min = get_int();
    printf("Bottles : %i\n", min*12);
}
