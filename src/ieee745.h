#ifndef IEEE745
#define IEEE745

struct ieee745 {
  private:
    int n = 3;

  public:
    int signal = 0;
    int expoent = 0;
    long matissa = 0;

    bool check() {
      return matissa >= 1 && matissa < 2;
    }

    double value() {
      return std::pow(-1, signal) * matissa * std::pow(2, expoent);
    }

    double valueByBinaryInput() {
      return std::pow(-1, signal) * matissa * std::pow(2, (expoent - (std::pow(2, n-1))) + 1);
    }
};

#endif // !IEEE745