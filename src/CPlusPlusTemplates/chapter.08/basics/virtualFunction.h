#include "../stdafx.h"

//��ģ��ĳ�Ա����ģ�岻��Ϊ�麯��
template<typename T>
class Dynamic{
public:
	Dynamic();//��ͨ��Ա����
	virtual ~Dynamic();//��ͨ��Ա����

	template<typename T2>
    void copy(T2 const&);//��ģ��ĳ�Ա����ģ�岻��Ϊ�麯����ԭ����ȷ��Dynamic<T>ʵ����ʱ�򣬲���֪��Copy�ĸ�����
};