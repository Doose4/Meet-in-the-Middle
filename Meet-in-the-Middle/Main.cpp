#include <iostream>
#include <fstream>
#include <sstream>

#include <string>
#include <vector>

using namespace std;

vector<int> read(vector<int> row, string filename)
{
    ifstream fin;
    string line;
    string val;
    

    // Open an existing file
    fin.open(filename);
    fin >> line;
    cout << line << endl;

    // Set's values in a vector with commas being the devider
    stringstream s(line);
    while (getline(s, val, ',')) {
        row.push_back(stoi(val));
    }

    //for (auto& val : row) {
    //    cout << val << "  ";
    //}

    fin.close();

    return row;
}

float even_medium(vector<int> row) {
    int size = row.size();
    size = ((size) / 2);
    float val1 = row[size];
    float val2 = row[size - 1];
    float med;
    med = (val1 + val2) / 2;
    return med;

}

float odd_medium(vector<int> row) {
    int size = row.size();
    size = ((size - 1) / 2);
    return row[size];
}

float find_medium(vector<int> row) {
    float med;

    int size = row.size();

    if ((size % 2) == 0) {
        med = even_medium(row);
    }
    else {
        med = odd_medium(row);
    }

    return med;
}

void assert(float val1, float val2){
    if (val1 == val2) { 
        cout << "Test Good!" << endl;
    }
    else {
        cout << "Test Failed! :(" << endl;
        cout << "The actual value was : " << val1 << endl
            << "This does not match: " << val2 << endl;
    }
}

void tester(vector<int> row) {
    float med;
    //tests all the data sets

    row = read(row, "Data1.csv");
    med = find_medium(row);
    assert(med, 25);
    row.clear();

    row = read(row, "Data2.csv");
    med = find_medium(row);
    assert(med, 53);
    row.clear();

    row = read(row, "Data3.csv");
    med = find_medium(row);
    assert(med, 5.5);
    row.clear();

    row = read(row, "Data4.csv");
    med = find_medium(row);
    assert(med, 10);
    row.clear();

    row = read(row, "Data5.csv");
    med = find_medium(row);
    assert(med, 10);
    row.clear();

    row = read(row, "Data6.csv");
    med = find_medium(row);
    assert(med, 15.5);
    row.clear();

    cout << "Test completed!" << endl;
}

int main() {
    vector<int> row;
    string userinput; 
    float med;

    cout << "Please enter the file name: " << endl;
    cin >> userinput;

    if (userinput == "test") 
    {
        tester(row);
        return 0;
    }

    row = read(row, userinput);

    med = find_medium(row);
    

    cout << "The medium number is: " << med << endl;

    return 0;
}
