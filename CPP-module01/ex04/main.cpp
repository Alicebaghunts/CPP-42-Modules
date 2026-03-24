#include <iostream>
#include <fstream>
#include <string>

#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define BLACK   "\033[30m"
#define CYAN    "\033[36m"
#define BRED    "\033[91m"
#define BCYAN   "\033[96m"

void printError(const std::string& msg, const std::string& detail = "")
{
    std::cerr << "\033[91mError:\033[0m " << msg;
    if (!detail.empty())
        std::cerr << detail ;
    std::cerr << std::endl;
}

int exitWithError(const std::string& msg, const std::string& detail = "")
{
    printError(msg, detail);
    return 1;
}

void replaceAll(std::string& str, const std::string& from, const std::string& to)
{
    if (from.empty())
        return ;
    size_t pos = 0;
    while ((pos = str.find(from, pos)) != std::string::npos)
    {
        str.erase(pos, from.length());
        str.insert(pos, to);
        pos += to.length();
    }
}

static bool processFile(const std::string& inFileName,
                        const std::string& s1,
                        const std::string& s2)
{
    std::ifstream inFile(inFileName.c_str());
    if (!inFile.is_open())
        return false;

    std::string outFileName = inFileName + ".replace";
    std::ofstream outFile(outFileName.c_str());
    if (!outFile.is_open())
        return (inFile.close(), false);

    std::string line;
    bool firstLine = true;
    while (std::getline(inFile, line))
    {
        if (!firstLine)
            outFile << '\n';
        replaceAll(line, s1, s2);
        outFile << line;
        firstLine = false;
    }
    inFile.close();
    outFile.close();
    return true;
}

int main(int argc, char** argv)
{
    if (argc != 4)
        return exitWithError("\033[91mUsage → \033[0m", "\033[96m./replace <filename> <s1> <s2>\033[0m");

    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    if (!processFile(filename, s1, s2))
    {
        if (std::ifstream(filename.c_str()).is_open() == false)
            return exitWithError("cannot open input file", filename);
        else
            return exitWithError("cannot create output file", filename + ".replace");
    }

    std::cout << "Replacement done → " << filename << ".replace" << std::endl;
    return 0;
}