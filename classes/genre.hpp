#pragma once

#include <string>

class Genre{
    std::string value;

    public:
        Genre(std::string genre);

        std::string toString();
        bool operator==(Genre& other) const;
};
