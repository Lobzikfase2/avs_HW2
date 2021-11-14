#ifndef TASK2_FEATUREFILM_H
#define TASK2_FEATUREFILM_H

#include <fstream>
#include "Film.h"
using namespace std;


class FeatureFilm : public Film{
public:
    FeatureFilm();
    void Read(ifstream &input_stream) override;
    void RandomRead() override;
    void Write(ofstream &output_stream) override;

private:
    string director;
};


#endif
