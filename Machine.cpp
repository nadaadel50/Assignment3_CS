#include "memory.h"
#include <bits/stdc++.h>
#include <utility> // for pair

#include<bitset>   //for converting to binary representation

using namespace std;

void input:: inputMemory(vector<pair<string,pair<string,string>>>& memo) {
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

void input::printMemory(const vector<pair<string, pair<string, string>>>& memo){
    for (const auto& it : memo) {
        cout << "First Part: " << it.first << " Second Part: " << it.second.first << " Third Part: " << it.second.second << endl;
    }
}


void cpu:: input_reg(vector<pair<string,pair<string,string>>>& memo) {
    for (const auto &it: memo) {
        if (it.first == "2") { //store
            int ss = stoi(it.second.second);
            if (reg.empty()) {
                reg.push_back(make_pair(it.second.first, ss));
            } else {
                bool k = false;
                for (int i = 0; i < reg.size(); ++i) {
                    if (reg[i].first == it.second.first) {
                        reg[i].second = ss;
                        k = true;
                        break;
                    }
                }
                if (k == false) {
                    reg.push_back(make_pair(it.second.first, ss));
                }
            }

        }
        else if (it.first == "3") {   //from register to memory
            for (const auto &pair: reg) {
                if (pair.first == it.second.first) {
                    storage.push_back(make_pair(it.second.second, pair.second));
                }
            }
        }

        else if (it.first == "1") {   //from memory to register
            for (const auto &pair: storage) {
                if (pair.first == it.second.second) {
                    int s = pair.second;
                    reg.push_back(make_pair(it.second.first, s));
                }
            }
        }
        else if(it.first == "5"){
            int r1;
            int r2;
            const int SIZE =32;   //for 32 bits
            char w1=it.second.second[0];
            char w2=it.second.second[1];

            for (const auto &pair: reg) {
                if (pair.first[0]==w1) {
                    r1 = pair.second;
                }
                if(pair.first[0]==w2){
                    r2=pair.second;
                }
            }

            bitset<SIZE>first_number(r1);  //convert to 2's complement
            bitset<SIZE>second_number(r2);

            //to convert the two numbers into unsigned long integer so that we can do the addition
            //+1 to keep a space if was any overflow

            bitset<SIZE+1>ans = first_number.to_ulong() + second_number.to_ulong();
            if(ans.test(SIZE)){                  //check for overflow
                cout<<"There is an overflow ."<<endl;
            }
            int res=static_cast<int>(ans.to_ulong());    //to convert from unsigned long integer into integer

            bool k = false;
            for (int i = 0; i < reg.size(); ++i) {
                if (reg[i].first == it.second.first) {
                    reg[i].second = res;
                    k = true;
                    break;
                }
            }
            if (k == false) {
                reg.push_back(make_pair(it.second.first, res));
            }

        }
    }
}

void cpu::printReg(const vector<pair<string ,int>>& reg){
    cout<<"-------------------------------------------\n";

    cout<<"Rigestr is: \n";
    for (const auto& it : reg) {
        cout << "First Part: " << it.first << " Second Part: " << it.second<< endl;
    }
    cout<<"-------------------------------------------\n";
}

void cpu::printstr(const vector<pair<string ,int>>& storage){
    for (const auto& it : storage) {
        cout << "First Part: " << it.first << " Second Part: " << it.second<< endl;
    }
}

const vector<pair<string ,int>>&cpu::getReg()const{
    return reg;
}
const vector<pair<string ,int>>&cpu::getstr()const{
    return storage;
}
