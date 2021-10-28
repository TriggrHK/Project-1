//
// Created by trevo on 10/27/2021.
//

#include "Interpreter.h"
Interpreter::Interpreter(datalogProgram newParse, Database newRelations){
parsedData = newParse;
relations = newRelations;
}

//Relation* Interpreter::evaluatePredicate(const Predicate& p){

//}

void Interpreter::Run() {
    std::vector<Predicate> schemes = parsedData.getSchemes();
    std::vector<Predicate> facts = parsedData.getFacts();
    std::vector<Predicate> queries = parsedData.getQueries();

    for(int i = 0; i < schemes.size(); i++){
        //evaluatePredicate(schemes[i]);
        //add to relation (vector of them?)
    }
    for(int i = 0; i < facts.size(); i++){
        //make a tuple then add to relation that has it's name
        //add to relation (vector of them?)
    }
    for(int i = 0; i < queries.size(); i++){
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