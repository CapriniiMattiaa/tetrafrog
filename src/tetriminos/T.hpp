#include "../Tetrimino.hpp"

class T : public Tetrimino {
 public:
  T() {
    this->id = 5;
  }
  void build();
};