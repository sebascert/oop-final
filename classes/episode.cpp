#include <sstream>

#include "episode.hpp"

Episode::Episode(Id id, std::string name, int duration, Genre genre, std::string title) :
    Video(id, name, duration, genre), title(title) {}

std::string Episode::toString() const{
    std::stringstream ss("");
    ss << "Id:" << id.toString()
       << " Nombre:" << name
       << " Duracion:" << duration
       << " Genero:" << genre.toString()
       << " Title:" << title
       << " Episode:" << id.getEpisode()
       << " Calificacion:" << rating.toString();
    return ss.str();
}
