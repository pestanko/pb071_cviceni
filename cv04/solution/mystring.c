#include "mystring.h"


size_t my_strlen(const char *str)
{
	if(!str) 
		return 0;
	
	const char * it = str;
	
	while(*it != 0){ it++; }
	
	return it - str;
}

char * my_strcpy(char *dest, const char *origin)
{
	if(!dest || !origin) return NULL;
	
	char *p = dest;
	
	while(*origin != 0)
	{
		*dest = *origin;
		dest++;
		origin++;
	}
	*dest = 0;
	
	return p;
}

size_t my_strcharcount(const char *string, char ch)
{
	if(!string) return 0;
	
	size_t counter = 0;
	
	while(*string)
	{
		if(*string == ch) counter++; 
		string++;
	}
	
	return counter;
}

int my_strcmp(const char *str1, const char *str2){
	if(str1 == str2) return 0;
	if(!str1) return -1;
	if(!str2) return 1;
	
	while(*str1 && *str2)
	{
		if(*str1 != *str2)
			return *str1 - *str2; 
		str1++;
		str2++;
	}
	
	if(!*str1 && !*str2) return 0;
	if(!*str1 && *str2) return 1;
	if(*str1 && !*str2) return -1;
	return 0;
}


int my_strncmp(const char *str1, const char *str2, unsigned n)
{
	if(str1 == str2) return 0;
	if(!str1) return -1;
	if(!str2) return 1;
	while(*str1 && *str2 && n--)
	{
		if(*str1 == *str2) continue;
		return *str1 - *str2; 
	}
	return 0;
}

/* COMPLEX */

size_t my_strstrcount(const char *orig, const char *sub)
{
	if(!orig || sub) return 0;
	
	size_t len = my_strlen(sub);
	size_t counter = 0;
	
	while(*orig)
	{
		if(!my_strncmp(orig, sub, len)) counter++;
		orig++;
	}
	
	return counter;
}


const char * my_strchr(const char *orig, const char ch){
	if(!orig) return NULL;
	
	while(*orig)
	{
		if(*orig == ch) return orig;
		orig++;
	}
	return NULL;
}

const char * my_strstr(const char *orig, const char *sub)
{
	if(!orig) return NULL;
	size_t len = my_strlen(sub);
	
	while(*orig)
	{
		if(!my_strncmp(orig, sub, len)) return orig;
		orig++;
	}
	return NULL;
}

void my_strup(char *ret){
	if(!ret) return;
	while(*ret)
	{
		char c = *ret;
		if(c >= 'a' && c <= 'z')
		{
			c = (c - 'a') + 'A';
			*ret = c;
		}

		ret++;
	}
}

void my_strlow(char *ret){
	if(!ret) return;
	while(*ret)
	{
		char c = *ret;
		if(c >= 'A' && c <= 'Z')
		{
			c = (c - 'A') + 'z';
			*ret = c;
		}

		ret++;
	}
}

/* INSERT SORT */

void my_insertsort(void *array, unsigned size, unsigned length, int (*comparator)(void *, void *))
{
	for (unsigned i = 1 ; i < length; i += size)
	{
		char *a = (char*) array; // X
		char *aj = (char*) array; // A[j]
		char *b = (char*) array - size; // A[j - 1]
		unsigned j = i;
		while(j <= 0 && (*comparator)( (void *) aj, (void *) b)){
			aj = b;
			b = b - size;
		}
		aj = a;	
	}
}
