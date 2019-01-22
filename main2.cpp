// #include "pch.h"
#include <iostream>

class Money
{

  public:
    Money() {}

    Money(int rubles, int cents)
        : m_rubles(rubles), m_cents(cents)
        {};

    void display() // сигнатура функции
    {
        std::cout << m_rubles << "," << m_cents << "";
    }
    
    void add(Money *amountToAdd)
    {
        // this.cents += amountToAdd.cents;
        // this.rubles += amountToAdd.rubles;
    }

    private:
      int m_rubles{ 0 };
      int m_cents{ 0 };
    //   const char *fractionalPartDelimeter = ",";
};

int main()
{
    Money money1;
    money1.display();
    // money1.display();
}