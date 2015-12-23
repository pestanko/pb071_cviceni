#include <stdio.h>

#define TEST_CASE(func_name)  int func_name()
#define CAST(a) (a)
#define CAST_TYPE(a,b) (a) (b)
#define PTR(p) (&(p))
#define VAL(p) (*(p))


static int test_result;
static int func_result;
static int test_count = 0;
static int test_passed = 0;
static int test_failed = 0;

#define PRINT(str, ...) do{ fprintf(str, __args__)  }while(0)

#define TEST_SCOPE(name) do{ ; }while(0)
#define RUN_TEST(func) do { func_result = func(); } while(0)

/* Assertions */ 

#define TEST_TRUE(cond) do{ test_result = cond;  }while(0)
#define TEST_FALSE(cond) do{ test_result = !cond;  }while(0)

#define TEST_EQ(a, b) TEST_TRUE( (a) == (b))
#define TEST_EQ_PTR TEST_EQ(PTR(a) == PTR(b))
#define TEST_EQ_VAL TEST_EQ(VAL(a) == VAL(b))


#define TEST_NEQ(a, b) TEST_TRUE( (a) == (b))
#define TEST_NEQ_PTR TEST_EQ(PTR(a), PTR(b))
#define TEST_NEQ_VAL TEST_EQ(VAL(a), VAL(b))



