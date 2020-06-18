# 1 const 修饰变量

```c++
const int a;			// a是一个常量
int const a;			// 同上

const int *p;			// 常量指针
int const *p;			// 常量指针，*p无法作为左值

int *const p;			// 指针常量， p无法作为左值

const int *const p;		// 既是常量指针又是指针常量；p、*p均无法作为左值
```

**ps：当函数接接收一个不会改变的参数时，加上const修饰**

# 2 