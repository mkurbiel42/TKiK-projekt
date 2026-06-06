#include <iostream>
#include <Translator.h>

#include "antlr4-runtime.h"
#include "PythonLexer.h"
#include "PythonParser.h"

#include "CustomErrorListener.h"
#include "PythonCustomParserVisitor.h"

#pragma execution_character_set("utf-8")

using namespace antlr4;
using namespace std;

std::list<std::string> Translator::errors = {};
bool Translator::areErrorsFatal = false;

std::string Translator::translate(std::string inputString) {
	errors = {};
	areErrorsFatal = false;
	if (inputString.back() != '\n')
		inputString += '\n';

	ANTLRInputStream input(inputString);
	PythonLexer lexer(&input);
	CommonTokenStream tokens(&lexer);

	PythonParser parser(&tokens);

	parser.removeErrorListeners();
	auto errorListener = new CustomErrorListener();
	parser.addErrorListener(errorListener);
	lexer.addErrorListener(errorListener);

	tree::ParseTree *tree = parser.file();

	if (errorListener->error) {
		for (auto error : errorListener->errors) cout << error << endl;
		areErrorsFatal = true;
		errors = errorListener->errors;
		return "";
	}



	for (auto c : tree->children) {
		cout << c->getText() << endl;
	}

	auto s = tree->toStringTree(&parser);
	cout << "Parse Tree: " << s << std::endl;

	auto *visitor = new PythonCustomParserVisitor();
	visitor->visit(tree);
	if (visitor->errors.size()>0) {
		for (auto e: visitor->errors) errors.push_back(e);
	}

	cout << "================" << endl;
	cout << "Przetlumaczone:" << endl << visitor->translated << endl;
	cout << "================" << endl;

	return visitor->translated;
}
