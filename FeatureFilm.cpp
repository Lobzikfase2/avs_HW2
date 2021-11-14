#include "FeatureFilm.h"


FeatureFilm::FeatureFilm() {
    title = director = "None";
    year = 0;
}

void FeatureFilm::Read(ifstream &input_stream) {
    ::Film::Read(input_stream);
    getline(input_stream, director);
}

void FeatureFilm::RandomRead() {
    ::Film::RandomRead();
    director = GenStr() + " " + GenStr();
}

void FeatureFilm::Write(ofstream &output_stream) {
    output_stream << "Feature film:" << endl;
    ::Film::Write(output_stream);
    output_stream << "\tdirector: " << director << endl;
    output_stream << endl;
}
