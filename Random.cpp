#include "Random.h"


std::string GenStr() {
    std::string str;
    str += char(rand() % 26 + int('A'));

    for (int i = 0; i < rand() % 21 + 3; ++i) {
        str += char(rand() % 26 + int('a'));
    }

    return str;
}
