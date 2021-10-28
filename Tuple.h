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
    bool operator< (const Tuple &rhs) const {
        return values < rhs.values;
    }
};


#endif //PROJECT_1_TUPLE_H
