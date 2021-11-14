#ifndef TASK2_DOCUMENTARYFILM_H
#define TASK2_DOCUMENTARYFILM_H

#include <fstream>
#include "Film.h"
using namespace std;


class DocumentaryFilm : public Film{
public:
    DocumentaryFilm();
    void Read(ifstream &input_stream) override;
    void RandomRead() override;
    void Write(ofstream &output_stream) override;

private:
    int duration;
};


#endif
