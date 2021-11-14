#include "Container.h"


Container::Container() {
    len = 0;
}

void Container::Fill(ifstream &input_stream) {
    while (!input_stream.eof()) {
        if ((storage[len] = Film::StaticRead(input_stream)) != nullptr) {
            len++;
        }
    }
}

void Container::RandomFill(int count) {
    while (len < count) {
        if ((storage[len] = Film::StaticRandomRead()) != nullptr) {
            len++;
        }
    }
}

void Container::Write(ofstream &output_stream) {
    output_stream << "Container contains " << len << " elements." << endl << endl;
    for (int i = 0; i < len; i++) {
        storage[i]->Write(output_stream);
    }
}

double Container::DeleteElements() {
    double sum = 0;
    for (int i = 0; i < len; i++) {
        sum += storage[i]->Func();
    }

    double average = sum / (len);

    for (int i = 0; i < len; i++) {
        if (storage[i]->Func() > average) {
            for(int j = i; j < len; j++) {
                storage[j] = storage[j+1];
            }
            storage[len-1] = nullptr;
            len--;
            i--;
        }
    }

    return average;
}

void Container::Clear() {
    for (int i = 0; i < len; i++) {
        delete storage[i];
    }

    len = 0;
}

Container::~Container() {
    Clear();
}
