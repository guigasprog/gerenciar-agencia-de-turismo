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
                            struct Guia *guia, struct Index_Guia * indicesGuia, int &contGuia,
                        struct Cidade *cidade, struct Index_Cidade *indicesCidade, int &contCidade,
                        struct Pais *paises, struct Index_Pais *indicesPaises, int &contPais, int &index){
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
        index = i;
        cout << "\tDescricao: " << pacote[i].descricao;
        buscaAleatoriaGuia(guia, indicesGuia, contGuia, pacote[i].codigo_guia,
                           cidade, indicesCidade, contCidade,
                           paises, indicesPaises, contPais);
        cout << "\tValor por Pessoa: " << pacote[i].valor_por_pessoa;
        cout << "\tTotal de Participantes: " << pacote[i].total_participantes;
        cout << "/" << pacote[i].quant_max_participantes << endl;
        return true;
    } else cout << "Pacote nao Encontrada!\n";
    return false;
}


bool buscaAleatoriaVenda (struct Venda *venda, struct Index_Venda *indicesVenda, int &cont, int cod,
                           struct Pacote *pacote, struct Index_Pacote *indicesPacote, int &contPacote,
                           struct Cliente *cliente, struct Index_Cliente *indicesCliente, int &contCliente,
                           struct Guia *guia, struct Index_Guia *indicesGuia, int &contGuia,
                           struct Cidade *cidade, struct Index_Cidade *indicesCidade, int &contCidade,
                           struct Pais *paises, struct Index_Pais *indicesPaises, int &contPais){
    int i = 0, f = cont;
    int m = (i + f) / 2;
    for (; f >= i && cod != indicesVenda[m].codigo; m = (i + f) / 2){
        if (cod > indicesVenda[m].codigo)
            i = m + 1;
        else
            f = m - 1;
    }
    int indexDoPacote;
    if (cod == indicesVenda[m].codigo){
        i = indicesVenda[m].index;
        buscaAleatoriaPacote(pacote, indicesPacote, contPacote, venda[i].codigo_pacote,
                             guia, indicesGuia, contGuia,
                             cidade, indicesCidade, contCidade,
                             paises, indicesPaises, contPais, indexDoPacote);
        buscaAleatoriaCliente(cliente, indicesCliente, contCliente, venda[i].codigo_cliente,
                             cidade, indicesCidade, contCidade,
                             paises, indicesPaises, contPais);
        cout << "\tQuantidade de pessoas: " << venda[i].quantidade_pessoas;
        cout << "\tValor Total: " << venda[i].valor_total;
        return true;
    } else cout << "Venda nao Encontrado!\n";
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
            system("pause");
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

void lerGuias(struct Index_Guia indicesGuia[], struct Guia guia[],
              struct Cidade *cidades, struct Index_Cidade *indicesCidades,
               struct Pais *paises, struct Index_Pais *indicesPaises,
               int &index, int indexCidade, int indexPais) {
    system("cls");
    int continuar = 0, i = index;
    while(continuar == 0) {
        cout << "Informe o codigo do Guia: "; cin >> guia[i].codigo;
        indicesGuia[i].codigo = guia[i].codigo;
        indicesGuia[i].index = i;
        cout << "Nome: ";
        cin >> guia[i].nome;
        cout << "Endereco: ";
        cin >> guia[i].endereco;
        cout << "Telefone: ";
        cin >> guia[i].telefone;
        cout << "Codigo Cidade: ";
        cin >> guia[i].codigo_cidade;
        guia[i].exclusao = 0;
        for(;buscaAleatoriaCidade(cidades, indicesCidades, paises, indicesPaises, indexCidade,
                              indexPais, guia[i].codigo_cidade) && guia[i].codigo_cidade != 0;) {
            cout << "\nInforme outro codigo da Cidade: "; cin >> guia[i].codigo_cidade;
        }
        system("pause");
        cout << "Deseja inserir mais Guias? Informe 1 para parar e 0 para continuar\n";
        cin >> continuar;
        system("cls");
        i++;
    }
    index = i;
}

void inclusaoGuia (struct Index_Guia indicesGuia[], struct Guia guia[],
                   struct Index_Cidade indicesCidade[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int indexCidade, int indexPais, int cod){
    cont++;

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
    system("pause");
    int i;
    for (i = cont - 1; indicesGuia[i].codigo > cod; i--){
        indicesGuia[i+1].codigo = indicesGuia[i].codigo;
        indicesGuia[i+1].index = indicesGuia[i].index;
    }
    indicesGuia[i+1].codigo = cod;
    indicesGuia[i+1].index = cont;
    cout << "\n\nInclusao realizada com Sucesso!\n";
}

 /**
  * INICIO - 3) função que permite a inclusão de novos registros na tabela de Clientes.
  */

void lerClientes(struct Index_Cliente indicesCliente[], struct Cliente clientes[],
              struct Cidade *cidades, struct Index_Cidade *indicesCidades,
               struct Pais *paises, struct Index_Pais *indicesPaises,
               int &index, int indexCidade, int indexPais) {
    system("cls");
    int continuar = 0, i = index;
    while(continuar == 0) {
        cout << "Informe o codigo do Cliente: "; cin >> clientes[i].codigo;
        indicesCliente[i].codigo = clientes[i].codigo;
        indicesCliente[i].index = i;
        cout << "Nome: ";
        cin >> clientes[i].nome;
        cout << "Endereco: ";
        cin >> clientes[i].endereco;
        cout << "Codigo Cidade: ";
        cin >> clientes[i].codigo_cidade;
        clientes[i].exclusao = 0;
        for(;buscaAleatoriaCidade(cidades, indicesCidades, paises, indicesPaises, indexCidade,
                              indexPais, clientes[i].codigo_cidade) && clientes[i].codigo_cidade != 0;) {
            cout << "\nInforme outro codigo da Cidade: "; cin >> clientes[i].codigo_cidade;
        }
        system("pause");
        cout << "Deseja inserir mais Clientes? Informe 1 para parar e 0 para continuar\n";
        cin >> continuar;
        system("cls");
        i++;
    }
    index = i;
}

void inclusaoCliente (struct Index_Cliente indicesCliente[], struct Cliente cliente[],
                   struct Index_Cidade indicesCidade[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int indexCidade, int indexPais, int cod){
    cont++;

    cliente[cont].codigo = cod;
    cout << "Nome: ";
    cin >> cliente[cont].nome;
    cout << "Endereco: ";
    cin >> cliente[cont].endereco;
    cout << "Codigo Cidade: ";
    cin >> cliente[cont].codigo_cidade;
    cliente[cont].exclusao = 0;

    for(;buscaAleatoriaCidade(cidades, indicesCidade, paises, indicesPais, indexCidade,
                              indexPais, cliente[cont].codigo_cidade);) {
        cout << "\nInforme outro codigo da Cidade: "; cin >> cliente[cont].codigo_cidade;
    }
    system("pause");
    int i;
    for (i = cont - 1; indicesCliente[i].codigo > cod; i--){
        indicesCliente[i+1].codigo = indicesCliente[i].codigo;
        indicesCliente[i+1].index = indicesCliente[i].index;
    }
    indicesCliente[i+1].codigo = cod;
    indicesCliente[i+1].index = cont;
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

void lerPacotes(struct Index_Pacote indicesPacotes[], struct Pacote pacotes[],
                     struct Index_Guia indicesGuias[], struct Guia guias[],
                   struct Index_Cidade indicesCidade[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &index, int indexGuia, int indexCidade, int indexPais) {
    system("cls");
    int continuar = 0, i = index;
    while(continuar == 0) {

        cout << "Informe o codigo do Pacote: "; cin >> pacotes[i].codigo;
        indicesPacotes[i].codigo = pacotes[i].codigo;
        indicesPacotes[i].index = i;
        cout << "Descricao: ";
        cin >> pacotes[i].descricao;
        cout << "Valor por pessoa: ";
        cin >> pacotes[i].valor_por_pessoa;
        cout << "Total Participantes: ";
        cin >> pacotes[i].total_participantes;
        cout << "Quant Max Participantes: ";
        cin >> pacotes[i].quant_max_participantes;
        cout << "Codigo Guia: ";
        cin >> pacotes[i].codigo_guia;

        for(;!buscaAleatoriaGuia(guias,indicesGuias,indexGuia,pacotes[i].codigo_guia,
                            cidades,indicesCidade,indexCidade,
                            paises,indicesPais,indexPais) && pacotes[i].codigo_guia != 0;) {
            cout << "\nInforme outro codigo de Guia: "; cin >> pacotes[i].codigo_guia;
        }
        system("pause");

        cout << "Deseja inserir mais Pacotes? Informe 1 para parar e 0 para continuar\n";
        cin >> continuar;
        system("cls");
        i++;
    }
    index = i;
}

void inclusaoPacote (struct Index_Pacote indicesPacotes[], struct Pacote pacotes[],
                     struct Index_Guia indicesGuias[], struct Guia guias[],
                   struct Index_Cidade indicesCidade[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int indexGuia, int indexCidade, int indexPais, int cod){

    pacotes[cont].codigo = cod;
    cout << "Informe a descricao do Pacote: "; cin >> pacotes[cont].descricao;
    cout << "Informe o valor por pessoa: "; cin >> pacotes[cont].valor_por_pessoa;
    cout << "Informe o num total de participante: "; cin >> pacotes[cont].total_participantes;
    cout << pacotes[cont].total_participantes << endl;
    system("pause");
    cout << "Informe a quantidade maxima de participante: "; cin >> pacotes[cont].quant_max_participantes;
    cout << "Informe o codigo do Guia: "; cin >> pacotes[cont].codigo_guia;

    for(;!buscaAleatoriaGuia(guias,indicesGuias,indexGuia,pacotes[cont].codigo_guia,
                            cidades,indicesCidade,indexCidade,
                            paises,indicesPais,indexPais) && pacotes[cont].codigo_guia != 0;) {
        cout << "\nInforme outro codigo da Guia: "; cin >> pacotes[cont].codigo_guia;
    }
    if(pacotes[cont].codigo_guia == 0) return;
    system("pause");
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

void lerVendas(struct Index_Venda indicesVendas[], struct Venda vendas[],
                    struct Index_Pacote indicesPacotes[], struct Pacote pacotes[],
                     struct Index_Cliente indicesClientes[], struct Cliente clientes[],
                     struct Index_Guia indicesGuias[], struct Guia guias[],
                   struct Index_Cidade indicesCidades[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &index, int &indexPacote, int &indexCliente, int &indexGuia, int &indexCidade, int &indexPais) {
    system("cls");
    int continuar = 0, i = index;
    while(continuar == 0) {

        cout << "Informe o codigo da Venda: "; cin >> vendas[i].codigo;
        indicesVendas[i].codigo = vendas[i].codigo;
        indicesVendas[i].index = i;

        cout << "Codigo Cliente: ";
        cin >> vendas[i].codigo_cliente;
        for(;!buscaAleatoriaCliente(clientes, indicesClientes, indexCliente, vendas[i].codigo_cliente,
                                cidades, indicesCidades, indexCidade,
                                paises, indicesPais, indexPais) && vendas[i].codigo_cliente != 0;) {
            cout << "\nInforme outro codigo de Cliente: "; cin >> vendas[i].codigo_cliente;
        }
        if(vendas[i].codigo_cliente == 0) return;
        system("pause");

        int indexDoPacote;
        cout << "Codigo Pacote: ";
        cin >> vendas[i].codigo_pacote;
        for(;!buscaAleatoriaPacote(pacotes, indicesPacotes, indexPacote, vendas[i].codigo_pacote,
                             guias, indicesGuias, indexGuia,
                             cidades, indicesCidades, indexCidade,
                             paises, indicesPais, indexPais, indexDoPacote) && vendas[i].codigo_pacote != 0;) {
            cout << "\nInforme outro codigo do Pacote: "; cin >> vendas[i].codigo_pacote;
        }
        if(vendas[i].codigo_pacote == 0) return;

        cout << "\nInforme a quantidade de pessoas: "; cin >> vendas[i].quantidade_pessoas;
        for(;vendas[i].quantidade_pessoas > -1 && vendas[i].quantidade_pessoas >= (pacotes[indexDoPacote].quant_max_participantes - pacotes[indexDoPacote].total_participantes)+1;) {
            cout << "\nInforme outro numero de pessoas: "; cin >> vendas[i].quantidade_pessoas;
        }
        pacotes[indexDoPacote].total_participantes += vendas[i].quantidade_pessoas;

        vendas[i].valor_total = vendas[i].quantidade_pessoas * pacotes[indexDoPacote].valor_por_pessoa;
        cout << "\n\nO valor total foi: RS" << vendas[i].valor_total;

        cout << "\n\nDeseja inserir mais Vendas? Informe 1 para parar e 0 para continuar\n";
        cin >> continuar;
        system("cls");
        i++;
    }
    index = i;
}

void inclusaoVenda (struct Index_Venda indicesVendas[], struct Venda vendas[],
                    struct Index_Pacote indicesPacotes[], struct Pacote pacotes[],
                     struct Index_Cliente indicesClientes[], struct Cliente clientes[],
                     struct Index_Guia indicesGuias[], struct Guia guias[],
                   struct Index_Cidade indicesCidades[], struct Cidade cidades[],
                   struct Index_Pais indicesPais[], struct Pais paises[],
                   int &cont, int &indexPacote, int &indexCliente, int &indexGuia, int &indexCidade, int &indexPais, int cod){

    vendas[cont].codigo = cod;

    int indexDoPacote;
    cout << "Informe o codigo do Pacote: "; cin >> vendas[cont].codigo_pacote;
    for(;!buscaAleatoriaPacote(pacotes, indicesPacotes, indexPacote, vendas[cont].codigo_pacote,
                             guias, indicesGuias, indexGuia,
                             cidades, indicesCidades, indexCidade,
                             paises, indicesPais, indexPais, indexDoPacote) && vendas[cont].codigo_pacote != 0;) {
        cout << "\nInforme outro codigo do Pacote: "; cin >> vendas[cont].codigo_pacote;
    }
    if(vendas[cont].codigo_pacote == 0) return;
    system("pause");

    cout << "Informe o codigo do Cliente: "; cin >> vendas[cont].codigo_cliente;

    for(;!buscaAleatoriaCliente(clientes, indicesClientes, indexCliente, vendas[cont].codigo_cliente,
                                cidades, indicesCidades, indexCidade,
                                paises, indicesPais, indexPais) && vendas[cont].codigo_cliente != 0;) {
        cout << "\nInforme outro codigo de Cliente: "; cin >> vendas[cont].codigo_cliente;
    }
    if(vendas[cont].codigo_cliente == 0) return;
    system("pause");

    cout << "\nInforme a quantidade de pessoas: "; cin >> vendas[cont].quantidade_pessoas;
    for(;vendas[cont].quantidade_pessoas > -1 && vendas[cont].quantidade_pessoas >= (pacotes[indexDoPacote].quant_max_participantes - pacotes[indexDoPacote].total_participantes)+1;) {
        cout << "\nInforme outro numero de pessoas: "; cin >> vendas[cont].quantidade_pessoas;
    }
    pacotes[indexDoPacote].total_participantes += vendas[cont].quantidade_pessoas;

    vendas[cont].valor_total = vendas[cont].quantidade_pessoas * pacotes[indexDoPacote].valor_por_pessoa;
    cout << "\n\nO valor total foi: RS" << vendas[cont].valor_total;


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
            cout << "Deseja fazer qual leitura?\n-> Pais - 0\n-> Cidade - 1\n-> Incluir Um Guia - 2\n-> Incluir Um Cliente - 3\n-> Incluir Um Pacote - 4\n-> Incluir Uma Venda - 5\n";
            cin >> i;
            if(i == 0) {
                lerPais(paises, indicesPaises, index_pais);
            } else if(i == 1) {
                lerCidade(cidades, indicesCidades, paises, indicesPaises, index_cidade, index_pais);
            } else if(i == 2) {
                if(index_cidade > 0) {
                    if(!index_guia < 1) {
                         cout << "Informe o codigo do Guia: "; cin >> i;
                    }
                    if(index_guia < 1) {
                        lerGuias(indicesGuias, guias, cidades, indicesCidades, paises, indicesPaises, index_guia, index_cidade, index_pais);
                    } else if(!buscaAleatoriaGuia(guias, indicesGuias, index_guia, i,
                                           cidades, indicesCidades, index_cidade,
                                           paises, indicesPaises, index_pais)) {
                        cout << "\nInforme os dados para inclusao: \n";
                        inclusaoGuia(indicesGuias, guias,
                                     indicesCidades, cidades,
                                     indicesPaises, paises,
                                     index_guia, index_cidade, index_pais, i);
                    }
                    system("pause");
                } else {
                    cout << "Insira pelo menos uma cidade!\n";
                    system("pause");
                }
            } else if(i == 3) {
                if(index_cidade > 0) {
                    if(!index_cliente < 1) {
                         cout << "Informe o codigo do Cliente: "; cin >> i;
                    }
                    if(index_cliente < 1) {
                        lerClientes(indicesClientes, clientes, cidades, indicesCidades, paises, indicesPaises, index_cliente, index_cidade, index_pais);
                    } else if(!buscaAleatoriaCliente(clientes, indicesClientes, index_cliente, i,
                                              cidades, indicesCidades, index_cidade,
                                              paises, indicesPaises, index_pais)) {
                        cout << "\nInforme os dados para inclusao: \n";
                        inclusaoCliente(indicesClientes, clientes,
                                     indicesCidades, cidades,
                                     indicesPaises, paises,
                                     index_cliente, index_cidade, index_pais, i);
                    }
                    system("pause");
                } else {
                    cout << "Insira pelo menos uma cidade!\n";
                    system("pause");
                }
            } else if(i == 4) {
                if(index_guia > 0) {
                    if(!index_pacote < 1) {
                         cout << "Informe o codigo do Pacote: "; cin >> i;
                    }
                    if(index_pacote < 1) {
                        lerPacotes(indicesPacotes, pacotes,
                                       indicesGuias, guias,
                                       indicesCidades, cidades,
                                       indicesPaises, paises,
                                       index_pacote, index_guia, index_cidade, index_pais);
                    } else if(!buscaAleatoriaPacote(pacotes, indicesPacotes, index_pacote, i,
                             guias, indicesGuias, index_guia,
                             cidades, indicesCidades, index_cidade,
                             paises, indicesPaises, index_pais, i)) {
                        cout << "\nInforme os dados para inclusao: \n";
                        inclusaoPacote(indicesPacotes, pacotes,
                                       indicesGuias, guias,
                                       indicesCidades, cidades,
                                       indicesPaises, paises,
                                       index_pacote, index_guia, index_cidade, index_pais, i);
                    }
                    system("pause");
                } else {
                    cout << "Insira pelo menos um Guia!\n";
                    system("pause");
                }
            } else if(i == 5) {
                if(index_pacote > 0 && index_cliente > 0) {
                    if(!index_venda < 1) {
                         cout << "Informe o codigo do Pacote: "; cin >> i;
                    }
                    if(index_venda < 1) {
                        lerVendas(indicesVendas, vendas,
                                      indicesPacotes, pacotes,
                                      indicesClientes, clientes,
                                      indicesGuias, guias,
                                      indicesCidades, cidades,
                                      indicesPaises, paises,
                                      index_venda, index_pacote, index_cliente, index_guia, index_cidade, index_pais);
                    } else if(!buscaAleatoriaVenda(vendas, indicesVendas, index_venda, i,
                                            pacotes, indicesPacotes, index_pacote,
                                            clientes, indicesClientes, index_cliente,
                                            guias, indicesGuias, index_guia,
                                            cidades, indicesCidades, index_cidade,
                                            paises, indicesPaises, index_pais)) {
                        cout << "\nInforme os dados para inclusao: \n";
                        inclusaoVenda(indicesVendas, vendas,
                                      indicesPacotes, pacotes,
                                      indicesClientes, clientes,
                                      indicesGuias, guias,
                                      indicesCidades, cidades,
                                      indicesPaises, paises,
                                      index_venda, index_pacote, index_cliente, index_guia, index_cidade, index_pais, i);
                    }
                    system("pause");
                } else {
                    cout << "Insira pelo menos um pacote e um cliente!\n";
                    system("pause");
                }
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
