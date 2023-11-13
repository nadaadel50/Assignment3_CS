#include "memory.h"
#include <bits/stdc++.h>
#include <utility> // for pair
#include "Machine.h"
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
            Jumpv.push_back(counter);
            counter += 2;
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
    //for (const auto &it: memo) {
    auto it = memo.begin();
    while(it != memo.end()){
        if (it->first == "2") { //store
            int ss = stoi(it->second.second);
            if (reg.empty()) {
                reg.push_back(make_pair(it->second.first, ss));
            } else {
                bool k = false;
                for (int i = 0; i < reg.size(); ++i) {
                    if (reg[i].first == it->second.first) {
                        reg[i].second = ss;
                        k = true;
                        break;
                    }
                }
                if (k == false) {
                    reg.push_back(make_pair(it->second.first, ss));
                }
            }
        }
        //------------------------------------------------------------------------
        else if (it->first == "3") {   //from register to memory
            for (const auto &pair: reg) {
                if (pair.first == it->second.first && it->second.second != "00") {
                    storage.push_back(make_pair(it->second.second, pair.second));
                }
                else if(it->second.second == "00"){
                    if(pair.first == it->second.first){
                        cout << "3R00 --> " <<"Register " << pair.first << " contains "<< pair.second << endl;
                    }
                }
            }
        }
        //------------------------------------------------------------------------
        else if (it->first == "1") {   //from memory to register
            for (const auto &pair: storage) {
                if (pair.first == it->second.second) {
                    int s = pair.second;
                    reg.push_back(make_pair(it->second.first, s));
                }
            }
        }
        //------------------------------------------------------------------------
        else if (it->first == "4") {   //from memory to register

            string s1;
            s1=it->second.second[0];
            string s2;
            s2=it->second.second[1];

            bool exist= false;
            for (const auto &pair: reg) {
                if (pair.first == s1) {
                    int s=pair.second;
                    exist= true;
                    bool k = false;
                    for (int i = 0; i < reg.size(); ++i) {
                        if (reg[i].first == s2) {
                            reg[i].second = pair.second;
                            k = true;
                            break;
                        }
                    }
                    if (k == false) {
                        reg.push_back(make_pair(s2, s));
                    }
                }
            }
            if(exist== false){
                cout<<"Register "<<s1<<" doesnot exist\n";
            }

        }
        //------------------------------------------------------------------------
        else if(it->first == "5"){
            int r1;
            int r2;
            const int SIZE =32;   //for 32 bits
            char w1=it->second.second[0];
            char w2=it->second.second[1];

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
                if (reg[i].first == it->second.first) {
                    reg[i].second = res;
                    k = true;
                    break;
                }
            }
            if (k == false) {
                reg.push_back(make_pair(it->second.first, res));
            }
        }
        //------------------------------------------------------------------------
        else if(it->first == "B") {
            int reg0, regR;
            for(const auto& pair: reg){
                if(pair.first == "0"){
                    reg0 = pair.second;
                }
                if(pair.first == it->second.first){
                    regR = pair.second;
                }
            }
            if(regR == reg0){
                string newmem = it->second.second;
                int destination = stoi(newmem);
                int index = destination / 2;
                if(index >= 0 && index < memo.size()){
                    it = memo.begin() + index;
                }
                else{
                    cout << "Invalid jump destination" << endl;
                }
            }
        }
        //-------------------------------------------------------------------
        else if(it->first == "C"){
            cout << "HALT" << endl;
            break;
        }
        it++;
    }
}

void cpu::printReg(const vector<pair<string ,int>>& reg){
    cout<<"-------------------------------------------\n";

    cout<<"Register is: \n";
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


