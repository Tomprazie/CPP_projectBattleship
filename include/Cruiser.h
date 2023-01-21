#ifndef CRUISER_H
#define CRUISER_H

#include "Boat.h"
#include <string>

using namespace std;


class Cruiser : public Boat
{
    private:

    public:
        Cruiser(int originLine, int originRow, string direction) : Boat(4, originLine, originRow, direction) {}

        virtual ~Cruiser() {}

        bool isSunk() {
            if (this->getNumberOfHit() == 4) return true;
            else return false;
        }
};

#endif // CRUISER_H
