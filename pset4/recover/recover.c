#include<cs50.h>
#include<stdio.h>
#include<string.h>
#define MAX 512
unsigned char buffer[MAX];
char name[8];

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Usage : ./recover image\n");
        return 1;
    }
    //open input file
    FILE *inptr = fopen(argv[1], "r");
    FILE *outptr = NULL;
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 2;
    }
    int count = 0;
    //reading infile till reaching the end of file
    while(fread(buffer, 512, 1, inptr) == 1)
    {
        //check for jpeg image
        if((buffer[0] == 0xff) && (buffer[1] == 0xd8) && (buffer[2] == 0xff) && ((buffer[3] & 0xf0) == 0xe0))
        {
            //printing jpegs
            sprintf(name, "%03i.jpg", count);
            //opening output file
            outptr = fopen(name, "w");
            //writing outfile
            fwrite(buffer, 512, 1, outptr);
            count++;
        }
        else
        {
            //for the remaining data
            if(outptr != NULL)
                fwrite(buffer, 512, 1, outptr);
        }
    }
    fclose(outptr);
    fclose(inptr);
    return 0;
}