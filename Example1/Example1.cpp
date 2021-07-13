/**************************************/
//		@author Hasan Semih Aktas
/**************************************/
#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
int SutunSayisi;
int SatirSayisi;
int SatirSayac,YildizSayac;
int main()
{
	do
	{
		cout << "5 ile 15 Arasinda (5 ve 15 Dahil) Satir Sayisi Giriniz:";
		cin >> SatirSayisi;
		while (SatirSayisi < 5 || 15 < SatirSayisi)    //Sayinýn 5 ile 15 arasinda (5 ile 15 dahil) olup olmadigini kontrol ediyor
		{
			cout << "Satir Sayisi Hatali Lutfen Baska Deger Giriniz:";
			cin >> SatirSayisi;
			Sleep(100);		//Sleep fonksiyonu programin calýsmasini 100 milisaniye durdurmak icin
		}
		cout << "5 ile 40 Arasinda (5 ile 40 Dahil) Sutun Sayisi Giriniz:";
		cin >> SutunSayisi;
		while (SutunSayisi < 5 || 40 < SutunSayisi)    //Sayinin 5 ile 40 arasinda (5 ile 40 dahil) olup olmadigini kontrol ediyor
		{
			cout << "Sutun Sayisi Hatali Lutfen Baska Deger Giriniz:";
			cin >> SutunSayisi;
			Sleep(100);
		}
		if (SutunSayisi != SatirSayisi * 2)    //Sutun sayisinin satir sayisinin 2 kati olup olmadigina bakiyor
		{
			cout << "Sutun Sayisi Satir Sayisi 2 Kati Olmalidir Tekrar Deneyiniz" << endl;
		}
	} while (SutunSayisi != SatirSayisi * 2);   //sutun sayisi satir sayisinin 2 kati degilse sart saglanasiya kadar bu dongu tekrarlaniyor
	for (SatirSayac = 1; SatirSayac <= SatirSayisi; SatirSayac++)
	{
		if (SatirSayac == 1 || SatirSayac == SatirSayisi)   //SatirSayaci 1 yada SatirSayisina esit oldugu zaman SutunSayisi kadar * koyuyor
		{
			for (YildizSayac= 0; YildizSayac < SutunSayisi; YildizSayac++) 
			{
				cout << "*";
				Sleep(100);
			}
		}
		else        //eger SatirSayaci 1 yada SatirSayisina esit degilse kurala gore * koyuyor
		{																																						//1. setw ilk * sonra islemin 1 eksigi kadar bosluk birakip sonraki yere * koyuyor
			cout << "*" << setw((SutunSayisi / 2) - SatirSayac) << "*" << setw((SatirSayac * 2) - 1) << "*" << setw((SutunSayisi / 2) - SatirSayac) << "*";		//2. setw 2. * itibaren islemin sonucunun 1 eksigi kadar bosluk birakip sonraki yere * koyuyor
			Sleep(100);																																			//3. set 3. * itibaren islemin sonucunun 1 eksigi kadar bosluk birakip sonraki yere * koyuyor
		}
		cout << endl;
	}
	cout << endl;
	for (SatirSayac = 1; SatirSayac <= SatirSayisi; SatirSayac++)
	{
		if(SatirSayac==1||SatirSayac==SatirSayisi)   //SatirSayaci 1 yada SatirSayisina esit oldugu zaman SutunSayisi kadar * koyuyor
		{
			for (YildizSayac= 0; YildizSayac < SutunSayisi; YildizSayac++) 
			{
				cout << "*";
				Sleep(100);
			}
		}
		else        //eger SatirSayaci 1 yada SatirSayisina esit degilse kurala gore * koyuyor
		{																																						//1. setw ilk * sonra islemin 1 eksigi kadar bosluk birakip sonraki yere * koyuyor
			cout << "*" << setw(SatirSayac - 1) << "*" << setw(SutunSayisi - (SatirSayac * 2) + 1) << "*" << setw(SatirSayac - 1) << "*";						//2. setw 2. * itibaren islemin sonucunun 1 eksigi kadar bosluk birakip sonraki yere * koyuyor
			Sleep(100);																																			//3. set 3. * itibaren islemin sonucunun 1 eksigi kadar bosluk birakip sonraki yere * koyuyor
		}
		cout << endl;
	}
	system("pause");
}