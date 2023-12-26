#include "J.hpp"

void J::build() {
  this->grid[0][1] = 1;
  this->grid[1][1] = 1;
  this->grid[2][1] = 1;
  this->grid[2][0] = 1;
}