#include <iostream>
#include <string>
#include <vector>
#include "dataframe.h"

int main() {
    std::string filePath = "C:\\Users\\moina\\CLionProjects\\csv-data-parse-example\\Book1.csv";
    DataFrame dataFrame;
    dataFrame.set_data(read_csv(filePath));
//    std::vector<std::vector<std::string>> dataFrame = read_csv(filePath);

    // Display dataframe
    for (int i=0; i < dataFrame.get_data().size(); i++) {
        std::vector<std::string> rowVectorForDisplay = dataFrame.get_data()[i];
        for (int j=0; j<rowVectorForDisplay.size(); j++) {
            std::cout << rowVectorForDisplay[j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
