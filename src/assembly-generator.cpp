std::string addition(const Branch &branch)
{
    std::string out = "\t\tadd\t\tebx, ";
    out += std::to_string(branch.value2);
    out += "\n";
    return out;
}

std::string subtract(const Branch &branch)
{
    std::string out = "\t\tsub"
                      "\t\tebx, ";
    out += std::to_string(branch.value2);
    out += "\n";
    return out;
}

std::string multiply(const Branch &branch)
{
    std::string out = "\t\tmov\t\teax, ";
    out += std::to_string(branch.value2);
    out += "\n"
           "\t\tmul\t\tebx\n"
           "\t\tmov\t\tebx, eax\n";
    return out;
}

std::string divide(const Branch &branch)
{
    std::string out = "\t\tmov\t\tedx, 0\n"
                      "\t\tmov\t\teax, ebx\n"
                      "\t\tmov\t\tecx, ";
    out += std::to_string(branch.value2);
    out += "\n"
           "\t\tdiv\t\tecx\n"
           "\t\tmov\t\tebx, eax\n";
    return out;
}

std::string init(const Branch &branch)
{
    std::string out = "\t\tmov\t\tebx, ";
    out += std::to_string(branch.value1);
    out += "\n";
    return out;
}
