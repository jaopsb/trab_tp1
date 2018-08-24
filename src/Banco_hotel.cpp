#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <sqlite3.h>
#include "Banco_hotel.h"
#include "Usuario.h"
#include "Acomodacao.h"

using namespace std;

//instrucoes para criacao de tabelas do banco
char *SQL_STMT_CREATE_USUARIO = "CREATE TABLE IF NOT EXISTS 'USUARIO' ( `ID` INTEGER PRIMARY KEY AUTOINCREMENT, `NOME` TEXT NOT NULL, `SENHA` TEXT NOT NULL ); ";
char *SQL_STMT_CREATE_ACOMODACAO = "CREATE TABLE IF NOT EXISTS `ACOMODACAO` ( `id` INTEGER PRIMARY KEY AUTOINCREMENT, `tipo` INTEGER NOT NULL, `capacidade` INTEGER NOT NULL, `cidade` TEXT NOT NULL, `estado` INTEGER NOT NULL, `diaria` REAL NOT NULL );";
char *SQL_STMT_CREATE_CARTAO = "CREATE TABLE IF NOT EXISTS 'CARTAO' ( `ID` INTEGER PRIMARY KEY AUTOINCREMENT,`NUMERO` TEXT NOT NULL, `DT_VALIDADE` TEXT NOT NULL, `ID_USUARIO` INTEGER NOT NULL );";
char *SQL_STMT_CREATE_CONTACORRENTE = "CREATE TABLE IF NOT EXISTS 'CONTACORRENTE' ( `ID` INTEGER PRIMARY KEY AUTOINCREMENT, `NUMERO` TEXT NOT NULL, `AGENDA` INTEGER NOT NULL, `BANCO` INTEGER NOT NULL, `ID_USUARIO` INTEGER NOT NULL );";
char *SQL_STMT_CREATE_RESERVA = "CREATE TABLE IF NOT EXISTS `RESERVA` ( `id` INTEGER PRIMARY KEY AUTOINCREMENT, `id_usuario` INTEGER NOT NULL, `id_acomodacao` INTEGER NOT NULL, `data_incio` TEXT NOT NULL, `data_fim` TEXT NOT NULL );";

static int callback(void *NotUsed, int argc, char **argv, char **azColName)
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
    }
    printf("\n");
    return 0;
}

Banco_hotel::Banco_hotel(char* nome_bd)
{
/*
    //implementando padrao singleton
    if(instancia > 0)
    {
        throw "Erro, apenas um banco deve estar rodando!";
    }else
    {
        instancia++;
    }
*/
    char *errmsg;
    vector<char *> sql;

    sql.push_back(SQL_STMT_CREATE_USUARIO);
    sql.push_back(SQL_STMT_CREATE_ACOMODACAO);
    sql.push_back(SQL_STMT_CREATE_CARTAO);
    sql.push_back(SQL_STMT_CREATE_CONTACORRENTE);
    sql.push_back(SQL_STMT_CREATE_RESERVA);

    //inicia o banco
    if(sqlite3_open(NOME_BD, &bd) != 0) throw "Erro ao Abrir banco";

    try
    {
        for (int i = 0; i < sql.size(); i++)
        {
            if (sqlite3_exec(bd, sql.at(i), callback, 0, &errmsg) > 0)
                throw errmsg;
        }
    }
    catch (char *msg)
    {
        throw msg;
        sqlite3_free(msg);
    }

    sqlite3_free(errmsg);
    sqlite3_close(bd);
}

/*
    Funcao de cadastro de usuarios
        Funcao que recebe um objeto de usuario, e insere no banco;
*/
bool Banco_hotel::cadastra_usuario(Usuario usu)
{
    char *errmsg;

    string SQL_STMT_INSERT_USUARIO = "INSERT INTO USUARIO (nome,senha) VALUES (";

    int rc = sqlite3_open(NOME_BD, &bd);

    SQL_STMT_INSERT_USUARIO += "'" + usu.get_nome() + "'";
    SQL_STMT_INSERT_USUARIO += ',';
    SQL_STMT_INSERT_USUARIO += "'" + usu.get_senha() + "');";

    rc = sqlite3_exec(bd,SQL_STMT_INSERT_USUARIO.c_str(),callback,0,&errmsg);

    if(rc) throw errmsg;

    sqlite3_free(errmsg);
    sqlite3_close(bd);

    return rc == 0;
}

bool Banco_hotel::buscar_usuario(Usuario* u, string nome_in,string senha_in)
{

    sqlite3* bd;
    char* errmsg;

    return false;
}

Banco_hotel::~Banco_hotel()
{

}
