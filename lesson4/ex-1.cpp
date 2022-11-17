#include <iostream>
#include <vector>
#include <string>
#include <tuple>

struct RGBVal{
    char r;
    char g; 
    char b;
};


class Vector3D{
    float values[2];
    public:
    float x(){
        return this->values[0];
    }
    float y(){
        return this->values[1];
    }
    float z(){
        return this->values[1];
    }
};

class Vector2D{
    float values[2];
    public:
    float x(){
        return this->values[0];
    }
    float y(){
        return this->values[1];
    }

};

class Voxel{
    public:
    RGBVal color;
    Voxel copy(){
        Voxel v(this->color);
        return v;
    }
    Voxel(RGBVal){}
};

namespace Build{
    class Map{
        // std::vector<std::vector<std::vector<Voxel>>> map;
        public:
        int shader;
        virtual Voxel at(Vector3D){} // read only
        virtual Map ChangeColorWithShader(Vector3D, RGBVal){

        }
    };
}


class Map3D : Build::Map{
    std::vector<std::vector<std::vector<Voxel>>> map;
    public:
    Voxel at(Vector3D position){ 
        return map[position.x()][position.y()][position.z()].copy();
    }
    void ChangeColorWithShader(Vector3D position, RGBVal color){
        this->map[position.x()][position.y()][position.z()].color = color*this->shader;
    }
};

class Map2D : Build::Map{
    std::vector<std::vector<Voxel>> map;
    public:
    Voxel at(Vector3D position){
        return map[position.x()][position.y()].copy();
    }
};

int main(){

    return 0;
}