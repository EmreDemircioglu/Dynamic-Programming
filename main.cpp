#include <iostream>
using namespace std;
#include <fstream>
#include <string>
#include "Graph.h"
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Run the code with the following command: ./project5 [input_file] [output_file]" << endl;
        return 1;
    }
    ifstream infile(argv[1]);
    string message;
    infile >> message;
    int sizeWords ;
    infile >> sizeWords;
    Graph g(message.length());
    for (int i = 0; i < sizeWords; ++i) {
        string word;
        infile >> word;
        g.rk(word.c_str(),message.c_str(),101);
    }
    ofstream myfile;
    myfile.open(argv[2]);
    myfile << g.solve();
    myfile.close();
    return 0;
}