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
        const Genre& getGenre() const;
        const Rating& getRating() const;
        bool hasId(Id id) const;
        virtual std::string tostring() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Video& obj);
};
