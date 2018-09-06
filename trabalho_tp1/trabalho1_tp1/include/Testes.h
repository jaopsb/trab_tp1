#ifndef TESTES_H
#define TESTES_H

#include <dominios.h>

class Testes {
 public:
  bool rodar_testes();
 private:
  //testes com insercao correspondente a especificacao
  void testa_agencia_ok();
  void testa_banco_ok();
  void testa_capacidade_acomodacao_ok();
  void testa_data_ok();
  void testa_data_validade_ok();
  void testa_diaria_ok();
  void testa_estado_ok();
  void testa_identificador_ok();
  void testa_nome_ok();
  void testa_numero_cartao_ok();
  void testa_numero_conta_corrente_ok();
  void testa_senha_ok();
  void testa_tipo_acomodacao_ok();
 
  //testes de insercao com valores que nao correspondem a especificacao
  void testa_agencia_erro() throw(invalid_argument);
  void testa_banco_erro() throw(invalid_argument);
  void testa_capacidade_acomodacao_erro() throw(invalid_argument);
  void testa_data_erro() throw(invalid_argument);
  void testa_data_validade_erro() throw(invalid_argument);
  void testa_diaria_erro() throw(invalid_argument);
  void testa_estado_erro() throw(invalid_argument);
  void testa_identificador_erro() throw(invalid_argument);
  void testa_nome_erro() throw(invalid_argument);
  void testa_numero_cartao_erro() throw(invalid_argument);
  void testa_numero_conta_corrente_erro() throw(invalid_argument);
  void testa_senha_erro() throw(invalid_argument);
  void testa_tipo_acomodacao_erro() throw(invalid_argument);
};

#endif // TESTES_H
