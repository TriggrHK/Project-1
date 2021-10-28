//
// Created by trevo on 10/27/2021.
//

#include "Relation.h"

Relation::Relation(std::string newName, Header newHeader){
name = newName;
header = newHeader;
}

void Relation::addTuple(Tuple newTuple){
    relationList.insert(newTuple);
}

void Relation::toString(){
    for(Tuple t: relationList){
        std::cout << t.toString(); //add toString for the Tuple
    }
}
/*
Relation Relation::select(int index, std::string value){
    //column and value to select

}

Relation Relation::select(int index,  int index2){
    //relation columns to select on same values

}

Relation Relation::project(std::vector<std::string> indices){
    //set columns to keep

}

Relation Relation::rename(std::vector<std::string> attributes){
    //define new header

}
*/
