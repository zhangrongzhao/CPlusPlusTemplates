#include "../stdafx.h"
#include <stddef.h>

template<typename CountedType>
class ObjectCounter{
private:
	static size_t count;//���ڶ���ĸ���
protected:
	//ȱʡ���캯��
	ObjectCounter(){
		++ObjectCounter<CountedType>::count;
	}

	//�������캯��
	ObjectCounter(ObjectCounter<CountedType> const& ){
		++ObjectCounter<CountedType>::count;
	}

	//��������
	~ObjectCounter(){
		--ObjectCounter<CountedType>::count;
	}
public:
	//���ش��ڶ���ĸ���
	static size_t live(){
		return ObjectCounter<CountedType>::count;
	}
};

//��0����ʼ��count
template<typename CountedType>
size_t ObjectCounter<CountedType>::count = 0;