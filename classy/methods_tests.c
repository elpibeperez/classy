#include <check.h>
#include "methods.h"


START_TEST(method_new_method_test)
{
    method m = method_new_method();
    fail_if(NULL == m ,"method_new_method test");
    method_end_method(m);
}
END_TEST

START_TEST(method_get_set_method_test)
{
    method m = method_new_method();
    char * name = "a_new_name";
    method_set_name(m, name);
    fail_if(0 != strcmp(name, method_get_name(m)), "method_get_set_method test");
    method_set_name(m, NULL);

    fail_if(NULL != method_get_name(m),"method_get_set_method test");
    fail_if(NULL != method_get_name(NULL),"method_get_set_method test");
    method_end_method(m);
}
END_TEST


START_TEST(method_get_set_inputs_test)
{
    //START HAPPY PATH
    method m =  method_new_method();
    input i = input_new_input();
    int id = 0;
    char * input_name = "input_name";
    char * input_type = "input_type";
    input_set_name(i, input_name);
    input_set_type(i, input_type);
    method_add_input(m, i);
    id = method_get_input_id_by_name(m,input_name);
    fail_if(-1 == id, "method_get_set_inputs tests");

    fail_if(NULL == method_get_input_by_id(m, id), "method_get_set_inputs tests");
    fail_unless(1 == method_get_input_size(m), "method_get_set_inputs tests");
    //END HAPPY PATH
    //START NULL TESTS
    id = method_get_input_id_by_name(NULL,input_name);
    fail_unless(-1 == id, "method_get_set_inputs tests");
    id = method_get_input_id_by_name(m,NULL);
    fail_unless(-1 == id, "method_get_set_inputs tests");
    fail_unless(-1 == method_get_input_size(NULL),"method_get_set_inputs tests");
    fail_unless(-1 == method_get_input_id_by_name(NULL, input_name), "method_get_set_inputs tests");
    fail_unless(-1 == method_get_input_id_by_name(m, NULL), "method_get_set_inputs tests");
    //END NULL TESTS
    method_end_method(m);
}
END_TEST

START_TEST(method_get_set_return_type_test)
{
    method m =  method_new_method();
    char * method_type = "class";
    method_set_return_type(m, method_type);

    fail_unless(0 == strcmp(method_get_return_type(m),method_type), "method_get_set_return_type tests");
    fail_unless(NULL == method_get_return_type(NULL), "method_get_set_return_type tests");
    method_set_return_type(m, NULL);
    method_end_method(m);
}
END_TEST

START_TEST(method_copy_compare_method)
{
    method m =  method_new_method();
    method m2 = NULL;
    input i = input_new_input();
    input i2 = NULL;
    char * name = "a_new_name";
    char * method_ret_type = "class";
    char * input_name = "input_name";
    char * input_type = "input_type";
    char * other_type = "other_type";
    input_set_name(i, input_name);
    input_set_type(i, input_type);

    method_set_name(m, name);
    method_add_input(m, i);
    method_set_return_type(m, method_ret_type);

    fail_unless(0 == method_compare_methods(m, m2),"method_copy_compare method");
    fail_unless(0 == method_compare_methods(m2, m),"method_copy_compare method");
    m2 = method_copy_method(m);
    //Testing copy ran correcly
    fail_unless( 0 == strcmp(name, method_get_name(m2)),"method_copy_compare method");
    fail_unless( 0 == strcmp(method_ret_type, method_get_return_type(m2)),"method_copy_compare method");
    fail_unless( 1 == method_get_input_size(m2),"method_copy_compare method");
    i2 = method_get_input_by_id(m2,0);
    fail_unless( i2 != NULL);
    fail_unless(0 == strcmp(input_name, input_get_name(i2)));
    fail_unless(0 == strcmp(input_type, input_get_type(i2)));
    fail_unless(1 == method_compare_methods(m,m2),"method_copy_compare method");
    input_set_type(i, other_type);
    method_add_input(m,i);
    fail_unless(0 == method_compare_methods(m,m2),"method_copy_compare method");

    input_end_input(i);
    method_end_method(m);

}
END_TEST



//TODO: method_get_commands(method m) and method_set_commands(method m, commands c);



int run_methods_tests(){
    Suite *s1 = suite_create("Methods");
    TCase *tc1_1 = tcase_create("Methods");
    TCase *tc1_2 = tcase_create("Methods");
    TCase *tc1_3 = tcase_create("Methods");
    TCase *tc1_4 = tcase_create("Methods");
    TCase *tc1_5 = tcase_create("Methods");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, method_new_method_test);

    suite_add_tcase(s1, tc1_2);
    tcase_add_test(tc1_2, method_get_set_method_test);

    suite_add_tcase(s1, tc1_3);
    tcase_add_test(tc1_3, method_get_set_inputs_test);

    suite_add_tcase(s1, tc1_4);
    tcase_add_test(tc1_4, method_get_set_return_type_test);

    suite_add_tcase(s1, tc1_5);
    tcase_add_test(tc1_5, method_copy_compare_method);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}

