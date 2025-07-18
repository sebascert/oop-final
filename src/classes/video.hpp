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

        Rating& getRating();
        const Genre& getGenre() const;
        bool hasId(const Id& id) const;
        std::string ratingFormat() const;
        std::string genreFormat() const;
        virtual std::string toString() const = 0;
        friend std::ostream& operator<<(std::ostream& os, const Video& obj);
};
