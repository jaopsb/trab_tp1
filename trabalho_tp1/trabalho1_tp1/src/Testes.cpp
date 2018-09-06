#include "Testes.h"
#include "dominios.h"
#include <stdexcept>
#include <iostream>

using namespace std;

/**\brief rodar_testes().Executa todos os testes criados para cada classe.
 * Nos Dominios, é verificado tanto a inserção de um valor de acordo com a especificação de cada função
 * como também um valor fora da especificação, verificando se há um erro esperado.
 * \param void
 * \return true se todos os testes rodarem corretamente e false se algum der erro
*/
bool Testes::rodar_testes() {

  bool resultado = true;

  try {

    testa_agencia_ok();
    testa_agencia_erro();

    testa_banco_ok();
    testa_banco_erro();

    testa_capacidade_acomodacao_ok();
    testa_capacidade_acomodacao_erro();

    testa_diaria_ok();
    testa_diaria_erro();

    testa_data_ok();
    testa_data_erro();

    testa_data_validade_ok();
    testa_data_validade_erro();

    testa_estado_ok();
    testa_estado_erro();

    testa_identificador_ok();
    testa_identificador_erro();

    testa_nome_ok();
    testa_nome_erro();

    testa_numero_cartao_ok();
    testa_numero_cartao_erro();

    testa_numero_conta_corrente_ok();
    testa_numero_conta_corrente_erro();

    testa_senha_ok();
    testa_senha_erro();

    testa_tipo_acomodacao_ok();
    testa_tipo_acomodacao_erro();

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

/**\briefvalidacao de insercao de um valor que confere com a especificação da classe Agencia 
*/
void Testes::testa_agencia_ok() {
  Agencia agencia;

  agencia.set_agencia(45678);
}

/**\briefValidação da inserção de um valor que nao corresponde a especificação da classe Agencia
*/
void Testes::testa_agencia_erro() throw(invalid_argument){
  bool resultado = false;
  Agencia agencia;

  try {

    agencia.set_agencia(19293847);

  } catch (const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {
    throw invalid_argument("Teste testa_agencia() falhou");
  }
}

void Testes::testa_banco_ok() {
  Banco banco;

  banco.set_banco(260);
}

void Testes::testa_banco_erro() throw(invalid_argument){
  bool resultado = false;
  Banco banco;

  try {

    banco.set_banco(-25948);

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_banco() falhou");

  }
}

void Testes::testa_capacidade_acomodacao_ok() {
  Capacidade_Acomodacao capacidade_acomodacao;

  capacidade_acomodacao.set_capacidade_acomodacao(7);
}

void Testes::testa_capacidade_acomodacao_erro() throw(invalid_argument){
  bool resultado = false;
  Capacidade_Acomodacao capacidade_acomodacao;

  try {

  capacidade_acomodacao.set_capacidade_acomodacao(2323);

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_capacidade_acomodacao() falhou");

  }
}

void Testes::testa_diaria_ok() {
  Diaria diaria;

  diaria.set_diaria(723.44);
}

void Testes::testa_diaria_erro() throw(invalid_argument){
  bool resultado = false;
  Diaria diaria;

  try {

  diaria.set_diaria(10000.001);

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_diaria() falhou");

  }
}

void Testes::testa_data_ok() {
  Data data;

  data.set_data("11/set/2001");
}

void Testes::testa_data_erro() throw(invalid_argument){
  bool resultado = false;
  Data data;

  try {

  data.set_data("34/Jul/32");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_data() falhou");

  }
}

void Testes::testa_data_validade_ok() {
  Data_Validade data_validade;

  data_validade.set_data_validade("12/44");
}

void Testes::testa_data_validade_erro() throw(invalid_argument){
  bool resultado = false;
  Data_Validade data_validade;

  try {

  data_validade.set_data_validade("44/84748");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_data_validade() falhou");

  }
}

void Testes::testa_estado_ok() {
  Estado estado;

  estado.set_estado("DF");
}

void Testes::testa_estado_erro() throw(invalid_argument){
  bool resultado = false;
  Estado estado;

  try {

  estado.set_estado("DH");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_estado() falhou");

  }
}

void Testes::testa_identificador_ok() {
  Identificador identificador;

  identificador.set_identificador("ideok");
}

void Testes::testa_identificador_erro() throw(invalid_argument){
  bool resultado = false;
  Identificador identificador;

  try {

  identificador.set_identificador("ADUAHDUAHDUAH");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_identificador() falhou");

  }
}

void Testes::testa_nome_ok() {
  Nome nome;
  nome.set_nome("João Pedro");
}

void Testes::testa_nome_erro() throw(invalid_argument){
  bool resultado = false;
  Nome nome;

  try {

  nome.set_nome("JIAIDSJ  eodmemde");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_diaria() falhou");

  }
}

void Testes::testa_numero_cartao_ok() {
  Numero_Cartao numero_cartao;

  numero_cartao.set_numero_cartao("5162205644883793");
}

void Testes::testa_numero_cartao_erro() throw(invalid_argument){
  bool resultado = false;
  Numero_Cartao numero_cartao;

  try {

  numero_cartao.set_numero_cartao("77876554");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_numero_cartao() falhou");

  }
}

void Testes::testa_numero_conta_corrente_ok() {
  Numero_Conta_Corrente numero_conta_corrente;

  numero_conta_corrente.set_numero_conta_corrente("003962");
}

void Testes::testa_numero_conta_corrente_erro() throw(invalid_argument){
  bool resultado = false;
  Numero_Conta_Corrente numero_conta_corrente;

  try {

  numero_conta_corrente.set_numero_conta_corrente("103183812031");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_numero_conta_corrente() falhou");

  }
}

void Testes::testa_senha_ok() {
  Senha senha;

  senha.set_senha("Senha123!");
}

void Testes::testa_senha_erro() throw(invalid_argument){
  bool resultado = false;
  Senha senha;

  try {

  senha.set_senha("sndjsndheuhdue");

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_senha() falhou");

  }
}

void Testes::testa_tipo_acomodacao_ok() {
  Tipo_Acomodacao tipo_acomodacao;

  tipo_acomodacao.set_tipo_acomodacao(1);
}

void Testes::testa_tipo_acomodacao_erro() throw(invalid_argument){
  bool resultado = false;
  Tipo_Acomodacao tipo_acomodacao;

  try {

  tipo_acomodacao.set_tipo_acomodacao(5);

  } catch(const invalid_argument& ia) {
    resultado = true;
  }

  if (!resultado) {

    throw invalid_argument("Teste set_tipo_acomodacao() falhou");

  }
}
