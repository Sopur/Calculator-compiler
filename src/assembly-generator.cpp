std::string addition(const Branch &branch)
{
    std::string out = "\tadd\tebx, ";
    out += std::to_string(branch.value2);
    out += "\n";
    return out;
}

std::string subtract(const Branch &branch)
{
    std::string out = "\tsub\tebx, ";
    out += std::to_string(branch.value2);
    out += "\n";
    return out;
}

std::string multiply(const Branch &branch)
{
    std::string out = "\tmov\teax, ";
    out += std::to_string(branch.value2);
    out += "\n"
           "\tmul\tebx\n"
           "\tmov\tebx, eax\n";
    return out;
}

std::string divide(const Branch &branch)
{
    std::string out = "\tmov\tedx, 0\n"
                      "\tmov\teax, ebx\n"
                      "\tmov\tecx, ";
    out += std::to_string(branch.value2);
    out += "\n"
           "\tdiv\tecx\n"
           "\tmov\tebx, eax\n";
    return out;
}

std::string init(const Branch &branch)
{
    std::string out = "\tmov\tebx, ";
    out += std::to_string(branch.value1);
    out += "\n";
    return out;
}
