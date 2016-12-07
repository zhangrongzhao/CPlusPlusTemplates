#include "../stdafx.h"

#ifndef COPY_SWAP_MOVE_TRAITS_H
#define COPY_SWAP_MOVE_TRAITS_H
#include "IsClassT.h"
#include "BitOrClassCSM.h"
template<typename T>
class CSMtraits :public BitOrClassCSM<T,IsClassT<T>::No>{ };


class MyPODType{ };

template<>
class CSMtraits<MyPODType> :public BitOrClassCSM <MyPODType,true>{ }


#endif//COPY_SWAP_MOVE_TRAITS_H