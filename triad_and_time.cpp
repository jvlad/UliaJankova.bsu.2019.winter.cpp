// #include "pch.h"
#include <iostream>
#include <utility>

using namespace std::rel_ops;

/*  
"#define" – то, как объявляется Macro

Macro – кусочек кода который будет подставляться в каждое место в программе,
где ты напишешь GEN_SET_AND_GET(some_variable)

Т. е. там где написано, к примеру,
GEN_SET_AND_GET(first)

эта строчка во время компиляции (т. e. перед выполнением) превратиться в  
int get_##first() const { return first; }
void set_##first(const int x) { first = x; }

Эти две – это 2 метода (функции) 
    * первая – get_##first() – возвращает значение first
    * вторая – set_##first(const int x) – устанавливает значение first

Таким образом строчка  
GEN_SET_AND_GET(second)

генерирует аналогичные 2 функции, но уже для переменной second

Такие 2 функции являются примером того, что называется "инкапсуляцией". 
Могу устно тебе расскзать потом, что это за концепция такая
*/
#define GEN_SET_AND_GET(PROP)               \
    int get_##PROP() const { return PROP; } \
    void set_##PROP(const int x) { PROP = x; }

class TRIAD
{
    int first;
    int second;
    int third;

  public:
    TRIAD(const int x, const int y, const int z) : first(x), second(y), third(z) {}
    GEN_SET_AND_GET(first)
    GEN_SET_AND_GET(second)
    GEN_SET_AND_GET(third)

    friend bool operator < (const TRIAD &lhs, const TRIAD &rhs)
    {
        // lexicagraphical compare
        return lhs.get_first() == rhs.get_first()
        //std::tie(lhs.first, lhs.second, lhs.third) < std::tie(rhs.first, rhs.second, rhs.third)
                   ? (
                         lhs.get_second() == rhs.get_second()
                             ? lhs.get_third() < rhs.get_third()
                             : lhs.get_second() < rhs.get_second())
                   : lhs.get_first() < rhs.get_first();
    }

    friend bool operator == (const TRIAD &lhs, const TRIAD &rhs)
    {
        return !(lhs < rhs || rhs < lhs);
    }

    friend bool operator > (const TRIAD &lhs, const TRIAD &rhs)
    {
        return rhs < lhs;
    }
};

class TIME : public TRIAD
{
  public:
    using TRIAD::TRIAD;
};

std::ostream &operator<<(std::ostream &out, const TIME &t)
{
    return out << t.get_first() << ':' << t.get_second() << ':' << t.get_third();
}

int main()
{
    TIME t1(1, 2, 3), t2(1, 42, 3);
    std::cout << t1 << std::endl;
    t1.set_second(42);
    std::cout << t1 << std::endl
              << std::boolalpha << (t1 > t2) << std::endl
              << (t1 != t2) << std::endl
              << (t1 <= t2);
}
