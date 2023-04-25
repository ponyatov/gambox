/// @file
/// @brief lexical skeleton
#pragma once

/// @defgroup skelex lexical skeleton

/// @ingroup skelex
/// @{
/// @name lexer

/// @brief fetch next token
extern int yylex();
/// @brief current file name
extern char* yyfile;
/// @brief current line number
extern int yylineno;
/// @brief last lexeme value
extern char* yytext;
/// @brief file input
extern FILE* yyin;

/// token constructor
#define TOKEN(C, X)               \
    {                             \
        yylval.o = new C(yytext); \
        return X;                 \
    }
/// @}

/// @name syntax parser

/// @brief run parser
extern int yyparse();

/// @brief error callback
#ifdef QT_CORE_LIB
extern void yyerror(QString msg);
#endif

// tokens and grammar elements
#include "gambox.parser.hpp"
