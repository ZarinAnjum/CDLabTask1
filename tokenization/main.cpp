#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> generateLineTokens(const string& fileName) {
    vector<string> tokens;
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "Error: Could not open file " << fileName << endl;
        return tokens;
    }

    string line;
    while (getline(inputFile, line)) {
        tokens.push_back(line);
    }

    inputFile.close();
    return tokens;
}

int main() {
    string sourceFileName = "sam.txt";
    vector<string> lineTokens = generateLineTokens(sourceFileName);

    if (lineTokens.empty() && sourceFileName.find("Error:") == string::npos) {
        cout << "The file was read, but no lines (tokens) were found." << endl;
        return 0;
    }

    cout << "--- Tokens (Source Code Lines) from " << sourceFileName << " ---" << endl;
    for (size_t i = 0; i < lineTokens.size(); ++i) {
        cout << "Line [" << i + 1 << "]: \"" << lineTokens[i] << "\"" << endl;
    }
    cout << "  " << endl;
    cout << "Total lines/tokens generated: " << lineTokens.size() << endl;

    return 0;
}