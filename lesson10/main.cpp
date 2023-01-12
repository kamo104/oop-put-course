#include <vector>
#include <iostream>
#include <string>
#include <fstream>

#include "Shiritori.h"





int main(){
    
    std::ifstream words("words.txt");
    std::string word;
    std::vector<std::string> wordList;
    while(words >> word){   
        wordList.push_back(word);
    }

    Shiritori game(wordList);
    std::string input;
    std::cout << "Welcome to Shiritori game by Kamil Grzymkowski" << "\n" << 
    "to start playing type any word" << "\n" <<
    "to restart the game type: '!restart'" << "\n";

    while(true){
        std::cin >> input;
        if(input=="!restart"){
            std::cout << game.restart() << "\n";
            continue;
        } 

        std::cout << game.play(input) << std::endl;
    }
    

    return 0;
}