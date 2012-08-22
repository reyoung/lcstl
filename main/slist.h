#ifndef SLIST_H
#define SLIST_H


#define Declare_SList_Prototype(type)\
    struct slist_t_##type##_node {\
        struct slist_t_##type##_node* next;\
        type data;\
    };\
    struct slist_t_##type {\
        struct slist_t_##type##_node* head;\
    };\
    extern struct slist_t_##type new_slist_##type();

#define slist_isEmpty(l) ((l).head==NULL)

#define Impl_SList(type,type_description_struct)\
    struct slist_t_##type new_slist_##type(){\
        struct slist_t_##type retv;\
        retv.head = NULL;\
        return retv;\
    }

#define Impl_Slist_Simple(type)\
    Impl_SList(type,GetSimpleTypeDescStruct(type))

#ifdef USE_SLIST_INT
Declare_SList_Prototype(int)
#endif

#endif // SLIST_H
