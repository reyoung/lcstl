TEMPLATE = app
CONFIG += console
CONFIG -= qt

#DEFINES+=USE_VECTOR_INT USE_VECTOR_DOUBLE \
#    USE_VECTOR_FLOAT USE_VECTOR_CHAR USE_VECTOR_SHORT \
#    USE_VECTOR_LONG USE_VECTOR_LONGLONG

#DEFINES+=USE_VECTOR_ITERATOR


DEFINES+=USE_SLIST_INT USE_SLIST_ITERATOR

SOURCES += main.c \
    impl.c

#QMAKE_CFLAGS_DEBUG+= -E


HEADERS += \
    cstl.h \
    vector.h \
    config.h \
    iterator.h \
    type_desc_structs.h \
    slist.h

