#ifndef TYPE_DESC_STRUCTS_H
#define TYPE_DESC_STRUCTS_H
#define TYPE_DESC_NAME_MAX 16

typedef void (*__assign_method_type)(void*, void*);
struct type_desc_struct{
//    char name[TYPE_DESC_NAME_MAX];

    __assign_method_type assign_method;
};


#define Declare_Simple_Type_Desc_Struct(type)\
    extern struct type_desc_struct __get_##type##_desc_struct();

#define GetSimpleTypeDescStruct(type)\
    (__get_##type##_desc_struct())


#define Impl_Simple_Type_Desc_Struct(type)\
    static struct type_desc_struct __##type##_desc;\
    static int   __##type##_inited=0;\
    static void __##type##_assign_method(void* to, void* from){\
        *(type*)to=*(type*)from;\
    }\
    struct type_desc_struct __get_##type##_desc_struct(){\
        if(!__##type##_inited){\
             __##type##_desc.assign_method = __##type##_assign_method;\
            __##type##_inited=-1;\
        }\
        return __##type##_desc;\
    }

#if (defined(USE_VECTOR_INT))
Declare_Simple_Type_Desc_Struct(int);
#endif


#endif // TYPE_DESC_STRUCTS_H
