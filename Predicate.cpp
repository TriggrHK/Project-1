//
// Created by trevo on 9/29/2021.
//

#include "Predicate.h"
Predicate::Predicate(std::string inID, std::vector<Parameter> inVec) {
    predID = inID;
    predParameter = inVec;
}
void Predicate::to_String() {
 std::cout << predID << "(";
 for(unsigned int i = 0; i < predParameter.size(); i++){
     predParameter[i].to_String();
     if(i + 1 < predParameter.size()){
         std::cout << ",";
     }
 }
 std::cout << ")";
}

std::string Predicate::getID(){
    return predID;
}
std::string Predicate::getStringAt(int index){
    return predParameter[index].getParam();
}

std::vector<std::string> Predicate::getStringVect(){
    std::vector<std::string> newString;
    for(unsigned int i = 0; i < predParameter.size(); i++){
        newString.push_back(predParameter[i].getParam());
    }
    return newString;
}

std::vector<Parameter> Predicate::getParamVect(){
    return predParameter;
}

int Predicate::getParamSize() {
    return predParameter.size();
}

