cmake_minimum_required(VERSION 3.16)

project(Project_1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project_1
        Automaton.h
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
        CommentAuto.cpp
        IdAuto.cpp
        QueriesAuto.cpp
        RulesAuto.cpp
        SchemesAuto.cpp
        StringAuto.cpp MultAuto.h AddAuto.h FactsAuto.cpp FactsAuto.h UndefinedAuto.cpp UndefinedAuto.h Parser.cpp Parser.h)
