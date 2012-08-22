#include <stdio.h>
#include "cstl.h"
#include <assert.h>
#include <stdio.h>

void testVectorInt(){
    int i=0;
    struct vector_t_int vectora = new_vector_int();
    struct vector_iterator_t_int  it;
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

    struct vector_t_int b = new_vector_int();
    for(i=0;i<100;++i){
        push_back_vector_int(&b,i);
    }
    for(i=0;i<100;++i){
        assert(vector_data(b,i)==i);
    }

    reset_vector_int(&b);

    for(i=0;i<100;++i){
        push_front_vector_int(&b,i);
    }
    for(i=0;i<100;++i){
        assert(vector_data(b,i)==100-i-1);
    }
    assert(pop_back_vector_int(&b)==0);
    assert(vector_size(b)==99);
    it = new_vector_int_iterator(&b);
    assert(it.pos == 0);
    assert(it.vec == &b);

    clone_vector_int(&vectora,&b);
    assert(vector_size(vectora)==99);

    for(i=0;i<99;++i){
        assert(vector_data(vectora,i)==100-i-1);
    }
    while(has_next_vector_iterator(it)){
        printf("%d ",next_vector_iterator(it));
    }
    printf("\n");
    while(has_prev_vector_iterator(it)){
        printf("%d ",prev_vector_iterator(it));
    }
    printf("\n");
    destory_vector_int(&b);

}
void testVectorDouble(){
    int i=0;
    struct vector_t_double va = new_vector_double();
    struct vector_iterator_t_double it ;
    for(i=0;i<100;++i){
        push_back_vector_double(&va,1.0/(i+1));
    }
    it = new_vector_double_iterator(&va);
    while(has_next_vector_iterator(it)){
        printf("%f ",next_vector_iterator(it));
    }
    destory_vector_double(&va);
}
void testVectorLongLong(){
    int i=0;
    long long temp;
    struct vector_t_longlong va = new_vector_longlong();
    for(;i<10000;++i){
        temp = i;
        push_back_vector_longlong(&va,temp);
    }
    for(i=0;i<10000;++i){
        temp = i;
        assert(vector_data(va,i)==temp);
    }
    destory_vector_longlong(&va);
}
void testCstl(){
    struct vector_t_int va,vb;
    va = new_vector_int();
    vb = new_vector_int();

    assign_vector_int(&va,300,-39);
    clone_vector_int(&vb,&va);
    destory_vector_int(&va);
    destory_vector_int(&vb);
}

void testVectorBM(){
    unsigned int i;
    for(i=0;i<100000;++i)
        testCstl();
}

int main(void)
{
//    testVectorInt();
//    testVectorDouble();
//    testVectorLongLong();
    testVectorBM();
    return 0;
}

