# Properties-PARSER

### ❤️Intro

一个基于C语言的属性解析器

### 🧡Document

使用方式

```bash
gcc testFile.c propertiesParser.c -o test
./test
```

属性用一个文件存储

```properties
# 支持注释，属性按行存储
name=steveyu
age = 21
version = 1.0
```

parse案例

```c
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "propertiesParser.h"

// testParseFile
void testParseFile() 
{
    parseFile("./test.properties");
    char* ch = getValue("name");
    char* ch2 = getValue("age");
    char* ch3 = getValue("version");
    char* ch4 = getValue("other");
    char* ch5 = getValue("A");
    char* ch6 = getValue("B");
    assert(strcmp(ch, "steveyu") == 0);
    assert(strcmp(ch2, "12") == 0);
    assert(strcmp(ch3, "1.0") == 0);
    assert(strcmp(ch4, "can") == 0);
    assert(strcmp(ch5, "1") == 0);
    assert(strcmp(ch6, "2") == 0);
}

int main(int argc, char const *argv[])
{
    testParseFile();
    return 0;
}
```