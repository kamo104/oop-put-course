#include <iostream>
#include <vector>
#include <string>


class RGBVal{
    public:
        char r;
        char g; 
        char b;
};

// a lens only tints a view in (my)sunglasses 
// RGBVal(255,255,255) would mean that it's clear and doesn't obscure any colors from getting through 
// RGBVal(0,0,0) would not let any light through
class SunGlassesLens{
    public:
        RGBVal color;
    SunGlassesLens(){}
    SunGlassesLens(RGBVal Color){
        this->color = Color;
    }
    SunGlassesLens(char r, char g, char b){
        RGBVal Color;
        Color.r = r;
        Color.g = g;
        Color.b = b;
        this->color = Color;
    }
};

class GlassesRim{
    public:
        RGBVal color;
    GlassesRim(){}
    GlassesRim(RGBVal Color){
        this->color = Color;
    }
    GlassesRim(char r, char g, char b){
        RGBVal Color;
        Color.r = r;
        Color.g = g;
        Color.b = b;
        this->color = Color;
    }
};

enum RimType {
    Wood,
    Steel,
};
RimType getRimType(std::string rimType);

enum LensType {
    Tinted,
    Clear,
};
LensType getLensType(std::string lensType);
class SunGlasses{
    std::pair<SunGlassesLens,SunGlassesLens> lenses;
    GlassesRim Rim;
    public:
    SunGlasses(){
    }
    
    SunGlasses(std::string lensType, std::string rimColor){
        switch(getLensType(lensType)){
            case(0):{
                SunGlassesLens Lens(125,125,125);
                this->lenses = std::make_pair(Lens,Lens);
                break;
            }
            case(1):{
                SunGlassesLens Lens(255,255,255);
                this->lenses = std::make_pair(Lens,Lens);
                break;
            }
        }
        switch(getRimType(lensType)){
            case(0):{
                GlassesRim Rim(152,92,42);
                this->Rim = Rim;
                break;
            }
            case(1):{
                GlassesRim Rim(152,92,42);
                this->Rim = Rim;
                break;
            }
        }
    }
    
    SunGlasses(SunGlassesLens Lens1, SunGlassesLens Lens2, RGBVal RimMaterial){
        this->lenses = std::make_pair(Lens1,Lens2);
        GlassesRim Rim(RimMaterial.r,RimMaterial.g,RimMaterial.b);
        this->Rim = Rim;
    }

    SunGlasses(std::string lensType, RGBVal RimMaterial){
        switch(getLensType(lensType)){
            case(0):{
                SunGlassesLens Lens(125,125,125);
                this->lenses = std::make_pair(Lens,Lens);
                break;
            }
            case(1):{
                SunGlassesLens Lens(255,255,255);
                this->lenses = std::make_pair(Lens,Lens);
                break;
            }
        }

        GlassesRim Rim(RimMaterial.r,RimMaterial.g,RimMaterial.b);
        this->Rim = Rim;
    }

    SunGlasses(RGBVal LensTint, RGBVal RimMaterial){
        SunGlassesLens Lens(LensTint.r,LensTint.g,LensTint.b);
        this->lenses = std::make_pair(Lens,Lens);
        GlassesRim Rim(RimMaterial.r,RimMaterial.g,RimMaterial.b);
        this->Rim = Rim;
    }
};

int main(int argc, char* argv[]){
    SunGlasses SteelRimGlasses();

    return 0;
}