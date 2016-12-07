#include "../stdafx.h"

#ifndef BRIDGE_PATTERN_H
#define BRIDGE_PATTERN_H
namespace Common{
	class Implementation{
	public:
		virtual void operationA() = 0;
		virtual void operationB() = 0;
		virtual void operationC() = 0;
	};

	class ImplementationA :public Implementation{
	public:
		void operationA(){ }
		void operationB(){ }
		void operationC(){ }
	};

	class ImplementationB :public Implementation{
	public:
		void operationA(){ }
		void operationB(){ }
		void operationC(){ }
	};
}
namespace DynamicPolymorphism{
	using namespace Common;

	class Interface{
	private:
		Common::Implementation* body;
	public:
		void operationA(){
			body->operationA();
		}
		void operationB(){
			body->operationB();
			body->operationC();
		}
	};

}
namespace StaticPolymorphism{
	using namespace Common;

	template<typename Impl>
	class Interface{
	private:
		Impl* body;
	public:
		void operationA(){
			body->operationA();
		}
		void operationB(){
			body->operationB();
			body->operationC();
		}
	};

}
namespace StandardTemplateLibrary{
   template<typename Iterator>
   Iterator max_element(Iterator begin,Iterator end){
       
   }

   template<typename T>
   class Vector{
   public:
	   typedef T const_iterator;
	   const_iterator begin() const;
	   const_iterator end() const;
   };

   template<typename T>
   class List{
   public:
	   typedef T const_iterator;
	   const_iterator begin() const;
	   const_iterator end() const;
   };

   template<typename T>
   void print_max(T const& container){
	   typename T::const_iterator pos;
	   pos = max_element(pos.begin(),pos.end());
   }
}
#endif//BRIDGE_PATTERN_H