#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario
{
    public:
        Usuario(string,int ,string);
        virtual ~Usuario();
        //metodos set
        bool set_identificador(int );
        bool set_senha(string ) throw();
        bool set_nome(string );

        //metodos get
        int get_identificador();
        string get_nome();

        bool valida_senha(string );

        string greeting();
    protected:

    private:
        string nome;
        int identificador;
        string senha;
};

#endif // USUARIO_H
