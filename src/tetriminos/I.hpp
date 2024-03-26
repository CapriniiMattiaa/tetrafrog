#include "../Tetrimino.hpp"

class I : public Tetrimino {
 public:
  void build();
  I() {
    this->id = 0;
  }
};