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
private:
    std::set<Tuple> relationList;
    std::string name;
    Header header;
public:
    Relation(){}
    Relation(std::string newName, Header newHeader);
    void addTuple(Tuple newTuple);
    void toString();
    void setTuples(std::set<Tuple> newList);
    int getNumTuples();
    Header getHeader();
    std::string getName();
    std::set<Tuple> getTuples();
    Relation select(int index, std::string value);//column and value to select
    Relation select(int index,  int index2);//relation columns to select on same values
    Relation project(std::vector<int> indices);//set columns to keep
    Relation rename(std::vector<std::string> attributes); //define new header
    void unionize(Relation combineWith, bool &didInsert); //combine two Relations
    Relation join(Relation combineWith); //natural join to relations
};


#endif //PROJECT_1_RELATION_H
