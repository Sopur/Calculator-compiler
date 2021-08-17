#include <vector>
#include <iostream>
#include <fstream>

inline bool isWhitespace(const char character)
{
    switch (character)
    {
    case '\n':
    case ' ':
        return true;

    default:
        return false;
    }
}

inline bool isNumber(const char character)
{
    switch (character)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return true;

    default:
        return false;
    }
}

inline bool isOperation(const char character)
{
    switch (character)
    {
    case '+': // Adding
    case '-': // Subtracting
    case '*': // Multiplying
    case '/': // Dividing
        return true;

    default:
        return false;
    }
}

inline void updateCounters(char token, int &character, int &line)
{
    if (token == '\n')
    {
        line++;
        character = 1;
    }
    else
    {
        character++;
    }
}

inline void checkEnd(std::ifstream &file)
{
    if (!file)
    {
        throwError("Unexpected end of input");
    }
}

void getToToken(std::ifstream &file, char &token, int &character, int &line)
{
    if (isWhitespace(token) == false)
        return;

    while (true)
    {
        checkEnd(file);
        token = file.get();
        updateCounters(token, character, line);
        if (isWhitespace(token) == true)
            continue;
        break;
    }
}

void printTokens(std::vector<std::string> *tokens)
{
    std::cout << "[ ";
    for (int i = 0; i < tokens->size(); i++)
    {
        const std::string &token = tokens->at(i);
        std::cout << '"' << token << "\", ";
    }
    std::cout << "]" << std::endl;
}

std::vector<std::string> *lex(std::ifstream &file, const std::string &path)
{
    std::vector<std::string> *tokens = new std::vector<std::string>;
    int line = 1;
    int character = 1;
    char expectingNumber = true;
    char token = file.get();
    while (file)
    {
        std::string placement;
        character++;
        if (token == '\n')
        {
            line++;
            character = 1;
            token = file.get();
            continue;
        }
        if (isWhitespace(token) == true)
        {
            token = file.get();
            continue;
        }

        if (isNumber(token) == true && expectingNumber == true)
        {
            placement.push_back(token);
            while (file)
            {
                token = file.get();
                if (isNumber(token) == true)
                {
                    character++;
                    placement.push_back(token);
                }
                else
                {
                    break;
                }
            }
            tokens->push_back(placement);
            expectingNumber = false;
            continue;
        }
        else if (isOperation(token) == true && expectingNumber == false)
        {
            placement.push_back(token);
            tokens->push_back(placement);
            expectingNumber = true;
        }
        else
        {
            contentError(token, character, line, "Unexpected token", std::string("Expected a") + ((expectingNumber == true) ? " number" : "n operator") + " but got \"" + token + "\" instead", path);
        }
        token = file.get();
    }

    // Check for legitness
    if (tokens->size() <= 1)
    {
        throwError("Cannot do calculations with 1 number or less");
    }
    if (expectingNumber == true)
    {
        throwError("Expected a number after an operator was called");
    }
    return tokens;
}
