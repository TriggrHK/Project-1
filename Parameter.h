//
// Created by trevo on 9/29/2021.
//

#ifndef PROJECT_1_PARAMETER_H
#define PROJECT_1_PARAMETER_H
#include <iostream>

class Parameter {
private:
    std::string param;
public:
    Parameter(std::string inString){param = inString;}
    void to_String();
    std::string getParam();
    bool isConst();
};


#endif //PROJECT_1_PARAMETER_H
