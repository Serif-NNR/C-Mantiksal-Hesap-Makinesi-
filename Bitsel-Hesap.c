/* -*- Mode: C; indent-tabs-mode: t; c-basic-offset: 4; tab-width: 4 -*-  */
/*
 * 
 * Copyright (C) 2017 Laprooz(Personal Computer Name) <Serif Inanir ALKU-Bilgisayar Muh.>
 *
 * C_kriptoloji_odevi is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * bitsel-hesap is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 // 
 /* Şerif İnanır - Alanya Alaaddin Keykubat Üniversitesi - Bilgisayar Mühandisliği */




/*   PROGRAM AMACI
	========================================================

	Girilen sayılarla mantıksal işlemler gerçekleştirir.
	
	Teklik Çiftlik nedir?
	-> Mantıksal işlem sonucunu ikilik sistemde ki 
	  karşılığının içinde ki 1 sayılarına bakar.
	  Ç (Çift) girildiyse ve bu 1 sayıları
			- Tek ise, sonuç bitlerinin
			  sonuna 1 ekleyerek 1 sayılarını 
			  çift yapar.
			- Çift ise sonuç bitlerinin sonuna
			  0 ekleyerek 1 sayılarının 
			  çiftliğini korur. 
	(T girilirse olay tam tersi şeklinde oluşur.)

*/






// Program Baslangici //////////////////////////////////


#include <stdio.h>

unsigned int bitsel_son=10,sifreli;
// Bu iki değişkeni PUBLIC yapmayı tercih ettim.
// Her fonksiyon içerisinde değeri farklı olacak ve her fonksiyonda farklı işlenecekler.
// Java'da ki kapsülleme gibi, tipik bir ağaç yapısı oluşturmak için.

int main(void)
{
    hakkimda();
    unsigned int operant1,operant2;
    char bitsel_operator;
	printf("Girdilerinizi\n[Isaretsiz Tamsayi] [Bitsel Operator] [Isaretsiz Tamsayi]\nseklinde giriniz :\n\(Ornek: 23^10\)\n>>>  ");
	scanf("%u%c%u",&operant1,&bitsel_operator,&operant2);
	switch(bitsel_operator){
        case '&':
            _and_(operant1,operant2);
            break;
        case '|':
            _or_(operant1,operant2);
            break;
        case '^':
            _xor_(operant1,operant2);
            break;
        case '<':
            sag_kaydir(operant1,operant2);
            break;
        case '>':
            sol_kaydir(operant1,operant2);
            break;
        default:
            printf("\nHatali bir bitsel operator girdiniz.\nProgrami yeniden baslatarak girdinizi kontrol ediniz.");
            break;
	}
	printf("\nProgram sonlandirildi. Cikmak icin ENTER'a basiniz.");

    system("pause");
//	Ben GNU/Linux kullandığım için son aşamada system("pause"); de hata aldım.    //////////////////////////////////
//  Ms-DOS'da işe yarıyor sadece. Muhtemelen MacOS'da da hata vericek.            //////////////////////////////////

    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////
// BURADAKİ FONKSİYONLAR GİRİLEN DEĞERLERİ MANTIKSAL İŞLEME SOKARLAR
int _and_(operant1,operant2){
    printf("AND uygulaniyor...\nSifrelenmis Veri :  ");
    bitsel_son=operant1&operant2;
    printf("%u",bitsel_son);
    _TC_soru(bitsel_son);
    return 0;
}
int _or_(operant1,operant2){
    printf("OR uygulaniyor...\nSifrelenmis Veri :  ");
    bitsel_son=operant1|operant2;
    printf("%u",bitsel_son);
    _TC_soru(bitsel_son);
    return 0;
}
int _xor_(operant1,operant2){
    printf("XOR uygulaniyor...\nSifrelenmis Veri :  ");
    bitsel_son=operant1^operant2;
    printf("%u",bitsel_son);
    _TC_soru(bitsel_son);
    return 0;
}



}*/
int sag_kaydir(operant1,operant2){
    printf("Sag kaydiriliyor...\nSifrelenmis Veri :  ");
    bitsel_son=operant1<<operant2;
    printf("%u",bitsel_son);
   _TC_soru(bitsel_son);
    return 0;
}
int sol_kaydir(operant1,operant2){
    printf("Sola kaydiriliyor...\nSifrelenmis Veri :  ");
    bitsel_son=operant1>>operant2;
    printf("%u",bitsel_son);
   _TC_soru(bitsel_son);
    return 0;
}
////////////////////////////////////////////////////////////////////////////////


int _TC_soru(bitsel_son){                                          // Bitsel-Mantıksal işlem fonksiyonlarının
    char tc_cevap;                                                                // Sonuçları buraya gönderilir. Burada Eslik değeri
    printf("\n>>>  Eslik kuralini belirtin [T/C]:  ");             // Kullanıcıya sorulur. Cevaba göre sonuc (bitsel_son)
    scanf("%s",&tc_cevap);                                                                // Değeri gerekli fonksiyonlara gönderilir.
    switch(tc_cevap){
        case 'T':
            printf("Secilen deger : Teklik\n");
            if (bitsel_son==0){
                cevap_bas(1,0001);
            }
            else{
                _T_(bitsel_son);
            }
            break;
        case 'C':
            printf("Secilen deger : Ciftlik\n");
            if (bitsel_son==0){
                cevap_bas(0,0000);
            }
            else{
                _C_(bitsel_son);
            }
            break;
        default:
            printf("Hatali eslik biti girdiniz. Programi tekrar baslatarak yeniden deneyin.\n");
    }
}


////////////////////////////////  BU FONKSİYONU SONRADAN EKLEDİM ÖDEVE --- İKİLİK TABANDAKİ TOPLAM 1 SAYISINI VERİYOR
int bit_haneleri(bin_paw){
    unsigned int basm=1,carp=1,toplamBir=0,ara=0;
    while (bin_paw/carp!=1){
        carp*=10;
        basm+=1;
    }
    ara=bin_paw;
    //printf("%u",ara);
    //printf("%u",carp);  //HATAYA KARŞI ÇIKTI KONTROLÜ
    while (carp>1){
        if (ara/carp==1){
            toplamBir+=1;
            ara=ara-carp;
        }
        //printf("\n%u-%u",carp,toplamBir);  HATA GÖRMEK İÇİN
        carp/=10;
    }
    return toplamBir;
}


int _C_(bitsel_son){               // Yaptığı tek şey:

    unsigned ikilik_taban=0,bitHane=0,ikilikTaban;
    sifreli=bitsel_son<<1;        // _TC_sorusu ndan aldığı sonuc değerini (bitsel_son)
                                    // sola bir kaydırır yani sağına bir 0 ekleyerek sayıyı büyütür.

    ikilik_taban=ikilik_sifre(sifreli);
    bitHane=bit_haneleri(ikilik_taban);
    //printf("%u\n%u",bitHane,ikilik_taban);  //İKİLİK TABANDA KAÇ TANE 1 VAR

    if (bitHane%2==1){
        sifreli+=1;
        }
    ikilikTaban=ikilik_sifre(sifreli);
    //printf("%u",sifreli);
    cevap_bas(sifreli,ikilikTaban);

    return 0;
}
int _T_(bitsel_son){               // Yaptığı tek şey:
    unsigned ikilik_taban=0,bitHane=0,ikilikTaban;
    sifreli=bitsel_son<<1;        // _C_ fonksiyonunun aynısı yapar ve sayıya 1 ekler.
                                        // Ondalık ve ikilik tabanda sayıya 1 eklenmesi aynı şeydir.

    ikilik_taban=ikilik_sifre(sifreli);      // Bu fonksiyonda sayıya ondalık tabanda bir ekler.
    bitHane=bit_haneleri(ikilik_taban);

    if (bitHane%2==0){
        sifreli+=1;
    }
    ikilikTaban=ikilik_sifre(sifreli);
    //printf("%u",sifreli);
    cevap_bas(sifreli,ikilikTaban);
    return 0;
}
// SAYIYI BİR BİRİM KAYDIRIP ikilik_sifre FONKSİYONUNA SET EDER.

int ikilik_sifre(sifreli){                           // Sayıyı onluk tabandan ikilik tabana çeviren fonksiyon:
    unsigned int deger,ara_islem,carp,bin_paw,cvp=0;  // Sayıyı 2'ye bölerek kalan değerini değişkene ekler.

    bin_paw=0;
    carp=1;
    cvp=sifreli;
    while(cvp>0){
        ara_islem=cvp/2;
        deger=cvp%2;
        cvp=ara_islem;
        bin_paw+=deger*carp;
        carp=carp*10;
    }
    return bin_paw;
}
// ONLUK SAYIYI VE İKİLİK TABANDA KARŞILIĞINI cevap_bas FONKSİYONUNA SET EDER.
// İKİLİK TABANA ÇEVİRİR SADECE.


int cevap_bas(cvp,bin_paw){                       // Aslında bu fonksiyona çok gerek duymadım
    printf("SONUC ONLUK SAYI   :   %u",cvp);        // Fakat fonksiyonel programlama yapmaya çalıştığımdan yapiyim dedim.
    printf("\n");                                 // He tabi bir de printf lerde ki iki nokta üst üsteyi alt alta
    printf("SONUC IKILIK SAYI  :   %u",bin_paw);    // daha kolay hizalamak için oluşturdum  -,-
    return (0);
}

int hakkimda(){
    printf("\tSerif Inanir - ALKU \n################################################################\n\n");
    return 0;
}
/********************************************************\  Program Bitisi
**********************************************************
** Şerif İnanır - Alanya Alaaddin Keykubat Üniversitesi **
**    Bilgisayar Mühendisliği - 1. Sınıf     **
**       Bitsel Operatörlerle Kriptoloji Ödevi          **
**********************************************************
\********************************************************/
