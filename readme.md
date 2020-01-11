

### 额外c++知识点补充

- __const 介绍__：

  - ```c++
    int a=12;
    const int *ptr = &a;//ptr指向的内容不能被修改  错误例子 *ptr=12;
    int const *ptr1 =&a;//和上面相同
    int * const ptr2 = &a;//赋值以后不能修改指针变量单是可以修改其指向指针的内容
    /************************************/
    const int a=12;
    int *ptr = &a  //错误原因 此时&a的类型是int const *; 正确做法 const int *ptr =&a;
        
    /************************************/
    class A{
    	public:
    	A(){}//提供这个函数即可
    	A print(){};
    };
    //为什么const A  a;只能调用const的修饰的成员函数和const成员变量
    //因为const只能将this指针变成const A *类型而实际上成员函数的完整是A print(A * const this){}所以在调用print函数是时汇出错因为有这样一个错误的操作就是将 const A * 赋值给 A *const;
    int main()
    {
        const A a;//回报错，说用户没有提供一个默认的构造函数，我的理解因为const修饰以后限定了初始化次数为1如果用了系统提供的默认构造函数那末可能导致成员变量后期将不能在被复制
    }
    ```

  - 
