//
// Created by trevo on 10/27/2021.
//

#include "Relation.h"

Relation::Relation(std::string newName, Header newHeader){
name = newName;
header = newHeader;
}

int Relation::getNumTuples() {
    return relationList.size();
}
void Relation::addTuple(Tuple newTuple){
    relationList.insert(newTuple);
}

void Relation::toString(){
    for(Tuple t: relationList){
        std::cout << t.toString(); //add toString for the Tuple
    }
}

void Relation::setTuples(std::set<Tuple> newList){
    relationList = newList;
}


Relation Relation::select(int index, std::string value){
    //column and value to select
    Relation tempRel = Relation(this->name, this->header);
    for(Tuple t: relationList){
        if(t.getString(index) == value){
            tempRel.addTuple(t);
        }
    }
    return tempRel;
}

Relation Relation::select(int index,  int index2){
    //relation columns to select on same values
    Relation tempRel = Relation(this->name, this->header);
    for(Tuple t: relationList){
        if(t.getString(index) == t.getString(index2)){
            tempRel.addTuple(t);
        }
    }
    return tempRel;
}

Relation Relation::project(std::vector<int> indices){
    //set columns to keep
    std::vector<std::string> projectHead;
    for(unsigned int i = 0; i < indices.size(); i++){
        projectHead.push_back(header.getColumn(indices[i]));
    }
    Header tempHead = Header(projectHead);
    Relation tempRel = Relation(this->name, tempHead);
    for(Tuple t: relationList){
        std::vector<std::string> tempString;
        for(unsigned int i = 0; i < indices.size(); i++){
            tempString.push_back(t.getString(indices[i]));
        }
        Tuple tempT = Tuple(tempString);
        tempRel.addTuple(tempT);
    }
    return tempRel;
}

Relation Relation::rename(std::vector<std::string> attributes){
    //define new header
    Header tempHead = Header(attributes);
    Relation tempRel = Relation(this->name, tempHead);
    tempRel.setTuples(this->relationList);
    return tempRel;
}
