#include <iostream>
#include <vector>

class RGBVal{
    public:
        char r;
        char g; 
        char b;
};

class Apple{
    private:
        RGBVal color;
    public:
        RGBVal getColor(){
            return this->color;
        }
        Apple(RGBVal color){
            this->color = color;
        }
        Apple(){
        }

};

class AppleTree{
    public:
        std::vector<Apple> apples;

        AppleTree(int numberOfApples){

            int v1 = rand()%256;
            for(int i=0;i<numberOfApples;i++){
                RGBVal color;
                color.r = rand()%256;
                color.g = rand()%256;
                color.b = rand()%256;

                Apple apple(color);
                this->apples.push_back(apple);
            }
        
        }
        std::vector<Apple> showApples(){
            return this->apples;
        }
        Apple giveApple(int apple){
            int startingPoint =apple;
            Apple result = this->apples[apple];
            while(apple < apples.size()-1){
                apples[apple]=apples[apple+1];
                apple++;
            }
            int size = apples.size();
            apples.resize(size-5);
            return result;
        }
};

class Human{
    public:
        // communication between objects
        int countRedApples(AppleTree tree){
            int counter=0;
            for(int i=0;i<tree.apples.size();i++){
                RGBVal color = tree.apples[i].getColor();
                if(color.r>(color.b+color.g)/2)counter++;
            }
            return counter;
        }
        Apple pickRandomApple(AppleTree tree){

            return tree.giveApple(rand()%(tree.apples.size()));
        }
};

int main(){
    
    AppleTree tree(10);
    Human girl;
    std::cout << girl.countRedApples(tree) << std::endl;
    std::cout << int(girl.pickRandomApple(tree).getColor().r) << std::endl;
    std::cout << tree.showApples()[9].getColor().r << std::endl;
    return 0;
}