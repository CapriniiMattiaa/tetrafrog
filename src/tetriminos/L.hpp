#include "../Tetrimino.hpp"

class L : public Tetrimino {
 public:
  L() {
    this->id = 2;
  }
  void build();
};