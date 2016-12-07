#include "stdafx.h"

#ifndef INCLUSION_MODEL_EXPLICIT_INSTANTITION_H
#define INCLUSION_MODEL_EXPLICIT_INSTANTITION_H

#include "definition.h"
#include <string>

template Stack<int>;

template Stack<std::string>;

template Stack<std::string>::Stack();
template void Stack<std::string>::push(std::string const&);
template std::string Stack<std::string>::top() const;
template std::string Stack<std::string>::pop();
template Stack<std::string> Stack<std::string>::operator=(Stack<std::string> const&);


#endif//INCLUSION_MODEL_EXPLICIT_INSTANTITION_H