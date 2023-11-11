//#include <utility> // for pair
#include"cpu.h"
//#include"memory.cpp"
using namespace std;

void cpu:: input_reg(vector<pair<string,pair<string,string>>>& memo) {
    storage.push_back(make_pair("A2",7));
    for (const auto& it : memo) {
        if(it.first=="1"){
            for(const auto& pair : storage){
                if(pair.first==it.second.second){
                    int s=pair.second;
                    int ss=stoi(it.second.first);
                    reg.push_back(make_pair(ss,s));
                }
            }

        }
    }
}


void cpu::printReg(const vector<pair<int,int>>& reg){
    for (const auto& it : reg) {
        cout << "First Part: " << it.first << " Second Part: " << it.second<< endl;
    }
}
const vector<pair<int,int>>&cpu::getReg()const{
    return reg;
}
