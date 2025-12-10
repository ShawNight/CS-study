# C++ Primer 学习笔记

### 第一章 开始

##### 1、基本语法

- `iostream` 头文件：输入输出流
- `main()` 函数：程序入口
- `cout` 和 `cin`：标准输出输入
- `<<` 和 `>>`：输出输入运算符

### 第二章 变量和基本类型

##### 1、基本数据类型

- 算术类型：`int, double, char, bool` 等
- 空类型：`void`
- 复合类型：指针、引用、数组

##### 2、变量定义和声明

- 定义：分配存储空间
- 声明：说明类型和名称
- `extern` 关键字用于声明

### 第三章 字符串、向量和数组

##### 1、string 类型

```cpp
string s = "hello";
s.size();  // 长度
s.empty(); // 是否为空
```

##### 2、vector 容器

```cpp
vector<int> vec = {1, 2, 3};
vec.push_back(4);  // 添加元素
vec.size();       // 元素个数
```

##### 3、迭代器

- 容器的访问工具
- `begin()` 和 `end()` 获取迭代器范围

### 第四章 表达式

##### 1、基本运算符

- 算术运算符：`+ - * / %`
- 关系运算符：`== != < > <= >=`
- 逻辑运算符：`&& || !`

##### 2、类型转换

- 隐式转换和显式转换
- `static_cast`、`const_cast` 等

### 第五章 语句

##### 1、条件语句

- `if-else` 语句
- `switch` 语句

##### 2、循环语句

- `while` 循环
- `for` 循环
- `do-while` 循环
- `break` 和 `continue`

### 第六章 函数

##### 1、函数基础

```cpp
int add(int a, int b) {
    return a + b;
}
```

##### 2、参数传递

- 值传递
- 引用传递
- 指针传递

##### 3、函数重载

- 相同函数名，不同参数列表

### 第七章 类

##### 1、类定义

```cpp
class Sales_data {
public:
    string isbn() const { return bookNo; }
private:
    string bookNo;
    unsigned units_sold = 0;
};
```

##### 2、构造函数

- 默认构造函数
- 委托构造函数
- 拷贝构造函数

### 第八章 IO 库

##### 1、iostream

- `cin`、`cout`、`cerr`、`clog`

##### 2、fstream

- 文件读写操作
- `ifstream`、`ofstream`

##### 3、sstream

- 字符串流操作
- `istringstream`、`ostringstream`

### 第九章 顺序容器

##### 1、容器类型

- `vector`：可变大小数组
- `list`：双向链表
- `deque`：双端队列
- `array`、`forward_list`

##### 2、容器操作

```cpp
container.push_back(elem);   // 尾部插入
container.insert(pos, elem); // 指定位置插入
container.erase(pos);       // 删除元素
```

### 第十章 泛型算法

##### 1、只读算法

accumulated 定义在头文件 numeric 中

```C++
int sum=accumulate(vec.cbegin(),vec.cend(),0)
```

### 第十一章 关联容器

##### **a、关联容器类型包括**

按关键字有序保存元素：保存在 map 与 set 头文件中

> ​ _map,set,multimap,multiset_

无序集合：保存在 unordered_map 与 unordered_set 头文件中

> ​ _unordered_map,unordered_set,unordered_multimap,unordered_multiset_

##### **b、关联容器类型要求**

定义有序关联容器时对键的类型有要求，键必须有<方法才能定义（排序使用),例如：可以定义 `vector<int>::iterator` 到 `int` 的 map，但是不能定义 `list<int>::iterator` 到 `int` 的 map。因为 map 的键必须实现 `<` 操作，list 的迭代器不支持比较运算。

##### **c、pair 类型**

定义在 utility 标准库中

##### **d、关联容器操作**

key_type 此容器关键字类型

mapped_type 每个关键字关联的类型

value_type 对于 set，与 key_type 相同；对于 map，为 pair<const key_type,mapped_type>

##### **e、关联容器迭代器**

```C++
auto map_it =word_count.begin();
cout<<map_it->first<<" "<<map_it->second;
set<int> iset={0,1,2,3,4,5};
auto set_it=iset.begin();
cout<<*set_it<<endl;
```

<u>通常不对关联容器使用算法</u>，使用关联容器自定义的 find 成员比使用泛型 find 算法快很多。

##### **f、关联容器操作**

```C++
c.insert(V)
```

有序容器插入成功返回一个**pair**，first 成员是一个迭代器，指向被插入的元素；second 成员是一个 bool 值，表示插入是否成功。

无序容器插入则返回插入元素的**迭代器**，因为插入始终是成功的。

```C++
c.erase(k); // k为关键字,返回size_type，指出删除元素的数量
c.erase(p); //p为迭代器，返回p之后的元素迭代器
c.erase(b,e);  //删除迭代器b,e之间的元素，返回e
```

##### **g、map 的下标操作**

```C++
c[k]		//返回关键字为k的元素；如果k不在c中，则添加一个关键字为k的元素
c.at(k)		//访问关键字为k的元素，带参数检查；如不存在，抛出out_of_range异常
```

set 类型不支持下标操作，由于 set 只有关键字没有值。

##### h、访问元素

```C++
c.find(k)
c.count(k)
c.lower_bound(k)
c.upper_bound(k)
c.equal_range(k)
```

##### i、无序容器

新标准库定义了 4 个无序容器，无序容器不是使用比较运算符来组织元素，而是使用一个哈希函数和关键字类型的==运算符来组织元素的。

无序容器的桶操作：

```C++
//桶接口
c.bucket_count()			//正在使用的桶的数目
c.max_bucket_count()		//容器能容纳的最多的桶的数量
c.bucket_size(n)			//第n个桶中有多少个元素
c.bucket(k)					//关键字为k的元素在哪个桶中
//桶迭代
local_iterator
const_local_iterator
//哈希策略
c.load_factor()				//每个桶的平均数量
c.max_load_factor()			//c试图维护的平均桶的大小，返回float值，c会在需要时添加新的桶，以使得load_factor<=max
c.rehash(n)					//重新存储，使得bucket_count>=n
c.reverse(n)				//重组存储，使得c可以保存n个元素且不必rehash
```

### 第十二章 关联容器

##### 1、shared_ptr 类

**概述**
`shared_ptr` 是一种智能指针，允许多个指针指向同一个对象。它通过引用计数来管理对象的生命周期。

**基本用法**

```cpp
// 创建 shared_ptr
shared_ptr<int> p1 = make_shared<int>(42);  // 推荐
shared_ptr<int> p2(new int(42));  // 不推荐

// 复制和赋值
shared_ptr<int> p3 = p1;  // 引用计数+1
p2 = p1;  // 引用计数+1，p2原来指向的对象引用计数-1

// 访问对象
cout << *p1 << endl;  // 42
cout << p1.get() << endl;  // 获取原始指针
```

**引用计数操作**

```cpp
p1.use_count();  // 返回引用计数值
p1.unique();     // 检查是否唯一拥有者
```

**注意事项**

- 避免 `shared_ptr` 循环引用，会导致内存泄漏
- 不要管理栈对象的指针
- 使用 `make_shared` 更高效和安全

##### 2、unique_ptr 类

**概述**
`unique_ptr` 独占所指向的对象，同一时间只能有一个 `unique_ptr` 指向给定对象。

**基本用法**

```cpp
// 创建 unique_ptr
unique_ptr<int> p1(new int(42));
auto p2 = make_unique<int>(42);  // C++14

// 移动语义
unique_ptr<int> p3 = move(p1);  // p1 变为空
// unique_ptr<int> p4 = p1;      // 错误：不能复制

// 访问对象
cout << *p3 << endl;  // 42
cout << p3.get() << endl;  // 获取原始指针
```

**自定义删除器**

```cpp
auto deleter = [](int* p) {
    cout << "Deleting int" << endl;
    delete p;
};
unique_ptr<int, decltype(deleter)> p(new int(42), deleter);
```

**与数组配合**

```cpp
unique_ptr<int[]> arr(new int[10]{1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
arr[0] = 100;  // 可以使用下标访问
```

##### 3、weak_ptr 类

**概述**
`weak_ptr` 是一种不控制所指向对象生命周期的智能指针，它指向由 `shared_ptr` 管理的对象。

**基本用法**

```cpp
// 创建 weak_ptr
shared_ptr<int> sp = make_shared<int>(42);
weak_ptr<int> wp = sp;  // 不影响引用计数

// 检查有效性
if (!wp.expired()) {
    // 转换为 shared_ptr
    shared_ptr<int> sp2 = wp.lock();
    cout << *sp2 << endl;
}
```

**解决循环引用问题**

```cpp
struct Node {
    shared_ptr<Node> next;
    weak_ptr<Node> parent;  // 使用 weak_ptr 避免循环引用
};
```

**观察者模式应用**

- `weak_ptr` 适合实现观察者模式
- 可以安全地检查对象是否仍然存在

##### 4、allocator 类

**概述**
`allocator` 类模板将内存分配和对象构造分离，提供更灵活的内存管理。

**基本用法**

```cpp
// 创建分配器
allocator<string> alloc;

// 分配未构造的内存
string* p = alloc.allocate(10);  // 分配10个string的空间

// 构造对象
alloc.construct(p, "hello");     // 在p位置构造string
alloc.construct(p + 1, "world"); // 在p+1位置构造string

// 使用对象
cout << p[0] << " " << p[1] << endl;

// 销毁对象
alloc.destroy(p);      // 销毁p位置的string
alloc.destroy(p + 1);  // 销毁p+1位置的string

// 释放内存
alloc.deallocate(p, 10);  // 释放10个string的空间
```

**高级用法**

```cpp
// 拷贝和填充未初始化内存
vector<int> vec = {1, 2, 3, 4, 5};
int* p = alloc.allocate(vec.size());

uninitialized_copy(vec.begin(), vec.end(), p);
uninitialized_fill_n(p + vec.size(), 5, 0);  // 填充5个0
```

**自定义分配器**

```cpp
template <typename T>
class MyAllocator {
public:
    using value_type = T;

    T* allocate(size_t n) {
        return static_cast<T*>(::operator new(n * sizeof(T)));
    }

    void deallocate(T* p, size_t) {
        ::operator delete(p);
    }
};
```

**应用场景**

- 容器内部实现
- 性能敏感的内存管理
- 需要精确控制内存分配的场景

### 第十三章 拷贝控制

```cpp
#include <string>

class HasPtr {
public:
    // 构造函数：初始化字符串指针、整数值和引用计数
    HasPtr(const std::string &s = std::string()) : 
        ps(new std::string(s)), i(0), use(new size_t(1)) { }
    
    // 拷贝构造函数：共享资源，增加引用计数
    HasPtr(const HasPtr &hp) : 
        ps(hp.ps), i(hp.i), use(hp.use) { 
        ++*use;  // 引用计数+1
    }
    
    // 拷贝赋值运算符：处理引用计数的变化
    HasPtr& operator=(const HasPtr &rhs) {
        ++*rhs.use;  // 增加右侧对象的引用计数
        if (--*use == 0) {  // 减少当前对象的引用计数
            delete ps;      // 如果引用计数为0，释放资源
            delete use;
        }
        ps = rhs.ps;   // 共享右侧对象的资源
        i = rhs.i;
        use = rhs.use;
        return *this;
    }
    
    // 析构函数：减少引用计数，必要时释放资源
    ~HasPtr() {
        if (--*use == 0) {  // 如果这是最后一个对象
            delete ps;      // 释放字符串
            delete use;      // 释放引用计数器
        }
    }
private:
    std::string *ps;  // 指向动态分配的string
    int i;            // 整数值
    size_t *use;      // 引用计数器，指向动态分配的size_t
};
```

**关键设计要点：**

1. **引用计数机制**：使用 `use` 指针记录共享同一资源的对象数量
2. **安全的拷贝**：拷贝构造函数增加引用计数，避免重复释放
3. **正确处理自赋值**：拷贝赋值运算符先增加右侧引用计数，再减少左侧
4. **资源管理**：析构函数在引用计数为0时释放资源
5. **共享语义**：多个对象可以安全共享同一个字符串资源

这个实现展示了如何手动实现类似智能指针的引用计数机制，是理解 `shared_ptr` 工作原理的好例子。
