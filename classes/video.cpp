#include "video.hpp"

Video::Video(Id id, std::string name, int duration, Genre genre) :
    id(id), name(name), genre(genre), duration(duration), rating(Rating()) {}

void Video::rateVideo(int rate){
    rating.rate(rate);
}

std::ostream& operator<<(std::ostream& os, const Video& obj){
    os << obj.tostring();
    return os;
}
