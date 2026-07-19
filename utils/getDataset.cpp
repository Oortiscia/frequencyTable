#include "getDataset.hpp"

#include <iostream>
#include <sstream>
#include <string>

std::vector<double> get_dataset() {
  std::cout << "Enter the population values separated by spaces:\n> ";

  std::string line;
  std::getline(std::cin, line);

  std::vector<double> dataset;
  std::istringstream iss(line);

  double value;
  while (iss >> value)
    dataset.push_back(value);

  return dataset;
}
