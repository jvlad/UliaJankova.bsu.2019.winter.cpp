#include <iostream>

/*
Создать класс Money для работы с денежными суммами. Число должно быть представлено двумя
полями: типа int для рублей и типа char для копеек. Дробная часть (копейки) при выводе на
экран должна быть отделена от целой части запятой. Перегрузить операции 
    * для сложения,
    * вычитания 
    * и операции сравнения 
        1. == 
        2. <
*/

class Money
{

  public:
    Money()
        : m_rubles(0), m_cents(0)
    {
    }

    Money(int rubles, int cents)
        : m_rubles(rubles)
    {
        m_cents = cents % 100;
        m_rubles += cents / 100;
    }

    void display() // сигнатура функции
    {
        std::cout << m_rubles << "," << m_cents << "";
    }

    void add(const Money &amountToAdd)
    {
        int centsTotal = m_cents + amountToAdd.m_cents;
        m_cents = centsTotal % 100;
        m_rubles += amountToAdd.m_rubles + centsTotal / 100;
    }

  private:
    int m_rubles;
    int m_cents;
};

void printSeparator() {
    std::cout << "=================================================";
}

int main()
{
    Money money1;
    money1.display();
    printSeparator();
    money1.add(Money(1, 230));
    money1.display();
}