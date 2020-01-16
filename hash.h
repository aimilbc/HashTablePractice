//
//  hash.h
//  HashTable
//
//  Created by AIMI ROSS on 1/15/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef HASH_H
#define HASH_H

class Hash{
private:
    static const int tableSize = 10;
    struct item{
        string name;
        string drink;
        item* next; // pointing the next item.
    };
    
    item* HashTable[tableSize];
    
public:
    Hash();
    int getHash(string);
    void addItem(string name, string drink);
    int NumOfItemsInBucket(int);
    void PrintTable();
};


#endif /* HASH_H */
