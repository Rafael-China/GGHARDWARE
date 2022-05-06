
																	//GG HARDWARE

#include <iostream>
#include <locale.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <iomanip>
#include <cstdlib>



						//Login "Marcelo123" Senha "GGHARDWARE123@" sendo que a senha precisa-se precionar espaço ao invés de ENTER.


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


//===================================================================================================================================================
//===================================================================================================================================================


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU PRODUTOS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void listagemdeperifericos () { //LISTAGEM DE PERIFERICOS "FAZ PARTE DA ABA PRODUTOS"
	
	fstream fin;
				HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
				vector<string> linhas;
				string linha, palavra, temp;
				fin.open("periferico.csv", ios::in);
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout<<"\t\t\t\t\t\t\t\t\t\t Lista de todos os Periféricos \n\n ";
	SetConsoleTextAttribute(h,7);
				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					cout << "\t\t\t\t\t Periférico " << linhas[0] << " \n\n ";
					cout << "Nome: " << linhas[1] << "\n";
            cout << "Marca: " << linhas[2] << "\n";
            cout << "Preço: R$ " << linhas[3] << "\n";
            cout << "Modelo: " << linhas[4] << "\n";
            cout << "======================================================== \n\n";
            
            
            }
	
}

void excluirhardware() { // excluir hardware "FAZ PARTE DA ABA PRODUTOS"
	
	int escolhaH ;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
system("cls");
cout<<"Versão do sistema 1.0\n\n";
SetConsoleTextAttribute(h,10);
cout <<"\t\t\t\t\t\t\t\t\t\t Excluir Hardwares \n\n ";
SetConsoleTextAttribute(h,7);
fstream fin, fout;
fin.open("hardware.csv", ios::in);
fout.open("atthardware.csv", ios::out);

int linhan1, linhan2, cont = 0;
string linha, palavra, temp;
vector<string> linhas;

cout << "Digite o código do hardware que você deseja excluir os dados: ";
cin >> linhan1;

while (fin >> temp) {
	
	linhas.clear();
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	while (getline(s, palavra, virgula)) {
	linhas.push_back(palavra);
	}
	
	int row_size = linhas.size(); 
	linhan2 = stoi(linhas[0]);
	
	if (linhan2 != linhan1) {
		if (!fin.eof()) {
			fout << ",";
			for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
        break;
    }
    
    if ( cont ==1){
    	
    	cout << "Produto excluído com sucesso!";
    	
		
		}else {
        cout << "O produto não foi encontrado!! Não foi possível excluir os dados! \n\n";
        system("pause");
	}
	fin.close();
	fout.close();
	
	remove("hardware.csv");
	rename("atthardware.csv", "hardware.csv");

int opex;
cout << "Digite o número correspondente à opção desejada.\n";
cout << "\n[1] Excluir outro hardware.\n";
	cout << "[0] Para voltar ao menu principal. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirhardware();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opção Inválida!";
			break;
	} 
	
}

void excluirperiferico() { // excluir periferico "FAZ PARTE DA ABA PRODUTOS"
	int escolhaP;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
system("cls");
cout<<"Versão do sistema 1.0\n\n";
SetConsoleTextAttribute(h,10);
cout <<"\t\t\t\t\t\t\t\t\t\t Excluir Periféricos \n\n";
SetConsoleTextAttribute(h,7);
fstream fin, fout;
fin.open("periferico.csv", ios::in);
fout.open("attperiferico.csv", ios::out);

int linhan1, linhan2, cont = 0;
string linha, palavra, temp;
vector<string> linhas;

cout << "Digite o código do periférico que você deseja excluir os dados: ";
cin >> linhan1;

while (fin >> temp) {
	
	linhas.clear();
	getline(fin, linha);
	
	stringstream s(linha);
	
	char virgula = ',';
	while (getline(s, palavra, virgula)) {
	linhas.push_back(palavra);
	}
	
	int row_size = linhas.size(); 
	linhan2 = stoi(linhas[0]);
	
	if (linhan2 != linhan1) {
		if (!fin.eof()) {
			fout << ",";
			for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof())
        break;
    }
    
    if (cont == 1) {
    
    cout<<"O produto foi excluído com sucesso!\n";
        	
		
    } else {
        cout << "O produto não foi encontrado!! Não foi possível excluir os dados! \n\n";
	}
	fin.close();
	fout.close();
	
	remove("periferico.csv");
	rename("attperiferico.csv", "periferico.csv");

int opex;
cout << "Digite o número correspondente à opção desejada.\n";
cout << "\n [1] Excluir outro periférico. \n";
	cout << "[0] Para voltar ao menu principal. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirperiferico();
			break;
		case 0:
			
			break;
		default:
			cout << "Opção Inválida!";
			break;
	} 
	
}

void categoriaProdutos () { //categorias dos produtos "FAZ PARTE DA ABA PRODUTOS"
	
	int escolhacategoria, categoriah, categoriap;
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout <<"\t\t\t\t\t\t\t\t\t\t Categorias de produtos \n\n";
	SetConsoleTextAttribute(h,7);
	cout<<"Faça sua escolha:\n [1] Hardware \n[2] Perifericos \n[3] Voltar ao menu principal\n";
	cin>>escolhacategoria;
	
	
	
	
	if (escolhacategoria == 1) {
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Hardware \n\n";
		SetConsoleTextAttribute(h,7);
	  cout << "Digite o número correspondente à categoria de Hardware que você deseja acessar: \n\n";
	  cout << "[1] Processador\n";
	  cout << "[2] Memória RAM\n";
	  cout << "[3] Placa mãe\n";
	  cout << "[4] HD \n";
	  cout << "[5] SSD\n";
	  cout << "[6] Placa de Vídeo\n";
	  cout << "[7] Gabinete\n";
	  cout << "[8] Fonte de Alimentação\n";
	  cout << "[9] Voltar ao menu de categorias\n";
	  cin >> categoriah;
	  cin.sync();
	  
	  while ((categoriah<=0)||(categoriah>=10)) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Hardware \n\n";
		SetConsoleTextAttribute(h,7);
		cout<<"Escolha uma opção válida:\n\n";
		cout << "Digite o número correspondente à categoria de Hardware que você deseja acessar: \n\n";
	  	cout << "[1] Processador\n";
	  	cout << "[2] Memória RAM\n";
	  	cout << "[3] Placa mãe\n";
	  	cout << "[4] HD \n";
	  	cout << "[5] SSD\n";
	  	cout << "[6] Placa de Vídeo\n";
	  	cout << "[7] Gabinete\n";
	  	cout << "[8] Fonte de Alimentação\n";
	  	cout << "[9] Voltar ao menu de categorias\n";
	  	cin >> categoriah;
			  
	}
	  if(categoriah == 1){
	
	  		system("cls");
	  		cout<<"Versão do sistema 1.0\n\n";
	  		SetConsoleTextAttribute(h,5);
	  		cout <<"\t\t\t\t\t\t\t\t\t\t Processador \n\n";
	  		SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Processador";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
					cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
	  		
	  	
	  	
	  	
	  	
	  } else if (categoriah == 2){
	  	
	  	system("cls");
	  	cout<<"Versão do sistema 1.0\n\n";
	  	SetConsoleTextAttribute(h,5);
	  	cout <<"\t\t\t\t\t\t\t\t\t\t Memória RAM \n\n";
	  	SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Memória RAM";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
					cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }


} else if (categoriah == 3){
	
	system("cls");
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,5);
	cout <<"\t\t\t\t\t\t\t\t\t\t Placa Mãe \n\n";
	SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Placa Mãe";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
					cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
	
	} else if (categoriah == 4){
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,5);
		cout <<"\t\t\t\t\t\t\t\t\t\t HD \n\n";
		SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " HD";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
		
		} else if (categoriah == 5){
			
			system("cls");
			cout<<"Versão do sistema 1.0\n\n";
			SetConsoleTextAttribute(h,5);
			cout <<"\t\t\t\t\t\t\t\t\t\t SSD \n\n";
			SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " SSD";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
			
			} else if (categoriah == 6){
				
				system("cls");
				cout<<"Versão do sistema 1.0\n\n";
				SetConsoleTextAttribute(h,5);
				cout <<"\t\t\t\t\t\t\t\t\t\t Placa de Vídeo \n\n";
				SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Placa de Vídeo";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
				
				} else if (categoriah == 7){
					
					system("cls");
					cout<<"Versão do sistema 1.0\n\n";
					SetConsoleTextAttribute(h,5);
					cout <<"\t\t\t\t\t\t\t\t\t\t Gabinete \n\n";
					SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Gabinete";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
					
					
					} else if (categoriah == 8){
						
						system("cls");
						cout<<"Versão do sistema 1.0\n\n";
						SetConsoleTextAttribute(h,5);
						cout <<"\t\t\t\t\t\t\t\t\t\t Fonte de Alimentação \n\n";
						SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Fonte de Alimentação";
	  		
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
						
						
	  	
	  	

	  } else if (categoriah == 9) {
	  
	  //volta ao menu de categorias
	  
	  categoriaProdutos ();
	   	
	  }

	
	int opex;
cout << "Digite o número correspondente à opção desejada: \n";
cout << "\n[1] Listar outro produto. \n";
	cout << "[0] Sair para o menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			categoriaProdutos ();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		cout << "Opção Inválida!";	
		}
			
			
	
		
		// caso a pessoa tenha digitado 2 e queira acessar as categorias de perifericos	
		
		} else if (escolhacategoria == 2) {
			
			system("cls");
			cout<<"Versão do sistema 1.0\n\n";
			SetConsoleTextAttribute(h,10);
			cout <<"\t\t\t\t\t\t\t\t\t\t Periféricos \n\n";
			SetConsoleTextAttribute(h,7);
			cout << "Digite o número correspondente à categoria de Periférico que você deseja acessar: \n\n";
	  cout << "[1] Mouse\n";
	  cout << "[2] Teclado\n";
	  cout << "[3] Monitor\n";
	  cout << "[4] Headset \n";
	  cout << "[5] Impressora\n";
	  cout << "[6] Voltar ao menu de categorias\n";
	  cin >> categoriap;
	  cin.sync();
	  
	  while ((categoriap<=0)||(categoriap>=7)) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Perifericos \n\n";
		SetConsoleTextAttribute(h,7);
		cout<<"Escolha uma opção válida:\n\n";
		cout << "Digite o número correspondente à categoria de Periférico que você deseja acessar: \n\n";
	  cout << "[1] Mouse\n";
	  cout << "[2] Teclado\n";
	  cout << "[3] Monitor\n";
	  cout << "[4] Headset \n";
	  cout << "[5] Impressora\n";
	  cout << "[6] Voltar ao menu de categorias\n";
	  cin >> categoriap;
	  cin.sync();
	  
		
		
	}
		
		if (categoriap == 1){
			
			system("cls");
			cout<<"Versão do sistema 1.0\n\n";
			SetConsoleTextAttribute(h,5);
			cout <<"\t\t\t\t\t\t\t\t\t\t Mouse \n\n";
			SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Mouse";
	  		
				fstream fin;
				fin.open("periferico.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Periférico " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
			
			
		} else if (categoriap == 2) {
			
			system("cls");
			cout<<"Versão do sistema 1.0\n\n";
			SetConsoleTextAttribute(h,5);
	  			cout <<"\t\t\t\t\t\t\t\t\t\t Teclado \n\n";
	  			SetConsoleTextAttribute(h,7);
	  		string tipo2;
	  		
	  		tipo2 = " Teclado";
	  		
				fstream fin;
				fin.open("periferico.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Periférico " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
		
		} else if (categoriap == 3) {
			
			system("cls");
	  		cout<<"Versão do sistema 1.0\n\n";
	  		SetConsoleTextAttribute(h,5);
	  		cout <<"\t\t\t\t\t\t\t\t\t\t Monitor \n\n";
	  		SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Monitor";
	  		
				fstream fin;
				fin.open("periferico.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Periférico " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
		
			} else if (categoriap == 4) {
				
				system("cls");
				cout<<"Versão do sistema 1.0\n\n";
				SetConsoleTextAttribute(h,5);
	  		cout <<"\t\t\t\t\t\t\t\t\t\t Headset \n\n";
	  		SetConsoleTextAttribute(h,7);
	  		string tipo2;
	  		
	  		tipo2 = " Headset";
	  		
				fstream fin;
				fin.open("periferico.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Periférico " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
					} else if (categoriap == 5) {
						
						system("cls");
						cout<<"Versão do sistema 1.0\n\n";
						SetConsoleTextAttribute(h,5);
						cout <<"\t\t\t\t\t\t\t\t\t\t Headset \n\n";
						SetConsoleTextAttribute(h,7);
	  		
	  		string tipo2;
	  		
	  		tipo2 = " Impressora";
	  		
				fstream fin;
				fin.open("periferico.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;

				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					if (linhas[5] == tipo2){
						
						cout << "\t\t\t\t\t Periférico " << linhas[0] << " \n\n";
						cout << "Categoria: " << linhas[5] << "\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
						
						
					}
					
            }
						
			} else if (categoriap == 6) {
								
								//volta ao menu categoria automaticamente
								
								categoriaProdutos ();
								
							}
								int opex;
cout << "Digite o número correspondente à opção desejada: \n";
cout << "\n [1] Listar outro produto. \n";
	cout << "[0] Voltar para o menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			categoriaProdutos ();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		cout << "Opção Inválida!";	
		}		
		
		} else if (escolhacategoria==3) {
			
			
		//volta ao menu pricipal automaticamente	
			
		} 	else {
			
			
			while ((escolhacategoria<=0)||(escolhacategoria>=4)) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";
		cout<<"Escolha uma opção válida!\n\n";
		cout<<"Faça sua escolha:\n [1] Hardware [2] Periféricos\n\n [3] Voltar ao menu principal\n";
		cin>>escolhacategoria;
		
	}
			
		}
	
		

system("pause");

}

void listagemdehardware() { // Listagem de produtos "FAZ PARTE DA ABA PRODUTOS"
				
				HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout<<"\t\t\t\t\t\t\t\t\t\t Lista de todos os Hardwares \n\n";
	SetConsoleTextAttribute(h,7);
				fstream fin;
				fin.open("hardware.csv", ios::in);
				vector<string> linhas;
				string linha, palavra, temp;
				while (fin >> temp) { 
				linhas.clear(); 
				getline(fin, linha);
				stringstream s(linha);
				char virgula = ',';
				while (getline(s, palavra, virgula)) {
					linhas.push_back(palavra);
					}
					
					cout << "\t\t\t\t\t Hardware " << linhas[0] << " \n\n";
					cout << "Nome: " << linhas[1] << "\n";
            		cout << "Marca: " << linhas[2] << "\n";
            		cout << "Preço: R$ " << linhas[3] << "\n";
           			cout << "Modelo: " << linhas[4] << "\n";
            		cout << "======================================================== \n\n";
            }
            
        listagemdeperifericos ();
				
            system("pause");
            }

void atualizacaodeprodutos () { //Atualização de produtos "FAZ PARTE DA ABA PRODUTOS"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	int HAOUPE;
	system("cls");
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout <<"\t\t\t\t\t\t\t\t\t\t Atualizar produto \n\n";
	SetConsoleTextAttribute(h,7);
	cout<<"Deseja atualizar:\n [1] Hardware\n [2] Periférico\n [3] Voltar ao menu Principal\n";
	cin>>HAOUPE;
	
	
	
	
	if (HAOUPE == 1) {
		
		//Atualização de hardware
		
		system("cls"); // Limpar tela anterior e exibir parte de atualizar dados dos clientes.
	
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout <<"\t\t\t\t\t\t\t\t\t\t Atualização de Hardware \n\n";
	SetConsoleTextAttribute(h,7);
	
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("hardware.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("atthardware.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, indice, sub, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, novo, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

    cout << "Digite o código do hardware que você deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();
SetConsoleTextAttribute(h,5);
    cout << "\t\t\t\t\t Alterar dados do hardware " << linhan1 << "  \n\n";
    SetConsoleTextAttribute(h,7);
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar a marca, Digite 2. \n";
    cout << "Para alterar o preço, Digite 3. \n";
    cout << "Para alterar a modelo, Digite 4. \n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	if (sub == 1) { // As alterações dependem da escolha do usuário, a variavel indice vai indicar qual valor será alterado.
  		
  		    cout << "\t\t\t\t\t Alterar nome do hardware  \n\n";
  			indice = 1;
  			
  		}else if(sub == 2){
		  
  			cout << "\t\t\t\t\t Alterar marca do hardware  \n\n";
  			indice = 2;
  		
  		
		  }else if (sub == 3) {
		  	
		  	cout << "\t\t\t\t\t Alterar preço do hardware  \n\n";
  			indice = 3;
		  	
		  } else if (sub == 4){
		  	
		  	cout << "\t\t\t\t\t Alterar modelo do hardware \n\n";
  			indice = 4;
		  	
		  }else{
		  
	        cout << "Opção Inválida!! \n";
	        atualizacaodeprodutos ();
			  			
	  }

    cout << "Informe o novo dado: "; // Variavel que armazena as novas informações do cliente
    getline(cin, novo);

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
  
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
        
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, atualize o cliente correspondente a ela.
            cont = 1; // caso seja verdadeira a condição
            stringstream convert; // A variavel convert é um objeto ou classe que passa o valor informado pelo o usuario para string.

            convert << novo; // Valor informado pelo usuario sendo convertido.

            linhas[indice] = convert.str(); // O valor é copiado para o indice informado e substituindo o valor anterior.
  
            if (!fin.eof()) { // Escreve o dado atualizado no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { // Escreve os dados existentes no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
		}
    }
    if (cont == 1) { // Caso condição verdadeira
        cout << "Os dados foram atualizados com Sucesso!! \n";
        system("pause");
        
        
      
	} else if (cont == 0) { // Caso condição falsa
    	cout << "O produto não foi encontrado!! Não foi possível atualizar os dados. \n\n";
    	system("pause");
    	atualizacaodeprodutos (); // Retorna ao inicio da função 
    	
	}

    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("hardware.csv"); // Remove o arquivo
    rename("atthardware.csv", "hardware.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
	
	atualizacaodeprodutos ();
			
		
	} else if (HAOUPE == 2) {
		
		//Atualização de Perifericos
		
		system("cls"); // Limpar tela anterior e exibir parte de atualizar dados dos clientes.
	
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout <<"\t\t\t\t\t\t\t\t\t\t Atualização de Periférico \n\n";
	SetConsoleTextAttribute(h,7);
	
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("periferico.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attperiferico.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, indice, sub, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, novo, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

    cout << "Digite o código do cliente que você deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();
SetConsoleTextAttribute(h,5);
    cout << "\t\t\t\t\t Alterar dados do Periféricos " << linhan1 << " \n\n";
    SetConsoleTextAttribute(h,7);
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar a marca, Digite 2. \n";
    cout << "Para alterar o preço , Digite 3. \n";
    cout << "Para alterar o modelo, Digite 4. \n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { // As alterações dependem da escolha do usuário, a variavel indice vai indicar qual valor será alterado.
  		case 1:
  		    cout << "\t\t\t\t\t Alterar nome do Periférico \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "\t\t\t\t\t Alterar marca do Periférico \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "\t\t\t\t\t Alterar preço do Periférico \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "\t\t\t\t\t Alterar modelo do Periférico \n\n";
  			indice = 4;
  			break;
  		default:
	        cout << "Opção Inválida!! \n";
	        atualizacaodeprodutos();
			break;  			
	  }

    cout << "Informe o novo dado: "; // Variavel que armazena as novas informações do cliente
    getline(cin, novo);

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
  
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
        
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, atualize o cliente correspondente a ela.
            cont = 1; // caso seja verdadeira a condição
            stringstream convert; // A variavel convert é um objeto ou classe que passa o valor informado pelo o usuario para string.

            convert << novo; // Valor informado pelo usuario sendo convertido.

            linhas[indice] = convert.str(); // O valor é copiado para o indice informado e substituindo o valor anterior.
  
            if (!fin.eof()) { // Escreve o dado atualizado no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { // Escreve os dados existentes no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
		}
    }
    if (cont == 1) { // Caso condição verdadeira
        cout << "Os dados foram atualizados com Sucesso!! \n";
        
	} else if (cont == 0) { // Caso condição falsa
    	cout << "O produto não foi encontrado!! Não foi possível atualizar os dados. \n\n";
    	system("pause");
    	atualizacaodeprodutos(); // Retorna ao inicio da função 
	}

    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("periferico.csv"); // Remove o arquivo
    rename("attperiferico.csv", "periferico.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    
    atualizacaodeprodutos ();
		
	}else if(HAOUPE==3){
		
		//Sai sozinho
		
	} else {
		
		while ((HAOUPE <= 0)||(HAOUPE >= 4)){
			
			system("cls");
			cout<<"Versão do sistema 1.0\n\n";
			SetConsoleTextAttribute(h,5);
				cout <<"\t\t\t\t\t\t\t\t\t\t Atualizar produto \n\n";
				SetConsoleTextAttribute(h,7);
			cout<<"\nCódigo Inválido\n\n";
			cout<<"Deseja atualizar: [1] Hardware\n [2]Periférico\n [3] Voltar ao menu Principal\n";
			cin>>HAOUPE;
			
		}
	}	
	
	
		
	
	
}

void cadastrarprodutosanunciados(){ //cadastramento de produtos anunciados  "FAZ PARTE DA ABA PRODUTOS"
	
	//================================ Cadastrar produtos anunciados ===================================
			
			HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
			system("cls"); // Limpar tela anterior e exibir cadastrar produtos anunciados.
	cout<<"Versão do sistema 1.0\n\n";
SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Produto(s) Anunciado(s) \n\n";
		SetConsoleTextAttribute(h,7);
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("produtoanunciado.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("produtoanunciado.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Você deseja cadastrar quantos produtos? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Produto(s):" << "\n\n";
  
    int codigo;
    string nome, modelo, preco, site;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
    	SetConsoleTextAttribute(h,5);
  		cout << "\t\t\t\t\t Adicionar produtos que estão em sites " << codigo << " \n\n";
  		SetConsoleTextAttribute(h,7);
  		cout << "Informe o nome do produto: ";
        getline(cin, nome);
        cout << "Informe o modelo do produto: ";
        getline(cin, modelo);
        cout << "Informe o preço do produto: ";
        getline(cin, preco);
        cout << "Informe o site em que está anunciado: ";
        getline(cin, site);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << modelo << ", "
             << preco << ", "
             << site
             << "\n";
    }
	cout << "Produto cadastrado com Sucesso! \n";
	
		int opex;

cout << "\nDigite 1 para cadastrar outro produto. \n";
	cout << "Digite 0 para sair para o menu principal. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			cadastrarprodutosanunciados();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		
		while ((opex>=3)||(opex<=0)){
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		cout << "Opção Inválida!";
		cout << "\nDigite 1 para cadastrar outro produto. \n";
		cout << "Digite 0 para sair para o menu principal. \n";
		cout << "=> ";
		cin >> opex;
	
	}
			
		}
	
	
	
}

void listarprodutosanunciados(){ //listagem de produtos anunciados "FAZ PARTE DA ABA PRODUTOS"
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Listar todos os Produtos Anunciados  \n\n";
	SetConsoleTextAttribute(h,7);
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("produtoanunciado.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
SetConsoleTextAttribute(h,5);
		cout << "\t\t\t\t\t Produto " << linhas[0] << " \n\n";
		SetConsoleTextAttribute(h,7);
			cout << "Código do Cadastramento: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Modelo: " << linhas[2] << "\n";
            cout << "Preço: R$ " << linhas[3] << "\n";
            cout << "Site: " << linhas[4] << "\n";
        cout << "======================================================== \n\n";

    }
	system("pause");
}
	


void MENUprodutos() { // menu de produtos dentro do VOID "ABA PRODUTOS"
	
	int menuprodutos1,escolhaoutros; 
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,6);
	cout <<"\t\t\t\t\t\t\t\t\t\t Produtos \n\n";
	SetConsoleTextAttribute(h,7);
	cout << "Digite o número correspondente ao que você deseja acessar: \n\n\n";
	cout << "[1] Cadastrar um novo produto\n";
	cout << "[2] Listar todos os produtos\n";
	cout << "[3] Categorias de produtos\n";
	cout << "[4] Excluir um produto cadastrado\n";
	cout << "[5] Cadastrar produtos anunciados em sites\n";
	cout << "[6] Produtos anunciados em sites\n";
	cout << "[7] Atualizar produto\n";
	cout << "[8] Voltar ao menu principal\n";
	cout << "[9] Encerrar o programa\n\n";
	cin >> menuprodutos1;
	
	//==============================================================
	
	//caso ele digite algum numero não listado
	
	while ((menuprodutos1>=10) || (menuprodutos1<=0)) {
		
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,6);
		cout <<"\t\t\t\t\t\t\t\t\t\t Produtos \n\n";
		SetConsoleTextAttribute(h,7);
		cout<<"Opção inválida\n\n\n";
	cout << "Digite o número correspondente ao que você deseja acessar: \n\n\n";
	cout << "[1] Cadastrar um novo produto\n";
	cout << "[2] Listar todos os produtos\n";
	cout << "[3] Categorias de produtos\n";
	cout << "[4] Excluir um produto cadastrado\n";
	cout << "[5] Produtos vendidos\n";
	cout << "[6] Listar produtos anunciados em sites\n";
	cout << "[7] Aualizar produto\n";
	cout << "[8] Voltar ao menu principal\n";
	cout << "[9] Encerrar o programa\n\n";
	cin >> menuprodutos1;
		
	}
	
	int escolhacadastro, tipohardware, tipoperiferico;

	switch (menuprodutos1){
	
	case 1:
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novos Produtos \n\n";
		SetConsoleTextAttribute(h,7);
		cout << "Você deseja cadastrar um:\n";
		cout << "[1] Hardware\n";
		cout << "[2] Periférico\n";
		
		cin >> escolhacadastro;
		cin.sync();
		
		
		while ((escolhacadastro>=3) || (escolhacadastro<=0)) {
		
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novos Produtos \n\n";
		SetConsoleTextAttribute(h,7);
		cout<<"Opção inválida\n\n\n";
		cout << "Você deseja cadastrar um:\n";
		cout << "[1] Hardware\n";
		cout << "[2] Periférico\n";
		cin >> escolhacadastro;
		cin.sync();
		
	}
		if (escolhacadastro == 1){
			
	
		
		//=========================== cadastrar um novo produto hardware ===================================
		
		
		system("cls"); // Limpar tela anterior e exibir parte cadastrar clientes.
	
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Hardware \n\n";
	SetConsoleTextAttribute(h,7); 
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("hardware.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("hardware.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Você deseja cadastrar quantos hardwares? ";
	cin >> n;
    cin.sync();
    
  
  //selecionar a categoria para  poder separar o produto na aba de CATEGORIAS
  
  system ("cls");
  cout<<"Versão do sistema 1.0\n\n";
  SetConsoleTextAttribute(h,10);
  cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Hardware \n\n";
  SetConsoleTextAttribute(h,7);
  cout << "Digite o número correspondente a categoria de hardware que você deseja cadastrar:\n";
  cout << "[1] Processador\n";
  cout << "[2] Memória RAM\n";
  cout << "[3] Placa mãe\n";
  cout << "[4] HD \n";
  cout << "[5] SSD\n";
  cout << "[6] Placa de Vídeo\n";
  cout << "[7] Gabinete\n";
  cout << "[8] Fonte de Alimentação\n";
  cout << "[9] Voltar ao menu de escolha de produtos\n";
  cin >> tipohardware;
  cin.sync();
  
  
  while ((tipohardware>=10) || (tipohardware<=0)) {
		
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Hardware \n\n";
		SetConsoleTextAttribute(h,7);
		cout<<"Opção inválida\n\n\n";
		cout << "Digite o número correspondente a categoria de hardware que você deseja cadastrar:\n";
		cout << "[1] Processador\n";
  		cout << "[2] Memória RAM\n";
  		cout << "[3] Placa mãe\n";
  		cout << "[4] HD \n";
  		cout << "[5] SSD\n";
  		cout << "[6] Placa de Vídeo\n";
  		cout << "[7] Gabinete\n";
  		cout << "[8] Fonte de Alimentação\n";
  		cout << "[9] Voltar ao menu de escolha de produtos\n";
	 	cin >> tipohardware;
  		cin.sync();
		
	}
  
  
  if (tipohardware == 1){
  	
  	string tipo;
  	tipo ="Processador";
  	system("cls");
  	SetConsoleTextAttribute(h,5);
  	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Processador(es) \n\n";
  	SetConsoleTextAttribute(h,7);
  	
  	cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  
    
		int codigo;
    	string nome, marca, preco, modelo;


    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4]
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";
	
  	system("pause");
  	
  	
  } else if (tipohardware == 2){
  	string tipo;
  	tipo = "Memória RAM";
  	system("cls");
  	SetConsoleTextAttribute(h,5);
  	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Nova(s) Memoria(s) RAM \n\n";
  	SetConsoleTextAttribute(h,7);
  			cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  
    int codigo;
    	string nome, marca, preco, modelo;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";

system("pause");
	
	
  } else if (tipohardware == 3){
  	string tipo;
  	tipo = "Placa Mãe";
  	system("cls");
  	
  				int codigo;
    	string nome, marca, preco, modelo;
    	SetConsoleTextAttribute(h,5);
    	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Nova(s) Placa(s) Mãe(s) \n\n";
    	SetConsoleTextAttribute(h,7);
  				cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  
    

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";

system("pause");
  				
  	
  	
  } else if (tipohardware == 4){
  	string tipo;
  	tipo = "HD";
  	system("cls");
  	SetConsoleTextAttribute(h,5);
  	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) HD(S) \n\n";
  	 SetConsoleTextAttribute(h,7);
  					 cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  int codigo;
    	string nome, marca, preco, modelo;
    

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";

system("pause");
  	
  } else if (tipohardware == 5){
string tipo;
  	tipo = "SSD";
  	system("cls");
  	SetConsoleTextAttribute(h,5);
  					 	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) SSD(s) \n\n";
  					 	SetConsoleTextAttribute(h,7); 
  					 	cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  
    int codigo;
    	string nome, marca, preco, modelo;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";

  	system("pause");
  	
  } else if(tipohardware == 6){
string tipo;
  	tipo = "Placa de Vídeo";
  	system("cls");
  					 		
  			int codigo;
    	string nome, marca, preco, modelo;		 
		SetConsoleTextAttribute(h,5);	
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Nova(s) Placa(s) de Vídeo(s) \n\n";
		SetConsoleTextAttribute(h,7);	
  					 		
  					 		cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  
    

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";

  system("pause");
  } else if(tipohardware == 7){
string tipo;
  	tipo = "Gabinete";
  	system("cls");
  					 			
  					 			int codigo;
    	string nome, marca, preco, modelo;
    	SetConsoleTextAttribute(h,5);
    	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Gabinete(s) \n\n";
    	SetConsoleTextAttribute(h,7);
  					 			cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";
	 system("pause");
  	
  } else if (tipohardware == 8){
string tipo;
  	tipo = "Fonte de Alimentação";
  	system("cls");
  					 				int codigo;
    	string nome, marca, preco, modelo;
    	SetConsoleTextAttribute(h,5);
    	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Nova(s) Fonte(s) de Alimentação \n\n";
    	SetConsoleTextAttribute(h,7);
  					 				cout << "Informe as informações de " << n << " Hardware:" << "\n\n";
  

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Hardware " << codigo << " \n\n";
  		cout << "Informe o Nome do Hardware: ";
        getline(cin, nome);
        cout << "Informe a Marca do Hardware: ";
        getline(cin, marca);
        cout << "Informe o Preço do Hardware: R$ ";
        getline(cin, preco);
        cout << "Informe o Modelo do Hardware: ";
        getline(cin, modelo);
        
        
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , marca[2] , preco[3] , modelo[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";
system("pause");
		 				
  	
  	
  } else if (tipohardware == 9) {
  	
  	MENUprodutos();
  	
  }
}

if(escolhacadastro == 2){

	
		
		//=========================== cadastrar um novo produto periférico ===================================
		
		
		
		system("cls"); // Limpar tela anterior e exibir parte cadastrar clientes.
		
	
    cout<<"Versão do sistema 1.0\n\n";
	system("cls");
	SetConsoleTextAttribute(h,10);
	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Periféricos \n\n";
	SetConsoleTextAttribute(h,7);
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("periferico.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("periferico.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Você deseja cadastrar quantos periféricos? ";
	cin >> n;
    cin.sync();
    
    
    //============================================================================
    
    //selecionar a categoria para poder separar o produto na aba de CATEGORIAS
  
  //==============================================================================
  
  cout << "Digite o número correspondente a categoria de periférico que você deseja cadastrar:\n\n";
  cout << "[1] Mouse\n";
  cout << "[2] Teclado\n";
  cout << "[3] Monitor\n";
  cout << "[4] HeadSet \n";
  cout << "[5] Impressora\n";
  cout << "[6] Voltar ao menu de escolha de produtos\n";
  cin >> tipoperiferico;
  cin.sync();
    
   while ((tipoperiferico>=7) || (tipoperiferico<=0)) {
		
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Perifericos \n\n";
		SetConsoleTextAttribute(h,7);
		cout<<"Opção inválida\n\n\n";
	cout << "Digite o número correspondente a categoria de hardware que você deseja cadastrar:\n";
  cout << "[1] Mouse\n";
  cout << "[2] Teclado\n";
  cout << "[3] Monitor\n";
  cout << "[4] HeadSet \n";
  cout << "[5] Impressora\n";
  cout << "[6] Voltar ao menu de escolha de produtos";
  cin >> tipoperiferico;
  cin.sync();
		
	}
    
    
    if (tipoperiferico == 1){
    	string tipo1;
    	tipo1 = "Mouse";
    system("cls");
    		int codigo;
    	string nome, marca, preco, modelo;
    	SetConsoleTextAttribute(h,5);
    	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar novo(s) Mouse(s) \n\n";
    	SetConsoleTextAttribute(h,7);
    		cout << "Informe os dados de " << n << " Periférico(s):" << "\n\n";
  
    

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Periférico " << codigo << " \n\n";
  		cout << "Informe o nome do periférico: ";
        getline(cin, nome);
        cout << "Informe a marca do periférico: ";
        getline(cin, marca);
        cout << "Informe o preco do periférico: R$ ";
        getline(cin, preco);
        cout << "Informe o modelo do periférico: ";
        getline(cin, modelo);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo1 << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";

system("pause");
		
	} else if (tipoperiferico == 2){
		string tipo1;
		 system("cls");
    	tipo1 = "Teclado";
    			system("cls");
    			SetConsoleTextAttribute(h,5);
    			cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Teclado(s) \n\n";
    			SetConsoleTextAttribute(h,7);
    			cout << "Informe os dados de " << n << " Periférico(s):" << "\n\n";
  
   int codigo;
    	string nome, marca, preco, modelo;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Periférico " << codigo << " \n\n";
  		cout << "Informe o nome do periférico: ";
        getline(cin, nome);
        cout << "Informe a marca do periférico: ";
        getline(cin, marca);
        cout << "Informe o preco do periférico: R$ ";
        getline(cin, preco);
        cout << "Informe o modelo do periférico: ";
        getline(cin, modelo);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo1 << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";


		system("pause");
			

	} else if (tipoperiferico == 3){
	string tipo1;
    	tipo1 = "Monitor";
    	 system("cls");
    				int codigo;
    	string nome, marca, preco, modelo;
    	system("cls");
    	SetConsoleTextAttribute(h,5);
    	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Monitor(es) \n\n";
		SetConsoleTextAttribute(h,7);
    				cout << "Informe os dados de " << n << " Periférico(s):" << "\n\n";
  
    
    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Periférico " << codigo << " \n\n";
  		cout << "Informe o nome do periférico: ";
        getline(cin, nome);
        cout << "Informe a marca do periférico: ";
        getline(cin, marca);
        cout << "Informe o preco do periférico: R$ ";
        getline(cin, preco);
        cout << "Informe o modelo do periférico: ";
        getline(cin, modelo);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo1 << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";
		
	system("pause");
	} else if(tipoperiferico == 4){
		string tipo1;
		 system("cls");
    	tipo1 = "Headset";
		
    					int codigo;
    	string nome, marca, preco, modelo;
    	system("cls");
    	SetConsoleTextAttribute(h,5);
    	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Headset(s) \n\n";
    	SetConsoleTextAttribute(h,7);
    					cout << "Informe os dados de " << n << " Periférico(s):" << "\n\n";
  
    
    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Periférico " << codigo << " \n\n";
  		cout << "Informe o nome do periférico: ";
        getline(cin, nome);
        cout << "Informe a marca do periférico: ";
        getline(cin, marca);
        cout << "Informe o preco do periférico: R$ ";
        getline(cin, preco);
        cout << "Informe o modelo do periférico: ";
        getline(cin, modelo);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo1 << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";
system("pause");

			

		
	} else if(tipoperiferico == 5){
		string tipo1;
    	tipo1 = "Impressora";
    	system("cls");
	
    						int codigo;
    	string nome, marca, preco, modelo;
    	SetConsoleTextAttribute(h,5);
    	cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Nova(s) Impressora(s) \n\n";
    	SetConsoleTextAttribute(h,7);
    						cout << "Informe os dados de " << n << " Periférico(s):" << "\n\n";
  
   

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Periférico " << codigo << " \n\n";
  		cout << "Informe o nome do periférico: ";
        getline(cin, nome);
        cout << "Informe a marca do periférico: ";
        getline(cin, marca);
        cout << "Informe o preco do periférico: R$ ";
        getline(cin, preco);
        cout << "Informe o modelo do periférico: ";
        getline(cin, modelo);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << marca << ", "
             << preco << ", "
             << modelo << ", "
             << tipo1 << ", "
             << "\n";
    }
	cout << "Os dados foram armazenados com Sucesso! \n";
system("pause");

	
	} else if (tipoperiferico == 6) {
		
		MENUprodutos();
		
	}
    	
    					
    }							
    		
    	break;

		
		case 2:
			
			
				listagemdehardware();
			
			
			
		break;
		
		case 3:
			
			
				categoriaProdutos ();
			
			
			
		break;
		
		case 4:
			
			// excluir produtos
			system("cls");
			cout<<"Versão do sistema 1.0\n\n";
			SetConsoleTextAttribute(h,10);
			cout <<"\t\t\t\t\t\t\t\t\t\t Excluir um produto cadastrado \n\n";
			SetConsoleTextAttribute(h,7);
				cout<<"Digite o número correspondente ao que você deseja excluir:\n [1] Hardware\n [2] Periférico\n"; 
				cin>>escolhaoutros;
				
				if (escolhaoutros == 1) {
					
					excluirhardware();
					
				} else if (escolhaoutros == 2) {
					
					excluirperiferico();	
					
				} else {
					
					while ((escolhaoutros>=3)&&(escolhaoutros<=0)) {
						
						system("cls");
						cout<<"Versão do sistema 1.0\n\n";
						cout<<"Digite uma opção válida";
						SetConsoleTextAttribute(h,10);
						cout <<"\t\t\t\t\t\t\t\t\t\t Excluir um produto cadastrado \n\n";
						SetConsoleTextAttribute(h,7);
						cout<<"Digite o número correspondente ao que você deseja excluir:\n [1] Hardware\n [2] Periférico\n"; 
						cin>>escolhaoutros;
						
					}
					
					
				}
			
			
			
		break;
		
		case 5:
			
		cadastrarprodutosanunciados();
		
		break;
		
		case 6:
			
			listarprodutosanunciados();
				
		
		break;
		
		case 7:
			
			atualizacaodeprodutos ();
			
		
		
			
			
			
		break;
		
		case 8:
				//volta automaticamente para o menu principal
			
			
		break;
		
		case 9:
	//encerra o programa em geral, não precisa colocar nada aqui.
			exit (0);
	} 

system("cls");	
cout<<"Versão do sistema 1.0\n\n";
	
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//===================================================================================================================================================
//===================================================================================================================================================




//===================================================================================================================================================
//===================================================================================================================================================


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU CLIENTES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cadastrarclientes() { //cadastrar novos clientes no sistema "FAZ PARTE DA ABA CLIENTES"
	
	//================================ Cadastrar novo cliente ===================================
			
			HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
			system("cls"); // Limpar tela anterior e exibir cadastrar clientes.
	cout<<"Versão do sistema 1.0\n\n";
SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Cliente(s) \n\n";
		SetConsoleTextAttribute(h,7);
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("clientes.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Você deseja cadastrar quantos clientes? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Cliente(s):" << "\n\n";
  
    int codigo, idade;
    string nome, telefone, email, cpf, cidade;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
    	SetConsoleTextAttribute(h,5);
  		cout << "\t\t\t\t\t Adicionar Cliente " << codigo << " \n\n";
  		SetConsoleTextAttribute(h,7);
  		cout << "Informe o nome completo do cliente: ";
        getline(cin, nome);
        cout << "Informe o telefone do cliente: ";
        getline(cin, telefone);
        cout << "Informe o e-mail do cliente: ";
        getline(cin, email);
        cout << "Informe a idade do cliente: ";
        cin >> idade;
        cin.sync();
        cout << "Informe o cpf do cliente: ";
        getline(cin, cpf);
        cout << "Informe a cidade em que o cliente reside: ";
        getline(cin, cidade);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << telefone << ", "
             << email << ", "
             << idade << ", "
             << cpf << ", "
             << cidade
             << "\n";
    }
	cout << "Cliente cadastrado com Sucesso! \n";
	
		int opex;

cout << "\nDigite 1 para cadastrar outro cliente. \n";
	cout << "Digite 0 para sair para o menu principal. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			cadastrarclientes();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		
		while ((opex>=3)||(opex<=0)){
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		cout << "Opção Inválida!";
		cout << "\nDigite 1 para cadastrar outro cliente. \n";
		cout << "Digite 0 para sair para o menu principal. \n";
		cout << "=> ";
		cin >> opex;
	
	}
			
		}
}

void listartodosclientes() { //listar todos os clientes cadastrados no sistema "FAZ PARTE DA ABA CLIENTES"
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Listar todos os Clientes  \n\n";
	SetConsoleTextAttribute(h,7);
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
SetConsoleTextAttribute(h,5);
		cout << "\t\t\t\t\t Cliente " << linhas[0] << " \n\n";
		SetConsoleTextAttribute(h,7);
			cout << "Código do Cliente: " << linhas[0] << "\n";
            cout << "Nome Completo: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "Idade: " << linhas[4] << "\n";
            cout << "CPF: " << linhas[5] << "\n";
            cout << "Cidade: " << linhas[6] << "\n";
            
        cout << "======================================================== \n\n";

    }
	system("pause");
}

void pesquisarcliente(){ //Pesquisa de clientes "FAZ PARTE DA ABA CLIENTES"
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");  // Limpar tela anterior e exibir parte buscar clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Pesquisar Clientes \n\n";
	SetConsoleTextAttribute(h,7);

    fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    cout << "Digite o código do cliente para visualizar seus dados: ";
    cin >> linhan1;
  
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
        
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, mostre o cliente correspondente a ela.
        
  			int op; 
  			
            cont = 1; // caso seja verdadeira a condição
            cout << "\t\t\t\t\t Cliente " << linhas[0] << " \n\n";
            cout << "Código do Cliente: " << linhas[0] << "\n";
            cout << "Nome Completo: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "Idade: " << linhas[4] << "\n";
            cout << "CPF: " << linhas[5] << "\n";
            cout << "Cidade: " << linhas[6] << "\n";
            cout << "======================================================== \n\n"; 
            
            
            // Opções de pesquisar novamente ou sair desta ação de busca.
            
				int opex;

	cout << "\nDigite 1 para listar outro cliente. \n";
	cout << "Digite 0 para sair para o menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			pesquisarcliente();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		
		while ((opex>=3)||(opex<=0)) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para listar outro cliente. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}
		}	
		        
    }
    
    if (cont == 0) { // condição explicado acima.
        cout << "Dados não encontrados... \n";
        system ("pause");
        pesquisarcliente(); // retorna ao inicio da busca.
	}
	
	
	}

}

void atualizarcliente(){ //Atualização de clientes "FAZ PARTE DA ABA CLIENTES"
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de atualizar dados dos clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Atualizar dados de Clientes \n\n";
	SetConsoleTextAttribute(h,7);
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attclientes.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, indice, sub, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, novo, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

    cout << "Digite o código do cliente que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

    cout << "\t\t\t\t\t Alterar dados do cliente " << linhan1 << " \n\n";
    cout << "Para alterar o nome, Digite 1. \n";
    cout << "Para alterar o telefone, Digite 2. \n";
    cout << "Para alterar o e-mail, Digite 3. \n";
    cout << "Para alterar a idade, Digite 4. \n";
    cout << "Para alterar o cpf, Digite 5. \n\n";
    cout << "Para alterar a cidade, Digite 6. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { // As alterações dependem da escolha do usuário, a variavel indice vai indicar qual valor será alterado.
  		case 1:
  		    cout << "\t\t\t\t\t Alterar nome do cliente \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "\t\t\t\t\t Alterar telefone do cliente \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "\t\t\t\t\t Alterar e-mail do cliente \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "\t\t\t\t\t Alterar idade do cliente \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "\t\t\t\t\t Alterar CPF do cliente \n\n";
  			indice = 5;
  			break;
  		case 6:
  			cout << "\t\t\t\t\t Alterar Cidade do cliente \n\n";
  			indice = 6;
  			break;
  		default:
	        cout << "Opção Inválida!! \n";
	        system ("pause");
	        atualizarcliente();
			break;  			
	  }

    cout << "Informe o novo dado: "; // Variavel que armazena as novas informações do cliente
    getline(cin, novo);

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
  
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
        
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, atualize o cliente correspondente a ela.
            cont = 1; // caso seja verdadeira a condição
            stringstream convert; // A variavel convert é um objeto ou classe que passa o valor informado pelo o usuario para string.

            convert << novo; // Valor informado pelo usuario sendo convertido.

            linhas[indice] = convert.str(); // O valor é copiado para o indice informado e substituindo o valor anterior.
  
            if (!fin.eof()) { // Escreve o dado atualizado no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { // Escreve os dados existentes no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
		}
    }
    if (cont == 1) { // Caso condição verdadeira
        cout << "Dados atualizados com Sucesso!! \n";
	} else if (cont == 0) { // Caso condição falsa
    	cout << "O cliente não foi encontrado! Não foi possível atualizar os dados. \n\n";
    	atualizarcliente(); // Retorna ao inicio da função 
	}

    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("clientes.csv"); // Remove o arquivo
    rename("attclientes.csv", "clientes.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    	int opex;

cout << "\nDigite 1 para atualizar os dados de outro cliente. \n";
	cout << "Digite 0 para sair para o menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			atualizarcliente();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
			
			
		while (opex>=2) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para atualizar os dados de outro cliente. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}	
		}
} 

void excluircliente(){ //Excluir clientes "FAZ PARTE DA ABA CLIENTES"
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de excluir dados dos clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Excluir Clientes do Sistema \n\n";
	SetConsoleTextAttribute(h,7);

    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("clientes.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attclientes.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

	cout << "Digite o código do cliente que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha);  // separa os dados por linha
  
  		char virgula = ','; // Variavel recebe a virgula como separador dos dados
  		
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.

        if (linhan2 != linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, exclui o cliente correspondente a ela
        	
            if (!fin.eof()) { // Escreve os dados existentes, exceto o dado deletado, no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
    }
    if (cont == 1) {
        cout << "Os dados foram deletados com sucesso!! \n";
    } else {
        cout << "Cliente não foi encontrado! Não foi Possivel excluir os dados. \n\n";
	}
		
    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("clientes.csv"); // Remove o arquivo
    rename("attclientes.csv", "clientes.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    int opex; // Opções de excluir novamente ou sair desta ação de deletar dados.
	cout << "Deseja excluir outro cliente? Digite 1. \n";
	cout << "Deseja sair para o menu principal? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluircliente();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opção Inválida!";
			break;
	} 
	
}

void adicionarcompra(){ //adicionar compras "FAZ PARTE DA ABA CLIENTES"
	
	//================================ Cadastrar nova compra ===================================
			
			HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
			system("cls"); // Limpar tela anterior e exibir cadastrar clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Cadastrar Nova Compra \n\n";
	SetConsoleTextAttribute(h,7);
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("comprasloja.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("comprasloja.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
	  
    cout << "Informe os dados da compra realizada pela loja:" << "\n\n";
  
    int codigo;
    string categoriaproduto, nomep, valorp, vendedor, data;

    codigo = x; // Objetivo da variavel x citada acima.

    	for (int i = 0; i < 1; i++){
		
    	codigo++;
  		cout << "Informe a categoria do produto (Hardware/Periférico): \n ";
        cin >> categoriaproduto;
        cin.sync();
        cout << "Informe o nome do produto: \n";
        getline(cin, nomep);
        cout << "Informe o valor que foi pago: R$ \n";
        getline(cin, valorp);
        cout << "Informe quem vendeu o produto: \n";
        getline(cin, vendedor);
        cout << "Informe a data da compra (no formato dd/mm/aaaa): \n";
        getline(cin, data);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << categoriaproduto << ", "
             << nomep << ", "
             << valorp << ", "
             << vendedor << ", "
             << data
             << "\n";
             
             cout << "Compra registrada com Sucesso! \n";
}

	int opex;

cout << "\nDigite 1 para adicionar outra compra. \n";
	cout << "Digite 0 para sair para menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			adicionarcompra ();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		while (opex>=3) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para adicionar outra compra. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}	
		}
	

	
}	

void historicocompras(){ //historico de compras "FAZ PARTE DA ABA CLIENTES"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Listar todas as compras \n\n";
	SetConsoleTextAttribute(h,7);
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("comprasloja.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }

		cout << "\t\t\t\t\t Compra " << linhas[0] << " \n\n";
		
			cout << "Código da Compra: " << linhas[0] << "\n";
            cout << "Categoria: " << linhas[1] << "\n";
            cout << "Nome do Produto: " << linhas[2] << "\n";
            cout << "Valor pago: R$ " << linhas[3] << "\n";
            cout << "Vendido por: " << linhas[4] << "\n";
            cout << "Data de aquisição: " << linhas[5] << "\n";
        cout << "======================================================== \n\n";

	
}

	system("pause");
}
		
void adicionarvenda(){ //adicionar venda "FAZ PARTE DA ABA CLIENTES"
	
	//================================ Cadastrar nova compra ===================================
			HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
			
			system("cls"); // Limpar tela anterior e exibir cadastrar clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Cadastrar Nova Venda \n\n";
	SetConsoleTextAttribute(h,7);
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("vendasloja.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("vendasloja.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
	  
    cout << "Informe os dados da venda realizada pela loja:" << "\n\n";
  
    int codigo;
    string categoriaproduto, nomep, valorp, comprador, data;

    codigo = x; // Objetivo da variavel x citada acima.

    	for (int i = 0; i < 1; i++){
		
    	codigo++;
  		cout << "Informe a categoria do produto (Hardware/Periférico): \n ";
        cin >> categoriaproduto;
        cin.sync();
        cout << "Informe o nome do produto: \n";
        getline(cin, nomep);
        cout << "Informe o valor de venda: R$ \n";
        getline(cin, valorp);
        cout << "Informe quem comprou o produto: \n";
        getline(cin, comprador);
        cout << "Informe a data da venda (no formato dd/mm/aaaa): \n";
        getline(cin, data);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << categoriaproduto << ", "
             << nomep << ", "
             << valorp << ", "
             << comprador << ", "
             << data
             << "\n";
             
             cout << "Compra registrada com Sucesso! \n";
}
	
	
	int opex;

cout << "\nDigite 1 para adicionar outra venda. \n";
	cout << "Digite 0 para sair para menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			adicionarvenda();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		while (opex>=3) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para adicionar outra venda. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}	
		}
	
	
}
	
void historicovendas(){ // historico de vendas "FAZ PARTE DA ABA CLIENTES"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Listar todas as compras \n\n";
	SetConsoleTextAttribute(h,7);
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("vendasloja.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }

		cout << "\t\t\t\t\t Venda " << linhas[0] << " \n\n";
		
			cout << "Código da Venda: " << linhas[0] << "\n";
            cout << "Categoria: " << linhas[1] << "\n";
            cout << "Nome do Produto: " << linhas[2] << "\n";
            cout << "Valor de venda: R$ " << linhas[3] << "\n";
            cout << "Comprador: " << linhas[4] << "\n";
            cout << "Data da venda: " << linhas[5] << "\n";
        cout << "======================================================== \n\n";

	
}

	system("pause");	
	
	
	
}

void MENUclientes () { // menu de clientes NO VOID "ABA CLIENTES"

system("cls");
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	int tabelaClientes;
cout<<"Versão do sistema 1.0\n\n";
 SetConsoleTextAttribute(h,6);
	cout << "\t\t\t\t\t\t\t\t\t\t Clientes \n\n";
	SetConsoleTextAttribute(h,7);		
	cout<<"Digite o número correspondente a opção que você deseja: \n[01] Cadastrar um novo cliente. \n[02] Listar todos os clientes. \n[03] Pesquisar Cliente. \n[04] Atualizar os dados de algum cliente.\n[05] Excluir Cliente.\n[06] Adicionar uma nova compra. \n[07] Histórico de compras.  \n[08] Adicionar uma nova venda.\n[09] Histórico de Vendas.\n[10] Voltar para o menu pricipal. \n[11] Encerrar o Programa.\n";
	cin>>tabelaClientes;
	
	if (tabelaClientes == 1) {
		

			cadastrarclientes();
		
		} else if (tabelaClientes == 2){
		
			
			listartodosclientes();
			
		} else if (tabelaClientes == 3){
			
			
			pesquisarcliente();
			
		} else if (tabelaClientes == 4){
		
			
			atualizarcliente();
		
		
			
		} else if (tabelaClientes == 5){
			
			excluircliente();
			
			} else if (tabelaClientes == 6){
			
			adicionarcompra();
			
		} else if (tabelaClientes == 7){
			
			historicocompras();
		
			
			} else if (tabelaClientes == 8){
			
			adicionarvenda();
			
		} else if (tabelaClientes == 9){
			
			historicovendas();
				

		} else if (tabelaClientes == 10){
			
			//volta automaticamente para o menu principal
			
			
		} else if ( tabelaClientes == 11) {
			
			exit (0);
			
		} else {
			
			cout << "Opção Inválida!";
			system("pause");
			MENUclientes();
			
		}
		
	
system("cls");
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//===================================================================================================================================================
//===================================================================================================================================================




//===================================================================================================================================================
//===================================================================================================================================================


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU FORNECEDORES ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cadastrarfornecedor (){ //cadastrar fornecedor "FAZ PARTE DA ABA FORNECEDORES"
		
		//================================ Cadastrar novo Fornecedor ===================================
			HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
			
			system("cls"); // Limpar tela anterior e exibir cadastrar clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Fornecedor(es) \n\n";
	SetConsoleTextAttribute(h,7);
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("fornecedores.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Você deseja cadastrar quantos fornecedores? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Fornecedor(es):" << "\n\n";
  
    int codigo;
    string nomef, telefonef, emailf, cnpj, cidadef, categoriaf, tipof;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Fornecedor " << codigo << " \n\n";
  		cout << "Informe o nome do fornecedor: ";
        getline(cin, nomef);
        cout << "Informe o telefone do fornecedor: ";
        getline(cin, telefonef);
        cout << "Informe o e-mail do fornecedor: ";
        getline(cin, emailf);
        cout << "Informe o CNPJ do fornecedor: ";
        getline(cin, cnpj);
        cout << "Informe a cidade em que o fornecedor se localiza: ";
        getline(cin, cidadef);
        cout << "Ele fornece qual categoria de produto? (Hardware ou Periférico) \n";
        getline(cin, categoriaf);
        cout << "Digite o tipo de Hardware ou Periférico que é fornecida por ele(a): ";
        getline(cin, tipof);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nomef << ", "
             << telefonef << ", "
             << emailf << ", "
             << cnpj << ", "
             << cidadef << ", "
             << categoriaf << ", "
             << tipof
             << "\n";
    }
	cout << "Fornecedor cadastrado com Sucesso! \n";
	
	int opex;

cout << "\nDigite 1 para adicionar outro fornecedor. \n";
	cout << "Digite 0 para sair para menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			cadastrarfornecedor ();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		while (opex>=3) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para adicionar outro fornecedor. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}	
		}
		
		
	}	

void listarfornecedor (){ //listar todos os fornecedores "FAZ PARTE DA ABA FORNECEDORES"

	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Listar todos os Fornecedores \n\n";
	SetConsoleTextAttribute(h,7);
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }

		cout << "\t\t\t\t\t Fornecedor " << linhas[0] << " \n\n";
		
			cout << "Código do Fornecedor: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "CNPJ: " << linhas[4] << "\n";
            cout << "Cidade: " << linhas[5] << "\n";
            cout << "Categoria: " << linhas[6] << "\n";
            cout << "Tipo: " << linhas[7] << "\n";
            
        cout << "======================================================== \n\n";

    }
	system("pause");
	
}

void pesquisarfornecedor(){ //pesquisar fornecedores "FAZ PARTE DA ABA FORNECEDORES"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");  // Limpar tela anterior e exibir parte buscar clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Pesquisar Fornecedor \n\n";
	SetConsoleTextAttribute(h,7);

    fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    cout << "Digite o código do fornecedor para visualizar os seus dados: ";
    cin >> linhan1;
  
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
        
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, mostre o cliente correspondente a ela.
        
  			int op; 
  			
            cont = 1; // caso seja verdadeira a condição
            
            cout << "\t\t\t\t\t Fornecedor " << linhas[0] << " \n\n";
		
			cout << "Código do Fornecedor: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "CNPJ: " << linhas[4] << "\n";
            cout << "Cidade: " << linhas[5] << "\n";
            cout << "Categoria: " << linhas[6] << "\n";
            cout << "Tipo: " << linhas[7] << "\n";
            
        cout << "======================================================== \n\n"; 
            
            
            // Opções de pesquisar novamente ou sair desta ação de busca.
            
				int opex;

	cout << "\nDigite 1 para pesquisar outro fornecedor. \n";
	cout << "Digite 0 para sair para menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			pesquisarfornecedor();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		while (opex>=3) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para pesquisar outro fornecedor. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}
		}	
		        
    }
    
    if (cont == 0) { // condição explicado acima.
        cout << "Dados não encontrados... \n";
        pesquisarfornecedor(); // retorna ao inicio da busca.
	}
	
	
	}
	
}

void atualizarfornecedor(){ //pesquisar fornecedores "FAZ PARTE DA ABA FORNECEDORES"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de atualizar dados dos clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Atualizar dados de Fornecedores \n\n";
	SetConsoleTextAttribute(h,7);
	
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attfornecedores.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, indice, sub, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, novo, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

    cout << "Digite o código do fornecedor que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

    cout << "\t\t\t\t\t Alterar dados do fornecedor " << linhan1 << " \n\n";
    cout << "Para alterar o Nome, Digite 1. \n";
    cout << "Para alterar o Telefone, Digite 2. \n";
    cout << "Para alterar o E-mail, Digite 3. \n";
    cout << "Para alterar o CNPJ, Digite 4. \n";
    cout << "Para alterar a Cidade, Digite 5. \n\n";
    cout << "Para alterar a Categoria, Digite 6. \n\n";
    cout << "Para alterar o tipo, Digite 7. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { // As alterações dependem da escolha do usuário, a variavel indice vai indicar qual valor será alterado.
  		case 1:
  		    cout << "\t\t\t\t\t Alterar nome do fornecedor \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "\t\t\t\t\t Alterar telefone do fornecedor \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "\t\t\t\t\t Alterar e-mail do fornecedor \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "\t\t\t\t\t Alterar CNPJ do fornecedor \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "\t\t\t\t\t Alterar Cidade do fornecedor \n\n";
  			indice = 5;
  			break;
  		case 6:
  			cout << "\t\t\t\t\t Alterar Categoria do fornecedor \n\n";
  			indice = 6;
  			break;
  		case 7:
  			cout << "\t\t\t\t\t Alterar Tipo do fornecedor \n\n";
  			indice = 7;
  			break;
  		default:
	        cout << "Opção Inválida!! \n";
	        atualizarfornecedor();
			break;  			
	  }

    cout << "Informe o novo dado: "; // Variavel que armazena as novas informações do cliente
    getline(cin, novo);

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
  
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
        
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, atualize o cliente correspondente a ela.
            cont = 1; // caso seja verdadeira a condição
            stringstream convert; // A variavel convert é um objeto ou classe que passa o valor informado pelo o usuario para string.

            convert << novo; // Valor informado pelo usuario sendo convertido.

            linhas[indice] = convert.str(); // O valor é copiado para o indice informado e substituindo o valor anterior.
  
            if (!fin.eof()) { // Escreve o dado atualizado no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { // Escreve os dados existentes no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
		}
    }
    if (cont == 1) { // Caso condição verdadeira
        cout << "Os dados foram atualizados com Sucesso!! \n";
	} else if (cont == 0) { // Caso condição falsa
    	cout << "O fornecedor não foi encontrado! Não foi possível atualizar os dados! \n\n";
    	atualizarfornecedor(); // Retorna ao inicio da função 
	}

    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("fornecedores.csv"); // Remove o arquivo
    rename("attfornecedores.csv", "fornecedores.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    	int opex;

cout << "\nDigite 1 para atualizar dados de outro cliente. \n";
	cout << "Digite 0 para sair para menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			atualizarfornecedor();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		while (opex>=2) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para listar outro cliente. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}	
		}
	
}

void excluirfornecedor(){ //excluir fornecedores "FAZ PARTE DA ABA FORNECEDORES"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de excluir dados dos clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Excluir Fornecedores do Sistema \n\n";
	SetConsoleTextAttribute(h,7);

    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("fornecedores.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attfornecedores.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

	cout << "Digite o código do fornecedor que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha);  // separa os dados por linha
  
  		char virgula = ','; // Variavel recebe a virgula como separador dos dados
  		
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.

        if (linhan2 != linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, exclui o cliente correspondente a ela
        	
            if (!fin.eof()) { // Escreve os dados existentes, exceto o dado deletado, no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
    }
    if (cont == 1) {
        cout << "Os dados foram deletados com sucesso!! \n";
    } else {
        cout << "O fornecedor não foi localizado!! Não foi possível excluir os dados! \n\n";
	}
		
    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("fornecedores.csv"); // Remove o arquivo
    rename("attfornecedores.csv", "fornecedores.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    int opex; // Opções de excluir novamente ou sair desta ação de deletar dados.
	cout << "Deseja excluir outro fornecedor? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirfornecedor();
			break;
		case 0:
			system("pause");
			break;
		default:
			while (opex>=2) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "Deseja excluir outro fornecedor? Digite 1. \n";
		cout << "Deseja sair? Digite 0. \n";
		cout << "=> ";
		cin >> opex;
	}
			break;
	} 
	
	
}

void MENUfornecedores() { // menu de fonecedores NO VOID "ABA FORNECEDORES"

system("cls");
HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	int tabelafornecedor;
cout<<"Versão do sistema 1.0\n\n";
SetConsoleTextAttribute(h,6);
	cout << "\t\t\t\t\t\t\t\t\t\t Fornecedores \n\n";	
	SetConsoleTextAttribute(h,7);	
	cout<<"Digite o número correspondente a opção que você deseja acessar: \n[01] Cadastrar novo fornecedor. \n[02] Listar todos fornecedores. \n[03] Pesquisar Fornecedor. \n[04] Atualizar Fornecedor. \n[05] Excluir Fornecedor \n[06] Voltar ao menu principal. \n[07] Encerrar o programa.\n";
	cin>>tabelafornecedor;
	
	if (tabelafornecedor == 1) {
		
			cadastrarfornecedor ();
		
	} else if(tabelafornecedor == 2) {
		
		
		listarfornecedor();
		
	} else if (tabelafornecedor == 3){
		
		pesquisarfornecedor();
		
		
	} else if (tabelafornecedor == 4){
		
		atualizarfornecedor();
		
	} else if (tabelafornecedor == 5){
		
		excluirfornecedor();
		
	} else if (tabelafornecedor == 6){
		
		//voltar ao menu principal
		
	} else if (tabelafornecedor == 7){
		
		exit(0);
		
	} else {
	
		cout << "Opção Inválida!";
		system("pause");
		MENUfornecedores;
	}
		
system("pause");	
	}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//===================================================================================================================================================
//===================================================================================================================================================




//===================================================================================================================================================
//===================================================================================================================================================


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU PARCEIROS ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void cadastrarparceiros(){  //cadastrar novo parceiro "FAZ PARTE DA ABA PARCEIROS"
	
	//================================ Cadastrar novo Parceiro ===================================
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);		
			
			system("cls"); // Limpar tela anterior e exibir cadastrar clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Parceiro(s) \n\n";
	SetConsoleTextAttribute(h,7);
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("parceiros.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("parceiros.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Voce deseja cadastrar quantos parceiros? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Parceiro(s):" << "\n\n";
  
    int codigo;
    string nomep, telefonep, emailp, cnpjp, cidadep;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
  		cout << "\t\t\t\t\t Adicionar Parceiro " << codigo << " \n\n";
  		cout << "Informe o nome do parceiro: ";
        getline(cin, nomep);
        cout << "Informe o telefone do parceiro: ";
        getline(cin, telefonep);
        cout << "Informe o e-mail do parceiro: ";
        getline(cin, emailp);
        cout << "Informe o CNPJ do parceiro: ";
        getline(cin, cnpjp);
        cout << "Informe a cidade em que o parceiro se localiza: ";
        getline(cin, cidadep);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nomep << ", "
             << telefonep << ", "
             << emailp << ", "
             << cnpjp << ", "
             << cidadep 
             << "\n";
    }
	cout << "Parceiro cadastrado com Sucesso! \n";
	
	int opex;

cout << "\nDigite 1 para adicionar outro parceiro. \n";
	cout << "Digite 0 para sair para menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			cadastrarparceiros ();
			
		}else if (opex==0){
		
			system ("pause");
			//volta automaticamente para o menu principal
			
			
		}else{
		while (opex>=2) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para adicionar outro parceiro. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}	
		}
	
}

void listarparceiros(){ // Listagem de parceiros "FAZ PARTE DA ABA PARCEIROS"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Listar todos os Parceiros \n\n";
	SetConsoleTextAttribute(h,7);
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("parceiros.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }

		cout << "\t\t\t\t\t Parceiros " << linhas[0] << " \n\n";
		
			cout << "Código do Parceiro: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Telefone: " << linhas[2] << "\n";
            cout << "E-mail: " << linhas[3] << "\n";
            cout << "CNPJ: " << linhas[4] << "\n";
            cout << "Cidade: " << linhas[5] << "\n";
        cout << "======================================================== \n\n";

    }
	system("pause");
	
}

void atualizarparceiros(){ // atualizar parceiros "FAZ PARTE DA ABA PARCEIROS"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de atualizar dados dos clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Atualizar dados de Parceiro \n\n";
	SetConsoleTextAttribute(h,7);
	
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("parceiros.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attparceiros.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, indice, sub, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, novo, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

    cout << "Digite o código do parceiro que deseja atualizar os dados: ";
    cin >> linhan1;
    cin.sync();

    cout << "\t\t\t\t\t Alterar dados do parceiro " << linhan1 << " \n\n";
    cout << "Para alterar o Nome, Digite 1. \n";
    cout << "Para alterar o Telefone, Digite 2. \n";
    cout << "Para alterar o E-mail, Digite 3. \n";
    cout << "Para alterar o CNPJ, Digite 4. \n";
    cout << "Para alterar a Cidade, Digite 5. \n\n";
    cout << "=> ";
    cin >> sub;
  	cin.sync();
  	
  	switch(sub) { // As alterações dependem da escolha do usuário, a variavel indice vai indicar qual valor será alterado.
  		case 1:
  		    cout << "\t\t\t\t\t Alterar nome do parceiro \n\n";
  			indice = 1;
  			break;
  		case 2:
  			cout << "\t\t\t\t\t Alterar telefone do parceiro \n\n";
  			indice = 2;
  			break;
  		case 3:
  			cout << "\t\t\t\t\t Alterar e-mail do parceiro \n\n";
  			indice = 3;
  			break;
  		case 4:
  			cout << "\t\t\t\t\t Alterar CNPJ do parceiro \n\n";
  			indice = 4;
  			break;
  		case 5:
  			cout << "\t\t\t\t\t Alterar Cidade do parceiro \n\n";
  			indice = 5;
  			break;
  		case 6:
  			cout << "\t\t\t\t\t Alterar Categoria do parceiro \n\n";
  			indice = 6;
  			break;
  		case 7:
  			cout << "\t\t\t\t\t Alterar Tipo do parceiro \n\n";
  			indice = 7;
  			break;
  		default:
	        cout << "Opção Inválida!! \n";
	        system("pause");
	        atualizarcliente();
			break;  			
	  }

    cout << "Informe o novo dado: "; // Variavel que armazena as novas informações do cliente
    getline(cin, novo);

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
  
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.
        
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
  
        if (linhan2 == linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, atualize o cliente correspondente a ela.
            cont = 1; // caso seja verdadeira a condição
            stringstream convert; // A variavel convert é um objeto ou classe que passa o valor informado pelo o usuario para string.

            convert << novo; // Valor informado pelo usuario sendo convertido.

            linhas[indice] = convert.str(); // O valor é copiado para o indice informado e substituindo o valor anterior.
  
            if (!fin.eof()) { // Escreve o dado atualizado no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {

                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        else {
            if (!fin.eof()) { // Escreve os dados existentes no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
  
                    fout << linhas[i] << ",";
                }
  
                fout << linhas[row_size - 1] << "\n";
            }
        }
        if (fin.eof()) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
		}
    }
    if (cont == 1) { // Caso condição verdadeira
        cout << "Os dados foram atualizados com Sucesso!! \n";
	} else if (cont == 0) { // Caso condição falsa
    	cout << "O parceiro não foi encontrado!! Não foi possível atualizar os dados! \n\n";
    	atualizarfornecedor(); // Retorna ao inicio da função 
	}

    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("parceiros.csv"); // Remove o arquivo
    rename("attparceiros.csv", "parceiros.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    	int opex;

cout << "\nDigite 1 para atualizar dados de outro parceiro. \n";
	cout << "Digite 0 para sair para menu inicial. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			atualizarparceiros();
			
		}else if (opex==0){
		
			system("pause");
			
			//volta automaticamente para o menu principal
			
			
		}else{
		while (opex>=2) {
		
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";	
		cout << "Opção Inválida!";	
		cout << "\nDigite 1 para atualizar dados de outro parceiro. \n";
		cout << "Digite 0 para sair para o menu inicial. \n";
		cout << "=> ";
		cin >> opex;
	}	
		}
	
}

void excluirparceiros(){ //excluir parceiros "FAZ PARTE DA ABA PARCEIROS"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls"); // Limpar tela anterior e exibir parte de excluir dados dos clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Excluir Parceiro do Sistema \n\n";
	SetConsoleTextAttribute(h,7);

    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("parceiros.csv", ios::in); // Abre e ler o arquivo se ele existir

    fout.open("attparceiros.csv", ios::out); // Cria um novo arquivo se ele não existir, neste caso temporariamente até que seja atualizado, backup.
  
    int linhan1, linhan2, cont = 0; // se cont manter-se 0 nenhum dado ou arquivo foi encontrado.
    string linha, palavra, temp;
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]

	cout << "Digite o código do parceiro que deseja excluir os dados: ";
    cin >> linhan1;

    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
        getline(fin, linha); // Busca os dados linha por linha
        stringstream s(linha);  // separa os dados por linha
  
  		char virgula = ','; // Variavel recebe a virgula como separador dos dados
  		
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
            linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
  
        int row_size = linhas.size(); // A variavel row_size armazena quantas linhas de dados contém no arquivo.
        linhan2 = stoi(linhas[0]); // variavel linhan2 recebe o valor da posição [0] - código - como string convertido para inteiro.

        if (linhan2 != linhan1) { // Se a variavel linhan2 for igual a variavel linhan1 informada pelo usuario, exclui o cliente correspondente a ela
        	
            if (!fin.eof()) { // Escreve os dados existentes, exceto o dado deletado, no arquivo temporario criado anteriomente attclientes.
            	
            	fout << ",";
            	
                for (int i = 0; i < row_size - 1; i++) {
                    fout << linhas[i] << ",";
                }
                fout << linhas[row_size - 1] << "\n";
            }
            
        } else {
            cont = 1;
        }
        if (fin.eof()) // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
            break;
    }
    if (cont == 1) {
        cout << "Dados deletados com sucesso!! \n";
    } else {
        cout << "O parceiro não foi encontrado! Não foi possível excluir os dados. \n\n";
	}
		
    fin.close(); // fecha a leitura do arquivo.
    fout.close(); // fecha a escrita no arquivo.

    remove("parceiros.csv"); // Remove o arquivo
    rename("attparceiros.csv", "parceiros.csv"); // Renomeia o aquivo temporario para o nome do arquivo principal com os dados atualizados.
    
    int opex; // Opções de excluir novamente ou sair desta ação de deletar dados.
	cout << "Deseja excluir outro parceiro? Digite 1. \n";
	cout << "Deseja sair? Digite 0. \n";
	cout << "=> ";
	cin >> opex;	
    
    switch(opex) {
    	case 1:
			excluirparceiros();
			break;
		case 0:
			system("pause");
			break;
		default:
			cout << "Opção Inválida!";
			break;
	} 
}

void produtosanunciadosparceiros(){ //cadastrar anunciantes "FAZ PARTE DA ABA PARCEIROS"
	
	//================================ Cadastrar produtos anunciados ===================================
			
			HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
			system("cls"); // Limpar tela anterior e exibir cadastrar produtos anunciados.
	cout<<"Versão do sistema 1.0\n\n";
SetConsoleTextAttribute(h,10);
		cout <<"\t\t\t\t\t\t\t\t\t\t Cadastrar Novo(s) Produto(s) Anunciado(s) por Parceiros \n\n";
		SetConsoleTextAttribute(h,7);
	    
    fstream fin, fout; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    				  // fin = file in = arquivo de entrada, fout = file out - arquivo de saida

    fin.open("produtoanunciadoparceiro.csv", ios::in); // Abre e ler o arquivo se ele existir
    
    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    int x = 0;
  
  	while(fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
	  
	    linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL
	
	    getline(fin, linha); // Busca os dados linha por linha
	
	    stringstream s(linha); // separa os dados por linha
	    
	    char virgula = ','; // Variavel recebe a virgula como separador dos dados

	    while (getline(s, palavra, virgula)) { // Cada linha tem variis dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
	    }
	    x = stoi(linhas[0]); // variavel x recebe o valor da posição [0] - código - como string convertido para inteiro.
	    // Esta parte tem como objetivo buscar o ultimo código, para quando precisar adcionar um novo cliente sempre com um id diferente dos existentes.
	}

    fout.open("produtoanunciadoparceiro.csv", ios::out | ios::app); // Cria um novo arquivo se ele não existir.
    
    int n;
	    
    cout << "Você deseja cadastrar quantos produtos? ";
	cin >> n;
    cin.sync();
  
    cout << "Informe os dados de " << n << " Produto(s):" << "\n\n";
  
    int codigo;
    string nome, nomep, modelo, preco, site;

    codigo = x; // Objetivo da variavel x citada acima.

    for (int i = 0; i < n; i++) {
    	
    	codigo++;
    	SetConsoleTextAttribute(h,5);
  		cout << "\t\t\t\t\t Adicionar produtos que estão em sites " << codigo << " \n\n";
  		SetConsoleTextAttribute(h,7);
  		cout << "Informe o nome do produto: ";
        getline(cin, nome);
        cout << "Informe o modelo do produto: ";
        getline(cin, modelo);
        cout << "Informe o preço do produto: ";
        getline(cin, preco);
        cout << "Informe o site em que está anunciado: ";
        getline(cin, site);
        cout << "Informe o nome do parceiro: ";
        getline(cin,nomep);
        cout << "=======================================================> \n\n";
  
        fout << ", " // Gravar os dados no arquivo criado ou lido anteriormente. 
			 << codigo << ", " // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5] 
             << nome << ", "
             << modelo << ", "
             << preco << ", "
             << site << ", "
             << nomep
             << "\n";
    }
	cout << "Produto cadastrado com Sucesso! \n";
	
		int opex;

cout << "\nDigite 1 para cadastrar outro produto. \n";
	cout << "Digite 0 para sair para o menu principal. \n";
	cout << "=> ";
	cin >> opex;	
    
    if (opex==1) {
    	
			produtosanunciadosparceiros();
			
		}else if (opex==0){
		
			
			//volta automaticamente para o menu principal
			
			
		}else{
		
		while ((opex>=3)||(opex<=0)){
		
		system("cls");
		cout<<"Versão do sistema 1.0\n\n";
		cout << "Opção Inválida!";
		cout << "\nDigite 1 para cadastrar outro produto. \n";
		cout << "Digite 0 para sair para o menu principal. \n";
		cout << "=> ";
		cin >> opex;
	
	}
			
		}
	
	
	
	
}

void listaranunciadosparceiros(){ //listagem dos anunciantes "FAZ PARTE DA ABA PARCEIROS"
	
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
system("cls"); // Limpar tela anterior e exibir parte de listar todos os clientes.
	cout<<"Versão do sistema 1.0\n\n";
	SetConsoleTextAttribute(h,10);
	cout << "\t\t\t\t\t\t\t\t\t\t Listar todos os Produtos Anunciados por Parceiros  \n\n";
	SetConsoleTextAttribute(h,7);
	
	fstream fin; // Biblioteca ou Classe que cria obejtos ou variaveis para manipular arquivos externos.
    			// fin = file in = arquivo de entrada, fout = file out - arquivo de saida
    
    fin.open("produtoanunciadoparceiro.csv", ios::in); // Abre e ler o arquivo se ele existir

    vector<string> linhas; // criado um vetor linhas do tipo string - ex. linhas[5]
    string linha, palavra, temp;
  
    while (fin >> temp) { // Verifica e ler os dados do arquivo, retorna true enquanto tive dados e false se atingir seu limite.
  
        linhas.clear(); // Remove todos os dados do vetor. ex. linhas = 0 ou nULL

        getline(fin, linha); // Busca os dados linha por linha
  
        stringstream s(linha); // separa os dados por linha
        
        char virgula = ','; // Variavel recebe a virgula como separador dos dados
  
        while (getline(s, palavra, virgula)) { // Cada linha tem varios dados que são sepadados por virgula e armazenado no vetor linhas.
			linhas.push_back(palavra); // ,1[0] , nome[1] , telefone[2] , email[3] , idade[4] , cpf[5]
        }
SetConsoleTextAttribute(h,5);
		cout << "\t\t\t\t\t Produto " << linhas[0] << " \n\n";
		SetConsoleTextAttribute(h,7);
			cout << "Código do Cadastramento: " << linhas[0] << "\n";
            cout << "Nome: " << linhas[1] << "\n";
            cout << "Modelo: " << linhas[2] << "\n";
            cout << "Preço: R$ " << linhas[3] << "\n";
            cout << "Site: " << linhas[4] << "\n";
            cout << "Nome do Parceiro: " << linhas[5] << "\n";
        cout << "======================================================== \n\n";

    }
	system("pause");
	
	
}



void MENUparceiros(){ //MENU DE PARCEIROS "ABA PARCEIROS"
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	system("cls");
cout<<"Versão do sistema 1.0\n\n";
int tabelaparceiros;
//preciso colocar em todos a opção de finalizar programa usando o "exit(0)"
SetConsoleTextAttribute(h,6);
	cout << "\t\t\t\t\t\t\t\t\t\t Parceiros \n\n";	
	 SetConsoleTextAttribute(h,7);
	cout<<"Digite o número correspondente a opção que você deseja acessar: \n[01] Cadastrar novos parceiros \n[02] Listar Todos Parceiros. \n[03] Atualizar Parceiros. \n[04] Excluir Parceiros. \n[05] Cadastrar Produtos Anunciados por Parceiros \n[06] Listar Produtos Anunciados por Parceiros  \n[07] Voltar ao menu principal. \n[08] Encerrar o programa.\n"; 
	cin>>tabelaparceiros;	
	cin.sync();
	
	if (tabelaparceiros == 1) {
		
		cadastrarparceiros();
				
		}else if (tabelaparceiros == 2){
			
			listarparceiros();
			
		} else if (tabelaparceiros == 3){
			
			atualizarparceiros();
			
		} else if (tabelaparceiros == 4){
			
			excluirparceiros();
			
		} else if (tabelaparceiros == 5){
			
			produtosanunciadosparceiros();
			
		} else if (tabelaparceiros == 6){
			
			listaranunciadosparceiros();
			
		} else if (tabelaparceiros == 7){
			
			system("pause");
			
		} else if(tabelaparceiros == 8){
			
			exit(0);
			
			
		} else {
		
		cout << "Opção Inválida!";
		system("pause");
		MENUparceiros();	
			
		}
			
			
		
	
	
system("cls");	

}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//===================================================================================================================================================
//===================================================================================================================================================




//===================================================================================================================================================
//===================================================================================================================================================


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ MENU SUPORTE ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void MENUsuporte () { //suporte
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
		system ("cls");
		cout<<"Versão do sistema 1.0\n\n";
		 SetConsoleTextAttribute(h,6);
		cout <<"\t\t\t\t\t\t\t\t\t\t Ajuda \n\n";
		 SetConsoleTextAttribute(h,7);
		cout <<"Dúvidas frequentes:\n\n Caso eu perca onde cliquei no sistema, como faço para identificar em qual menu estou?\n\n\tEm nosso sistema, prezamos muito pela localização do nosso cliente, em qualquer menu onde o usuario entrar, estará localizado no canto superior da tela o nome do menu \n\tonde o próprio clicou.\n";
		cout<<"\nQualquer dúvida entre em contato com um de nossos desenvolvedores através dos e-mails (Favor colocar no assunto: GG-HARDWARE): \n\n0000877038@senaimgaluno.com.br (Rafael)\n0000875904@senaimgaluno.com.br (Hicaro)\n\n";
		system("pause");
	
}

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//===================================================================================================================================================
//===================================================================================================================================================




//===================================================================================================================================================
//===================================================================================================================================================


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ TELA DE BEM VINDO ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void bemvindo() { //tela de bem vindo
	char aa = ' ';
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(h,1);
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	Sleep(500);
	cout <<setw(30)<<SetConsoleTextAttribute(h,3);cout << "########  ######## ##     ##               ##     ## #### ##    ## ########   #######        #### #### ####\n";
	Sleep(500);
	cout <<setw(30)<<SetConsoleTextAttribute(h,4);cout << "##     ## ##       ###   ###               ##     ##  ##  ###   ## ##     ## ##     ##       #### #### ####\n";
	Sleep(500);
	cout <<setw(30)<<SetConsoleTextAttribute(h,5);cout << "##     ## ##       #### ####               ##     ##  ##  ####  ## ##     ## ##     ##       #### #### ####\n";
	Sleep(500);
	cout <<setw(30)<<SetConsoleTextAttribute(h,6);cout << "########  ######   ## ### ##    #######    ##     ##  ##  ## ## ## ##     ## ##     ##        ##   ##   ## \n";
	Sleep(500);
	cout <<setw(30)<<SetConsoleTextAttribute(h,7);cout << "##     ## ##       ##     ##                ##   ##   ##  ##  #### ##     ## ##     ##					  \n";
	Sleep(500);
	cout <<setw(30)<<SetConsoleTextAttribute(h,1);cout << "##     ## ##       ##     ##                 ## ##    ##  ##   ### ##     ## ##     ##       #### #### ####\n";
	Sleep(500);
	cout <<setw(30)<<SetConsoleTextAttribute(h,2);cout << "########  ######## ##     ##                  ###    #### ##    ## ########   #######        #### #### ####\n";
	Sleep(500);
	system("cls");
	Sleep(600);
	system("cls");
	Sleep(600);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,5);cout << "########  ######## ##     ##               ##     ## #### ##    ## ########   #######        #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,6);cout << "##     ## ##       ###   ###               ##     ##  ##  ###   ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,7);cout << "##     ## ##       #### ####               ##     ##  ##  ####  ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,1);cout << "########  ######   ## ### ##    #######    ##     ##  ##  ## ## ## ##     ## ##     ##        ##   ##   ## \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,2);cout << "##     ## ##       ##     ##                ##   ##   ##  ##  #### ##     ## ##     ##					  \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,3);cout << "##     ## ##       ##     ##                 ## ##    ##  ##   ### ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,4);cout << "########  ######## ##     ##                  ###    #### ##    ## ########   #######        #### #### ####\n";
	Sleep(600);
	system("cls");
	Sleep(600);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,6);cout << "########  ######## ##     ##               ##     ## #### ##    ## ########   #######        #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,7);cout << "##     ## ##       ###   ###               ##     ##  ##  ###   ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,1);cout << "##     ## ##       #### ####               ##     ##  ##  ####  ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,2);cout << "########  ######   ## ### ##    #######    ##     ##  ##  ## ## ## ##     ## ##     ##        ##   ##   ## \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,3);cout << "##     ## ##       ##     ##                ##   ##   ##  ##  #### ##     ## ##     ##					  \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,4);cout << "##     ## ##       ##     ##                 ## ##    ##  ##   ### ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,5);cout << "########  ######## ##     ##                  ###    #### ##    ## ########   #######        #### #### ####\n";
	Sleep(600);
	system("cls");
	Sleep(600);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,2);cout << "########  ######## ##     ##               ##     ## #### ##    ## ########   #######        #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,3);cout << "##     ## ##       ###   ###               ##     ##  ##  ###   ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,1);cout << "##     ## ##       #### ####               ##     ##  ##  ####  ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,2);cout << "########  ######   ## ### ##    #######    ##     ##  ##  ## ## ## ##     ## ##     ##        ##   ##   ## \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,7);cout << "##     ## ##       ##     ##                ##   ##   ##  ##  #### ##     ## ##     ##					  \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,4);cout << "##     ## ##       ##     ##                 ## ##    ##  ##   ### ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,5);cout << "########  ######## ##     ##                  ###    #### ##    ## ########   #######        #### #### ####\n";
	Sleep(600);
	system("cls");
	Sleep(600);
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,1);cout << "########  ######## ##     ##               ##     ## #### ##    ## ########   #######        #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,2);cout << "##     ## ##       ###   ###               ##     ##  ##  ###   ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,3);cout << "##     ## ##       #### ####               ##     ##  ##  ####  ## ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,4);cout << "########  ######   ## ### ##    #######    ##     ##  ##  ## ## ## ##     ## ##     ##        ##   ##   ## \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,5);cout << "##     ## ##       ##     ##                ##   ##   ##  ##  #### ##     ## ##     ##					  \n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,6);cout << "##     ## ##       ##     ##                 ## ##    ##  ##   ### ##     ## ##     ##       #### #### ####\n";
	cout <<setw(30)<<SetConsoleTextAttribute(h,7);cout << "########  ######## ##     ##                  ###    #### ##    ## ########   #######        #### #### ####\n";
	Sleep(600);
		
}
	
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//===================================================================================================================================================
//===================================================================================================================================================




//===================================================================================================================================================
//===================================================================================================================================================


//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ LOGIN DO SISTEMA ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

void loginsistema() { //login do sistema
	
	
string login;
char senhaADM[40];
int conta;
//tela inicial de login do adm 
    

	cout<<"Versão do sistema 1.0\n\n";
cout << "\n\n\n\n\n\n\n";	

HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
   

    SetConsoleTextAttribute(h,3);
	
cout <<setw(115)<<"    ###     ######  ######## ########  ######  ##     ##\n";
cout <<setw(115)<<"   ## ##   ##    ##    ##    ##       ##    ## ##     ##\n";
cout <<setw(115)<<"  ##   ##  ##          ##    ##       ##       ##     ##\n";
cout <<setw(115)<<" ##     ##  ######     ##    ######   ##       #########\n";
cout <<setw(115)<<" #########       ##    ##    ##       ##       ##     ##\n";
cout <<setw(115)<<" ##     ## ##    ##    ##    ##       ##    ## ##     ##\n";
cout <<setw(115)<<" ##     ##  ######     ##    ########  ######  ##     ##\n";
	
SetConsoleTextAttribute(h,7);
	
	 time_t timer;
  struct tm *horarioLocal;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  int dia = horarioLocal->tm_mday;
  int mes = horarioLocal->tm_mon + 1;
  int ano = horarioLocal->tm_year + 1900;

  int hora = horarioLocal->tm_hour;
  int min  = horarioLocal->tm_min;
  int sec  = horarioLocal->tm_sec;
  
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t      Data: "    << dia  << "/" << mes << "/" << ano << endl;
    cout << "\t\t\t\t\t\t\t\t\t      Horário: " << hora << ":" << min << endl;
    cout << "\n\n\n\n\n\n\n\n";
	cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t Login de administrador: ";
	getline(cin, login);
	cout<<"\n\n\t\t\t\t\t\t\t\tDigite a senha do administrador: ";
	
	//mascarar a senha
	
	fflush(stdin);
	for (int x = 0; x < 39; x++){
		senhaADM[x] = getch();
		putchar ('*');
			if (GetKeyState (VK_RETURN) < 0){
				x = 39;
			}

}

	
	
	for(int i = 0; i < 39; i++){
		
		if (senhaADM[i] == 'G'){
			
			conta++;
			
		} else if (senhaADM[i] == 'H'){
			conta++;
			
		} else if (senhaADM[i] == 'A'){
			conta++;
			} else if (senhaADM[i] == 'R'){
			conta++;
			
		} else if (senhaADM[i] == 'D'){
			conta++;
			} else if (senhaADM[i] == 'W'){
			conta++;
			
		} else if (senhaADM[i] == 'A'){
			conta++;
			} else if (senhaADM[i] == 'R'){
			conta++;
			
		} else if (senhaADM[i] == 'E'){
			conta++;
			} else if (senhaADM[i] == 1){
			conta++;
			
		} else if (senhaADM[i] == 2){
			conta++;
			} else if (senhaADM[i] == 3){
			conta++;
			
		} else if (senhaADM[i] == '@'){
			conta++;
			
	} else if (senhaADM[i] == ' '){
	conta++;
	
}

}

	
	if ((conta > 11) && (login == "Marcelo123")){
		
	
		
	} else {

system("cls");
cout << "Usuário ou senha incorretos, tente novamente.\n\n";

//tela inicial de login do adm 
    

	cout<<"Versão do sistema 1.0\n\n";
cout << "\n\n\n\n\n\n\n";	

HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
   

    SetConsoleTextAttribute(h,3);
	
cout <<setw(115)<<"    ###     ######  ######## ########  ######  ##     ##\n";
cout <<setw(115)<<"   ## ##   ##    ##    ##    ##       ##    ## ##     ##\n";
cout <<setw(115)<<"  ##   ##  ##          ##    ##       ##       ##     ##\n";
cout <<setw(115)<<" ##     ##  ######     ##    ######   ##       #########\n";
cout <<setw(115)<<" #########       ##    ##    ##       ##       ##     ##\n";
cout <<setw(115)<<" ##     ## ##    ##    ##    ##       ##    ## ##     ##\n";
cout <<setw(115)<<" ##     ##  ######     ##    ########  ######  ##     ##\n";
	
SetConsoleTextAttribute(h,7);
	
	 time_t timer;
  struct tm *horarioLocal;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  int dia = horarioLocal->tm_mday;
  int mes = horarioLocal->tm_mon + 1;
  int ano = horarioLocal->tm_year + 1900;

  int hora = horarioLocal->tm_hour;
  int min  = horarioLocal->tm_min;
  int sec  = horarioLocal->tm_sec;
  
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t      Data: "    << dia  << "/" << mes << "/" << ano << endl;
    cout << "\t\t\t\t\t\t\t\t\t      Horário: " << hora << ":" << min << endl;
    cout << "\n\n\n\n\n\n\n\n";
	cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t Login de administrador: ";
	getline(cin, login);
	cout<<"\n\n\t\t\t\t\t\t\t\tDigite a senha do administrador: ";
	
	//mascarar a senha
	
	fflush(stdin);
	for (int x = 0; x < 39; x++){
		senhaADM[x] = getch();
		putchar ('*');
			if (GetKeyState (VK_RETURN) < 0){
				x = 39;
			}

}

	
	
	for(int i = 0; i < 39; i++){
		
		if (senhaADM[i] == 'G'){
			
			conta++;
			
		} else if (senhaADM[i] == 'H'){
			conta++;
			
		} else if (senhaADM[i] == 'A'){
			conta++;
			} else if (senhaADM[i] == 'R'){
			conta++;
			
		} else if (senhaADM[i] == 'D'){
			conta++;
			} else if (senhaADM[i] == 'W'){
			conta++;
			
		} else if (senhaADM[i] == 'A'){
			conta++;
			} else if (senhaADM[i] == 'R'){
			conta++;
			
		} else if (senhaADM[i] == 'E'){
			conta++;
			} else if (senhaADM[i] == 1){
			conta++;
			
		} else if (senhaADM[i] == 2){
			conta++;
			} else if (senhaADM[i] == 3){
			conta++;
			
		} else if (senhaADM[i] == '@'){
			conta++;
			
	} else if (senhaADM[i] == ' '){
	conta++;
	
}

}

	
	if ((conta > 11) && (login == "Marcelo123")){
		
	
		
	} else {

system("cls");
cout << "Usuário ou senha incorretos, tente novamente.\n\n";
//tela inicial de login do adm 
    

	cout<<"Versão do sistema 1.0\n\n";
cout << "\n\n\n\n\n\n\n";	

HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
   

    SetConsoleTextAttribute(h,3);
	
cout <<setw(115)<<"    ###     ######  ######## ########  ######  ##     ##\n";
cout <<setw(115)<<"   ## ##   ##    ##    ##    ##       ##    ## ##     ##\n";
cout <<setw(115)<<"  ##   ##  ##          ##    ##       ##       ##     ##\n";
cout <<setw(115)<<" ##     ##  ######     ##    ######   ##       #########\n";
cout <<setw(115)<<" #########       ##    ##    ##       ##       ##     ##\n";
cout <<setw(115)<<" ##     ## ##    ##    ##    ##       ##    ## ##     ##\n";
cout <<setw(115)<<" ##     ##  ######     ##    ########  ######  ##     ##\n";
	
SetConsoleTextAttribute(h,7);
	
	 time_t timer;
  struct tm *horarioLocal;

  time(&timer); // Obtem informações de data e hora
  horarioLocal = localtime(&timer); // Converte a hora atual para a hora local

  int dia = horarioLocal->tm_mday;
  int mes = horarioLocal->tm_mon + 1;
  int ano = horarioLocal->tm_year + 1900;

  int hora = horarioLocal->tm_hour;
  int min  = horarioLocal->tm_min;
  int sec  = horarioLocal->tm_sec;
  
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t      Data: "    << dia  << "/" << mes << "/" << ano << endl;
    cout << "\t\t\t\t\t\t\t\t\t      Horário: " << hora << ":" << min << endl;
    cout << "\n\n\n\n\n\n\n\n";
	cout <<"\n\n\n\n\n\t\t\t\t\t\t\t\t Login de administrador: ";
	getline(cin, login);
	cout<<"\n\n\t\t\t\t\t\t\t\tDigite a senha do administrador: ";
	
	//mascarar a senha
	
	fflush(stdin);
	for (int x = 0; x < 39; x++){
		senhaADM[x] = getch();
		putchar ('*');
			if (GetKeyState (VK_RETURN) < 0){
				x = 39;
			}

}

	
	
	for(int i = 0; i < 39; i++){
		
		if (senhaADM[i] == 'G'){
			
			conta++;
			
		} else if (senhaADM[i] == 'H'){
			conta++;
			
		} else if (senhaADM[i] == 'A'){
			conta++;
			} else if (senhaADM[i] == 'R'){
			conta++;
			
		} else if (senhaADM[i] == 'D'){
			conta++;
			} else if (senhaADM[i] == 'W'){
			conta++;
			
		} else if (senhaADM[i] == 'A'){
			conta++;
			} else if (senhaADM[i] == 'R'){
			conta++;
			
		} else if (senhaADM[i] == 'E'){
			conta++;
			} else if (senhaADM[i] == 1){
			conta++;
			
		} else if (senhaADM[i] == 2){
			conta++;
			} else if (senhaADM[i] == 3){
			conta++;
			
		} else if (senhaADM[i] == '@'){
			conta++;
			
	} else if (senhaADM[i] == ' '){
	conta++;
	
}

}

	
	if ((conta > 11) && (login == "Marcelo123")){
		
	
		
	} else {

system("cls");
cout << "Usuário ou senha incorretos, tente novamente.\n\n";
loginsistema();	
	
}
	
}
}
}



//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~


//===================================================================================================================================================
//===================================================================================================================================================



int main(int argc, char** argv) { // Int main

	
	setlocale(LC_ALL, "Portuguese");
	
int sair;
int j = -1;
	
	loginsistema();
	

	

		//TELA DE BEM VINDO
	
		system ("cls");
		
		bemvindo();
		
		
		
		
		//MENU PRINCIPAL
		
		
		system ("cls");
		
		
		while (j != 0){
			
			
		system("cls");
		
		//Aqui é o menu de opçoes PRINCIPAL
		cout<<"Versão do sistema 1.0\n\n";
		HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
   

    SetConsoleTextAttribute(h,3);
		cout <<"\t\t\t\t\t\t\t\t\t GGHARDWARE MENU PRINCIPAL \n\n";
		 SetConsoleTextAttribute(h,7);
		cout<<"\nDigite o número correspondente a opção desejada: \n\n";
		cout<<"\n[01] Produtos.\n[02] Clientes.\n[03] Fornecedores.\n[04] Parceiros.\n[05] Ajuda.\n[06] Sobre.\n[07] Finalizar o programa.\n ";
		cin>>setw(115)>>sair;
		cin.sync();
				
		switch (sair) {
			
			
			
			case 1:
				
				MENUprodutos(); //VOID para a tabela de produtos
				
			break;
			
			case 2:
				
				MENUclientes (); //VOID para a tabela de clientes
				
			break;
			
			case 3:
			
				MENUfornecedores(); //VOID para a tabela de fornecedores
				
			break;
				
			case 4:
				
				MENUparceiros (); //VOID para a tabela de parceiros
				
			break;
			
			case 5:
				
				//Suporte para todo o sistema
				
				MENUsuporte ();
				
				
			break;
			
			case 6:
				
				//colocar o sobre aqui
				system("cls");
				cout<<"Versão do sistema 1.0\n\n";
				SetConsoleTextAttribute(h,6);
				cout <<"\t\t\t\t\t\t\t\t\t\t Sobre \n\n";
				SetConsoleTextAttribute(h,7);
				cout<<"\nO sistema tem a finalidade de sanar os problemas de armazenamento e de gerenciamento de estoque.\nContendo uma interface nítida e com fácil localização da pagina em que se encontra.\n";
				cout<<"\nDesenvolvido\tRafael de Carvalho, Hicaro Gabriel, Marvin Aragão, Fernanda Yasmin\n\n";
				cout<<"Versão\t1.0\n\n";
				system("pause");
			break;
			
			case 7:
				
				cout<<"\n\nPrograma encerrado!!!\n"; // encerramento do programa
				
				exit(0);
				
			break;
			
			default:
			
			
			break;
			
			}
		}
	

	return 0;
}
