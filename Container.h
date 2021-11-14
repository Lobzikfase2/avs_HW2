#ifndef TASK2_CONTAINER_H
#define TASK2_CONTAINER_H

#include <fstream>
#include "Film.h"


class Container{
public:
    Container();
    void Fill(ifstream &input_stream);
    void RandomFill(int count);
    void Write(ofstream &output_stream);
    double DeleteElements();
    ~Container();

private:
    static const int MAX_LEN = 10000;
    int len;
    Film* storage[MAX_LEN]{};

    void Clear();
};


#endif
