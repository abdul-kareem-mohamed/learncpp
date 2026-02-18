#include <iostream>

class Fraction
{
    private:
        double m_numerator{ 0 };
        double m_denominator{ 1 };
    public:
        explicit Fraction(double numerator=0.0, double denominator = 0.0) 
        : m_numerator {numerator}
        , m_denominator {denominator}
        {
        }
        
        void setFraction()
        {
            std::cout << "Enter a value for numerator: ";
            std::cin >> m_numerator;
            std::cout << "Enter a value for denominator: ";
            std::cin >> m_denominator;
            std::cout << '\n';
        }
        Fraction multiply(Fraction f2)
        {
            return Fraction { m_numerator * f2.m_numerator, m_denominator * f2.m_denominator };
        }
        double getNumerator() const
        {
            return m_numerator;
        }
        double getDenominator() const
        {
            return m_denominator;
        }


};


void printFraction(const Fraction& f)
{
    std::cout << f.getNumerator() << '/' << f.getDenominator() << '\n';
}

int main()
{
    Fraction f1{};
    f1.setFraction();

    Fraction f2{};
    f2.setFraction();

    std::cout << "Your fractions multiplied together: ";

    printFraction(f1.multiply(f2));

    return 0;
}
