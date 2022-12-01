#include <iostream>
#include <string>
#include <vector>
#include "dataframe.h"
#include "filenames.h"

int main() {
    DataFrames df;
    df = read_csv(filePath2);
    std::cout << std::stod(df.get_value("Value", "Reference Temperature", "string"));

    return 0;
}
