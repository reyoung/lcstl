## LCSTL --- lightweight C-style STL-like Library ##
一个轻量级的stl C语言实现。启发自[libcstl](https://github.com/activesys/libcstl)。但不同的是有几点根本上的想法不同:

* **只做一件事**: 这个库不会实现任何除了stl数据结构和基本之外的东西。也就是，不会有内存池。如果用户认为malloc，free很慢，可以使用其他库来完成。例如，TCMalloc
* **轻量级**: 这个库不需要任何预编译。想要使用的时候，只需包含一个Impl.c，将.h加入includepath即可。
* **静态化**: 这个库的类型注册是纯静态的。也就是，新建一个类型，就会新建一系列新的函数。这样做的好处是:
	* 运行时效率略高
	* 可以编译器检查错误。类型安全

## Get Start ##
目前这个库还处于非常初期的开发中，欢迎测试和反馈issue。

* 将Impl.c加入到项目中，将.h的路径加入到includepath中
* 进行使用类型的定义
	* 例如需要使用vector int类型，并且需要使用vector的迭代器，需要define USE_VECTOR_INT和USE_VECTOR_ITERATOR
	* 如果使用的编译器不支持外部define，则可以在config.h中将这两个值define一下。
* include "cstl.h"，使用cstl.h
* 在main下的main.c为测试代码，其中可以查找相应的类型的用途。

## Status ##
VERSION: pre alpha. V0.0.1PA

已经实现的功能:
* vector
* vector iterator
* custom type in vector

预期的实现计划

* slist,queue in V0.0.2PA, due to 9-22, 2012
* list,deque,stack in V0.0.3PA, due to 10-22, 2012
* set,map in V0.0.4PA, due to 11-22, 2012
* multiset,multimap in V0.0.5PA, due to 12-22, 2012
* algo in V0.0.5PA, due to 1-22, 2013