#include "pch.h"
#include <conio.h>
#include <iostream>

struct Money
{
  long roubles;
  int copecks;
  double wholeSum;
};

void saveNewAmount(Money* arg)
{
  arg->roubles = (int)arg->wholeSum;
  arg->copecks = (int)((arg->wholeSum - (int)arg->wholeSum) * 100);
}

void Read(Money* arg)
{
  std::cout << "vvedite chislo ";
  std::cin >> arg->wholeSum;
  saveNewAmount(arg);
}

void Display(Money* arg)
{

  std::cout << arg->roubles << ",";
  if (arg->copecks < 0)
  {
    std::cout << "-";
  }
  std::cout << arg->copecks;  _getch();

}

Money* Sum()
{
  Money* arg1 = new Money;
  Money* arg2 = new Money;
  Read(arg1); Read(arg2);
  Money* temp = new Money;
  temp->wholeSum = arg1->wholeSum + arg2->wholeSum;
  saveNewAmount(temp);
  return temp;
}

Money* Razn()
{
  Money* arg1 = new Money;
  Money* arg2 = new Money;
  Read(arg1); Read(arg2);
  Money* temp = new Money;
  temp->wholeSum = arg1->wholeSum - arg2->wholeSum;
  saveNewAmount(temp);
  return temp;
}

void Sravnenie()
{
  Money* arg1 = new Money;
  Money* arg2 = new Money;
  Read(arg1); Read(arg2);
  if (arg1->wholeSum == arg2->wholeSum) {
    std::cout << "chisla ravni"; _getch();
  }
  else if (arg1->wholeSum > arg2->wholeSum) {
    std::cout << "Pervoe chislo bolshe"; _getch();
  }
  else {
    std::cout << "Vtoroe chislo bolshe"; _getch();

  }
}

int menu()
{
  system("cls");
  std::cout << "\n\n\n\tMenu";
  std::cout << "\n------------------------";
  std::cout << "\n  1. Summa";
  std::cout << "\n  2. Raznost'";
  std::cout << "\n  3. Sravnenie";
  std::cout << "\n  4. Vihod";
  std::cout << "\n-------------------------";
  std::cout << "\n\tYour choice(1-4)";
  int w;
  std::cin >> w;
  return w;
}

int main(int argc, char* argv[])
{
  int s;
  do {
    s = menu();
    switch (s) {
    case 1: Display(Sum()); break;
    case 2:Display(Razn()); break;
    case 3:Sravnenie(); break;
    case 4: break;
    }
  } while (s != 4);
  _getch();
  return 0;
}