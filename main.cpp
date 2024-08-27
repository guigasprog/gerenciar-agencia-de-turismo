#include <iostream>

using namespace std;

 /**
  * INICIO - Structs
  */

struct Pais {
    int codigo_pais;
    string nome;
};

struct Cidade {
    int codigo_cidade;
    string nome;
    string UF;
    int codigo_pais;
};

struct Guia {
    int codigo_guia;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
    int exclusao;
};

struct Cliente {
    int codigo_cliente;
    string nome;
    string endereco;
    int codigo_cidade;
    int exclusao;
};

struct Pacote {
    int codigo_pacote;
    string descricao;
    int codigo_guia;
    double valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct Venda {
    int codigo_venda;
    int codigo_cliente;
    int codigo_pacote;
    int quantidade_pessoas;
    double valor_total;
};

struct Index_Pais {
    int codigo_pais;
    int index;
};

struct Index_Cidade {
    int codigo_cidade;
    int index;
};

struct Index_Guia {
    int codigo_guia;
    int index;
};

struct Index_Cliente {
    int codigo_cliente;
    int index;
};

struct Index_Pacote {
    int codigo_pacote;
    int codigo_guia;
    int index;
};

struct Index_Venda {
    int codigo_venda;
    int codigo_cliente;
    int index;
};

 /**
  * FIM - Structs
  */


int main()
{
    /**
     * DEFINICOES DAS STRUCTS EM VETORES
     */
    struct Pais paises[10];
    struct Cidade cidades[20];
    struct Guia guias[10];
    struct Cliente clientes[10];
    struct Pacote pacotes[10];
    struct Venda vendas[10];

    int index_pais = 0, index_cidade = 0, index_guia= 0,
        index_cliente = 0, index_pacote = 0, index_venda = 0;





    return 0;
}
