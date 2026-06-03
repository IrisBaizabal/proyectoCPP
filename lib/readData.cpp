#include "readData.h"

readData::readData()
{
}

readData::~readData()
{
}

void readData::readFile(const std::string& filePath)
{
    std::ifstream file(filePath);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filePath);
    }

    // Read the file content here
    // For example, you can read line by line:
    std::string line;
    while (std::getline(file, line)) {
        // Process the line as needed
        // For example, you can print it:
        std::cout << line << std::endl;
    }

    file.close();
}