#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario
{
    public:
        Usuario(string,int ,string);
        Usuario(string,string);
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
        string get_senha();//nao eh bom,mas como eh apenas didatico pode
    protected:
    private:
        string nome;
        int identificador;
        string senha;
};

#endif // USUARIO_H
