//
// Created by trevo on 10/27/2021.
//

#ifndef PROJECT_1_DATABASE_H
#define PROJECT_1_DATABASE_H
#include <map>
#include "Relation.h"

class Database {
private:
    std::map<std::string, Relation> database;
};


#endif //PROJECT_1_DATABASE_H
