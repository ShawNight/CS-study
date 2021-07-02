# C++ Primer学习笔记

###  第十章 泛型算法

##### 1、只读算法

accumulated定义在头文件numeric中

```C++
int sum=accumulate(vec.cbegin(),vec.cend(),0)
```

### 第十一章 关联容器



##### **a、关联容器类型包括**

按关键字有序保存元素：保存在map与set头文件中

> ​	*map,set,multimap,multiset*

无序集合：保存在unordered_map与unordered_set头文件中

> ​	*unordered_map,unordered_set,unordered_multimap,unordered_multiset*

##### **b、关联容器类型要求**

定义有序关联容器时对键的类型有要求，键必须有<方法才能定义（排序使用),例如：可以定义 `vector<int>::iterator` 到 `int` 的map，但是不能定义 `list<int>::iterator` 到 `int` 的map。因为map的键必须实现 `<` 操作，list 的迭代器不支持比较运算。

##### **c、pair类型**

定义在utility标准库中

##### **d、关联容器操作**

key_type	此容器关键字类型

mapped_type	每个关键字关联的类型

value_type 	对于set，与key_type相同；对于map，为pair<const key_type,mapped_type>

##### **e、关联容器迭代器**

```C++
auto map_it =word_count.begin();
cout<<map_it->first<<" "<<map_it->second;
set<int> iset={0,1,2,3,4,5};
auto set_it=iset.begin();
cout<<*set_it<<endl;
```

<u>通常不对关联容器使用算法</u>，使用关联容器自定义的find成员比使用泛型find算法快很多。

##### **f、关联容器操作**

```C++
c.insert(V)   
```

有序容器插入成功返回一个**pair**，first成员是一个迭代器，指向被插入的元素；second成员是一个bool值，表示插入是否成功。

无序容器插入则返回插入元素的**迭代器**，因为插入始终是成功的。

``` C++
c.erase(k); // k为关键字,返回size_type，指出删除元素的数量
c.erase(p); //p为迭代器，返回p之后的元素迭代器
c.erase(b,e);  //删除迭代器b,e之间的元素，返回e
```

##### **g、map的下标操作**

```C++
c[k]		//返回关键字为k的元素；如果k不在c中，则添加一个关键字为k的元素
c.at(k)		//访问关键字为k的元素，带参数检查；如不存在，抛出out_of_range异常
```

set类型不支持下标操作，由于set只有关键字没有值。

##### h、访问元素

```C++
c.find(k)
c.count(k)
c.lower_bound(k)
c.upper_bound(k)
c.equal_range(k)
```

##### i、无序容器

新标准库定义了4个无序容器，无序容器不是使用比较运算符来组织元素，而是使用一个哈希函数和关键字类型的==运算符来组织元素的。

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

##### 1、shared_ptr类

##### 2、unique_ptr类

##### 3、weak_ptr类

##### 4、allocator类

### 第十三章 拷贝控制