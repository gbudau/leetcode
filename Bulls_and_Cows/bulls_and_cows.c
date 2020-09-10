#define _GNU_SOURCE
#include <stdio.h>

char * getHint(char * secret, char * guess){
    int set[10] = {0}, bulls = 0, cows = 0;
    
    for (int i = 0; secret[i]; i++)
        if (secret[i] == guess[i])
            bulls++;
        else
            set[secret[i] - '0']++;
    for (int i = 0; guess[i]; i++)
    {
        if (guess[i] != secret[i] && set[guess[i] - '0'])
        {
            cows++;
            set[guess[i] - '0']--;
        }
    }
    char *ans;
    asprintf(&ans, "%dA%dB", bulls, cows);
    return ans;
}
