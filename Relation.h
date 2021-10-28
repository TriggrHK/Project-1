//
// Created by trevo on 10/27/2021.
//

#ifndef PROJECT_1_RELATION_H
#define PROJECT_1_RELATION_H
#include <set>
#include "iostream"
#include "Tuple.h"
#include "Header.h"
class Relation {
//toString... for(Tuple T: mySet){cout << t.toString();}
//for each loop on the set
private:
    std::set<Tuple> relationList;
    std::string name;
    Header header;
public:
    Relation(std::string newName, Header newHeader){
        name = newName;
        header = newHeader;
    }
    void addTuple(Tuple newTuple){
        relationList.insert(newTuple);
    }
    void toString(){
        for(Tuple t: relationList){
            //std::cout << t.toString(); add toString for the Tuple
        }
    }
    Relation select(int index, std::string value);//column and value to select
    Relation select(int index,  int index2);//relation columns to select on same values
    Relation project(std::vector<std::string> indices);//set columns to keep
    Relation rename(std::vector<std::string> attributes); //define new header

};


#endif //PROJECT_1_RELATION_H
