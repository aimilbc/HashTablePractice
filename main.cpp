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
    string name;
    
    hashObj.addItem("Kana", "Cognac");
    hashObj.addItem("Aimi", "Tito's");
    hashObj.addItem("Leana", "Waterrr");
    hashObj.addItem("Michael", "Anything");
    hashObj.addItem("Anthony", "Moscow Mule");
    hashObj.addItem("Olivia", "No Peanut");
    hashObj.addItem("Travis", "Bubble Juice");
    hashObj.addItem("Paul", "Vodka");
    hashObj.addItem("Michelle", "Dirty Martini");
    hashObj.addItem("Kulala", "Shochu");
    hashObj.addItem("Brandon", "Beer");
    
    //hashObj.PrintTable();
    hashObj.PrintItemsInBucket(2);
    
    while(name != "exit"){
        cout << "Remove ";
        cin >> name;
        if(name != "exit"){
            hashObj.RemoveItem(name);
        }
    }
    //hashObj.PrintTable();
    hashObj.PrintItemsInBucket(2);
    
    return 0;
}
