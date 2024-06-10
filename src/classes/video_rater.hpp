#pragma once

#include <vector>
#include <sstream>
#include <functional>

#include "video.hpp"

class VideoRater{
    std::vector<Video*> videos;

    std::vector<Video*> getVideosBy(std::function<bool(Video*)> predicate) const;

    public:
        VideoRater(std::istringstream input);
        ~VideoRater();

        std::vector<Video*> getCatalog() const;
        std::vector<Video*> getByRate(float minRate, int videoTypes) const;
        std::vector<Video*> getByGenre(const Genre& genre, int videoTypes) const;
        Video& operator[](const Id& id);
};
