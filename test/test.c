#include "../src/lib.h"
#include <stdlib.h>
#include <stdio.h>
#include <check.h>
#include <math.h>
#define EPSILON 0.000001


START_TEST(test_CreateConst_easysentence)
{	
	char test_str[] = "Я закінчив школу";
	long int expected_res = 185;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_DEquestion)
{	
	char test_str[] = "Was ist das?";
	long int expected_res = 333;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_truesentence)
{	
	char test_str[] = "Шо нам ті кулі, нас ракети не беруть.";
	long int expected_res = 23243626;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_numbersentence)
{	
	char test_str[] = "Мені 18 років";
	long int expected_res = 425;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


START_TEST(test_CreateConst_nosentence)
{	
	char test_str[] = "\0";
	long int expected_res = 0;
	long int actual_res = CreateConst(test_str);
	
	ck_assert_int_eq(expected_res, actual_res);
}
END_TEST


Suite *lab_test_suite(void)
{
	Suite *s;
	TCase *tc_CreateConst;

	s = suite_create("lab13");

	tc_CreateConst = tcase_create("CreateConst");

	tcase_add_test(tc_CreateConst, test_CreateConst_easysentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_DEquestion);
	tcase_add_test(tc_CreateConst, test_CreateConst_truesentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_numbersentence);
	tcase_add_test(tc_CreateConst, test_CreateConst_nosentence);

	suite_add_tcase(s, tc_CreateConst);

	return s;
}


int main(void)
{
	int number_failed;
	Suite *s;
	SRunner *sr;


	s = lab_test_suite();
	sr = srunner_create(s);


	srunner_run_all(sr, CK_NORMAL);
	number_failed = srunner_ntests_failed(sr);
	srunner_free(sr);


	return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
