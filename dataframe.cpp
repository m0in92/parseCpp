//
// Created by moina on 11/28/2022.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "dataframe.h"
#include <stdexcept>
#include <algorithm>


void DataFrame::transpose() {
    // Swap index and colname values.
    std::vector<std::string> indexTemp = index;
    index = colName;
    colName = indexTemp;
    // Transpose the data
    const std::vector<std::vector<std::string>> dataTemp = data;
    for (int i=0; i < data.size(); i++) {
        for (int j=0; j < data[i].size(); j++) {
            data[i][j] = dataTemp[j][i];
        }
    }
}

int DataFrame::get_col_index(std::string inputColName) {
    int colIndex = -1;
    for (int i=0; i<colName.size(); i++) {
        if (colName[i].compare(inputColName) == 0) {
            colIndex = i;
        }
    }
    if (colIndex == -1)
        throw std::invalid_argument("Invalid column name.");
}

std::vector<std::string> DataFrame::get_col(std::string inputColName) {
    try{
        int colIndex = DataFrame::get_col_index(inputColName);
        std::vector<std::string> colTemp;
        for (int i=0; i<data.size(); i++) {
            colTemp.push_back(data[i][colIndex]);
        }
        return colTemp;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "invalid column name." << std::endl;
    }
}

std::vector<double> DataFrame::get_col_to_double(std::string inputColName) {
    const std::vector<std::string> tempColinString = DataFrame::get_col(inputColName);
    std::vector<double> doubleVector(tempColinString.size());
    std::transform(tempColinString.begin(), tempColinString.end(), doubleVector.begin(), [](const std::string& val) {
        return std::stod(val);
    });
    return doubleVector;
}

void DataFrame::display_colnames() {
    std::cout << " "; // initial delimiters
    for(int i=0; i<colName.size(); i++){
        std::cout << colName[i] << " ";
    }
    std::cout << std::endl;
}

void DataFrame::display_dataframes() {
    // Header
    DataFrame::display_colnames();
    for (int rowIndex=0; rowIndex<data.size(); rowIndex++){
        // on a single line.
        std::cout << index[rowIndex] << " ";
        for (int colIndex=0; colIndex<data.size(); colIndex++){
            std::cout << data[rowIndex][colIndex] << " ";
        }
        std::cout << std::endl;
    }
}

DataFrame read_csv(std::string filePath, int colNameIndex) {
    /*
     * This function opens and reads the csv file.
     * */
    // open csv file
    std::ifstream inputFile;
    inputFile.open(filePath);

    // initialize the dataframe and line
    std::string line;
    std::vector<std::vector<std::string>> dataFrameTemp;
    std::vector<std::string> colNameTemp;
    std::vector<std::string> indexTemp;

    int index = 0;
    while (std::getline(inputFile, line)) {
        // initialize row entry (single entry within a row, rowInput(entire row), and rowVector (vector containing all
        // row entries.)
        std::string  rowEntry;
        std::stringstream rowInput(line);
        std::vector<std::string> rowVector;
        while (std::getline(rowInput, rowEntry, ',')) {
            rowVector.push_back(rowEntry);
        }
        if (index==colNameIndex) {
            colNameTemp = rowVector; // add colname
        }
        else {
            dataFrameTemp.push_back(rowVector); // add rowVector to the dataframe vector.
            indexTemp.push_back(std::to_string(index-1));
        }
        index++;
    }
    DataFrame dataFrame;
    dataFrame.set_index(indexTemp);
    dataFrame.set_colname(colNameTemp);
    dataFrame.set_data(dataFrameTemp);
    return dataFrame;
}
