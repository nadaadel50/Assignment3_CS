#include "CPU.h"
#include "memory.h"
#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <vector>
#include <utility> // for pair
using namespace std;

void memory:: inputMemory(vector<pair<string,pair<string,string>>>& memo) {
    ifstream inputFile("text.txt");
    string line;

    while (getline(inputFile, line)) {
        string firstPart, secondPart, thirdPart;
        istringstream text(line);
            if(text >>firstPart >> secondPart >> thirdPart){
                if(firstPart.substr(0,2) == "0x"){
                    firstPart = firstPart.substr(2);
                }
                if(secondPart.substr(0, 2) == "0x"){
                    secondPart = secondPart.substr(2);
                }
                if(thirdPart.substr(0, 2) == "0x"){
                    thirdPart = thirdPart.substr(2);
                }
                memo.push_back(make_pair(firstPart, make_pair(secondPart, thirdPart)));
            }
    }
    inputFile.close();
}

void memory::printMemory(const vector<pair<string, pair<string, string>>>& memo){
    for (const auto& it : memo) {
        cout << "First Part: " << it.first << " Second Part: " << it.second.first << " Third Part: " << it.second.second << endl;
    }
}
