#include <iostream>
#include <vector>
#include <limits.h>
#include <sys/stat.h>
#include <unistd.h>
#include <filesystem>
#include <fstream>
#include "./types.cpp"
#include "./errors.cpp"
#include "./lexer.cpp"
#include "./parser.cpp"
#include "./assembly-generator.cpp"
#include "./compile.cpp"
namespace fs = std::filesystem;

// Messages
inline void printHelp()
{
    std::cout << "[USAGE] ==> calc:" << NEWLINE << "<pathname>" << std::endl;
}

// Util
inline std::string getPath(const std::string &file)
{
    return std::filesystem::absolute(std::filesystem::path(file));
}
inline bool file_exists(const std::string &name)
{
    struct stat buffer;
    return stat(name.c_str(), &buffer) == 0;
}
int main(const int argc, const char *argv[])
{
    // Make sure the arguments given is valid
    if (argc != 2)
    {
        printHelp();
        throwError("Invalid argument(s)");
    }
    const std::string &path = getPath(argv[1]);

    // Check if the file given exists
    if (file_exists(path) == false)
    {
        throwError(std::string("File \"" + path + "\" does not exist").c_str());
    }

    std::ifstream file(path);
    const auto tokens = lex(file, path);
    const auto syntaxTree = parse(tokens);
    const auto compiled = compile(syntaxTree);

    std::ofstream outputFile;
    outputFile.open(path + ".asm");
    outputFile << *compiled;
    outputFile.close();
    exit(EXIT_SUCCESS);
}
