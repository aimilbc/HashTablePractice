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
    
    int ind = 0;
    
    ind = hashObj.getHash("Aimi");
    
    cout << ind << endl;
    
    return 0;
}
