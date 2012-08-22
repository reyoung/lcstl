#include "vector.h"
#include "slist.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//! Start Vector Impl Defines.
#ifdef USE_VECTOR_INT
Impl_Vector(int,GetSimpleTypeDescStruct(int))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(int)
#endif
#endif

#ifdef USE_VECTOR_DOUBLE
Impl_Vector(double,GetSimpleTypeDescStruct(double))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(double)
#endif
#endif

#ifdef USE_VECTOR_FLOAT
Impl_Vector(float,GetSimpleTypeDescStruct(float))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(float)
#endif
#endif

#ifdef USE_VECTOR_CHAR
Impl_Vector(char,GetSimpleTypeDescStruct(char))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(char)
#endif
#endif

#ifdef USE_VECTOR_SHORT
Impl_Vector(short,GetSimpleTypeDescStruct(short))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(short)
#endif
#endif

#ifdef USE_VECTOR_LONG
Impl_Vector(long,GetSimpleTypeDescStruct(long))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(long)
#endif
#endif

#ifdef USE_VECTOR_LONGLONG
Impl_Vector(longlong,GetSimpleTypeDescStruct(longlong))
#ifdef USE_VECTOR_ITERATOR
Impl_Vector_Iterator(longlong)
#endif
#endif

//! End Vector Impl Defines



//! Start SList Impl Defines

#ifdef USE_SLIST_INT
Impl_Slist_Simple(int)
#endif

//! End SList Impl Defines


//! Start Type Desc Impl Defines

#ifdef USE_SIMPLE_TYPE_INT
Impl_Simple_Type_Desc_Struct(int)
#endif

#ifdef USE_SIMPLE_TYPE_DOUBLE
Impl_Simple_Type_Desc_Struct(double)
#endif

#ifdef USE_SIMPLE_TYPE_FLOAT
Impl_Simple_Type_Desc_Struct(float)
#endif

#ifdef USE_SIMPLE_TYPE_CHAR
Impl_Simple_Type_Desc_Struct(char)
#endif

#ifdef USE_SIMPLE_TYPE_SHORT
Impl_Simple_Type_Desc_Struct(short)
#endif

#ifdef USE_SIMPLE_TYPE_LONG
Impl_Simple_Type_Desc_Struct(long)
#endif

#ifdef USE_SIMPLE_TYPE_LONGLONG
Impl_Simple_Type_Desc_Struct(longlong)
#endif
