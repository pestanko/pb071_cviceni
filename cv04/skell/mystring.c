#include <stdio.h>
#include <stdlib.h>




unsigned my_strlen(const char *string)
{
	if(!string) return 0;
	unsigned count = 0;
	while(*string != 0) { string++;}
	return count;
}

char * my_strcpy(char *dest, const char *origin)
{
	if(!dest) return NULL;
	if(!origin) return dest;

	unsigned i = my_strlen(dest);
	unsigned j = 0;
	while(origin[j] != 0) dest[i++] = origin[j++];
	dest[j+1] = '\0';
	return dest;
}

unsigned my_strcharcount(const char *string, char ch)
{
	if(!string) return 0;
	unsigned count = 0;
	while(*string != 0)
	{
		if(*string == ch) count++;
		string++;
	}
	return count;
}



int my_strncmp(const char *str1, const char *str2, unsigned n)
{
	if(str1 == str2) return 0;
	if(!str1) return -1;
	if(!str2) return 1;


	while( *str1 != 0 && *str2 != 0 && n > 0)
	{
		int res = *str1 - *str2;
		if(res != 0) return res;
		str1++;
		str2++;
		n--;
	}
	return 0;
}


int my_strcmp(const char *str1, const char *str2)
{
	if(str1 == str2) return 0;
	if(!str1) return -1;
	if(!str2) return 1;


	while( *str1 != 0 && *str2 != 0)
	{
		int res = *str1 - *str2;
		if(res != 0) return res;
		str1++;
		str2++;
	}
	return 0;
}



unsigned my_strstrcount(const char *orig, const char *sub)
{
	if(!orig || !sub) return NULL;

	unsigned count = 0;
	unsigned len = my_strlen(sub);

	while(*orig != 0)
	{
		if(!my_strncmp(orig++, sub, len)) 
			count++;
	}
	return count;
}


char * my_strchr(const char *orig, const char ch)
{
	if(!orig) return NULL;
	while(*orig)
	{
		if(*orig == ch) return orig;
		orig++;
	}
	return NULL;
}

char * my_strstr(const char *orig, const char *sub)
{
	if(!orig || !sub) return NULL;
	unsigned len = my_strlen(sub);

	while(*orig)
	{
		if(my_strncmp(orig, sub, len)) return orig;
		orig++;
	}

	return NULL;
}



void my_strup(const char *ret)
{
	if(!ret)
		return;

	while(*ret)
	{
		char c = *ret;

		if(c >= 'a' && c<= 'z') 
		{
			int d = z - 'a';
			*ret = 'A' + d;
		}
		ret++;
	}
}


void my_strlow(const char *ret)
{
	if(!ret)
		return;

	while(*ret)
	{
		char c = *ret;

		if(c >= 'A' && c <= 'Z') 
		{
			int d = z - 'A';
			*ret = 'a' + d;
		}
		ret++;
	}
}


void my_insertsort(void *array, unsigned length, int (*comparator)(void *, void *))
{
	for(int i = 0; i < length - 1; i++)
	{
		x = array[i];
		j = i;
		while(j >= 0 && ((*comparator)(&array[j-1], &array[i]) > 0))
		{
			array[j] = array[j-1];
			j--;
		}
		array[j] = x;
	}
}


void my_strescape(char *orig, char *res, char escape, char *escseq)
{

}

void my_strunescape(char *orig, char *res, char escape, char *escseq)
{

}


