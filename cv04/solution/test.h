#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// FILE:LINE {function} - (condition)


#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

int _test_all = 0;
int _test_passed = 0;
int _test_verbose = 0;
const char *_msg;


#define PRINT_WHAT(cond, str)do { \
	_msg = ((cond) ? ANSI_COLOR_GREEN "PASSED" ANSI_COLOR_RESET : ANSI_COLOR_RED "FAILED" ANSI_COLOR_RESET) ;\
	printf("%s:%d (%s) - (%s) - [ %s ]: %s\n", __FILE__, __LINE__, __func__, #cond, _msg, (const char *) str ); \
}while(0)\


#define REQUIREM(cond, msg) do{ \
	_test_all++; \
	if(cond){ _test_passed++; }else{ PRINT_WHAT(cond, msg); } \
	if(cond && _test_verbose) PRINT_WHAT(cond, msg);\
}while(0)\

#define REQUIRE(cond) REQUIREM(cond, "")

#define REQUIRE_FALSE(cond) REQUIRE(!(cond))

#define REQUIREM_FALSE(cond, msg) REQUIREM(cond, msg)


#define TEST_CASE_BEGIN(name) int name (){\
	fprintf(stdout, "\nTEST CASE: [%s] \n", #name );



#define TEST_CASE_END(str) return 0; }

#define TEST_CASE_RUN(name) name()


#define PRINT_STATS do{ \
	fprintf(stdout,  "\n\nALL TESTS: %4d\n", _test_all);\
	fprintf(stdout, ANSI_COLOR_GREEN "PASSED: %4d\n", _test_passed); \
	fprintf(stdout, ANSI_COLOR_RED "FAILED: %4d\n" ANSI_COLOR_RESET, _test_all - _test_passed);\
	}while(0)









