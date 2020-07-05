//
//  propertiesParser.h
//  propertiesParser
//
//  Created by Steve Yu on 2020/7/5.
//  Copyright © 2020 Steve Yu. All rights reserved.
//

/*
 * parseFile
 * parse a file to get properties
 * - path: your path name
 * - getValue: get a value by key
 */
void parseFile(const char* path);

/*
 * getValue
 * get a value by key
 * - key: get value by a key
 */
char* getValue(char *key);