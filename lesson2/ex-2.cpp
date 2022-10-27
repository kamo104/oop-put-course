#include <iostream>
#include <vector>

class Key{
    public:
    std::string name;
};
// changing something is a verb
// getting something is a noun
class KeyChain{
    std::vector<Key> keys;

    public:
    std::vector<Key> myKeys(){
        return this->keys;
    }
    Key getHomeKey(std::string name){
        for(int i=0;i<keys.size();i++){
            if(keys[i].name=="home") return keys[i];
        }
        return keys[0];
    }
    void addKey(Key key){
        keys.push_back(key);
    }
    KeyChain(){

    }
};

int main(int argc, char* argv[]){
    

    return 0;
}