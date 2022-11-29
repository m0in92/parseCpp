//
// Created by moina on 11/28/2022.
//

#ifndef CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H
#define CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H

#include <vector>
#include <string>

class DataFrame{
public:
    std::vector<std::vector<std::string>> get_data() {return data;}
    void set_data(std::vector<std::vector<std::string>> inputData) {data = inputData;}
private:
    std::vector<std::vector<std::string>> data;
};

std::vector<std::vector<std::string>> read_csv(std::string, int colNameIndex = 0);

#endif //CSV_DATA_PARSE_EXAMPLE_DATAFRAME_H
