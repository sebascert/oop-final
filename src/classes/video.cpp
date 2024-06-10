#include <sstream>

#include "video.hpp"

Video::Video(Id id, std::string name, int duration, Genre genre) :
    id(id), name(name), genre(genre), duration(duration), rating(Rating()) {}

const Genre& Video::getGenre() const{
    return genre;
}

Rating& Video::getRating(){
    return rating;
}

bool Video::hasId(const Id& id) const{
    return this->id == id;
}

std::string Video::ratingFormat() const{
    std::stringstream ss("");
    ss << "Id:" << id.toString()
       << " Nombre:" << name
       << " Calificacion:" << rating.toString();
    return ss.str();
}

std::string Video::genreFormat() const{
    std::stringstream ss("");
    ss << "Id:" << id.toString()
       << " Nombre:" << name
       << " Genero:" << genre.toString()
       << " Calificacion:" << rating.toString();
    return ss.str();
}

std::ostream& operator<<(std::ostream& os, const Video& obj){
    os << obj.toString();
    return os;
}
