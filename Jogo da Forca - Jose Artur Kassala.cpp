/*
AUTORIA
Jogo da forca feito por Jose Artur Kassala
data: 14/08/2019
tel: 932 693 623
pais: ANGOLA
Morada: Benguela->Lobito->Bela Vista->Rua Caconda


DOCUMENTACAO:

palavra[] -> array char onde vai a palavra digitada
acertou[] -> array char onde vai mostrar as letras certas
letra -> variavel onde vai a letra digitada
quant -> variavel que recebe a quantidade de letras da palavra digitada contida no array palavra[]
chances -> variavel que guarda as chances de jogada do jogador
acertos -> e a quantidade de letras acertatas e ela e paralelo a variavel quant
cont -> e um contador
resp -> e a variavel que guarda a resposta do jogador se deseja repetir o jogo depois de ter acabado
palavra1[50] ->array booleana para nao considerar a posicao do vector palavra[] ja seleccionada
estado -> variavel booleana que diz se a letra ja foi encontrada ou nao
cstring -> biblioteca c++ para manipular string e com ele que eu descubro a quantidade de string com -> strlen()
system("TITLE ") funcao do DOS que altera o titulo do programa

*/
#include <iostream>
#include <cstring>

using namespace std;

void cabecario(){
	cout<<"\n-------------------------\nJOGO DA FORCA\nFEITO POR: JOSE ARTUR KASSALA\n-------------------------\n\n\n";
}

int main(){
	system("TITLE Jogo da Forca JAK ");
	
	//declarando as variaveis
	char palavra[50], acertou[50], letra;
	int quant, chances, acertos, cont, resp;
	bool palavra1[50], estado;
	
	//preenchendo variaveis
	inicio:
	chances=3;
	acertos=0;

	cabecario();
	
	//pedindo a palavra secreta
	cout<<"DIGITE A PALAVRA SECRETA\n";
	cin>>palavra;
	//descobrindo a quantidade de caracter digitados
	quant=strlen(palavra);
	
	//preencher acertou e palavra1
	for(int i=0; i<=quant; i++){
		acertou[i]='-';
		palavra1[i]=false;
	}
	
	//comecando o jogo
	while(chances>0 && acertos<quant){
		estado=false;
		system("cls");
		cabecario();
		cout<<"chances: "<<chances<<"\nPalavra Secreta: ";
		
		for(int x=0; x<quant; x++){
		cout<<acertou[x];
	}
	
	cout<<"\nDIGITE UMA DAS LETRA DA PALAVRA SECRETA\n";
	cin>>letra;
		cont=0;
		while(cont<=quant){
			
			if(palavra[cont]==letra && palavra1[cont]!=true){
				acertos++;
				acertou[cont]=letra;
				palavra1[cont]=true;
				estado=true;
				cont=quant+1;
			}
		cont++;
	}
	
	if(!estado){
		chances--;
	} 
		
		
	}
	
	//FIM DO JOGO
	cout<<"A PALAVRA SECRETA ERA: "<<palavra<<endl;
	(acertos==quant) ? cout<<"\n Parabens! Voce Acertou\n" : cout<<"Lamentamos mas voce Errou!\n";
	cout<<"\n-------------------------\nDESEJAS REPETIR O JOGO?\nSIM ->[1]\nNAO ->[0]\n-------------------------\n";
	cin>>resp;
	if(resp==1){
		system("cls");
		goto inicio;
	} else{
		system("cls");
	cout<<"\n-------------------------\nACABASTE DE JOGAR O JOGO DA FORCA\nFEITO POR: JOSE ARTUR KASSALA\n-------------------------\n";
	}
	
	system("pause");
	return 0;
}
