//
// Created by rusla on 31.12.2023.
//

#ifndef ERROR_HPP
#define ERROR_HPP
#include <exception>
#include <optional>

namespace Framework
{
    class Error : public std::exception
    {
    public:
        explicit Error(const char* msg, std::optional<const char*> additionalMsg = std::nullopt);

        [[nodiscard]] const char* what() const noexcept override;

        [[nodiscard]] const char* GetMessage() const noexcept;
        [[nodiscard]] std::optional<const char*> GetAdditionalMessage() const noexcept;

    private:
        const char* msg;
        std::optional<const char*> additionalMsg;
    };
} // Framework

#endif //ERROR_HPP
