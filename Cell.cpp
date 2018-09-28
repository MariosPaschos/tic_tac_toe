#include "Cell.h"

// Default constructor
Cell::Cell() : i(-1), j(-1), sign('_') {}

Cell::Cell(int i, int j) : i(i), j(j) , sign('_') {}

int Cell::getI() const {
    return i;
}

int Cell::getJ() const {
    return j;
}

char Cell::getSign() const {
    return sign;
}

void Cell::setSign(char sign) {
    this->sign = sign;
}

std::ostream &operator<<(std::ostream &os, const Cell &cell) {
    os << "(" << cell.i << "," << cell.j <<") " << endl;
    return os;
}

bool Cell::isEmpty() const {
    return this->getSign() == '_';
}




