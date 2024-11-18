//C:\Users\User\source\repos\Lab11.2\t1.txt
#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

string Spaces(const string& s) {
    string result = s;

    result.erase(result.begin(), find_if(result.begin(), result.end(), [](char ch) {
        return ch != ' ';
        }));

    result.erase(find_if(result.rbegin(), result.rend(), [](char ch) {
        return ch != ' ';
        }).base(), result.end());

    auto new_end = unique(result.begin(), result.end(), [](char a, char b) {
        return a == ' ' && b == ' ';
        });
    result.erase(new_end, result.end());

    return result;
}

int main() {
    setlocale(LC_ALL, "ukr");
    string inputFileName, outputFileName;

    cout << "Введiть файл: ";
    cin >> inputFileName;
    cout << "Файл щоб зберегти: ";
    cin >> outputFileName;

    ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        cout << "Не вдалося вiдкрити файл!" << endl;
        return 1;
    }

    ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        cout << "Не вдалося знайти файл!" << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line)) {
        string processedLine = Spaces(line);
        outputFile << processedLine << endl;
    }

    inputFile.close();
    outputFile.close();

    cout << "Виправлений файл: " << outputFileName << endl;

    return 0;
}
