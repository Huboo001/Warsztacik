#include "Interface.h"
#include <ctime>

using namespace std;

int main()
{
	srand(time(NULL));
	Interface interfejs("zgloszenia.txt", "ceny.txt", "faktury.txt");

	cout << "Witamy w aplikacji warszatowej,\nwybierz:\n1 aby utworzyc zgloszenie\n2 aby drukowac fakture\n3 aby wyswietlic liste zgloszen\n";
	cout << "4 aby wyswietlic liste z cenami\n5aby wyswietlic liste faktur\n6 aby wyjsc\n";
	int wybor;
	cin >> wybor;

	while (true)
	{
		system("cls");
		switch (wybor)
		{
			case(1):
				interfejs.UtworzZgloszenie();
				break;
			case(2):
				interfejs.DawajFakture();
				break;
			case(3):
				interfejs.WyswietlZgloszenia();
				break;
			case(4):
				interfejs.WyswietlCeny();
				break;
			case(5):
				interfejs.WyswietlFaktury();
				break;
		}

		if (wybor == 6)
		{
			break;
		}

		while (getchar() != '\n');

		cout << endl << endl << "Witamy w aplikacji warszatowej,\nwybierz\n1 aby utworzyc zgloszenie\n2 aby drukowac fakture\n3 aby wyswietlic liste zgloszen\n";
		cout << "4 aby wyswietlic liste z cenami\n5aby wyswietlic liste faktur\n6 aby wyjsc\n";
		cin >> wybor;

	}
	return 0;
}