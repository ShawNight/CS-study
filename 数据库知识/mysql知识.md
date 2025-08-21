# MySQL学习

## 一、检索数据

1、检索单个列

```sql
select prod_name from products;
```

2、检索多个列

```sql
select prod_id, prod_name，prod_price from products;
```

3、检索所有列

```sql
select * from products;
```

4、检索不同的行（去重）

```sql
select distinct vend_id from products;
```

> *不能部分使用DISTINCT DISTINCT关键字应用于所有列而不仅是前置它的列。如果给出SELECT DISTINCT vend\_id,prod\_price，除非指定的两个列都不同，否则所有行都将被检索出来*

5、限制结果

```sql
select prod_name from products limit 5;
```

## 二、排序检索数据

1、排序数据 order by

```sql
select prod_name from products order by prod_name; //单个排序

select prod_name from products order by prod_name, prod_price; //按多个列排序

select prod_id, prod_price, prod_name from products order by prod_price DESC; //指定排序顺序,DESC降序，默认增序
```
