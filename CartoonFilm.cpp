#include "CartoonFilm.h"


CartoonFilm::CartoonFilm() {
    title = "None";
    year = 0;
    t = type(0);
}

void CartoonFilm::Read(ifstream &input_stream) {
    ::Film::Read(input_stream);
    string s_type;
    getline(input_stream, s_type);
    t = type(stoi(s_type));
}

void CartoonFilm::RandomRead() {
    ::Film::RandomRead();
    t = type(rand() % 3);
}

void CartoonFilm::Write(ofstream &output_stream) {
    output_stream << "Cartoon film:" << endl;
    ::Film::Write(output_stream);

    switch (t) {
        case type::HAND_DRAWN:
            output_stream << "\ttype: " << "hand drawn" << endl;
            break;
        case type::PUPPET:
            output_stream << "\ttype: " << "puppet" << endl;
            break;
        case type::PLASTICINE:
            output_stream << "\ttype: " << "plasticine" << endl;
            break;
    }

    output_stream << endl;
}
