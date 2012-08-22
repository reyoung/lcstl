## LCSTL --- lightweight C-style STL-like Library ##
一个轻量级的stl C语言实现。启发自[libcstl](https://github.com/activesys/libcstl)。但不同的是有几点根本上的想法不同:

* *只做一件事*: 这个库不会实现任何除了stl数据结构和基本之外的东西。也就是，不会有内存池。如果用户认为malloc，free很慢，可以使用其他库来完成。例如，TCMalloc

* *轻量级*: 这个库不需要任何预编译。想要使用的时候，只需包含一个Impl.c，将.h加入includepath即可。
* *静态化*: 这个库的类型注册是纯静态的。也就是，新建一个类型，就会新建一系列新的函数。这样做的好处是:
	* 运行时效率略高
	* 可以编译器检查错误。类型安全
