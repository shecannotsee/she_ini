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

Q1

每一行只有三种状态：1.注释；2.section；3.key-value

通过第一个字符可以判断出来是哪一种状态

Q2：如何处理状态机

1.检查自己的字符串；2.是否结束？非结束则推送到下一个状态

Q3：举例

起始节点：无状态->通过自身属性更新状态

中间节点：检查自身状态->通过自身属性更新状态



### Building

just include the head like this example in cmake

```cmake
# ....
# set third-party path
set(path "")
# include
include_directories(${path})
# ...
```



### how to use?

example

```c++
#include "DataStructure/Section.h"
#include "Parse/Parse.h"

void main(){
  //config data
  std::vector<sheIni::Section> config;
  {
    sheIni::IniFile config_file("./config.ini");
    config_file.parse(config);
  }

  for (auto& e:config) {
    // get section
    std::cout<<"section is:"<<e.getSection()<<"\n";
    // get key-value from section
    for (auto& ee: e.getAllKV() ) {
      std::cout<<"key:【"<<std::get<0>(ee)<<"】="
              <<"value【"<<std::get<1>(ee)<<"】\n";
    }
  }
}
```

