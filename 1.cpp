#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <chrono>
#include <tuple>

using namespace std;

vector<string> numbers = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

int part1() {
    ifstream file;
    file.open("inpt1.txt");
    if (!file) {
        cout << "Error in opening file" << endl;
        return 1;
    }
    string line;
    int running_sum = 0;

    while(getline(file, line)) {
    vector<char> digits_on_line;
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                digits_on_line.push_back(line[i]);
            }
        }
        string numstring = {digits_on_line[0], digits_on_line.back()};
        //cout << numstring << endl;
        running_sum += stoi(numstring);
    }
    file.close();
    cout << "running sum is " << running_sum << endl;
    return 0;
}

tuple<int, int> check_if_substrings_in_string(string inpt_string, vector<string>& stringstocheck) {
    int position = -1;
    int number = -1;
    for (int i = 0; i < stringstocheck.size(); i++) {
        position = inpt_string.find(stringstocheck[i]);
        if (position != -1) {
            cout << "position is " << position << endl;
            cout << "number is " << i+1 << endl;
            number = i+1; //TODO: make this return all the values it found in the string, not just the first one
        }
    }
    return make_tuple(position, number);
}

int part2() {
    ifstream file;
    file.open("inpt1.txt");
    if (!file) {
        cout << "Error in opening file" << endl;
        return 1;
    }
    string line;
    int running_sum = 0;

    while(getline(file, line)) {
    vector<char> digits_on_line;
        for (int i = 0; i < line.length(); i++) {
            if (isdigit(line[i])) {
                digits_on_line.push_back(line[i]);
            }
        }
        string numstring = {digits_on_line[0], digits_on_line.back()};
        //cout << numstring << endl;
        running_sum += stoi(numstring);
    }
    file.close();
    cout << "running sum is " << running_sum << endl;
    return 0;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    cout << "Hello, World!" << endl;
    part1();
    auto result = check_if_substrings_in_string("one two this four", numbers);

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}