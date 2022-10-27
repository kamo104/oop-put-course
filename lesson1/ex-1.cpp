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
        RGBVal Color;
    public:
        RGBVal getColor(){
            return this->Color;
        }
        Apple(RGBVal Color){
            this->Color = Color;
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
                RGBVal Color;
                Color.r = rand()%256;
                Color.g = rand()%256;
                Color.b = rand()%256;

                Apple Apple(Color);
                this->apples.push_back(Apple);
            }
        
        }
        std::vector<Apple>& showApples(){
            return this->apples;
        }
        Apple giveApple(int apple){
            int startingPoint =apple;
            Apple Result = this->apples[apple];
            while(apple < this->apples.size()-1){
                this->apples[apple]=this->apples[apple+1];
                
                apple++;
            }
            //int size = apples.size();
            this->apples.resize(1);
            //std::cout << this->apples.size() << "\n";
            return Result;
        }
};

class Human{
    public:
        // communication between objects
        int countRedApples(AppleTree Tree){
            int counter=0;
            for(int i=0;i<Tree.apples.size();i++){
                RGBVal Color = Tree.apples[i].getColor();
                if(Color.r>(Color.b+Color.g)/2)counter++;
            }
            return counter;
        }
        Apple pickRandomApple(AppleTree Tree){
            return Tree.giveApple(rand()%(Tree.apples.size()));
        }
};

int main(){
    
    AppleTree Tree(10);
    Human Girl;
    std::cout << Girl.countRedApples(Tree) << std::endl;
    std::cout << int(Girl.pickRandomApple(Tree).getColor().r) << std::endl;
    std::cout << Tree.apples.size() << "\n";
    // std::cout << (int)Tree.apples[8].getColor().r << " " << (int)Tree.apples[9].getColor().r << std::endl;
    return 0;
}