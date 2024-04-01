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

float find_mean(vector<int> row) {
    float mean;
    int size = row.size();
    float total=0;

    for (int i = 0; i < size; i++)
    {
        total = total + row[i];
    }

    mean = total/size;

    return mean;
}

string find_mode(vector<int> row) {
    string mode;
    int size = row.size();
    int max_size = 1;
    int current_size = 1;

    mode = to_string(row[0]);

    for (int i = 1; i < size; i++)
    {
        if (row[i] == row[i-1])
        {
            current_size++;
        } else {
            current_size = 1;
        }

        if (current_size > max_size)
        {
            max_size = current_size;
            mode = to_string(row[i]);
        } else if (current_size == max_size) {
            mode = mode + "," + to_string(row[i]);
        }
    }

    return mode;
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

void assert(string val1, string val2) {
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
    float mean;
    string mode;
    //tests all the data sets

    row = read(row, "Data1.csv");
    med = find_medium(row);
    mean = find_mean(row);
    mode = find_mode(row);
    assert(med, 25);
    assert(mean, 36);
    cout << mode << endl;
    //assert(mode, 36);
    row.clear();

    row = read(row, "Data2.csv");
    med = find_medium(row);
    mean = find_mean(row);
    mode = find_mode(row);
    assert(med, 53);
    assert(mean, 50.7);
    cout << mode << endl;
    row.clear();

    row = read(row, "Data3.csv");
    med = find_medium(row);
    mean = find_mean(row);
    mode = find_mode(row);
    assert(med, 5.5);
    assert(mean, 5.5);
    cout << mode << endl;
    row.clear();

    row = read(row, "Data4.csv");
    med = find_medium(row);
    mean = find_mean(row);
    mode = find_mode(row);
    assert(med, 10);
    assert(mean, 9);
    cout << mode << endl;
    row.clear();

    row = read(row, "Data5.csv");
    med = find_medium(row);
    mean = find_mean(row);
    mode = find_mode(row);
    assert(med, 10);
    assert(mean, 8.66667);
    cout << mode << endl;
    row.clear();

    row = read(row, "Data6.csv");
    med = find_medium(row);
    mean = find_mean(row);
    mode = find_mode(row);
    assert(med, 15.5);
    assert(mean, 15.66667);
    cout << mode << endl;
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
