#pragma once

#include <string>
#include <sstream>
#include <unordered_map>
#include <typeindex>
#include <type_traits>

#include "../classes/id.hpp"
#include "../classes/genre.hpp"

std::unordered_map<std::type_index, std::string> typeNames = {
    {typeid(int), "Entero"},
    {typeid(float), "Flotante"},
    {typeid(double), "Flotante Doble"},
    {typeid(Id), "Video id"},
    {typeid(Genre), "Video Genero"},
};

/// @brief Tries to parse user input into generic object
/// @tparam T Generic type, either with with stream extraction operator or contructor from string
/// @param message 
/// @param delim 
/// @return Built object from input, or throws of invalid argument if failed
template<typename T>
T getInput(char delim){
    std::string buff;
    std::getline(std::cin, buff, delim);

    if constexpr (std::is_default_constructible<T>::value){
        std::istringstream buffss(buff);
        T value;
        if (!(buffss >> value) || buffss.peek() != EOF)
            throw std::invalid_argument(typeNames[typeid(T)] + " Invalido");
        return value;
    }else
        return T(buff);
}
