#include "Sozluk.h"
#include "Kelime.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<conio.h>
#include<fstream>
#include<cstdlib>
#include<cstdio>


using namespace std;

Kelime k1,k2;


void Sozluk:: turkceIngilizceSozluk()

{
  
    system("cls");
    char kelime[20];
    bool sonuc = false;

    cout<<"\nKelime Bulma Ekrani..."<<endl;
    cout<<"Turkcesi : ";
    cin>>kelime;

    cout<<"Turkce\t"<<"Ingilizce"<<endl;
   
   
    ifstream file("kelimeler.txt",ios::app);

    while (file.read((char*)&k1,sizeof(k1)) != NULL);  // k1 nesnesini dosyaya yazdırdık. boyut olarak yer ayırdık.
    {
        if(strcmp(kelime,k1.turkce) == 0 )
        {

        sonuc=true;
        cout<<k1.turkce<<"\t"<<k1.ingilizce<<endl;
        break;

        }
    }

    file.close();
    
    if (sonuc == false)
    {
        cout<<"Aradiginiz kelime bulunamadi."<<endl;
    }

    system("pause"); // entera basana kadar bekletir. bilgileri durdurur.
    
}

void  Sozluk:: ingilizceTurkceSozluk()

{

    
    system("cls");
    char kelime[20];
    bool sonuc = false;

    cout<<"\nKelime Bulma Ekrani..."<<endl;
    cout<<"Ingilizcesi : ";
    cin>>kelime;

    cout<<"Ingilizce\t"<<"Turkce"<<endl;
   
   
    ifstream file("kelimeler.txt",ios::app);

    while (file.read((char*)&k1,sizeof(k1)) != NULL);  // k1 nesnesini dosyaya yazdırdık. boyut olarak yer ayırdık.
    {
        if(strcmp(kelime,k1.ingilizce) == 0 )
        {

        sonuc=true;
        cout<<k1.ingilizce<<"\t"<<k1.turkce<<endl;
        break;

        }
    }

    file.close();
    
    if (sonuc == false)
    {
        cout<<"Aradiginiz kelime bulunamadi."<<endl;
    }

    system("pause"); // entera basana kadar bekletir. bilgileri durdurur.
    
}



void  Sozluk:: kelimeEkle()

{
    system("cls");
    cout<<"\nKelime Ekleme Ekrani..."<<endl;
    cout<<"Turkcesi : ";
    cin>>k1.turkce;
    cout<<"Ingilizcesi : ";
    cin>>k1.ingilizce;
    cout<<"Kelime basariyla eklendi."<<endl;
    

    ofstream file("kelimeler.txt",ios::app);
    file.write((char*)&k1,sizeof(k1)); // k1 nesnesini dosyaya yazdırdık. boyut olarak yer ayırdık.
    file.close();
    cout<"Kayit Tamamlandi"<<endl;



}

void  Sozluk:: kelimeBul()

{

    int secim = menuBul();

    while (secim !=5)
    {
        switch ( secim )
        {

        case 1:
            turkceIngilizce();
            break;

        case 2:
            ingilizceTurkce();
            break;

        default:
            cout<<"Hatali secim yaptiniz."<<endl;
            break;
        }

        secim = menuBul();
        
    }

    cout<<"Ana Menuye Dondunuz..."<<endl;

}

void  Sozluk:: kelimeSil()

{
 
    listele();
    int numara;
    cout<<"Silmek istediginiz kelimenin sirasini giriniz : ";
    cin>>numara;

    int sayac = 0;
    bool sonuc = false;
  
    ifstream file("kelimeler.txt");
    ofstream file2("yedek.txt");

    while (file.read((char*)&k1,sizeof(k1)) != NULL);  // k1 nesnesini dosyaya yazdırdık. boyut olarak yer ayırdık.
    {
        sayac++;
        if(numara == sayac)
        {

        sonuc=true;

        }

        else
        {
           file2.write((char *)&k1 , sizeof(k1) );
        }
        
    }

    file.close();
    file2.close();
    
    if (sonuc )
    {
        remove("kelimeler.txt");
        rename("yedek.txt","kelimeler.txt");
        cout<<"Kelime basariyla silindi."<<endl;
    }
    else
    {
        cout<<"Kelime bulunamadi."<<endl;
    }

    system("pause"); // entera basana kadar bekletir. bilgileri durdurur.


}

void  Sozluk:: listele()

{

    system("cls");
    int sayac = 0;
    cout<<"\nKelime Listeleme Ekrani..."<<endl;
    cout<<"SiraNo"<<"\t"<<"Turkce \t"<<"Ingilizce"<<endl;
    cout<<"Kelime basariyla listelendi."<<endl;
   
    ifstream file("kelimeler.txt",ios::app);

    while (file.read((char*)&k1,sizeof(k1)) != NULL);  // k1 nesnesini dosyaya yazdırdık. boyut olarak yer ayırdık.
    {
        cout<<sayac<<"\t"<<k1.turkce<<"\t"<<k1.ingilizce<<endl;
        
    }

    file.close();
    cout<<"\nToplam Kelime Sayisi : "<<sayac<<endl;
    cout<"Okuma Tamamlandi"<<endl;

   




}

int  Sozluk:: menu()

{ 
    // system("cls");
    int secim;
    cout<<"\nTURKCE INGILIZCE SOZLUK UYUGULAMASI"<<endl;
    cout<<"[1] - Kelime Ekle"<<endl;
    cout<<"[2] - Kelime Bul"<<endl;
    cout<<"[3] - Kelime Sil"<<endl;
    cout<<"[4] - Kelime Listele"<<endl;
    cout<<"[5] - Cikis"<<endl;
    cout<<"Seciminiz : ";
    cin>>secim;

    return secim;

}

int  Sozluk:: menuBul()

{

    system("cls");
    int secim;
    cout<<"\nKELIME BULMA SECENEKLERI"<<endl;
    cout<<"[1] - Turkce Ingilizce"<<endl;
    cout<<"[2] - Ingilizce Turkce"<<endl;
    cout<<"[0] - Ana Menuye Don"<<endl;
    cout<<"Seciminiz : ";
    cin>>secim;

    return secim;


}

void  Sozluk:: giris()

{
    
    int secim = menu();

    while (secim !=5)
    {
        switch ( secim )
        {
        case 1:
            kelimeEkle();
            break;

        case 2:
            menuBul();
            break;

        case 3:
            kelimeSil();
            break;

        case 4:
            listele();
            break;

        default:
            cout<<"Hatali secim yaptiniz."<<endl;
            break;
        }

        secim = menu();
        
    }

    cout<<"Programdan cikiliyor..."<<endl;

}
