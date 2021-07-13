/*******************************************
**  @author Hasan Semih Aktaş
*******************************************/

#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string.h>

using namespace std;

void urunMenu();
void projeMenu();

/*
    Proje hakkında urun bilgileri fiyatları ve hakediş tarihini haekediş.txt ye kaydediyorum.
    Hakediş.txt ye kaydetme sırası : projeNo-hakedişTarihi-urunNo-alınanUrunAdet-alınan urunlerin ne kadar tuttuğu
    Projenin fiyat bilgileri dışında geri kalan bilgiler proje.txt de yazıyor.
    proje.txt nin yazma sırası : projeNo-projeAdi -projeYurutucuAdi-projeYurutucuSoyAdi-projeSorumlusuAdi-projeSorumlusuSoyAdi-projeKontrolörüAdi-projeKontrolörüSoyAdi
    Urunler hakkında bilgiler urun.txt de yazıyor.
    urun.txt de yazma sırası : urunNo-urunAdi-urunden kaç adet oldugu-urunun birim fiyatı-urunun markası  
*/

int main()
{
    string secim;

    //ürün.txt ve hakediş.txt de yer alacak alanlar
    string urunNo;
    string urunAdi;
    double urunBirim;
    double urunBirimFiyat;
    string urunMarkasi;

    //proje.txt de yer alacak alanlar
    string projeNo; //hakediş.txt de yer alacak 
    string projeAdi;
    string projeYurutucuAdi;
    string projeYurutucuSoyAdi;
    string projeSorumlusuAdi;
    string projeSorumlusuSoyAdi;
    string projeKontrolörüAdi;
    string projeKontrolörüSoyAdi;

    //hakediş.txt de yer alacak alanlar
    int projeHakedişTarihi;
    double secilenUrunAdet;
    double urunTutar;
    double urunlerinToplamTutarı;

    char devamSecim;
    do {
        do
        {
            cout << endl<< "Ne Yapmak Istiyorsunuz?" << endl << endl;
            cout << "1)Urun Islemleri" << endl << endl;
            cout << "2)Proje Islemleri" << endl << endl;
            cin >> secim;
            cout << endl;
        } while (secim != "1" && secim != "2");

    
        if (secim == "1")
        {
            string secim2;
            do
            {
                urunMenu();
                cin >> secim2;
                cout << endl;
                if (secim2 != "1" && secim2 != "2" && secim2 != "3" && secim2 != "4" && secim2 != "5")
                {
                    cout << "Lutfen 1-5 Arasi Bir Rakam Giriniz" << endl;
                }
            } while (secim2 != "1" && secim2 != "2" && secim2 != "3" && secim2 != "4" && secim2 != "5");

            if (secim2 == "1")
            {
                string yeniUrunNo;
                ofstream UrunEkle;
                UrunEkle.open("urun.txt", ios::app);
                cout << "Urun No Giriniz:  ";
                do {
                    cin >> yeniUrunNo;
                    ifstream UrunOku("urun.txt");
                    while (!UrunOku.eof())
                    {
                        UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                        if (yeniUrunNo == urunNo)
                        {
                            cout <<endl<< "Lutfen Baska Urun No Giriniz:  ";
                            UrunOku.close();
                            break;
                        }
                    }
                } while (yeniUrunNo == urunNo);
                urunNo = yeniUrunNo;
                cout << endl << endl << "Urun Adi Giriniz:  ";
                cin >> urunAdi;
                cout << endl << endl << "Urun Adeti:  ";
                cin >> urunBirim;
                cout << endl << endl << "Urun Birim Fiyati Giriniz:  ";
                cin >> urunBirimFiyat;
                cout << endl << endl << "Urun Markasi Giriniz:  ";
                cin >> urunMarkasi;
                UrunEkle << urunNo << ' ' << urunAdi << ' ' << urunBirim << ' ' << urunBirimFiyat << ' ' << urunMarkasi << "\n";
                UrunEkle.close();
                cout << "Urun Ekleme Basarili!";

                cout <<endl<< "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yazınız";
                    cin >> devamSecim;
                    cout << endl;
                }
            }

            if (secim2 == "2")
            {
                int toplamUrunSayısı = 0;

                string silinecekUrunNo;
                string kayitliUrunNo[100];
                string kayitliUrunAdi[100];
                double kayitliUrunBirim[100];
                double kayitliUrunBirimFiyat[100];
                string kayitliUrunMarkasi[100];
                int sayac1 = 0;
                int sayac2 = 0;

                string yeniUrunNoListe[100];
                string yeniUrunAdiListe[100];
                double yeniUrunBirimiListe[100];
                double yeniUrunBirimFiyatListe[100];
                string yeniUrunMarkasiListe[100];

                cout << "Silinecek Urun Noyu Yaziniz:  ";
                cin >> silinecekUrunNo;
                cout << endl;

                ifstream UrunOku("urun.txt");
                while (!UrunOku.eof())
                {
                    UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                    sayac1++;
                    kayitliUrunNo[sayac1] = urunNo;
                    kayitliUrunAdi[sayac1] = urunAdi;
                    kayitliUrunBirim[sayac1] = urunBirim;
                    kayitliUrunBirimFiyat[sayac1] = urunBirimFiyat;
                    kayitliUrunMarkasi[sayac1] = urunMarkasi;
                }
                toplamUrunSayısı = sayac1 - 1;

                for (sayac1 = 1; sayac1 <= toplamUrunSayısı; sayac1++)
                {
                    if (silinecekUrunNo != kayitliUrunNo[sayac1])
                    {
                        sayac2++;
                        yeniUrunNoListe[sayac2] = kayitliUrunNo[sayac1];
                        yeniUrunAdiListe[sayac2] = kayitliUrunAdi[sayac1];
                        yeniUrunBirimiListe[sayac2] = kayitliUrunBirim[sayac1];
                        yeniUrunBirimFiyatListe[sayac2] = kayitliUrunBirimFiyat[sayac1];
                        yeniUrunMarkasiListe[sayac2] = kayitliUrunMarkasi[sayac1];
                    }
                }
                toplamUrunSayısı = sayac2;

                ofstream UrunleriEkle;
                UrunleriEkle.open("urun.txt", ios::out);
                for (sayac1 = 1; sayac1 <= toplamUrunSayısı; sayac1++)
                {
                    UrunleriEkle << yeniUrunNoListe[sayac1] << ' ' << yeniUrunAdiListe[sayac1] << ' ' << yeniUrunBirimiListe[sayac1] << ' ' << yeniUrunBirimFiyatListe[sayac1] << ' ' << yeniUrunMarkasiListe[sayac1] << "\n";
                }
                UrunleriEkle.close();
                cout << "Islem Bitmistir!" << endl << endl;

                cout <<endl<< "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yazınız";
                    cin >> devamSecim;
                    cout << endl;
                }
            }

            if (secim2 == "3")
            {
                string arananUrunNo;
                cout << "Bilgilerini istediginiz urunun nosu:  ";
                cin >> arananUrunNo;
                cout << endl;
                ifstream UrunOku("urun.txt");
                while (!UrunOku.eof())
                {
                    UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                    if (arananUrunNo == urunNo)
                    {
                        cout << "Urun No:  " << urunNo << endl << endl;
                        cout << "Urun Adi:  " << urunAdi << endl << endl;
                        cout << "Urun Adedi:  " << urunBirim << endl << endl;
                        cout << "Urun Birim Fiyati:  " << urunBirimFiyat << endl << endl;
                        cout << "Urun Markasi:  " << urunMarkasi << endl << endl;
                        break;
                    }
                }
                if (arananUrunNo != urunNo)
                {
                    cout << "Boyle Bir Urun Yok!  " << endl ;
                }
                cout <<endl<< "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yazınız";
                    cin >> devamSecim;
                    cout << endl;
                }
                UrunOku.close();
            }

            if (secim2 == "4")
            {
                int toplamKayitliUrunSayisi = 0;
                int sayac = 0;
                string kayitliUrunNo[100];
                string kayitliUrunAdi[100];
                double kayitliUrunBirim[100];
                double kayitliUrunBirimFiyat[100];
                string kayitliUrunMarkasi[100];
                cout << "Tum Urunlerimiz ve Hakkinda Bilgiler" << endl << endl;
                ifstream UrunOku("urun.txt");
                while (!UrunOku.eof())
                {
                    sayac++;
                    UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                    kayitliUrunNo[sayac] = urunNo;
                    kayitliUrunAdi[sayac] = urunAdi;
                    kayitliUrunBirim[sayac] = urunBirim;
                    kayitliUrunBirimFiyat[sayac] = urunBirimFiyat;
                    kayitliUrunMarkasi[sayac] = urunMarkasi;
                }
                toplamKayitliUrunSayisi = sayac - 1;
                for (sayac = 1; sayac <= toplamKayitliUrunSayisi; sayac++)
                {
                    cout << "Urun No: " << kayitliUrunNo[sayac] << "  " << "Urun Adi: " << kayitliUrunAdi[sayac] << "  " << "Urun Adedi: " << kayitliUrunBirim[sayac] << "  " << "Urun Adedi Birimi: " << kayitliUrunBirimFiyat[sayac] << "  " << "Urun Markasi: " << kayitliUrunMarkasi[sayac] << endl;
                }
                cout <<endl<< "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yazınız";
                    cin >> devamSecim;
                    cout << endl;
                }
            }

            if (secim2 == "5")
            {
                string secim3;
                do {
                    cout << "Urun Fiyati Degistirmek Icin 1 e, Urun Adedini Degistirmek Icin 2 e basiniz" << endl << endl;
                    cin >> secim3;
                    cout << endl;
                    if (secim3 != "1" && secim3 != "2")
                    {
                        cout << "Lutfen 1 veya 2 Giriniz" << endl;
                    }
                } while (secim3 != "1" && secim3 != "2");

                if (secim3 == "1")
                {
                    int sayac = 0;
                    int toplamKayitliUrunSayisi = 0;
                    string degistirilecekUrunNo;
                    double degistirilmisFiyat;
                    string kayitliUrunNo[100];
                    string kayitliUrunAdi[100];
                    double kayitliUrunBirim[100];
                    double kayitliUrunBirimFiyat[100];
                    string kayitliUrunMarkasi[100];
                    cout << "Fiyati Degistirilecek Urunun Nosu" << endl << endl;
                    cin >> degistirilecekUrunNo;
                    cout << endl;
                    ifstream UrunOku("urun.txt");
                    while (!UrunOku.eof())
                    {
                        sayac++;
                        UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                        kayitliUrunNo[sayac] = urunNo;
                        kayitliUrunAdi[sayac] = urunAdi;
                        kayitliUrunBirim[sayac] = urunBirim;
                        kayitliUrunBirimFiyat[sayac] = urunBirimFiyat;
                        kayitliUrunMarkasi[sayac] = urunMarkasi;
                    }
                    toplamKayitliUrunSayisi = sayac - 1;
                    for (sayac = 1; sayac <= toplamKayitliUrunSayisi; sayac++)
                    {
                        if (degistirilecekUrunNo == kayitliUrunNo[sayac])
                        {
                            cout << "Yapmak Istediginiz Fiyat Kactir?" << endl << endl;
                            cin >> degistirilmisFiyat;
                            kayitliUrunBirimFiyat[sayac] = degistirilmisFiyat;
                            break;
                        }
                    }
                    if (degistirilecekUrunNo != kayitliUrunNo[sayac])
                    {
                        cout << "Boyle Bir Urun Yok" << endl << endl;
                    }
                    ofstream UrunleriDuzenle;
                    UrunleriDuzenle.open("urun.txt", ios::out);
                    for (sayac = 1; sayac <= toplamKayitliUrunSayisi; sayac++)
                    {
                        UrunleriDuzenle << kayitliUrunNo[sayac] << ' ' << kayitliUrunAdi[sayac] << ' ' << kayitliUrunBirim[sayac] << ' ' << kayitliUrunBirimFiyat[sayac] << ' ' << kayitliUrunMarkasi[sayac] << "\n";
                    }
                    UrunleriDuzenle.close();
                    cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                    cin >> devamSecim;
                    if (devamSecim != 'e' && devamSecim != 'h')
                    {
                        cout << "Lutfen e veya h yazınız";
                        cin >> devamSecim;
                        cout << endl;
                    }
                }

                if (secim3 == "2")
                {
                    int sayac = 0;
                    int toplamKayitliUrunSayisi = 0;
                    string degistirilecekUrunNo;
                    double degistirilmisAdet;
                    string kayitliUrunNo[100];
                    string kayitliUrunAdi[100];
                    double kayitliUrunBirim[100];
                    double kayitliUrunBirimFiyat[100];
                    string kayitliUrunMarkasi[100];
                    cout << "Adeti Degistirilecek Urunun Nosu" << endl << endl;
                    cin >> degistirilecekUrunNo;
                    cout << endl;
                    ifstream UrunOku("urun.txt");
                    while (!UrunOku.eof())
                    {
                        sayac++;
                        UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                        kayitliUrunNo[sayac] = urunNo;
                        kayitliUrunAdi[sayac] = urunAdi;
                        kayitliUrunBirim[sayac] = urunBirim;
                        kayitliUrunBirimFiyat[sayac] = urunBirimFiyat;
                        kayitliUrunMarkasi[sayac] = urunMarkasi;
                    }
                    toplamKayitliUrunSayisi = sayac - 1;
                    for (sayac = 1; sayac <= toplamKayitliUrunSayisi; sayac++)
                    {
                        if (degistirilecekUrunNo == kayitliUrunNo[sayac])
                        {
                            cout << "Yapmak Istediginiz Adet Kactir?" << endl << endl;
                            cin >> degistirilmisAdet;
                            kayitliUrunBirim[sayac] = degistirilmisAdet;
                            break;
                        }
                    }
                    if (degistirilecekUrunNo != kayitliUrunNo[sayac])
                    {
                        cout << "Boyle Bir Urun Yok" << endl << endl;
                    }
                    ofstream UrunleriDuzenle;
                    UrunleriDuzenle.open("urun.txt", ios::out);
                    for (sayac = 1; sayac <= toplamKayitliUrunSayisi; sayac++)
                    {
                        UrunleriDuzenle << kayitliUrunNo[sayac] << ' ' << kayitliUrunAdi[sayac] << ' ' << kayitliUrunBirim[sayac] << ' ' << kayitliUrunBirimFiyat[sayac] << ' ' << kayitliUrunMarkasi[sayac] << "\n";
                    }
                    UrunleriDuzenle.close();
                    cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                    cin >> devamSecim;
                    if (devamSecim != 'e' && devamSecim != 'h')
                    {
                        cout << "Lutfen e veya h yaziniz";
                        cin >> devamSecim;
                        cout << endl;
                    }
                }
            }
        }

        if (secim == "2")
        {
            string secim2;
            char urunSecDevam;
            string secilenUrunNo;
            double secilenAdet;
            do
            {
                projeMenu();
                cin >> secim2;
            } while (secim2 != "1" && secim2 != "2" && secim2 != "3" && secim2 != "4" && secim2 !="5");

            if (secim2 == "1")
            {
                char urununVarOlupOlmadiginiKontrol='h';
                urunTutar = 0;
                int toplamUrunSayısı;
                string kayitliUrunNo[100];
                string kayitliUrunAdi[100];
                double kayitliUrunBirim[100];
                double kayitliUrunBirimFiyat[100];
                string kayitliUrunMarkasi[100];
                int sayac1 = 0;

                string yeniProjeNo;
                ofstream ProjeEkle;
                ProjeEkle.open("proje.txt", ios::app);
                cout<<  "Proje No Giriniz:  ";
                do {
                    cin >> yeniProjeNo;
                    ifstream ProjeOku("proje.txt");
                    while (!ProjeOku.eof())
                    {
                        ProjeOku >> projeNo >> projeAdi >> projeYurutucuAdi >> projeYurutucuSoyAdi >> projeSorumlusuAdi>>projeSorumlusuSoyAdi>>projeKontrolörüAdi>>projeKontrolörüSoyAdi;
                        if (yeniProjeNo == projeNo)
                        {
                            cout <<endl<< "Lutfen Baska Proje No Giriniz:  ";
                            ProjeOku.close();
                            break;
                        }
                    }
                } while (yeniProjeNo == projeNo);
                projeNo = yeniProjeNo;
                cout << endl << endl << "Proje Adi Giriniz:  ";
                cin >> projeAdi;
                cout << endl << endl << "Proje Yurutucu Adi:  ";
                cin >> projeYurutucuAdi;
                cout << endl << endl << "Proje Yurutucu Soyadi:  ";
                cin >> projeYurutucuSoyAdi;
                cout << endl << endl << "Proje Sorumlusu Adi:  ";
                cin >> projeSorumlusuAdi;
                cout << endl << endl << "Proje Sorumlusu Soyadi:  ";
                cin >> projeSorumlusuSoyAdi;
                cout << endl << endl << "Proje Kontroloru Adi:  ";
                cin >> projeKontrolörüAdi;
                cout << endl << endl << "Proje Kontroloru Soyadi:  ";
                cin >> projeKontrolörüSoyAdi;
                ProjeEkle << projeNo << ' ' << projeAdi << ' ' << projeYurutucuAdi << ' ' << projeYurutucuSoyAdi << ' ' << projeSorumlusuAdi << ' ' << projeSorumlusuSoyAdi<< ' ' << projeKontrolörüAdi <<' ' << projeSorumlusuSoyAdi <<"\n";
                ProjeEkle.close();

                ifstream UrunOku;
                UrunOku.open("urun.txt");
                while (!UrunOku.eof())
                {
                    sayac1++;
                    UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                    kayitliUrunNo[sayac1] = urunNo;
                    kayitliUrunAdi[sayac1] = urunAdi;
                    kayitliUrunBirim[sayac1] = urunBirim;
                    kayitliUrunBirimFiyat[sayac1] = urunBirimFiyat;
                    kayitliUrunMarkasi[sayac1] = urunMarkasi;
                }
                UrunOku.close();
                toplamUrunSayısı = sayac1 - 1;

                do
                {
                    ofstream HakedişEkle;
                    HakedişEkle.open("hakediş.txt", ios::app);

                    ifstream UrunOku;
                    cout << "Hangi Urunden Almak Istiyorsunuz? " << endl;
                    cin >> secilenUrunNo;
                    cout << endl;

                    UrunOku.open("urun.txt");
                    while (!UrunOku.eof())
                    {
                        UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;

                        if (secilenUrunNo == urunNo)
                        {
                            urununVarOlupOlmadiginiKontrol = 'e';
                            cout << "Kac Adet Almak Istersiniz?" << endl;
                            cin >> secilenAdet;
                            if (secilenAdet <= urunBirim)
                            {
                                urunTutar = urunBirimFiyat * secilenAdet;

                                HakedişEkle << projeNo << ' ' << 0 << ' ' << urunNo << ' ' << secilenAdet << ' ' << urunTutar << "\n"; //hakediş tarihi belli olmadıgı icin 0

                                for (sayac1 = 1; sayac1 <= toplamUrunSayısı; sayac1++)
                                {
                                    if (secilenUrunNo == kayitliUrunNo[sayac1])
                                    {
                                        double toplam = kayitliUrunBirim[sayac1];
                                        kayitliUrunBirim[sayac1] = toplam - secilenAdet;
                                    }
                                }
                                break;
                            }
                            else
                            {
                                cout << "Elimizde Bu Kadar Urun Yok!" << endl << endl;
                            }
                        }
                    }
                    if (urununVarOlupOlmadiginiKontrol!='e')
                    {
                        cout << "Boyle Bir Urun Yok!  " << endl;
                        break;
                    }

                    cout << "Urun Secmeye Devam Etmek Icin e, Cikmak Icin h ye basiniz!!" << endl;
                    cin >> urunSecDevam;
                    HakedişEkle.close();
                    if (urunSecDevam != 'e' && urunSecDevam != 'h')
                    {
                        cout << "Lutfen e veya h giriniz!" << endl;
                        cin >> urunSecDevam;
                    }

                } while (urunSecDevam == 'e');

                ofstream UrunleriDuzenle;
                UrunleriDuzenle.open("urun.txt", ios::out);
                for (sayac1 = 1; sayac1 <= toplamUrunSayısı; sayac1++)
                {
                    UrunleriDuzenle << kayitliUrunNo[sayac1] << ' ' << kayitliUrunAdi[sayac1] << ' ' << kayitliUrunBirim[sayac1] << ' ' << kayitliUrunBirimFiyat[sayac1]<< ' ' << kayitliUrunMarkasi[sayac1] << "\n";
                }
                UrunleriDuzenle.close();

                cout << "Proje Ekleme Basarili!";

                cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yazınız";
                    cin >> devamSecim;
                    cout << endl;
                }
            }
            
            if (secim2 == "2")
            {
                string silinecekProjeNo;
                int sayac1 = 0;
                int sayac2 = 0;


                string kayitliProjeNo[100];
                string kayitliProjeAdi[100];
                string kayitliProjeYurutucuAdi[100];
                string kayitliProjeYurutucuSoyAdi[100];
                string kayitliProjeSorumlusuAdi[100];
                string kayitliProjeSorumlusuSoyAdi[100];
                string kayitliProjeKontroloruAdi[100];
                string kayitliProjeKontroloruSoyAdi[100];

                string yeniProjeNoListe[100];
                string yeniProjeAdiListe[100];
                string yeniProjeYurutucuAdiListe[100];
                string yeniProjeYurutucuSoyAdiListe[100];
                string yeniProjeSorumlusuAdiListe[100];
                string yeniProjeSorumlusuSoyAdiListe[100];
                string yeniProjeKontroloruAdiListe[100];
                string yeniProjeKontroloruSoyAdiListe[100];

                string kayitliHakedişProjeNo[100];
                int kayitliHakedişTarihi[100];
                string kayitliHakedişUrunNo[100];
                double kayitliHakedişUrunAdedi[100];
                double kayitliHakedişUrunTutar[100];
               
                string yeniHakedişProjeNo[100];
                int yeniHakedişTarihi[100];
                string yeniHakedişUrunNo[100];
                double yeniHakediUrunAdedi[100];
                double yeniHakedişUrunTutar[100];
                
                int hakedişKayitliUrun = 0;
                int toplamProjeSayisi=0;
                int yeniKayitliProjeSayisi = 0;
                int yeniHakedişKayitliUrunSayisi = 0;
                char projeOlupOlmadigiKontrolu='h';
                char projeHakedisTarihiOlupOlmadigiKontrol='h';

                cout << "Silinecek Proje No: " << endl<<endl;
                cin >> silinecekProjeNo;

                ifstream ProjeOku;
                ProjeOku.open("proje.txt");
                while (!ProjeOku.eof())
                {
                    sayac1++;
                    ProjeOku >> projeNo >> projeAdi >> projeYurutucuAdi >> projeYurutucuSoyAdi >> projeSorumlusuAdi >> projeSorumlusuSoyAdi >> projeKontrolörüAdi >> projeKontrolörüSoyAdi;
                    kayitliProjeNo[sayac1] = projeNo;
                    kayitliProjeAdi[sayac1] = projeAdi;
                    kayitliProjeYurutucuAdi[sayac1] = projeYurutucuAdi;
                    kayitliProjeYurutucuSoyAdi[sayac1] = projeYurutucuSoyAdi;
                    kayitliProjeSorumlusuAdi[sayac1] = projeSorumlusuAdi;
                    kayitliProjeSorumlusuSoyAdi[sayac1] = projeSorumlusuSoyAdi;
                    kayitliProjeKontroloruAdi[sayac1] = projeKontrolörüAdi;
                    kayitliProjeKontroloruSoyAdi[sayac1] = projeKontrolörüSoyAdi;

                }
                toplamProjeSayisi = sayac1;
                sayac1 = 0;

                ifstream HakedişOku;
                HakedişOku.open("hakediş.txt");
                while (!HakedişOku.eof())
                {
                    sayac1++;
                    HakedişOku >> projeNo >> projeHakedişTarihi >> urunNo >> urunBirim >> urunTutar;
                    kayitliHakedişProjeNo[sayac1] = projeNo;
                    kayitliHakedişTarihi[sayac1] = projeHakedişTarihi;
                    kayitliHakedişUrunNo[sayac1] = urunNo;
                    kayitliHakedişUrunAdedi[sayac1] = urunBirim;
                    kayitliHakedişUrunTutar[sayac1] = urunTutar;
                }
                hakedişKayitliUrun = sayac1;

                for (sayac1 = 1; sayac1 <= toplamProjeSayisi; sayac1++)
                {
                    if (silinecekProjeNo == kayitliProjeNo[sayac1])
                    {
                        projeOlupOlmadigiKontrolu = 'e';

                    }
                }
                if (projeOlupOlmadigiKontrolu != 'e')
                {
                    cout << "Boyle Bir Proje Yok!" << endl << endl;
                }
                if (projeOlupOlmadigiKontrolu == 'e')
                {
                    for (sayac1 = 1; sayac1 <= hakedişKayitliUrun; sayac1++)
                    {
                        if (silinecekProjeNo == kayitliHakedişProjeNo[sayac1])
                        {   
                            if (kayitliHakedişTarihi[sayac1] != 0)
                            {
                                projeHakedisTarihiOlupOlmadigiKontrol = 'e';
                            }
                        }
                    }
                }
                if (projeHakedisTarihiOlupOlmadigiKontrol == 'e')
                {
                    cout << "Bu Projenin Hakedis Tarihi Verilmis Silinemez!" << endl << endl;
                }

                if (projeHakedisTarihiOlupOlmadigiKontrol !='e')
                {
                    for (sayac1 = 1; sayac1 <= toplamProjeSayisi; sayac1++)
                    {
                        if (silinecekProjeNo != kayitliProjeNo[sayac1])
                        {
                            sayac2++;
                            yeniProjeNoListe[sayac2] = kayitliProjeNo[sayac1];
                            yeniProjeAdiListe[sayac2] = kayitliProjeAdi[sayac1];
                            yeniProjeYurutucuAdiListe[sayac2] = kayitliProjeYurutucuAdi[sayac1];
                            yeniProjeYurutucuSoyAdiListe[sayac2] = kayitliProjeYurutucuSoyAdi[sayac1];
                            yeniProjeSorumlusuAdiListe[sayac2] = kayitliProjeSorumlusuAdi[sayac1];
                            yeniProjeSorumlusuSoyAdiListe[sayac2] = kayitliProjeSorumlusuSoyAdi[sayac1];
                            yeniProjeKontroloruAdiListe[sayac2] = kayitliProjeKontroloruAdi[sayac1];
                            yeniProjeKontroloruSoyAdiListe[sayac2] = kayitliProjeKontroloruSoyAdi[sayac1];
                        }
                    }
                    yeniKayitliProjeSayisi = sayac2;
                    sayac2 = 0;
                    for (sayac1 = 1; sayac1 <= hakedişKayitliUrun; sayac1++)
                    {
                        if (silinecekProjeNo != kayitliHakedişProjeNo[sayac1])
                        {
                            sayac2++;
                            yeniHakedişProjeNo[sayac2] = kayitliHakedişProjeNo[sayac1];
                            yeniHakedişTarihi[sayac2] = kayitliHakedişTarihi[sayac1];
                            yeniHakedişUrunNo[sayac2] = kayitliHakedişUrunNo[sayac1];
                            yeniHakediUrunAdedi[sayac2] = kayitliHakedişUrunAdedi[sayac1];
                            yeniHakedişUrunTutar[sayac2] = kayitliHakedişUrunTutar[sayac1];
                        }
                    }
                    yeniHakedişKayitliUrunSayisi = sayac2;

                    ofstream ProjeYaz;
                    ProjeYaz.open("proje.txt", ios::out);
                    {
                        for (sayac1 = 1; sayac1 <= yeniKayitliProjeSayisi; sayac1++)
                        {
                            ProjeYaz << yeniProjeNoListe[sayac1] << ' ' << yeniProjeAdiListe[sayac1] << ' ' << yeniProjeYurutucuAdiListe[sayac1] << ' ' << yeniProjeYurutucuSoyAdiListe[sayac1] << ' ' << yeniProjeSorumlusuAdiListe[sayac1] << ' ' << yeniProjeSorumlusuSoyAdiListe[sayac1] << ' ' << yeniProjeKontroloruAdiListe[sayac1] << ' ' << yeniProjeKontroloruSoyAdiListe[sayac1] << "\n";
                        }
                    }
                    ProjeYaz.close();

                    ofstream HakedişYaz;
                    HakedişYaz.open("hakediş.txt", ios::out);
                    {
                        for (sayac1 = 1; sayac1 <= yeniHakedişKayitliUrunSayisi; sayac1++)
                        {
                            HakedişYaz << yeniHakedişProjeNo[sayac1] << ' ' << yeniHakedişTarihi[sayac1] << ' ' << yeniHakedişUrunNo[sayac1] << ' ' << yeniHakediUrunAdedi[sayac1] << ' ' << yeniHakedişUrunTutar[sayac1] << "\n";
                        }
                    }

                    cout << "Islem Basarili Olarak Gerceklesmistir!" << endl << endl ;
                }
                cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yazınız";
                    cin >> devamSecim;
                    cout << endl;
                }
            }

            if (secim2 == "3")
            {
                string arananProjeNo;
                string hakedişProjeNo[100];
                int hakedişProjeHakedişTarihi[100];
                string hakedişUrunNo[100];
                double hakedişSecilenUrunAdet[100];
                double hakedişUrunTutar[100];
                int hakedişTarihi;
                int toplamUrunSayisi = 0;
                int sayac = 0;

                cout << "Bilgilerini istediginiz projenin nosu:  ";
                cin >> arananProjeNo;
                cout << endl;
                ifstream HakedişOku("hakediş.txt");
                urunlerinToplamTutarı = 0;
                while (!HakedişOku.eof())
                {
                    sayac++;
                    HakedişOku >> projeNo >> projeHakedişTarihi >> urunNo >> secilenUrunAdet >> urunTutar;
                    hakedişProjeNo[sayac] = projeNo;
                    hakedişProjeHakedişTarihi[sayac] = projeHakedişTarihi;
                    hakedişUrunNo[sayac] = urunNo;
                    hakedişSecilenUrunAdet[sayac] = secilenUrunAdet;
                    hakedişUrunTutar[sayac] = urunTutar;     
                }
                toplamUrunSayisi = sayac - 1;

                for (sayac = 1; sayac <= toplamUrunSayisi; sayac++)
                {
                    if (arananProjeNo == hakedişProjeNo[sayac])
                    {
                        urunlerinToplamTutarı += hakedişUrunTutar[sayac];
                    }
                }

                ifstream ProjeOku("proje.txt");
                while (!ProjeOku.eof())
                {
                    ProjeOku >> projeNo >> projeAdi >> projeYurutucuAdi >> projeYurutucuSoyAdi >> projeSorumlusuAdi >> projeSorumlusuSoyAdi >> projeKontrolörüAdi >> projeKontrolörüSoyAdi;
                    if (arananProjeNo == projeNo)
                    {
                        cout << "Proje No:  " << projeNo << endl << endl;
                        cout << "Proje Adi:  " << projeAdi << endl << endl;
                        cout << "Proje Yurutucu Adi:  " << projeYurutucuAdi << endl << endl;
                        cout << "Proje Yurutucu Soy Adi:  " << projeYurutucuSoyAdi << endl << endl;
                        cout << "Proje Sorumlusu Adi:  " << projeSorumlusuAdi << endl << endl;
                        cout << "Proje Sorumlusu Soy Adi:  " << projeSorumlusuSoyAdi << endl << endl;
                        cout << "Proje Kontroloru Adi:  " << projeKontrolörüAdi << endl << endl;
                        cout << "Proje Kontroloru Soy Adi:  " << projeKontrolörüSoyAdi << endl << endl;
                        for (sayac = 1; sayac <= toplamUrunSayisi; sayac++)
                        {
                            if (arananProjeNo == hakedişProjeNo[sayac])
                            {
                                hakedişTarihi = hakedişProjeHakedişTarihi[sayac];
                                cout << "Alinan Urun:  " << hakedişUrunNo[sayac] << "  " << "Alinan Adet:  " << hakedişSecilenUrunAdet[sayac] << "  " << "Urunun Tutari:  " << hakedişUrunTutar[sayac]<<endl<<endl;
                            }
                        }
                        cout << "Proje Hakediş Tarihi:  " << hakedişTarihi<<endl<<endl;

                        cout << "Proje Toplam Tutar:  " << urunlerinToplamTutarı << endl << endl;
                        break;
                    }
                }
                if (arananProjeNo != projeNo)
                {
                    cout << "Boyle Bir Proje Yok!  " << endl ;
                }
                cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yazınız";
                    cin >> devamSecim;
                    cout << endl;
                }
                ProjeOku.close();
            }

            if (secim2 == "4")
            {
                int toplamKayitliProjeSayisi = 0;
                int sayac = 0;
                int sayac2 = 0;

                string kayitliProjeNo[100];
                string kayitliProjeAdi[100];
                string hakedişProjeNo[100];
                double hakedişUrunTutar[100];
                double projeninTutarı[100];
                int hakedişProjeTarihi[100];
                int hakedişTarihi[100];

                int toplamUrunSayisi = 0;

                cout << "Tum Projeler ve Hakkinda Bilgiler" << endl << endl;
                ifstream ProjeOku;
                ProjeOku.open("proje.txt");
                while (!ProjeOku.eof())
                {
                    sayac++;
                    ProjeOku >> projeNo >> projeAdi >> projeYurutucuAdi >> projeYurutucuSoyAdi >> projeSorumlusuAdi >> projeSorumlusuSoyAdi >> projeKontrolörüAdi >> projeKontrolörüSoyAdi;
                    kayitliProjeNo[sayac] = projeNo;
                    kayitliProjeAdi[sayac] = projeAdi;
                }
                toplamKayitliProjeSayisi = sayac ;

                ifstream HakedişOku;
                HakedişOku.open("hakediş.txt");
                while (!HakedişOku.eof())
                {
                    sayac2++;
                    HakedişOku >> projeNo >> projeHakedişTarihi >> urunNo >> secilenUrunAdet >> urunTutar;
                    hakedişProjeNo[sayac2] = projeNo; 
                    hakedişUrunTutar[sayac2] = urunTutar;
                    hakedişProjeTarihi[sayac2] = projeHakedişTarihi;
                }
                toplamUrunSayisi = sayac2 ;

                for (sayac = 1; sayac <= toplamKayitliProjeSayisi; sayac++)
                {
                    projeninTutarı[sayac] = 0;

                    for (sayac2 = 1; sayac2 <= toplamUrunSayisi; sayac2++)
                    {
                        if (kayitliProjeNo[sayac] == hakedişProjeNo[sayac2])
                        {
                            projeninTutarı[sayac] += hakedişUrunTutar[sayac2];
                            hakedişTarihi[sayac] = hakedişProjeTarihi[sayac2];
                        }
                    }
                }
        
                for (sayac = 1; sayac <= toplamKayitliProjeSayisi; sayac++)
                {
                    cout << "Proje No: " << kayitliProjeNo[sayac] << "  " << "Proje Adi: " << kayitliProjeAdi[sayac] << "  " << "Urun Tutari: " << projeninTutarı[sayac] << "  " << "Hakedis Tarihi:  " << hakedişTarihi[sayac]<< endl;
                }

                cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                cin >> devamSecim;
                if (devamSecim != 'e' && devamSecim != 'h')
                {
                    cout << "Lutfen e veya h yaziniz";
                    cin >> devamSecim;
                    cout << endl;
                }
            }

            if (secim2 == "5")
            {
                string secim3;
                do {
                    cout << "Proje Urunleri Hakkinda Islemler Icin 1 e, Hakedis Tarihi Belirlemek Icin 2 e basiniz" << endl << endl;
                    cin >> secim3;
                    cout << endl;
                    if (secim3 != "1" && secim3 != "2")
                    {
                        cout << "Lutfen 1 veya 2 Giriniz" << endl;
                    }
                } while (secim3 != "1" && secim3 != "2");

                if (secim3 == "1")
                {
                    string secim4;
                    do {
                        cout << "Projeye Urun Eklemek Icin 1 e,  Projeden Urun Cikarmak Icin 2 e basiniz" << endl << endl;
                        cin >> secim4;
                        cout << endl;
                        if (secim4 != "1" && secim4 != "2")
                        {
                            cout << "Lutfen 1 veya 2 Giriniz" << endl;
                        }
                    } while (secim4 != "1" && secim4 != "2");

                    if (secim4 == "1")
                    {

                        string urunAdediBelirlenecekProjeNo;
                        int eklenecekProjeninHakedişTarihi=0;
                        string eklenecekUrunNo;
                        double eklenecekUrunAdet;

                        string kayitliHakedişProjeNo[100];
                        int kayitliHakedişTarihi[100];
                        string kayitliHakedişUrunNo[100];
                        double kayitliHakedişUrunAdet[100];
                        double kayitliHakedişUrunTutar[100];

                        string kayitliUrunNo[100];
                        string kayitliUrunAdi[100];
                        double kayitliUrunAdet[100];
                        double kayitliUrunBirimTutar[100];
                        string kayitliUrunMarkasi[100];


                        string adediDegistirilcekUrunNo;
                        int sayac = 0;
                        int toplamProjeUrunSayisi = 0;
                        int toplamUrunSayisi = 0;
                        char projeOlupOlmadigiKontrolu = 'h';
                        char urunOlupOlmadigiKontrolu = 'h';
                        char hakedisteProjeyeAitAlınanUrununOlupOlmadigiKontrolu = 'h';

                        cout << "Hangi Projeye Urun Eklemek Istiyorsunuz:  " << endl;
                        cin >> urunAdediBelirlenecekProjeNo;

                        ifstream HakedişOku;
                        HakedişOku.open("hakediş.txt");
                        while (!HakedişOku.eof())
                        {
                            sayac++;
                            HakedişOku >> projeNo >> projeHakedişTarihi >> urunNo >> secilenUrunAdet >> urunTutar;
                            kayitliHakedişProjeNo[sayac] = projeNo;
                            kayitliHakedişTarihi[sayac] = projeHakedişTarihi;
                            kayitliHakedişUrunNo[sayac] = urunNo;
                            kayitliHakedişUrunAdet[sayac] = secilenUrunAdet;
                            kayitliHakedişUrunTutar[sayac] = urunTutar;
                        }
                        toplamProjeUrunSayisi = sayac;
                        sayac = 0;

                        ifstream UrunOku;
                        UrunOku.open("urun.txt");
                        while (!UrunOku.eof())
                        {
                            sayac++;
                            UrunOku >> urunNo >> urunAdi >> urunBirim >> urunBirimFiyat >> urunMarkasi;
                            kayitliUrunNo[sayac] = urunNo;
                            kayitliUrunAdi[sayac] = urunAdi;
                            kayitliUrunAdet[sayac] = urunBirim;
                            kayitliUrunBirimTutar[sayac] = urunBirimFiyat;
                            kayitliUrunMarkasi[sayac] = urunMarkasi;

                        }
                        toplamUrunSayisi = sayac;

                        for (sayac = 1; sayac <= toplamProjeUrunSayisi; sayac++)
                        {
                            if (urunAdediBelirlenecekProjeNo == kayitliHakedişProjeNo[sayac])
                            {
                                projeOlupOlmadigiKontrolu = 'e';
                            }
                        }

                        for (sayac = 1; sayac <= toplamProjeUrunSayisi; sayac++)
                        {
                            if (urunAdediBelirlenecekProjeNo == kayitliHakedişProjeNo[sayac])
                            {
                                eklenecekProjeninHakedişTarihi = kayitliHakedişTarihi[sayac];
                            }
                        }

                        if (projeOlupOlmadigiKontrolu != 'e')
                        {
                            cout << "Boyle Bir Proje Yok!" << endl << endl;
                        }

                        if (projeOlupOlmadigiKontrolu == 'e')
                        {
                            cout << "Hangi Urunden Eklemek Istiyorsunuz:" << endl;
                            cin >> eklenecekUrunNo;

                            for (sayac = 1; sayac <= toplamUrunSayisi; sayac++)
                            {
                                if (kayitliUrunNo[sayac] == eklenecekUrunNo)
                                {
                                    cout << "Kac Adet Eklemek Istiyorsunuz:" << endl;
                                    cin >> eklenecekUrunAdet;

                                    double Fiyat = eklenecekUrunAdet * kayitliUrunBirimTutar[sayac];

                                    double Adet = kayitliUrunAdet[sayac];
                                    kayitliUrunAdet[sayac] = Adet - eklenecekUrunAdet;

                                    if (eklenecekUrunAdet <= kayitliUrunAdet[sayac])
                                    {                                       
                                        for (int sayac2 = 1; sayac2 <= toplamProjeUrunSayisi; sayac2++)
                                        {
                                            if (kayitliHakedişProjeNo[sayac2] == urunAdediBelirlenecekProjeNo && kayitliHakedişUrunNo[sayac2] == eklenecekUrunNo)
                                            {
                                                hakedisteProjeyeAitAlınanUrununOlupOlmadigiKontrolu = 'e';

                                                double ilkAdet = kayitliHakedişUrunAdet[sayac2];
                                                kayitliHakedişUrunAdet[sayac2] = ilkAdet + eklenecekUrunAdet;

                                                double ilkFiyat = kayitliHakedişUrunTutar[sayac2];
                                                kayitliHakedişUrunTutar[sayac2] = ilkFiyat + Fiyat;

                                                ofstream HakedişYaz;
                                                HakedişYaz.open("hakediş.txt", ios::out);
                                                {
                                                    for (int sayac3 = 1; sayac3 < toplamProjeUrunSayisi; sayac3++)
                                                    {
                                                        HakedişYaz << kayitliHakedişProjeNo[sayac3] << ' ' << kayitliHakedişTarihi[sayac3] << ' ' << kayitliHakedişUrunNo[sayac3] << ' ' << kayitliHakedişUrunAdet[sayac3] << ' ' << kayitliHakedişUrunTutar[sayac3] << "\n";
                                                    }
                                                }
                                            }
                                        }

                                        if (hakedisteProjeyeAitAlınanUrununOlupOlmadigiKontrolu == 'h')
                                        {
                                            ofstream HakedişYaz;
                                            HakedişYaz.open("hakediş.txt", ios::app);
                                            {
                                                HakedişYaz << urunAdediBelirlenecekProjeNo << ' ' << eklenecekProjeninHakedişTarihi << ' ' << eklenecekUrunNo << ' ' << eklenecekUrunAdet << ' ' << Fiyat << "\n";
                                            }
                                        }                                                                              

                                        ofstream UrunYaz;
                                        UrunYaz.open("urun.txt", ios::out);
                                        {
                                            for (int sayac2 = 1; sayac2 <= toplamUrunSayisi-1; sayac2++)
                                            {
                                                UrunYaz << kayitliUrunNo[sayac2] << ' ' << kayitliUrunAdi[sayac2] << ' ' << kayitliUrunAdet[sayac2] << ' ' << kayitliUrunBirimTutar[sayac2] << ' ' << kayitliUrunMarkasi[sayac2] << "\n";
                                            }
                                        }
                                    }
                                    else
                                    {
                                        cout << "Elimizide Bu Kadar Urun Yok!" << endl << endl;
                                    }
                                    break;
                                }
                            }
                        }

                        cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                        cin >> devamSecim;
                        if (devamSecim != 'e' && devamSecim != 'h')
                        {
                            cout << "Lutfen e veya h yaziniz";
                            cin >> devamSecim;
                            cout << endl;
                        }
                    }

                    if (secim4 == "2")
                    {
                        string cikarmaProjeNo;
                        string cikarmaUrunNo;
                        double cikarmaAdet;
                        string cikarildiktanSonraAdet;
                        char projeOlupOlmadigiKontrolu = 'h';
                        char urunOlupOlmadigiKontrolu = 'h';
                        string urunAdediBelirlenecekProjeNo;
                        string kayitliProjeNo[100];
                        int kayitliHakedişTarihi[100];
                        string kayitliUrunNo[100];
                        double kayitliUrunAdet[100];
                        double kayitliUrunTutar[100];
                        int sayac = 0;
                        int toplamProjeSayisi = 0;

                        cout << "Urun Cikarmak Istediginiz Projenin Nosu:  " << endl;
                        cin >> cikarmaProjeNo;

                        ifstream HakedişOku;
                        HakedişOku.open("hakediş.txt");
                        while (!HakedişOku.eof())
                        {
                            sayac++;
                            HakedişOku >> projeNo >> projeHakedişTarihi >> urunNo >> secilenUrunAdet >> urunTutar;
                            kayitliProjeNo[sayac] = projeNo;
                            kayitliHakedişTarihi[sayac] = projeHakedişTarihi;
                            kayitliUrunNo[sayac] = urunNo;
                            kayitliUrunAdet[sayac] = secilenUrunAdet;
                            kayitliUrunTutar[sayac] = urunTutar;
                        }
                        toplamProjeSayisi = sayac;

                        for (sayac = 1; sayac <= toplamProjeSayisi; sayac++)
                        {
                            if (cikarmaProjeNo == kayitliProjeNo[sayac])
                            {
                                projeOlupOlmadigiKontrolu = 'e';

                            }
                        }
                        if (projeOlupOlmadigiKontrolu != 'e')
                        {
                            cout << "Boyle Bir Proje Yok!" << endl << endl;
                        }
                        if (projeOlupOlmadigiKontrolu == 'e')
                        {
                            cout << "Cikarmak Istediginiz Urun Nosu: " << endl;
                            cin >> cikarmaUrunNo;

                            for (sayac = 1; sayac <= toplamProjeSayisi; sayac++)
                            {
                                if (cikarmaProjeNo == kayitliProjeNo[sayac])
                                {
                                    if (cikarmaUrunNo == kayitliUrunNo[sayac])
                                    {
                                        urunOlupOlmadigiKontrolu = 'e';
                                        cout << "Kac Adet Cikarmak Istiyorsunuz?" << endl;
                                        cin >> cikarmaAdet;
                                        if (cikarmaAdet < kayitliUrunAdet[sayac])
                                        {
                                            double tut = kayitliUrunAdet[sayac];
                                            kayitliUrunAdet[sayac] = tut - cikarmaAdet;

                                            double fiyatTut = kayitliUrunTutar[sayac];
                                            double adetFiyat = fiyatTut / tut;
                                            double sonFiyat = (tut - cikarmaAdet) * adetFiyat;
                                            kayitliUrunTutar[sayac] = sonFiyat;

                                            ofstream HakedisYaz;
                                            HakedisYaz.open("hakediş.txt", ios::out);
                                            {
                                                for (int sayac2 = 1; sayac2 <= toplamProjeSayisi; sayac2++)
                                                {
                                                    HakedisYaz << kayitliProjeNo[sayac2] << ' ' << kayitliHakedişTarihi[sayac2] << ' ' << kayitliUrunNo[sayac2] << ' ' << kayitliUrunAdet[sayac2] << ' ' << kayitliUrunTutar[sayac2] << "\n";
                                                }
                                            }
                                            break;
                                        }
                                        else if (cikarmaAdet == kayitliUrunAdet[sayac])
                                        {
                                            ofstream HakedisYaz;
                                            HakedisYaz.open("hakediş.txt", ios::out);
                                            {
                                                for (int sayac3 = 1; sayac3 <= toplamProjeSayisi; sayac3++)
                                                {
                                                    if (cikarmaUrunNo != kayitliUrunNo[sayac3])
                                                    {
                                                        HakedisYaz << kayitliProjeNo[sayac3] << ' ' << kayitliHakedişTarihi[sayac3] << ' ' << kayitliUrunNo[sayac3] << ' ' << kayitliUrunAdet[sayac3] << ' ' << kayitliUrunTutar[sayac3] << "\n";
                                                    }
                                                    else
                                                    {
                                                        sayac3++;
                                                    }
                                                }
                                            }
                                            break;
                                        }
                                        else
                                        {
                                            cout << "Cikarmak Istediginiz Adet Aldiginiz Adetten Fazla Islem Yapilamiyor" << endl << endl;
                                            break;
                                        }
                                    }
                                }
                            }
                            cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                            cin >> devamSecim;
                            if (devamSecim != 'e' && devamSecim != 'h')
                            {
                                cout << "Lutfen e veya h yaziniz";
                                cin >> devamSecim;
                                cout << endl;
                            }
                        }
                    }
                }

                if (secim3 == "2")
                {
                    string tarihiBelirlenecekProjeNo;
                    string kayitliProjeNo[100];
                    int kayitliHakedişTarihi[100];
                    string kayitliUrunNo[100];
                    double kayitliUrunAdet[100];
                    double kayitliUrunTutar[100];
                    int belirlenenHakedişTarihi;
                    int sayac = 0;
                    int toplamProjeSayisi=0;
                    char projeOlupOlmadigiKontrolu = 'h';

                    cout << "Hakedis Tarihi Belirlemek Istediginiz Projenin Nosu:  " << endl ;
                    cin >> tarihiBelirlenecekProjeNo;
                    cout << endl << endl;

                    ifstream HakedişOku;
                    HakedişOku.open("hakediş.txt");
                    while (!HakedişOku.eof())
                    {
                        sayac++;
                        HakedişOku >> projeNo >> projeHakedişTarihi >> urunNo >> secilenUrunAdet >> urunTutar;
                        kayitliProjeNo[sayac] = projeNo;
                        kayitliHakedişTarihi[sayac] = projeHakedişTarihi;
                        kayitliUrunNo[sayac] = urunNo;
                        kayitliUrunAdet[sayac] = secilenUrunAdet;
                        kayitliUrunTutar[sayac] = urunTutar;
                    }
                    toplamProjeSayisi = sayac;

                    for (sayac = 1; sayac <= toplamProjeSayisi; sayac++)
                    {
                        if (tarihiBelirlenecekProjeNo == kayitliProjeNo[sayac])
                        {
                            projeOlupOlmadigiKontrolu = 'e';

                        }
                    }
                    if (projeOlupOlmadigiKontrolu != 'e')
                    {
                        cout << "Boyle Bir Proje Yok!" << endl << endl;
                    }
                    if (projeOlupOlmadigiKontrolu == 'e')
                    {
                        cout << "Hakedis Tarihi Giriniz:  " << endl;
                        cin >> belirlenenHakedişTarihi;
                 
                        for (sayac = 1; sayac <= toplamProjeSayisi; sayac++)
                        {
                            if (tarihiBelirlenecekProjeNo == kayitliProjeNo[sayac])
                            {
                                kayitliHakedişTarihi[sayac] = belirlenenHakedişTarihi;
                            }
                        }

                        ofstream HakedisYaz;
                        HakedisYaz.open("hakediş.txt", ios::out);
                        {
                            for (sayac = 1; sayac <= toplamProjeSayisi; sayac++)
                            {
                                HakedisYaz << kayitliProjeNo[sayac] << ' ' << kayitliHakedişTarihi[sayac] << ' ' << kayitliUrunNo[sayac] << ' ' << kayitliUrunAdet[sayac] << ' ' << kayitliUrunTutar[sayac] << "\n";
                            }
                        }

                        cout << "Islem Basarili!" << endl << endl;
                    }
                    cout << endl << "Isleme Devam Etmek Istiyor Musunuz?(devam etmek istiyorsaniz e istemiyorsaniz h yaziniz):  ";
                    cin >> devamSecim;
                    if (devamSecim != 'e' && devamSecim != 'h')
                    {
                        cout << "Lutfen e veya h yaziniz";
                        cin >> devamSecim;
                        cout << endl;
                    }
                }
            }
        }

    } while (devamSecim == 'e');

    system("pause");

}

void urunMenu()
{
    cout << "Urun Islemi Olarak Ne Yapmak Istiyorsunuz?" << endl<<endl;
    cout << "1)Urun Ekleme" << endl<<endl;
    cout << "2)Urun Silme" << endl<<endl;
    cout << "3)Urune Ait Bilgi Arama" << endl<<endl;
    cout << "4)Tum Urunleri Listeleme" << endl<<endl;
    cout << "5)Urun Adedi Fiyati Guncelleme" << endl << endl;
}

void projeMenu()
{
    cout << endl;
    cout << "Proje Islemi Olarak Ne Yapmak Istiyorsunuz?" << endl<<endl;
    cout << "1)Proje Ekleme" << endl<<endl;
    cout << "2)Proje Silme" << endl<<endl;
    cout << "3)Projeye Ait Bilgi Arama" << endl<<endl;
    cout << "4)Tum Projeleri Listeleme" << endl<<endl;
    cout << "5)Proje Urun Miktarlarini Guncelle ve Tarihi Belirle" << endl << endl;
}
