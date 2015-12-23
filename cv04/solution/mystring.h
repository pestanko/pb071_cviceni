#include <stdlib.h>


#ifndef __MY_STRING__
#define __MY_STRING__

size_t my_strlen(const char *str);
char * my_strcpy(char *dest, const char *origin);
size_t my_strcharcount(const char *string, char ch);
int my_strcmp(const char *str1, const char *str2);


int my_strncmp(const char *str1, const char *str2, unsigned n);

/* COMPLEX */

size_t my_strstrcount(const char *orig, const char *sub);

const char * my_strchr(const char *orig, const char ch);
const char * my_strstr(const char *orig, const char *sub);

void my_strup(char *ret);

void my_strup(char *ret);

/* INSERT SORT */

void my_insertsort(void *array, unsigned size, unsigned length, int (*comparator)(void *, void *));


#endif