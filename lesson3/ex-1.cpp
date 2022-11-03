#include <iostream>
#include <vector>
#include <string>
#include <tuple>

// 4 internal class properties
// 1 constructor
// 1 method

class CarBoundingBox{
    float x; // width
    float y; // depth
    float z; // height
    public:
    std::vector<float> boundingBox(){
        std::vector<float> dims;
        dims.push_back(this->x);
        dims.push_back(this->y);
        dims.push_back(this->z);
        return dims;
    }

    CarBoundingBox(){}
    CarBoundingBox(std::string type){
        if(type == "default"){
            this->x = x;
        }
    }
    CarBoundingBox(float x, float y, float z){
        this->x = x;
        this->y = y;
        this->z = z;
    }
};

class Date{
    char day;
    char month;
    int year;
    

    public:
    bool produced;
    Date(){
        this->produced = 0;
    };
    Date(char day, char month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
        this->produced = 1;
    }
};

class Vehicle{
    private:
    std::string type;
    Date productionDate;
    CarBoundingBox carBoundingBox;
    std::vector<std::tuple<float,float,float>> wheelPositions; // float from 0 to 1 on bounding box
    
    public:
    Date produceDate(){
        if(this->productionDate.produced) return this->productionDate;

    }
    float wheelSpan(){
        std::vector<float> dims = this->carBoundingBox.boundingBox();
        float minX=1, maxX=0;
        for(auto& position : this->wheelPositions){
            float x = std::get<0>(position);
            x<minX ? minX = x : minX=minX;
            x>maxX ? maxX = x : maxX=maxX;
        }
        return(dims[0]*(maxX-minX));
    }

    Vehicle(){
        Date date;
        CarBoundingBox CarBoundingBox(0,0,0);
        this->productionDate = date;
    }

    Vehicle(Date productionDate, std::string type){
        this->productionDate = productionDate;
        this->type = type;
        CarBoundingBox carBoundingBox(2,2.7,1.5);
        this->carBoundingBox = carBoundingBox;

    }

    Vehicle(std::string type, Date productionDate, std::vector<std::tuple<float,float,float>> wheelPositions, CarBoundingBox carBoundingBox){
        this->type = type;
        this->productionDate = productionDate;
        this->wheelPositions = wheelPositions;
        this->carBoundingBox = carBoundingBox;
    }
};

int main(int argc, char* argv[]){

    return 0;
}