#pragma once

#include <string>

class Rating{
    int count;
    float value;

    public:
        Rating();

        static bool validRate(float rate);
        void rate(int rate);
        std::string toString() const;
        bool operator>=(float other) const;
};
