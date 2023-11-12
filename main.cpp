#include "Machine.h"
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    vector<pair<string, pair<string, string>>> memo;

    input mem;
    mem.inputMemory(memo);
    mem.printMemory(memo);

    vector<pair<string , int >>reg;
//    reg={{'1',0},{'2',0},{'3',0},{'4',0},{'5',0},{'6',0},{'7',0},{'8',0},{'9',0},{'A',0},{'B',0},{'C',0},{'D',0}
//    ,{'E',0},{'F',0}};
    vector<pair<string, int >>storage;
    cpu c;
    c.input_reg(memo);
    c.printReg(c.getReg());
    c.printstr(c.getstr());
    
}

