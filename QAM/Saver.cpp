#include "Saver.h"
#include <fstream>
#include <iostream>
using namespace std;


void Saver::save_vector(const vector<double>& data, const char* filename)
{
    ofstream file(filename, ios::out); 
    if (file.is_open()) 
    {
        for (const auto& value : data)
            file << value << "\n";
        file.close();
    }
    else
        cerr << "Unable to open file: " << filename << endl;
    file.close();
}
    

void Saver::save_double_vector(const vector<vector<double> >& vecOfVecs, const char* filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& vec : vecOfVecs) {
            for (const auto& item : vec) {
                file << item << " ";
            }
            file << "\n";
        }
        file.close();
    }
    else {
        cerr << "Unable to open file: " << filename << endl;
    }
    file.close();
}
