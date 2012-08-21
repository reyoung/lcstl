#ifndef TYPE_DESC_STRUCTS_H
#define TYPE_DESC_STRUCTS_H
#define TYPE_DESC_NAME_MAX 16

typedef void (*__assign_method_type)(void*, void*);
typedef int (*__cmp_method_type)(void*, void*);
typedef int (*__init_method_type)(void*);
typedef void (*__destory_method_type)(void*);

struct type_desc_struct{
    __assign_method_type assign_method;
    __cmp_method_type cmp_method;
    __init_method_type init_method;
    __destory_method_type destory_method;
};


#define Declare_Simple_Type_Desc_Struct(type)\
    extern struct type_desc_struct __get_##type##_desc_struct();

#define GetSimpleTypeDescStruct(type)\
    (__get_##type##_desc_struct())


#define Impl_Simple_Type_Desc_Struct(type)\
    static struct type_desc_struct __##type##_desc;\
    static int   __##type##_inited=0;\
    struct type_desc_struct __get_##type##_desc_struct(){\
        if(!__##type##_inited){\
            __##type##_desc.assign_method = NULL;\
            __##type##_desc.cmp_method = NULL;\
            __##type##_desc.init_method = NULL;\
            __##type##_desc.destory_method = NULL;\
            __##type##_inited=-1;\
        }\
        return __##type##_desc;\
    }

#if (defined(USE_VECTOR_INT))
Declare_Simple_Type_Desc_Struct(int);
#endif


#endif // TYPE_DESC_STRUCTS_H
