#include "test.h"
#include "mystring.h"
#include <string.h>

char buffer[255];
char *pointer = NULL;

#define STRLEN_REQ(a, len) REQUIRE( my_strlen(a) == len)

#define STRCMP_SREQ(a, b) REQUIRE(strcmp(a, b) == 0)

#define TEST_CPY(a) do {	\
	pointer = my_strcpy(buffer, a); \
	REQUIRE(buffer == pointer);\
	STRCMP_SREQ(buffer, pointer);\
}while(0)

#define STRCC(a, b, l) REQUIRE(my_strcharcount(a, b) == l)

#define STRCMP_EQ(a,b) REQUIRE(my_strcmp(a,b) == 0)
#define STRCMP_NEQ(a,b) REQUIRE_FALSE(my_strcmp(a,b) != 0)
#define STRCMP_FIRST(a,b) REQUIRE(my_strcmp(a,b) <  0)
#define STRCMP_SEC(a,b) REQUIRE(my_strcmp(a,b) > 0)

#define STRSTR(a,b, l) REQUIRE(my_strstrcount(a,b) == l)



TEST_CASE_BEGIN(test_len)

	STRLEN_REQ("Ahoj", 4);
	STRLEN_REQ("", 0);
	STRLEN_REQ(NULL, 0);
	
	STRLEN_REQ("Ahoj svet!", 10);
	STRLEN_REQ("Lorem\nIpsum\n Tabs Cols Rows\n", 28);
	
TEST_CASE_END(test_len)

TEST_CASE_BEGIN(test_cpy)
	TEST_CPY("Ahoj");
	TEST_CPY("");
	
TEST_CASE_END(test_cpy)


TEST_CASE_BEGIN(test_char_count)
	STRCC("Ahoj", 'A', 1);
	STRCC("", 'A', 0);
	STRCC(NULL, 'A', 0);
	STRCC("AAAA", 'A', 4);
	STRCC("Ahoj", 'a', 0);
	STRCC("a aa aa bb ab bca", 'a', 7);
TEST_CASE_END(test_char_count)

TEST_CASE_BEGIN(test_cmp)
	STRCMP_EQ("Ahoj svet", "Ahoj svet");
	STRCMP_NEQ("Ahoj", "ahoj");
	STRCMP_NEQ("aaa aa", "aaaa a");
	STRCMP_NEQ("aaaaa", "aaaa");
	STRCMP_FIRST("abc", "bcd");
	STRCMP_FIRST("Abc", "abc");
	STRCMP_SEC("abc", "abb");
TEST_CASE_END(test_cmp)


TEST_CASE_BEGIN(test_ncmp)
{
	REQUIRE(my_strncmp("Ahoj", "Agoj", 1) == 0);
	REQUIRE(my_strncmp("Ahoj", "Ahoj", 100) == 0);
	REQUIRE(my_strncmp("Ahoj", "Agoj", 100) > 0);
	REQUIRE(my_strncmp("Ahoj", "Agoj", 5) != 0);
}
TEST_CASE_END(test_ncmp)


TEST_CASE_BEGIN(test_strstrcount)
{
	STRSTR("aaa", "a", 3);
	STRSTR("", "a", 0);
	STRSTR(NULL, "a", 0);
	STRSTR("aaa", NULL, 0);
	STRSTR("aaaa", "", 0);
	STRSTR("aaa", "aa", 2);
	STRSTR("abba baab a b", "a b", 3);
}
TEST_CASE_END(test_strstrcount)


int main()
{
	
	TEST_CASE_RUN(test_len);
	TEST_CASE_RUN(test_cpy);
	TEST_CASE_RUN(test_char_count);
	TEST_CASE_RUN(test_cmp);
	TEST_CASE_RUN(test_ncmp);
	TEST_CASE_RUN(test_strstrcount);

	
	PRINT_STATS;	
	return 0;
}

