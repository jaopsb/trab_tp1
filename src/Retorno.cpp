#include "Retorno.h"
#include <string>

Retorno::Retorno(bool r, string m)
{
    resultado = r;
    msg = m;
}

Retorno::Retorno(){msg = " "; resultado = true;}

string Retorno::get_mensagem()
{
    return msg;
}

bool Retorno::get_resultado()
{
    return resultado;
}

Retorno::~Retorno(){
}
