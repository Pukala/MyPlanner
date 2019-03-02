#include <stack>
#include <map>
#include <sstream>
#include <vector>
#include <cmath>

class RpnCalculator
{
  public:
    RpnCalculator() = default;

    double compute(const std::string &operation);

  private:
    double popStack();

    void computeWhenIsOperator(std::string opr);

    std::stack<double> valStack;
};