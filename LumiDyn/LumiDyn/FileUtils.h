#ifndef FILE_UTILS_H
#define FILE_UTILS_H

#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

namespace LumiDynEngine {

    class FileUtils {
    public:
        static std::vector<char> readFile(const std::string& filename);
    };

}

#endif // FILE_UTILS_H
