#include <iostream>

#include "antlr4-runtime.h"
#include "PythonLexer.h"
#include "PythonParser.h"

#include <filesystem>

#include "PythonCustomParserVisitor.h"

#pragma execution_character_set("utf-8")

using namespace antlr4;
using namespace std;

string translate(string inputString) {
	if (inputString.back() != '\n')
		inputString += '\n';

	ANTLRInputStream input(inputString);
	PythonLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	PythonParser parser(&tokens);
	tree::ParseTree *tree = parser.file();

	for (auto c : tree->children) {
		cout << c->getText() << endl;
	}

	auto s = tree->toStringTree(&parser);
	cout << "Parse Tree: " << s << std::endl;

	auto *visitor = new PythonCustomParserVisitor();
	visitor->visit(tree);

	cout << "================" << endl;
	cout << "Przetlumaczone:" << endl << visitor->translated << endl;
	cout << "================" << endl;

	return visitor->translated;
}
