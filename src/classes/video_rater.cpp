#include <iostream>
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
            std::string name = getInput<std::string>(input, "", ',');
            int duration = getInput<int>(input, "Duracion invalida", ',');;
            // First reads genres value, registers it to valid and then pass it to Video
            if (videoType == 'p'){
                std::string str_genre = getInput<std::string>(input, "Genero invalido", '\n');;
                Genre::registerValidGenre(str_genre);
                videos.emplace_back(new Movie(id, name, duration, Genre(str_genre)));
            }else if (videoType == 'c'){
                std::string str_genre = getInput<std::string>(input, "Genero invalido", ',');;
                Genre::registerValidGenre(str_genre);
                std::string title = getInput<std::string>(input, "", ',');
                int episode = getInput<int>(input, "Episodio invalido", '\n');
                videos.emplace_back(new Episode(id, name, duration, Genre(str_genre), title));
                continue;
            }else
                throw std::invalid_argument("");
            line++;
        }
    }catch (std::invalid_argument& e){
        std::cout << "Datos de video invalido, linea:" << line;
        if (e.what() != "")
            std::cout << "\nError: " << e.what();
        exit(EXIT_FAILURE);
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

bool VideoRater::videoTypeChecker(int videoTypes, Video* video){
    bool validType;
    if (videoTypes == 1)
        validType = dynamic_cast<Movie*>(video) != nullptr;
    else if (videoTypes == 2)
        validType = dynamic_cast<Episode*>(video) != nullptr;
    else if (videoTypes == 3)
        validType = true;
    else
        throw std::invalid_argument("Tipo de videos " + std::to_string(videoTypes) + " invalido");
    return validType;
}

std::vector<Video*> VideoRater::getCatalog() const{
    return videos;
}

std::vector<Video*> VideoRater::getByRate(float minRate, int videoTypes) const{
    if (!Rating::validRate(minRate))
        throw std::invalid_argument("Calificacion invalida");

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
