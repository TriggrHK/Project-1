//
// Created by trevo on 10/27/2021.
//

#include "Relation.h"

Relation::Relation(std::string newName, Header newHeader){
name = newName;
header = newHeader;
}
Header Relation::getHeader(){
    return header;
}
int Relation::getNumTuples() {
    return relationList.size();
}
void Relation::addTuple(Tuple newTuple, bool &didInsert){
    didInsert = relationList.insert(newTuple).second;
}

void Relation::toString(){
    for(Tuple t: relationList){
        for(int i = 0; i < header.getSize(); i++){
            if(i == 0){
                std::cout << "  ";
            }
            if (header.getColumn(i) != t.toString(i)) {
                std::cout << header.getColumn(i) << "=" << t.toString(i);
                if(i + 1 != header.getSize() ){
                    std::cout << ", ";
                } else{
                    std::cout << "\n";
                }
            }
        }
    }
}

void Relation::setTuples(std::set<Tuple> newList){
    relationList = newList;
}
std::set<Tuple> Relation::getTuples(){
    return relationList;
}

std::string Relation::getName() {
    return name;
}

Relation Relation::select(int index, std::string value, bool &didInsert){
    //column and value to select
    Relation tempRel = Relation(this->name, this->header);
    for(Tuple t: relationList){
        if(t.getString(index) == value){
            tempRel.addTuple(t, didInsert);
        }
    }
    return tempRel;
}

Relation Relation::select(int index,  int index2, bool &didInsert){
    //relation columns to select on same values
    Relation tempRel = Relation(this->name, this->header);
    for(Tuple t: relationList){
        if(t.getString(index) == t.getString(index2)){
            tempRel.addTuple(t, didInsert);
        }
    }
    return tempRel;
}

Relation Relation::project(std::vector<int> indices, bool &didInsert){
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
        tempRel.addTuple(tempT, didInsert);
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
void Relation::unionize(Relation combineWith, bool &didInsert){
    //perform union on two relations
    for(Tuple t: combineWith.getTuples()){
        if(relationList.insert(t).second){
            //relationList.insert(t);
            std::cout << t.toString() << "\n";
            didInsert = true;
        }
    }
}

//calculate once which headers are similar for join?
Relation Relation::join(Relation combineWith, bool &didInsert) {
    std::vector<int> leftMatch;
    std::vector<int> rightMatch;
    std::vector<int> noMatch;
    //calculate columns that match values, also remember which ones in the right side don't match
    header.matchHeaders(combineWith.getHeader(), leftMatch, rightMatch, noMatch);
    Header tempHead = Header(this->header.combineHeaders(combineWith.getHeader())); //add left and non matching
    Relation tempRel = Relation(this->name, tempHead);
    std::set<Tuple> combineList = combineWith.getTuples();
    for (Tuple t1: relationList) {
        for (Tuple t2: combineList) {
            if (t1.match(t2, leftMatch, rightMatch)){ //use matching columns and make sure both work
                Tuple t = t1.combineTuples(t2, noMatch); //combine by using all left and non matching columns right
                tempRel.addTuple(t, didInsert);
            }
        }
    }
    return tempRel;
}

//Rule eval: do while loop add a counter for how many times it has interated, reloop if bool addedTuple is true