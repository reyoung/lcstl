TEMPLATE = app
CONFIG += console
CONFIG -= qt

DEFINES+=USE_VECTOR_INT

SOURCES += main.c \
    impl.c

HEADERS += \
    cstl.h \
    vector.h \
    config.h \
    iterator.h \
    type_desc_structs.h

