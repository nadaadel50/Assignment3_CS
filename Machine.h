#include<bits/stdc++.h>
#include <utility> // for pair
using namespace std;

class input{
protected:
    vector<string>v;
    vector<pair<string,pair<string,string>>>memo;
public:
    void inputMemory(vector<pair<string,pair<string,string>>>& memo);
    void printMemory(const vector<pair<string, pair<string, string>>>& memo);
};


class cpu {
protected:
    vector<pair<string , int >>reg;
    vector<pair<string, int >>storage;
public:
    void input_reg(vector<pair<string,pair<string,string>>>& memo);

    void printReg(const   vector<pair<string , int >>& reg);
    void printstr(const   vector<pair<string , int >>& storage);

    const vector<pair<string ,int>>&getReg()const;
    const vector<pair<string ,int>>&getstr()const;


};














//class CPU{
//    void pc();
//    int instruction_register();
//    int Accumulator();
//};