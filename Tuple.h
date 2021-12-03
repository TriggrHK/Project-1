//
// Created by trevo on 10/27/2021.
//

#ifndef PROJECT_1_TUPLE_H
#define PROJECT_1_TUPLE_H
#include <vector>
#include <string>

class Tuple {
private:
    std::vector<std::string> values;
public:
    Tuple(){}
    Tuple(std::vector<std::string> newValues){
        values = newValues;
    }
    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
    std::string toString(){
        std::string allVals = "";
        for(unsigned int i = 0; i < values.size(); i++){
            allVals = allVals + " " + values[i];
        }
        return allVals;
    }
    std::string toString(int index){
        std::string allVals = "";
        allVals = values[index];
        return allVals;
    }
    std::vector<std::string> getValues(){
        return values;
    }
    std::string getString(int index){
        std::string tempString = values[index];
        return tempString;
    }
    bool match(Tuple input, std::vector<int> leftMatch, std::vector<int> rightMatch){
        for(unsigned int i = 0; i < leftMatch.size(); i++){
            if(!(values[leftMatch[i]] == input.values[rightMatch[i]])){
                return false;
            }
        }
        return true;
    }
    Tuple combineTuples(Tuple input, std::vector<int> noMatch){
        std::vector<std::string> tempVals = values;
        for(unsigned int i = 0; i < noMatch.size(); i++){
            tempVals.push_back(input.getString(noMatch[i]));
        }
        Tuple t = Tuple(tempVals);
        return t;
    }
};


#endif //PROJECT_1_TUPLE_H
