对于一个ini文件格式如下

```ini
#这也是一条注释
;这是一条注释
[section1]
key1=value1
key2 = value2
key3 = value3

[section2]
key1 = value1
key2 =value2

;为了弥补ini文件在多级菜单下的不良表现
;通过添加子文件的归属来补充其子模块的配置能力
[section3]
(f) key1 = value1
```



0.英文小写的分号和#都可以表示注释

```ini
; 注释1
# 注释2
；中文分号并不能表示注释
```



1.默认文件名是每一个section的父标签



2.section下的k-v默认是属于该section的

可以通过以下方式

```c++
std::string = xxx[section][key];
```

来获取对应的值



3.(f)表示该键值对是一个文件路径，通过获取该文件路径，可以重新开辟一个ini文件，然后里面就有对应的section和键值对

这样子做可以扩展ini文件在多级或者是模块化上的缺陷，并且能够进行相应的扩展和分层



4.ini文件默认通过换行符来标志着这一行的结束，windows下的换行符为\r\n，linux/unix下的换行符为\n，这一点需要注意区分



5.括号还可以用来表示键值对的属性，例如

```ini
# 这是一个整数，对应c++中的int32
(i) secends = 100
# 这是一个浮点数，对应c++中的double
(d) x = 12.32
```

其他未用()标注的k-v键值对会默认用c++的std::string进行解析如果标注了类型会使用对应的类型进行解析

TODO:该特性希望能够在初始化库的时候能够手动去指定(i)和(d)对应的类型，例如用long和float去处理应该也是可以的



6.可以使用英文分号来代替换行

```ini
key1 = value1;key2 = value2;
# 效果等价于
key1 = value1
key2 = value2
```

当然，如果在英文分号后再加一个回车将是一个更加良好的习惯

```ini
[section]
key1 = value1;
key2 = value2;
```



