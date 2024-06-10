#include <sstream>
#include <iomanip>

#include "id.hpp"

const int Id::idLength = 8;
const int Id::seasonLength = 2;
const int Id::episodeLength = 2;

Id::Id(std::string id) {
    if (id.length() == Id::idLength){
        this->id = std::stoi(id.substr(0, Id::idLength));
        this->season = 0;
        this->episode = 0;
    }else if (id.length() == Id::idLength+Id::seasonLength+Id::episodeLength+3){
        int p = 0;
        this->id = std::stoi(id.substr(p, Id::idLength));
        p += Id::idLength+2;
        this->season = std::stoi(id.substr(p, Id::seasonLength));
        p += Id::seasonLength+1;
        this->episode = std::stoi(id.substr(p, Id::episodeLength));
    }else
        throw std::invalid_argument("Id invalida");
}

std::string Id::toString() const{
    std::stringstream ss;
    ss << std::setw(Id::idLength) << std::setfill('0') << id;
    if (season != 0)
        ss << "-S" << std::setw(Id::seasonLength) << std::setfill('0') << +season;
    if (episode != 0)
        ss << "E" << std::setw(Id::episodeLength) << std::setfill('0') << +episode;

    return ss.str();
}

bool Id::operator==(const Id& other) const{
    return id == other.id && season == other.season && episode == other.episode;
}
