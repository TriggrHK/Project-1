//
// Created by trevo on 10/27/2021.
//

#include "Interpreter.h"
Interpreter::Interpreter(datalogProgram newParse, Database newRelations){
    parsedData = newParse;
    relations = newRelations;
    rules = parsedData.getRules();
    schemes = parsedData.getSchemes();
    facts = parsedData.getFacts();
    queries = parsedData.getQueries();

    /*for(unsigned int i = 0; i < schemes.size(); i++){
        relations.addRelation(schemes[i].getID(), evaluatePredicate(schemes[i]));
    }*/
    for(unsigned int i = 0; i < schemes.size(); i++) {
        relations.addRelation(schemes[i].getID(), createPredicates(schemes[i]));
    }
    for(unsigned int i = 0; i < facts.size(); i++){
        //make a tuple then add to relation that has it's name
        //add to relation (vector of them?)
        relations.addTuple(facts[i].getID(), facts[i].getStringVect());
    }
//    std::cout << "\n" << "Number of Relations is = " << relations.getSize() << "\n";
}

//Relation evaluateRule{ do{}while(addedTuple == True);

void Interpreter::Run() {
    //  std::cout << "scheme size is " << schemes.size() << "\n"; std::cout << "facts size is " << facts.size() << "\n"; std::cout << "queries size is " << queries.size() << "\n"; std::cout << "\n" << "Number of Relations is = " << relations.getSize() << "\n";

    std::cout << "Rule Evaluation\n";
    evaluateRules();
    std::cout << "Query Evaluation\n";
    evaluateQueries();
    return;
}

Relation Interpreter::createPredicates(const Predicate& p){
    Predicate tempPred = p;
    std::string name = tempPred.getID();
    std::vector<std::string> headerValues = tempPred.getStringVect();
    Header newHeader = Header(headerValues);
    Relation newRelation = Relation(name, newHeader);
    return newRelation;
}

Relation Interpreter::evaluatePredicate(Predicate p, Relation compareRel) {
    std::map<std::string, int> savedVars;
    std::vector<Parameter> tempList = p.getParamVect();
    std::vector<int> seenCol;
    bool didInsert;
    for (unsigned int i = 0; i < tempList.size(); i++) {
        if (tempList[i].isConst()) {
            compareRel = compareRel.select(i, tempList[i].getParam(),didInsert);
        } else if (i < tempList.size()) {
            if(savedVars.find(tempList[i].getParam()) == savedVars.end()){
                seenCol.push_back(i);
                savedVars[tempList[i].getParam()] = i;
            }
            compareRel = compareRel.select(savedVars[tempList[i].getParam()], i, didInsert);
        }
    }
    compareRel = compareRel.rename(p.getStringVect());
    compareRel = compareRel.project(seenCol, didInsert);
    return compareRel;
}

void Interpreter::evaluateRules(){
    bool changedRule = false;
    int iterationCount = 0;
    do {
        changedRule = false;
        bool testB = false;
        for (unsigned int i = 0; i < rules.size(); i++) {
            rules[i].to_String();
            std::vector<Relation> intermediateResults;
            Relation stepTwoResult;
            std::vector<Predicate> tempPred = rules[i].getRightHand();
            for (unsigned int k = 0; k < tempPred.size(); k++) {
                Relation compareRel = relations.getRelation(tempPred[k].getID());
                compareRel = evaluatePredicate(tempPred[k], compareRel);
                intermediateResults.push_back(compareRel);
                ///step two join the relations
                if(intermediateResults.size() > 1){
                        stepTwoResult = intermediateResults[0].join(intermediateResults[1], testB);
                    for(unsigned int j = 2; j < intermediateResults.size(); j++){
                        stepTwoResult = stepTwoResult.join(intermediateResults[j], testB);
                    }
                }
                ///if only one relation
                else{
                    stepTwoResult = intermediateResults[0];
                }
                ///project the result
                std::vector<int> seenCol;
                for(unsigned int g = 0; g < stepTwoResult.getHeader().getSize(); g++){
                    for(unsigned int h = 0; h < rules[i].getHead().getParamSize(); h++){
                        if(stepTwoResult.getHeader().getColumn(g) == rules[i].getHead().getStringAt(h)){
                            seenCol.push_back(g);
                        }
                    }
                }
                stepTwoResult.project(seenCol, testB);
                ///rename
                ///union
                stepTwoResult.unionize(relations.getRelation(stepTwoResult.getName()), changedRule);
                ///print function
             //   tempPred[k].to_String();
/*
                if(iterationCount == 0) {
                    std::cout << "\n";
                }
*/
                /*if (compareRel.getNumTuples() > 0) {
                    compareRel.toString();
                }*/
            }
        }
        iterationCount++;
        if(iterationCount > 2){changedRule = false;}
    }while(changedRule);
    std::cout << "\nSchemes populated after " << iterationCount << " passes through the Rules.\n\n";
}

void Interpreter::evaluateQueries(){
    for(unsigned int k = 0; k < queries.size(); k++) {
        Relation compareRel = relations.getRelation(queries[k].getID());
        compareRel = evaluatePredicate(queries[k],compareRel);
        ///print function
        queries[k].to_String();
        std::cout << "? ";
        if (compareRel.getNumTuples() > 0) {
            std::cout << "Yes(" << compareRel.getNumTuples() << ")\n";
            compareRel.toString();
        } else {
            std::cout << "No\n";
        }
    }
}



/*Relation Interpreter::evaluatePredicate(const Predicate& p){
    Predicate tempPred = p;
    std::string name = tempPred.getID();
    std::vector<std::string> headerValues = tempPred.getStringVect();
    Header newHeader = Header(headerValues);
    Relation newRelation = Relation(name, newHeader);
    return newRelation;
}

void Interpreter::evaluateQueries(){
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
        } else {
            std::cout << "No\n";
        }
    }
}*/