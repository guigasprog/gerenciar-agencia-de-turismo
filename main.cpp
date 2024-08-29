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
        cout << "\nCodigo do Pais: " << paises[i].codigo;
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
        cout << "\nCodigo do cidade: " << cidade[i].codigo;
        cout << "\tNome: " << cidade[i].nome;
        cout << "\tUF: " << cidade[i].uf;
        buscaAleatoriaPais(paises, indicesPaises, indexPais, cidade[i].codigo_pais);
        return false;
    } else cout << "Cidade nao Encontrada!\n";
    return true;
}

bool buscaAleatoriaGuia (struct Guia *guia, struct Index_Guia *indicesGuia, int &cont, int cod){
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
        cout << "\nCodigo do Guia: " << guia[i].codigo;
        cout << "\tNome: " << guia[i].nome;
        cout << "\tEndereço: " << guia[i].endereco;
        cout << "\tTelefone: " << guia[i].telefone;
        cout << "\tCodCidade: " << guia[i].codigo_cidade << endl;
        return false;
    } else cout << "Guia nao Encontrada!\n";
    return true;
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
    // inclusao do novo registro na area de dados
    guia[cont].codigo = cod;
    cout << "Nome: ";
    cin >> guia[cont].nome;
    cout << "Endereco: ";
    cin >> guia[cont].endereco;
    cout << "Telefone: ";
    cin >> guia[cont].telefone;
    cout << "Codigo Cidade: ";
    cin >> guia[cont].codigo_cidade;
    for(;buscaAleatoriaCidade(cidades, indicesCidade, paises, indicesPais, indexCidade,
                              indexPais, guia[cont].codigo_cidade);) {
        cout << "\nInforme outro codigo da Cidade: "; cin >> guia[cont].codigo_cidade;
    }
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
        cout << "O que deseja fazer?\n-> Ler dados - 0\n-> Imprimir Dados - 1\n";
        cin >> i;
        if(i == 0) {
            cout << "Deseja fazer qual leitura?\n-> Pais - 0\n-> Cidade - 1\n-> Incluir Um Guia - 2\n";
            cin >> i;
            if(i == 0) {
                lerPais(paises, indicesPaises, index_pais);
            } else if(i == 1) {
                lerCidade(cidades, indicesCidades, paises, indicesPaises, index_cidade, index_pais);
            } else if(i == 2) {
                if(index_cidade > 0) {
                    cout << "Informe o codigo do Guia: "; cin >> i;
                    if(buscaAleatoriaGuia(guias, indicesGuias, index_guia, i)) {
                        inclusaoGuia(indicesGuias, guias,
                                     indicesCidades, cidades,
                                     indicesPaises, paises,
                                     index_guia, index_cidade, index_pais, i);
                    }
                } else cout << "Insira pelo menos uma cidade!\n";
                system("pause");
                system("cls");
            }
        } else if(i == 1) {
            cout << "O que deseja fazer?\n-> Ler dados - 0\n-> Imprimir Dados - 1\n";
            cin >> i;
        }
    }


    return 0;
}
