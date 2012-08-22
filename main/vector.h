#ifndef VECTOR_H
#define VECTOR_H

#include "config.h"
#include "type_desc_structs.h"
#include "iterator.h"


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
    extern void reset_vector_##type(struct vector_t_##type* vec);\
    extern type pop_back_vector_##type(struct vector_t_##type *vec);\
    extern void clone_vector_##type(struct vector_t_##type * to,\
            struct vector_t_##type* from);\
    extern void assign_vector_##type(struct vector_t_##type* vec,unsigned int count,type data);\
    extern int contains_vector_##type(struct vector_t_##type vec,type data);

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
        unsigned int i=0;\
        if(type_description_struct.destory_method){\
            for(;i<vector_size(*v);++i){\
                type_description_struct.destory_method(&vector_data(*v,i));\
            }\
        }\
        free(v->data);\
        v->data = NULL;\
    }\
    static void __increase_vector_##type##_size(struct vector_t_##type * vec,unsigned int inc_val){\
        vec->size+= inc_val;\
        while(vec->size >= vec->capacity){\
            vec->capacity <<=1;\
        }\
        vec->data =realloc(vec->data,vec->capacity*sizeof(type));\
    }\
    void push_back_vector_##type( struct vector_t_##type * vec, type val ){\
        __increase_vector_##type##_size(vec,1);\
        if(type_description_struct.assign_method)\
            type_description_struct.assign_method (&vec->data[vec->size-1],&val);\
        else\
            vec->data[vec->size-1] = val;\
    }\
    void push_front_vector_##type(struct vector_t_##type * vec, type val){\
        unsigned int i;\
        __increase_vector_##type##_size(vec,1);\
        for(i=vec->size-1;i!=0;--i){\
            if(type_description_struct.assign_method)\
                type_description_struct.assign_method(&vector_data(*vec,i),&vector_data(*vec,i-1)); \
            else\
                vector_data(*vec,i) = vector_data(*vec,i-1);\
        }\
        if(type_description_struct.assign_method)\
            type_description_struct.assign_method(&vec->data[0],&val);\
        else\
            vec->data[0] = val;\
    }\
    void reset_vector_##type(struct vector_t_##type* vec){\
        destory_vector_##type(vec);\
        vec->capacity = 20;\
        vec->size = 0;\
        vec->data = malloc(vec->capacity*sizeof(type));\
    }\
    type pop_back_vector_##type(struct vector_t_##type * vec){\
        assert(vector_size(*vec)!=0);\
        return vec->data[--vec->size];\
    }\
    void clone_vector_##type(struct vector_t_##type * to,\
                struct vector_t_##type* from){\
        unsigned int i=0;\
        destory_vector_##type(to);\
        to->capacity = from->capacity;\
        to->size = from->size;\
        to->data = realloc(to->data,to->capacity*sizeof(type));\
        if(type_description_struct.assign_method){\
            for(;i<to->size;++i){\
                type_description_struct.assign_method(&vector_data(*to,i),&vector_data(*from,i));\
            }\
        }else{\
            memcpy(to->data,from->data,(int)to->size*sizeof(type));\
        }\
    }\
    void assign_vector_##type(struct vector_t_##type* vec,unsigned int count,type data){\
        unsigned int i=vector_size(*vec);\
        __increase_vector_##type##_size(vec,count);\
        if(type_description_struct.assign_method){\
            for(;i<vector_size(*vec);++i){\
                type_description_struct.assign_method(&vector_data(*vec,i),&data);\
            }\
        } else {\
            for(;i<vector_size(*vec);++i){\
                vector_data(*vec,i) = data;\
            }\
        }\
    }\
    int contains_vector_##type(struct vector_t_##type vec,type data){\
        unsigned int i = 0;\
        if(type_description_struct.cmp_method){\
            for(;i<vector_size(vec);++i){\
                if(type_description_struct.cmp_method(&vector_data(vec,i),&data)==0){\
                    return -1;\
                }\
            }\
        }else{\
            for(;i<vector_size(vec);++i){\
                if(vector_data(vec,i)==data)    return -1;\
            }\
        }\
        return 0;\
    }

#ifdef USE_VECTOR_INT
Declare_Vector_PROTOTYPE(int)
#ifdef USE_VECTOR_ITERATOR
Declare_Vector_Iterator_Prototype(int)
#endif
#endif

#ifdef USE_VECTOR_DOUBLE
Declare_Vector_PROTOTYPE(double)
#ifdef USE_VECTOR_ITERATOR
Declare_Vector_Iterator_Prototype(double)
#endif
#endif

#ifdef USE_VECTOR_FLOAT
Declare_Vector_PROTOTYPE(float)
#ifdef USE_VECTOR_ITERATOR
Declare_Vector_Iterator_Prototype(float)
#endif
#endif


#ifdef USE_VECTOR_CHAR
Declare_Vector_PROTOTYPE(char)
#ifdef USE_VECTOR_ITERATOR
Declare_Vector_Iterator_Prototype(char)
#endif
#endif

#ifdef USE_VECTOR_SHORT
Declare_Vector_PROTOTYPE(short)
#ifdef USE_VECTOR_ITERATOR
Declare_Vector_Iterator_Prototype(short)
#endif
#endif

#ifdef USE_VECTOR_LONG
Declare_Vector_PROTOTYPE(long)
#ifdef USE_VECTOR_ITERATOR
Declare_Vector_Iterator_Prototype(long)
#endif
#endif

#ifdef USE_VECTOR_LONGLONG
Declare_Vector_PROTOTYPE(longlong)
#ifdef USE_VECTOR_ITERATOR
Declare_Vector_Iterator_Prototype(longlong)
#endif
#endif


#endif // VECTOR_H
