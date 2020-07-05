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
    assert(strcmp(ch2, "21") == 0);
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