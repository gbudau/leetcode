#include <stdlib.h>
#include <string.h>
#define MAX_WORDS 31
#define MAX_WORD_LEN 12

typedef struct	s_translation
{
	int		n;
	char	word[MAX_WORD_LEN];
}				t_translation;

size_t	copy_string(char *dst, const char *src, size_t n)
{
	size_t	i = 0;
	while (src[i] && i < n - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (i);
}

void	init_value(t_translation *t, int n, char *word)
{
	t->n = n;
	copy_string(t->word, word, MAX_WORD_LEN);
}

void	init_translation_array(t_translation *t)
{
	init_value(&t[0], 1000000000, "Billion ");
	init_value(&t[1], 1000000, "Million ");
	init_value(&t[2], 1000, "Thousand ");
	init_value(&t[3], 100, "Hundred ");
	init_value(&t[4], 90, "Ninety ");
	init_value(&t[5], 80, "Eighty ");
	init_value(&t[6], 70, "Seventy ");
	init_value(&t[7], 60, "Sixty ");
	init_value(&t[8], 50, "Fifty ");
	init_value(&t[9], 40, "Forty ");
	init_value(&t[10], 30, "Thirty ");
	init_value(&t[11], 20, "Twenty ");
	init_value(&t[12], 19, "Nineteen ");
	init_value(&t[13], 18, "Eighteen ");
	init_value(&t[14], 17, "Seventeen ");
	init_value(&t[15], 16, "Sixteen ");
	init_value(&t[16], 15, "Fifteen ");
	init_value(&t[17], 14, "Fourteen ");
	init_value(&t[18], 13, "Thirteen ");
	init_value(&t[19], 12, "Twelve ");
	init_value(&t[20], 11, "Eleven ");
	init_value(&t[21], 10, "Ten ");
	init_value(&t[22], 9, "Nine ");
	init_value(&t[23], 8, "Eight ");
	init_value(&t[24], 7, "Seven ");
	init_value(&t[25], 6, "Six ");
	init_value(&t[26], 5, "Five ");
	init_value(&t[27], 4, "Four ");
	init_value(&t[28], 3, "Three ");
	init_value(&t[29], 2, "Two ");
	init_value(&t[30], 1, "One ");
}

void	fill_number_to_words(t_translation *t, int num, char **str)
{
	for (int i = 0; num; i++)
	{
		if (num >= t[i].n)
		{
			char *next = *str;
			if (t[i].n >= 100)
			{
				int rest = num % t[i].n;
				num = num / t[i].n;
				fill_number_to_words(t, num, str);
				next = *str;
				next += copy_string(next , t[i].word, MAX_WORD_LEN);
				num = rest;
			}
			else
			{
				num = num - t[i].n;
				next += copy_string(next , t[i].word, MAX_WORD_LEN);
			}
			*str = next;
		}
	}
}

char	*numberToWords(int num)
{
	t_translation t[MAX_WORDS];

	if (num < 0)
		return (NULL);
	if (num == 0)
		return (strdup("Zero"));
	char *ret = malloc(128);
	if (ret == NULL)
		return (NULL);
	init_translation_array(t);
	char *tmp = ret;
	fill_number_to_words(t, num, &tmp);
	*(tmp - 1) = '\0';
	return (ret);
}
