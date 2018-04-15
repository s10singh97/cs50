/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>
#define MAX 65536

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // Implementing Binary Search
    if(n <= 0)
        return false;
    int bg = 0, last = n - 1;
    while(bg <= last)
    {
        int mid = (bg + last) / 2;
        if(values[mid] == value)                           //Success : Found the element
            return true;
        else if(value > values[mid])                       //Ignoring left side of array
            bg = mid + 1;
        else if(value < values[mid])                       //Igmoring right side of array
            last = mid - 1;
    }
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // Implementing Counting Sort
    int i, j, max = 0;
    max = values[0];                                       //Finding Largest element in the array
    for(i = 1; i < n; i++)
    {
        if(values[i] > max)
            max = values[i];
        else
        {
            max = values[0];
            continue;
        }
    }
    int a[MAX];                                            //Dummy Array                       
    for(i = 0; i < (max + 1); i++)                         //Initialising dummy array with 0
    {
        a[i] = 0;
    }
    for(i = 0; i < n; i++)                                 //Incrementing dummy array by 1 for all those elements which are present in the main array 
    {
        j = values[i];
        a[j]++;
    }
    j = 0;
    for(i = 0; i < (max + 1); i++)                         //Determining the final position of the elements
    {
        if(a[i] != 0)
        {
            while(a[i] != 0)
            {
                values[j] = i;
                j++;
                a[i]--;
            }
            if(j == n)
                break;
        }
        else
            continue;
    }
}
