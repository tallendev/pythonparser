#include "ast.h"
#include <iostream>
#include "parse.tab.h"

extern FILE * yyin;
extern int keywords;
extern int identifiers;
extern int numbers;
extern int yydebug;
extern int yylineno;

int yylex(void);
extern int yyparse();
extern void yylex_destroy();
extern int num_calclist;
extern std::ofstream ast_out;

void openFile(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
      std::cerr << "Could not open file \"" 
                << filename 
                << "\"" << std::endl;
      exit(1);
    }
    yyin = file;
}

int main(int argc, char * argv[]) {
  if (argc > 1) { // user-supplied filename
    openFile(argv[1]);
  }

  std::stringstream ss;
  ss << "ast" << num_calclist++ << ".gv";
  ast_out.open(ss.str().c_str());
  yydebug = 0;//1;
  int parseErrors = yyparse();
  if ( parseErrors ) {
    std::cerr << "Abnormal termination" << std::endl;
    return 1;
  }
  ast_out.close();
  yylex_destroy();
  return 0;
}
