#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

using namespace std;

int* read()
{
    ifstream fin;
    string line;
    string val;
    int* row_ptr;
    vector<int> row;
    

    // Open an existing file
    fin.open("Data1.csv");
    fin >> line;
    cout << line << endl;


    stringstream s(line);
    while (getline(s, val, ',')) {
        row.push_back(stoi(val));
    }

    for (auto& val : row) {
        cout << val << "  ";
    }
    fin.close();

    row_ptr = &row[0];

    return row_ptr;
}

int main()
{
    vector<int> row;
    int* row_pnt;
    row_pnt = read();
    cout << row_pnt;
    return 0;
}

//#include <iostream>
//#include <fstream>
//#include <sstream>
//
//#include <string>
//#include <vector>
//
//using namespace std;
//
//int main(int argc, char** argv) {
//
//    string line;                    /* string to hold each line */
//    vector<vector<int>> array;      /* vector of vector<int> for 2d array */
//
//    if (argc < 2) { /* validate at least 1 argument given */
//        cerr << "error: insufficient input.\n"
//            "usage: " << argv[0] << " filename\n";
//        return 1;
//    }
//
//    ifstream f(argv[1]);   /* open file */
//    if (!f.is_open()) {     /* validate file open for reading */
//        perror(("error while opening file " + string(argv[1])).c_str());
//        return 1;
//    }
//
//    while (getline(f, line)) {         /* read each line */
//        string val;                     /* string to hold value */
//        vector<int> row;                /* vector for row of values */
//        stringstream s(line);          /* stringstream to parse csv */
//        while (getline(s, val, ','))   /* for each value */
//            row.push_back(stoi(val));  /* convert to int, add to row */
//        array.push_back(row);          /* add row to array */
//    }
//    f.close();
//
//    cout << "complete array\n\n";
//    for (auto& row : array) {           /* iterate over rows */
//        for (auto& val : row)           /* iterate over vals */
//            cout << val << "  ";        /* output value      */
//        cout << "\n";                   /* tidy up with '\n' */
//    }
//    return 0;
//}