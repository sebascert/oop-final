#pragma once

#include <cstdint>
#include <string>

class Id{
    const static int idLength;
    const static int seasonLength;
    const static int episodeLength;

    uint32_t id;
    uint8_t season;
    uint8_t episode;

    public:
        Id(std::string id);

        std::string toString() const;
        bool operator==(const Id& other) const;
};
