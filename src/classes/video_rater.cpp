#include <sstream>
#include <string>
#include <algorithm>

#include "video_rater.hpp"
#include "movie.hpp"
#include "episode.hpp"
#include "../ui/get_input.hpp"

VideoRater::VideoRater(std::istream& input){
    int line = 1;
    try{
        while (input.peek() != EOF){
            char videoType = getInput<char>(input, "Tipo de video invalido", ',');
            Id id = getInput<Id>(input, "Id invalido", ',');
            std::string name = getInput<std::string>(input, "Error en string", ',');
            int duration = getInput<int>(input, "Duracion invalida", ',');;
            if (videoType == 'c'){
                Genre genre = getInput<Genre>(input, "Genero invalido", ',');;
                std::string title = getInput<std::string>(input, "Error en string", ',');
                int episode = getInput<int>(input, "Episodio invalido", '\n');
                videos.emplace_back(new Episode(id, name, duration, genre, title));
                continue;
            }else if (videoType == 'p'){
                Genre genre = getInput<Genre>(input, "Genero invalido", '\n');;
                videos.emplace_back(new Movie(id, name, duration, genre));
            }else
                throw std::invalid_argument("");
            line++;
        }
    }catch (std::invalid_argument& e){
        std::stringstream ss("");
        ss << "Datos de video invalido, linea:";
        if (e.what() != "")
            ss << "\nError: " << e.what();
        throw std::invalid_argument(ss.str());
    }
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
