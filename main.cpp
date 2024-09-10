#include <iostream>

using namespace std;

 /**
  * INICIO - Structs
  */

struct Pais {
    int codigo;
    string nome;
};

struct Cidade {
    int codigo;
    string nome;
    string uf;
    int codigo_pais;
};

struct Guia {
    int codigo;
    string nome;
    string endereco;
    string telefone;
    int codigo_cidade;
    int exclusao;
};

struct Cliente {
    int codigo;
    string nome;
    string endereco;
    int codigo_cidade;
    int exclusao;
};

struct Pacote {
    int codigo;
    string descricao;
    int codigo_guia;
    double valor_por_pessoa;
    int total_participantes;
    int quant_max_participantes;
};

struct Venda {
    int codigo;
    int codigo_cliente;
    int codigo_pacote;
    int quantidade_pessoas;
    double valor_total;
};

struct Index_Pais {
    int codigo;
    int index;
};

struct Index_Cidade {
    int codigo;
    int index;
};

struct Index_Guia {
    int codigo;
    int index;
};

struct Index_Cliente {
    int codigo;
    int index;
};

struct Index_Pacote {
    int codigo;
    int codigo_guia;
    int index;
};

struct Index_Venda {
    int codigo;
    int codigo_cliente;
    int index;
};

 /**
  * FIM - Structs
  */

 /**
 * BUSCA ALEATORIA
 */

bool buscaAleatoriaPais (struct Pais *paises, struct Index_Pais *indicesPaises, int &cont, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indicesPaises[m].codigo; m = (i + f) / 2){
        if (cod > indicesPaises[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == indicesPaises[m].codigo){
        i = indicesPaises[m].index;
        cout << "\tNome: " << paises[i].nome << endl;
        return false;
    } else cout << "Pais nao Encontrado!\n";
    return true;
}

bool buscaAleatoriaCidade (struct Cidade *cidade, struct Index_Cidade *indicesCidade,
                           struct Pais *paises, struct Index_Pais *indicesPaises,
                            int &cont, int indexPais, int cod){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indicesCidade[m].codigo; m = (i + f) / 2){
        if (cod > indicesCidade[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == indicesCidade[m].codigo){
        i = indicesCidade[m].index;
        cout << "\tNome: " << cidade[i].nome;
        cout << "\tUF: " << cidade[i].uf;
        buscaAleatoriaPais(paises, indicesPaises, indexPais, cidade[i].codigo_pais);
        return false;
    } else cout << "Cidade nao Encontrada!\n";
    return true;
}

bool buscaAleatoriaGuia (struct Guia *guia, struct Index_Guia *indicesGuia, int &cont, int cod,
                        struct Cidade *cidade, struct Index_Cidade *indicesCidade, int &contCidade,
                        struct Pais *paises, struct Index_Pais *indicesPaises, int &contPais){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indicesGuia[m].codigo; m = (i + f) / 2){
        if (cod > indicesGuia[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == indicesGuia[m].codigo){
        i = indicesGuia[m].index;
        cout << "\tNome: " << guia[i].nome;
        cout << "\tEndereço: " << guia[i].endereco;
        cout << "\tTelefone: " << guia[i].telefone;
        buscaAleatoriaCidade(cidade, indicesCidade, paises, indicesPaises, contCidade, contPais, guia[i].codigo_cidade);
        return true;
    } else cout << "Guia nao Encontrada!\n";
    return false;
}

bool buscaAleatoriaCliente (struct Cliente *cliente, struct Index_Cliente *indicesCliente, int &cont, int cod,
                        struct Cidade *cidade, struct Index_Cidade *indicesCidade, int &contCidade,
                        struct Pais *paises, struct Index_Pais *indicesPaises, int &contPais){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indicesCliente[m].codigo; m = (i + f) / 2){
        if (cod > indicesCliente[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == indicesCliente[m].codigo){
        i = indicesCliente[m].index;
        cout << "\tNome: " << cliente[i].nome;
        cout << "\tEndereço: " << cliente[i].endereco;
        buscaAleatoriaCidade(cidade, indicesCidade, paises, indicesPaises, contCidade, contPais, cliente[i].codigo_cidade);
        return true;
    } else cout << "Cliente nao Encontrada!\n";
    return false;
}

bool buscaAleatoriaPacote (struct Pacote *pacote, struct Index_Pacote *indicesPacote, int &cont, int cod,
                           struct Guia *guia, struct Index_Guia *indicesGuia, int &contGuia,
                           struct Cidade *cidade, struct Index_Cidade *indicesCidade, int &contCidade,
                           struct Pais *paises, struct Index_Pais *indicesPaises, int &contPais){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indicesPacote[m].codigo; m = (i + f) / 2){
        if (cod > indicesPacote[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    if (cod == indicesPacote[m].codigo){
        i = indicesPacote[m].index;
        cout << "\tDescricao do Pacote: " << pacote[i].descricao;
        cout << "\nValor por pessoa: " << pacote[i].valor_por_pessoa;
        cout << "\tTotal de Participantes: " << pacote[i].total_participantes;
        cout << "\tQuantidade maxima de Participantes: " << pacote[i].quant_max_participantes;
        buscaAleatoriaGuia(guia, indicesGuia, contGuia, pacote[i].codigo_guia,
                           cidade, indicesCidade, contCidade,
                           paises, indicesPaises, contPais);
        return true;
    } else cout << "Pacote nao Encontrado!\n";
    return false;
}

 /**
  * INICIO - 1) funções para leitura dos dados das estruturas: Países, Cidades.
  */

void lerPais(struct Pais *paises, struct Index_Pais *indicesPaises, int &index) {
    system("cls");
    int continuar = 0, i = index;
    while(continuar == 0) {
        cout << "Informe o codigo do Pais: "; cin >> paises[i].codigo;
        indicesPaises[i].codigo = paises[i].codigo;
        indicesPaises[i].index = i;
        cout << "Informe o nome do Pais: "; cin >> paises[i].nome;
        cout << "Deseja inserir mais paises? Informe 1 para parar e 0 para continuar\n";
        cin >> continuar;
        system("cls");
        i++;
    }
    index = i;
}

void lerCidade(struct Cidade *cidades, struct Index_Cidade *indicesCidades,
               struct Pais *paises, struct Index_Pais *indicesPaises,
               int &index, int indexPais) {
    system("cls");
    int continuar = 0, i = index;
    if(indexPais > 0)
        while(continuar == 0) {
            cout << "Informe o codigo da Cidade: "; cin >> cidades[i].codigo;
            indicesCidades[i].codigo = cidades[i].codigo;
            indicesCidades[i].index = i;
            cout << "Informe o nome da Cidade: "; cin >> cidades[i].nome;
            cout << "Informe o uf da Cidade: "; cin >> cidades[i].uf;
            cout << "Informe o codigo do pais: "; cin >> cidades[i].codigo_pais;
            for(;buscaAleatoriaPais(paises, indicesPaises, indexPais, cidades[i].codigo_pais);) {
                cout << "\nInforme outro codigo do pais: "; cin >> cidades[i].codigo_pais;
            }
            cout << "Deseja inserir mais cidades? Informe 1 para parar e 0 para continuar\n";
            cin >> continuar;
            system("cls");
            i++;
        }
    else {
        cout << "Informe pelo menos um Pais!\n";
        system("pause");
    }
    system("cls");
    index = i;
}

 /**
  * INICIO - 2) função que permite a inclusão de novos registros na tabela de Guias.
  */

void inclusaoGuia (struct Index_Guia indicesGuia[], struct Guia guia[],
                   struct Index_Cidade indicesCidade[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int indexCidade, int indexPais, int cod){

    guia[cont].codigo = cod;
    cout << "Nome: ";
    cin >> guia[cont].nome;
    cout << "Endereco: ";
    cin >> guia[cont].endereco;
    cout << "Telefone: ";
    cin >> guia[cont].telefone;
    cout << "Codigo Cidade: ";
    cin >> guia[cont].codigo_cidade;
    guia[cont].exclusao = 0;

    for(;buscaAleatoriaCidade(cidades, indicesCidade, paises, indicesPais, indexCidade,
                              indexPais, guia[cont].codigo_cidade) && guia[cont].codigo_cidade != 0;) {
        cout << "\nInforme outro codigo da Cidade: "; cin >> guia[cont].codigo_cidade;
    }
    if(guia[cont].codigo_cidade == 0) return ;
    int i;
    for (i = cont - 1; indicesGuia[i].codigo > cod; i--){
        indicesGuia[i+1].codigo = indicesGuia[i].codigo;
        indicesGuia[i+1].index = indicesGuia[i].index;
    }
    indicesGuia[i+1].codigo = cod;
    indicesGuia[i+1].index = cont;
    cont++;
    cout << "\n\nInclusao realizada com Sucesso!\n";
}

 /**
  * INICIO - 3) função que permite a inclusão de novos registros na tabela de Clientes.
  */

void inclusaoCliente (struct Index_Cliente indicesCliente[], struct Cliente cliente[],
                   struct Index_Cidade indicesCidade[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int indexCidade, int indexPais, int cod){

    cliente[cont].codigo = cod;
    cout << "Nome: ";
    cin >> cliente[cont].nome;
    cout << "Endereco: ";
    cin >> cliente[cont].endereco;
    cout << "Codigo Cidade: ";
    cin >> cliente[cont].codigo_cidade;
    cliente[cont].exclusao = 0;

    for(;buscaAleatoriaCidade(cidades, indicesCidade, paises, indicesPais, indexCidade,
                              indexPais, cliente[cont].codigo_cidade) && cliente[cont].codigo_cidade != 0;) {
        cout << "\nInforme outro codigo da Cidade: "; cin >> cliente[cont].codigo_cidade;
    }
    if(cliente[cont].codigo_cidade == 0) return;
    int i;
    for (i = cont - 1; indicesCliente[i].codigo > cod; i--){
        indicesCliente[i+1].codigo = indicesCliente[i].codigo;
        indicesCliente[i+1].index = indicesCliente[i].index;
    }
    indicesCliente[i+1].codigo = cod;
    indicesCliente[i+1].index = cont;
    cont++;
    cout << "\n\nInclusao realizada com Sucesso!\n";
}

/**
 * INICIO - 4) função para permitir a exclusão de registros na tabela de Clientes.
 */

bool buscaAleatoriaVendasCliente(struct Index_Venda *indicesVendas, int &cont, int codCliente) {
    if(cont > 0) {
        int i = 0, f = cont;
        int m = (i + f) / 2;
        for (; f >= i && codCliente != indicesVendas[m].codigo_cliente; m = (i + f) / 2){
            if (codCliente > indicesVendas[m].codigo_cliente)
                i = m + 1;
            else
                f = m - 1;
        }
        i = indicesVendas[m].index;
        if (codCliente == indicesVendas[m].codigo_cliente){
            return false;
            cout << "\n\nExiste Vendas atribuidas ao Cliente!";
        }
    }
    return true;
}

void exclusaoCliente (struct Cliente *clientes, struct Index_Cliente *indicesClientes,
                      struct Index_Venda *indicesVendas, int &cont, int &contVenda, int cod) {
  int i = 0, f = cont;
  int m = (i + f) / 2;
  for (; f >= i && cod != indicesClientes[m].codigo; m = (i + f) / 2){
        if (cod > indicesClientes[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indicesClientes[m].index;
    if (buscaAleatoriaVendasCliente(indicesVendas, contVenda, cod) && (cod == indicesClientes[m].codigo) && clientes[i].exclusao == 0){
        clientes[i].exclusao = 1;
        cout << "\n\n Cliente Excluido com Sucesso";
    }
    else
        cout << "\nCodigo inexistente!\n";
}

/**
 * INICIO - 5) função para permitir a exclusão de registros na tabela de Guias.
 */

bool buscaAleatoriaPacoteGuia(struct Index_Pacote *indicesPacotes, int &cont, int codGuia) {
    if(cont > 0) {
        int i = 0, f = cont;
        int m = (i + f) / 2;
        for (; f >= i && codGuia != indicesPacotes[m].codigo_guia; m = (i + f) / 2){
            if (codGuia > indicesPacotes[m].codigo_guia)
                i = m + 1;
            else
                f = m - 1;
        }
        i = indicesPacotes[m].index;
        if (codGuia == indicesPacotes[m].codigo_guia){
            return false;
            cout << "\n\nExiste Pacotes atribuidas ao Guia!";
        }
    }
    return true;
}

void exclusaoGuia(struct Guia *guias, struct Index_Guia *indicesGuias,
                  struct Index_Pacote *indicesPacotes, int &cont, int &contPacote, int cod) {
  int i = 0, f = cont;
  int m = (i + f) / 2;
  for (; f >= i && cod != indicesGuias[m].codigo; m = (i + f) / 2){
        if (cod > indicesGuias[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    i = indicesGuias[m].index;
    if (buscaAleatoriaPacoteGuia(indicesPacotes, contPacote, cod) && (cod == indicesGuias[m].codigo) && guias[i].exclusao == 0){
        guias[i].exclusao = 1;
        cout << "\n\n Guia Excluido com Sucesso";
    }
    else
        cout << "\nCodigo inexistente!\n";
}

/**
  * INICIO - 6) função que permite a inclusão de novos registros na tabela de Pacote.
  */

void inclusaoPacote (struct Index_Pacote indicesPacotes[], struct Pacote pacotes[],
                     struct Index_Guia indicesGuias[], struct Guia guias[],
                   struct Index_Cidade indicesCidade[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int indexGuia, int indexCidade, int indexPais, int cod){

    pacotes[cont].codigo = cod;
    cout << "Informe a descricao do Pacote: "; cin >> pacotes[cont].descricao;
    cout << "Informe o valor por pessoa: "; cin >> pacotes[cont].valor_por_pessoa;
    cout << "Informe o num total de participante: "; cin >> pacotes[cont].total_participantes;
    cout << "Informe a quantidade maxima de participante: "; cin >> pacotes[cont].quant_max_participantes;
    cout << "Informe o codigo do Guia: "; cin >> pacotes[cont].codigo_guia;

    for(;!buscaAleatoriaGuia(guias,indicesGuias,indexGuia,pacotes[cont].codigo_guia,
                            cidades,indicesCidade,indexCidade,
                            paises,indicesPais,indexPais) && pacotes[cont].codigo_guia != 0;) {
        cout << "\nInforme outro codigo da Guia: "; cin >> pacotes[cont].codigo_guia;
    }
    if(pacotes[cont].codigo_guia == 0) return;
    int i;
    for (i = cont - 1; indicesPacotes[i].codigo > cod; i--){
        indicesPacotes[i+1].codigo = indicesPacotes[i].codigo;
        indicesPacotes[i+1].index = indicesPacotes[i].index;
    }
    indicesPacotes[i+1].codigo = cod;
    indicesPacotes[i+1].index = cont;
    cont++;
    cout << "\n\nInclusao realizada com Sucesso!\n";
}

/**
  * INICIO - 7) função para permitir a inclusão de novos registros na tabela de Vendas.
  */

void inclusaoVenda (struct Index_Venda indicesVendas[], struct Venda vendas[],
                    struct Index_Pacote indicesPacotes[], struct Pacote pacotes[],
                     struct Index_Cliente indicesClientes[], struct Cliente clientes[],
                     struct Index_Guia indicesGuias[], struct Guia guias[],
                   struct Index_Cidade indicesCidades[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int indexPacote, int indexCliente, int indexGuia, int indexCidade, int indexPais, int cod){

    vendas[cont].codigo = cod;
    cout << "Informe o codigo do Cliente: "; cin >> vendas[cont].codigo_cliente;

    for(;!buscaAleatoriaCliente(clientes, indicesClientes, indexCliente, vendas[cont].codigo_cliente,
                                cidades, indicesCidades, indexCidade,
                                paises, indicesPais, indexPais) && vendas[cont].codigo_cliente != 0;) {
        cout << "\nInforme outro codigo de Cliente: "; cin >> vendas[cont].codigo_cliente;
    }
    if(vendas[cont].codigo_cliente == 0) return;

    cout << "Informe o codigo do Pacote: "; cin >> vendas[cont].codigo_pacote;
    for(;!buscaAleatoriaPacote(pacotes, indicesPacotes, indexPacote, vendas[cont].codigo_pacote,
                               guias, indicesGuias, indexGuia,
                               cidades, indicesCidades, indexCidade,
                               paises, indicesPais, indexPais) && vendas[cont].codigo_cliente != 0;) {
        cout << "\nInforme outro codigo do Pacote: "; cin >> vendas[cont].codigo_pacote;
    }
    if(vendas[cont].codigo_cliente == 0) return;

    cout << "Informe o numero de pessoas: "; cin >> vendas[cont].quantidade_pessoas;
    for(;vendas[cont].quantidade_pessoas > -1 && vendas[cont].quantidade_pessoas <= (pacotes[vendas[cont].codigo_pacote].quant_max_participantes - pacotes[vendas[cont].codigo_pacote].total_participantes);) {
        cout << "\nInforme outro numero de pessoas: "; cin >> vendas[cont].quantidade_pessoas;
    }
    pacotes[vendas[cont].codigo_pacote].total_participantes += vendas[cont].quantidade_pessoas;
    cout << "\n\nO valor total foi: " << vendas[cont].quantidade_pessoas*pacotes[vendas[cont].codigo_pacote].valor_por_pessoa;


    int i;
    for (i = cont - 1; indicesVendas[i].codigo > cod; i--){
        indicesVendas[i+1].codigo = indicesVendas[i].codigo;
        indicesVendas[i+1].index = indicesVendas[i].index;
    }
    indicesVendas[i+1].codigo = cod;
    indicesVendas[i+1].index = cont;
    cont++;
    cout << "\n\nInclusao realizada com Sucesso!\n";
}

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

    /**
     * DEFINICOES DOS INDICES EM VETORES
     */
    struct Index_Pais indicesPaises[10];
    struct Index_Cidade indicesCidades[20];
    struct Index_Guia indicesGuias[10];
    struct Index_Cliente indicesClientes[10];
    struct Index_Pacote indicesPacotes[10];
    struct Index_Venda indicesVendas[10];


    int index_pais = 0, index_cidade = 0, index_guia= 0,
        index_cliente = 0, index_pacote = 0, index_venda = 0;

    /**
     * INTERFACE
     */
    int i, x = 0;

    while(x != 1) {
        cout << "O que deseja fazer?\n-> Ler dados - 0\n-> Imprimir Dados - 1\n-> Exclusao de dados - 2\n";
        cin >> i;
        if(i == 0) {
            cout << "Deseja fazer qual leitura?\n-> Pais - 0\n-> Cidade - 1\n-> Incluir Um Guia - 2\n-> Incluir Um Cliente - 3\n-> Incluir Um Pacote - 4\n";
            cin >> i;
            if(i == 0) {
                lerPais(paises, indicesPaises, index_pais);
            } else if(i == 1) {
                lerCidade(cidades, indicesCidades, paises, indicesPaises, index_cidade, index_pais);
            } else if(i == 2) {
                if(index_cidade > 0) {
                    cout << "Informe o codigo do Guia: "; cin >> i;
                    if(!buscaAleatoriaGuia(guias, indicesGuias, index_guia, i,
                                           cidades, indicesCidades, index_cidade,
                                           paises, indicesPaises, index_pais)) {
                        cout << "\nInforme os dados para inclusao: \n";
                        inclusaoGuia(indicesGuias, guias,
                                     indicesCidades, cidades,
                                     indicesPaises, paises,
                                     index_guia, index_cidade, index_pais, i);
                    }
                } else cout << "Insira pelo menos uma cidade!\n";
                system("pause");
            } else if(i == 3) {
                if(index_cidade > 0) {
                    cout << "Informe o codigo do Cliente: "; cin >> i;
                    if(!buscaAleatoriaCliente(clientes, indicesClientes, index_cliente, i,
                                              cidades, indicesCidades, index_cidade,
                                              paises, indicesPaises, index_pais)) {
                        cout << "\nInforme os dados para inclusao: \n";
                        inclusaoCliente(indicesClientes, clientes,
                                     indicesCidades, cidades,
                                     indicesPaises, paises,
                                     index_cliente, index_cidade, index_pais, i);
                    }
                } else cout << "Insira pelo menos uma cidade!\n";
                system("pause");
            } else if(i == 4) {
                if(index_guia > 0) {
                    cout << "Informe o codigo do Pacote: "; cin >> i;
                    if(!buscaAleatoriaPacote(pacotes, indicesPacotes, index_pacote, i,
                                             guias, indicesGuias, index_guia,
                                             cidades, indicesCidades, index_cidade,
                                             paises, indicesPaises, index_pais)) {
                        cout << "\nInforme os dados para inclusao: \n";
                        inclusaoPacote(indicesPacotes, pacotes,
                                       indicesGuias, guias,
                                       indicesCidades, cidades,
                                       indicesPaises, paises,
                                       index_pacote, index_guia, index_cidade, index_pais, i);
                    }
                } else cout << "Insira pelo menos uma guia!\n";
                system("pause");
            }
        } else if(i == 1) {
            cout << "O que deseja fazer?\n-> Ler dados - 0\n-> Imprimir Dados - 1\n";
            cin >> i;
        } else if(i == 2) {
            cout << "O que deseja excluir?\n-> Clientes - 0\n-> Guias - 1\n";
            cin >> i;
            if(i == 0) {
                if(index_cliente > 0) {
                    for (int codpesq = 9; codpesq != 0;){
                        cout << "\n\nInforme o Codigo do Cliente a ser Excluido (0 para Encerrar): ";
                        cin >> codpesq;
                        if (codpesq != 0)
                            exclusaoCliente(clientes,indicesClientes,indicesVendas,index_cliente,index_venda,codpesq);
                    }
                } else cout << "\nInforme pelo menos 1 Cliente!\n";
                system("pause");
            } else if(i == 1) {
                if(index_guia > 0) {
                    for (int codpesq = 9; codpesq != 0;){
                        cout << "\n\nInforme o Codigo do Guia a ser Excluido (0 para Encerrar): ";
                        cin >> codpesq;
                        if (codpesq != 0)
                            exclusaoGuia(guias,indicesGuias,indicesPacotes,index_cliente,index_pacote,codpesq);
                    }
                } else cout << "\nInforme pelo menos 1 Cliente!\n";
                system("pause");
            }
        }
        system("cls");
    }


    return 0;
}
