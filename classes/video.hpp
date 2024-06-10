#pragma once

#include <string>

#include "id.hpp"
#include "genre.hpp"
#include "rating.hpp"

class Video{
    protected:
        Id id;
        std::string name;
        int duration;
        Genre genre;
        Rating rating;

    public:

        Video(Id id, std::string name, int duration, Genre genre);
        void rateVideo(int rate);
        virtual std::string tostring() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Video& obj);
};
