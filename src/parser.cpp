struct Branch
{
    int value1;
    int operation;
    int value2;
};

void printParsed(std::vector<Branch> *parsed)
{
    const int size = parsed->size();
    std::cout << "{\n";
    for (int i = 0; i < size; i++)
    {
        const auto branch = parsed->at(i);
        std::cout << "\t{ value1: " << branch.value1 << ", operation: " << branch.operation << ", value2: " << branch.value2;
        std::cout << " },\n";
    }
    std::cout << "}" << std::endl;
}

inline int findType(char symbol)
{
    switch (symbol)
    {
    case '+':
        return ADDITION;
    case '-':
        return SUBTRACTION;
    case '*':
        return MULTIPlACATION;
    case '/':
        return DIVISION;

    default:
        return ADDITION;
    }
}

std::vector<Branch> *parse(std::vector<std::string> *lexed)
{
    const int size = lexed->size();
    std::vector<Branch> *parsed = new std::vector<Branch>;
    for (int position = 0; (position + 2) <= size; position += 2)
    {
        Branch placement;
        placement.value1 = atoi(lexed->at(position).c_str());
        placement.operation = findType(lexed->at(position + 1)[0]);
        placement.value2 = atoi(lexed->at(position + 2).c_str());
        parsed->push_back(placement);
    }
    return parsed;
}
