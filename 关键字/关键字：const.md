# 1 const 修饰变量

```c++
const int a;			// a是一个常量
int const a;			// 同上

const int *p;			// 常量指针
int const *p;			// 常量指针，*p无法作为左值，即无法改变所指向的对象

int *const p;			// 指针常量， p无法作为左值，即无法改变指向

const int *const p;		// 既是常量指针又是指针常量；p、*p均无法作为左值
```

**ps：当函数接收一个只读不写的参数时，加上const修饰**



# 2 const 修饰类成员函数

**当类实例化的对象是常量对象时，只能调用常量成员函数**

```c++
class Person
{
public:
    string str;
	string speak() const 	// 常量成员函数
    {
        return str;
    }
    string eat()			// 普通成员函数
    {
        return str;
    }
}
const Person person;			// 常量对象
string str = person.speak();	// 只能调用常量成员函数
person.eat()					// 报错
```

《C++ Primer》P231：

函数参数列表之后的`const`关键字的作用是：修改隐式`this`指针的类型

首先，`this`指针默认是一个**指针常量（Person  *const this）**，可以指向一个普通的对象

```c++
Person person1;
person1.eat();
/*相当于调用
void eat(Person *const this)	// this的类型与对象类型一致，都是Person
{
	return this->str;
}
*/
```

然而，我们不能把`this`绑定到一个常量对象上（类型不一致）

因此，如果要让常量对象使用某些函数时，需要在函数的参数列表后加上`const`修饰，以确保类型一致

这样，`this`指针就是一个==指向常量的指针常量==了

```c++
const Person person2;
person2.speak();
/*相当于调用
void speak(const Person *const this)	// this的类型与对象类型一致，都是const Person
{
	return this->str;
}
*/
```



