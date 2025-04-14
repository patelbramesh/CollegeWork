/*
File Name: chapter5exe18.cpp
Programer Name: Bramesh Patel
Date: 04/25
Requirements: 
Write a program that produces a bar chart showing the population growth of Prairieville, 
a small town in the Midwest, at 20-year intervals during the past 100 years. 
The program should read in the population figures for 1900, 1920, 1940, 1960, 1980, and 2000 from a file. 

Here is an example of how the chart might begin:

    PRAIRIEVILLE POPULATION GROWTH
    (each * represents 1,000 people)
    1900 **
    1920 ****
    1940 *****
*/
#include<iostream>
#include<fstream>
using namespace std;

void openFile(ifstream& file, string filename) {

    file.open(filename); 

    if(!file){
        cerr << "Error: Could not open file " << filename << endl;
        exit(1); 
    }
}
void displayChart(ifstream& file){
    int population = 6;
    int years = 1900;

    cout << "PRAIRIEVILLE POPULATION GROWTH\n";
    cout << "(each * represents 1,000 people)\n";

    // To read each population number from the file
    while (file >> population) {

        // Print the year
        cout << years << " ";

    // Print one * for every 1000 people
    for (int i = 0; i < population / 1000; ++i) {
            cout << "*";
        }

        cout << endl;     // Move to the next line
        years += 20;       // Move to the next year interval
    }
}

int main(){

    ifstream inputFile;

    // To open the file safely
    openFile(inputFile, "People.txt");

    // Call the module to read from the file and print the population bar chart
    displayChart(inputFile);

    // Close the file after reading is complete
    inputFile.close();

    return 0; 
}