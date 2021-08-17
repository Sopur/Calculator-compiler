#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>

inline std::string getAssemblyFilePath(const std::string &file)
{
    return std::filesystem::absolute(std::filesystem::path("assembly/" + file + ".asm"));
}

std::string getAssembly(const std::string &name)
{
    std::string out;
    std::ifstream file(getAssemblyFilePath(name));
    while (file)
    {
        std::string line;
        std::getline(file, line);
        out += line;
        if (file)
        {
            out += "\n";
        }
    }
    return out;
}

std::string *compile(const std::vector<Branch> *parsed)
{
    const int size = parsed->size();
    std::string *compiled = new std::string;

    const std::string COMMENT = getAssembly("comment");
    const std::string INIT = getAssembly("init");
    const std::string EXIT = getAssembly("exit");
    *compiled += COMMENT;
    *compiled += INIT;
    *compiled += init(parsed->at(0));
    for (int i = 0; i < size; i++)
    {
        const Branch branch = parsed->at(i);
        switch (branch.operation)
        {
        case ADDITION:
        {
            *compiled += addition(branch);
            break;
        }
        case SUBTRACTION:
        {
            *compiled += subtract(branch);
            break;
        }
        case MULTIPlACATION:
        {
            *compiled += multiply(branch);
            break;
        }
        case DIVISION:
        {
            *compiled += divide(branch);
            break;
        }
        }
    }
    *compiled += EXIT;
    *compiled += COMMENT;
    return compiled;
}
