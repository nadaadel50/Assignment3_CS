#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <vector>
#include <utility> // for pair
using namespace std;


class memory{
protected:
    vector<string>v;
    vector<pair<string,pair<string,string>>>memo;
public:
    void inputMemory(vector<pair<string,pair<string,string>>>& memo);
    void printMemory(const vector<pair<string, pair<string, string>>>& memo);
};

