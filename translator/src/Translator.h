#include <list>
#include <string>

class Translator{
public:
    static std::list<std::string> errors;
    static bool areErrorsFatal;

    static std::string translate(std::string inputString);
};