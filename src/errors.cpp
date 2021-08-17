#include <iostream>
#include <math.h>

// Terminal colors and shit
const char RED[] = "\x1B[31m";
const char RESET[] = "\x1b[0m";
const char UNDERLINE[] = "\x1b[4m";
const char NEWLINE[] = "\n\t\t";
const char DIM[] = "\x1b[2m";

// Messages
inline void printError(const char *message[])
{
    std::cout << RED << "[ERROR]" << RESET << " ==> " << UNDERLINE << *message << RESET << std::endl;
}

inline void throwError(const char message[])
{
    printError(&message);
    exit(EXIT_FAILURE);
}

void contentError(const char character, int position, int line, const char header[], const std::string &message, const std::string &path)
{
    const std::string &offset = std::string(int(message.size() / 2), ' ');
    printError(&header);

    std::cout << offset << RED << UNDERLINE << character << RESET << '\n'
              << offset << "^\n"
              << message << '\n'
              << DIM << "at " << path << ":" << line << ':' << position - 1 << std::endl;
    exit(EXIT_FAILURE);
}