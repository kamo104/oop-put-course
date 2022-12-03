#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <cmath>

//check arguments provided and throw exceptions from logs
class Number{
    public:
    virtual double DoubleValue()=0;
};

class Logarithm : Number{
    private:
    double base, argument;

    public:
    double DoubleValue() override {
        double result=0;
        try{
            double result =log(this->argument)/log(this->base);
        }
        catch(std::logic_error e){
            throw(std::logic_error("Division by zero in calculation"));
        }
        

        return result;
    }
    Logarithm(double base, double argument){
        if(argument<0) throw std::invalid_argument("argument out of function domain");
        if(base<=1) throw std::invalid_argument("base out of function domain");

        this->base = base;
        this->argument = argument;
    }
};

int main(){
    try{
        Logarithm log(0,2);
        log.DoubleValue();
    }
    catch(std::invalid_argument e){
        std::cout<< e.what();
    }
    catch(std::logic_error e){
        return 1;
    }

    
    
    return 0;
}