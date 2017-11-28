#pragma once
class Player
{
private:

	int count, currentCount;
	std::string nome[11];
	int pontuacao[11];
	std::ofstream teste;  // ADD a Arquivos
	std::ifstream teste2; // Ler o Arquivo

public:
	std::string getNome();
	int getPontuacao();
	void setNome(std::string nome);
	void addPontuacao(int pontuacao);
	std::string converte();

	void cadastra(std::string nome, int pontuacao);

	void Records();
	void addRecords();
	void lerArquivos();
	void Register();
	void Ordena();

	Player();
	~Player();
};

