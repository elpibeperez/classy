#include <check.h>
#include "attributes.h"
#include <string.h>

START_TEST(attribute_new_attribute_test)
{
    attribute a = attribute_new_attribute();
    fail_unless(NULL != a,"attribute_new_attribute test");
    attribute_end_attribute(a);
}
END_TEST

START_TEST(attribute_get_set_attribute_test)
{
    attribute a = attribute_new_attribute();
    access ac= A_SET;
    attribute_set_access(a, ac);

    fail_unless(A_SET == attribute_get_access(a),"attribute_get_set_access test");

    attribute_end_attribute(a);
}
END_TEST

START_TEST(attribute_get_set_attribute_access_NULL)
{
    attribute_set_access(NULL, A_SET);
    fail_unless(A_ERROR == attribute_get_access(NULL),"attribute_get_set_access test");
}
END_TEST


START_TEST(attribute_get_set_attribute_type)
{
    attribute a = attribute_new_attribute();
    char * type = "class";
    attribute_set_type(a, type);

    fail_unless(0 == strcmp(type, attribute_get_type(a))
            ,"attribute_get_set_type test");
    attribute_end_attribute(a);
}
END_TEST


START_TEST(attribute_get_set_attribute_name)
{
    attribute a = attribute_new_attribute();
    char * name = "newclass";
    attribute_set_name(a, name);

    fail_unless(0 == strcmp(name, attribute_get_name(a))
            ,"attribute_get_set_name test");
    attribute_end_attribute(a);
}
END_TEST



START_TEST(attribute_are_attributes_equal_not_equal)
{
    attribute a1 = attribute_new_attribute();
    attribute a2 = attribute_new_attribute();
    access ac1= A_SET;
    char * name1 = "newclass";
    char * type1 = "class";

    access ac2= A_SET_GET;
    char * name2 = "counter";
    char * type2 = "num";

    attribute_set_access(a1,ac1);
    attribute_set_name(a1, name1);
    attribute_set_type(a1,type1);

    attribute_set_access(a2,ac2);
    attribute_set_name(a2, name2);
    attribute_set_type(a2,type2);


    fail_unless(0 == are_attributes_equal(a1, a2)
            ,"attribute_get_set_name test");
    attribute_end_attribute(a1);
    attribute_end_attribute(a2);
}
END_TEST

START_TEST(attribute_are_attributes_equal_ret_equal)
{
    attribute a1 = attribute_new_attribute();
    attribute a2 = attribute_new_attribute();
    access ac1= A_SET;
    char * name1 = "newclass";
    char * type1 = "class";

    access ac2= A_SET;
    char * name2 = "newclass";
    char * type2 = "class";

    attribute_set_access(a1,ac1);
    attribute_set_name(a1, name1);
    attribute_set_type(a1,type1);

    attribute_set_access(a2,ac2);
    attribute_set_name(a2, name2);
    attribute_set_type(a2,type2);


    fail_unless(0 != are_attributes_equal(a1, a2)
            ,"attribute_get_set_name test");
    attribute_end_attribute(a1);
    attribute_end_attribute(a2);
}
END_TEST

START_TEST(attribute_are_attributes_equal_aliasing)
{
    attribute a1 = attribute_new_attribute();
    access ac1= A_SET;
    char * name1 = "newclass";
    char * type1 = "class";

    attribute_set_access(a1,ac1);
    attribute_set_name(a1, name1);
    attribute_set_type(a1,type1);


    fail_unless(0 != are_attributes_equal(a1, a1)
            ,"attribute_are_attributes_equal_aliasing test");
    attribute_end_attribute(a1);
}
END_TEST

START_TEST(attribute_are_attributes_equal_first_null)
{
    attribute a1 = attribute_new_attribute();
    access ac1= A_SET;
    char * name1 = "newclass";
    char * type1 = "class";

    attribute_set_access(a1,ac1);
    attribute_set_name(a1, name1);
    attribute_set_type(a1,type1);


    fail_unless(0 == are_attributes_equal(NULL,a1)
            ,"attribute_are_attributes_equal_aliasing test");
    attribute_end_attribute(a1);
}
END_TEST

START_TEST(attribute_are_attributes_equal_second_null)
{
    attribute a1 = attribute_new_attribute();
    access ac1= A_SET;
    char * name1 = "newclass";
    char * type1 = "class";

    attribute_set_access(a1,ac1);
    attribute_set_name(a1, name1);
    attribute_set_type(a1,type1);


    fail_unless(0 == are_attributes_equal(a1, NULL)
            ,"attribute_are_attributes_equal_aliasing test");
    attribute_end_attribute(a1);
}
END_TEST


int run_attribute_tests()
{
    Suite *s1 = suite_create("Attributes");
    TCase *tc1_1 = tcase_create("Attributes");
    TCase *tc1_2 = tcase_create("Attributes");
    TCase *tc1_3 = tcase_create("Attributes");
    TCase *tc1_4 = tcase_create("Attributes");
    TCase *tc1_5 = tcase_create("Attributes");
    TCase *tc1_6 = tcase_create("Attributes");
    TCase *tc1_7 = tcase_create("Attributes");
    TCase *tc1_8 = tcase_create("Attributes");
    TCase *tc1_9 = tcase_create("Attributes");
    TCase *tc1_10 = tcase_create("Attributes");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, attribute_new_attribute_test);

    suite_add_tcase(s1, tc1_2);
    tcase_add_test(tc1_2, attribute_get_set_attribute_test);

    suite_add_tcase(s1, tc1_3);
    tcase_add_test(tc1_3, attribute_get_set_attribute_type);

    suite_add_tcase(s1, tc1_4);
    tcase_add_test(tc1_4, attribute_get_set_attribute_name);

    suite_add_tcase(s1, tc1_5);
    tcase_add_test(tc1_5    , attribute_are_attributes_equal_not_equal);

    suite_add_tcase(s1, tc1_6);
    tcase_add_test(tc1_6 , attribute_are_attributes_equal_ret_equal);

    suite_add_tcase(s1, tc1_7);
    tcase_add_test(tc1_7 , attribute_are_attributes_equal_aliasing);

    suite_add_tcase(s1, tc1_8);
    tcase_add_test(tc1_8 , attribute_are_attributes_equal_first_null);

    suite_add_tcase(s1, tc1_9);
    tcase_add_test(tc1_9 , attribute_are_attributes_equal_second_null);

    suite_add_tcase(s1, tc1_10);
    tcase_add_test(tc1_10 , attribute_get_set_attribute_access_NULL);


//attribute_get_set_attribute_access_NULL
    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
