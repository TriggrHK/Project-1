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
    if (!input.empty()) {
        if (input[0] == '|') {
            inputRead++;
            index++;
            S3(input.substr(1));
        } else {
            if (input[0] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S2(input.substr(1));
        }
    }
    else{
        Serr();
    }
}

void CommentAuto::S3(const std::string& input) {
    if (!input.empty()) {
        if (input[0] == '#') {
            inputRead++;
            index++;
        } else if (input[0] == '|') {
            inputRead++;
            index++;
            S3(input.substr(1));
        } else {
            if (input[0] == '\n') {
                newLines++;
            }
            inputRead++;
            index++;
            S2(input.substr(1));
        }
    }
    else{
        Serr();
    }
}
