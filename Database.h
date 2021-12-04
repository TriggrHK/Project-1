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
public:
    Database(){}
    void addRelation(std::string name, Relation newRelation);
    void addTuple(std::string name, std::vector<std::string> tuples);
    //addRow?
    Relation& getRelation(std::string name);
    int getSize(){
        return database.size();
    }
};

#endif //PROJECT_1_DATABASE_H
