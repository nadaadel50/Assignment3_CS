#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
#include <vector>
#include <string>
#include "memory.h"
//#include "cmake-build-debug/memory.h"


#include "cpu.h"

using namespace std;


int main() {
    vector<pair<string, pair<string, string>>> memo;
    memory mem;
    mem.inputMemory(memo);
    mem.printMemory(memo);

    vector<pair<int , int >>reg;
    vector<pair<string, int >>storage;
    cpu c;
    c.input_reg(memo);
    c.printReg(c.getReg());

    return 0;
}
