#ifndef DESTROYER_H
#define DESTROYER_H

#include "Boat.h"
#include <string>

using namespace std;


class Destroyer : public Boat
{
    private:

    public:
        Destroyer(int originLine, int originRow, string direction) : Boat(3, originLine, originRow, direction) {}

        virtual ~Destroyer() {}

        bool isSunk() {
            if (this->getNumberOfHit() == 3) return true;
            else return false;
        }
};

#endif // DESTROYER_H
