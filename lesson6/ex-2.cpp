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
            std::cout << e.what() << "\n";
        }
        

        return result;
    }
    Logarithm(double base, double argument){
        try{
            if(argument<0){
                throw std::domain_error("argument");
            }
            if(base<=1){
                throw std::domain_error("base");
            }
        }
        catch(std::domain_error ex){
            std::string s(ex.what()); 
            s.append(" out of domain");

            throw std::invalid_argument(s);
        }
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
        std::cout<< e.what();
    }

    
    
    return 0;
}