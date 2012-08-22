#include "vector.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#ifdef USE_VECTOR_INT
Impl_Vector(int,GetSimpleTypeDescStruct(int))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(int)
#endif

#endif


#if (defined(USE_VECTOR_INT))
Impl_Simple_Type_Desc_Struct(int)
#endif
