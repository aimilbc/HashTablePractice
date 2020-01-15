//
//  hash.cpp
//  HashTable
//
//  Created by AIMI ROSS on 1/15/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

Hash::Hash(){}

int Hash::getHash(string key){
    int index = 0;
    
    for(int i = 0; i < key.length(); i++){
        cout << "(int)key[i] = " << (int)key[i] << endl;
        index += key[i];
    }
    
    return index;
}
