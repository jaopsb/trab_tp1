#include <iostream>
#include <Testes.h>
#include <Entidades.h>

using namespace std;

int main() {

  Teste_Agencia t_agencia;
  Teste_Banco t_banco;
  Teste_Capacidade_Acomodacao t_cap_acm;
  Teste_Data t_data;
  Teste_Data_Validade t_data_val;
  Teste_Diaria t_diaria;
  Teste_Estado t_estado;
  Teste_Identificador t_identificador;
  Teste_Nome t_nome;
  Teste_Numero_Cartao t_num_cartao;
  Teste_Numero_Conta_Corrente t_num_cc;
  Teste_Senha t_senha;
  Teste_Tipo_Acomodacao t_tipo_acm;

  t_agencia.rodar_suite();
  t_banco.rodar_suite();  
  t_cap_acm.rodar_suite();
  t_data.rodar_suite();
  t_data_val.rodar_suite();
  t_diaria.rodar_suite();
  t_estado.rodar_suite();
  t_identificador.rodar_suite();
  t_nome.rodar_suite();
  t_num_cartao.rodar_suite();
  t_num_cc.rodar_suite();
  t_senha.rodar_suite();
  t_tipo_acm.rodar_suite();

  return 0;
}
