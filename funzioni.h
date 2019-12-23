//
// Created by stefano on 23/12/2019.
//

#ifndef PROGETTOALGORITMI_FUNZIONI_H
#define PROGETTOALGORITMI_FUNZIONI_H

#ifndef iostream
#include <iostream>
#endif
#ifndef sstream
#include <sstream>
#endif
#ifndef vector
#include <vector>
#endif

using namespace std;

/**
 * Trasforma un vector in un output
 * Uso: cout << myVector << endl;
 */
template <typename T>               // sends a vector to a line of output stream
ostream &operator << (ostream &out, const vector<T> &vec){
    for(long i=0; i<vec.size(); i++)
        out << vec[i] << " ";
    out << endl;
    return out;
}

/**
 * Trasforma l'input in un vector
 * Uso: cin >> myVector;
 */
template <typename T>               // consumes a line of input and stores it into a vector
istream &operator >> (istream &in, vector<T> &vec){
    string line;
    getline(in, line);      // read entire line from input stream
    istringstream sin(line);        // create new stream from line

    int value;
    vec.clear();
    while(sin >> value)             // turn line stream into vector
        vec.push_back(value);
    return in;
}

#endif //PROGETTOALGORITMI_FUNZIONI_H
