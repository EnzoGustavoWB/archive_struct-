#include <iostream>
#include <string.h>
#include <fstream> // salvar em arquivo
using namespace std;

// Estrutura de produto
struct produto {
    int quantidade, codigo;
    char nome[50];
    float valor;
};

// Cadastra um novo produto
void cadastrarProduto(produto lista[], int &qtd)
{
    cout << "Digite o nome do produto: ";
    cin >> lista[qtd].nome;

    cout << "Digite o codigo do produto: ";
    cin >> lista[qtd].codigo;

    cout << "Digite a quantidade do produto: ";
    cin >> lista[qtd].quantidade;

    cout << "Digite o valor do produto: ";
    cin >> lista[qtd].valor;

    qtd++; // aumenta total cadastrado
}

// Lista todos os produtos
void listarProduto(produto lista[], int qtd)
{
    if (qtd == 0) {
        cout << "Nenhum produto cadastrado!\n" << endl;
       
        return;
    }

    cout << "\n---- LISTA DE PRODUTOS ----\n" << endl;
    for (int i = 0; i < qtd; i++) {
        cout << "Codigo: " << lista[i].codigo << endl;
        cout << "Nome: " << lista[i].nome << endl;
        cout << "Quantidade: " << lista[i].quantidade << endl;
        cout << "Valor: R$ " << lista[i].valor << endl;
        cout << "----------------------------\n" << endl;;
    }
}

// Busca produto pelo código
void buscarProduto(produto lista[], int qtd)
{
    int codigo;
    cout << "Digite o codigo do produto que deseja buscar: " << endl;
    cin >> codigo;

    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo == codigo) {
            cout << "\nProduto encontrado:\n" << endl;
            cout << "Codigo: " << lista[i].codigo << endl;
            cout << "Nome: " << lista[i].nome << endl;
            cout << "Quantidade: " << lista[i].quantidade << endl;
            cout << "Valor: R$ " << lista[i].valor << endl;
           
            return;
        }
    }

    cout << "Produto NAO encontrado!\n" << endl;
}

// Exclui produto pelo código
void excluirProduto(produto lista[], int &qtd)
{
    if (qtd == 0) {
        cout << "Nenhum produto para excluir!\n" << endl;
        
        return;
    }

    int codigo;
    cout << "Digite o codigo do produto que deseja excluir: " << endl;
    cin >> codigo;

    int pos = -1;

    // procura posição
    for (int i = 0; i < qtd; i++) {
        if (lista[i].codigo == codigo) {
            pos = i;
           
            break;
        }
    }

    if (pos == -1) {
        cout << "Produto nao encontrado!\n" << endl;
        return;
    }

    // desloca os itens
    for (int i = pos; i < qtd - 1; i++) {
        lista[i] = lista[i + 1];
    }

    qtd--; // reduz total
    cout << "Produto removido com sucesso!\n" << endl;
}

// Salva produtos em arquivo
void salvarEmArquivo(produto lista[], int qtd)
{
    ofstream arquivo("produtos.txt");

    if (!arquivo) {
        cout << "Erro ao abrir arquivo!\n" << endl;
        return;
    }

    for (int i = 0; i < qtd; i++) {
        arquivo << lista[i].codigo << " "
                << lista[i].nome << " "
                << lista[i].quantidade << " "
                << lista[i].valor << endl;
    }

    arquivo.close();
    cout << "Produtos salvos com sucesso!\n" << endl;
}

int main()
{
    produto lista[100]; // armazenamento
    int qtd = 0;        // total cadastrado
    int opcao;

    do {
        cout << "\n===== MENU =====\n" << endl;
        cout << "1 - Cadastrar produto\n" << endl;
        cout << "2 - Listar produtos\n" << endl;
        cout << "3 - Buscar produto\n" << endl;
        cout << "4 - Excluir produto\n" << endl;
        cout << "5 - Salvar em arquivo\n" << endl;
        cout << "0 - Sair\n" << endl;
        cout << "Escolha uma opcao: " << endl;
        cin >> opcao;

        switch(opcao) {
            case 1: cadastrarProduto(lista, qtd); break;
            case 2: listarProduto(lista, qtd); break;
            case 3: buscarProduto(lista, qtd); break;
            case 4: excluirProduto(lista, qtd); break;
            case 5: salvarEmArquivo(lista, qtd); break;
            case 0: cout << "Saindo...\n" << endl; break;
            default: cout << "Opcao invalida!\n" << endl;
        }

    } while (opcao != 0);

    return 0;
}
