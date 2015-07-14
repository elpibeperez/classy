#include "inputs_tests.h"
#include "attributes_tests.h"
#include "methods_tests.h"
#include "syntactic_structure_test.h"
int main(){

    int ret = 0;
    ret = run_inputs_tests();
    if(ret == 0){
        ret =  run_attribute_tests();
    }if(ret == 0){
        ret =  run_methods_tests();
    }if (ret == 0){
        ret = run_syntactic_structure_tests();
    }

    return ret;
}
