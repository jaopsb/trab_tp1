#ifndef DOMINIOS_H
#define DOMINIOS_H


class Agencia
{
    public:
        dominios();
        virtual ~dominios();

    private:
        int valor;

        void validar(int) throw {invalid_argument};
};

#endif // DOMINIOS_H
