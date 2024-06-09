#include <stdexcept>
#include <algorithm>

#include "genre.hpp"

Genre::Genre(std::string genre) : value(genre) {
    std::string validGenres[] = {"accion", "accion", "accion"};
    auto found = std::find(std::begin(validGenres), std::end(validGenres), genre);
    if (found == std::end(validGenres))
        throw std::invalid_argument("Genero Invalido");
}

std::string Genre::toString(){
    return value;
}

bool Genre::operator==(Genre& other) const{
    return value == other.value;
}
