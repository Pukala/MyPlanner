#include "RpnCalculator.hpp"

static std::map<std::string, double (*)(double, double)> ops{
    {"+", [](double a, double b) { return a + b; }},
    {"-", [](double a, double b) { return a - b; }},
    {"*", [](double a, double b) { return a * b; }},
    {"/", [](double a, double b) { return a / b; }}};

const bool isNotOperator(const char ch)
{
    return (ch != '+' and ch != '-' and ch != '*' and ch != '\\');
}

double RpnCalculator::compute(const std::string &operation)
{
    std::string tmp{};
    double val{};

    for (auto i = 0; i < operation.size(); i++)
    {
        if (operation[i] == ' ')
        {
            continue;
        }

        tmp = operation[i];
        std::stringstream ss{};
        ss.str(tmp);

        if (ss >> val)
        {
            valStack.push(val);
        }
        else
        {
            computeWhenIsOperator(tmp);
        }
    }
    return valStack.top();
}

double RpnCalculator::popStack()
{
    const auto r{valStack.top()};
    valStack.pop();
    return r;
}

void RpnCalculator::computeWhenIsOperator(std::string opr)
{
    const auto r{popStack()};
    const auto l{popStack()};

    const auto &op(ops.at(opr));
    const double result{op(l, r)};
    valStack.push(result);
}
