#include "../Tetrimino.hpp"

class O : public Tetrimino {
 public:
  O() {
    this->id = 3;
  }
  void build();
};