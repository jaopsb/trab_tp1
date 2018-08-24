#ifndef ACOMODACAO_H
#define ACOMODACAO_H
#include "Data.h"
#include <string>

class Acomodacao
{
    public:
        Acomodacao();
        virtual ~Acomodacao();

        void set_identificador(int);
        void set_tipo(int);
        void set_capacidade(int);
        void set_data_inicio(Data);
        void set_data_termino(Data);
        void set_estado(string);
        void set_diaria(float);

        int get_identificador();
        int get_tipo();
        int get_capacidade();


    protected:

    private:
        int identificador;
        int tipo; //TODO: enum
        int capacidade;
        Data data_inicio;
        Data data_termino;
        string estado; //TODO: enum
        float diaria;
};

#endif // ACOMODACAO_H
