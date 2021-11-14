#include <iostream>
#include <cstring>
#include "Container.h"


int main(int argc, char* argv[]) {
    if(argc != 5) {
        cout << "Incorrect command line!\n"
                "  Waited:\n"
                "     command -i input_file output_file01 output_file02\n"
                "  Or:\n"
                "     command -f number output_file01 output_file02\n";
        return 1;
    }

    Container container;
    clock_t start_time = clock();

    if (strcmp(argv[1], "-i") == 0) {
        cout << "Start..." << endl;
        ifstream input_stream(argv[2]);
        try {
            container.Fill(input_stream);
        }
        catch (exception){
            cout << "Problems with input_file! Check data in file, or try another file path." << endl;
            return 2;
        }
    }
    else if (strcmp(argv[1], "-g") == 0) {
        int count = stoi(argv[2]);
        if ((count < 1) || (count > 10000)) {
            cout << "Incorrect number of films = " << count << "! Choose from [1, 10000].\n";
            return 3;
        }

        srand(time(nullptr));
        cout << "Start..." << endl;
        container.RandomFill(count);
    }
    else {
        cout << "Incorrect qualifier value!\n"
                "  Waited:\n"
                "     command -i input_file output_file01 output_file02\n"
                "  Or:\n"
                "     command -g number output_file01 output_file02\n";
        return 4;
    }

    ofstream output_stream1(argv[3]);
    ofstream output_stream2(argv[4]);
    container.Write(output_stream1);
    output_stream2 << "Function average: " << container.DeleteElements() << "." << endl;
    container.Write(output_stream2);

    clock_t end_time = clock();
    double seconds = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time has passed: " << seconds << "s." << endl;
    cout << "End." << endl;
    return 0;
}
