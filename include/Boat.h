#ifndef BOAT_H
#define BOAT_H


#include <string>

using namespace std;


class Boat
{
    private:
        int length;
        int originLine;
        int originRow;
        string direction;
        int numberOfHit = 0;

    public:
        Boat(int length, int originLine, int originRow, string direction) {
            this->length = length;
            this->originLine = originLine;
            this->originRow = originRow;
            this->direction = direction;
        }

        virtual ~Boat() {}

        void isHit() {
            numberOfHit += 1;
        }

        int getNumberOfHit() {
            return numberOfHit;
        }

        virtual bool isSunk() {return false;}
};

#endif // BOAT_H
