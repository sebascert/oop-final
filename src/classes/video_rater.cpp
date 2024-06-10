#include <string>
#include <algorithm>
#include <stdexcept>

#include "video_rater.hpp"
#include "movie.hpp"
#include "episode.hpp"

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

bool VideoRater::videoTypeChecker(int videoTypes, Video* v){
    bool validType;
    if (videoTypes == 1)
        validType = dynamic_cast<Movie*>(v) != nullptr;
    else if (videoTypes == 2)
        validType = dynamic_cast<Episode*>(v) != nullptr;
    else if (videoTypes == 2)
        validType = true;
    else
        throw std::invalid_argument("Tipo de videos " + std::to_string(videoTypes) + " invalido");
    return validType;
}

std::vector<Video*> VideoRater::getCatalog() const{
    return videos;
}

std::vector<Video*> VideoRater::getByRate(float minRate, int videoTypes) const{
    return getVideosBy([minRate, videoTypes](Video* v) {
        return v->getRating()>=minRate && VideoRater::videoTypeChecker(videoTypes, v);
    });
}

std::vector<Video*> VideoRater::getByGenre(const Genre& genre, int videoTypes) const{
    return getVideosBy([genre, videoTypes](Video* v) {
        return v->getGenre() == genre && VideoRater::videoTypeChecker(videoTypes, v);
    });
}

Video& VideoRater::operator[](const Id& id){
    auto found = std::find_if(videos.begin(), videos.end(), [id](Video* v){return v->hasId(id);});
    if (found != videos.end())
        return **found;
    else
        throw std::invalid_argument("Video con Id " + id.toString() + " no encontrado");
}
