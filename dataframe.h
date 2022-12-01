//
// Created by moina on 11/28/2022.
//

#ifndef CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H
#define CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H

#include <vector>
#include <string>

class DataFrames{
public:
    // Accessor Functions
    std::vector<std::string> get_indexname() {return index;}
    std::vector<std::string> get_colname() {return colName;}
    std::vector<std::vector<std::string>> get_data() {return data;}
    int get_col_index(std::string);
    int get_index_index(std::string);
    DataFrames get_col(std::string);
    std::string get_value(const std::string inputColName, const std::string inputIndexName, const std::string dataType);
    std::vector<double> get_col_to_double(std::string);
    // Modifier Functions
    void set_index(std::vector<std::string> inputIndex) {index = inputIndex;}
    void set_colname(std::vector<std::string> inputColName) {colName = inputColName;}
    void set_data(std::vector<std::vector<std::string>> inputData) {data = inputData;}
    void transpose();
    // Display functions
    void display_index();
    void display_colnames();
    void display_data();
    void display_dataframes();
private:
    std::vector<std::string> index;
    std::vector<std::string> colName;
    std::vector<std::vector<std::string>> data;
};

DataFrames read_csv(std::string, int colNameIndex = 0, int indexRow = 0);


#endif //CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H
