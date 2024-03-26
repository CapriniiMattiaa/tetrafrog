#include "../Tetrimino.hpp"

class Z : public Tetrimino {
 public:
  Z() {
    this->id = 6;
  }
  void build();
};