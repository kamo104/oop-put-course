#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>


using namespace std;

class Elf{
    public:
    int carriedCalories;
    int index;

    string properties(){
        string s;
        s.append(to_string(this->index));
        s.append(" ");
        s.append(to_string(this->carriedCalories));
        return s;
    }

    Elf(int index,int carriedCalories){
        this->index = index;
        this->carriedCalories = carriedCalories;
    }
};

Elf findMaxElf(){
    string input;
    int caloriesSum=0, elfNum=1;
    Elf elf(1,0);
    while(getline(cin,input)){
        if(input==""){
            if(caloriesSum>elf.carriedCalories) elf = Elf(elfNum,caloriesSum);
            
            caloriesSum=0;
            elfNum+=1;
            continue;
        };
        
        caloriesSum += stoi(input);
    }
    return elf;
}
int main(){
    Elf elf = findMaxElf();
    cout << elf.properties() << endl;
    return 0;
}