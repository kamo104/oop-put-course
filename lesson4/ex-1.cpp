#include <iostream>
#include <vector>
#include <string>
#include <tuple>

class RGBVal{
    char r;
    char g; 
    char b;
    public:
    RGBVal& operator*(float val){
        RGBVal v;
        v.r = this->r*val;
        v.g = this->g*val;
        v.b = this->b*val;
        return v;
    }
};

template<class T>
class Vector3{
    T values[3];
    public:
    T x(){
        return this->values[0];
    }
    T y(){
        return this->values[1];
    }
    T z(){
        return this->values[2];
    }
};

template<class T>
class Vector2{
    T values[2];
    public:
    T x(){
        return this->values[0];
    }
    T y(){
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
    template<class T>
    class Map{
        public: //
        int shader;
        virtual Voxel at(Vector3<T>) const = 0; // read only
        virtual Map* ChangeColorWithShader(Vector3<T>, RGBVal)const = 0 ;
    };
}


class Map3D : Build::Map<float>{
    std::vector<std::vector<std::vector<Voxel>>> map;

    public:
    Voxel at(Vector3<float> position){ 
        return map[position.x()][position.y()][position.z()].copy();
    }
    Map* ChangeColorWithShader(Vector3<float> position, RGBVal color){
        this->map[position.x()][position.y()][position.z()].color = color*this->shader;
        return this;
    }
};

class Map2D : Build::Map<float>{
    std::vector<std::vector<Voxel>> map;

    public:
    Voxel at(Vector3<float> position){
        return map[position.x()][position.y()].copy();
    }

    Map* ChangeColorWithShader(Vector2<float> position, RGBVal color){
        this->map[position.x()][position.y()].color = color*this->shader;
        return this;
    }
};

int main(){

    return 0;
}