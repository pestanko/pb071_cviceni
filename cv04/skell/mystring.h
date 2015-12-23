#ifndef __MY_STRING__
#define __MY_STRING__

unsigned my_strlen(const char *string);

char * my_strcpy(char *dest, const char *origin);

unsigned my_strcharcount(const char *string, char ch);

int my_strcmp(const char *str1, const char *str2);

int my_strncmp(const char *str1, const char *str2, unsigned n);

unsigned my_strstrcount(const char *orig, const char *sub); // skúste pri implementácii použiť my_strncmp pre uľahčenie práce

char * my_strchr(const char *orig, const char ch);

char * my_strstr(const char *orig, const char *sub);

void my_strup(const char *ret);

void my_insertsort(void *array, unsigned length, int (*comparator)(void *, void *));

void my_strescape(char *orig, char *res, char escape, char *escseq);

void my_strunescape(char *orig, char *res, char escape, char *escseq);

#endif





