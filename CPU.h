/*class CPU {
protected:
    int counter = 0;

public:
    int registers[16];
    int ProgramCounter; //keeps track of our instruction cycle
    int InstructionRegister; //loads our instructions from memory
    int Accumulator;

};
*/
#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <vector>
#include <utility> // for pair
//#include "memory.h"
using namespace std;


class cpu {
protected:
    vector<pair<int , int >>reg;
    vector<pair<string, int >>storage;
public:
    void input_reg(vector<pair<string,pair<string,string>>>& memo);
   // void input_storage(vector<pair<string,pair<string,string>>>& memo);
    void printReg(const   vector<pair<int , int >>& reg);
    const vector<pair<int,int>>&getReg()const;

};







