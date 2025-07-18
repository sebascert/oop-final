#include <sstream>

#include "movie.hpp"

std::string Movie::toString() const{
    std::stringstream ss("");
    ss << "Id:" << id.toString()
       << " Nombre:" << name
       << " Genero:" << genre.toString()
       << " Duracion:" << duration
       << " Calificacion:" << rating.toString();
    return ss.str();
}
