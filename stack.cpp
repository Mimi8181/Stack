#include <iostream>
using namespace std;

int maksimal = 5;
string arrayBuku[5];
int top = 0;

bool isFull()
{
    if (top == maksimal)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmpty()
{
    if (top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pushArray(string data)
{
    if (isFull())
    {
        cout << "Data penuh" << endl;
    }
    else
    {
        arrayBuku[top] = data;
        top++;
    }
}

void popArray()
{
    if (isEmpty())
    {
        cout << "Data kosong!!" << endl;
    }
    else
    {
        arrayBuku[top - 1] = "";
        top--;
    }
}

void displayArray()
{
    if (isEmpty())
    {
        cout << "Data kosong!!" << endl;
    }
    else
    {
        cout << "Data stack array : " << endl;
        for (int i = maksimal - 1; i >= 0; i--)
        {
            if (arrayBuku[i] != "")
            {
                cout << "Data : " << arrayBuku[i] << endl;
            }
        }
        cout << "\n"
             << endl;
    }
}

void peekArray(int posisi)
{
    if (isEmpty())
    {
        cout << "Data kosong!!" << endl;
    }
    else
    {
        int index = top;
        for (int i = 0; i < posisi; i++)
        {
            index--;
        }
        cout << "Data posisi ke-" << posisi << " : " << arrayBuku[index] << endl;
    }
}

void changeArray(string data, int posisi)
{
    if (isEmpty())
    {
        cout << "Data kosong!!" << endl;
    }
    else
    {
        int index = top;
        for (int i = 0; i < posisi; i++)
        {
            index--;
        }
        nomor[index] = data;
    }
}
int nomor[];
int countArray()
{
    if (isEmpty())
    {
        return 0;
    }
    else
    {
        return top;
    }
}

void destroyArray()
{
    for (int i = 0; i < top; i++)
    {
        arrayBuku[i] = "";
    }
    top = 0;
}

int terbesar()
{
    int data = nomor[top];
    for (int i = top - 1; i >= 0; i--)
    {
        if (nomor[i] >= data)
        {
            data = nomor[i];
        }
    }
    return data;
}

int terkecil()
{
    int data = nomor[top];
    for (int i = top - 1; i >= 0; i--)
    {
        if (nomor[i] <= data)
        {
            data = nomor[i];
        }
    }
    return data;
}

int nilaiTotal()
{
    int total = 0;
    for (int i = top; i >= 0; i--)
    {
        int data = nomor[i];
        total += data;
    }
    return total;
}

int rata2()
{
    int average = nilaiTotal() / top;
    return average;
}

// Pakai Linked List
struct dataBarang
{
    string namaBarang;
    int hargaBarang;

    // pointer
    dataBarang *prev;
    dataBarang *next;
};

dataBarang *head, *tail, *cur, *newNode, *del;
int maksimalBarang = 5;

void createBarang(string namaBarang, int hargaBarang)
{
    head = new dataBarang();
    head->namaBarang = namaBarang;
    head->hargaBarang = hargaBarang;
    head->prev = NULL;
    head->next = NULL;
    tail = head;
}

int countBarang()
{
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        int banyak = 0;
        cur = head;
        while (cur != NULL)
        {
            cur = cur->next;
            banyak++;
        }
        return banyak;
    }
}

bool isFullBarang()
{
    if (countBarang() == maksimalBarang)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isEmptyBarang()
{
    if (countBarang() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void pushBarang(string namaBarang, int hargaBarang)
{

    if (isFullBarang())
    {
        cout << "Stack Full!!" << endl;
    }
    else
    {
        if (isEmptyBarang())
        {
            createBarang(namaBarang, hargaBarang);
        }
        else
        {
            newNode = new dataBarang();
            newNode->namaBarang = namaBarang;
            newNode->hargaBarang = hargaBarang;
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = NULL;
            tail = newNode;
        }
    }
}

void popBarang()
{
    del = tail;
    tail = tail->prev;
    tail->next = NULL;
    delete del;
}

void displayBarang()
{
    if (isEmptyBarang())
    {
        cout << "Data Barang kosong" << endl;
    }
    else
    {
        cout << "\n\nData barang : " << endl;
        cur = tail;
        while (cur != NULL)
        {
            cout << "Data Barang : " << cur->namaBarang << " - Rp." << cur->hargaBarang << endl;
            cur = cur->prev;
        }
    }
}

void peekBarang(int posisi)
{

    if (isEmptyBarang())
    {
        cout << "Data Barang kosong" << endl;
    }
    else
    {
        int nomor = 1;
        cur = tail;
        while (nomor < posisi)
        {
            cur = cur->prev;
            nomor++;
        }
        cout << "Data Barang Posisi ke-" << posisi << " : " << cur->namaBarang << " - Rp." << cur->hargaBarang << endl;
    }
}

void changeBarang(string namaBarang, int posisi)
{
    if (isEmptyBarang())
    {
        cout << "Data Barang kosong" << endl;
    }
    else
    {
        int nomor = top;
        for (int i = 0; i < posisi; i++)
        {
            nomor--;
        }
        arrayBuku[nomor] = namaBarang;
    }
}

void destroyBarang()
{
    cur = head;
    while (cur != NULL)
    {
        del = cur;
        head = head->next;
        delete del;
        cur = cur->next;
    }
}

int main()
{

    pushArray("Matematika");
    pushArray("Web Programming");
    pushArray("Pemrograman Berbasis Objek");
    pushArray("Sistem Operasi");
    pushArray("Struktur Data");
    displayArray();

    cout << "Apakah data full ? : " << isFull() << endl;
    cout << "Apakah data kosong ? : " << isEmpty() << endl;

    peekArray(3);

    cout << "Banyak data : " << countArray() << endl;
}