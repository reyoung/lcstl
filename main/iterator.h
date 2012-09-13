#ifndef ITERATOR_H
#define ITERATOR_H
//#include "vector.h"
//#include "slist.h"

#define Declare_Vector_Iterator_Prototype(type)\
    struct vector_iterator_t_##type{\
        struct vector_t_##type* vec;\
        unsigned int pos;\
    };\
    extern struct vector_iterator_t_##type new_vector_##type##_iterator\
                        (struct vector_t_##type* vec);

#define to_front_vector_iterator(it) ((it).pos=0)
#define to_back_vector_iterator(it) ((it).pos= vector_size(*(it).vec))
#define has_next_vector_iterator(it) ((it).pos < vector_size(*(it).vec))
#define has_prev_vector_iterator(it) ((it).pos!=0)
#define next_vector_iterator(it) (vector_data(*(it).vec,(it).pos++))
#define peek_next_vector_iterator(it) (vector_data(*(it).vec,(it).pos))
#define peek_prev_vector_iterator(it) (vector_data(*(it).vec,(it).pos-1))
#define prev_vector_iterator(it) (vector_data(*(it).vec,--(it).pos))

#define Impl_Vector_Iterator(type)\
    struct vector_iterator_t_##type new_vector_##type##_iterator\
                            (struct vector_t_##type* vec){\
        struct vector_iterator_t_##type retv;\
        retv.vec = vec; retv.pos = 0;\
        return retv;\
    }




#define Declare_SList_Iterator_Prototype(type)\
    struct slist_t_##type##_node;\
    struct slist_iterator_t_##type {\
        struct slist_t_##type##_node * head;\
        struct slist_t_##type##_node * cur;\
    };\
    extern struct slist_iterator_t_##type new_slist_##type##_iterator\
            (struct slist_t_##type* slist);



#define has_next_slist_iterator(it)\
    ((it).cur==NULL ||(it).cur->next!=NULL)

#define next_slist_iterator(it)\
    (((it).cur)\
    ?(((it).cur=(it).cur->next)?(it).cur->data:0)\
    :((it).cur=(it.head))?(it).cur->data:0)

#define peek_next_slist_iterator(it)\
    ((it).cur?(it.cur->next->data):(it.head->data))

#define to_back_slist_iterator(it)\
    do{it.cur = 0;}while(0)

#define Impl_Slist_Iterator(type)\
    struct slist_iterator_t_##type new_slist_##type##_iterator\
                (struct slist_t_##type* slist){\
        struct slist_iterator_t_##type retv;\
        retv.head  = slist->head;\
        retv.cur = NULL;\
        return retv;\
    }



#endif // ITERATOR_H
