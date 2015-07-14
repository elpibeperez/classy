#include <check.h>
#include "inputs.h"

START_TEST(input_new_input_test)
{
    input i = input_new_input();
    fail_unless( NULL != i, "input_new_input test");
    input_end_input(i);
}
END_TEST

START_TEST(input_get_set_name_test)
{
    char * name = "My name";
    input i = input_new_input();
    int ret = 0;
    input_set_name(i,name);
    ret = strcmp(input_get_name(i), name);
    fail_unless( 0 == ret, "input_new_input test");
    input_end_input(i);
}
END_TEST

START_TEST(input_get_set_type_test)
{
    char * type = "A type";
    input i = input_new_input();
    int ret = 0;
    input_set_type(i,type);
    ret = strcmp(input_get_type(i), type);
    fail_unless( 0 == ret, "input_new_input test");
    input_end_input(i);
}
END_TEST


int run_inputs_tests()
{
    Suite *s1 = suite_create("Inputs");
    TCase *tc1_1 = tcase_create("Inputs");
    TCase *tc1_2 = tcase_create("Inputs");
    TCase *tc1_3 = tcase_create("Inputs");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, input_new_input_test);

    suite_add_tcase(s1, tc1_2);
    tcase_add_test(tc1_2, input_get_set_name_test);

    suite_add_tcase(s1, tc1_3);
    tcase_add_test(tc1_3, input_get_set_type_test);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
