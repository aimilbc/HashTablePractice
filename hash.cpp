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

Hash::Hash(){  // default constructor
    for(int i = 0; i < tableSize; i++){
        HashTable[i] = new item;
        HashTable[i] -> name = "empty";
        HashTable[i] -> drink = "empty";
        HashTable[i]->next = NULL;
    }
}

void Hash::addItem(string name, string drink){  // adding an item in the table
    int index = getHash(name);  // get an index number for the person using getHash function
    if(HashTable[index]->name == "empty"){  // since default is "empty", it means there is no item in the bucket, so we can add the item straight
        HashTable[index]->name = name;
        HashTable[index]->drink = drink;
    }
    else{ // if there were item(s) in the bucket, add a new item after the very last item of the bucket.
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

int Hash::NumOfItemsInBucket(int index){ // find amount of items in the bucket
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

void Hash::PrintTable(){ // print the items in the table(printing only the first item if there were multiple items in a bucket)
    int num;
    for(int i = 0; i<tableSize; i++){
        num = NumOfItemsInBucket(i);  // find the amount of items in the bucket
        cout << "---------------------------" << endl;
        cout << "index = " << i << endl;
        cout << HashTable[i]->name << endl;
        cout << HashTable[i]->drink << endl;
        cout << "# of items in the bucket = " << num << endl;
    }
}

void Hash::PrintItemsInBucket(int index){ // display the items in the bucket
    item* Ptr = HashTable[index]; // create a pointer to point to the first item in the bucket
    
    if(Ptr->name == "empty"){ // if there were not item in the bucket
        cout << "Index " << index << " is empty" << endl;
    }
    
    else{ // if there were item(s) in the bucket
        cout << "Index " << index << " has " << NumOfItemsInBucket(index) << " items." << endl; // display the amount of item(s) in the bucket
        while(Ptr != NULL){
            cout << "---------------------------" << endl;
            cout << "Name: " << Ptr->name << endl;
            cout << "Drink: " << Ptr->drink << endl;
            Ptr = Ptr->next; // treverse the pointer to the next item until point to NULL
        }
    }
}

void Hash::FindDrink(string name){ // find the drink by name
    int ind = getHash(name); // get index number using getHash function
    bool found = false;
    string drink;
    item* Ptr = HashTable[ind];
    
    while(Ptr != NULL){
        if(Ptr->name == name){
            found = true;
            drink = Ptr->drink;
        }
        Ptr = Ptr->next;
    }
    if (found == true){
        cout << "Favorite drink = " << drink << endl;
    }
    else{
        cout << name << "'s info wasn't found in the Table" << endl;
    }
}

void Hash::RemoveItem(string name){
    int ind = getHash(name); // get index number of the name
    item* delPtr;
    item* P1;
    item* P2;
    
    // the bucket has no item
    if(HashTable[ind]->name == "empty"){
        cout << name << "'s info wasn't found in the Table" << endl;
    }
    
    // the bucket has ONLY one item wich is the item we're looking for
    else if(HashTable[ind]->name == name && NumOfItemsInBucket(ind) == 1){
        HashTable[ind]->name = "empty";
        HashTable[ind]->drink = "empty";
        
        cout << name << " has been removed from the table." << endl;
    }
    
    // the item was in the bucket's first place and there are more items in the bucket
    else if(HashTable[ind]->name == name && NumOfItemsInBucket(ind) != 1){
        delPtr = HashTable[ind]; // a pointer points to the deleting item
        HashTable[ind] = HashTable[ind]->next; // the table points second item(skipping the deleting item)
        delete delPtr; // deleting the item from the bucket
        
        cout << name << " has been removed from the table." << endl;
    }
    
    // the item found in the bucket, but not the first item
    else{
        P1 = HashTable[ind]->next;  // P1 points the next item
        P2 = HashTable[ind]; // P2 points the first item
        // P2's "next" pointer is pointing P1
        
        while(P1 != NULL && P1->name != name){ // trevers P1 and P2 until find the deleting item
            P2 = P1;
            P1 = P1->next;
        }
        if (P1 == NULL){ // it means the pointer is pointing the last item, so the item is not found in the table
            cout << name << "'s info wasn't found in the Table" << endl;
        }
        else{ // it means item found.
            delPtr = P1; // deleting item assigned to delPtr pointer
            P1 = P1->next; // P1 points to the next item
            P2->next = P1; // P2 points P1(skipping the deleting item)
            
            delete delPtr; // deleting the item
            cout << name << " has been removed from the table." << endl;
        }
    }
}

int Hash::getHash(string key){ // get a index number of item
    // key = name, adding ASCII number of the name and divided by the table size
    int index = 0;
    
    for(int i = 0; i < key.length(); i++){
        index += key[i];
    }
    
    return index % tableSize;
}
