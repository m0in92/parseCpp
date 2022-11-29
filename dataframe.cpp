//
// Created by moina on 11/28/2022.
//

#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "dataframe.h"


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
        }
        indexTemp.push_back(std::to_string(index));
        index++;
    }
    DataFrame dataFrame;
    dataFrame.set_index(indexTemp);
    dataFrame.set_colname(colNameTemp);
    dataFrame.set_data(dataFrameTemp);
    return dataFrame;
}
