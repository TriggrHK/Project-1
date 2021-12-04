//
// Created by trevo on 10/27/2021.
//

#ifndef PROJECT_1_HEADER_H
#define PROJECT_1_HEADER_H
#include <string>
#include <vector>
#include <set>

class Header {
private :
    std::vector<std::string> attributes;
public:
    Header(){}
    Header(std::vector<std::string> newHeader){
        attributes = newHeader;
    }
    std::string getColumn(int index){
        return attributes[index];
    }
    int getSize(){
        return attributes.size();
    }
    Header getAttributes(){
        return attributes;
    }
    void matchHeaders(Header compareWith, std::vector<int> &left, std::vector<int> &right, std::vector<int> &noMatch){
       for(int k = 0; k < compareWith.getSize(); k++){
           noMatch.push_back(k);
       }
        for(unsigned int i = 0; i < attributes.size(); i++){
            for(int j = 0; j < compareWith.getSize(); j++){
                if(attributes[i] == compareWith.getColumn(j)){
                    left.push_back(i);
                    right.push_back(j);
                }
            }
        }
        for(unsigned int i = 0; i < right.size(); i++){
            for(unsigned int j = 0; j < noMatch.size(); j++){
                if(right[i] == noMatch[j]){
                    noMatch.erase(noMatch.begin()+j);
                }
            }
        }
    }

    std::vector<std::string> combineHeaders(Header combineWith){
        std::vector<std::string> tempVect = attributes;
        for(int i = 0; i < combineWith.getSize(); i++){
            bool matches = false;
            for(unsigned int j = 0; j < tempVect.size(); j++){ ///is this going to work?
                if(tempVect[j] == combineWith.getColumn(i)){
                    matches = true;
                }
            }
            if(!matches){
                tempVect.push_back(combineWith.getColumn(i));
            }
        }
        return tempVect;
    }
};


#endif //PROJECT_1_HEADER_H
