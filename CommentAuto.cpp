//
// Created by trevo on 9/13/2021.
//
#include "CommentAuto.h"

void CommentAuto::S0(const std::string& input) {
    if (input[index] == '#') {
        inputRead = 1;
        index++;
        S1(input);
    }
    else {
        Serr();
    }
}
void CommentAuto::S1(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S2(input);
    }
    else {
        while (input[index] != '\n'){
        inputRead++;
        index++;
        }
    }
}

void CommentAuto::S2(const std::string& input) {
    if (input[index] == '|') {
        inputRead++;
        index++;
        S3(input);
    }
    else {
        if (input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}

void CommentAuto::S3(const std::string& input) {
    if (input[index] == '#') {
        inputRead++;
        index++;
    }
    else if (input[index] == '|'){
        inputRead++;
        index++;
        S3(input);
    }
    else {
        if (input[index] == '\n'){
            newLines++;
        }
        inputRead++;
        index++;
        S2(input);
    }
}
