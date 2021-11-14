#ifndef TASK2_CARTOONFILM_H
#define TASK2_CARTOONFILM_H

#include <fstream>
#include "Film.h"
using namespace std;


class CartoonFilm : public Film{
public:
    CartoonFilm();
    void Read(ifstream &input_stream) override;
    void RandomRead() override;
    void Write(ofstream &output_stream) override;

private:
    enum type {HAND_DRAWN, PUPPET, PLASTICINE};
    type t;
};


#endif
