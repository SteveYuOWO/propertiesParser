//
//  propertiesParser.c
//  propertiesParser
//
//  Created by Steve Yu on 2020/7/5.
//  Copyright © 2020 Steve Yu. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include <stdbool.h>

#define KEY_LEN 100
#define VALUE_LEN 100
#define PAIR_SIZE 100
#define MAX_FILE_LINE_SIZE 200
#define MAX_FILE_SIZE 100000

// struct _pair
typedef struct _pair 
{
    char key[KEY_LEN];
    char value[VALUE_LEN];
}pair;

// global pair
pair p[PAIR_SIZE];
size_t p_size = 0;

// insertPair
void insertPair(char *key, char *value) 
{
    for(int i = 0; i < p_size; i++) {
        if(strcmp(p[i].key, key) == 0) {
            strcpy(p[i].value, value);
            return;
        }
    }
    strcat(p[p_size].key, key);
    strcat(p[p_size].value, value);
    p_size++;
    return;
}

// parseProperties
// parse Properties By char*
void parseProperties(char* input) 
{
    if(strlen(input) == 0) return;
    for(int i = 0; i < strlen(input); i++) {
        char key[KEY_LEN], value[VALUE_LEN];
        int keyi = 0, valuei = 0;
        while(i < strlen(input) && input[i] != '=') 
            key[keyi++] = input[i++];
        i++;
        key[keyi] = '\0';
        while(i < strlen(input) && input[i] != '\n') 
            value[valuei++] = input[i++];
        value[valuei] = '\0';
        insertPair(key, value);
    }
}

// getValue
// get a value by key
char* getValue(char *key) 
{
    for(int i = 0; i < p_size; i++) 
        if(strcmp(key, p[i].key) == 0) return p[i].value;
    return NULL;
}

// parse files
void parseFile(const char* path) 
{
    FILE *f = fopen(path, "r");
    char buff[MAX_FILE_LINE_SIZE], buffsz = 0;
    char file_text[MAX_FILE_SIZE];
    char c;
    while(fscanf(f, "%c", &c) != EOF) {
        if(c == ' ' || c == '\t') continue; // remove ' '
        if(c == '#') { // remove comment
            while(true) {
                if(fscanf(f, "%c", &c) == EOF) break;
                if(c == '\n') break;
            }
        }
        buff[buffsz++]  = c;
        if(c == '\n') {
            if(buffsz != 0) { // blank line
                parseProperties(buff);
                buffsz = 0;
            }
        }
    }
    fclose(f);
}
