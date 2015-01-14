#include <stdio.h>
#include <stdlib.h>

const int global_var;
const int global_var_init = 5;
char * gloval_ptr;
char *gloval_ptr_init = "Hello, worlds";

int main(){

    int local_var;
    int local_var_init = 5;

    char * local_ptr;
    char * local_ptr_init = "Hello Local Worlds";

    int * local_dynamic_ptr = (int*)malloc(sizeof(int));
    int * local_dynamic_ptr2 = (int*)malloc(sizeof(int));

    printf("Just text : %p\n",(void*)(&"Hello, World"));
    printf("Global int var : %p\n",(void*)&global_var);
    printf("Global int ptr: %p\n",(void*)&gloval_ptr);
    printf("Global int var with init : %p\n",(void*)&global_var_init);
    printf("Global int ptr with init : %p\n",(void*)&gloval_ptr_init);
    printf("Local int ptr  : %p\n",(void*)&local_ptr);
    printf("Local int ptr with init : %p\n",(void*)&local_ptr_init);
    printf("Local int var  : %p\n",(void*)&local_var);
    printf("Local int var with init : %p\n",(void*)&local_var_init);
    //printf("Local Dynamic ptr : %p\n",(void*)&global_dynamic_ptr);
    printf("Local Dynamic ptr : %p\n",(void*)&local_dynamic_ptr);
    printf("Local Dynamic ptr : %p\n",(void*)&local_dynamic_ptr2);
    return 0;
}