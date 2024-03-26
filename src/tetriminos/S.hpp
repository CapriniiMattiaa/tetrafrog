#include "../Tetrimino.hpp"

class S : public Tetrimino {
 public:
  S() {
    this->id = 4;
  }
  void build();
};