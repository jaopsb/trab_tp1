#ifndef USUARIO_H
#define USUARIO_H
#include <string>

using namespace std;

class Usuario
{
    public:
        Usuario(string,string ,string);
        Usuario(string,string);
        Usuario();
        virtual ~Usuario();
        //metodos set
        bool set_identificador(int );
        bool set_login(string);
        bool set_senha(string );
        bool set_nome(string );

        //metodos get
        int get_identificador();
        string get_nome();
        string get_login();

        bool valida_senha(string );

        string greeting();
        string get_senha();//nao eh bom,mas como eh apenas didatico pode
        bool empty();
    protected:
    private:
        string nome;
        string login;
        int identificador;
        string senha;
};

#endif // USUARIO_H
