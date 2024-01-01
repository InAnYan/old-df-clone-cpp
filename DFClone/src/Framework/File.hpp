//
// Created by rusla on 01.01.2024.
//

#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>

namespace Framework
{
    class File
    {
    public:
        explicit File(const std::string& path);

    private:
        std::fstream stream;
    };
} // Framework

#endif //FILE_HPP
