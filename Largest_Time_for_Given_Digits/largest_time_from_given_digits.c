#define _GNU_SOURCE
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define MAX(a,b) (((a)>(b))?(a):(b))

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

int     get_hours(int *A, int ASize, int *max_minutes)
{
    int minutes, max_hour = -1;

    for (int i = 0; i < ASize; i++)
    {
        for (int j = 0; j < ASize; j++)
        {
            if (i != j)
            {
                int hour = A[i] * 10 + A[j];
                if (hour < 24 && hour > max_hour &&
                    (minutes = get_minutes(A, ASize, i, j)) != -1)
                {
                    max_hour = hour;
                    *max_minutes = minutes;
                }
            }
        }
    }
    return max_hour;
}

char * largestTimeFromDigits(int* A, int ASize){
    char    *result = NULL;
    int     hours, minutes;

    if (ASize != 4 || (hours = get_hours(A, ASize, &minutes)) == -1)
        return strdup("");
    asprintf(&result, "%.2d:%.2d", hours, minutes);
    return result;
}
