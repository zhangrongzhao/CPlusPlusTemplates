#include "../stdafx.h"
#include "isClassType.h"
#include "csm1.h"
#include "csm2.h"


template<typename T>
class CSMTraits :public BitOrClassCSM<T,IsClassType<T>::No>{

};

/*
//对PODType（Plain old data type）,可以使用安全的位拷贝。特化POD来获得更好的性能。
template<>
class CSMTraits<MyPODType>:public BitOrClassCSM<MyPODType,true>{

};
*/