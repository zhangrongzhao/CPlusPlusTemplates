////字符串作为模板实参时，必须是外部链接对象。如果是内部链接对象，相同的字符串值可能保存在不同的地址中。不能视为常量
//template<char const* str>
//class　Message{};
//
//extern char const hello[] = "Hello World.";
//
//Message<hello>* hello_msg;
