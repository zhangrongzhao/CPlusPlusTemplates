#include "../stdafx.h"

#ifndef BINDER_1_H
#define BINDER_1_H

#include "BoundVal.h"
#include "BinderParams.h"
#include "..\Traits\ForwardParam.h"

template<typename FO,int P,typename V>
class Binder:private FO,private V{//空基类优化，避免没有必要的内存开销
public:
	//因为一个参数已经绑定啦，所以这里减去一个参数个数
	enum{ NumParams = FO::NumParams - 1 };

	//返回类型：仿函数的返回类型
	typedef typename FO::ReturnT ReturnT;

	//参数类型
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
	//构造函数，保存仿函数和特定值
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
	//函数调用
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
		//针对于绑定实参前面的类型
		typedef typename TypeOp<typename IfThenElse<(A<=Params::NumParams),
			                                        FunctorParam<Params,A>,
													FunctorParam<Params,A-1>
		                                           >::ResultT::Type
		                       >::RefT NoSkipT;

		//针对于绑定实参后面的类型
		typedef typename TypeOp<typename IfThenElse<(A>1),
			                                        FunctorParam<Params,A-1>,
													FunctorParam<Params,A>
		                                           >::ResultT::Type
		                       >::RefT SkipT;

		//绑定参数的类型
		typedef typename TypeOp<typename V::ValueT>::RefT BindT;

		//借助三个不同的类，来实现三种选择
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

		//外部实际调用的选择函数
		typedef typename SignSelect<A-P, NoSkipT, BindT, SkipT>::ResultT ReturnT;
		typedef typename SignSelect<A-P, NoSkip, Bind, Skip>::ResultT  SelectedT;

		static ReturnT from(SkipT prev_arg,NoSkipT arg,BindT bound_val){
			return SelectedT::select(prev_arg,arg,bound_val);
		}
	};
};

#endif//BINDER_1_H
