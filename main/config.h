#ifndef CONFIG_H
#define CONFIG_H

#define NEED_TYPEDEF_STRUCT 0

typedef long long longlong;

#if (NEED_TYPEDEF_STRUCT==1)
#define __AUX_STRUCT_TYPEDEF(struct_type,value_type)\
    typedef struct struct_type##_t_##value_type struct_type##_##value_type;
#else
#define __AUX_STRUCT_TYPEDEF(struct_type, value_type)\
    ;
#endif

#if (defined(USE_VECTOR_CHAR))
#define USE_SIMPLE_TYPE_CHAR
#endif

#if (defined(USE_VECTOR_SHORT))
#define USE_SIMPLE_TYPE_SHORT
#endif

#if (defined(USE_VECTOR_INT)||defined(USE_SLIST_INT))
#define USE_SIMPLE_TYPE_INT
#endif

#if (defined(USE_VECTOR_LONG))
#define USE_SIMPLE_TYPE_LONG
#endif

#if (defined(USE_VECTOR_LONGLONG))
#define USE_SIMPLE_TYPE_LONGLONG
#endif

#if (defined(USE_VECTOR_DOUBLE))
#define USE_SIMPLE_TYPE_DOUBLE
#endif

#if (defined(USE_VECTOR_FLOAT))
#define USE_SIMPLE_TYPE_FLOAT
#endif

#endif // CONFIG_H
