/*************************************************************************
  > File Name: test.cpp
  > Author: zhangning
  > Mail: amoscykl@163.com 
  > Created Time: 2019年11月07日 星期四 20时56分28秒
 ************************************************************************/

#include<iostream>
#include <stdlib.h>
using namespace std;
/*
 *const_cast:
 *		去除指针或引用的const属性
 *		转化常量指针或引用为非常量的指针或引用，并仍然指向原来的对象
 *		一般用于修改指针，如const char *ptr;
 *static_cast:
 *		用于数据类型的转换,基本上拥有c旧式转化的威力,与意义，以及相同的限制，例如不可以将int，double，转成pointer，或者转成struct，并且他不能移除表达式的常量属性，因为有上面const_cast的存在吧。
 *		转换数据类型，由于没有运行时的类型检查所以不保证转换的安全性，所以适用于静态类型的转换
 *		类的上下行转化，由于没有运行时的检查，所以向下转换时不安全，因为派生类的范围一般比较大你将基类的指针变为派生类的指针只是将指针跨度变大但是其指向的内容还是基类的对象属性容易发生越界。
 *dynamic_cast:
 *		安全的上下行转换
 *		上行转换(子类到基类指针的转换),dynamic_cast转换成功。而向下转换的时候(基类到子类指针的转换)，dynamic_cast转换时也不报错，但是返回的是NULL，NULL说明进行了运行时类型的检查(RTTI),是安全的不会
 *指向未知的内存。
 *
 *
 *reinterpret_cast:
 *		进行无关类型的转化
 *		用于在任意的指针或引用间的转换指针和足够大的整形之间的转换，整形到指针的转换，
 *
 *
 *
 * */

class Base{
	public:
		Base() {}
		~Base() {}
		void print() {
			std::cout << "This is Base" << endl;
		}

		virtual void virtual_foo() {}
};

class Derived : public Base{
	public:
		Derived() {}
		~Derived() {}
		void print() {
			std::cout << "This is Derived" << endl;
		}

		virtual void virtual_foo() {}
};
int main()
{
#if  0
	cout << "const_cast测试" << endl;
	int ary[4] = { 1, 2, 3, 4 };
	const int *c_ary = ary;
	//c_ary[0] = 5;//错误，常量不能改变
	int *ary2 = const_cast<int*>(c_ary);//const_cast将常量指针转化为非常量指针
	ary2[0] = 5;//正确

	int a = 2;
	const int &c_a = a;
	//c_a = 5;//错误，常量不能改变
	int &a2 = const_cast<int&>(c_a);//const_cast将常量引用转化为非常量引用
	a2 = 5;//正确

	const int c_val = 3;
	int &ref_val = const_cast<int&>(c_val);//得到去const的引用
	int *ptr_val = const_cast<int*>(&c_val);//得到去const的指针

	system("./pause");


#elif 0
	cout << "static_cast测试" << endl;
	float f_pi = 3.1415;
	int i_pi = static_cast<int>(f_pi);

	//类的上下行转换
	class Base{
	};
	class Derived :public Base{
	};

	//上行转换 Derived->Base，安全
	Derived derived;
	Base *base_ptr = static_cast<Base*>(&derived);

	//下行转换 Base->Derived，由于没有动态类型检查，编译能通过但不安全
	Base base;
	Derived *derived_ptr = static_cast<Derived*>(&base);

	system("./pause");


#elif 0
	cout << "dynamic_cast测试" << endl;
	//上行转换 Derived->Base
	Derived *derived = new Derived();
	derived->print();//输出This is Derived
	Base* deri2base = dynamic_cast<Base*>(derived);
	if (deri2base != nullptr){
		derived->print();//输出This is Derived
	}

	//下行转换 Base->Derived
	Base *base = new Base();
	base->print();//输出This is Base
	Derived* base2deri = dynamic_cast<Derived*>(base);
	if (base2deri != nullptr){//base2deri为空，不进行打印
		base2deri->print();
	}

	Base *base2 = new Derived();
	base2->print();//输出This is Base
	//Derived* deri2 = new Base();//错误。不能直接将Base*转换为Derived*，即不能直接下行转换。

	delete derived;
	derived = nullptr;
	delete base;
	base = nullptr;

	system("./pause");

#else 
	int *p = new int(5);
	cout << "p的地址: " << hex << p << endl;//std::hex用于以16进制输出十进制数
	int p_addr = reinterpret_cast<int>(p);
	cout << "p_addr的值： " << hex << p_addr << endl;

	delete p;
	p = nullptr;

	system("./pause");

#endif



}
