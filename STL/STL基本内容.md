# 1 STL基本概念

STL（Standard Template Library），标准模板库

STL几乎所有的代码都采用了模板类或者模板函数

STL分为以下六大组件：

- 容器：用于存放数据的各种数据结构，如vector, list, deque, set, map, string等
- 算法：处理数据的常用算法，如sort, find, copy, for_each等
- 迭代器：类似指针
- 仿函数：类似函数，可作为算法的某种策略
- 适配器：一种用来修饰容器、仿函数、迭代器接口的东西
- 空间适配器：负责空间的配置与管理



# 2 容器

STL容器就是实现的一些数据结构，如：数组、链表、栈、队列、集合、映射表等

这些容器分为**顺序容器**和**关联容器**



顺序容器：vector, string, deque, list, forward_list, array

关联容器：pair, set, map



## 2.1 容器通用操作

假设有容器C，一般都有会有以下几种公共操作：

### 2.1.1 定义和初始化

```c++
C c; 			// 默认构造函数
C c1(c2);   	// 拷贝构造函数
C c{a,b,c}; 	// 列表初始化
C c(n, elem);   // 重复n个elem
```

### 2.1.2 大小

```c++
c.size();		// c中元素个数
c.max_size();	// c可保存的最大元素数目
c.empty();		// 若c中有元素，返回false；否则返回true

c.resize(n);	// 调整c的大小为n个元素，多出的元素被丢弃
c.resize(n,t);	// 调整c的大小为n个元素，元素初始化为t
```

### 2.1.3 获取迭代器

```c++
c.begin();				// 返回指向c的首元素的迭代器
c.end();				// 返回指向c的尾元素后一个位置的迭代器
c.cbegin();c.cend();	// 返回const_iterator
```

### 2.1.4 赋值与swap

```c++
c1=c2;			// c2赋值给c1
c1={a,b,c};		// 赋值
c1.swap(c2);	// 交换容器c1,c2的内容
swap(c1,c2);	// 同上
```

### 2.1.5 添加、插入与删除

在不同的容器，这些操作的参数列表有区别

```c++
c.push_back(elem);	// 在尾部添加元素
c.push_front(elem);	// 在头部添加元素（只支持list, forward_list, deque）

c.insert(args);		// 将 args 中的元素插入到c中 

c.pop_back();		// 删除c中尾元素
c.pop_front();		// 删除c中首元素（只支持list, forward_list, deque）

c.erase(args);		// 删除 args 指定的元素	
c.clear();			// 清空c，返回void
```

### 2.1.6 访问元素

```c++
c.back();	// 返回c中尾元素的引用
c.front();	// 返回c中首元素的引用
c[n];		// 使用下标访问
```



# 3 迭代器 

迭代器是用来访问STL容器的机制，可以像指针一样间接访问对象

可以使用迭代器的容器有：string（严格来说不是容器）、vector



## 3.1 获取迭代器

前面提到，容器是一个类模板，类就会有成员变量和成员函数

STL的容器中，大部分容器都支持迭代器机制：

- 这些容器都拥有`begin`和`end`这两个成员变量
- 这两个成员变量负责返回指向**第一个元素**和**最后一个元素下一位置**的迭代器

就相当于，有两个指针，分别指向了容器的**头部**和**尾部下一位置**



```c++
vector<int> v;
v.push_back(1);
v.push_back(2);
vector<int>::iterator it = v.begin(); // 需要指定作用域
auto it = v.end(); //用 auto 自动获取数据类型
```



## 3.2 迭代器类型

- iterator：可读可写迭代器
- const_iterator：可读不可写迭代器，类似常量指针



使用`begin`和`end`获取迭代器时，一般看容器的类型是什么，迭代器类型就是什么，如：

`vector<int> v1`：使用`begin`、`end`返回的迭代器类型是iterator，说明v1可读可写

`const vector<int> v2`：const修饰迭代器，v2是个常量，返回的迭代器类型是const_iterator，说明v2可读不可写



## 3.3 迭代器操作

迭代器访问机制类似于指针，因此可以使用`*`解引用或`->`箭头运算符来访问容器对象

