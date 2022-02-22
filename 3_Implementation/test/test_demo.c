#include "unity.h"
#include "header.h"
void setUp()
{
} 
void tearDown()
{
}
void test_displayRecord(void)
{
    TEST_ASSERT_EQUAL(0, displayRecord(100));
}

void test_displayAllRecords(void)
{
    TEST_ASSERT_EQUAL(0, displayAllRecords());
}
int test_main() // main function for test_demo file
{
    UNITY_BEGIN(); // Initialize Unity Test 
    RUN_TEST(test_displayRecord); // Test to chech if contacts exist
    RUN_TEST(test_displayAllRecords); // test to display all contacts
    return UNITY_END(); // End Unity Test 
}