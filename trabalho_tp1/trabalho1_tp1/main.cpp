#include <iostream>
#include <Testes.h>

using namespace std;

int main()
{

  Testes teste;

  if (teste.rodar_testes()) {

    cout << "ok" << endl;

  } else {

    cout << "nao ok" << endl;
  }

  return 0;
}
