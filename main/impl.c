#include "vector.h"
#include <stdlib.h>
#include <assert.h>
#ifdef USE_VECTOR_INT
Impl_Vector(int,GetSimpleTypeDescStruct(int))
#endif


#if (defined(USE_VECTOR_INT))
Impl_Simple_Type_Desc_Struct(int)
#endif
