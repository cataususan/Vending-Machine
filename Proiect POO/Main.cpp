#include "CommandPanel.h"
#include <iostream>

int main()
{
	CommandPanel commandPanel;
	int op, prajitura, nrpraj;

	do
	{
		cout << "0.Iesire" << endl;
		cout << "1.Meniul cu prajituri" << endl;
		cout << "2.Prajiturile Din Carusel" << endl;
		cout << "3.Alegeti produsul si numarul de produse" << endl;
		cout << "Optiunea aleasa este: "; cin >> op;
		cout << endl;

		switch (op)
		{
		case 0:
			exit(0);
			break;
		case 1:
			commandPanel.showProducts();
			cout << endl;
			break;
		case 2:
			commandPanel.showProductsInCarousel();
			cout << endl;
			break;
		case 3:
			commandPanel.showProducts();
			cout << "Alegeti produsul:";
			cin >> prajitura;
			cout << "Intoduceti numarul de produse:";
			cin >> nrpraj;
			cout << endl;

			switch (prajitura)
			{
			case 1:
				commandPanel.selectProduct("Papanasi", nrpraj);
				break;
			case 2:
				commandPanel.selectProduct("Cu mere", nrpraj);
				break;
			case 3:
				commandPanel.selectProduct("Dobos", nrpraj);
				break;
			default:
				cout << "Nu ati introdus o optiune valida" << endl << endl;
				break;
			}
			break;
		default:
			cout << "Nu ati introdus o optiune valida!" << endl << endl;
			break;
		}
	} while (1);
	return 0;
}