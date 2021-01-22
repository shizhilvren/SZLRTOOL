#include "tool.h"
#include "debug.h"
#include <fstream>

bool TOOL::isFileCanRead(std::string filenname)
{
    std::ifstream f(filenname.c_str(), std::ios_base::in);
    return f.good();
}

void TOOL::showInfo(const std::string info)
{
    std::cout << info;
    std::cout << NONE << std::endl;
}

void TOOL::line_split(const std::string& line, std::vector<std::string>& list)
{
    list.clear();
    size_t i = 0, j = 0;
    for (; j < line.length(); j++) {
        if (line[j] == '\t' || line[j] == ' ') {
            if (i != j) {
                list.push_back(line.substr(i, j - i));
                i = j + 1;
            } else {
                i++;
            }
        }
    }
    if (i != j) {
        list.push_back(line.substr(i, j - i));
        i = j + 1;
    }
}



// void TOOL::output()
// {
//     // out << std::endl;
// }
