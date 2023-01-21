#ifndef AIRCRAFTCARRIER_H
#define AIRCRAFTCARRIER_H

#include "Boat.h"
#include <string>

using namespace std;


class AircraftCarrier : public Boat
{
    private:

    public:
        AircraftCarrier(int originLine, int originRow, string direction) : Boat(5, originLine, originRow, direction) {}

        virtual ~AircraftCarrier() {}

        bool isSunk() {
            if (this->getNumberOfHit() == 5) return true;
            else return false;
        }
};

#endif // AIRCRAFTCARRIER_H
