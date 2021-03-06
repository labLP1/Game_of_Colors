#include "stdafx.h"
#include "Opencv.h"
#include "Cards.h"
#include "Player.h"


int main()
{
	Player *jogador = new Player();
	Cards *card = new Opencv();

	char resp = 's';

	Mat frame, red, green, blue, black, white, yellow;
	int r, g, b, p, w, y;
	int tentativas = 3, x = 0;
	string nick;

	while (resp != 'n'){
		jogador->lerArquivos();
		jogador->Ordena();
		card->setColor();
		
		cout << "COR: " << card->getColor();

		std::cout << "Digite seu nickname: ";
		std::cin >> nick;

		VideoCapture capture(0);
		capture.open(true);

		if (!capture.isOpened())
			return -1;

		while (true) {
			
			
			capture.read(frame);
			putText(frame, nick , Point(50, 50), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 1, LINE_AA);
			putText(frame, jogador->converte() , Point(550, 50), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 1, LINE_AA);
			putText(frame, card->getColor(), Point(250, 450), FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255), 1, LINE_AA);

			// configurar aqui cores estaticas:
			inRange(frame, Scalar(10, 10, 100), Scalar(100, 100, 255), red);     // RED COLOR
			inRange(frame, Scalar(0, 0, 0), Scalar(50, 50, 50), black);          // BLACK COLOR
			inRange(frame, Scalar(10, 100, 10), Scalar(100, 255, 100), green);   // GREEN COLOR
			inRange(frame, Scalar(100, 10, 10), Scalar(255, 100, 100), blue);    // BLUE COLOR
			inRange(frame, Scalar(180, 180, 180), Scalar(255, 255, 255), white); // WHITE COLOR
			inRange(frame, Scalar(150, 150, 0), Scalar(255, 255, 0), yellow);

			r = countNonZero(red);
			g = countNonZero(green);
			b = countNonZero(blue);
			p = countNonZero(black);
			w = countNonZero(white);
			y = countNonZero(yellow);

			card->pegaCor(r, g, b, p, w, y);

			if (x == 50) {
				if (card->verifica()) {
					std::cout << "Correto!" << endl;
					card->setColor();
					jogador->addPontuacao(100);
				}
				else {
					std::cout << "Errado, tente novamente!" << endl;
					tentativas--;
					jogador->addPontuacao(-50);
				}
				x = 0;
			}
			// Até aqui.

			if (tentativas <= 0) {
				x = 0;
				break;
			}

			imshow("Tela de Jogo", frame);

			if (waitKey(30) == 27)
				break;

			x++;

		}

		jogador->Register();
		jogador->Ordena();
		jogador->Records();
		system("PAUSE");
		std::cout << "New Game (s\n): ";
		std::cin >> resp;
	}
	
	std::cout << "GOODBYE!" << endl;

	return 0;
}

