#pragma once

#include <cstddef>
#include <vector>
#include <list>

class Coord {
    std::pair<size_t, size_t> el;

public:
    Coord(size_t x, size_t y): el(x, y) {}

    size_t x() {
        return el.first;
    }

    size_t y() {
        return el.second;
    }
};

class Model {
    std::vector<Coord> rabbits_{Coord(5,5), Coord(6,6), Coord(7,7)};
    std::list<Coord> snake_ = {Coord(2,2), Coord(2,3), Coord(2,4)};

public:
    Model() {}

    const std::list<Coord>& snake() {
        return snake_;
    }

    const std::vector<Coord>& rabbits() {
        return rabbits_;
    }
};
