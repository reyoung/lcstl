#include <stdio.h>
#include "cstl.h"
#include <assert.h>
#include <stdio.h>
int main(void)
{
    struct vector_t_int vectora = new_vector_int();
    assert(vector_isValid(vectora));
    assert(vector_size(vectora)==0);
    assert(vector_isEmpty(vectora));
    assert(vector_capacity(vectora)==20);

    push_back_vector_int(&vectora,10);
    assert(vector_data(vectora,0)==10);
    assert(vector_size(vectora)==1);

    push_front_vector_int(&vectora,1);
    assert(vector_data(vectora,0)==1);
    assert(vector_data(vectora,1)==10);
    assert(vector_size(vectora)==2);

    destory_vector_int(&vectora);
    assert(!vector_isValid(vectora));
    return 0;
}

