#include <iostream>
#include <string>
#include <vector>
#include "dataframe.h"
#include "filenames.h"

int main() {
    DataFrame dataFrame;
    dataFrame = read_csv(filePath);

    dataFrame.display_dataframes();

    std::vector<std::string> df_col = dataFrame.get_col("col2");

//    std::cout << std::stod(df_col[1]) << std::endl;

    return 0;
}
