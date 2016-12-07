#include "stdafx.h"
#include "stackDef.h"

//ÏÔÊ½ÊµÀý»¯
template Stack<std::string>::Stack();

template void Stack<std::string>::push(std::string const&);

template std::string Stack<std::string>::pop();

template std::string Stack<std::string>::top() const;

template Stack<int>::Stack();