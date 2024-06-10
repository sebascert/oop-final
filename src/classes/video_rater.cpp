#include <algorithm>
#include <stdexcept>

#include "video_rater.hpp"

VideoRater::VideoRater(std::istringstream input){
    //TODO
}

VideoRater::~VideoRater(){
    for(Video* vid : videos)
        delete vid;
}

std::vector<Video*> VideoRater::getVideosBy(std::function<bool(Video*)> predicate) const{
    std::vector<Video*> foundVideos;
    std::copy_if(videos.begin(), videos.end(), std::back_inserter(foundVideos), predicate);
    return foundVideos;
}

std::vector<Video*> VideoRater::getCatalog() const{
    return videos;
}

std::vector<Video*> VideoRater::getByRate(float minRate, int videoTypes) const{
    return getVideosBy([minRate](Video* v) {
        return v->getRating()>=minRate;
    });
}

std::vector<Video*> VideoRater::getByGenre(const Genre& genre, int videoTypes) const{
    return getVideosBy([genre](Video* v) {
        return v->getGenre() == genre;
    });
}

Video& VideoRater::operator[](const Id& id){
    auto found = std::find_if(videos.begin(), videos.end(), [id](Video* v){return v->hasId(id);});
    if (found != videos.end())
        return **found;
    else
        throw std::invalid_argument("Video con Id " + id.toString() + " no encontrado");
}
