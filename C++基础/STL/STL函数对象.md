# 1 函数对象

**本质：**函数对象(仿函数)是一个**类**，不是一个函数

==STL把函数对象作用在相关的函数中，如sort、find_if等==



## 1.1 概念

* 重载**函数调用操作符**的类，其实例化的对象常称为**函数对象**
* **函数对象**使用重载的()时，行为类似函数调用，也叫**仿函数**



## 1.2 使用函数对象

**特点：**

* （1）函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
* （2）函数对象超出普通函数的概念，函数对象可以使用自己的成员变量
* （3）函数对象可以作为参数传递

```c++
#include <string>

class MyAdd
{
public :
	int operator()(string str) // 重载()运算符
	{
		cout << str << endl;
	}
    int cout=2;
};

void doPrint(MyPrint &mp , string test)
{
	mp(test);
}

void test01()
{
	MyAdd myAdd;
	myAdd("hello world"); 	 // （1）调用函数对象
    int a = myAdd.cout; 	 // （2）可以调用成员变量
	MyAdd myAdd1;
    doPrint(myAdd1, "hi..."); // （3）可以作为参数传递
}
```



# 2 谓词

对于仿函数而言：

* 返回bool类型的仿函数称为**谓词**
* 如果operator()接受一个参数，那么叫做一元谓词
* 如果operator()接受两个参数，那么叫做二元谓词



## 2.1 一元谓词

```c++
//一元谓词
struct GreaterFive{
	bool operator()(int val) { // 只有一个参数
		return val > 5;
	}
};

void test01() {
	vector<int> v;
    //使用函数对象改变算法策略，寻找值大于5的元素
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
}
```



## 2.2 二元谓词

```c++
//二元谓词
class MyCompare
{
public:
	bool operator()(int num1, int num2)
	{
		return num1 > num2;
	}
};
vector<int> v;
//使用函数对象改变算法策略，排序从大到小
sort(v.begin(), v.end(), MyCompare());
```



# 3 内建函数对象

头文件：`<functional>`

STL中的内建函数对象本质是**类模板**，使用时需要显式指定参数类型



## 3.1 算术仿函数

**功能描述：**

* 实现四则运算
* 其中negate是一元运算，其他都是二元运算



**仿函数原型：**

* `template<class T> T plus<T>`                //加法仿函数
* `template<class T> T minus<T>`              //减法仿函数
* `template<class T> T multiplies<T>`    //乘法仿函数
* `template<class T> T divides<T>`         //除法仿函数
* `template<class T> T modulus<T>`         //取模仿函数
* `template<class T> T negate<T>`           //取反仿函数



```c++
plus<int> p;
cout << p(10, 20) << endl; // 30

negate<int> n;
cout << n(50) << endl; // 50取反
```



## 3.2 关系仿函数

**功能描述：**

- 实现关系对比



**仿函数原型：**

* `template<class T> bool equal_to<T>`                    //等于
* `template<class T> bool not_equal_to<T>`            //不等于
* `template<class T> bool greater<T>`                      //大于
* `template<class T> bool greater_equal<T>`          //大于等于
* `template<class T> bool less<T>`                           //小于
* `template<class T> bool less_equal<T>`               //小于等于



```c++
class MyCompare
{
public:
	bool operator()(int v1,int v2)
	{
		return v1 > v2;
	}
};
vector<int> v;
//自己实现仿函数
//sort(v.begin(), v.end(), MyCompare());
//STL内建仿函数  大于仿函数
sort(v.begin(), v.end(), greater<int>());
```

