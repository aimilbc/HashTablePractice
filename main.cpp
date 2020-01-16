//
//  main.cpp
//  HashTable
//
//  Created by AIMI ROSS on 1/15/20.
//  Copyright © 2020 AIMI ROSS. All rights reserved.
//

#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Hash hashObj;
    
    hashObj.addItem("Kana", "Cognac");
    hashObj.addItem("Aimi", "Tito's");
    hashObj.addItem("Leana", "Waterrr");
    hashObj.addItem("Michael", "Anything");
    hashObj.addItem("Anthony", "MoscowMule");
    hashObj.addItem("Olivia", "NoPeanut");
    hashObj.addItem("Travis", "BubbleJuice");
    
    hashObj.PrintTable();
    cout << "Leana's hash bucket number is " << hashObj.getHash("Leana") << endl;
    cout << "Index 1 has " << hashObj.NumOfItemsInBucket(1) << endl;
    
    return 0;
}
