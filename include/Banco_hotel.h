#ifndef BANCO_HOTEL_H
#define BANCO_HOTEL_H
#include <string>
#include "Data.h"
#include "Usuario.h"
#include "Acomodacao.h"

class Banco_hotel
{
    public:
        Banco_hotel(char *);
        virtual ~Banco_hotel();

        void cadastra_usuario(Usuario);
        void cadastra_acomodacao(Acomodacao);
        void cadastra_contacorrente(string,int,int);
        void cadastra_cartao(string,Data);

    protected:

    private:
};

#endif // BANCO_HOTEL_H
