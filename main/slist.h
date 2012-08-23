#ifndef SLIST_H
#define SLIST_H
#include "iterator.h"

#define Declare_SList_Prototype(type)\
    struct slist_t_##type##_node {\
        struct slist_t_##type##_node* next;\
        type data;\
    };\
    struct slist_t_##type {\
        struct slist_t_##type##_node* head;\
    };\
    extern struct slist_t_##type new_slist_##type();\
    extern void push_back_slist_##type(struct slist_t_##type* sl,type data);\
    extern unsigned int slist_size_##type(struct slist_t_##type sl);\
    extern void destory_slist_##type(struct slist_t_##type* sl);

#define slist_isEmpty(l) ((l).head==NULL)

#define Impl_SList(type,type_description_struct)\
    struct slist_t_##type new_slist_##type(){\
        struct slist_t_##type retv;\
        retv.head = NULL;\
        return retv;\
    }\
    struct slist_t_##type##_node* __new_slist_node_##type(type data){\
        struct slist_t_##type##_node* retv = malloc(sizeof(struct slist_t_##type##_node));\
        retv->next = NULL;\
        if(type_description_struct.assign_method)\
            type_description_struct.assign_method(&retv->data,&data);\
        else\
            retv->data = data;\
        return retv;\
    }\
    void push_back_slist_##type(struct slist_t_##type* sl, type data){\
        struct slist_t_##type##_node* it = sl->head;\
        if(slist_isEmpty(*sl)){\
            sl->head = __new_slist_node_##type(data);\
        }else{\
            while(it->next)it=it->next;\
            it->next = __new_slist_node_##type(data);\
        }\
    }\
    unsigned int slist_size_##type(struct slist_t_##type sl){\
        unsigned int retv = 0;\
        while(sl.head){\
            ++retv;\
            sl.head = sl.head->next;\
        }\
        return retv;\
    }\
    void __destory_slist_node_##type(struct slist_t_##type##_node* node){\
        if(type_description_struct.destory_method){\
            type_description_struct.destory_method(&node->data);\
        }\
        free(node);\
    }\
    void __destory_slist_rest_##type(struct slist_t_##type##_node* it){\
        if(it){\
            __destory_slist_rest_##type(it->next);\
            __destory_slist_node_##type(it);\
        }\
    }\
    void destory_slist_##type(struct slist_t_##type* sl){\
        struct slist_t_##type##_node* it = sl->head;\
        __destory_slist_rest_##type(it);\
        sl->head = NULL;\
    }

#define Impl_Slist_Simple(type)\
    Impl_SList(type,GetSimpleTypeDescStruct(type))

#ifdef USE_SLIST_INT
Declare_SList_Prototype(int)
Declare_SList_Iterator_Prototype(int)
#endif

#endif // SLIST_H
