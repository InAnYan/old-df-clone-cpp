//
// Created by rusla on 01.01.2024.
//

#include "File.hpp"

#include "Error.hpp"

namespace Framework
{
    File::File(const std::string& path)
        : stream(path)
    {
        if (!stream)
        {
            // TODO: Is it right to pass c_str?
            throw Error("could not open file", path.c_str());
        }
    }
} // Framework
