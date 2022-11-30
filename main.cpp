#include <iostream>
#include <string>
#include <vector>
#include "dataframe.h"
#include "filenames.h"

int main() {
    DataFrames df;
    df = read_csv(filePath2);
    std::vector<double> df_col = df.get_col_to_double("Value");

    std::cout << df_col[3] << std::endl;

    std::cout << df.get_index()[2] << std::endl;

    df.display_dataframes();

    return 0;
}
