#include "Usuario.h"
#include <locale>
#include <stdlib.h>
#include <iostream>
#include <string>

using namespace std;

Usuario::Usuario(string n, int id, string s)
{
    if(Usuario::set_identificador(id) && Usuario::set_nome(n))
    {
        if(Usuario::valida_senha(s))
        {
            Usuario::set_senha(s);
        }
    }
}

Usuario::~Usuario()
{
    //dtor
}

bool Usuario::set_senha(string s) throw()
{
    bool resultado = false;

    if(!s.empty())
    {
        senha = s;
        resultado = true;
    }else
    {
        throw "senha nao setada";
    }

    return resultado;
}

bool Usuario::set_identificador(int id)
{
    bool resultado;

    if (id != 0 )
    {
        identificador = id;
        resultado = true;
    }else
    {
        resultado = false;
    }

        return resultado;
}

bool Usuario::set_nome(string n)
{
    bool resultado;

    if (!n.empty()){
        nome = n;
        resultado = true;
    }else
    {
        resultado = false;
    }

    return resultado;
}
/** Usuario::valida_senha()
    @param string s
    @author joaop

    M�todo que valdia a consistecia de uma senha, utilizando as regras:
    1- deve conter letras e numeros;
    2- deve conter pelo menos uma letra maiuscula;
    2- deve ter pelo menos 8 caracteres;
*/
bool Usuario::valida_senha(string s)
{
    int maiuscula,numero;
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
    if (maiuscula != 0 && numero == 0)
        throw "Senha deve conter pelo menos 1 numero!";
    if (maiuscula == 0 && numero != 0)
        throw "Senha deve conter pelo menos uma letra maiuscula!";

    return resultado;
}

string Usuario::greeting()
{
    string resultado = "Meu nome: ";
    resultado += nome;
    resultado += ", id:";
    resultado += to_string(identificador);
    resultado += ", senha: ";
    resultado += senha;

   return resultado;
}
