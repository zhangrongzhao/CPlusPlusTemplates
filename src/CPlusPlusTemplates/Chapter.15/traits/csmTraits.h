#include "../stdafx.h"
#include "isClassType.h"
#include "csm1.h"
#include "csm2.h"


template<typename T>
class CSMTraits :public BitOrClassCSM<T,IsClassType<T>::No>{

};

/*
//��PODType��Plain old data type��,����ʹ�ð�ȫ��λ�������ػ�POD����ø��õ����ܡ�
template<>
class CSMTraits<MyPODType>:public BitOrClassCSM<MyPODType,true>{

};
*/