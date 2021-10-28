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

   // for(unsigned int i = 0; i < queries.size(); i++){
        /*get the relation ‘r’ with the same name as the query ‘q’
            select for each constant in the query ‘q’
            select for each pair of matching variables in ‘q’
            project using the positions of the variables in ‘q’
            rename to match the names of variables in ‘q’
            print the resulting relation*/
   // }
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