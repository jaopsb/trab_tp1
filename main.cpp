#include <iostream>
#include "Data.h"
#include "Usuario.h"
#include "Retorno.h"
#include "Banco_hotel.h"

using namespace std;

Retorno *valida_senha(string s)
{
    int maiuscula = 0;
    int numero = 0;
    int i = 0;

    if (s.length() < 7)
        return new Retorno(false, "A senha deve conter pelo menos 8 caracteres!");

    while (s[i])
    {
        if (isalpha(s[i]))
        {
            if (int(s[i]) >= 65 && int(s[i]) <= 90)
            {
                //existe maiuscula
                maiuscula++;
            }
        }
        else
        {
            numero++;
        }
        i++;
    }
    //retorna um booleano com a soma das maiusculas e numeros dentro da senha

    //fazendo valida��es de haver um n�mero ou maiuscula
    if (maiuscula != 0 && numero == 0)
        return new Retorno(false, "A senha deve conter pelo menos 1 numero!");

    if (maiuscula == 0 && numero != 0)
        return new Retorno(false, "A senha deve conter pelo menos uma letra maiuscula!");

    if (maiuscula == 0 && numero == 0)
        return new Retorno(false, "A senha deve conter pelo menos uma letra maiuscula e um numero!");

    return new Retorno(maiuscula + numero > 0 , "");
}

void registrar()
{
    Banco_hotel banco(" ");
    string nome_in, senha_in;
    char resp_in;
    Retorno *retorno = new Retorno();

    cout << "Registro:" << endl;
    cout << "Nome:";
    getline(cin, nome_in);

    try
    {
        do{
            cout << "Senha:";
            getline(cin,senha_in);

            retorno = valida_senha(senha_in);

            if (!retorno->get_resultado())
                cout << retorno->get_mensagem() << endl;

        }while (!retorno->get_resultado());
    }
    catch (char *msg)
    {
        cout << msg;
    }

    cout << "Confirmar?" << endl;
    cout << "Nome: " << nome_in << ", Senha: " << senha_in << endl;
    cout << "(S/N)";
    cin >> resp_in;

    if (resp_in == 's' || resp_in == 'S')
    {
        Usuario u(nome_in, senha_in);

        if(banco.cadastra_usuario(u))
            cout << "Cadastro feito com sucesso!" << endl;
    }

    delete retorno;
}

void login(){
    cout << "aaah safado... jaja"<< endl;
    getwchar();
}

int main()
{
    int opt;
    bool fim = false;

    do{

        try
        {
            do{
                cout << "+-----------------------------------+" << endl;
                cout << "|Iniciando Hotel 2.0" << endl;
                cout << "|Escolha uma opcao:" << endl;
                cout << "| 1- Login" << endl;
                cout << "| 2- Registrar" << endl;
                cout << "| 3- Cadastrar Acomocadao (Migrar)" << endl;
                cout << "| 4- sair" << endl;
                cout << "+-----------------------------------+" << endl;

                cin >> opt;
                getwchar();
                if (opt > 0 && opt < 4)
                    fim = true;

            } while (!fim);

            switch (opt)
            {
            case 1:
                login();
            break;
            case 2:
                registrar();
            break;
            }
        }
        catch (char *msg)
        {
            cout << msg;
        }

    }while(opt != 4);
    return 0;
}
