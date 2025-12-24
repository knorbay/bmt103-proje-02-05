#include <stdio.h>

/* Ogrenci kayit programı bu programin amaci sturct ve pointer kullanarak aldigimiz
 bilgileri dosyaya kaydetmektir.*/
//Bilgiler için olusturulan yapi

struct ogrenci {
    char soyadi[20],adi[20],bolumu[30],cinsiyet,dogum_yeri[20];
    int no[15],yasi,telefon[15];
};

//Programin basladigi ana fonskiyon

int main() {

    //Dosya islemleri icin degisken

    FILE *fp;

    //Ogrenci yapisindan degisken

    struct ogrenci o;

    //Kayıda devam etmek icin sorulacak sorunun cevap degiskeni

    char devam;

    //Ilk calıstiginda dosyayi olusturmak ve sonrasinda kullanmak icin yapian islem

    fp = fopen("veri.dat", "ab");

//Dosyanin acilip acilmadigini kontrol eder

    if (fp == NULL) {
        printf("Dosya acilamadi!");
        return 1;
    }

//do while sebebi bir kere kayit başlatip sonrasinda devam etmek istemedigini sormak icindir

    do {
        printf("Ogrenci Bilgilerini giriniz.(Turkce harf girmeyiniz.'ç,ğ,ü,ö,ı')\n");
        printf("-------------------------------\n");
        printf("Adi: ");
        scanf( " %[^\n]", o.adi);

        printf("Soyadi: ");
        scanf(" %s", o.soyadi);

        printf("Okul No: ");
        scanf(" %d", &o.no);

        printf("Bolumu: ");
        scanf( " %[^\n]", o.bolumu);

        printf("Cinsiyet (E/K): ");
        scanf(" %c", &o.cinsiyet);

        printf("Dogum yeri: ");
        scanf(" %s", o.dogum_yeri);

        printf("Yasi: ");
        scanf(" %d", &o.yasi);

        printf("Telefon: ");
        scanf(" %d", &o.telefon);
        printf("-------------------------------\n");
        printf("Kayit yapmaya devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devam);

        //fwrite binary seklinde yazdigi ve bizim dosyamizda binary olduğundan bu sekli tercih etmeliyiz

        fwrite(&o, sizeof(struct ogrenci), 1, fp);

    } while (devam == 'E' || devam == 'e');

//Dosya kapatilir sonrasinda program sonlandirilir

    fclose(fp);
    return 0;
}