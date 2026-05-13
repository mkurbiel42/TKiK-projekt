#include "PythonLexerBase.h"

// Generated from PythonLexer.g4 by ANTLR 4.13.2


#include "PythonLexer.h"


using namespace antlr4;



using namespace antlr4;

namespace {

struct PythonLexerStaticData final {
  PythonLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  PythonLexerStaticData(const PythonLexerStaticData&) = delete;
  PythonLexerStaticData(PythonLexerStaticData&&) = delete;
  PythonLexerStaticData& operator=(const PythonLexerStaticData&) = delete;
  PythonLexerStaticData& operator=(PythonLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag pythonlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<PythonLexerStaticData> pythonlexerLexerStaticData = nullptr;

void pythonlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (pythonlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(pythonlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<PythonLexerStaticData>(
    std::vector<std::string>{
      "NEWLINE", "EQUALS", "RETURN", "RAISE", "PASS", "DEL", "BREAK", "CONTINUE", 
      "GLOBAL", "NONLOCAL", "COMMA", "DEF", "PAR_LEFT", "PAR_RIGHT", "BRACKET_LEFT", 
      "BRACKET_RIGHT", "BRACE_LEFT", "BRACE_RIGHT", "LAMBDA", "COLON", "IF", 
      "ELIF", "ELSE", "FOR", "IN", "WHILE", "CLASS", "TRY", "EXCEPT", "FINALLY", 
      "MATCH", "CASE", "UNDERSCORE", "DOT", "WALRUS", "OR", "AND", "NOT", 
      "PLUS", "MINUS", "STAR", "SLASH", "EQEQUAL", "NOTEQUAL", "LESS", "GREATER", 
      "LESSEQUAL", "GREATEREQUAL", "DOUBLESLASH", "PERCENT", "DOUBLESTAR", 
      "TRUE", "FALSE", "NONE", "PLUSEQUAL", "MINUSEQUAL", "STAREQUAL", "SLASHEQUAL", 
      "PERCENTEQUAL", "DOUBLESTAREQUAL", "DOUBLESLASHEQUAL", "NAME", "NUMBER", 
      "STRING", "WHITESPACESKIP", "INTEGER", "FLOAT", "SPACES"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
    },
    std::vector<std::string>{
      "", "", "", "", "", "'='", "'return'", "'raise'", "'pass'", "'del'", 
      "'break'", "'continue'", "'global'", "'nonlocal'", "','", "'def'", 
      "'('", "')'", "'['", "']'", "'{'", "'}'", "'lambda'", "':'", "'if'", 
      "'elif'", "'else'", "'for'", "'in'", "'while'", "'class'", "'try'", 
      "'except'", "'finally'", "'match'", "'case'", "'_'", "'.'", "':='", 
      "'or'", "'and'", "'not'", "'+'", "'-'", "'*'", "'/'", "'=='", "'!='", 
      "'<'", "'>'", "'<='", "'>='", "'//'", "'%'", "'**'", "'True'", "'False'", 
      "'None'", "'+='", "'-='", "'*='", "'/='", "'%='", "'**='", "'//='"
    },
    std::vector<std::string>{
      "", "DEDENT", "INDENT", "ENDMARKER", "NEWLINE", "EQUALS", "RETURN", 
      "RAISE", "PASS", "DEL", "BREAK", "CONTINUE", "GLOBAL", "NONLOCAL", 
      "COMMA", "DEF", "PAR_LEFT", "PAR_RIGHT", "BRACKET_LEFT", "BRACKET_RIGHT", 
      "BRACE_LEFT", "BRACE_RIGHT", "LAMBDA", "COLON", "IF", "ELIF", "ELSE", 
      "FOR", "IN", "WHILE", "CLASS", "TRY", "EXCEPT", "FINALLY", "MATCH", 
      "CASE", "UNDERSCORE", "DOT", "WALRUS", "OR", "AND", "NOT", "PLUS", 
      "MINUS", "STAR", "SLASH", "EQEQUAL", "NOTEQUAL", "LESS", "GREATER", 
      "LESSEQUAL", "GREATEREQUAL", "DOUBLESLASH", "PERCENT", "DOUBLESTAR", 
      "TRUE", "FALSE", "NONE", "PLUSEQUAL", "MINUSEQUAL", "STAREQUAL", "SLASHEQUAL", 
      "PERCENTEQUAL", "DOUBLESTAREQUAL", "DOUBLESLASHEQUAL", "NAME", "NUMBER", 
      "STRING", "WHITESPACESKIP"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,0,68,450,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,
  	7,14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,
  	7,21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,
  	7,28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,
  	7,35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,
  	7,42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,
  	7,49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,
  	7,56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,2,61,7,61,2,62,7,62,2,63,
  	7,63,2,64,7,64,2,65,7,65,2,66,7,66,2,67,7,67,1,0,1,0,1,0,3,0,141,8,0,
  	1,0,1,0,3,0,145,8,0,1,0,3,0,148,8,0,3,0,150,8,0,1,0,1,0,1,1,1,1,1,2,1,
  	2,1,2,1,2,1,2,1,2,1,2,1,3,1,3,1,3,1,3,1,3,1,3,1,4,1,4,1,4,1,4,1,4,1,5,
  	1,5,1,5,1,5,1,6,1,6,1,6,1,6,1,6,1,6,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,7,1,
  	7,1,8,1,8,1,8,1,8,1,8,1,8,1,8,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,10,
  	1,10,1,11,1,11,1,11,1,11,1,12,1,12,1,12,1,13,1,13,1,13,1,14,1,14,1,14,
  	1,15,1,15,1,15,1,16,1,16,1,16,1,17,1,17,1,17,1,18,1,18,1,18,1,18,1,18,
  	1,18,1,18,1,19,1,19,1,20,1,20,1,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,
  	1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,24,1,24,1,24,1,25,1,25,1,25,1,25,
  	1,25,1,25,1,26,1,26,1,26,1,26,1,26,1,26,1,27,1,27,1,27,1,27,1,28,1,28,
  	1,28,1,28,1,28,1,28,1,28,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,29,1,30,
  	1,30,1,30,1,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,32,1,32,1,33,1,33,
  	1,34,1,34,1,34,1,35,1,35,1,35,1,36,1,36,1,36,1,36,1,37,1,37,1,37,1,37,
  	1,38,1,38,1,39,1,39,1,40,1,40,1,41,1,41,1,42,1,42,1,42,1,43,1,43,1,43,
  	1,44,1,44,1,45,1,45,1,46,1,46,1,46,1,47,1,47,1,47,1,48,1,48,1,48,1,49,
  	1,49,1,50,1,50,1,50,1,51,1,51,1,51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,
  	1,52,1,53,1,53,1,53,1,53,1,53,1,54,1,54,1,54,1,55,1,55,1,55,1,56,1,56,
  	1,56,1,57,1,57,1,57,1,58,1,58,1,58,1,59,1,59,1,59,1,59,1,60,1,60,1,60,
  	1,60,1,61,1,61,5,61,395,8,61,10,61,12,61,398,9,61,1,62,1,62,3,62,402,
  	8,62,1,63,1,63,5,63,406,8,63,10,63,12,63,409,9,63,1,63,1,63,1,63,5,63,
  	414,8,63,10,63,12,63,417,9,63,1,63,3,63,420,8,63,1,64,1,64,1,64,1,64,
  	1,65,1,65,5,65,428,8,65,10,65,12,65,431,9,65,1,66,1,66,5,66,435,8,66,
  	10,66,12,66,438,9,66,1,66,1,66,4,66,442,8,66,11,66,12,66,443,1,67,4,67,
  	447,8,67,11,67,12,67,448,2,407,415,0,68,1,4,3,5,5,6,7,7,9,8,11,9,13,10,
  	15,11,17,12,19,13,21,14,23,15,25,16,27,17,29,18,31,19,33,20,35,21,37,
  	22,39,23,41,24,43,25,45,26,47,27,49,28,51,29,53,30,55,31,57,32,59,33,
  	61,34,63,35,65,36,67,37,69,38,71,39,73,40,75,41,77,42,79,43,81,44,83,
  	45,85,46,87,47,89,48,91,49,93,50,95,51,97,52,99,53,101,54,103,55,105,
  	56,107,57,109,58,111,59,113,60,115,61,117,62,119,63,121,64,123,65,125,
  	66,127,67,129,68,131,0,133,0,135,0,1,0,7,3,0,65,90,95,95,97,122,4,0,48,
  	57,65,90,95,95,97,122,4,0,10,10,13,13,34,34,92,92,4,0,10,10,13,13,39,
  	39,92,92,2,0,9,9,32,32,1,0,49,57,1,0,48,57,459,0,1,1,0,0,0,0,3,1,0,0,
  	0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,0,15,
  	1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,0,25,1,0,
  	0,0,0,27,1,0,0,0,0,29,1,0,0,0,0,31,1,0,0,0,0,33,1,0,0,0,0,35,1,0,0,0,
  	0,37,1,0,0,0,0,39,1,0,0,0,0,41,1,0,0,0,0,43,1,0,0,0,0,45,1,0,0,0,0,47,
  	1,0,0,0,0,49,1,0,0,0,0,51,1,0,0,0,0,53,1,0,0,0,0,55,1,0,0,0,0,57,1,0,
  	0,0,0,59,1,0,0,0,0,61,1,0,0,0,0,63,1,0,0,0,0,65,1,0,0,0,0,67,1,0,0,0,
  	0,69,1,0,0,0,0,71,1,0,0,0,0,73,1,0,0,0,0,75,1,0,0,0,0,77,1,0,0,0,0,79,
  	1,0,0,0,0,81,1,0,0,0,0,83,1,0,0,0,0,85,1,0,0,0,0,87,1,0,0,0,0,89,1,0,
  	0,0,0,91,1,0,0,0,0,93,1,0,0,0,0,95,1,0,0,0,0,97,1,0,0,0,0,99,1,0,0,0,
  	0,101,1,0,0,0,0,103,1,0,0,0,0,105,1,0,0,0,0,107,1,0,0,0,0,109,1,0,0,0,
  	0,111,1,0,0,0,0,113,1,0,0,0,0,115,1,0,0,0,0,117,1,0,0,0,0,119,1,0,0,0,
  	0,121,1,0,0,0,0,123,1,0,0,0,0,125,1,0,0,0,0,127,1,0,0,0,0,129,1,0,0,0,
  	1,149,1,0,0,0,3,153,1,0,0,0,5,155,1,0,0,0,7,162,1,0,0,0,9,168,1,0,0,0,
  	11,173,1,0,0,0,13,177,1,0,0,0,15,183,1,0,0,0,17,192,1,0,0,0,19,199,1,
  	0,0,0,21,208,1,0,0,0,23,210,1,0,0,0,25,214,1,0,0,0,27,217,1,0,0,0,29,
  	220,1,0,0,0,31,223,1,0,0,0,33,226,1,0,0,0,35,229,1,0,0,0,37,232,1,0,0,
  	0,39,239,1,0,0,0,41,241,1,0,0,0,43,244,1,0,0,0,45,249,1,0,0,0,47,254,
  	1,0,0,0,49,258,1,0,0,0,51,261,1,0,0,0,53,267,1,0,0,0,55,273,1,0,0,0,57,
  	277,1,0,0,0,59,284,1,0,0,0,61,292,1,0,0,0,63,298,1,0,0,0,65,303,1,0,0,
  	0,67,305,1,0,0,0,69,307,1,0,0,0,71,310,1,0,0,0,73,313,1,0,0,0,75,317,
  	1,0,0,0,77,321,1,0,0,0,79,323,1,0,0,0,81,325,1,0,0,0,83,327,1,0,0,0,85,
  	329,1,0,0,0,87,332,1,0,0,0,89,335,1,0,0,0,91,337,1,0,0,0,93,339,1,0,0,
  	0,95,342,1,0,0,0,97,345,1,0,0,0,99,348,1,0,0,0,101,350,1,0,0,0,103,353,
  	1,0,0,0,105,358,1,0,0,0,107,364,1,0,0,0,109,369,1,0,0,0,111,372,1,0,0,
  	0,113,375,1,0,0,0,115,378,1,0,0,0,117,381,1,0,0,0,119,384,1,0,0,0,121,
  	388,1,0,0,0,123,392,1,0,0,0,125,401,1,0,0,0,127,419,1,0,0,0,129,421,1,
  	0,0,0,131,425,1,0,0,0,133,432,1,0,0,0,135,446,1,0,0,0,137,138,4,0,0,0,
  	138,150,3,135,67,0,139,141,5,13,0,0,140,139,1,0,0,0,140,141,1,0,0,0,141,
  	142,1,0,0,0,142,145,5,10,0,0,143,145,2,12,13,0,144,140,1,0,0,0,144,143,
  	1,0,0,0,145,147,1,0,0,0,146,148,3,135,67,0,147,146,1,0,0,0,147,148,1,
  	0,0,0,148,150,1,0,0,0,149,137,1,0,0,0,149,144,1,0,0,0,150,151,1,0,0,0,
  	151,152,6,0,0,0,152,2,1,0,0,0,153,154,5,61,0,0,154,4,1,0,0,0,155,156,
  	5,114,0,0,156,157,5,101,0,0,157,158,5,116,0,0,158,159,5,117,0,0,159,160,
  	5,114,0,0,160,161,5,110,0,0,161,6,1,0,0,0,162,163,5,114,0,0,163,164,5,
  	97,0,0,164,165,5,105,0,0,165,166,5,115,0,0,166,167,5,101,0,0,167,8,1,
  	0,0,0,168,169,5,112,0,0,169,170,5,97,0,0,170,171,5,115,0,0,171,172,5,
  	115,0,0,172,10,1,0,0,0,173,174,5,100,0,0,174,175,5,101,0,0,175,176,5,
  	108,0,0,176,12,1,0,0,0,177,178,5,98,0,0,178,179,5,114,0,0,179,180,5,101,
  	0,0,180,181,5,97,0,0,181,182,5,107,0,0,182,14,1,0,0,0,183,184,5,99,0,
  	0,184,185,5,111,0,0,185,186,5,110,0,0,186,187,5,116,0,0,187,188,5,105,
  	0,0,188,189,5,110,0,0,189,190,5,117,0,0,190,191,5,101,0,0,191,16,1,0,
  	0,0,192,193,5,103,0,0,193,194,5,108,0,0,194,195,5,111,0,0,195,196,5,98,
  	0,0,196,197,5,97,0,0,197,198,5,108,0,0,198,18,1,0,0,0,199,200,5,110,0,
  	0,200,201,5,111,0,0,201,202,5,110,0,0,202,203,5,108,0,0,203,204,5,111,
  	0,0,204,205,5,99,0,0,205,206,5,97,0,0,206,207,5,108,0,0,207,20,1,0,0,
  	0,208,209,5,44,0,0,209,22,1,0,0,0,210,211,5,100,0,0,211,212,5,101,0,0,
  	212,213,5,102,0,0,213,24,1,0,0,0,214,215,5,40,0,0,215,216,6,12,1,0,216,
  	26,1,0,0,0,217,218,5,41,0,0,218,219,6,13,2,0,219,28,1,0,0,0,220,221,5,
  	91,0,0,221,222,6,14,3,0,222,30,1,0,0,0,223,224,5,93,0,0,224,225,6,15,
  	4,0,225,32,1,0,0,0,226,227,5,123,0,0,227,228,6,16,5,0,228,34,1,0,0,0,
  	229,230,5,125,0,0,230,231,6,17,6,0,231,36,1,0,0,0,232,233,5,108,0,0,233,
  	234,5,97,0,0,234,235,5,109,0,0,235,236,5,98,0,0,236,237,5,100,0,0,237,
  	238,5,97,0,0,238,38,1,0,0,0,239,240,5,58,0,0,240,40,1,0,0,0,241,242,5,
  	105,0,0,242,243,5,102,0,0,243,42,1,0,0,0,244,245,5,101,0,0,245,246,5,
  	108,0,0,246,247,5,105,0,0,247,248,5,102,0,0,248,44,1,0,0,0,249,250,5,
  	101,0,0,250,251,5,108,0,0,251,252,5,115,0,0,252,253,5,101,0,0,253,46,
  	1,0,0,0,254,255,5,102,0,0,255,256,5,111,0,0,256,257,5,114,0,0,257,48,
  	1,0,0,0,258,259,5,105,0,0,259,260,5,110,0,0,260,50,1,0,0,0,261,262,5,
  	119,0,0,262,263,5,104,0,0,263,264,5,105,0,0,264,265,5,108,0,0,265,266,
  	5,101,0,0,266,52,1,0,0,0,267,268,5,99,0,0,268,269,5,108,0,0,269,270,5,
  	97,0,0,270,271,5,115,0,0,271,272,5,115,0,0,272,54,1,0,0,0,273,274,5,116,
  	0,0,274,275,5,114,0,0,275,276,5,121,0,0,276,56,1,0,0,0,277,278,5,101,
  	0,0,278,279,5,120,0,0,279,280,5,99,0,0,280,281,5,101,0,0,281,282,5,112,
  	0,0,282,283,5,116,0,0,283,58,1,0,0,0,284,285,5,102,0,0,285,286,5,105,
  	0,0,286,287,5,110,0,0,287,288,5,97,0,0,288,289,5,108,0,0,289,290,5,108,
  	0,0,290,291,5,121,0,0,291,60,1,0,0,0,292,293,5,109,0,0,293,294,5,97,0,
  	0,294,295,5,116,0,0,295,296,5,99,0,0,296,297,5,104,0,0,297,62,1,0,0,0,
  	298,299,5,99,0,0,299,300,5,97,0,0,300,301,5,115,0,0,301,302,5,101,0,0,
  	302,64,1,0,0,0,303,304,5,95,0,0,304,66,1,0,0,0,305,306,5,46,0,0,306,68,
  	1,0,0,0,307,308,5,58,0,0,308,309,5,61,0,0,309,70,1,0,0,0,310,311,5,111,
  	0,0,311,312,5,114,0,0,312,72,1,0,0,0,313,314,5,97,0,0,314,315,5,110,0,
  	0,315,316,5,100,0,0,316,74,1,0,0,0,317,318,5,110,0,0,318,319,5,111,0,
  	0,319,320,5,116,0,0,320,76,1,0,0,0,321,322,5,43,0,0,322,78,1,0,0,0,323,
  	324,5,45,0,0,324,80,1,0,0,0,325,326,5,42,0,0,326,82,1,0,0,0,327,328,5,
  	47,0,0,328,84,1,0,0,0,329,330,5,61,0,0,330,331,5,61,0,0,331,86,1,0,0,
  	0,332,333,5,33,0,0,333,334,5,61,0,0,334,88,1,0,0,0,335,336,5,60,0,0,336,
  	90,1,0,0,0,337,338,5,62,0,0,338,92,1,0,0,0,339,340,5,60,0,0,340,341,5,
  	61,0,0,341,94,1,0,0,0,342,343,5,62,0,0,343,344,5,61,0,0,344,96,1,0,0,
  	0,345,346,5,47,0,0,346,347,5,47,0,0,347,98,1,0,0,0,348,349,5,37,0,0,349,
  	100,1,0,0,0,350,351,5,42,0,0,351,352,5,42,0,0,352,102,1,0,0,0,353,354,
  	5,84,0,0,354,355,5,114,0,0,355,356,5,117,0,0,356,357,5,101,0,0,357,104,
  	1,0,0,0,358,359,5,70,0,0,359,360,5,97,0,0,360,361,5,108,0,0,361,362,5,
  	115,0,0,362,363,5,101,0,0,363,106,1,0,0,0,364,365,5,78,0,0,365,366,5,
  	111,0,0,366,367,5,110,0,0,367,368,5,101,0,0,368,108,1,0,0,0,369,370,5,
  	43,0,0,370,371,5,61,0,0,371,110,1,0,0,0,372,373,5,45,0,0,373,374,5,61,
  	0,0,374,112,1,0,0,0,375,376,5,42,0,0,376,377,5,61,0,0,377,114,1,0,0,0,
  	378,379,5,47,0,0,379,380,5,61,0,0,380,116,1,0,0,0,381,382,5,37,0,0,382,
  	383,5,61,0,0,383,118,1,0,0,0,384,385,5,42,0,0,385,386,5,42,0,0,386,387,
  	5,61,0,0,387,120,1,0,0,0,388,389,5,47,0,0,389,390,5,47,0,0,390,391,5,
  	61,0,0,391,122,1,0,0,0,392,396,7,0,0,0,393,395,7,1,0,0,394,393,1,0,0,
  	0,395,398,1,0,0,0,396,394,1,0,0,0,396,397,1,0,0,0,397,124,1,0,0,0,398,
  	396,1,0,0,0,399,402,3,131,65,0,400,402,3,133,66,0,401,399,1,0,0,0,401,
  	400,1,0,0,0,402,126,1,0,0,0,403,407,5,34,0,0,404,406,8,2,0,0,405,404,
  	1,0,0,0,406,409,1,0,0,0,407,408,1,0,0,0,407,405,1,0,0,0,408,410,1,0,0,
  	0,409,407,1,0,0,0,410,420,5,34,0,0,411,415,5,39,0,0,412,414,8,3,0,0,413,
  	412,1,0,0,0,414,417,1,0,0,0,415,416,1,0,0,0,415,413,1,0,0,0,416,418,1,
  	0,0,0,417,415,1,0,0,0,418,420,5,39,0,0,419,403,1,0,0,0,419,411,1,0,0,
  	0,420,128,1,0,0,0,421,422,7,4,0,0,422,423,1,0,0,0,423,424,6,64,7,0,424,
  	130,1,0,0,0,425,429,7,5,0,0,426,428,7,6,0,0,427,426,1,0,0,0,428,431,1,
  	0,0,0,429,427,1,0,0,0,429,430,1,0,0,0,430,132,1,0,0,0,431,429,1,0,0,0,
  	432,436,7,5,0,0,433,435,7,6,0,0,434,433,1,0,0,0,435,438,1,0,0,0,436,434,
  	1,0,0,0,436,437,1,0,0,0,437,439,1,0,0,0,438,436,1,0,0,0,439,441,5,46,
  	0,0,440,442,7,6,0,0,441,440,1,0,0,0,442,443,1,0,0,0,443,441,1,0,0,0,443,
  	444,1,0,0,0,444,134,1,0,0,0,445,447,7,4,0,0,446,445,1,0,0,0,447,448,1,
  	0,0,0,448,446,1,0,0,0,448,449,1,0,0,0,449,136,1,0,0,0,14,0,140,144,147,
  	149,396,401,407,415,419,429,436,443,448,8,1,0,0,1,12,1,1,13,2,1,14,3,
  	1,15,4,1,16,5,1,17,6,6,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  pythonlexerLexerStaticData = std::move(staticData);
}

}

PythonLexer::PythonLexer(CharStream *input) : PythonLexerBase(input) {
  PythonLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *pythonlexerLexerStaticData->atn, pythonlexerLexerStaticData->decisionToDFA, pythonlexerLexerStaticData->sharedContextCache);
}

PythonLexer::~PythonLexer() {
  delete _interpreter;
}

std::string PythonLexer::getGrammarFileName() const {
  return "PythonLexer.g4";
}

const std::vector<std::string>& PythonLexer::getRuleNames() const {
  return pythonlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& PythonLexer::getChannelNames() const {
  return pythonlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& PythonLexer::getModeNames() const {
  return pythonlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& PythonLexer::getVocabulary() const {
  return pythonlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView PythonLexer::getSerializedATN() const {
  return pythonlexerLexerStaticData->serializedATN;
}

const atn::ATN& PythonLexer::getATN() const {
  return *pythonlexerLexerStaticData->atn;
}


void PythonLexer::action(RuleContext *context, size_t ruleIndex, size_t actionIndex) {
  switch (ruleIndex) {
    case 0: NEWLINEAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 12: PAR_LEFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 13: PAR_RIGHTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 14: BRACKET_LEFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 15: BRACKET_RIGHTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 16: BRACE_LEFTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;
    case 17: BRACE_RIGHTAction(antlrcpp::downCast<antlr4::RuleContext *>(context), actionIndex); break;

  default:
    break;
  }
}

bool PythonLexer::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 0: return NEWLINESempred(antlrcpp::downCast<antlr4::RuleContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

void PythonLexer::NEWLINEAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 0: this->onNewLine(); break;

  default:
    break;
  }
}

void PythonLexer::PAR_LEFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 1: this->openBrace(); break;

  default:
    break;
  }
}

void PythonLexer::PAR_RIGHTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 2: this->closeBrace(); break;

  default:
    break;
  }
}

void PythonLexer::BRACKET_LEFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 3: this->openBrace(); break;

  default:
    break;
  }
}

void PythonLexer::BRACKET_RIGHTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 4: this->closeBrace(); break;

  default:
    break;
  }
}

void PythonLexer::BRACE_LEFTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 5: this->openBrace(); break;

  default:
    break;
  }
}

void PythonLexer::BRACE_RIGHTAction(antlr4::RuleContext *context, size_t actionIndex) {
  switch (actionIndex) {
    case 6: this->closeBrace(); break;

  default:
    break;
  }
}


bool PythonLexer::NEWLINESempred(antlr4::RuleContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return this->atStartOfInput();

  default:
    break;
  }
  return true;
}


void PythonLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  pythonlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(pythonlexerLexerOnceFlag, pythonlexerLexerInitialize);
#endif
}
