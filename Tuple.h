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
    Tuple();
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
};


#endif //PROJECT_1_TUPLE_H
