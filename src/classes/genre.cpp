#include <stdexcept>
#include <algorithm>

#include "genre.hpp"

Genre::Genre(std::string genre) : value(genre) {
    auto found = std::find(std::begin(Genre::validGenres), std::end(Genre::validGenres), genre);
    if (found == std::end(validGenres))
        throw std::invalid_argument("Genero Invalido");
}

std::string Genre::toString() const{
    return value;
}

//Clean on program first run
std::unordered_set<std::string> Genre::validGenres;

void Genre::registerValidGenre(std::string genre){
    validGenres.insert(genre);
}

bool Genre::operator==(const Genre& other) const{
    return value == other.value;
}
