#include "Machine.h"
#include <fstream>
#include <bits/stdc++.h>

using namespace std;
int main() {
    vector<pair<string, pair<string, string>>> memo;
    vector<int>Jumpv;
    vector<string>hexVector;
    input mem;
    mem.inputMemory(memo, Jumpv, hexVector);
    mem.printMemory(memo);

    vector<pair<string , int >>reg;

    vector<pair<string, int >>storage;
    cpu c;
    c.input_reg(memo, hexVector);
    c.printReg(c.getReg());
    c.printstr(c.getstr());

}
