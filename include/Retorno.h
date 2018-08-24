#ifndef RETORNO_H
#define RETORNO_H
#include <string>
#include<stdio.h>

using namespace std;

class Retorno
{
    public:
        Retorno(bool,string);
        Retorno();
        virtual ~Retorno();

        string get_mensagem();
        bool get_resultado();

    protected:

    private:
        bool resultado;
        string msg;
};

#endif // RETORNO_H
