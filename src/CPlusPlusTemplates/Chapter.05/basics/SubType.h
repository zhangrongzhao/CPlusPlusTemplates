#include "../stdafx.h"

template<typename T>
class MyClass{
public:
   //typeaname��ʾSubTypeΪģ�����T���ڲ�����
   //���SubTypeǰ�����ùؼ���typename,*�ᱻ��Ϊ�ǳ˺ţ���ɳ˻����ʽ��
   typename T::SubType *pointer;
};