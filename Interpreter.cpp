//
// Created by trevo on 10/27/2021.
//

#include "Interpreter.h"
Interpreter::Interpreter(datalogProgram newParse, Database newRelations){
    parsedData = newParse;
    relations = newRelations;
    schemes = parsedData.getSchemes();
    facts = parsedData.getFacts();
    queries = parsedData.getQueries();

    for(unsigned int i = 0; i < schemes.size(); i++){
        relations.addRelation(schemes[i].getID(), evaluatePredicate(schemes[i]));
    }
    for(unsigned int i = 0; i < facts.size(); i++){
        //make a tuple then add to relation that has it's name
        //add to relation (vector of them?)
        relations.addTuple(facts[i].getID(), facts[i].getStringVect());
    }
//    std::cout << "\n" << "Number of Relations is = " << relations.getSize() << "\n";
}


Relation Interpreter::evaluatePredicate(const Predicate& p){
    Predicate tempPred = p;
    std::string name = tempPred.getID();
    std::vector<std::string> headerValues = tempPred.getStringVect();
    Header newHeader = Header(headerValues);
    Relation newRelation = Relation(name, newHeader);
    return newRelation;
}

void Interpreter::Run() {
/*
    std::cout << "scheme size is " << schemes.size() << "\n";
    std::cout << "facts size is " << facts.size() << "\n";
    std::cout << "queries size is " << queries.size() << "\n";
*/
    //std::cout << "\n" << "Number of Relations is = " << relations.getSize() << "\n";

    for(unsigned int k = 0; k < queries.size(); k++) {
        std::map<std::string, int> savedVars;
        std::vector<Parameter> tempList = queries[k].getParamVect();
        Relation compareRel = relations.getRelation(queries[k].getID());
        std::vector<int> seenCol;
        for (unsigned int i = 0; i < tempList.size(); i++) {
            if (tempList[i].isConst()) {
                //save to do type one project
                compareRel = compareRel.select(i, tempList[i].getParam()); ///do we want i?
            } else if (i < tempList.size()) {
                if(savedVars.find(tempList[i].getParam()) == savedVars.end()){
                seenCol.push_back(i);
                savedVars[tempList[i].getParam()] = i;
                }
                compareRel = compareRel.select(savedVars[tempList[i].getParam()], i);
                /*
                if(!tempList[i+1].isConst() && (tempList[i].getParam() == tempList[i+1].getParam())){
                    compareRel= compareRel.select(i, i+1);
                } ///do we want i?
                else if (!tempList[i+1].isConst()){
                    compareRel= compareRel.select(i, i);
                }*/
            }
        }
        compareRel = compareRel.rename(queries[k].getStringVect());
        compareRel = compareRel.project(seenCol);
        ///print function
        queries[k].to_String();
        std::cout << "? ";
        if (compareRel.getNumTuples() > 0) {
            std::cout << "Yes(" << compareRel.getNumTuples() << ")\n";
            compareRel.toString();
            //std::cout << "\n";
/*
            for (unsigned int j = 0; j < compareRel.getNumTuples(); j++) {
                std::cout << "\t" << queries[k].getStringAt(j) << "=";
                //get value to go on side of equals
                std::cout << "\n";
            }
*/
        } else {
            std::cout << "No\n";
        }
        //Relation tempRel = evaluatePredicate(queries[k]);
/*get the relation ‘r’ with the same name as the query ‘q’
                   select for each constant in the query ‘q’
                   select for each pair of matching variables in ‘q’
                   project using the positions of the variables in ‘q’
                   rename to match the names of variables in ‘q’
                   print the resulting relation*/

    }
return;
}




/*
for each scheme ‘s’
create a relation using name and parameter values from ‘s’
for each fact ‘f’
make a tuple ‘t’ using the values from ‘f’
add ‘t’ to relation with the same name as ‘f’
for each query ‘q’
get the relation ‘r’ with the same name as the query ‘q’
select for each constant in the query ‘q’
select for each pair of matching variables in ‘q’
project using the positions of the variables in ‘q’
rename to match the names of variables in ‘q’
print the resulting relatio
 */