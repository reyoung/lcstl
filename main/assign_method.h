#ifndef ASSIGN_METHOD_H
#define ASSIGN_METHOD_H


#define Declare_SimpleTypeAssignMethod(type)\
    extern void __assign_##type##_simp (type* to, type* from);

#define Impl_SimpleTypeAssignMethod(type)\
    void __assign_##type##_simp(type* to, type* from){\
        *to = *from;\
    }
#define SimpleTypeAssignMethod(type)    __assign_##type##_simp


#if (defined(USE_VECTOR_INT))
Declare_SimpleTypeAssignMethod(int)
#endif


#endif // ASSIGN_METHOD_H
