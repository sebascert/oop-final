#include "video.hpp"

Video::Video(Id id, std::string name, int duration, Genre genre) :
    id(id), name(name), genre(genre), duration(duration), rating(Rating()) {}

const Genre& Video::getGenre() const{
    return genre;
}

const Rating& Video::getRating() const{
    return rating;
}

bool Video::hasId(Id id) const{
    return this->id == id;
}

std::ostream& operator<<(std::ostream& os, const Video& obj){
    os << obj.tostring();
    return os;
}
