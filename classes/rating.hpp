#pragma once

#include <string>

class Rating{
    int count;
    float value;

    public:
        Rating();

        std::string toString() const;
        void rate(int rate);
};
