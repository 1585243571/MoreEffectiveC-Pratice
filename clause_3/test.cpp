/*************************************************************************
	> File Name: test.cpp
	> Author: zhangning
	> Mail: amoscykl@163.com 
	> Created Time: 2019年12月17日 星期二 18时45分20秒
 ************************************************************************/

#include<iostream>
using namespace std;
class base{

	public:
		int a_ =12;

};

class drive:public base{

	public:
		int b_=14;

};


/*
 *
 * 该准则讲了一个问题：
 *					不要以多太处理数组,例如 base buff[12],定义一个数组都打印他的成员变量a_数值发现都是12,如果用drive buff[12]传入打印就会出现意想不到的问题，这个是因为在数组寻址的时候其实是
 *					数组首地址加上i由于base和driver的跨度不同也就是大小所以肯定在打印drive里的元素时候会越界到下一个对象的内存
 * 
 *
 * */


void p(base array[])
{
	for(int i=0;i<12;i++){
	cout<<array[i].a_<<endl;
}}

int main()
{
	base a[12];
	p(a);
	cout<<"-------------------"<<endl;
	drive b[12];
	p(b);


}
