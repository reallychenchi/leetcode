#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int matchw(char *s, int strl, char **words, int wordl)
{
	if (0 == wordl || strl < wordl * strlen(words[0]))
		return 1;
	char *tmpw[wordl];
	char *cmpw[wordl];
	char *b = s;
	for (int i = 0; i < wordl; ++i)
	{
		cmpw[i] = b;
		b = b + strlen(words[0]);
	}
	char *start = s;
	char *end = b;
	int bfound = wordl;
	memcpy(tmpw, words, wordl * sizeof(char *));
	for (int j = 0; j < wordl; ++j)
	{
		b = cmpw[j];
		int found = 0;
		for (int i = 0; i < wordl; ++i)
		{
			if (tmpw[i] == 0)
			{
				continue;
			}
			else if (memcmp(tmpw[i], b, strlen(tmpw[i])) == 0)
			{
				printf("MATCH %d, %d, %s %s\n", j, i, tmpw[i], b);
				tmpw[i] = 0;
				found = 1;
				bfound--;
				break;
			}
		}

		if (found == 0)
			return 1;
	}
	if (bfound == 0)
	{
		printf("FOUND %s\n", start);
		return 0;
	}
	else
	{
		return 1;
	}
}

int *findSubstring(char *s, char **words, int wordl, int *returnSize)
{
	int strl = strlen(s);
	*returnSize = 0;
	int *ret = malloc(sizeof(int) * strl);
	for (int i = 0; i < strl && i != -1;)
	{
		int r = matchw(s + i, strl - i, words, wordl);
		if (r != 1)
		{
			ret[*returnSize] = i;
			*returnSize = *returnSize + 1;
		}
		i += 1;
	}
	return ret;
}

int main()
{
	int rSz = 0;

	char *data[3] = {"word", "ertt", "uopu"};
	char *str = malloc(80 * sizeof(char));
	memset(str, 'a', 80 * sizeof(char));
	str[79] = 0;

	memcpy(str + 5, data[0], 4);
	memcpy(str + 9, data[1], 4);
	memcpy(str + 13, data[2], 4);
	memcpy(str + 29, data[2], 4);
	memcpy(str + 33, data[0], 4);
	memcpy(str + 37, data[1], 4);
	memcpy(str + 50, data[0], 4);

	int *r = findSubstring(str, data, 3, &rSz);
	printf("A FOUND %d\n ", rSz);
	for (int i = 0; i < rSz; ++i)
	{
		printf("FOUND %d, ", r[i]);
	}
	printf("\n\n\n");

	str = "wordgoodgoodgoodbestword";
	char *data2[4] = {"word", "good", "best", "word"};
	r = findSubstring(str, data2, 4, &rSz);
	printf("A FOUND %d\n ", rSz);
	for (int i = 0; i < rSz; ++i)
	{
		printf("FOUND %d, ", r[i]);
	}
	printf("\n\n\n");

	str = "barfoofoobarthefoobarman";
	char *data3[3] = {"bar","foo","the"};
	r = findSubstring(str, data3, 3, &rSz);
	printf("A FOUND %d\n ", rSz);
	for (int i = 0; i < rSz; ++i)
	{
		printf("FOUND %d, ", r[i]);
	}
	printf("\n\n\n");


	str = "a";
	char *data4[0] = {};
	r = findSubstring(str, data4, 0, &rSz);
	printf("A FOUND %d\n ", rSz);
	for (int i = 0; i < rSz; ++i)
	{
		printf("FOUND %d, ", r[i]);
	}
	printf("\n\n\n");
}
