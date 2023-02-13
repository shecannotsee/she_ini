sheIni is a library for parsing ini type files. On this basis, there are some extensions to ini type files

Authors: shecannotsee (shecannotsee@163.com)

# Features

- In order to compensate for the poor performance of ini type files supported by objects,the problem is solved by adding file objects.
- Easy to use.
- Clear architecture so that you can easily modify the library



# Documentation

You can find more details in folder ./example

config.ini

```
[config-set]
ip = 127.0.0.1
port = 80889
[f] config_path = /etc/example/
[f] log_path = /var/log/example/
```

example.cpp

```c++
#include <iostream>
#include <string>
// You should use this head file.
#include <IniStructure.h>

int main() {
  sheIni::IniStructure web_config;
  // Load the file data to your memory object.
  web_config.readFromFile("../config.ini");
  // And use the results.
  auto ip       = web_config.section("config-set").getKey("ip");
  auto port     = web_config.section("config-set").getKey("port");
  auto cfg_path = web_config.section("config-set").getKey("config_path");
  auto log_path = web_config.section("config-set").getKey("log_path");

  using ::std::cout;using ::std::endl;
  // print
  cout << "http://" << ip << ":" << port << endl;
  cout << "Config peth :[" << cfg_path << "]\n";
  cout << "log path :[" << log_path << "]\n";
//  print results
//  http://127.0.0.1:80889
//  Config peth :[f/etc/example/]
//  log path :[f/var/log/example/]

  return 0;
};
```



# Getting the Source

```shell
git clone https://github.com/shecannotsee/sheIni.git
```



# Building

This project supports [CMake](https://cmake.org/) out of the box.

### Build for Linux or Mac

```shell
# now you are in the directory ${path}/sheIni
➜ pwd
${path}/sheIni
➜ mkdir build
➜ cd build
➜ cmake ..
➜ make -j8
➜ make install DESTDIR=${path}/sheBase64lib
```





# Rules for ini files

An ini file example

```ini
# note1
[section1]
key1=value1
key2 = value2
key3 = value3

[section2]
key1 = value1
key2 =value2

# note2
[section3]
(f) key1 = value1
```

**[Rules-1]**  '#' can indicate note

**[Rules-1]**  The file name is the parent label of each section

**[Rules-2]**  The k-v under the section belongs to the section by default

**[Rules-3]**  The type of key-value pair can be defined through '()'

For example

(f) This means that the value of the key-value pair can be directly parsed into an ini file type, which can be directly loaded into the sheIni object

(i) It means that the value of the key-value pair is an integer

(d) It means that the value of the key-value pair is a floating point type

More types may be added in the future for ease of use

**[Rules-4]**  You can use ';' Instead of line feed

```ini
key1 = value1;key2 = value2;
# Equivalent to
key1 = value1
key2 = value2
```

Of course, if ';' It would be a better habit to add a return

```ini
[section]
key1 = value1;
key2 = value2;
```

**[Rules-5]**  '=' , '[]'  and '()' can have spaces before and after



Character table

| character | meaning                                                  | action                                                       |
| --------- | -------------------------------------------------------- | ------------------------------------------------------------ |
| ';'       | It can indicate the end of a line                        | End reading of this line                                     |
| '#'       | Indicates a note                                         | No action                                                    |
| '['       | Indicates that the following characters are all sections | Start using container of **section**                         |
| ']'       | Indicates that the previous characters are all sections  | Judge whether the character is a legal **section**           |
| '('       | Indicates that the following character is a type         | Start using container of **type**                            |
| ')'       | Indicates that the preceding character is a type         | Judge whether the character is a legal **type**, and then start to use the key container |
| '='       | Indicates the end of key and the beginning of value      | The key processing is finished, and the value container will be used later |
| '\n'      | The newline character of the file under unix-like        | End reading of this line                                     |
| '\r\n'    | The newline character of the file under windows          | End reading of this line                                     |

