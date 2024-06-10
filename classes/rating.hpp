#pragma once

#include <string>

class Rating{
    int count;
    float value;

    public:
        Rating();

        void rate(int rate);
        std::string toString() const;
        bool operator>=(float other) const;
};
