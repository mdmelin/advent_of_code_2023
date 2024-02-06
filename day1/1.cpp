#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>
#include <string>
#include <chrono>
#include <algorithm>
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

tuple<vector<int>, vector<char>> check_if_substrings_in_string(string inpt_string, vector<string>& stringstocheck) {
    vector<int> positions;
    vector<char> numbers;
    int position = -1;
    for (int i = 0; i < stringstocheck.size(); i++) { //TODO: handle case where substring occurs more than once
        position = inpt_string.find(stringstocheck[i]);
        if (position != -1) {
            //cout << "position is " << position << endl;
            //cout << "number is " << i+1 << endl;
            char num = '0' + i+1;
            //cout << "num is " << num << endl;
            numbers.push_back(num);
            positions.push_back(position);
        }
    }
    return make_tuple(positions, numbers);
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
        char firstnum = '0';
        char lastnum = '0';
        int last_position = -1;
        int first_position = -1;
        int first_index = 0;
        int last_index = 0;
        for (int i = 0; i < line.length(); i++) { //iterate across a line to find digits
            if (isdigit(line[i])) {
                if (firstnum == '0') {
                    firstnum = line[i];
                    first_index = i;
                }
                lastnum = line[i];
                last_index = i;
            }
        }
        for (int i = 0; i < numbers.size(); i++) { //find digit strings in a line
            first_position = line.find(numbers[i]);
            last_position = line.rfind(numbers[i]);
            if (first_position != -1 && first_position < first_index) {
                firstnum = i+1 + '0';
                first_index = first_position;
            } 
            if (last_position != -1 && last_position > last_index) {
                lastnum = i+1 + '0';
                last_index = last_position;
            }
        }
        //cout << line << endl;
        string numstring = {firstnum, lastnum};
        //cout << numstring << endl;
        running_sum += stoi(numstring);
    }
    file.close();
    cout << "running sum is " << running_sum << endl;
    return 0;
}

int main() {
    auto start = chrono::high_resolution_clock::now();
    part1();
    //auto [locs, nums] = check_if_substrings_in_string("one two this four", numbers);
    part2();
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop - start);
    cout << "Time taken by function: " << duration.count() << " microseconds" << endl;
    return 0;
}