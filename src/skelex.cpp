#include "gambox.hpp"

char* yyfile = nullptr;

#define YYERR "\n\n" << yyfile << ":" << msg << "[" << yytext << "]\n\n"

#ifdef QT_CORE_LIB
extern void yyerror(QString msg) {
    qDebug() << YYERR;
#endif
    exit(-1);
}
