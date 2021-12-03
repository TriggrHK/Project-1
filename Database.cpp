//
// Created by trevo on 10/27/2021.
//

#include "Database.h"
void Database::addRelation(std::string name, Relation newRelation){
    //database.insert(std::pair<std::string,Relation>(name,newRelation));
    database[name] = newRelation;
   // database.insert({name, newRelation});
}
void Database::addTuple(std::string name, std::vector<std::string> tuples){
    Tuple newT = Tuple(tuples);
    Relation newRel = database[name];
    bool didInsert = false;
    newRel.addTuple(newT, didInsert);
    database.erase(name);
    database.insert({name, newRel});
    //newRel.toString();
}

Relation Database::getRelation(std::string name){
    Relation r = database[name];
    return r;
}
