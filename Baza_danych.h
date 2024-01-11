#pragma once
#include <iostream>
#include <fstream>
#include "zgloszenie.h"
#include "faktura.h"

using namespace std;

class Baza_danych
{
	string nazwa_pliku_ze_zgloszeniami;
	string nazwa_pliku_z_cenami;
	string nazwa_pliku_z_fakturami;

public:
	Baza_danych(string npzz, string npzc, string npzf)
	{
		nazwa_pliku_ze_zgloszeniami = npzz;
		nazwa_pliku_z_cenami = npzc;
		nazwa_pliku_z_fakturami = npzf;
	}

	void DodajDoBazy(struct zgloszenie zgloszonko)
	{
		ofstream pliczek(nazwa_pliku_ze_zgloszeniami, ios::app);
		pliczek << zgloszonko.imie << endl;
		pliczek << zgloszonko.nazwisko << endl;
		pliczek << zgloszonko.rejestracja << endl << endl;
		cout << "dodano klienta do bazy" << endl;
		pliczek.close();
	}

	bool KlientWBazie(struct zgloszenie zgloszonko)
	{
		zgloszenie sprawdzacz_zgloszen;
		string pom;
		ifstream pliczek(nazwa_pliku_ze_zgloszeniami);
		while (getline(pliczek, sprawdzacz_zgloszen.imie))
		{
			getline(pliczek, sprawdzacz_zgloszen.nazwisko);
			getline(pliczek, sprawdzacz_zgloszen.rejestracja);
			getline(pliczek, pom);

			if (sprawdzacz_zgloszen.imie == zgloszonko.imie && sprawdzacz_zgloszen.nazwisko == zgloszonko.nazwisko && sprawdzacz_zgloszen.rejestracja == zgloszonko.rejestracja)
			{
				return true;
			}
		}
		pliczek.close();
		return false;
	}

	void DodajFakturke(struct faktura fakturka)
	{
		ofstream pliczek(nazwa_pliku_z_fakturami, ios::app);
		pliczek << fakturka.nr_faktury << endl;
		pliczek << fakturka.imie << endl;
		pliczek << fakturka.nazwisko << endl;
		pliczek << fakturka.rejestracja << endl;
		pliczek << fakturka.co_bylo_robione << endl;
		pliczek << fakturka.cena << endl << endl;
	}

	void ListaZgloszen()
	{
		ifstream pliczek(nazwa_pliku_ze_zgloszeniami);
		string linia;

		cout << "Lista zgloszen:" << endl;

		while (getline(pliczek, linia))
		{
			cout << linia << " ";
			getline(pliczek, linia);
			cout << linia << " ";
			getline(pliczek, linia);
			cout << linia << endl;
			getline(pliczek, linia);
		}
	}

	void ListaCen()
	{
		ifstream pliczek(nazwa_pliku_z_cenami);
		string linia;

		cout << "Lista cen:" << endl;

		while (getline(pliczek, linia))
		{
			cout << linia << ": ";
			getline(pliczek, linia);
			cout << linia << endl;
		}
	}

	void ListaFaktur()
	{
		ifstream pliczek(nazwa_pliku_z_fakturami);
		string linia;

		cout << "Lista faktur:" << endl;

		while (getline(pliczek, linia))
		{
			cout << "Nr faktury:" << linia << endl;
			getline(pliczek, linia);
			cout << linia << " ";
			getline(pliczek, linia);
			cout << linia << " ";
			getline(pliczek, linia);
			cout << linia << endl;
			getline(pliczek, linia);
			cout << "Co bylo robione: " << linia << endl;
			getline(pliczek, linia);
			cout << "Cena:" << linia << endl << endl;
			getline(pliczek, linia);
		}
	}

	string GetNPZZ()
	{
		return nazwa_pliku_ze_zgloszeniami;
	}

	string GetNPZC()
	{
		return nazwa_pliku_z_cenami;
	}
};
