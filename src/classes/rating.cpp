#include <sstream>
#include <iomanip>

#include "rating.hpp"

Rating::Rating() : count(0), value(0) {}

std::string Rating::toString() const{
    if (count == 0)
        return "SC";

    std::stringstream ss("");
    ss << std::fixed << std::setprecision(1) << value;
    return ss.str();
}

void Rating::rate(int rate){
    if (rate < 1 || rate > 5)
        throw std::invalid_argument("Calificacion invalida");

    count++;
    value = value*(1-(1.0/count)) + (((float)rate)/count);
}

bool Rating::operator>=(float other) const{
    return count > 0 && value >= other;
}
