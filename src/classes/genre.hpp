#pragma once

#include <string>
#include <unordered_set>

class Genre{
    std::string value;
    static std::unordered_set<std::string> validGenres;


    public:
        Genre(std::string genre);

        std::string toString() const;
        static void registerValidGenre(std::string genre);
        bool operator==(const Genre& other) const;
};
