#include<bits/stdc++.h>
#include <utility> // for pair
using namespace std;

class input{
protected:
    vector<string>v;
    vector<pair<string,pair<string,string>>>memo;
    vector<int>Jumpv;
    vector<string>hexVector;
    int counter = 0;
public:
    void inputMemory(vector<pair<string,pair<string,string>>>& memo, vector<int>&Jumpv, vector<string>&hexVector);
    void printMemory(const vector<pair<string, pair<string, string>>>& memo);
};


class cpu {
protected:
    vector<pair<string , string >>reg;
    vector<pair<string, string >>storage;

public:
    void input_reg(vector<pair<string,pair<string,string>>>& memo, vector<string>&hexVector);

    void printReg(const   vector<pair<string , string >>& reg);
    void printstr(const   vector<pair<string , string >>& storage);

    const vector<pair<string ,string>>&getReg()const;
    const vector<pair<string ,string>>&getstr()const;

    bool size_of_storage(const   vector<pair<string , string >>& storage);
};
