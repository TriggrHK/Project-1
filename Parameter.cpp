//
// Created by trevo on 9/29/2021.
//

#include "Parameter.h"
void Parameter::to_String() {
    std::cout << param;
}
std::string Parameter::getParam() {
    return param;
}
bool Parameter::isConst() {
    if(param[0] == '\''){
        return true;
    }
    else{
        return false;
    }
}