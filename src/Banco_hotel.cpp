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
char* SQL_STMT_USUARIO = "CREATE TABLE IF NOT EXISTS 'USUARIO' ( `ID` INTEGER PRIMARY KEY AUTOINCREMENT, `NOME` TEXT NOT NULL, `SENHA` TEXT NOT NULL ); ";
char* SQL_STMT_ACOMODACAO = "CREATE TABLE IF NOT EXISTS `ACOMODACAO` ( `id` INTEGER PRIMARY KEY AUTOINCREMENT, `tipo` INTEGER NOT NULL, `capacidade` INTEGER NOT NULL, `cidade` TEXT NOT NULL, `estado` INTEGER NOT NULL, `diaria` REAL NOT NULL );";
char* SQL_STMT_CARTAO = "CREATE TABLE IF NOT EXISTS 'CARTAO' ( `ID` INTEGER PRIMARY KEY AUTOINCREMENT,`NUMERO` TEXT NOT NULL, `DT_VALIDADE` TEXT NOT NULL, `ID_USUARIO` INTEGER NOT NULL );";
char* SQL_STMT_CONTACORRENTE = "CREATE TABLE IF NOT EXISTS 'CONTACORRENTE' ( `ID` INTEGER PRIMARY KEY AUTOINCREMENT, `NUMERO` TEXT NOT NULL, `AGENDA` INTEGER NOT NULL, `BANCO` INTEGER NOT NULL, `ID_USUARIO` INTEGER NOT NULL );";
char* SQL_STMT_RESERVA = "CREATE TABLE IF NOT EXISTS `RESERVA` ( `id` INTEGER PRIMARY KEY AUTOINCREMENT, `id_usuario` INTEGER NOT NULL, `id_acomodacao` INTEGER NOT NULL, `data_incio` TEXT NOT NULL, `data_fim` TEXT NOT NULL );";

static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
   for(int i = 0; i<argc; i++) {
      printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
   }
   printf("\n");
   return 0;
}

Banco_hotel::Banco_hotel(char* nome_bd)
{
    sqlite3 *db;
    char *errmsg;
    vector<char*> sql;

    sql.push_back(SQL_STMT_USUARIO);
    sql.push_back(SQL_STMT_ACOMODACAO);
    sql.push_back(SQL_STMT_CARTAO);
    sql.push_back(SQL_STMT_CONTACORRENTE);
    sql.push_back(SQL_STMT_RESERVA);

    //inicia o banco
    int rc = sqlite3_open(nome_bd,&db);

    try
    {

        for(int i = 0; i < sql.size(); i++)
        {
            if(sqlite3_exec(db,sql.at(i),callback,0 ,&errmsg) > 0) throw errmsg;
        }

    }catch(char *msg)
    {
        throw msg;
        sqlite3_free(msg);
    }

    sqlite3_free(errmsg);
    sqlite3_close(db);
}

Banco_hotel::~Banco_hotel()
{
    //dtor
}

Banco_hotel::cadastra_usuario(Usuario usu)
{
    //TODO: Criar funcao
}

