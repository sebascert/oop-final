#pragma once

#include <string>
#include <sstream>
#include <unordered_map>
#include <typeindex>
#include <type_traits>

/// @brief Tries to parse user input into generic object
/// @tparam T Generic type, either with stream extraction operator overload
/// or contructor with string arg
/// @param is
/// @param errMsg
/// @param delim
/// @return Built object from input, if failed to read format throws invalid_argument
template<typename T>
T getInput(std::istream& is, std::string errMsg, char delim){
    std::string buff;
    std::getline(is, buff, delim);

    if constexpr (std::is_same<T, std::string>::value)
        return buff;

    if constexpr (std::is_default_constructible<T>::value){
        std::istringstream buffss(buff);
        T value;
        if (!(buffss >> value) || buffss.peek() != EOF)
            throw std::invalid_argument(errMsg);
        return value;
    }else
        return T(buff);
}
