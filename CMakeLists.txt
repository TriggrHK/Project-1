cmake_minimum_required(VERSION 3.16)

project(Project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_1
        Automaton.h
        ColonAuto.cpp
        ColonAuto.h
        ColonDashAuto.cpp
        ColonDashAuto.h
        Lexer.cpp
        Lexer.h
        main.cpp
        Token.cpp
        Token.h
        QueriesAuto.h
        IdAuto.h
        CommaAuto.h
        LP_Auto.h
        Q_MarkAuto.h
        RulesAuto.h
        RP_Auto.h
        StringAuto.h
        PeriodAuto.h
        EOF_CPAuto.h
        SchemesAuto.h
        CommentAuto.h
        CommaAuto.cpp
        CommentAuto.cpp
        EOF_CPAuto.cpp
        IdAuto.cpp
        LP_Auto.cpp
        PeriodAuto.cpp
        Q_MarkAuto.cpp
        QueriesAuto.cpp
        RP_Auto.cpp
        RulesAuto.cpp
        SchemesAuto.cpp
        StringAuto.cpp MultAuto.cpp MultAuto.h AddAuto.cpp AddAuto.h FactsAuto.cpp FactsAuto.h UndefinedAuto.cpp UndefinedAuto.h)
