//
// Created by trevo on 9/29/2021.
//
#include "Rule.h"

Rule::Rule(Predicate inPred, std::vector<Predicate> inPredVector) {
    headPredicate = inPred;
    bodyPredicates = inPredVector;
}
void Rule::to_String() {
    headPredicate.to_String();
    std::cout << " :- ";
    for(int i = 0; i < bodyPredicates.size(); i++){
        bodyPredicates[i].to_String();
    }
    std::cout << ".";
}