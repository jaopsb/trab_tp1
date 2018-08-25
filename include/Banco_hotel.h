#ifndef BANCO_HOTEL_H
#define BANCO_HOTEL_H
#include <string>
#include "Data.h"
#include "sqlite3.h"
#include "Usuario.h"
#include "Acomodacao.h"

class Banco_hotel
{
    public:
        Banco_hotel(char*);
        virtual ~Banco_hotel();

        bool cadastra_usuario(Usuario);
        void cadastra_acomodacao(Acomodacao);
        void cadastra_contacorrente(string,int,int);
        void cadastra_cartao(string,Data);

        Usuario buscar_usuario(string,string);
    protected:

    private:
        int instancia;
        sqlite3* bd;
        char* NOME_BD = "hotel.db";
};

#endif // BANCO_HOTEL_H
