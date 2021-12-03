//
// Created by trevo on 9/29/2021.
//

#ifndef PROJECT_1_PREDICATE_H
#define PROJECT_1_PREDICATE_H
#include <vector>
#include <iostream>
#include "Parameter.h"

class Predicate {
private:
    std::string predID;
    std::vector<Parameter> predParameter;
public:
    Predicate(std::string inID, std::vector<Parameter> inVec);
    Predicate(){}
    void to_String();
    std::string getID();
    std::vector<std::string> getStringVect();
    std::vector<Parameter> getParamVect();
    int getParamSize();
    std::string getStringAt(int index);
};

#endif //PROJECT_1_PREDICATE_H
