//
// Created by rusla on 31.12.2023.
//

#include "Error.hpp"

namespace Framework {
    Error::Error(const char* msg, std::optional<const char*> additionalMsg)
        : msg(msg), additionalMsg(additionalMsg)
    {
    }

    const char* Error::what() const noexcept
    {
        return msg;
    }

    const char* Error::GetMessage() const noexcept
    {
        return msg;
    }

    std::optional<const char*> Error::GetAdditionalMessage() const noexcept
    {
        return additionalMsg;
    }
} // Framework