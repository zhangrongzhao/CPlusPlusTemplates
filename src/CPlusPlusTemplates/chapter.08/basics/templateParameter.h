#include "../stdafx.h"

//template<typename T,
//         T* Root,
//		 template<T*>//位于后面的模板参数声明可以引用前面的模板参数名称。 
//         class Buf
//>
//class Structure;

//
//template<typename Allocator>
//class List{
//	class Allocator* allocator;//
//	friend class Allocator;//
//};
//
//template<typename T,
//         typename T::Allocator* Allocator>
//class List;

template<int buf[5]> class Lexer;
template<int* buf> class Lexer;

