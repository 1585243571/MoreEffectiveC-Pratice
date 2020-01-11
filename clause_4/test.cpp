/*************************************************************************
	> File Name: test.cpp
	> Author: zhangning
	> Mail: amoscykl@163.com 
	> Created Time: 2020年01月10日 星期五 21时23分21秒
 ************************************************************************/

#include<iostream>
using namespace std;

class A{
	public:
//		A(){}

		A(int a){}
};

class B:public A{

	public:
		B():A(1){}

};
int main()
{

	// A a[10]; 错误因为没有默认的构造函数
	//解除这个束缚有3种方法
	
	//方法1
	A a[]={A(1),A(2)};
	// 方法 2
	A *a1[10];//指针数组 存放A类 的指针不想要调用构造器
	typedef  A * A_ptr;
	A **a2 = new  A_ptr[10];//用的时候需要给数组里的指针分配内存  该方法很明显浪费了内存用了好多指针，而且很容易忘记释放内层造成内存泄漏
	// 方法3 利用 placement new 提前分配好所需要的内存
	void * ptr =  operator new[](10*sizeof(A));
	A *ptr1 = static_cast<A *>(ptr);
	for(int i = 0; i < 10 ; i++)
	{
		new (&ptr1[i])A(i);
	}
	

	B b;


}
