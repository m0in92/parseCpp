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


void DataFrames::transpose() {
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

int DataFrames::get_col_index(std::string inputColName) {
    int colIndex = -1;
    for (int i=0; i<colName.size(); i++) {
        if (colName[i].compare(inputColName) == 0) {
            colIndex = i;
        }
    }
    if (colIndex == -1)
        throw std::invalid_argument("Invalid column name.");
    return colIndex;
}

int DataFrames::get_index_index(std::string inputIndexName) {
    int rowIndex = -1;
    for (int i=0; i< index.size(); i++) {
        if (index[i].compare(inputIndexName) == 0) {
            rowIndex = i;
        }
    }
    if (rowIndex == -1)
        throw std::invalid_argument("Invalid index name.");
    return rowIndex;
}

DataFrames DataFrames::get_col(std::string inputColName) {
    try{
        int colIndex = DataFrames::get_col_index(inputColName);
        std::vector<std::vector<std::string>> rowTemp;
//        std::vector<std::string> colTemp;
        for (int i=0; i<data.size(); i++) {
            std::vector<std::string> colTemp;
            colTemp.push_back(data[i][colIndex]);
            rowTemp.push_back(colTemp);
        }
        DataFrames dfTemp;
        dfTemp.set_data(rowTemp);
        dfTemp.set_index(index);
        std::vector<std::string> colNameTemp;
        colNameTemp.push_back(inputColName);
        dfTemp.set_colname(colNameTemp);
        return dfTemp;
    }
    catch (const std::invalid_argument& e) {
        std::cout << "invalid column name." << std::endl;
    }
}

std::string DataFrames::get_value(const std::string inputcolName, const std::string inputIndexName, const std::string dataType) {
    DataFrames df = DataFrames::get_col(inputcolName);
    int indexIndex = DataFrames::get_index_index(inputIndexName);
    const int colIndex = 0;
    return df.get_data()[indexIndex][colIndex];
}

//std::vector<double> DataFrames::get_col_to_double(std::string inputColName) {
//    const std::vector<std::string> tempColinString = DataFrames::get_col(inputColName);
//    std::vector<double> doubleVector(tempColinString.size());
//    std::transform(tempColinString.begin(), tempColinString.end(), doubleVector.begin(), [](const std::string& val) {
//        return std::stod(val);
//    });
//    return doubleVector;
//}

void DataFrames::display_colnames() {
    std::cout << " "; // initial delimiters
    for(int i=0; i<colName.size(); i++){
        std::cout << colName[i] << " ";
    }
    std::cout << std::endl;
}

void DataFrames::display_dataframes() {
    // Header
    DataFrames::display_colnames();
    for (int rowIndex=0; rowIndex<data.size(); rowIndex++){
        // on a single line.
        std::cout << index[rowIndex] << " ";
        for (int colIndex=0; colIndex< data[rowIndex].size(); colIndex++){
            std::cout << data[rowIndex][colIndex] << " ";
        }
        std::cout << std::endl;
    }
}

DataFrames read_csv(std::string filePath, int colNameIndex, int indexRow) {
    /*
     * This function opens and reads the csv file.
     * */
    // open csv file
    std::ifstream inputFile;
    inputFile.open(filePath);

    // initialize the dataframe and line
    std::string line = "";
    std::vector<std::vector<std::string>> dataFrameTemp;
    std::vector<std::string> colNameTemp;
    std::vector<std::string> indexTemp;

    int index = 0;
    while (std::getline(inputFile, line)) {
        // initialize row entry (single entry within a row, rowInput(entire row), and rowVector (vector containing all
        // row entries.)
        std::string  rowEntry = "";
        std::stringstream rowInput(line);
        std::vector<std::string> rowVector;
        int colIndex = 0;
        while (std::getline(rowInput, rowEntry, ',')) {
            if (colIndex == indexRow){
                if (index > 0)
                    indexTemp.push_back(rowEntry);
            }
            else
                rowVector.push_back(rowEntry);
            colIndex++;
        }
        if (index==colNameIndex) {
            colNameTemp = rowVector; // add colname
        }
        else {
            dataFrameTemp.push_back(rowVector); // add rowVector to the dataframe vector.
//            indexTemp.push_back(std::to_string(index-1));
        }
        index++;
        line = "";
    }
    DataFrames dataFrame;
    dataFrame.set_index(indexTemp);
    dataFrame.set_colname(colNameTemp);
    dataFrame.set_data(dataFrameTemp);
    return dataFrame;
}
