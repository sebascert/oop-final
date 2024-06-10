#pragma once

#include "video.hpp"

class Movie : public Video{
    using Video::Video;

    public:
        std::string toString() const override;
};
