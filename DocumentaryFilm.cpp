#include "DocumentaryFilm.h"


DocumentaryFilm::DocumentaryFilm() {
    title = "None";
    year = duration = 0;
}

void DocumentaryFilm::Read(ifstream &input_stream) {
    ::Film::Read(input_stream);
    string s_duration;
    getline(input_stream, s_duration);
    duration = stoi(s_duration);
}

void DocumentaryFilm::RandomRead() {
    ::Film::RandomRead();
    duration = rand() % 150 + 60;
}

void DocumentaryFilm::Write(ofstream &output_stream) {
    output_stream << "Documentary film:" << endl;
    ::Film::Write(output_stream);
    output_stream << "\tduration: " << duration << endl;
    output_stream << endl;
}
