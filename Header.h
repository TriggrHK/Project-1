//
// Created by trevo on 10/27/2021.
//

#ifndef PROJECT_1_HEADER_H
#define PROJECT_1_HEADER_H
#include <string>
#include <vector>

class Header {
private :
    std::vector<std::string> attributes;
public:
    Header(){}
    Header(std::vector<std::string> newHeader){
        attributes = newHeader;
    }
};


#endif //PROJECT_1_HEADER_H
