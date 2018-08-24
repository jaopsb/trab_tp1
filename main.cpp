#include <iostream>
#include "Usuario.h"
#include "Data.h"
#include "Banco_hotel.h"

using namespace std;

bool valida_senha(string s)
{
    int maiuscula = 0;
    int numero = 0;
    int i = 0;
    bool resultado;

    if (!(s.length() >= 8))
        throw "A senha deve conter pelo menos 8 caracteres!";

    while (s[i])
    {
        if (isalpha(s[i]))
        {
            if (int(s[i]) >=65 && int(s[i]) <= 90 )
            {
                //existe maiuscula
                maiuscula++;
            }
        }else
        {
        numero++;
        }
        i++;
    }
    //retorna um booleano com a soma das maiusculas e numeros dentro da senha
    resultado = maiuscula + numero > 0;

    //fazendo valida��es de haver um n�mero ou maiuscula
    if (maiuscula != 0 && numero == 0){
        throw "A senha deve conter pelo menos 1 numero!";
    }
    if (maiuscula == 0 && numero != 0){
        throw "A senha deve conter pelo menos uma letra maiuscula!";
    }
    if( maiuscula == 0  && numero == 0){
        throw "A senha deve conter pelo menos uma letra maiuscula e um numero!";
    }
    return resultado;
}

int main()
{
    try
    {
        Banco_hotel banco("hotel.db");

    }catch(char *msg)
    {
        cout << msg;
    }

    return 0;
}
