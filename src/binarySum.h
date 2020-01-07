#ifndef BINARYSUM_H
#define BINARYSUM_H

class BS {
  public:
    BS(int _e) :
      e(_e) {};

    BS operator+(const BS& bs) const {
      return dec() + bs.dec();
    }

    double dec() const {
      return (b * std::pow(2, e));
    }

  private:
    int e = 0;
    short b = 1;
};

#endif // !BINARYSUM_H
