
#include "stdafx.h"
#include "MemberFunctionPointer.h"

//void main(){
//
//	//��ͨ��Ա��������
//	D obj;
//	obj.mf1();
//	obj.mf2();//����ָ�����
//}


//int main(){
//	D obj;
//	D* ptr = new D();
// 	call_memfun(obj,&D::mf1);
//	call_memfun(obj,&D::mf2);
//
//	//�Գ�Ա����ָ�����ǿ������ת������ַ�����ᷢ���ı䡣
//	void(D::*pmf_a)() = &D::mf2;//��ַ����Ϊ+4���ֽ�
//	void(B2::*pmf_b)() = (void(B2::*)())pmf_a;//�ֱ��ԭ���ĵ�ַ������ַ����Ϊ0
//
//	//��Ա����ָ��ȡ�����������.*  ->*
//	(obj.*pmf_a)();//����λ��obj�е�pmf�����õĳ�Ա����
//	(ptr->*pmf_b)();//����λ��ptrָ�������õĶ����pmf_b�����õĳ�Ա������
//
//	//ͨ��ָ�����һ����ͨ������һ��һԪ����
//	//(*ptr)();
//
//}

