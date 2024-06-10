#pragma once

#include <string>

#include "video.hpp"

class Episode : public Video{
    using Video::Video;

    std::string title;

    public:
        Episode(Id id, std::string name, int duration, Genre genre, std::string title);
        std::string toString() const;
};
