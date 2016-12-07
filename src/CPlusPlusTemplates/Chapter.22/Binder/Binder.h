#include "../stdafx.h"

#ifndef BINDER_1_H
#define BINDER_1_H

#include "BoundVal.h"
#include "BinderParams.h"
#include "..\Traits\ForwardParam.h"

template<typename FO,int P,typename V>
class Binder:private FO,private V{//�ջ����Ż�������û�б�Ҫ���ڴ濪��
public:
	//��Ϊһ�������Ѿ����������������ȥһ����������
	enum{ NumParams = FO::NumParams - 1 };

	//�������ͣ��º����ķ�������
	typedef typename FO::ReturnT ReturnT;

	//��������
	typedef BinderParams<FO, P> Params;

#define ComposeParamT(N)                                                             \
	typedef typename ForwardParamT<typename Params::Param##N##T>::Type Param##N##T;  \

	ComposeParamT(1);
	ComposeParamT(2);
	ComposeParamT(3);
	ComposeParamT(4);
	ComposeParamT(5);
	ComposeParamT(6);
	ComposeParamT(7);
	ComposeParamT(8);
	ComposeParamT(9);
	ComposeParamT(10);
	ComposeParamT(11);
	ComposeParamT(12);
	ComposeParamT(13);
	ComposeParamT(14);
	ComposeParamT(15);
	ComposeParamT(16);
	ComposeParamT(17);
	ComposeParamT(18);
	ComposeParamT(19);
	ComposeParamT(20);
#undef ComposeParamT

public:
	//���캯��������º������ض�ֵ
	Binder(FO& fo) :FO(fo){}
	Binder(FO& fo, V& v) :FO(fo), V(v){}
	Binder(FO& fo, V const& v) :FO(fo), V(v){}

	Binder(FO const& fo) :FO(fo){}
	Binder(FO const& fo, V& v) :FO(fo), V(v){}
	Binder(FO const& fo, V const& v) :FO(fo), V(v){}

	template<typename T>
	Binder(FO& fo, T& v) : FO(fo), V(BoundVal<T>(v)){ }
	template<typename T>
	Binder(FO& fo, T const& v) : FO(fo), V(BoundVal<T const>(v)){}

public:
	//��������
	ReturnT operator()(){
		return FO::operator()(V::get());
	}

	ReturnT operator()(Param1T v1){
		return FO::operator()(ArgSelect<1>::from(v1,v1,V::get()),
			                  ArgSelect<2>::from(v1,v1,V::get()));
	}

	ReturnT operator()(Param1T v1,Param2T v2){
		return FO::operator()(ArgSelect<1>::from(v1,v1,V::get()),
			                  ArgSelect<2>::from(v1,v2,V::get()),
							  ArgSelect<3>::from(v2,v2,V::get()));
	}

	ReturnT operator()(Param1T v1, Param2T v2, Param3T v3){
		return FO::operator()(ArgSelect<1>::from(v1, v1, V::get()),
			                  ArgSelect<2>::from(v1, v2, V::get()),
			                  ArgSelect<3>::from(v2, v3, V::get()),
			                  ArgSelect<4>::from(v3, v3, V::get()));
	}

private:
	template<int A>
	class ArgSelect{
	public:
		//����ڰ�ʵ��ǰ�������
		typedef typename TypeOp<typename IfThenElse<(A<=Params::NumParams),
			                                        FunctorParam<Params,A>,
													FunctorParam<Params,A-1>
		                                           >::ResultT::Type
		                       >::RefT NoSkipT;

		//����ڰ�ʵ�κ��������
		typedef typename TypeOp<typename IfThenElse<(A>1),
			                                        FunctorParam<Params,A-1>,
													FunctorParam<Params,A>
		                                           >::ResultT::Type
		                       >::RefT SkipT;

		//�󶨲���������
		typedef typename TypeOp<typename V::ValueT>::RefT BindT;

		//����������ͬ���࣬��ʵ������ѡ��
		class NoSkip{
		public:
			static NoSkipT select(SkipT prev_arg, NoSkipT arg, BindT bound_val){  return arg; }
		};

		class Skip{
		public:
			static SkipT select(SkipT prev_arg, NoSkipT arg, BindT bound_val){ return prev_arg; }
		};

		class Bind{
		public:
			static BindT select(SkipT prev_arg, NoSkip arg, BindT bound_val){ return bound_val; }
		};

		//�ⲿʵ�ʵ��õ�ѡ����
		typedef typename SignSelect<A-P, NoSkipT, BindT, SkipT>::ResultT ReturnT;
		typedef typename SignSelect<A-P, NoSkip, Bind, Skip>::ResultT  SelectedT;

		static ReturnT from(SkipT prev_arg,NoSkipT arg,BindT bound_val){
			return SelectedT::select(prev_arg,arg,bound_val);
		}
	};
};

#endif//BINDER_1_H
