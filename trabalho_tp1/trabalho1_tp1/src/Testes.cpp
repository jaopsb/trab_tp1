#include "Testes.h"
#include "dominios.h"
#include <stdexcept>
#include <iostream>

using namespace std;

void Teste::temp_teste(string nome_func, void(*f)(void)) {
  try {

    cout << "Teste " << nome_func;
    (*f)();
    cout << " - OK" << endl;

  } catch(const invalid_argument& ia) {
    cout << "Erro ao realizar o teste "<< nome_func << ": " << ia.what() << endl;
  }
}

/******* SUITES DE TESTES *******/

/**\brief rodar_suite().Executa todos os Teste criados para cada classe.
 * 
 * Nos Dominios, é verificado tanto a inserção de um valor de acordo com a especificação de cada função
 * como também um valor fora da especificação, verificando se há um erro esperado.
 * \param void
 * \return true se todos os Teste rodarem corretamente e false se algum der erro
*/
bool Teste_Agencia::rodar_suite() {

  try {

    temp_teste("Insere agencia com sucesso",testa_agencia_ok);
    temp_teste("Insere agencia com erro",testa_agencia_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Banco::rodar_suite() {

  try {

    temp_teste("Insere banco com sucesso",testa_banco_ok);
    temp_teste("Insere banco com erro",testa_banco_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Capacidade_Acomodacao::rodar_suite() {

  try {

    temp_teste("Insere capacidade de acomodacao com sucesso",testa_capacidade_acomodacao_ok);
    temp_teste("Insere capacidade de acomodacao com erro",testa_capacidade_acomodacao_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Data::rodar_suite() {

  try {

    temp_teste("Insere data com sucesso",testa_data_ok);
    temp_teste("Insere data com erro",testa_data_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Data_Validade::rodar_suite() {

  try {

    temp_teste("Insere data validade com sucesso",testa_data_validade_ok);
    temp_teste("Insere data validade com erro",testa_data_validade_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Diaria::rodar_suite() {

  try {

    temp_teste("Insere diaria com sucesso",testa_diaria_ok);
    temp_teste("Insere diaria com erro",testa_diaria_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Estado::rodar_suite() {

  try {

    temp_teste("Insere estado com sucesso",testa_estado_ok);
    temp_teste("Insere estado com erro",testa_estado_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Identificador::rodar_suite() {

  try {

    temp_teste("Insere identificador com sucesso",testa_identificador_ok);
    temp_teste("Insere identificador com erro",testa_identificador_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Nome::rodar_suite() {

  try {

    temp_teste("Insere nome com sucesso",testa_nome_ok);
    temp_teste("Insere nome com erro",testa_nome_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Numero_Cartao::rodar_suite() {

  try {

    temp_teste("Insere numero cartao com sucesso",testa_numero_cartao_ok);
    temp_teste("Insere numero cartao com erro",testa_numero_cartao_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Numero_Conta_Corrente::rodar_suite() {

  try {

    temp_teste("Insere numero conta corrente com sucesso",testa_numero_conta_corrente_ok);
    temp_teste("Insere numero conta corrente com erro",testa_numero_conta_corrente_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Senha::rodar_suite() {

  try {

    temp_teste("Insere senha com sucesso",testa_senha_ok);
    temp_teste("Insere senha com erro",testa_senha_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}

bool Teste_Tipo_Acomodacao::rodar_suite() {

  try {

    temp_teste("Insere tipo de acomodacao com sucesso",testa_tipo_acomodacao_ok);
    temp_teste("Insere tipo de acomodacao com erro",testa_tipo_acomodacao_erro);

  } catch( const invalid_argument& ia) {

    cout << ia.what() << endl;
    resultado = false;
  }

  return resultado;
}


/******** TESTES DE SUCESSO E ERRO UNITARIOS *********/

/**\briefvalidacao de insercao de um valor que confere com a especificação da classe Agencia
*/
void Teste_Agencia::testa_agencia_ok() {
  Agencia agencia;

  agencia.set_agencia(45678);
}

/**\briefValidação da inserção de um valor que nao corresponde a especificação da classe Agencia
*/
void Teste_Agencia::testa_agencia_erro() throw(invalid_argument){
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

void Teste_Banco::testa_banco_ok() {
  Banco banco;

  banco.set_banco(260);
}

void Teste_Banco::testa_banco_erro() throw(invalid_argument){
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

void Teste_Capacidade_Acomodacao::testa_capacidade_acomodacao_ok() {
  Capacidade_Acomodacao capacidade_acomodacao;

  capacidade_acomodacao.set_capacidade_acomodacao(7);
}

void Teste_Capacidade_Acomodacao::testa_capacidade_acomodacao_erro() throw(invalid_argument){
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

void Teste_Diaria::testa_diaria_ok() {
  Diaria diaria;

  diaria.set_diaria(723.44);
}

void Teste_Diaria::testa_diaria_erro() throw(invalid_argument){
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

void Teste_Data::testa_data_ok() {
  Data data;

  data.set_data("11/set/2001");
}

void Teste_Data::testa_data_erro() throw(invalid_argument){
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

void Teste_Data_Validade::testa_data_validade_ok() {
  Data_Validade data_validade;

  data_validade.set_data_validade("12/44");
}

void Teste_Data_Validade::testa_data_validade_erro() throw(invalid_argument){
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

void Teste_Estado::testa_estado_ok() {
  Estado estado;

  estado.set_estado("DF");
}

void Teste_Estado::testa_estado_erro() throw(invalid_argument){
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

void Teste_Identificador::testa_identificador_ok() {
  Identificador identificador;

  identificador.set_identificador("ideok");
}

void Teste_Identificador::testa_identificador_erro() throw(invalid_argument){
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

void Teste_Nome::testa_nome_ok() {
  Nome nome;
  nome.set_nome("João Pedro");
}

void Teste_Nome::testa_nome_erro() throw(invalid_argument){
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

void Teste_Numero_Cartao::testa_numero_cartao_ok() {
  Numero_Cartao numero_cartao;

  numero_cartao.set_numero_cartao("5162205644883793");
}

void Teste_Numero_Cartao::testa_numero_cartao_erro() throw(invalid_argument){
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

void Teste_Numero_Conta_Corrente::testa_numero_conta_corrente_ok() {
  Numero_Conta_Corrente numero_conta_corrente;

  numero_conta_corrente.set_numero_conta_corrente("003962");
}

void Teste_Numero_Conta_Corrente::testa_numero_conta_corrente_erro() throw(invalid_argument){
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

void Teste_Senha::testa_senha_ok() {
  Senha senha;

  senha.set_senha("Senha123!");
}

void Teste_Senha::testa_senha_erro() throw(invalid_argument){
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

void Teste_Tipo_Acomodacao::testa_tipo_acomodacao_ok() {
  Tipo_Acomodacao tipo_acomodacao;

  tipo_acomodacao.set_tipo_acomodacao(1);
}

void Teste_Tipo_Acomodacao::testa_tipo_acomodacao_erro() throw(invalid_argument){
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
