//
// Created by moina on 11/28/2022.
//

#ifndef CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H
#define CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H

#include <vector>
#include <string>

class DataFrame{
public:
    // Accessor Functions
    std::vector<std::string> get_colname() {return colName;}
    std::vector<std::vector<std::string>> get_data() {return data;}
    // Modifier Functions
    void set_colname(std::vector<std::string> inputColName) {colName = inputColName;}
    void set_data(std::vector<std::vector<std::string>> inputData) {data = inputData;}
private:
    std::vector<std::string> colName;
    std::vector<std::vector<std::string>> data;
};

DataFrame read_csv(std::string, int colNameIndex = 0);


#endif //CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H
