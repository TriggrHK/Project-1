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