    #include "lexer.h"
    using namespace std;

    int main(int argc, char **argv)
    {
        if (argc == 1)
        {
            cerr << "Filename argument required\n";
            exit (1);
        }
        ifstream yyin(argv[1]);
        if (!yyin)
        {
            cerr << "Can't read " << argv[1] << endl;
            exit(1);
        }
        Scanner scanner(&yyin, argv[1]);
        try
        {
            return scanner.yylex();
        }
        catch (Scanner::Error err)
        {
            char const *msg[] =
            {
                "Include specification",
                "Circular Include",
                "Nesting",
                "Read",
            };
            cerr << msg[err] << " error in " << scanner.lastFile() <<
                                ", line " << scanner.lineno() << endl;
            scanner.stackTrace();
            return 1;
        }
        return 0;
    }
