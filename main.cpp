#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
#include <vector>
#include <string>
#include "memory.h"
#include "cmake-build-debug/memory.h"

using namespace std;


int main() {
    vector<pair<string, pair<string, string>>> memo;
    memory mem;
    mem.inputMemory(memo);
    mem.printMemory(memo);
    
    return 0;
}
