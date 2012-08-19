#ifndef CONFIG_H
#define CONFIG_H

#define NEED_TYPEDEF_STRUCT 0



#if (NEED_TYPEDEF_STRUCT==1)
#define __AUX_STRUCT_TYPEDEF(struct_type,value_type)\
    typedef struct struct_type##_t_##value_type struct_type##_##value_type;
#else
#define __AUX_STRUCT_TYPEDEF(struct_type, value_type)\
    ;
#endif
#endif // CONFIG_H
