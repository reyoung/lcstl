#ifndef VECTOR_H
#define VECTOR_H

#include "config.h"
#include "type_desc_structs.h"



#define Declare_Vector_PROTOTYPE(type)\
    struct vector_t_##type {\
        type* data;\
        unsigned int size;\
        unsigned int capacity;\
    };\
    __AUX_STRUCT_TYPEDEF(vector,type)\
    extern struct vector_t_##type new_vector_##type();\
    extern struct vector_t_##type new_vector_##type##_with_capacity(unsigned int capacity);\
    extern void destory_vector_##type(struct vector_t_##type * v);\
    extern void push_back_vector_##type(struct vector_t_##type * vec, type value);\
    extern void push_front_vector_##type(struct vector_t_##type * vec, type value);\
    extern void reset_vector_##type(struct vector_t_##type* vec);

#define vector_data(v,i)    ((v).data[i])
#define vector_size(v)      ((v).size)
#define vector_capacity(v)  ((v).capacity)
#define vector_isValid(v)   ((v).data!=NULL)
#define vector_isEmpty(v)   (vector_size(v)==0)

#define Impl_Vector(type,type_description_struct)\
    struct vector_t_##type new_vector_##type(){\
        return new_vector_##type##_with_capacity(20);\
    }\
    struct vector_t_##type new_vector_##type##_with_capacity(unsigned int capacity){\
        struct vector_t_##type retv;\
        retv.data = malloc(capacity*sizeof(type));\
        retv.size = 0;\
        retv.capacity = capacity;\
        return retv;\
    }\
    void destory_vector_##type(struct vector_t_##type * v){\
        free(v->data);\
        v->data = NULL;\
    }\
    static void __increase_vector_##type##_size(struct vector_t_##type * vec,unsigned int inc_val){\
        vec->size+= inc_val;\
        if(vec->size >= vec->capacity){\
            vec->capacity <<=1;\
            vec->data =realloc(vec->data,vec->capacity*sizeof(type));\
        }\
    }\
    void push_back_vector_##type( struct vector_t_##type * vec, type val ){\
        __increase_vector_##type##_size(vec,1);\
        type_description_struct.assign_method (&vec->data[vec->size-1],&val);\
    }\
    void push_front_vector_##type(struct vector_t_##type * vec, type val){\
        unsigned int i;\
        __increase_vector_##type##_size(vec,1);\
        for(i=vec->size-1;i!=0;--i){\
            type_description_struct.assign_method(&vector_data(*vec,i),&vector_data(*vec,i-1)); \
        }\
        type_description_struct.assign_method(&vec->data[0],&val);\
    }\
    void reset_vector_##type(struct vector_t_##type* vec){\
        vec->capacity = 20;\
        vec->size = 0;\
        vec->data = realloc(vec->data,vec->capacity*sizeof(type));\
    }

#ifdef USE_VECTOR_INT
Declare_Vector_PROTOTYPE(int)
#endif


#endif // VECTOR_H
