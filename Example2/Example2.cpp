/*******************************************
**  @author Hasan Semih Aktaş
*******************************************/
#include <iostream>
#include <ctime>	    //her çalıştırmada başka bir random değeri ataması için
#include <iomanip>		//setw komutu için
#include <Windows.h>	//coord komutu için
using namespace std;
int sahneOlustur();
void sahneCiz();
int LSekliOlustur();
void LSekliCiz();
void LSekliAsagıGotur();
void koordinatAta(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
struct SahneYapısı
{
	int genislik;
	int yukseklik;
	char karakter;
}sahne;
struct LSekliYapısı
{
	int x;
	int y;
	int boyut;
	char karakter;
}LSekli;
int main()
{
	sahneOlustur();
	sahneCiz();
	do{
		LSekliOlustur();
		do {
			Sleep(100);
			system("CLS");
			LSekliAsagıGotur();
			sahneCiz();
			LSekliCiz();
		} while (2 * LSekli.boyut + LSekli.y != sahne.yukseklik - 2);//sahnenin içindeki boşluğun son kısmına gelesiye kadar aşağı indirmke için bu do while
	} while (2 * LSekli.boyut + LSekli.y == sahne.yukseklik - 2);	//sahnenin içindeki boşluğun son kısmına gelince sonraki adımda baştan bir şekil oluşturup baştan aşağı indirmek için
	system("pause");
}
int sahneOlustur()
{
	srand(time(0));
	sahne.genislik = (rand() % 3+3)*10;	//sahnenin genisliğini 30 40 50 den birisini rastgele atamak için bir işlem
	sahne.yukseklik = (rand() % 11)+20;	//sahnenin yüksekliğini 20-30 arası olması için gereken islem
	int karakterBelirleme = rand() % 5;
	switch (karakterBelirleme)
	{
	case 0:
	{
		sahne.karakter = '*';
		break;
	}
	case 1:
	{
		sahne.karakter = '#';
		break;
	}
	case 2:
	{
		sahne.karakter = '$';
		break;
	}
	case 3:
	{
		sahne.karakter = '+';
		break;
	}
	case 4:
	{
		sahne.karakter = '@';
		break;
	}
	}
	return sahne.genislik,sahne.yukseklik,sahne.karakter;
}
void sahneCiz()
{
	for (int sayac = 1; sayac <= sahne.genislik; sayac++)
	{
		cout << sahne.karakter;
	}
	cout << endl;
	for (int sayac = 2; sayac < sahne.yukseklik; sayac++)
	{
		cout << sahne.karakter << setw(sahne.genislik - 1) <<sahne.karakter << endl;
	}
	for (int sayac = 1; sayac <= sahne.genislik; sayac++)
	{
		cout << sahne.karakter;
	}
	cout << endl;
}
int LSekliOlustur()
{
	do {
		LSekli.x = (rand() % 21) + 5;	//sahnenin x değişkenini 5-25 arası rastgele bir deger atamak için islem
		LSekli.y = 2;
		LSekli.boyut = (rand() % 6) + 2;	//şeklin boyutunu 2-7 arası rastgele bir deger atamak için islem
	} while (LSekli.x + (2 * LSekli.boyut) > sahne.genislik || LSekli.x + (2 * LSekli.boyut) == sahne.genislik );	//sekil sahnenin dışına çıkmaması için yaptığım şart
	int karakterBelirleme = rand() % 5;
	switch (karakterBelirleme)
	{
	case 0:
	{
		LSekli.karakter = '*';
		break;
	}
	case 1:
	{
		LSekli.karakter = '#';
		break;
	}
	case 2:
	{
		LSekli.karakter = '$';
		break;
	}
	case 3:
	{
		LSekli.karakter = '+';
		break;
	}
	case 4:
	{
		LSekli.karakter = '@';
		break;
	}
	}
	return LSekli.x, LSekli.y, LSekli.boyut, LSekli.karakter;
}
void LSekliCiz()
{
	int x = 0;
	int y = 0;
	int y2 = 0;
	int x2 = 0;
	for (int sayac = 1; sayac <= 2 * LSekli.boyut + 1; sayac++)
	{
		if (sayac == 1)
		{
			for (int sayac2 = 1; sayac2 <= LSekli.boyut; sayac2++)
			{
				koordinatAta(LSekli.x+x, LSekli.y);
				cout << LSekli.karakter;
				x++;
			}
		}
		if (1 < sayac && sayac <= LSekli.boyut)
		{
			koordinatAta(LSekli.x, LSekli.y+y+1);
			cout << LSekli.karakter << setw(LSekli.boyut - 1) << LSekli.karakter;
			y++;
		}
		if (sayac == LSekli.boyut + 1)
		{
			koordinatAta(LSekli.x, LSekli.y+ LSekli.boyut);
			cout << LSekli.karakter << setw(LSekli.boyut - 1) << LSekli.karakter;
			for (int sayac2 = 1; sayac2 <= LSekli.boyut; sayac2++)
			{
				cout << LSekli.karakter;
			}
		}
		if (LSekli.boyut + 1 < sayac && sayac < 2 * LSekli.boyut + 1)
		{
			koordinatAta(LSekli.x,LSekli.y+LSekli.boyut + y2 + 1);
			cout << LSekli.karakter << setw(2 * LSekli.boyut - 1) << LSekli.karakter;
			y2++;
		}
		if (sayac == 2 * LSekli.boyut + 1)
		{
			for (int sayac2 = 1; sayac2 <= 2 * LSekli.boyut; sayac2++)
			{
				koordinatAta(LSekli.x+x2, 2*LSekli.boyut + LSekli.y );
				cout << LSekli.karakter;
				x2++;
			}
		}
	}
}
void LSekliAsagıGotur()
{	
	LSekli.y++;
}



