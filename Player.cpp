#include "stdafx.h"
#include "Player.h"



std::string Player::getNome()
{
	return this->nome[this->currentCount];
}

int Player::getPontuacao()
{
	return this->pontuacao[this->currentCount];
}

void Player::setNome(string nome)
{
	this->nome[this->count] = nome;
}

void Player::addPontuacao(int pontuacao)
{
	this->pontuacao[this->currentCount] += pontuacao;
}

void Player::cadastra(string nome, int pontuacao)
{
	if (nome != "") {
		this->setNome(nome);
		this->pontuacao[this->count] = pontuacao;

		if (this->count == 11) {
			this->count = 11;
			this->currentCount = this->count - 1;
		}
		else {
			this->count++;
			this->currentCount = this->count - 1;
		}
	}
}


void Player::Records()
{
	int i, j;
	cout << "...................RECORDS...................." << endl;
	cout << "Posicao\t\tNickname\tPontuacao" << endl;
	for (i = this->currentCount, j = 1; i >= 0; i--, j++) {
		cout << "   " << j << "\t\t" << this->nome[i] << "\t\t " << this->pontuacao[i] << endl;
	}
}

void Player::addRecords()
{
	int i;
	for (i = 0; i < 10; i++) {
		if (this->getPontuacao() > this->pontuacao[i]) {
			this->pontuacao[9] = this->getPontuacao();
			this->nome[9] = this->getNome();
		}
	}
}

void Player::lerArquivos()
{
	teste2.open("teste.txt");
	if (teste2.is_open()) {
		int i;
		for (i = 0; !teste2.eof(); i++) {
			teste2 >> this->nome[i];
			teste2 >> this->pontuacao[i];
			this->count++;
		}
	}
	teste2.close();
}


void Player::Register()
{
	teste.open("teste.txt");
	if (teste.is_open()) {
		int i;
		for (i = 0; i < this->count; i++) {
			teste << this->nome[i] << endl << this->pontuacao[i] << endl << endl;
		}
	}
	teste.close();
}


void Player::Ordena()
{
	int i, j, y;
	string aux;

	for (i = 0; i < this->count; i++) {
		for (j = 0; j < this->count; j++) {
			if (this->pontuacao[i] < this->pontuacao[j]) {

				y = this->pontuacao[i];
				this->pontuacao[i] = this->pontuacao[j];
				this->pontuacao[j] = y;

				aux = this->nome[i];
				this->nome[i] = this->nome[j];
				this->nome[j] = aux;

			}
		}
	}
}

std::string Player::converte()
{
	std::ostringstream x;
	x << this->getPontuacao();
	return x.str();
}


Player::Player()
{
	int i;
	count = 0;
	currentCount = 0;

}


Player::~Player()
{
}
