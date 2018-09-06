#include <iostream>
#include <Testes.h>

using namespace std;

int main()
{

  Testes teste;

  if (teste.rodar_testes()) {

    cout << "Testes executados com sucesso" << endl;

  } else {

    cout << "Erro nos testes" << endl;
  }

  return 0;
}
