#pragma once

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

class Word final {
    private:
    std::string text;
    std::string lowerCaseText;

    public:
    bool operator!=(Word otherWord){
        return otherWord.lowerCase()!=this->lowerCase()?true:false;
    }
    bool operator==(Word otherWord){
        return otherWord.lowerCase()==this->lowerCase()?true:false;
    }
    char operator[](size_t where){
        return this->lowerCaseText[where];
    }

    std::string characters(){
        return this->text;
    }
    std::string lowerCase(){
        return this->lowerCaseText;
    }
    size_t size(){
        return this->text.size();
    }
    Word(std::string text){
        this->text = text;

        // create a lowercase version
        std::string temp(text);
        std::transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        this->lowerCaseText = temp;
    }
};


class Shiritori final{
    std::vector<Word> words;
    std::vector<Word> possibleWords;
    bool useWordList=false;
    bool gameOver=false;
    
    // returns 1 if the word is valid
    // returning 0 is possible if needed for any reason (unexplained) but still ends the game
    // returns -1 if it is invalid by the first condition
    // returns -2 if it is invalid by the second condition
    // returns -3 if it is not in the dictionary
    int isWordValid(Word word){
        if(this->useWordList){
            bool appeared=false;
            for(Word &temp:this->possibleWords){
                if(temp==word) appeared=true;
            }
            
            if(appeared==false) return -3;
        }

        if(this->words.size()<=0) return true;

        Word lastWord = this->words[this->words.size()-1];
        
        bool wordRepeated=false;
        for(Word &temp:this->words) if (temp==word) wordRepeated = true;

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
        for(Word &word:this->words){
            
            output.append(word.characters());
            
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
    Shiritori(std::vector<Word> possibleWords){
        this->useWordList = true;
        this->possibleWords = possibleWords;
    }
};
