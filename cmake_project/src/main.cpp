#include <iostream>

#include "antlr4-runtime.h"
#include "PythonLexer.h"
#include "PythonParser.h"

#include <filesystem>

#pragma execution_character_set("utf-8")

using namespace antlr4;
using namespace std;

int main(int argc, const char * argv[]) {
	ifstream inputFile("./examples/testfile.py");

	std::cout << std::filesystem::current_path() << std::endl;
	stringstream inputBuffer;

	if(inputFile.is_open()){
		inputBuffer << inputFile.rdbuf();
	}else{
		cout << "unable to open the file" << endl;
		return 1;
	}
	
    ANTLRInputStream input(inputBuffer.str());
	PythonLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    PythonParser parser(&tokens);
    tree::ParseTree *tree = parser.file();

    for (auto c : tree->children) {
      cout << c->getText() << endl;
    }

    auto s = tree->toStringTree(&parser);
    cout << "Parse Tree: " << s << std::endl;

    return 0;
}
