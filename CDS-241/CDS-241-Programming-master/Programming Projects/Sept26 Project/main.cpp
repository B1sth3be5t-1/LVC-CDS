#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <fstream>
#include <string>

using namespace std;

int main() {
    int max;
    double num, mean, median, stdDev;
    string title;
    const string lineLong = "----------------|---------------|---------------|---------------|----------------";
    const string lineShort = "\t\t|-----------------------------------------------|"; // 47 chars
    vector<double> vals;
    vector<int> buckets;

    //open file
    ifstream file {"../grades.txt"};

    //file check
    if (!file.is_open()) {
        cout << "Error opening file";
        return 1;
    }

    //get first number, skip a line, and get second line 
    file >> max;
    getline(file, title);
    getline(file, title);

    //read doubles from file
    while (file >> num) vals.push_back(num);

    //calculate mean
    double total;
    for (auto d : vals) 
        total += d;
    total /= vals.size();
    mean = total;

    
    //calculate median
    sort(vals.begin(), vals.end());

    if (vals.size() % 2 != 0) 
        median = vals[(vals.size() + 1) / 2];
    else 
        median = (vals[(vals.size() + 1) / 2] + vals[(vals.size() + 2) / 2]) / 2;
    //calculate standard deviation
    for (auto d : vals)
        stdDev += pow((d - mean), 2);
    stdDev /= mean;
    stdDev = sqrt(stdDev);
    
    //create buckets
    for (int i = 0; i < 5; ++i) buckets.push_back(0);

    for (auto d : vals) {
        double percent = d * 100 / max;
        if (percent < 60) ++buckets[0];
        else if (percent == 100) ++buckets[4];
        else ++buckets[(percent / 10) - 5];
    }


    
    //output name of assignment
    {
    cout << lineShort << endl;
    string endT {"\t\t\t\t\t\t\t\t|"};
    cout << "\t\t|\t    " << title << endT << endl;
    }

    //output basic information
    {
    cout << lineShort << endl;
    cout << "\t\t|      Perfect Score:\t|     # of scores:\t|" << endl;
    cout << lineShort << endl;

    cout << "\t\t|\t    " << max << "\t\t|" << "\t   " << vals.size() << "\t\t|" << endl;
    cout << lineShort << endl;
    }

    //outputs titles
    {
    cout << lineShort << endl;
    cout << "\t\t|    Average:\t|     Median:\t|    Std. Dev\t|" << endl;
    cout << lineShort << endl;
    }
    
    //output values
    {
    printf ("\t\t|   %f\t|   %f\t|   %f\t|\n", mean, median, stdDev);
    cout << lineShort << endl;
    cout << lineShort << endl;

    cout << "\t\t|\t\t     Buckets: \t\t\t|" << endl;
    }

    //outputs letter row
    {
    vector<char> letters {'F', 'D', 'C', 'B', 'A'};
    cout << lineLong << endl;
    for (int i = 0; i < letters.size(); ++i)  
        cout << "|\t" << letters[i] << "\t";
    cout << "|" << endl;
    cout << lineLong << endl;
    }

    //outputs bucket numbers
    {
    for (int i = 0; i < buckets.size(); ++i) 
        cout << "|\t" << buckets[i] << "\t";
    cout << "|" << endl;
    cout << lineLong << endl;
    }

    //output C count
    {
    cout << lineShort << endl;
    cout << "\t\t|\t       Passing grades (C):  \t\t|" << endl;
    cout << lineShort << endl;
    cout << "\t\t|\t\t      " << (buckets[2] + buckets[3] + buckets[4]) << "/" << vals.size() << "\t\t\t|" << endl;
    }
}
