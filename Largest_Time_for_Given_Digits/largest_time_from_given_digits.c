#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

bool    all_digits(int *A, int ASize)
{
    for (int i = 0; i < ASize; i++)
        if (A[i] < 0 || A[i] > 9)
            return false;
    return true;
}

int     create_minutes(int a, int b)
{
    int first = a * 10 + b;
    int second = b * 10 + a;

    if (first > 59 && second > 59)
        return -1;
    if (first > 59)
        return second;
    if (second > 59)
        return first;
    return MAX(first, second);
}

int    get_minutes(int *A, int ASize, int idx1, int idx2)
{
    int minutes[2];

    int j = 0;

    for (int i = 0; i < ASize; i++)
    {
        if (i != idx1 && i != idx2)
            minutes[j++] = A[i];
    }
    return create_minutes(minutes[0], minutes[1]);
}

int     get_hours(int *A, int ASize, int *minutes)
{
    int test, max_hour = -1;

    for (int i = 0; i < ASize; i++)
    {
        for (int j = 0; j < ASize; j++)
        {
            if (i != j)
            {
                int number = A[i] * 10 + A[j];
                if (number < 24 && number > max_hour &&
                    (test = get_minutes(A, ASize, i, j)) != -1)
                {
                    max_hour = number;
                    *minutes = test;
                }
            }
        }
    }
    return max_hour;
}

char * largestTimeFromDigits(int* A, int ASize){
    char    *result = NULL;
    int     hours, minutes;

    if (ASize != 4 || !all_digits(A, ASize))
        return strdup("");
    if ((hours = get_hours(A, ASize, &minutes)) == -1)
        return strdup("");
    asprintf(&result, "%.2d:%.2d", hours, minutes);
    return result;
}
