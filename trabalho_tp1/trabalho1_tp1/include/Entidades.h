#ifndef ENTIDADES_H
#define ENTIDADES_H
#include <dominios.h>

class Usuario {
 public:
  void set_nome(string);
  string get_nome() { return nome.get_nome(); };

  void set_identificador(string);
  string get_identificador() { return identificador.get_identificador(); };

  void set_senha(string);
  string get_senha() { return senha.get_senha(); };
 private:
  Nome nome;
  Identificador identificador; //PK
  Senha senha;
};

class Acomodacao {
 public:
  void set_capacidade(int);
  int get_capacidade() { return capacidade.get_capacidade_acomodacao(); };

  void set_cidade(string);
  string get_cidade() { return cidade.get_nome(); };

  void set_data_inicio(string);
  string get_data_inicio() { return data_de_inicio.get_data(); };

  void set_data_termino(string);
  string get_data_termino() { return data_de_termino.get_data(); };

  void set_diaria(float);
  float get_diaria() { return diaria.get_diaria(); };

  void set_estado(string);
  string get_estado() { return estado.get_estado(); };

  void set_identificador(string);
  string get_identificador() { return identificador.get_identificador(); };

  void set_tipo(int);
  int get_tipo() { return tipo.get_tipo_acomodacao(); };
 private:
  Identificador identificador;
  Tipo_Acomodacao tipo;
  Capacidade_Acomodacao capacidade;
  Data data_de_inicio;
  Data data_de_termino;
  Nome cidade;
  Estado estado;
  Diaria diaria;
};

class Cartao_de_Credito {
 public:
  void set_numero(string);
  string get_numero() { return numero.get_numero_cartao(); };

  void set_data_validade(string);
  string get_data_validade() { return data_validade.get_data_validade(); }
 private:
  Numero_Cartao numero;
  Data_Validade data_validade;
};

class Conta_corrente {
 public:
  void set_agencia(int);
  int get_agencia() { return agencia.get_agencia(); };

  void set_banco(int);
  int get_banco() { return banco.get_banco(); };

  void set_numero(string);
  string get_numero() { return numero.get_numero_conta_corrente(); };
 private:
  Numero_Conta_Corrente numero;
  Agencia agencia;
  Banco banco;
};

#endif // ENTIDADES_H
