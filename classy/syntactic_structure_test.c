#include "syntactic_structure_test.h"
#include <check.h>
#include "syntactic_structure.h"


START_TEST(syntactic_structure_new_syntactic_structure_test)
    {
        syntactic_structure s = syntactic_structure_new_syntactic_structure();
        fail_if(NULL == s ,"syntactic_structure_new_syntactic_structure test");
        syntactic_structure_end_syntactic_structure(s);
    }
END_TEST

START_TEST(syntactic_structure_set_get_inherit_test)
    {
        syntactic_structure s = syntactic_structure_new_syntactic_structure();
        char * inherit = "father";
        fail_if(NULL == s ,"syntactic_structure_set_get_inherit test");
        syntactic_structure_set_inherit(s, inherit);
        fail_if(0 != strcmp(syntactic_structure_get_inherit(s),inherit) ,
                    "syntactic_structure_set_get_inherit test");
        syntactic_structure_set_inherit(NULL, inherit);
        syntactic_structure_set_inherit(s, NULL);
        syntactic_structure_end_syntactic_structure(s);
    }
END_TEST

START_TEST(syntactic_structure_add_get_use_test)
    {
        syntactic_structure s = syntactic_structure_new_syntactic_structure();
        char * using1 = "use1";
        syntactic_structure_add_use(s, using1);
        fail_if(0 != strcmp(syntactic_structure_get_use(s, 0),using1) ,
                "syntactic_structure_add_get_use test");
        fail_if(1 != syntactic_structure_get_use_size(s) ,
                "syntactic_structure_add_get_use test");
        syntactic_structure_add_use(NULL, using1);
        syntactic_structure_add_use(s, NULL);
        syntactic_structure_get_use_size(NULL);
        syntactic_structure_get_use(NULL, 0);
        syntactic_structure_get_use(s, 10);
        syntactic_structure_end_syntactic_structure(s);

    }
END_TEST

START_TEST(syntactic_structure_add_get_attrib_test)
{
    syntactic_structure s = syntactic_structure_new_syntactic_structure();
    attribute attrib = attribute_new_attribute();

    attribute_set_name(attrib,"count");
    attribute_set_access(attrib, A_SET);
    attribute_set_type(attrib,"num");

    syntactic_structure_add_attrib(s, attrib);
    fail_if(A_SET != attribute_get_access(syntactic_structure_get_attrib(s,0)),
            "syntactic_structure_add_get_attrib_test");
    fail_if(0 != strcmp("num",
            attribute_get_type(syntactic_structure_get_attrib(s,0))),
            "syntactic_structure_add_get_attrib_test");
    fail_if(0 != strcmp("count",
            attribute_get_name(syntactic_structure_get_attrib(s,0))),
            "syntactic_structure_add_get_attrib_test");
    fail_if(1 != syntactic_structure_get_attrib_size(s),
            "syntactic_structure_add_get_attrib_test");
    fail_if(0 != syntactic_structure_get_attrib_id_by_name(s,"count"),
            "syntactic_structure_add_get_attrib_test");
    fail_if(0 != syntactic_structure_get_attrib_id(s,attrib),
            "syntactic_structure_add_get_attrib_test");

    syntactic_structure_add_attrib(s, NULL);
    syntactic_structure_add_attrib(NULL, attrib);
    syntactic_structure_get_attrib(NULL,0);
    syntactic_structure_get_attrib_size(NULL);
    syntactic_structure_get_attrib_id_by_name(NULL,"count");
    syntactic_structure_get_attrib_id_by_name(s, NULL);

}
END_TEST

START_TEST(syntactic_structure_add_get_method_test)
{
    syntactic_structure s = syntactic_structure_new_syntactic_structure();
    method m = method_new_method();
    input i = input_new_input();
    method_set_name(m, "fib");
    method_set_return_type(m, "num");
    input_set_name(i, "i");
    input_set_type(i, "num");
    method_add_input(m, i);

    syntactic_structure_add_method(s,m);
    fail_unless(1 == syntactic_structure_get_method_size(s)
        ,"syntactic_structure_add_get_method_test");
    fail_if(NULL == syntactic_structure_get_method(s,0)
        ,"syntactic_structure_add_get_method_test");
    fail_if(-1 == syntactic_structure_get_method_id(s,m)
        ,"syntactic_structure_add_get_method_test");
    //TEST NULLS
    syntactic_structure_add_method(s,NULL);
    syntactic_structure_add_method(NULL,m);
    syntactic_structure_get_method_size(NULL);
    syntactic_structure_get_method(NULL, 0);
    syntactic_structure_get_method(NULL, -1);
    syntactic_structure_get_method(NULL, -10);
    syntactic_structure_get_method_id(NULL,m);
    syntactic_structure_get_method_id(s,NULL);

}
END_TEST
//method syntactic_structure_get_method(syntactic_structure s, int i);
//void syntactic_structure_add_method(syntactic_structure s, method m);
//int syntactic_structure_get_method_id(syntactic_structure s, method m);
//int syntactic_structure_get_method_size(syntactic_structure s);



START_TEST(syntactic_structure_add_get_name_test)
    {

    }
END_TEST


//char *syntactic_structure_get_name(syntactic_structure s, int i);
//void syntactic_structure_add_name(syntactic_structure s, char *name);
//int syntactic_structure_get_name_id(syntactic_structure s, char *name);
//int syntactic_structure_get_name_size(syntactic_structure s);

//void syntactic_structure_end_syntactic_structure(syntactic_structure s);



int run_syntactic_structure_tests(){
    Suite *s1 = suite_create("Syntactic Structure");
    TCase *tc1_1 = tcase_create("Syntactic Structure");
    TCase *tc1_2 = tcase_create("Syntactic Structure");
    TCase *tc1_3 = tcase_create("Syntactic Structure");
    TCase *tc1_4 = tcase_create("Syntactic Structure");
    TCase *tc1_5 = tcase_create("Syntactic Structure");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, syntactic_structure_new_syntactic_structure_test);

    suite_add_tcase(s1, tc1_2);
    tcase_add_test(tc1_2, syntactic_structure_set_get_inherit_test);

    suite_add_tcase(s1, tc1_3);
    tcase_add_test(tc1_3, syntactic_structure_add_get_use_test);

    suite_add_tcase(s1, tc1_4);
    tcase_add_test(tc1_4, syntactic_structure_add_get_attrib_test);

    suite_add_tcase(s1, tc1_5);
    tcase_add_test(tc1_5, syntactic_structure_add_get_method_test);

    //syntactic_structure_add_get_method_test
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
