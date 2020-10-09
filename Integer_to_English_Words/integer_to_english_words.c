#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_WORDS 31
#define MAX_WORD_LEN 10

typedef struct	s_dict
{
	int		n;
	char	word[MAX_WORD_LEN];
}				t_dict;



void	init_value(t_dict *dict, int n, char *word)
{
	dict->n = n;
	strncpy(dict->word, word, MAX_WORD_LEN);
}

void	init_dict(t_dict *eng_nrs)
{
	init_value(&eng_nrs[0], 1000000000, "Billion");
	init_value(&eng_nrs[1], 1000000, "Million");
	init_value(&eng_nrs[2], 1000, "Thousand");
	init_value(&eng_nrs[3], 100, "Hundred");
	init_value(&eng_nrs[4], 90, "Ninety");
	init_value(&eng_nrs[5], 80, "Eighty");
	init_value(&eng_nrs[6], 70, "Seventy");
	init_value(&eng_nrs[7], 60, "Sixty");
	init_value(&eng_nrs[8], 50, "Fifty");
	init_value(&eng_nrs[9], 40, "Forty");
	init_value(&eng_nrs[10], 30, "Thirty");
	init_value(&eng_nrs[11], 20, "Twenty");
	init_value(&eng_nrs[12], 19, "Nineteen");
	init_value(&eng_nrs[13], 18, "Eighteen");
	init_value(&eng_nrs[14], 17, "Seventeen");
	init_value(&eng_nrs[15], 16, "Sixteen");
	init_value(&eng_nrs[16], 15, "Fifteen");
	init_value(&eng_nrs[17], 14, "Fourteen");
	init_value(&eng_nrs[18], 13, "Thirteen");
	init_value(&eng_nrs[19], 12, "Twelve");
	init_value(&eng_nrs[20], 11, "Eleven");
	init_value(&eng_nrs[21], 10, "Ten");
	init_value(&eng_nrs[22], 9, "Nine");
	init_value(&eng_nrs[23], 8, "Eight");
	init_value(&eng_nrs[24], 7, "Seven");
	init_value(&eng_nrs[25], 6, "Six");
	init_value(&eng_nrs[26], 5, "Five");
	init_value(&eng_nrs[27], 4, "Four");
	init_value(&eng_nrs[28], 3, "Three");
	init_value(&eng_nrs[29], 2, "Two");
	init_value(&eng_nrs[30], 1, "One");
}

void	fill_hundreds(t_dict *eng_nrs, int num, char **ret)
{
	for (int i = 0; i < MAX_WORDS; i++)
	{
		if (num >= eng_nrs[i].n)
		{
				char *tmp = *ret;
				if (num >= 100)
				{
					int rest = num % eng_nrs[i].n;
					num = num / eng_nrs[i].n;
					fill_hundreds(eng_nrs, num, ret);
					tmp = *ret;
					tmp += sprintf(tmp, "%s ", eng_nrs[i].word);
					num = rest;
				}
				else
				{
					num = num - eng_nrs[i].n;
					tmp += sprintf(tmp, "%s ", eng_nrs[i].word);
				}
				*ret = tmp;
		}
	}
}

void	fill_number_to_words(t_dict *eng_nrs, int num, char *ret)
{
	for (int i = 0; i < MAX_WORDS; i++)
	{
		if (num >= eng_nrs[i].n)
		{
			if (eng_nrs[i].n >= 100)
			{
				int rest = num % eng_nrs[i].n;
				num = num / eng_nrs[i].n;
				fill_hundreds(eng_nrs, num, &ret);
				ret += sprintf(ret, "%s ", eng_nrs[i].word);
				num = rest;
			}
			else
			{
				fill_hundreds(eng_nrs, num, &ret);
				break;
			}
		}
	}
	*(ret - 1) = '\0';
}

char	*numberToWords(int num)
{
	t_dict eng_nrs[MAX_WORDS];

	if (num < 0)
		return (NULL);
	if (num == 0)
		return (strdup("Zero"));
	char *ret = malloc(128);
	if (ret == NULL)
		return (NULL);
	init_dict(eng_nrs);
	fill_number_to_words(eng_nrs, num, ret);
	return (ret);
}
