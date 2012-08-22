#ifndef ITERATOR_H
#define ITERATOR_H
#include "vector.h"

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

#endif // ITERATOR_H
