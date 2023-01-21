#ifndef SUBMARINE_H
#define SUBMARINE_H

#include "Boat.h"
#include <string>

using namespace std;


class Submarine : public Boat
{
    private:

    public:
        Submarine(int originLine, int originRow, string direction) : Boat(2, originLine, originRow, direction) {}

        virtual ~Submarine() {}

        bool isSunk() {
            if (this->getNumberOfHit() == 2) return true;
            else return false;
        }
};

#endif // SUBMARINE_H
