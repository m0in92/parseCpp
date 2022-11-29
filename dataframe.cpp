//
// Created by moina on 11/28/2022.
//

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "dataframe.h"


std::vector<std::vector<std::string>> read_csv(std::string filePath, int colNameIndex) {
    /*
     * This function opens and reads the csv file.
     * */
    // open csv file
    std::ifstream inputFile;
    inputFile.open(filePath);

    // initialize the dataframe and line
    std::string line;
    std::vector<std::vector<std::string>> dataFrame;

    while (std::getline(inputFile, line)) {
        // initialize row entry (single entry within a row, rowInput(entire row), and rowVector (vector containing all
        // row entries.)
        std::string  rowEntry;
        std::stringstream rowInput(line);
        std::vector<std::string> rowVector;
        while (std::getline(rowInput, rowEntry, ',')) {
            rowVector.push_back(rowEntry);
        }
        // add rowVector to the dataframe vector.
        dataFrame.push_back(rowVector);
    }
    return dataFrame;
}
