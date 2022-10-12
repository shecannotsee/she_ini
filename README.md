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
key2
```

Q1

每一行只有三种状态：1.注释；2.section；3.key-value

通过第一个字符可以判断出来是哪一种状态

Q2

对于section下的key



### Building

just include the head like this example in cmake

```cmake
# ...
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

