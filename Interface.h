#pragma once
#include "Baza_danych.h"

class Interface
{
	Baza_danych bd;

public:
	Interface(string npzz, string npzc, string npzf) : bd(npzz, npzc, npzf) {}

	void UtworzZgloszenie()
	{
		cout << "Podaj imie nazwisko oraz numer rejestracyjny w formacie imie nazwisko numer rejestracyjnyENTER: ";
		zgloszenie nowe_zgloszenie;
		cin >> nowe_zgloszenie.imie >> nowe_zgloszenie.nazwisko >> nowe_zgloszenie.rejestracja;

		if (bd.KlientWBazie(nowe_zgloszenie))
		{
			return;
		}

		bd.DodajDoBazy(nowe_zgloszenie);
	}

	void DawajFakture()
	{
		struct zgloszenie dane_klienta;
		cout << "Podaj dane klienta w formacie Imie Nazwisko RejestracjaENTER" << endl;
		cin >> dane_klienta.imie >> dane_klienta.nazwisko >> dane_klienta.rejestracja;

		if (!bd.KlientWBazie(dane_klienta))
		{
			cout << "Tego klienta nie ma w bazie, pierw utworz zgloszenie" << endl;
			return;
		}

		struct faktura fakturka;

		fakturka.imie = dane_klienta.imie;
		fakturka.nazwisko = dane_klienta.nazwisko;
		fakturka.rejestracja = dane_klienta.rejestracja;
		fakturka.nr_faktury = rand();
		cout << "Podaj co bylo robione" << endl;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin, fakturka.co_bylo_robione);
		cout << "Podaj finalna cene" << endl;
		cin >> fakturka.cena;

		system("cls");
		cout << "Wprowadzone dane:" << endl;
		cout << "Nr faktury: " << fakturka.nr_faktury << endl;
		cout << fakturka.imie << " " << fakturka.nazwisko << " " << fakturka.rejestracja << endl;
		cout << "Robota: " << fakturka.co_bylo_robione << endl;
		cout << "Finalna cena: " << fakturka.cena << endl;
		cout << "Drukowanie faktury..." << endl << endl;

		bd.DodajFakturke(fakturka);
	}

	void WyswietlZgloszenia()
	{
		bd.ListaZgloszen();
	}

	void WyswietlCeny()
	{
		bd.ListaCen();
	}

	void WyswietlFaktury()
	{
		bd.ListaFaktur();
	}
};