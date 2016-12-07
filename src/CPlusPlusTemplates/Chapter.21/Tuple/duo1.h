#include "../stdafx.h"

#ifndef DUO_1_H
#define DUO_1_H

template<typename T1,typename T2>
class Duo{
private:
	T1 value1;//��һ�����ֵ
	T2 value2;//�ڶ������ֵ
public:
	typedef T1 Type1;//��һ���������
	typedef T2 Type2; //�ڶ����������
	enum { N = 2 };//��ĸ���
public:
	//���캯��
	Duo():value1(),value2(){ }
	Duo(T1 const& a,T2 const& b):value1(a),value2(b){ }
	
	//�����ڹ����ڼ䣬������ʽ������ת��
	template<typename U1,typename U2>
	Duo(Duo<U1,U2> const& d):value1(d.v1()),value2(d.v2()){ }

	//�����ڸ�ֵ�ڼ䣬������ʽ������ת��
	template<typename U1,typename U2>
	Duo<T1, T2>& operator=(Duo<U1,U2> const& d){
		value1 = d.value1;
		value2 = d.value2;
		return *this;
	}

	//���ڷ�����ĺ���������ʺ�����
	T1& v1(){ return value1;}
	T1 const& v1() const{return value1;}
	T2& v2(){return value2;}
	T2 const& v2() const{return value2;	}
};

//�Ƚ�����������������ͣ�
template<typename T1, typename T2, typename U1, typename U2>
inline bool operator==(Duo<T1, T2> const& d1, Duo<U1, U2> const& d2){
	return d1.v1() == d2.v1() && d1.v2() == d2.v2();
}

template<typename T1,typename T2,typename U1,typename U2>
inline bool operator!=(Duo<T1,T2> const& d1,Duo<U1,U2> const& d2){
	return !(d1==d2);
}

//��Դ����ͳ�ʼ���ĸ�������
template<typename T1,typename T2>
inline Duo<T1,T2> make_duo(T1 const& a,T2 const& b){
	return Duo<T1, T2>(a,b);
}

//template<typename T1,typename T2>
//inline Duo<T1, T2> make_duo(T1& a,T2& b){
//	return Duo<T1, T2>(a,b);
//}


#endif//DUO_1_H