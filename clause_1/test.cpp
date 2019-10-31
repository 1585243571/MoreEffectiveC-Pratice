/*************************************************************************
	> File Name: test.cpp
	> Author: zhangning
	> Mail: amoscykl@163.com 
	> Created Time: 2019年10月31日 星期四 21时37分56秒
 ************************************************************************/

#include<iostream>
using namespace std;

/* pointers 和 references的差异 
 * 1.pointers可以指向不同的对象，而reference 定义完后就只能代表定义时候的对象
 * 2.reference不可以为null他只要定义完就代表一个有效的空间，而pointers未必如果是null我们就可能出现断错误，因此用pointers时候我们需要判读其的有效性而reference不需要
 *
 * 注意：delete ptr;并不会将ptr变为null,所以我们要养成习惯delete完后ptr=null,尽管我们不使他为空他仍然可以被访问，而且不会报错，只不过是一个垃圾直，这个比不报错，更可怕。
 *      还有注意delete null 并不会报错,所以delete完后将其设为null可以防止double free
 * 
 *应用场景
    如果我们指向一个对象后就不在改变那我们就用reference否则选用pointers
 *
 * */

void print(const int *ptr)
{
	if(ptr){
		cout<<*ptr<<endl;
	}
}

void print(const int &ptr)
{
	cout<<ptr<<endl;
}
int main()
{
	int a;
	print(a);
	print(&a);
}
