#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<string.h>
#include<stdbool.h>


// 1. S�n�flar�n �devi sadece bir say� tutan ba�l� liste i�in listeye eleman ekleme(sona ve araya), listeden eleman ��karma (aranan de�er) ve listeyi yazd�rma fonksiyonlar�n� yazmak.

// Ba�l� listedir. Dinamik boyutlu bir soyut veri yap�s�d�r. her eleman kendisinden sonra gelen eleman�n adresini i�aret eder.
// Araya elaman eklemede a��r� bir h�z fark� olu�ur. Arraylerde boyut sabittir ama linkedlistte ise boyut belle�in boyutuna g�re de�i�ebilir. her Node(d���m) bellekte farkl� yerlerde olabilir.
// Arraylist gibi bellekte s�ral� olarak dizilen yap�lara kar��n dezavantajlar� ise bellkete adreste ta��d��� i�in fazla yer kaplar. istenen bir elemana gidebilmek i�in en ba�tan iterasyon yapmak laz�m(��nk� de�erin adresi belli de�il). Dizilerde rastgele eri�im vard�r ancak linkedListlerde s�ral� eri�im var.
// listenin ba��n� ve sonun g�steren i�aret�iler vard�r.

struct node  // Node'ler i�erisinde istedi�imiz kadar de�er belirleyebiliriz kesin olmas� gereken kendinden �nceki Nodenin pointeri olmal�.
{

    int number;
    struct node* ptr;

};

typedef struct node AA;

AA* Head = NULL; // default olarak bir ba� belirledik.
AA* Tail = NULL; // default olarak bir son belirledik.

void addSon(int data)  // eklemede iki farkl� i�lem var birisi linkedList'in bo� olma di�eri ise dolu olma durumu.
{

    if (Head == NULL)
    {

        AA* newNode = (AA*)malloc(sizeof(AA));
        newNode->number = data;
        newNode->ptr = NULL;
        Head = newNode;
        Tail = newNode;

    }
    else
    {

        AA* newNode = (AA*)malloc(sizeof(AA));
        newNode->number = data;
        newNode->ptr = NULL;
        Tail->ptr = newNode;

        Tail = newNode;
    }

}

void addAra(int data)  // eklemede iki farkl� i�lem var birisi linkedList'in bo� olma di�eri ise dolu olma durumu.
{

    if (Head == NULL)
    {

        AA* newNode = (AA*)malloc(sizeof(AA));
        newNode->number = data;
        newNode->ptr = NULL;
        Head = newNode;
        Tail = newNode;

    }
    else
    {

        int elemansayisi = kacelemanVar();
        int zrt;
        do
        {

            printf("Kacinci siraya eleman eklemek istersiniz: ");
            scanf("%d",&zrt);
            if(zrt < 1 || zrt > elemansayisi)
            {
                printf("Yanlis bir deger girdiniz...\n");
            }
        }
        while(zrt < 1 || zrt > elemansayisi);
        if(zrt == elemansayisi)
        {
            addSon(data);
        }
        else if (zrt == 1)
        {
            basa_ekle(data);
        }
        else
        {

            AA* newNode = (AA*)malloc(sizeof(AA));
            newNode->number = data;
            newNode->ptr = NULL;


            AA* index = Head;
            int i = 0;
            while(i < zrt - 1)
            {
                printf("%d-",index->number);
                index = index->ptr;
                i++;
            }
            AA* gecici = index->ptr;
            index->ptr = newNode;
            newNode->ptr = gecici;

        }

    }

}


void basa_ekle(int data)
{
    if(Head==NULL)
    {
        AA* newNode=(AA *)malloc(sizeof(AA));
        newNode->number=data;
        newNode->ptr=NULL;
        Head=Tail=newNode;

    }
    else
    {
        AA *newNode=(AA *)malloc(sizeof(AA));
        newNode->number = data;
        newNode->ptr = Head;
        Head=newNode;

    }

}

int kacelemanVar()
{

    AA* index = Head;
    int i = 0;
    while(index != NULL)
    {
        index = index->ptr;
        i++;
    }

    return i;

}

void print()
{

    AA* index = Head;
    int i = 1;
    while(index != NULL)
    {
        printf("%d-",index->number);
        index = index->ptr;
        i++;
    }
    if(i == 1)
    {
        printf("Listede eleman yok...\n");
    }
}

void search(int TT)
{

    AA* index = Head;
    int i = 1;
    while(index != NULL)
    {
        if(index->number == TT)
        {
            print("Aranan deger %d. sirada...\n",i);
            return;
        }
        index = index->ptr;
        i++;
    }

    if(i == 1)
    {
        printf("\nListede eleman yok...\n\n");
    }

}

void deleteData(int data)
{

    AA* TT = NULL;
    AA* YY = Head;
    if(YY == NULL)
    {
        printf("Listebos...\n\n");
        return;
    }
    else if(Head->number == data)
    {
        AA* UU = Head;
        Head = Head->ptr;
        free(UU);
        return;
    }
    else
    {

        while(YY->ptr != NULL && YY->ptr != data)
        {
            TT = YY;
            YY = YY->ptr;
        }
        if(YY == NULL)
        {
            print("Aranan deger yok...");
            return;
        }
        TT->ptr = YY->ptr;
        if(Tail->number == data)
        {
            Tail = YY;
        }
        free(YY);

    }




}

int main()
{

    while(true)
    {

        int select = menu();
        if(select == 5)
        {
            printf("Sistemden cikiliyor...");
            sleep(2);
            break;
        }
        else if(select == 4)
        {

            printf("Arayacaginiz degeri giriniz: ");
            int dt;
            scanf("%d",&dt);
            search(dt);

        }
        else if(select == 3)
        {
            print();
        }
        else if(select == 2)
        {
            printf("Silmek istediginiz degeri giriniz: ");
            int dt;
            scanf("%d",&dt);
            deleteData(dt);
        }
        else
        {
            int secim;
            do
            {
                printf("Sona eklemek isterseniz 1, Araya eklemek isterseniz 2 secimini yapin.");
                scanf("%d",&secim);
            }
            while(secim < 1 || secim > 2);
            if(secim == 1)
            {
                printf("Eklemek istediginiz degeri giriniz: ");
                int dt;
                scanf("%d",&dt);
                addSon(dt);
            }
            else
            {
                printf("Eklemek istediginiz degeri giriniz: ");
                int dt;
                scanf("%d",&dt);
                addAra(dt);
            }

        }

    }


    return 0;

}

int menu()
{
    int select;
    do
    {
        printf("\n1-Eleman ekle\n2-Eleman sil\n3-Elemanlarin hepsini yazdir\n4-Eleman ara\n5-Sistemden cik\n\nYapacaginiz islemi seciniz:");
        scanf("%d",&select);
        if(select < 1 || select > 5)
        {
            print("\nDogru bir secim giriniz...\n");
        }
    }
    while(select < 1 || select > 5);
    system("cls");
    printf("\n");

    return select;
}

