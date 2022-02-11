#include "unity.h"
#include "main.h"

#include "main.h"
#define PROJECT_NAME    "BikeRecords"

/* Prototypes for all the test functions */
void test_Add_Record(void);
void test_List_Record(void);
void test_Modify_Record(void);
void test_Delete_Record(void);
void test_Exit(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_Add_Record);
  /*RUN_TEST(test_Modify_Record);
  RUN_TEST(test_Exit);*/
  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 

void test_Add_Record() {
  TEST_ASSERT_EQUAL(dominor400 2019 373, Add_Record(dominor400,2019,373));
  
  /* Dummy fail*/
  
  
  TEST_ASSERT_EQUAL(12 raaga 35000, Add_Record(raaga, 12, 7500));*/
}
