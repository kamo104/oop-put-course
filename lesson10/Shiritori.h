#pragma once

#include <vector>
#include <string>
#include <iostream>

// bak[e] -> [!e]agle == condition 1
// no repeating one word == condition 2



// has words
// boolean game_over

// instance methods:
// play(string word) right word prints current words, wrong word prints "x does not start with letter 'a'"
// restart() [restarts the game]

// class Shiritori{
//     public:
//     virtual std::string play(std::string)=0;

// };


class Shiritori final{
    std::vector<std::string> words;
    std::vector<std::string> possibleWords;
    bool useWordList=false;
    bool gameOver=false;
    
    // returns 1 if the word is valid
    // returning 0 is possible if needed for any reason (unexplained) but still ends the game
    // returns -1 if it is invalid by the first condition
    // returns -2 if it is invalid by the second condition
    // returns -3 if it is not in the dictionary
    int isWordValid(std::string word){
        if(this->useWordList){
            bool appeared=false;
            for(std::string &temp:this->possibleWords){
                if(temp==word) appeared=true;
            }
            
            if(appeared==false) return -3;
        }

        if(this->words.size()<=0) return true;

        std::string lastWord = this->words[this->words.size()-1];
        
        bool wordRepeated=false;
        for(std::string &temp:this->words) if (temp==word) wordRepeated = true;

        if( wordRepeated==true ) return -2;
        if( lastWord[lastWord.size()-1]!=word[0] ) return -1;

        

        return 1;
    }

    public:
    std::string play(std::string word){
        if(this->gameOver==true) return "The game has already ended";

        std::string output;
        int isValid = this->isWordValid(word);
        switch(isValid){
            case(0):{
                std::cout<< "for some reason your input is incorrect" << "endl";
                this->gameOver = true;
                return "game over";
            }
            case(1):{
                words.push_back(word);
                return this->printWords();
            }
            case(-1):{
                
                std::cout << "'" << word[0] << "' is different from '" << this->words[this->words.size()-1][this->words[this->words.size()-1].size()-1] << "'!" << std::endl;
                this->gameOver = true;
                return "game over";
            }
            case(-2):{
                
                std::cout << "this word has already been used!" << std::endl;
                this->gameOver = true;
                return "game over";
            }
            case(-3):{
                std::cout << word << " is not in the dictionary!!" << std::endl;
                this->gameOver = true;
                return "game over";
            }
        }
        return "";
    }
    std::string printWords(){
        std::string output = "[";
        for(std::string &word:this->words){
            
            output.append(word);
            
            if(word!=this->words[this->words.size()-1])
            output.append(", ");
        }
        output.append("]");
        return output;
    }
    std::string restart(){
        this->words.clear();
        this->gameOver = false;
        return "game restarted!";
    }

    Shiritori(){}
    Shiritori(std::vector<std::string> possibleWords){
        this->useWordList = true;
        this->possibleWords = possibleWords;
    }
};
