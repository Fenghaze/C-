# 1 STL常用算法

头文件：`<algorithm>`，`<functional>`， `<numeric>`



* `<algorithm>`是所有STL头文件中最大的一个，范围涉及到比较、 交换、查找、遍历操作、复制、修改等等
* `<numeric>`体积很小，只包括几个在序列上面进行简单数学运算的模板函数
* `<functional>`定义了一些模板类,用以声明函数对象。



使用这些造好的轮子，使得对STL容器的操作变得更加方便快捷......



# 2 遍历算法

## 2.1 ==for_each==

功能：遍历容器

`void for_each(iterator begin, iterator end, _func)`

- begin：开始迭代器
- end：结束迭代器
- _func：普通函数或函数对象

```c++
#include <algorithm>
#include <vector>

//普通函数
void print01(int val) 
{
	cout << val << " ";
}
//函数对象
class print02 
{
 public:
	void operator()(int val) 
	{
		cout << val << " ";
	}
};

//for_each算法基本用法
void test01() {

	vector<int> v;
	for (int i = 0; i < 10; i++) 
	{
		v.push_back(i);
	}

	//遍历算法
	for_each(v.begin(), v.end(), print01);
	cout << endl;

	for_each(v.begin(), v.end(), print02());
	cout << endl;
}
```



## 2.2 transform

功能：将容器1中的元素搬运到容器2中

搬运前，容器2必须要**提前开辟空间**，否则无法正常搬运

`void transform(iterator begin1, iterator end1, iterator begin2, _func)`

- begin1：容器1开始迭代器
- end1：容器1结束迭代器
- begin2：容器2开始迭代器
- _func：普通函数或函数对象



# 3 查找、统计算法

**算法简介：**

- `find`                     //查找元素
- `find_if`               //按条件查找元素
- `adjacent_find`    //查找相邻重复元素
- `binary_search`    //二分查找法
- `count`                   //统计元素个数
- `count_if`             //按条件统计元素个数



## 3.1 find

查找指定元素，找到返回指定元素的迭代器，找不到返回结束迭代器end()

`iterator find(iterator begin, iterator end, value);`

- begin：开始迭代器
-  end：结束迭代器
-  value：查找的元素



## 3.2 find_if

按条件查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

`iterator find_if(iterator begin, iterator end, _Pred);  `

- begin：开始迭代器
-  end：结束迭代器
- _Pred ：函数或者谓词（返回bool类型的仿函数）



## 3.3 adjacent_find

查找相邻重复元素,返回相邻元素的第一个位置的迭代器

`iterator adjacent_find(iterator beg, iterator end);`

- begin：开始迭代器
-  end：结束迭代器



## 3.4 binary_search

二分查找的前提条件：容器中元素有序



二分查找指定的元素，查到 返回true  否则false

`bool binary_search(iterator begin, iterator end, value);  `

- begin：开始迭代器
-  end：结束迭代器
-  value：查找的元素



## 3.5 count

统计元素个数

`int count(iterator begin, iterator end, value);`

- begin：开始迭代器
-  end：结束迭代器
-  value：查找的元素



**当要统计自定义数据类型时，类中需要重载`==`运算符进行判断**

```c++
#include <algorithm>
#include <vector>

//自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	bool operator==(const Person & p)
	{
		if (this->m_Age == p.m_Age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	string m_Name;
	int m_Age;
};

void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);

	v.push_back(p1);
	v.push_back(p2);
    
    Person p("诸葛亮",35);

	int num = count(v.begin(), v.end(), p);
	cout << "num = " << num << endl;
}
```



## 3.6 count_if

按条件统计元素个数

`int count_if(iterator begin, iterator end, _Pred);  `

- begin：开始迭代器
-  end：结束迭代器
-  _Pred：仿函数

```c++
//自定义数据类型
class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

class AgeLess35
{
public:
	bool operator()(const Person &p)
	{
		return p.m_Age < 35;
	}
};
void test02()
{
	vector<Person> v;

	Person p1("刘备", 35);
	Person p2("关羽", 35);
	v.push_back(p1);
	v.push_back(p2);
    
	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "小于35岁的个数：" << num << endl;
}
```



# 4 排序算法

- `sort`             //对容器内元素进行排序
- `random_shuffle`   //洗牌   指定范围内的元素随机调整次序
- `merge `           // 容器元素合并，并存储到另一容器中
- `reverse`       // 反转指定范围的元素



## 4.1 ==sort==

按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

`iterator sort(iterator begin, iterator end, _Pred);  `

- begin：开始迭代器
-  end：结束迭代器
-  _Pred：仿函数



## 4.2 random_shuffle

shuffle：洗牌，指定范围内的元素随机调整次序

`void random_shuffle(iterator begin, iterator end);  `

- begin：开始迭代器
- end：结束迭代器



random_shuffle洗牌算法比较实用，使用时记得加随机数种子

```c++
srand((unsigned int)time(NULL)); // 随机数种子
vector<int> v;
//打乱顺序
random_shuffle(v.begin(), v.end());
```



## 4.3 merge

两个容器元素合并，并存储到另一容器中

前提：两个容器必须是**有序**的



`void merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

- beg1：容器1开始迭代器
- end1：容器1结束迭代器
- beg2：容器2开始迭代器
- end2：容器2结束迭代器
- dest：目标容器开始迭代器



## 4.4 reverse

将容器内的元素进行反转

`void reverse(iterator begin, iterator end);`

- begin：开始迭代器
- end：结束迭代器



# 5 拷贝替换算法

- `copy`                      // 容器内指定范围的元素拷贝到另一容器中
- `replace`                // 将容器内指定范围的旧元素修改为新元素
- `replace_if `          // 容器内指定范围满足条件的元素替换为新元素
- `swap`                     // 互换两个容器的元素



## 5.1 copy

容器内指定范围的元素拷贝到目标容器中

利用copy算法在拷贝时，目标容器记得**提前开辟空间**：`v2.resize(v1.size());`

`void copy(iterator beg, iterator end, iterator dest);  `

- beg：开始迭代器
- end： 结束迭代器
- dest ：目标起始迭代器



## 5.2 replace

将容器内指定范围的旧元素修改为新元素

`void replace(iterator beg, iterator end, oldvalue, newvalue);  `

- beg：开始迭代器
- end：结束迭代器
- oldvalue：旧元素
- newvalue：新元素



## 5.3 replace_if

将区间内满足条件的元素，替换成指定元素

`void replace_if(iterator beg, iterator end, _pred, newvalue);  `

- beg：开始迭代器
- end：结束迭代器
- _pred：仿函数
- newvalue：替换的新元素



## 5.4 swap

互换两个**相同类型**的容器的元素

`void swap(container v1, container v2);`

- v1：容器1
- v2：容器2



# 6 算术生成算法

头文件：`<numeric>`

- `accumulate`      // 计算容器元素累计总和
- `fill`                 // 向容器中添加元素



## 6.1 accumulate

计算区间内容器元素累计总和

`int accumulate(iterator beg, iterator end, value);  `

- beg：开始迭代器
- end：结束迭代器
- value：起始值



## 6.2 fill

向容器指定区间内填充指定的元素

`void fill(iterator beg, iterator end, value);  `

- beg：开始迭代器
- end：结束迭代器
- value：要填充的值



# 7 求集合算法

- `set_intersection`          // 求两个容器的交集，公共元素

- `set_union`                       // 求两个容器的并集，合并

- `set_difference `              // 求两个容器的差集



## 7.1 set_intersection

求两个集合的交集，将交集放到一个新的容器中，返回新容器最后一个元素的迭代器地址

**注意:**

- **两个集合必须是有序序列**
- 新容器需要开辟空间，且空间大小取两个容器的size最小值

`iterator set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

- beg1：容器1开始迭代器
- end1：容器1结束迭代器
- beg2：容器2开始迭代器
- end2：容器2结束迭代器
- dest：目标容器开始迭代器

```c++
#include <vector>
#include <algorithm>
void test01()
{
	vector<int> v1;
	vector<int> v2;
	vector<int> vTarget;
	//取两个里面较小的值给目标容器开辟空间
	vTarget.resize(min(v1.size(), v2.size()));

	//返回目标容器的最后一个元素的迭代器地址
	vector<int>::iterator itEnd = 
        set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());
}
```



## 7.2 set_union

求两个集合的合集，将合集放到一个新的容器中，返回新容器最后一个元素的迭代器地址

**注意:**

- **两个集合必须是有序序列**
- 新容器需要开辟空间，且空间大小为两个容器size之和

`iterator set_union(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

- beg1：容器1开始迭代器
- end1：容器1结束迭代器
- beg2：容器2开始迭代器
- end2：容器2结束迭代器
- dest：目标容器开始迭代器



## 7.3 set_difference

求两个集合的差集，将差集放到一个新的容器中，返回新容器最后一个元素的迭代器地址

**注意:**

- **两个集合必须是有序序列**
- 新容器需要开辟空间，且空间大小取两个容器size的最大值

`iterator set_difference(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);  `

- beg1：容器1开始迭代器
- end1：容器1结束迭代器
- beg2：容器2开始迭代器
- end2：容器2结束迭代器
- dest：目标容器开始迭代器