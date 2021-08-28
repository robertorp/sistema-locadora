#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <iostream>

////////// PROTÓTIPO DE MENU PRINCIPAL /////////////////////////////////////////////////////////////
char menuPrincipal(void); // Chama menu principal.
char menuCadastro(void); // Chama menu de cadastro.
char menuRelatorios(void); // Chama menu de relatorios.
void menuLocadora(void); // Recebe menus e sub menus.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPO DE ABRIR ARQUIVO //////////////////////////////////////////////////////////////
FILE * fAbreArquivo(char); // Função para ler, abrir, e sobre escrever o arquivo.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPOS CLIENTE //////////////////////////////////////////////////////////////////////
void getCliente(void); // Cadastro de clientes.
void listaCadastroCliente(void); // Lista o cadastro de cliente.
void buscaClienteNome(void); // Pesquisa de cliente por nome.
int consultarClienteCodigo(void); // Pesquisa de cliente por código.
void alterarCliente(void); // Alterar um determinado cadastro de cliente.
void excluirCliente(void); // Excluir um determinado cadastro de cliente.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPOS FILME ////////////////////////////////////////////////////////////////////////
void getFilme(void); // Cadastra um filme.
void listaCadastroFilme(void); // Lista o todos filmes.
void buscaFilmeNome(void); // Pesquisa um filme pelo nome.
int consultarFilmeCodigo(void); // Pesquisa um filme pelo código.
void alterarVideo(void); // Altera filmes.
void excluirFilme(void); // Exclui filmes.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPO LOCAÇÃO DE FILME //////////////////////////////////////////////////////////////
void locacaoFilme(void); // Faz a locação de filmes.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPO DE DEVOLUÇÃO DE FILME /////////////////////////////////////////////////////////
void devolucaoFilme(void); // Faz a devolução de filmes.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPO IMPRIME FILMES LOCADOS ////////////////////////////////////////////////////////
void imprimeFilmesLocados(void); // Imprime todos filmes que estão locados.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPO IMPRIMIR LOCAÇÕES EFETUADAS POR UM DADO CLIENTE ///////////////////////////////
void imprimirLocacoesPorUmDadoCliente(void); // Imprime locações efetuadas por um dado cliente.
////////////////////////////////////////////////////////////////////////////////////////////////////


////////// PROTÓTIPO IMPRIMIR DEVOLUÇÕES EFETUADAS POR UM DADO CLIENTE /////////////////////////////
void imprimirDevolucoesPorUmDadoCliente(void); // Imprime devoluções efetuadas por um dado cliente.
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// PROTÓTIPO AUXILIAR TRABALHO /////////////////////////////////////////////////////////////
void gotoxy(short, short); // Posiciona o cursor do console nas coordenadas coluna x e linha y.
void limpaTela(void); // Limpa a tela do console e posiciona o cursor na coluna 0 linha 0.
void achouu(int); // Verifica se achou algum registro, se não achar então ele imprime resposta.
int listagemDiretaOuPartes(void); // Pergunta ao usuário se ele quer fazer uma listagem direta ou por partes.
////////////////////////////////////////////////////////////////////////////////////////////////////
int buscaCodigoGeral(int, int);

////////// MENU PRINCIPAL //////////////////////////////////////////////////////////////////////////
int main(void)
{
    system("title SysLoc");
    menuLocadora();
    return(0);
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// MENU LOCADORA ///////////////////////////////////////////////////////////////////////////
void menuLocadora(void)
{
    char opcao; // Recebe menu principal.
    char opcao2; // Recebe sub-menus.
    char opcao3; // Variável para controle de limpatela.
    const char ESC = 27; // Constante da tecla ESC.

    do
    {
    opcao = menuPrincipal();

        switch(opcao)
        {
            case 'f': // MENU FILME
                     do // Inicio do laço filme.
                     {
                         opcao2 = menuCadastro(); // Recebe variável do menu cadastro.
                         switch(opcao2)
                         {
                             case 'i': getFilme(); break;
                             case 'a': alterarVideo(); break;
                             case 'e': excluirFilme(); break;
                             case 'c': buscaFilmeNome(); break;
                             case 'l': listaCadastroFilme(); break;
                         }
                     printf("\nENTER volta MENU FILME\\ESC para MENU PRINCIPAL");
                     opcao3 = getch();
                        limpaTela();
                     }while(opcao3 != ESC); // Fim do laço filme
            break;
            case 'c': // MENU CLIENTE
                     do // Inicio do laço cliente.
                     {
                     opcao2 = menuCadastro(); // Recebe variável do menu de cadastro.
                        switch(opcao2)
                        {
                            case 'i': getCliente(); break;
                            case 'a': alterarCliente(); break;
                            case 'e': excluirCliente(); break;
                            case 'c': buscaClienteNome(); break;
                            case 'l': listaCadastroCliente(); break;
                        }
                        printf("\nENTER volta MENU FILME\\ESC para MENU PRINCIPAL");
                        opcao3 = getch();
                            limpaTela();
                     }while(opcao3 != ESC); // Fim do laço cliente.

            break;
            case 'l': locacaoFilme(); break; // MENU LOCAÇÃO
            case 'd': devolucaoFilme(); break; // MENU DEVOLUÇÃO
            case 'r': // MENU RELATÓRIOS
                     do // Inicio do laço relatórios.
                     {
                         opcao2 = menuRelatorios(); // Recebe variável do menu de relatorios.
                         switch(opcao2)
                         {
                             case 'f': imprimeFilmesLocados(); break;
                             case 'l': imprimirLocacoesPorUmDadoCliente(); break;
                             case 'd': imprimirDevolucoesPorUmDadoCliente(); break;
                         }
                         printf("\nENTER volta MENU RELATORIOS\\ESC para MENU PRINCIPAL");
                         opcao3 = getch(); // Espera comando do usuário
                             limpaTela(); // limpa tela.
                     }while(opcao3 != ESC); // Fim do laço relatorios.
            break;
            case 's': exit(0); break; // SAI DO PROGRAMA.
        }
        printf("\nENTER PARA MENU PRINCIPAL\\ESC para SAIR DO PROGRAMA");
    }while(getch() != ESC);
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// MENU PRINCIPAL //////////////////////////////////////////////////////////////////////////
char menuPrincipal(void)
{
    limpaTela(); // Inicia limpando tela.
    HANDLE hConsole; // Auxiliar em mudança de cores.
    int opcao; // Recebe teclas.
    char menu; // Recebe variável para entrar em outros menus.
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Auxiliar em mudança de cores.


    // MENU FILME
    SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); // Muda cor para verde.
    gotoxy(33, 5); printf("FILMES");
    SetConsoleTextAttribute(hConsole, 7); // Daqui para baixo todos com cores originais do console.
    gotoxy(33, 7); printf("CLIENTE");
    gotoxy(33, 9); printf("LOCACAO DE FILMES");
    gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
    gotoxy(33, 13); printf("RELATORIOS");
    gotoxy(33, 15); printf("SAIR");
    gotoxy(20, 22); printf("Filmes...................");
    menu = 'f'; // Variável menu recebe f.

        do // Inicio do laço MENU PRINCIPAL
        {
            if(menu == 'f')
            {
                opcao = getch();
                switch(opcao)
                {
                    case 80: // MENU CLIENTE
                            gotoxy(33, 5); printf("FILMES");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); 
                            gotoxy(33, 7); printf("CLIENTE");
                            SetConsoleTextAttribute(hConsole, 7); 
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");
                            gotoxy(20, 22); printf("Cliente..................");
                            menu = 'c';
                    break;

                    case 72: // MENU SAIR
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 15); printf("SAIR");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(20, 22); printf("SAIR.....................");
                            menu = 's';
                    break;
                }
            }


            if(menu == 'c')
            {
                opcao = getch();
                switch(opcao)
                {
                    case 80: // MENU LOCACAO DE FILMES
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");

                            gotoxy(20, 22); printf("Locacao de Filmes........");
                            menu = 'l';
                    break;



                    case 72: // MENU FILMES
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 5); printf("FILMES");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");

                            gotoxy(20, 22); printf("Filmes...................");
                            menu = 'f';
                    break;
                }
            }

            if(menu == 'l')
            {
                opcao = getch();
                switch(opcao)
                {
                    case 80: // MENU DEVOLUÇÃO DE FILMES
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");

                            gotoxy(20, 22); printf("Devolucao de filme.......");
                            menu = 'd';
                    break;

                    case 72: // MENU CLIENTE
                            gotoxy(33, 5); printf("FILMES");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 7); printf("CLIENTE");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");

                            gotoxy(20, 22); printf("Cliente..................");
                            menu = 'c';
                    break;
                }
            }

            if(menu == 'd')
            {
                opcao = getch();
                switch(opcao)
                {
                    case 80: // MENU RELATORIOS
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 13); printf("RELATORIOS");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 15); printf("SAIR");

                            gotoxy(20, 22); printf("Relatorios...............");
                            menu = 'r';
                    break;

                    case 72: //MENU LOCACAO DE FILMES
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");

                            gotoxy(20, 22); printf("Locacao de Filmes........");
                            menu = 'l';
                    break;
                }
            }

            if(menu == 'r')
            {
                opcao = getch();
                switch(opcao)
                {
                    case 80: // MENU SAIR
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 15); printf("SAIR");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(20, 22); printf("SAIR.....................");
                            menu = 's';
                    break;

                    case 72: // MENU DEVOLUÇÃO DE FILMES
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");
                            gotoxy(20, 22); printf("Devolucao de filme.......");
                            menu = 'd';
                }
            }


            if(menu == 's')
            {
                opcao = getch();
                switch(opcao)
                {
                    case 80: // MENU FILMES
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 5); printf("FILMES");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            gotoxy(33, 13); printf("RELATORIOS");
                            gotoxy(33, 15); printf("SAIR");
                            gotoxy(20, 22); printf("Filmes...................");
                            menu = 'f';
                    break;

                    case 72: // MENU RELATORIOS
                            gotoxy(33, 5); printf("FILMES");
                            gotoxy(33, 7); printf("CLIENTE");
                            gotoxy(33, 9); printf("LOCACAO DE FILMES");
                            gotoxy(33, 11); printf("DEVOLUCAO DE FILMES");
                            SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                            gotoxy(33, 13); printf("RELATORIOS");
                            SetConsoleTextAttribute(hConsole, 7);
                            gotoxy(33, 15); printf("SAIR");
                            gotoxy(20, 22); printf("Relatorio................");
                            menu = 'r';
                    break;
                }
            }
            // TECLE ENTER PARA SAIR.
        }while(opcao != 13); // Fim laço MENU PRINCIPAL

                     // LIMPAR O VERDE DA TELA
        gotoxy(33,5);
        printf("                    ");
        gotoxy(33,7);
        printf("                    ");
        gotoxy(33,9);
        printf("                    ");
        gotoxy(33,11);
        printf("                    ");
        gotoxy(33,13);
        printf("                    ");
        gotoxy(33,15);
        printf("                    ");
        gotoxy(20,22);
        printf("                                                          ");

        return(menu); // Retorna valor.
}
///////////////////////////////////////////////////////////////////////////////////////////////////



////////// SUB MENU DE CADASTROS //////////////////////////////////////////////////////////////////
char menuCadastro(void)
{
    limpaTela(); // Limpa tela.
    HANDLE hConsole; // Auxiliar em mudança de cores.
    int opcao; // Recebe teclas.
    char menu; // Recebe variável para executar funções.

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Auxiliar em mudança de cores.

    // MENU INCLUIR
    SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); // Muda cor para verde.
    gotoxy(0,0); printf("Incluir");
    SetConsoleTextAttribute(hConsole, 7); // Todos daqui para baixo com cores originais do console.
    gotoxy(0,2); printf("Alterar");
    gotoxy(0,4); printf("Excluir");
    gotoxy(0,6); printf("Consultar");
    gotoxy(0,8); printf("Listar");
    menu = 'i'; // Variável recebe valor para execução da função.

    do // Inicio do laço MENU CADASTRO.
    {
        if(menu == 'i')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU ALTERAR
                        gotoxy(0,0); printf("Incluir");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,2); printf("Alterar");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,4); printf("Excluir");
                        gotoxy(0,6); printf("Consultar");
                        gotoxy(0,8); printf("Listar");
                        menu = 'a';
                break;

                case 72: // MENU LISTAR
                        gotoxy(0,0); printf("Incluir");
                        gotoxy(0,2); printf("Alterar");
                        gotoxy(0,4); printf("Excluir");
                        gotoxy(0,6); printf("Consultar");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,8); printf("Listar");
                        SetConsoleTextAttribute(hConsole, 7);
                        menu = 'l';
                break;
            }
        }

        if(menu == 'a')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU EXCLUIR
                        gotoxy(0,0); printf("Incluir");
                        gotoxy(0,2); printf("Alterar");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,4); printf("Excluir");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,6); printf("Consultar");
                        gotoxy(0,8); printf("Listar");
                        menu = 'e';
                break;

                case 72: // MENU INCLUIR
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,0); printf("Incluir");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,2); printf("Alterar");
                        gotoxy(0,4); printf("Excluir");
                        gotoxy(0,6); printf("Consultar");
                        gotoxy(0,8); printf("Listar");
                        menu = 'i';
                break;
            }
        }

        if(menu == 'e')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU CONSULTAR
                        gotoxy(0,0); printf("Incluir");
                        gotoxy(0,2); printf("Alterar");
                        gotoxy(0,4); printf("Excluir");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,6); printf("Consultar");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,8); printf("Listar");
                        menu = 'c';
                break;

                case 72: // MENU ALTERAR
                        gotoxy(0,0); printf("Incluir");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,2); printf("Alterar");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,4); printf("Excluir");
                        gotoxy(0,6); printf("Consultar");
                        gotoxy(0,8); printf("Listar");
                        menu = 'a';
                break;
            }
        }

        if(menu == 'c')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU LISTAR
                        gotoxy(0,0); printf("Incluir");
                        gotoxy(0,2); printf("Alterar");
                        gotoxy(0,4); printf("Excluir");
                        gotoxy(0,6); printf("Consultar");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,8); printf("Listar");
                        SetConsoleTextAttribute(hConsole, 7);
                        menu = 'l';
                break;

                case 72: // MENU EXCLUIR
                        gotoxy(0,0); printf("Incluir");
                        gotoxy(0,2); printf("Alterar");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,4); printf("Excluir");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,6); printf("Consultar");
                        gotoxy(0,8); printf("Listar");
                        menu = 'e';
                break;
            }
        }

        if(menu == 'l')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU INCLUIR
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,0); printf("Incluir");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,2); printf("Alterar");
                        gotoxy(0,4); printf("Excluir");
                        gotoxy(0,6); printf("Consultar");
                        gotoxy(0,8); printf("Listar");
                        menu = 'i';
                break;

                case 72: // MENU CONSULTAR
                        gotoxy(0,0); printf("Incluir");
                        gotoxy(0,2); printf("Alterar");
                        gotoxy(0,4); printf("Excluir");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,6); printf("Consultar");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,8); printf("Listar");
                        menu = 'c';
                break;
            }
        }

    }while(opcao != 13); // Fim laço MENU CADASTRO.
    // LIMPAR O VERDE DA TELA.
    gotoxy(0,0);
    printf("                 ");
    gotoxy(0,2);
    printf("                 ");
    gotoxy(0,4);
    printf("                 ");
    gotoxy(0,6);
    printf("                 ");
    gotoxy(0,8);
    printf("                 ");

    return(menu); // Retorna valor.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// MENU RELATÓRIOS /////////////////////////////////////////////////////////////////////////
char menuRelatorios(void)
{
    int opcao; // Recebe teclas.
    char menu; // Recebe variável para executar funções.
    HANDLE hConsole; // Auxiliar em mudança de cores.

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE); // Auxiliar em mudança de cores.
    // MENU FILMES LOCADOS
    SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN); // Muda cor para verde.
    gotoxy(0,0); printf("Filmes Locados");
    SetConsoleTextAttribute(hConsole, 7); // Todos daqui para baixo com cores originais do console.
    gotoxy(0,1); printf("Locacoes de um cliente");
    gotoxy(0,2); printf("Devolucoes de um cliente");
    menu = 'f'; // Recebe variável.

    do // Inicio do laço MENU RELATÓRIOS
    {
        if(menu == 'f')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU LOCAÇÕES DE UM CLIENTE
                        gotoxy(0,0); printf("Filmes Locados");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,1); printf("Locacoes de um cliente");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,2); printf("Devolucoes de um cliente");
                        menu = 'l';
                break;

                case 72: // MENU DEVOLUÇÕES DE UM CLIENTE
                        gotoxy(0,0); printf("Filmes Locados");
                        gotoxy(0,1); printf("Locacoes de um cliente");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,2); printf("Devolucoes de um cliente");
                        SetConsoleTextAttribute(hConsole, 7);
                        menu = 'd';
                break;
            }
        }

        if(menu == 'l')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU DEVOLUÇÕES DE UM CLIENTE
                        gotoxy(0,0); printf("Filmes Locados");
                        gotoxy(0,1); printf("Locacoes de um cliente");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,2); printf("Devolucoes de um cliente");
                        SetConsoleTextAttribute(hConsole, 7);
                        menu = 'd';
                break;

                case 72: // MENU FILMES LOCADOS
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,0); printf("Filmes Locados");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,1); printf("Locacoes de um cliente");
                        gotoxy(0,2); printf("Devolucoes de um cliente");
                        menu = 'f';
                break;

            }
        }

        if(menu == 'd')
        {
            opcao = getch();

            switch(opcao)
            {
                case 80: // MENU FILMES LOCADOS
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,0); printf("Filmes Locados");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,1); printf("Locacoes de um cliente");
                        gotoxy(0,2); printf("Devolucoes de um cliente");
                        menu = 'f';
                break;

                case 72: // MENU LOCAÇÕES DE UM CLIENTE
                        gotoxy(0,0); printf("Filmes Locados");
                        SetConsoleTextAttribute(hConsole, BACKGROUND_GREEN);
                        gotoxy(0,1); printf("Locacoes de um cliente");
                        SetConsoleTextAttribute(hConsole, 7);
                        gotoxy(0,2); printf("Devolucoes de um cliente");
                        menu = 'l';
                break;
            }
        }

    }while(opcao != 13); // Fim do laço MENU RELATÓRIOS.
    // LIMPAR O VERDE DA TELA
    gotoxy(0,0); printf("                                    ");
    gotoxy(0,1); printf("                                    ");
    gotoxy(0,2); printf("                                    ");

    return(menu); // Retorna valor.
}
////////////////////////////////////////////////////////////////////////////////////////////////////
////////// FUNÇÃO ABRE ARQUIVO SE NÃO TIVER ENTÃO CRIA ARQUIVO E LE ////////////////////////////////
FILE * fAbreArquivo(char * cArquivo)
{
    FILE * ponteiro; // Cria ponteiro

    ponteiro = fopen(cArquivo, "rb+"); // Abre arquivo.

    if(ponteiro == NULL) // Se estiver NULL.
        ponteiro = fopen(cArquivo, "wb"); // Cria arquivo.
    fclose(ponteiro); // Fecha ponteiro.

    ponteiro = fopen(cArquivo, "rb+"); // Abre arquivo.

    return ponteiro; // Retorna valor.
}
//////////////////////////////////////////////////////////////////////////////////////////////////////



////////// TIPO DE DADO CLIENTE ////////////////////////////////////////////////////////////////////
typedef struct cliente
{
    int codigoCliente; // Variável para receber o código do cliente.
    char nomeCliente[50]; // Variável para receber o nome do cliente.
    int excluir; // Statos se esta excluido ou não esta excluido.
    char cpf[11];
    int rg;
    int cep;
    char rua[50];
    char cidade[50];
} cliente;
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// DEFINE TAMANHO DA STRUCK EM BYTES ///////////////////////////////////////////////////////
#define TAMCLIENTE sizeof(struct cliente)
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// FUNÇÃO CADASTRA CLIENTE /////////////////////////////////////////////////////////////////
void getCliente(void)
{
    limpaTela(); // Limpa tela.

    char resposta = 's'; // Resposta recebe valor s.
    cliente cadastroCliente; // Tipo de dado 'cliente'.
    FILE * ponteiro; // Cria ponteiro.

    while(resposta == 's' || resposta == 'S') // Se sim então continua cadastrando cliente.
    {
        ponteiro = fAbreArquivo("CADCLI.DAT"); // Abre arquivo 'CADCLI.DAT'.
        if(ponteiro == NULL) // Verifica se ponteiro criou arquivo.
            exit(0);

        fseek(ponteiro, -1 * TAMCLIENTE, SEEK_END); // Posiciona ponteiro. 
        fread(&cadastroCliente, TAMCLIENTE, 1, ponteiro); // Ler linha arquivo do endereço em que 'ponteiro' se encontra.
        cadastroCliente.codigoCliente = (feof(ponteiro) ? 1 : cadastroCliente.codigoCliente +1); // if else, para adicionar código ao registro.

        // Cadastro de cliente.
        gotoxy(31,0);
        printf("CADASTRO DE CLIENTE\n");
        printf("================================================================================");
        printf("Codigo: %d", cadastroCliente.codigoCliente); // Recebe código e imprime na tela.
        rewind(stdin); // Limpa buffer do teclado.
        gotoxy(0,3); 
        printf("Nome do Cliente: ");
        gotoxy(0,5); 
        printf("CPF: ");
        gotoxy(25,5); 
        printf("RG: ");
        gotoxy(0,7);
        printf("Cidade: ");
        gotoxy(25,7);
        printf("CEP: ");
        gotoxy(0,9);
        printf("Rua/Numero/Complemento: ");
        printf("\n================================================================================");

        
        gotoxy(17,3);
        gets(cadastroCliente.nomeCliente); // Recebe nome do cliente.
        
        rewind(stdin);
        gotoxy(5,5);
        gets(cadastroCliente.cpf); // Recebe cpf do cliente.
        
        gotoxy(29,5);
        scanf("%d", &cadastroCliente.rg); // Recebe RG do cliente.
        
        rewind(stdin); // Limpa buffer do teclado.
        gotoxy(8,7);
        gets(cadastroCliente.cidade); // Recebe cidade do cliente.
        
        gotoxy(29,7);
        scanf("%d", &cadastroCliente.cep);
        
        rewind(stdin); // Limpa buffer do teclado.
        gotoxy(24,9);
        gets(cadastroCliente.rua);
        
        cadastroCliente.excluir = 0;

        fseek(ponteiro, 0L, SEEK_END); // Empurra ponteiro para o descritor, para adicionarmos um novo registro.
        fwrite(&cadastroCliente, TAMCLIENTE, 1, ponteiro); // Grava dados no arquivo.
        fclose(ponteiro); // Fecha ponteiro.

        printf("\n\nRegistro Gravado.");
        printf("\nContinuar...(s/n)");
            resposta = getch();
        if(resposta == 's' || resposta == 'S') // Se 's' ou 'S' então limpa a tela e continua a cadastrar.
            limpaTela(); // Limpa tela.
        printf("\n");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// FUNÇÃO PARA MOSTRAR UMA LISTA DE CADASTRO DE CLIENTE ////////////////////////////////////
void listaCadastroCliente(void)
{
    FILE * ponteiro; // Cria variável tipo FILE.
    cliente listaCliente; // Cria variável do tipo cliente (struck cliente).
    int qtd = 0; // Quantidade recebe 0, para paginação de cadastro.
    int paraListagem = 0; // Recebe 0; Se 1 para paginação de cadastro.

    paraListagem = listagemDiretaOuPartes(); // Função de Menu de escolha se quer paginar ou não.

    ponteiro = fAbreArquivo("CADCLI.DAT"); // Abre arquivo CADCLI.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
        exit(0); // Sai do programa

    printf("\n\n    LISTA DE CADASTRO DE CLIENTE\n");
    printf("------------------------------------\n");

    while(!feof(ponteiro)) // Enquanto ponteiro não chega ao final, não para.
    {
        fread(&listaCliente, TAMCLIENTE, 1, ponteiro); // Lê arquivo, CLIENTE.DAT.

        if(!feof(ponteiro) && listaCliente.excluir == 0) // Enquanto ponteiro não chega ao final, não para, e listaCliente.excluir == 0.
        {
            printf("\nCodigo: %d", listaCliente.codigoCliente); // Imprime código.
            printf("\nNome: %s", listaCliente.nomeCliente); // Imprime nome do cliente.
            printf("\nCPF: %s", listaCliente.cpf); // Imprime cpf do cliente.
            printf("\nRG: %d", listaCliente.rg); // Imprime rg do cliente.
            printf("\nCidade: %s", listaCliente.cidade); // Imprime cidade do cliente.
            printf("\nCEP: %d", listaCliente.cep); // Imprime cep da cidade do cliente.
            printf("\nRua/Numero/Complemento: %s\n", listaCliente.rua); // Imprime endereço do cliente.
            qtd++;
            if(qtd > 4 && paraListagem == 1)
            {
                getch(); // Para loop ate que aperte alguma tecla.
                qtd = 0; // Apos listagem quantidade recebe 0 novamente.
            }
        }
    }
    fclose(ponteiro); // Fecha ponteiro.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// BUSCA POR NOME //////////////////////////////////////////////////////////////////////////
void buscaClienteNome(void)
{
    limpaTela(); // Limpa tela.
    FILE * ponteiro; // Cria ponteiro para arquivo.
    cliente buscaCliente; // Variável do tipo cliente(struct).
    int achou = 0; // Achou recebe 0.
    int temp; // Recebe tamanho da string(Nome do cliente) digitada pelo usuário.
    char nomeCliente[50]; // Recebe nome digitado pelo usuário que deseja buscar.
    char comparanome[50]; // Recebe nome do arquivo CLIENTE.DAT.


    rewind(stdin); // Limpa buffer do teclado.
    printf("Nome cliente: ");
    gets(nomeCliente); // Recebe nome digitado pelo usúario.

    temp = strlen(nomeCliente); // Captura tamanho da string(Nome digitado pelo usuário).

    ponteiro = fAbreArquivo("CADCLI.DAT"); // Abre arquivo CADCLI.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
        exit(0); // Sai do programa.

    printf("\n\n     CADASTRO BUSCADO\n");

    while(!feof(ponteiro)) // Enquanto ponteiro não chega ao fim do arquivo CADCLI.DAT não para.
    {
        fread(&buscaCliente, TAMCLIENTE, 1, ponteiro); // Lê um registro do CADCLI.DAT.
        strncpy(comparanome, buscaCliente.nomeCliente, temp); // Copia nome do arquivo CADCLI.DAT para variável comparanome.

        if(!feof(ponteiro) && buscaCliente.excluir == 0) // Se ponteiro não chegou ao fim e buscaCliente.statos é diferende de zero então entra.

                if(strnicmp(nomeCliente, comparanome, temp) == 0) // Se nomes forem iguais a 0 então imprime.
                {
                    printf("------------------------------------\n");
                    printf("\nCodigo: %d", buscaCliente.codigoCliente);
                    printf("\nNome: %s", buscaCliente.nomeCliente);
                    printf("\nCPF: %s", buscaCliente.cpf);
                    printf("\nRG: %d", buscaCliente.rg);
                    printf("\nCidade: %s", buscaCliente.cidade);
                    printf("\nCEP: %d", buscaCliente.cep);
                    printf("\nRua/Numero/Complemento: %s\n", buscaCliente.rua);
                    printf("------------------------------------\n");
                    achou = 1; // Se for igual a 0 e porque não achou registro.
                }

    }
    fclose(ponteiro); // Fecha ponteiro.
    achouu(achou); // Se achou for igual a 0 então imprime mensagem.
    getch(); 
    limpaTela(); // Limpa tela.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// BUSCA POR CÓDIGO ////////////////////////////////////////////////////////////////////////
int consultarClienteCodigo(void)
{
    FILE * ponteiro; // Cria variável tipo FILE.
    cliente consultaCliente; // Cria variável do tipo filme(struck filme).
    int achou = 0; // Achou recebe 0.
    int posicao = 0; // Posicao recebe 0.
    int codigoCliente = 0; // Código do cliente recebe 0.

    printf("Codigo cliente: "); 
    scanf("%d", &codigoCliente); // Lê código digitado pelo usuário.

    ponteiro = fAbreArquivo("CADCLI.DAT"); // Abre arquivo CADCLI.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
        exit(0); // Sai do programa.



    while(!feof(ponteiro) && (achou == 0)) // Enquanto ponteiro não chegar ao final e achou for igual a 0 então não para.
    {
        fread(&consultaCliente, TAMCLIENTE, 1, ponteiro); // Lê arquivo CLIENTE.DAT.

        if(!feof(ponteiro)) // Enquanto ponteiro não chegar ao final não para.
        {
            if(codigoCliente == consultaCliente.codigoCliente) // Se codigo digitado pelo usuário for igual ao do arquivo então entra.
            {
                if(consultaCliente.excluir == 1) // Se excluir for igual a um então arquivo esta excluido.
                    posicao = -2; // Posicão recebe -2.
                achou = 1; // Achou recebe 1.
            }
            else
                posicao++; // Enquanto não achar cliente então acrescenta mais um em posicão.
        }
        else
            posicao = -1; // Ponteiro chegou no final do arquivo e não achou nada.
    }

    achouu(achou); // Entra se achou for igual a 0 e imprime mensagem.

    fclose(ponteiro); // Fecha ponteiro.
    limpaTela(); // Limpa tela.
    return(posicao); // Retorna posição do cadastro do cliente buscado.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// ALTERAR CLIENTE /////////////////////////////////////////////////////////////////////////
void alterarCliente(void)
{
    limpaTela(); // Limpa tela.
    char resposta = 's'; // Resposta recebe 's'.
    int posicao = 0; // Posição recebe 0.
    cliente alterarCliente; // Variável tipo cliente.
    FILE * ponteiro; // Cria variável tipo file para arquivo(ponteiro).

    buscaClienteNome(); // Chama função.
    posicao = consultarClienteCodigo(); // Chama função e retorna valor da posição.

    if(posicao == -1 || posicao == -2) // Se for posição igual a -1 ou -2 então não executa nada.
        getch(); // Esperando teclar qualquer tecla para sair.
    else // Se não for -1 ou -2 entra.
    {
        ponteiro = fAbreArquivo("CADCLI.DAT"); // Abre arquivo CADCLI.DAT.
        if(ponteiro == NULL) // Se ponteiro for igual a NULL(VAZIO).
            exit(0); // Fecha programa.

        fseek(ponteiro, posicao * TAMCLIENTE, SEEK_CUR); // Posiciona ponteiro de acordo com valor retornado pela busca por código.
        fread(&alterarCliente, TAMCLIENTE, 1, ponteiro); // Lê arquivo CADCLI.DAT.

        printf("Registro buscado...\n");
        gotoxy(0,2); 
        printf("Codigo: %d", alterarCliente.codigoCliente);
        gotoxy(0,3);
        printf("Nome: %s", alterarCliente.nomeCliente);
        gotoxy(0,5);
        printf("CPF: %s", alterarCliente.cpf);
        gotoxy(25,5);
        printf("RG: %d", alterarCliente.rg);
        gotoxy(0,7);
        printf("Cidade: %s", alterarCliente.cidade);
        gotoxy(25,7);
        printf("CEP: %d", alterarCliente.cep);
        gotoxy(0,9);
        printf("Rua/Numero/Complemento: %s", alterarCliente.rua);
        printf("\n-------------------------------------------------------------------------------\n");
        printf("Deseja alterar o registro(s/n)"); // Pergunta se deseja continuar gravando mais registros.
        resposta = getch(); // Espera resposta do usuário.

        while(resposta == 's' || resposta == 'S') // Se resposta for 's' ou 'S' então salva arquivo.
        {
            gotoxy(0,12);           
            printf("Codigo: %d", alterarCliente.codigoCliente); // Recebe código e imprime na tela.
            
            gotoxy(0,13);
            printf("Nome do cliente: ");
            
            gotoxy(0,15);
            printf("CPF: ");
            
            gotoxy(25,15);
            printf("RG: ");
            
            gotoxy(0,17);
            printf("Cidade: ");
            
            gotoxy(25,17);
            printf("CEP: ");
            
            gotoxy(0,19);
            printf("Rua/Numero/Complemento: ");
            /////////////
            rewind(stdin); // Limpa buffer do teclado.
            gotoxy(17,13);
            gets(alterarCliente.nomeCliente); // Recebe novo nome.
            
            rewind(stdin);
            gotoxy(5,15);
            gets(alterarCliente.cpf); // Recebe novo cpf.
            
            gotoxy(29,15);
            scanf("%d", &alterarCliente.rg); // Recebe novo rg.
            
            rewind(stdin); // Limpa buffer do teclado.
            gotoxy(8,17);
            gets(alterarCliente.cidade); // Recebe nova cidade.
            
            gotoxy(30,17);
            scanf("%d", &alterarCliente.cep); // Recebe novo cep.
            
            rewind(stdin); // Limpa buffer do teclado.
            gotoxy(24,19);
            gets(alterarCliente.rua); // Recebe nova rua.
            
            alterarCliente.excluir = 0;

            fseek(ponteiro, posicao * TAMCLIENTE, SEEK_SET); // Posiciona no arquivo determinado para sobreescrever.
            fwrite(&alterarCliente, TAMCLIENTE, 1, ponteiro); // Salva novos dados.
            printf("\nRegravacao feita com sucesso.");
            resposta = 'n'; // Resposta recebe 'n' para sair do laço.
            getch(); // Digite qualquer coisa para finalizar função.
        }
        fclose(ponteiro); // Fecha ponteiro.
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// EXCLUIR CLIENTE /////////////////////////////////////////////////////////////////////////
void excluirCliente(void)
{
    limpaTela(); // Limpa tela.
    char resposta = 's'; // Resposta recebe 's'.
    int posicao = 0; // Posição recebe 0.
    cliente excluiCliente; // Cria variável tipo cliente.
    FILE * ponteiro; // Cria variável tipo file, para arquivo(ponteiro).

    buscaClienteNome(); // Chamada da função.
    posicao = consultarClienteCodigo(); // Chamada da função, retorna posição do dado no arquivo CADCLI.DAT.

    if(posicao == -1 || posicao == -2) // Se posição for -1 ou -2 então, não faz nada.
        getch(); // Esperando usuário teclar qualquer tecla para sair da função.
    else // Se posição for positivo então entra.
    {
        ponteiro = fAbreArquivo("CADCLI.DAT"); // Abre arquivo CADCLI.DAT.
        if(ponteiro == NULL) // Se ponteiro for igual a NULL(VAZIO).
            exit(0); // Sai do programa.

        fseek(ponteiro, posicao * TAMCLIENTE, SEEK_SET); // Posiciona ponteiro para leitura de arquivo CADCLI.DAT.
        fread(&excluiCliente, TAMCLIENTE, 1, ponteiro); // Lê um determinado dado do arquivo CADCLI.DAT.
        // Faz a impressão dos dados.
        printf("Registro buscado...\n");
        printf("-------------------------------------------------------------------------------\n");
        gotoxy(0,2);
        printf("Codigo: %d", excluiCliente.codigoCliente);
        
        gotoxy(0,3);
        printf("Nome: %s", excluiCliente.nomeCliente);
        
        gotoxy(0,5);
        printf("CPF: %s", excluiCliente.cpf);
        
        gotoxy(25,5);
        printf("RG: %d", excluiCliente.rg);
        
        gotoxy(0,7);
        printf("Cidade: %s", excluiCliente.cidade);
        
        gotoxy(25,7);
        printf("CEP: %d", excluiCliente.cep);
        
        gotoxy(0,9);
        printf("Rua/Numero/Complemento: %s", excluiCliente.rua);
        printf("\n-------------------------------------------------------------------------------\n");
        excluiCliente.excluir = 1;

        printf("\nDeseja excluir o registro(s/n)?"); // Pergunta se deseja excluir dado.
        resposta = getch(); // Espera resposta.


        while(resposta == 's' || resposta == 'S') // Se resposta for 's' ou 'S' então exclui dado do arquivo CADCLI.DAT.
        {
            fseek(ponteiro, posicao * TAMCLIENTE, SEEK_SET); // Posiciona ponteiro para regravação de dado.
            fwrite(&excluiCliente, TAMCLIENTE, 1, ponteiro); // Salva novos dados no arquivo CADCLI.DAT.
            printf("\nRegistro excluido com sucesso.");
            resposta = 'n'; // Resposta recebe 'n' para sair do laço.
            getch(); // Tecle qualquer tecla para sair da função.
        }
        fclose(ponteiro); // Fecha ponteiro.
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////




////////// TIPO DE DADO FILME //////////////////////////////////////////////////////////////////////
typedef struct filme
{
    int codigoFilme;      // Codigo do filme.
    char nomeFilme[50];   // Nome do filme.
    char sinopse[120];    // Sinopse do filme.
    char genero[30];      // Genero do filme.
    int tempo;            // Duração do filme (minutos).
    int quantidade;       // Recebe quantidade de copias de filmes.
    float valor;          // Valor do filme (diaria).
    int excluir;          // Statos do filme se esta excluido ou não.
    int locado;           // Statos do filme se esta locado ou não.
} filme;
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// DEFINE TAMANHO DA STRUCK EM BYTES ///////////////////////////////////////////////////////
#define TAMFILME sizeof(struct filme)
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// FUNÇÃO CADASTRA FILME ///////////////////////////////////////////////////////////////////
void getFilme(void)
{
    limpaTela(); // Limpa tela.
    char resposta = 's'; // Resposta recebe 's'.
    filme cadastroFilme; // Cria variável do tipo filme(struct filme).
    FILE * ponteiro; // Cria ponteiro.

    while(resposta == 's' || resposta == 'S') // Se resposta for 's' ou 'S' então entra.
    {
        ponteiro = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
        if(ponteiro == NULL) // Se ponteiro for igual a NULL(VAZIO).
            exit(0); // Sai do programa.

        fseek(ponteiro, -1 * TAMFILME, SEEK_END); // Inicia ponteiro no final do arquivo e volta -X bytes.
        fread(&cadastroFilme, TAMFILME, 1, ponteiro); // Ler linha arquivo do endereço em que 'ponteiro' se encontra.
        cadastroFilme.codigoFilme = (feof(ponteiro) ? 1 : cadastroFilme.codigoFilme +1); // if else, para adicionar código ao registro.

        // Cadastro de filme.
        gotoxy(31,0);
        printf("CADASTRO DE FILME");
        printf("\n================================================================================");
        gotoxy(0,2); printf("Codigo: %d", cadastroFilme.codigoFilme); // Recebe código e imprime na tela.
        
        rewind(stdin); // Limpa buffer do teclado.
        
        gotoxy(0,3);
        printf("Nome do filme: ");
        
        gotoxy(50,3);
        printf("Genero: ");
        
        gotoxy(0,5);
        printf("Sinopse: ");
        
        gotoxy(0,9);
        printf("Tempo (minutos): ");
        
        gotoxy(25,9);
        printf("Valor (diaria): ");
        
        gotoxy(50,9);
        printf("Quantidade: ");
        printf("\n================================================================================");

        gotoxy(15,3);
        gets(cadastroFilme.nomeFilme); // Recebe nome do filme.
        
        gotoxy(58,3);
        gets(cadastroFilme.genero); // Recebe genero do filme.
        
        gotoxy(9,5);
        gets(cadastroFilme.sinopse); // Recebe sinopse do filme.
        
        gotoxy(17,9);
        scanf("%d", &cadastroFilme.tempo); // Recebe tempo do filme.
        
        gotoxy(41,9);
        scanf("%f", &cadastroFilme.valor); // Recebe valor do filme.
        
        gotoxy(62,9);
        scanf("%d", &cadastroFilme.quantidade);
        
        cadastroFilme.excluir = 0;
        
        cadastroFilme.locado = 0;

        fseek(ponteiro, 0L, SEEK_END); // Empurra ponteiro para o descritor, para adicionarmos um novo registro.
        fwrite(&cadastroFilme, TAMFILME, 1, ponteiro); // Grava dados no arquivo.
        fclose(ponteiro); // Fecha ponteiro.

        printf("\n\nRegistro Gravado.");
        printf("\nContinuar...(s/n)"); // Pergunta se deseja adcionar um novo cadastro.
        resposta = getch(); // Espera resposta.
        if(resposta == 's' || resposta == 'S') // Se resposta for 's' ou 'S' então limpa tela.
            limpaTela();
        printf("\n");
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// FUNÇÃO PARA MOSTRAR UMA LISTA DE CADASTRO DE FILME //////////////////////////////////////
void listaCadastroFilme(void)
{
    FILE * ponteiro; // Cria variável tipo FILE.
    filme listaFilme; // Cria variável do tipo filme(struck filme).
    int qtd = 0; // Quantidade recebe zero.
    int paraListagem = 0; // Para listagem recebe zero.

    paraListagem = listagemDiretaOuPartes(); // Chama função.

    ponteiro = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
    if(ponteiro == NULL) // Se ponteiro for NULL. 
        exit(0); // Sai do programa.

    printf("\n\n     LISTA DE CADASTRO DE FILME\n");
    printf("------------------------------------\n");

    while(!feof(ponteiro)) // Enquanto ponteiro não chega no final.
    {
        fread(&listaFilme, TAMFILME, 1, ponteiro); // Lê arquivo CADFIL.DAT.
        if(!feof(ponteiro) && listaFilme.excluir == 0) // Enquanto ponteiro não chega no final e excluir for igual a 0.
        {                  // ENTÃO EMPRIMA
            printf("\nCodigo: %d", listaFilme.codigoFilme);
            printf("\nNome: %s", listaFilme.nomeFilme);
            printf("\nGenero: %s", listaFilme.genero);
            printf("\nSinopse: %s", listaFilme.sinopse);
            printf("\nTempo (minutos): %d", listaFilme.tempo);
            printf("\nValor (diaria): %.2fR$", listaFilme.valor);
            printf("\nQuantidade: %d\n", listaFilme.quantidade);
            qtd++;
            if(qtd > 4 && paraListagem == 1) // Quando quantidade for maior que 4 e paraListagem igual a 1 então para listagem.
            {
                getch(); // Espera usuário digitar qualquer tecla para continuar listagem.
                qtd = 0; // Quantidade recebe 0.
            }
        }
    }
    fclose(ponteiro); // Fecha ponteiro.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// BUSCA POR NOME //////////////////////////////////////////////////////////////////////////
void buscaFilmeNome(void)
{
    limpaTela(); // Limpa tela.
    FILE * ponteiro; // Cria ponteiro para arquivo.
    filme buscaFilme; // Variável do tipo cliente(struct).
    int achou = 0; // Achou recebe 0.
    int temp; // Variável para capturar tamanho da string(nome) digitada pelo usuário.
    char nomeFilme[50]; // Recebe nome digitado pelo usuário que deseja buscar.
    char comparanome[50]; // Recebe nome do filme, arquivo CADFIL.DAT


    rewind(stdin); // Limpa buffer do teclado.
    printf("Nome filme: ");
    gets(nomeFilme); // Recebe nome digitado pelo usúario.

    temp = strlen(nomeFilme); // Captura o tamanho da string(nome) digitada pelo usuário.

    ponteiro = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
    if(ponteiro == NULL) // Se ponteiro for igual a NULL(VAZIO).
        exit(0); // Sai do programa.

    printf("\n\n     CADASTRO BUSCADO\n");

    while(!feof(ponteiro)) // Enquanto ponteiro não chega ao fim do arquivo CADFIL.DAT não para.
    {
        fread(&buscaFilme, TAMFILME, 1, ponteiro); // Lê um registro do CADFIL.DAT.
        strncpy(comparanome, buscaFilme.nomeFilme, temp); // Copia nome do arquivo CADFIL.DAT para variável compara nome, com tamanho definido pela string(NOME) digitado pelo usuário.

        if(!feof(ponteiro) && buscaFilme.excluir == 0) // Se ponteiro não chegou ao fim e buscaCliente.statos é diferende de zero então entra.

                if(strnicmp(nomeFilme, comparanome, temp) == 0) // Se nome digitado pelo usuário for igual ao do arquivo CADFIL.DAT.
                {                      // IMPRIMA 
                    printf("------------------------------------\n");
                    printf("\nCodigo: %d", buscaFilme.codigoFilme);
                    printf("\nNome: %s", buscaFilme.nomeFilme);
                    printf("\nSinopse: %s", buscaFilme.sinopse);
                    printf("\nGenero: %s", buscaFilme.genero);
                    printf("\nTempo (minutos): %d", buscaFilme.tempo);
                    printf("\nValor (diaria): %.2fR$", buscaFilme.valor);
                    printf("\nQuantidade: %d\n", buscaFilme.quantidade);
                    printf("------------------------------------\n");
                    achou = 1;
                }

    }

    fclose(ponteiro); // Fecha ponteiro.
    achouu(achou); // Se achou for igual a 0 então imprima.
    getch(); // Espera usuário teclar qualquer tecla para sair da função.
    limpaTela(); // Limpa tela.

}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// BUSCA POR CÓDIGO ////////////////////////////////////////////////////////////////////////
int consultarFilmeCodigo(void)
{
    FILE * ponteiro; // Cria variável tipo FILE.
    filme listaFilme; // Cria variável do tipo filme(struck filme).
    int achou = 0; // Achou recebe 0.
    int posicao = 0; // Posição recebe 0.
    int codigoFilme = 0; // Código Filme recebe 0.

    printf("Codigo filme: ");
    scanf("%d", &codigoFilme); // Lê o código que o usuário digitou.

    ponteiro = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
        exit(0); // Sai do programa.



    while(!feof(ponteiro) && (achou == 0)) // Enquanto ponteiro não chega no final e achou for igual a 0 lê arquivo.
    {
        fread(&listaFilme, TAMFILME, 1, ponteiro); // Lê arquivo CADFIL.DAT.

        if(!feof(ponteiro)) // Enquanto ponteiro não chega no final.
        {
            if(codigoFilme == listaFilme.codigoFilme) // Se código digitado pelo usuário for igual ao do arquivo CADFIL.DAT.
            {
                if(listaFilme.excluir == 1) // Se excluir for igual a 1.
                    posicao = -2; // Posição recebe -2.
                achou = 1; // Achou recebe 1.
            }
            else
                posicao++; // Enquanto código não for igual então acrescenta mais um em posição.
        }
        else
            posicao = -1; // Se ponteiro chegou no final e não achou nada então acrescenta -1 em posição.
    }
    achouu(achou); // Se achou for igual a 0 então imprima.

    fclose(ponteiro); // Fecha ponteiro.

    return(posicao); // Retorna posição do registro buscado.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// ALTERAR VIDEO ///////////////////////////////////////////////////////////////////////////
void alterarVideo(void)
{
    char resposta = 's'; // Resposta recebe 's'.
    int posicao = 0; // Posição recebe 0.
    filme alterarFilme; // Variável tipo filme.
    FILE * ponteiro; // Variável tipo FILE para arquivos.

    buscaFilmeNome(); // Chama função.
    posicao = consultarFilmeCodigo(); // Chama função e posição recebe dado procurado pelo usuário.
    limpaTela(); // Limpa tela.

    if(posicao == -1) // Se posição for igual a -1.
        getch(); // Espera usuário digitar qualquer tecla para finalizar função.
    else
        if(posicao == -2) // Se posição for igual a -2.
            getch(); // Espera usuário digitar qualquer tecla para finalizar função.
        else 
        {
            ponteiro = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
            if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
                exit(0); // Sai do programa.

            fseek(ponteiro, posicao * TAMFILME, SEEK_CUR); // Posiciona ponteiro no dado buscado pelo usuário.
            fread(&alterarFilme, TAMFILME, 1, ponteiro); // Lê dado buscado pelo usuário.
            // IMPRIME
            printf("Registro buscado...\n\n");
            
            printf("Codigo: %d", alterarFilme.codigoFilme);
            
            printf("\nNome: %s", alterarFilme.nomeFilme);
            
            gotoxy(50,3);
            printf("Genero: %s", alterarFilme.genero);
            
            gotoxy(0,5);
            printf("Sinopse: %s", alterarFilme.sinopse);
            
            gotoxy(0,9);
            printf("Tempo (minutos): %d", alterarFilme.tempo);
            
            gotoxy(25,9);
            printf("Valor (diaria): %.2fR$", alterarFilme.valor);
            
            gotoxy(50,9);
            
            printf("Quantidade: %d", alterarFilme.quantidade);
            printf("\n-------------------------------------------------------------------------------");
           
            printf("\nDeseja alterar o registro(s/n)"); // Pergunta se realmente deseja alterar dado.
            resposta = getch(); // Espera resposta do usuário.

            while(resposta == 's' || resposta == 'S') // Se a resposta for 's' ou 'S' então entra.
            {
                printf("\nCodigo: %d", alterarFilme.codigoFilme); // Recebe código e imprime na tela.
                
                rewind(stdin); // Limpa buffer do teclado.
                printf("\nNome do filme: ");
                
                gotoxy(50,13);
                printf("Genero: ");
                
                gotoxy(0,15);
                printf("Sinopse: ");
                
                gotoxy(0,19);
                printf("Tempo (minutos): ");
                
                gotoxy(25,19);
                printf("Valor (diaria): ");
                
                gotoxy(50,19);
                printf("Quantidade: ");
/////////////////////////////
                
                gotoxy(15,13);
                gets(alterarFilme.nomeFilme); // Recebe nome do filme.
                
                gotoxy(58, 13);
                gets(alterarFilme.genero); // Recebe genero do filme.
               
                gotoxy(9,15);
                gets(alterarFilme.sinopse); // Recebe sinopse do filme.
               
                gotoxy(17,19);
                scanf("%d", &alterarFilme.tempo); // Recebe tempo do filme.
               
                gotoxy(41,19);
                scanf("%f", &alterarFilme.valor); // Recebe valor do filme.
               
                gotoxy(62,19);
                scanf("%d", &alterarFilme.quantidade); // Recebe valor da quantidade de filmes.
               
                alterarFilme.excluir = 0;

                fseek(ponteiro, posicao * TAMFILME, SEEK_SET); // Posiciona ponteiro no dado que sera sobre escrevido pelo usuário.
                fwrite(&alterarFilme, TAMFILME, 1, ponteiro); // Salva dado do usuário.
                printf("\nRegravacao feita com sucesso.");
                resposta = 'n'; // Resposta recebe 'n' para sair do laço.
                getch(); // Espera usuário digitar qualquer tecla para finalizar função.
            }
            fclose(ponteiro); // Fecha ponteiro.
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// EXCLUIR FILME ///////////////////////////////////////////////////////////////////////////
void excluirFilme(void)
{
    char resposta = 's'; // Resposta recebe 's'.
    int posicao = 0; // Posição recebe 0.
    filme excluiFilme; // Cria tipo de dado filme.
    FILE * ponteiro; // Cria tipo de dado FILE para arquivos.

    buscaFilmeNome(); // Chama função.
    posicao = consultarFilmeCodigo(); // Chama função para usuário pesquisar dado pelo código e retorna posição.

    if(posicao == -1) // Se posição for igual a -1.
        getch(); // Espera usuário digitar qualquer tecla para sair da função.
    else
        if(posicao == -2) // Se posição for igual a -2.
            getch(); // Espera usuário digitar qualquer tecla para sair da função.
        else
        {
            ponteiro = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
            if(ponteiro == NULL) // Se ponteiro for igual a NULL(VAZIO).
                exit(0); // Sai do programa.

            fseek(ponteiro, posicao * TAMFILME, SEEK_SET); // Posiciona ponteiro no dado que o usuário buscou.
            fread(&excluiFilme, TAMFILME, 1, ponteiro); // Lê dado que usuário buscou.
                                // IMPRIME 
            printf("-------------------------------------------------------------------------------\n");
            printf("Codigo: %d", excluiFilme.codigoFilme);
           
            printf("\nNome: %s", excluiFilme.nomeFilme);
           
            gotoxy(50,3);
            printf("Genero: %s", excluiFilme.genero);
           
            gotoxy(0,5);
            printf("Sinopse: %s", excluiFilme.sinopse);
           
            gotoxy(0,9);
            printf("Tempo (minutos): %d", excluiFilme.tempo);
           
            gotoxy(25,9);
            printf("Valor (diaria): %.2fR$", excluiFilme.valor);
           
            gotoxy(50,9);
            printf("Quantidade: %d", excluiFilme.quantidade);
            printf("\n-------------------------------------------------------------------------------");
           
            excluiFilme.excluir = 1; // Altera excluir para 1.

            printf("\n\nDeseja excluir o registro(s/n)?"); // Pergunta para usuário se realmente deseja excluir registro buscado.
            resposta = getch(); // Espera resposta.


            while(resposta == 's' || resposta == 'S') // Se resposta for igual a 's' ou 'S' então exclui registro buscado pelo usuário.
            {
                fseek(ponteiro, posicao * TAMFILME, SEEK_SET); // Posiciona ponteiro no dado buscado pelo usuário.
                fwrite(&excluiFilme, TAMFILME, 1, ponteiro); // Sobre escreve dado que foi buscado pelo usuário.
                printf("\nRegistro excluido com sucesso.\n\n");
                resposta = 'n'; // Resposta recebe 'n' para sair do laço.
                getch(); // Espera usuário digitar qualquer tecla para sair da função.
            }
            fclose(ponteiro); // Fecha ponteiro.
        }
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// STRUCT LOCAFILME ////////////////////////////////////////////////////////////////////////
typedef struct locafilme
{
    int codigoNota; // Recebe o código da nota.
    int codigoFilme; // Recebe o código do filme locado pelo usuário.
    int codigoCliente; // Recebe o código do cliente locado pelo usuário.
    int excluir; // 0 não esta excluida, 1 verdade que esta excluida.
    int statusNota; // 1 está em aberto, 0 está fechada(concluida).
    int quantidade; // Recebe a quantidade de filmes.
    //int quantidadeClienteLevou; // Recebe a quantidade de filmes que o Cliente levou.
    float valor; // Recebe o valor do filme.
    char nomeCliente[50]; // Recebe o nome do cliente que locou um filme.
    char nomeFilme[50]; // Recebe o nome do filme que o cliente levou.

} locafilme;
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// DEFINE TAMANHO DA STRUCT LOCAFILME EM BYTES /////////////////////////////////////////////
#define TAMLOCAFILME sizeof(struct locafilme)
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// LOCAÇÃO DE FILME ////////////////////////////////////////////////////////////////////////
void locacaoFilme(void)
{
    int posicao = 0; // Posição recebe 0.
    int posicao2 = 0; // Posição2 recebe 0.
    char resposta = 's'; // Resposta recebe 's'.
    FILE * ponteiro; // Cria variável tipo FILE para arquivo.
    FILE * ponteiro2; // Cria variável tipo FILE para arquivo.
    FILE * ponteiro3; // Cria variável tipo FILE para arquivo.
    cliente locacaoCliente; // Cria variável tipo cliente.
    filme locacaoFilmes; // Cria variável tipo filme.
    locafilme locaFilmes; // Cria variável tipo locafilme.

    buscaClienteNome(); // Chama função para buscar o nome do cliente no arquivo CADCLI.DAT.
    posicao = consultarClienteCodigo(); // Chama função para busca de cliente por código e retorna posição do dado buscado.

        buscaFilmeNome(); // Chama função para buscar o nome do filme no arquivo CADFIL.DAT.
        posicao2 = consultarFilmeCodigo(); // Chama função para busca de filme por código e retorna posição do dado buscado.
        limpaTela(); // Limpa a tela.

        if(posicao == -1 || posicao2 == -1 || posicao == -2 || posicao2 == -2) // Se posição for igual a -1 ou -2 ou posição2 for igual a -1 ou -2.
            getch(); // Espera usuário digitar qualquer tecla para sair da função.
        else
            {
                ponteiro = fAbreArquivo("CADCLI.DAT"); // Abre arquivo CADCLI.DAT.
                ponteiro2 = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
                ponteiro3 = fAbreArquivo("LOCFILME.DAT"); // ABRE arquivo LOCFILME.DAT.
                if(ponteiro == NULL) // Se ponteiro der NULL
                    exit(0); // Sai do programa.
                else
                    if(ponteiro2 == NULL) // Se ponteiro2 der NULL
                        exit(0);  // Sai do programa.

                fseek(ponteiro, posicao * TAMCLIENTE, SEEK_SET); // Posiciona ponteiro no arquivo CADCLI.DAT.
                fseek(ponteiro2, posicao2 * TAMFILME, SEEK_SET); // Posiciona ponteiro2 no arquivo CADFIL.DAT. 
                fseek(ponteiro3, -1 * TAMLOCAFILME, SEEK_END); // Posiciona ponteiro3 no arquivo LOCAFILME.DAT.
                fread(&locacaoCliente, TAMCLIENTE, 1, ponteiro); // Lê dado buscado pelo usuário do cliente.
                fread(&locacaoFilmes, TAMFILME, 1, ponteiro2); // Lê dado buscado pelo usuário de filme.
                fread(&locaFilmes, TAMLOCAFILME, 1, ponteiro3); // Lê arquivo LOCAFILME.DAT.
                locaFilmes.codigoNota = (feof(ponteiro3) ? 1 : locaFilmes.codigoNota +1); // Incrementa código a nota.
                gotoxy(32,0);
                             // IMPRIMA
                printf("LOCACAO DE FILME");
                printf("\n================================================================================");
                printf("\nCodigo da Nota: %d", locaFilmes.codigoNota); // Imprime código nota.
                printf("\nCodigo cliente: %d", locacaoCliente.codigoCliente); // Imprime código cliente.
                locaFilmes.codigoCliente = locacaoCliente.codigoCliente; // locaFilmes.codigoCliente recebe valor de locacaoCliente.codigoCliente.
                printf("\nNome: %s", locacaoCliente.nomeCliente);
                strcpy(locaFilmes.nomeCliente, locacaoCliente.nomeCliente);
                printf("\nCodigo filme: %d", locacaoFilmes.codigoFilme);
                locaFilmes.codigoFilme = locacaoFilmes.codigoFilme;
                printf("\nFilme: %s", locacaoFilmes.nomeFilme);
                strcpy(locaFilmes.nomeFilme, locacaoFilmes.nomeFilme);
                printf("\nValor: %2.2f\n\n", locacaoFilmes.valor);
                locaFilmes.valor = locacaoFilmes.valor;
                locaFilmes.statusNota = 0;
                locaFilmes.excluir = 0;

                printf("Concluir locacao?(s/n)\n"); // Pergunta ao usuário se ele deseja realmente locar o filme.
                    resposta = getch(); // Espera resposta do usuário.
                if(resposta == 's' || resposta == 'S') // Se resposta for igual a 's' ou 'S'.
                {
                    if(locacaoFilmes.quantidade > 0) // Se quantidade de filmes for igual a 0 ou menor então não tem filmes.
                        locacaoFilmes.locado++; // se locado da struct filmes estiver acima de 0 então esta locado o filme.
                    else
                        printf("Nao tem em estoque.\n");

                    if(locacaoFilmes.quantidade > 0)
                    {
                        locacaoFilmes.quantidade--; // quantidade da struct filme, recebe menos 1 de um determinado filme do cadastro.


                        fseek(ponteiro, posicao * TAMCLIENTE, SEEK_SET); // Posiciona ponteiro no dado buscado pelo usuário.
                        fseek(ponteiro2, posicao2 * TAMFILME, SEEK_SET); // Posiciona ponteiro2 no dado buscado pelo usuário.
                        fseek(ponteiro3, 0L, SEEK_END); // ponteiro vai até o descritor do arquivo LOCAFILME.DAT para registrar nova nota.
                        fwrite(&locacaoCliente, TAMCLIENTE, 1, ponteiro); // Salva arquivo CADCLI.DAT.
                        fwrite(&locacaoFilmes, TAMFILME, 1, ponteiro2); // Salva arquivo CADFILME.DAT.
                        fwrite(&locaFilmes, TAMLOCAFILME, 1, ponteiro3); // Salva nova nota no arquivo LOCAFILME.DAT.
                        printf("Concluido com sucesso.\n");
                    }
                }
                fclose(ponteiro); // Fecha ponteiro.
                fclose(ponteiro2); // Fecha ponteiro2.
                fclose(ponteiro3); // Fecha ponteiro3.
           }

}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// BUSCA POR NOME CLIENTE NOTA /////////////////////////////////////////////////////////////
void buscaNomeClienteNota(void)
{
    FILE * ponteiro; // Cria variável tipo FILE para arquivo.
    locafilme buscaNota; // Cria variável tipo locafilme.
    int achou = 0; // Variável achou recebe 0.
    int temp; // Variável para capturar o tamanho da string(nome) digitado pelo usuário.
    char nomeClienteNota[50]; // Recebe nome que o usuário digitou.
    char comparanome[50]; // Recebe nome do arquivo LOCAFILME.DAT.

    rewind(stdin); // Limpa buffer do teclado.
    printf("NomeCliente: "); 
    gets(nomeClienteNota); // Espera usuário digitar um nome e recebe.

    temp = strlen(nomeClienteNota); // Captura o tamanho da string(nome) digitado pelo usuário.

    ponteiro = fAbreArquivo("LOCFILME.DAT"); // Abre arquivo LOCFILME.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
        exit(0); // Sai do programa.

    printf("\n\n         NOTA BUSCADA\n");

    while(!feof(ponteiro)) // Enquanto ponteiro não chegar ao final não para.
    {
        fread(&buscaNota, TAMLOCAFILME, 1, ponteiro); // Lê arquivo LOCAFILME.DAT.
        strncpy(comparanome, buscaNota.nomeCliente, temp); // Variável comparanome, recebe dado de LOCAFILME.DAT com tamanho determinado pela string(nome) digitado pelo usuário.

        if(!feof(ponteiro) && buscaNota.excluir == 0 && buscaNota.statusNota == 0) // Enquanto ponteiro não chega no final e excluir for igual a 0 e nota statos for igual a 0, não para.
            if(strnicmp(nomeClienteNota, comparanome, temp) == 0) // Compara nome digitado pelo usuário e nome do arquivo LOCAFILME.DAT.
            {
                                         // IMPRIME
                printf("\n-----------------------------------\n");
                printf("\nCodigo da Nota: %d", buscaNota.codigoNota);
                printf("\nCodigo cliente: %d", buscaNota.codigoCliente);
                printf("\nNome: %s", buscaNota.nomeCliente);
                printf("\nCodigo filme: %d", buscaNota.codigoFilme);
                printf("\nFilme: %s", buscaNota.nomeFilme);
                printf("\nValor: %2.2f\n", buscaNota.valor);
                printf("-----------------------------------\n");
                achou = 1;
            }

    }
    achouu(achou); // Se achou for igual a 0 então imprime.
    fclose(ponteiro); // Fecha ponteiro.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// BUSCA POR CÓDIGO DA NOTA ////////////////////////////////////////////////////////////////
int buscaCodigoNota(void)
{
    int achou = 0; // Achou recebe 0.
    int posicao = 0; // Posição recebe 0.
    int codigoNota = 0; // Código nota recebe 0.
    locafilme pesquisaCodigoNota; // Variável tipo locafilme.
    FILE * ponteiro; // Variável tipo FILE para arquivo.

    printf("Codigo nota: "); 
    scanf("%d", &codigoNota); // Código digitado pelo usuário.

    ponteiro = fAbreArquivo("LOCFILME.DAT"); // Abre arquivo LOCFILME.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
        exit(0); // Sair do programa.

    while(!feof(ponteiro) && achou == 0) // Enquanto ponteiro não chega no final e achou for igual a 0 então não para.
    {
        fread(&pesquisaCodigoNota, TAMLOCAFILME, 1, ponteiro); // Lê dados do arquivo LOCAFILME.DAT.

        if(!feof(ponteiro)) // Enquanto ponteiro não chegar ao final não para.
        {
            if(codigoNota == pesquisaCodigoNota.codigoNota) // Se código digitado pelo usuário for igual ao código do arquivo LOCAFILME.DAT.
            {
                if(pesquisaCodigoNota.excluir > 0 && pesquisaCodigoNota.statusNota > 0) // Se excluir for maior que 0 e pesquisa codigo nota for maior que 0.
                    posicao = -2; // Posição recebe -2
                achou = 1; // Achou recebe 1.
            }
            else
                posicao++; // Enquanto não acha nota, acrescenta mais 1.
        }
        else
            posicao = -1; // Se ponteiro chegar ao final do arquivo e não encontrar nada, então posição recebe -1.
    }

    achouu(achou); // Se achou for igual a 0, então irmprime.

    fclose(ponteiro); // Fecha ponteiro.

    return(posicao); // Retorna posição capturada.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// DEVOLUÇÃO DE FILME //////////////////////////////////////////////////////////////////////
void devolucaoFilme(void)
{
    limpaTela(); // Limpa tela.
    int posicao = 0; // Posição recebe 0.
    int posicao2 = 0; // Posição2 recebe 0.
    int achou = 0; // Achou recebe 0.
    int codigoFilme = 0; // Codigo filme recebe 0.
    char resposta = 's'; // Resposta recebe 's'.
    FILE * ponteiro; // Variável do tipo FILE para arquivos.
    FILE * ponteiro2; // Variável do tipo FILE para arquivos.
    locafilme devolucaoDeFilme; // Cria variável do tipo locafilme.
    filme devolveFilme; // Cria variável do tipo filme.
    int opcao = 2;

    buscaNomeClienteNota(); // Busca nome do cliente pelo arquivo LOCAFILME.DAT.
    getch(); 
    limpaTela(); // Limpa tela.
    posicao = buscaCodigoNota(); // Busca a nota pelo código digitado pelo usuário e retorna posição da nota no arquivo LOCAFILME.DAT.
    limpaTela(); // Limpa tela.
    // IMPRIME
    gotoxy(31,0);
    printf("DEVOLUCAO DE FILME");
    printf("\n================================================================================");

    if(posicao == -1 || posicao == -2) // Se posição for igual a -1 ou -2.
        getch(); // Espera usuário teclar qualquer tecla para sair do programa.
    else
    {
        ponteiro = fAbreArquivo("LOCFILME.DAT"); // Abre arquivo LOCFILME.DAT.
        ponteiro2 = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
        if(ponteiro == NULL) // Se ponteiro for igual a NULL(VAZIO).
            exit(0); // Sai do programa.

        fseek(ponteiro, posicao * TAMLOCAFILME, SEEK_SET); // Posiciona ponteiro no arquivo LOCFILME.DAT.
        fread(&devolucaoDeFilme, TAMLOCAFILME, 1, ponteiro); // Lê dado do arquivo LOCFILME.DAT.
        fseek(ponteiro2, posicao2 * TAMFILME, SEEK_SET); // Posiciona ponteiro no arquivo CADFIL.DAT.
        fread(&devolveFilme, posicao2 * TAMFILME, 1, ponteiro2); // Lê dado do arquivo CADFIL.DAT.

        //////////////// BUSCA NO CADASTRO DE FILME //////////////////////////////
        codigoFilme = devolucaoDeFilme.codigoFilme; // variável codigoFilme recebe codigo do filme que esta na nota.
        while(!feof(ponteiro) && (achou == 0)) // Enquanto ponteiro não chega no final e achou for igual a 0 então não para.
        {
            fread(&devolveFilme, TAMFILME, 1, ponteiro2); // Lê dado do arquivo CADFIL.DAT.

            if(!feof(ponteiro2)) // Enquanto ponteiro2 não chegar ao final, não para.
            {
                if(codigoFilme == devolveFilme.codigoFilme) // Se código do filme for igual ao do código filme do arquivo CADFIL.DAT.
                {
                    if(devolveFilme.excluir > 0 || devolucaoDeFilme.statusNota > 0) // Se excluir for maior que 0 ou statosNota maior que 0.
                        posicao2 = -2; // Posição recebe -2.
                    achou = 1; // Achou recebe 1.
                }
                else
                    posicao2++; // Enquanto não encontra códigos iguais acrescenta posição2 em 1.
            }
            else
                posicao2 = -1; // Se percorreu o arquivo todo e não encontrou nada então posição2 recebe -1.
        }
        if(achou == 0 || posicao2 == -2) // Se achou for igual a 0 ou posição2 for igual a -2.
        {
                 // IMRPIME
            printf("\n\n         NOTA BUSCADA\n");
            printf("------------------------------------\n");
            printf("\nRegistro nao encontrado.");
            printf("\n------------------------------------\n");
        }
        else
        {
                // IMRPIME
            printf("-----------------------------------\n");
            printf("\nCodigo da Nota: %d", devolucaoDeFilme.codigoNota);
            printf("\nCodigo cliente: %d", devolucaoDeFilme.codigoCliente);
            printf("\nNome: %s", devolucaoDeFilme.nomeCliente);
            printf("\nCodigo filme: %d", devolucaoDeFilme.codigoFilme);
            printf("\nFilme: %s", devolucaoDeFilme.nomeFilme);
            printf("\nValor: %2.2f\n\n", devolucaoDeFilme.valor);
            printf("-----------------------------------\n");


            printf("Concluir devolucao?(s/n)\n"); // Pergunta ao usuário se realmente deseja concluir devolução.
                resposta = getch(); // Espera resposta do usuário.
            if(resposta == 's' || resposta == 'S') // Se resposta for igual a 's' ou 'S'.
            {
                if(devolveFilme.quantidade >= 0) // se quantidade for maior ou igual a zero na quantidade do filme a ser devolvido então entra
                    devolveFilme.locado--; // locado recebe menos um pois um filme foi devolvido ( statos do filme _
                else
                    printf("Nao tem em estoque.\n");

                if(devolveFilme.quantidade >= 0)
                {
                    devolveFilme.quantidade++; // Quantidade de um filme recebe +1 pois foi devolvido.
                    devolucaoDeFilme.statusNota = 1; // Statos da nota recebe 1 é verdade que esta desativa.

                    fseek(ponteiro, posicao * TAMLOCAFILME, SEEK_SET); // Posiciona ponteiro no arquivo LOCFILME.DAT.
                    fseek(ponteiro2, posicao2 * TAMFILME, SEEK_SET); // Posiciona ponteiro2 no arquivo CADFIL.DAT.
                    fwrite(&devolucaoDeFilme, TAMLOCAFILME, 1, ponteiro); // Salva arquivo LOCFILME.DAT.
                    fwrite(&devolveFilme, TAMFILME, 1, ponteiro2); // SALVA ARQUIVO CADFIL.DAT.
                    printf("Concluido com sucesso.\n");
                }
            }
        }
        fclose(ponteiro); // Fecha ponteiro.
        fclose(ponteiro2); // Fecha ponteiro2.
    }

}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// IMPRIMIR FILMES LOCADOS /////////////////////////////////////////////////////////////////
void imprimeFilmesLocados(void)
{ 
    int achou = 0; // Achou recebe 0.
    FILE * ponteiro; // Cria variável tipo FILE, para arquivo.
    filme imprimeFilmeLocado; // Cria variável tipo filme.
    int qtd = 0; // Quantidade igual a 0.
    int paraListagem = 0; // Para listagem igual a 0.

    paraListagem = listagemDiretaOuPartes(); // Chama função.

    ponteiro = fAbreArquivo("CADFIL.DAT"); // Abre arquivo CADFIL.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO).
        exit(0); // Sai do programa.

    gotoxy(33,0);
    printf("FILMES LOCADOS");
    printf("\n================================================================================");

    while(!feof(ponteiro)) // Enquanto ponteiro não chega no final, não para.
    {
        fread(&imprimeFilmeLocado, TAMFILME, 1, ponteiro); // Lê dado do arquivo CADFIL.DAT.

        if(!feof(ponteiro)) // Enquanto ponteiro não chega no final, não para.
            if(imprimeFilmeLocado.excluir == 0 && imprimeFilmeLocado.locado != 0) // Se excluir for igual a 0 e locado diferente de 0.
            {                             // IMPRIME
                printf("\nCodigo: %d", imprimeFilmeLocado.codigoFilme);
                printf("\nNome: %s", imprimeFilmeLocado.nomeFilme);
                printf("\nSinopse: %s", imprimeFilmeLocado.sinopse);
                printf("\nGenero: %s", imprimeFilmeLocado.genero);
                printf("\nTempo (minutos): %d", imprimeFilmeLocado.tempo);
                printf("\nValor (diaria): %.2fR$", imprimeFilmeLocado.valor);
                printf("\nQuantidade: %d\n", imprimeFilmeLocado.quantidade);
                achou = 1;
                if(qtd > 4 && paraListagem == 1) // Se quantidade for maior que 4 e paraListagem for igual a 1 então para listagem.
                {
                    getch(); // Tecla qualquer tecla para continuar listagem.
                    qtd = 0; // Quantidade recebe 0.
                }
            }
    }
    fclose(ponteiro); // Fecha ponteiro.

    achouu(achou); // Se achou for igual a 0 então imprime.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// IMPRIME FILMES LOCADOS POR UM CLIENTE ///////////////////////////////////////////////////
void imprimirLocacoesPorUmDadoCliente(void)
{
    FILE * ponteiro; // Cria ponteiro para arquivo.
    locafilme imprimirCliente; // Variável tipo locafilme.
    char nomeCliente[50]; // Nome digitado pelo usuário.
    char comparaCliente[50]; // Recebe nome do cliente no arquivo.
    int temp; // Captura tamanho de string digitada pelo usuário.
    int achou = 0; // Se for igual a 0 então não achou.
    int qtd = 0; // Contador.
    int paraListagem = 0; // Para listagem inicia com 0.

    paraListagem = listagemDiretaOuPartes(); // Chama função.

    gotoxy(25,0);
    printf("LOCAÇÕES FEITAS POR UM CLIENTE");
    printf("\n================================================================================");

    rewind(stdin);
    printf("\nNome do cliente: ");
    gets(nomeCliente); // Leitura de nome de cliente.

    temp = strlen(nomeCliente); // Captura tamanho da string digitada pelo usuário.

    ponteiro = fAbreArquivo("LOCFILME.DAT"); // Abre arquivo LOCFILME.DAT.
    if(ponteiro == NULL) // Se ponteiro igual a NULL(VAZIO)
        exit(0); // Sai do programa.

    while(!feof(ponteiro)) // Enquanto ponteiro não chega no final então não para.
    {
        fread(&imprimirCliente, TAMLOCAFILME, 1, ponteiro); // Lê arquivo LOCFILME.DAT.
        strncpy(comparaCliente, imprimirCliente.nomeCliente, temp); // Copia valor do registro de LOCFILME.DAT para compara cliente.

        if(!feof(ponteiro)) // Enquanto não chegar ao final não para.
                                // Se nomes forem iguais e excluir for igual a 0 e statos for igual a 1 então imprima.
            if(strnicmp(nomeCliente, comparaCliente, temp) == 0 && imprimirCliente.excluir == 0 && imprimirCliente.statusNota == 0)
            {
                printf("\n-----------------------------------\n");
                printf("\nCodigo da Nota: %d", imprimirCliente.codigoNota);
                printf("\nCodigo cliente: %d", imprimirCliente.codigoCliente);
                printf("\nNome: %s", imprimirCliente.nomeCliente);
                printf("\nCodigo filme: %d", imprimirCliente.codigoFilme);
                printf("\nFilme: %s", imprimirCliente.nomeFilme);
                printf("\nValor: %2.2f\n", imprimirCliente.valor);
                printf("-----------------------------------\n");
                achou = 1; // Achou recebe 1.
                if(qtd > 4 && paraListagem == 1) // Contador para parar a listagem.
                {
                    getch(); // Para listagem
                    qtd = 0; // Contador recebe zero.
                }
            }

    }
    fclose(ponteiro); // fecha ponteiro

    achouu(achou); // chamada da função
}
////////////////////////////////////////////////////////////////////////////////////////////////////


////////// IMPRIMIR FILMES DEVOLVIDOS POR UM DADO CLIENTE //////////////////////////////////////////
void imprimirDevolucoesPorUmDadoCliente(void)
{
    FILE * ponteiro; // Cria ponteiro para arquivo.
    locafilme imprimirCliente; // Cria variável tipo locafilme.
    char nomeCliente[50]; // Armazenar nome do cliente digitado pelo usuário.
    char comparaCliente[50]; // Armazenar nome do cliente do arquivo LOCFIL.DAT.
    int temp; // Armazenar tamanho da string digitada pelo usuário
    int achou = 0; // Se achou for igual a 1 então achou, se igual a 0 então não achou
    int qtd = 0; // Contador.
    int paraListagem = 0; // Se for igual a 1 então faz listagem por partes.

    paraListagem = listagemDiretaOuPartes(); // Função que mostra menus.

    gotoxy(24,0);
    printf("DEVOLUCOES FEITAS POR UM CLIENTE");
    printf("\n================================================================================");

    rewind(stdin);
    printf("\nNome do cliente: ");
    gets(nomeCliente); // Faz a leitura do nome do cliente.

    temp = strlen(nomeCliente); // Captura o tamanho da string.

    ponteiro = fAbreArquivo("LOCFILME.DAT"); // Abre arquivo.
    if(ponteiro == NULL)
        exit(0); // Sai do programa.

    while(!feof(ponteiro)) // Enquanto não chegar ao final do arquivo então não para.
    {
        fread(&imprimirCliente, TAMLOCAFILME, 1, ponteiro); // Lê arquivo.
        strncpy(comparaCliente, imprimirCliente.nomeCliente, temp); // Copia nome do arquivo para variável de comparação.

        if(!feof(ponteiro))
                            // Se nomes forem iguais e excluir for igual a 0 e statos for igual a 1 então imprima.
            if(strnicmp(nomeCliente, comparaCliente, temp) == 0 && imprimirCliente.excluir == 0 && imprimirCliente.statusNota == 1)
            {                        // IMPRIME
                printf("\n-----------------------------------\n");
                printf("\nCodigo da Nota: %d", imprimirCliente.codigoNota);
                printf("\nCodigo cliente: %d", imprimirCliente.codigoCliente);
                printf("\nNome: %s", imprimirCliente.nomeCliente);
                printf("\nCodigo filme: %d", imprimirCliente.codigoFilme);
                printf("\nFilme: %s", imprimirCliente.nomeFilme);
                printf("\nValor: %2.2f\n", imprimirCliente.valor);
                printf("-----------------------------------\n");
                achou = 1; // Achou recebe 1.
                if(qtd > 4 && paraListagem == 1) // Contador para parar a listagem.
                {
                    getch(); // Para listagem.
                    qtd = 0; // Contador recebe 0.
                }
            }

    }
    fclose(ponteiro); // Fecha ponteiro.

    achouu(achou); // Chamada da função achou.
}
////////////////////////////////////////////////////////////////////////////////////////////////////



////////// FUNÇÕES AUXILIAR TRABALHO ///////////////////////////////////////////////////////////////

////////// Posiciona o cursor do console nas coordenadas coluna x e linha y //////////
void gotoxy(short x, short y) {
	HANDLE hConsoleOutput;
	COORD Cursor_Pos = {x, y};
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsoleOutput, Cursor_Pos);
}
//////////////////////////////////////////////////////////////////////////////////////

////////// Limpa a tela do console e posiciona o cursor na coluna 0 linha 0 //////////
void limpaTela(void) {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = {0, 0};
	DWORD count;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);
	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);
	SetConsoleCursorPosition(hStdOut, coord);
}
//////////////////////////////////////////////////////////////////////////////////////


////////// Achou /////////////////////////////////////////////////////////////////////
void achouu(int achou)
{
    if(achou == 0) // Se igual a zero então imprime.
    {
        printf("\n-----------------------------------\n");
        printf("\nRegistro nao encontrado.");
        printf("\n-----------------------------------\n");
    }
}
//////////////////////////////////////////////////////////////////////////////////////



////////// Listagem de direta ou por partes //////////////////////////////////////////
int listagemDiretaOuPartes(void)
{
    int paraListagem = 0; // Recebe número inteiro.
    int opcao = 0; // Recebe número inteiro.

    gotoxy(0,0);
    printf("(1)Listagem direta");
    gotoxy(0,1);
    printf("(2)Listagem por partes\n");
    scanf("%d", &opcao); // Recebe 1 ou 2.
    
    switch(opcao)
    {
        case 1: paraListagem = 0; break;
        case 2: paraListagem = 1; break; 
        default:
            printf("\n\nInvalido.");
        break;
    }
    limpaTela(); // Limpa tela.
    return(paraListagem); // Retorna valor.
}
////////////////////////////////////////////////////////////////////////////////////////////////////
