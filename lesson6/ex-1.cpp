#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <cmath>

class NumberCollection{
    private:
    std::vector<int> numbers;
    public:
    int min(){
        if(numbers.size()<0)return 0; //should raise an exception but I have no time
        int minVal=numbers.at(0);
        for(auto number:numbers) number<minVal?minVal=number:minVal=minVal;
    }
    int max(){
        if(numbers.size()<0)return 0; //should raise an exception but I have no time
        int maxVal=numbers.at(0);
        for(auto number:numbers) number<maxVal?maxVal=number:maxVal=maxVal;
    }
    double average(){
        int sum=0;
        for(auto number:numbers) sum+=number;
        return double(sum)/double(numbers.size());
    }
    
    NumberCollection(int a, int b){
        this->numbers.push_back(a);
        this->numbers.push_back(b);
    }
    NumberCollection(std::vector<int> numbers){
        this->numbers = numbers;
    }
};
int main(){
    NumberCollection numbers(1,2);
    numbers.max();
    return 0;
}