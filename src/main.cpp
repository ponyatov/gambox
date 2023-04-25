#include "gambox.hpp"

int main(int argc, char* argv[]) {
    init(argc, argv);
    for (int i = 1; i < argc; i++) {
        arg(i, argv[i]);
        yyfile = argv[i];
        assert(yyin = fopen(yyfile, "r"));
        yyparse();
        fclose(yyin);
    }
    return fini();
}

void arg(int argc, char* argv) {
#ifdef QT_CORE_LIB
    qDebug() << "argv[" << argc << "] = <" << argv << "]";
#else
#error Qt
    printf("argv[%i] = <%s>\n", argc, argv);
#endif
}

void init(int& argc, char* argv[]) {
    arg(0, argv[0]);
#ifdef QT_CORE_LIB
    assert(!GUI::gui);
    assert(GUI::gui = new GUI());
#else
#error
#endif
}

int fini(int err) {
    exit(err);
    return err;
}
