#ifndef TASK2_FILM_H
#define TASK2_FILM_H

#include <fstream>
#include "Random.h"
using namespace std;


class Film{
public:
    static Film* StaticRead(ifstream &input_stream);
    static Film* StaticRandomRead();
    virtual void Read(ifstream &input_stream);
    virtual void RandomRead();
    virtual void Write(ofstream &output_stream);
    double Func();

protected:
    string title;
    int year;
};


#endif
