#include "Film.h"
#include "FeatureFilm.h"
#include "CartoonFilm.h"
#include "DocumentaryFilm.h"


Film* Film::StaticRead(ifstream &input_stream) {
    string type;
    getline(input_stream, type);

    Film* film = nullptr;

    switch(stoi(type)) {
        case 1:
            film = new FeatureFilm;
            film->Read(input_stream);
            break;
        case 2:
            film = new CartoonFilm;
            film->Read(input_stream);
            break;
        case 3:
            film = new DocumentaryFilm;
            film->Read(input_stream);
            break;
    }

    return film;
}

Film* Film::StaticRandomRead() {
    int type = rand() % 3 + 1;
    Film* film = nullptr;

    switch(type) {
        case 1:
            film = new FeatureFilm;
            film->RandomRead();
            break;
        case 2:
            film = new CartoonFilm;
            film->RandomRead();
            break;
        case 3:
            film = new DocumentaryFilm;
            film->RandomRead();
            break;
    }

    return film;
}

void Film::Read(ifstream &input_stream) {
    getline(input_stream, title);
    string s_year;
    getline(input_stream, s_year);
    year = stoi(s_year);
}

void Film::RandomRead() {
    title = GenStr();
    year = rand() % 126 + 1895;
}

void Film::Write(ofstream &output_stream) {
    output_stream << "\ttitle: " << title << endl;
    output_stream << "\tyear: " << year << endl;
}

double Film::Func() {
    return year / title.length();
}