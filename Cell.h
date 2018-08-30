

#ifndef TIC_TAC_TOE_CELL_H
#define TIC_TAC_TOE_CELL_H


#include <ostream>
#include <iostream>

using namespace std;

class Cell {
private:
    int i;
    int j;
    char sign;
public:
    Cell();
    explicit Cell(int i, int j);
    Cell(const Cell& cell)= default;
    Cell &operator=(const Cell& cell)= default;
    ~Cell()= default;
    int getI() const;
    int getJ() const;
    char getSign() const;
    void setSign(char sign);
    bool isEmpty() const;


    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);
};


#endif //TIC_TAC_TOE_CELL_H
