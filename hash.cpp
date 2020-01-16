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

Hash::Hash(){
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item;
        HashTable[i] -> name = "empty";
        HashTable[i] -> drink = "empty";
        HashTable[i]->next = NULL;
    }
}

void Hash::addItem(string name, string drink){
    int index = getHash(name);
    if(HashTable[index]->name == "empty"){
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else{
        item* Ptr = HashTable[index]; // a pointer pointing at the very first item in that bucket
        item* n = new item; // created a new item
        n->name = name; // assigned name
        n->drink = drink; // assigned drink
        n->next = NULL; // pointer points NULL since it's the new item and this will be the last item on that bucket
        while (Ptr->next != NULL){ // traverse the bucket to find the last item, so we can add the new item
            Ptr = Ptr->next;
        }
        Ptr->next = n; // assigned the new item address to the last item pointer
    }
}
int Hash::NumOfItemsInBucket(int index){
    int count = 0;
    
    if(HashTable[index]->name == "empty"){ // since the default constructor assigns name = "empty", the bucket will not contain anything
        return count;
    }
    else{ // if there was an item in that bucket, traverse the bucket to count the item
        count++;  // since we know there was at least one item in that bucket, increase the count to 1.
        item* Ptr = HashTable[index]; // create a pointer to point the first item in the bucket
        while (Ptr->next != NULL) { // traverse and count the item while the item pointer is NOT pointing to NULL
            count++;
            Ptr = Ptr->next;
        }
    }
    
    return count;
}

int Hash::getHash(string key){
    int index = 0;
    
    for(int i = 0; i < key.length(); i++){
        cout << "(int)key[i] = " << (int)key[i] << endl;
        index += key[i];
    }
    
    return index%tableSize;
}
