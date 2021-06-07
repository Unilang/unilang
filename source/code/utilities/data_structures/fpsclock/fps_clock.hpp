#pragma once

// Simple fps handling class for sfml based on the sf::Clock class
// As init value for fpsClock you pass an amount of fps you want to acquire.
// the tick() method control frame rate and interpolation returns interpolated value between frames.

#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

class FpsClock {
    sf::Clock clock;
    sf::Time presentTime;
    sf::Time skipTime;
    sf::Time prevTime;

    public:
    FpsClock( int skipTime_ );
    bool tick();
    double interpolation();
};
