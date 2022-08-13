#pragma once
#include <iostream>
#include <string>
#include <list>
#define A (sqrt(5) - 1) / 2
using namespace std;


int type = 1;



class HashTableLine {
public:
    int key;
    int data;

    HashTableLine() {
        key = 0;
        data = 0;
    }
};


class HashTable
{
    int m;
    HashTableLine* line;

public:
    HashTable(int V);
    void insertItem(int key, int data);
    void deleteItem(int key);

    ~HashTable() {
        delete[] line;
    }

    int Count() {
        int k = 0;
        for (int i = 0; i < m; i++)
            if (line[i].key != 0)
                k++;
        return k;
    }

    int findItem(int key) {
        int index = hashFunction(key);
        if (line[index].key == 0) {
            cout << "Такого значения нет.\n";
            return -1;
        }
        if (line[index].key != key) {
            while (line[index].key != key) {
                index++;
                if (index == m) {
                    cout << "Такого значения нет.\n";
                    return -1;
                }
            }
        }
        cout << "Line:\n";
        cout << "[" << index << "] -> " << line[index].key << " -> " << line[index].data << endl;
        return index;
    }



    int hashFunction(int key)
    {
        double x = (key * A);
        int k = (x * 1000);
        k = k % 1000;
        x = ((double)k / 1000);
        return x * m;
    }
    void displayHash();


    int linealHash(int key) {
        int hash = hashFunction(key);
        int i = 0;
        while (line[hash + i].key != 0) {
            i++;
        }
        return hash + i;
    }

    int squareHash(int key) {
        int hash = hashFunction(key);
        int i = 0;
        hash = (hash + i + 3 * i * i) % m;
        while (line[hash].key != 0) {
            hash = (hash + i + 3 * i * i) % m;
            i++;
        }
        return hash;
    }

    int doubleHash(int key) {
        int hash = hashFunction(key);
        int i = 0;
        hash = (hash + i * (1 + (key % (m - 1)))) % m;
        while (line[hash].key != 0) {
            hash = (hash + i * (1 + (key % (m - 1)))) % m;
            i++;
        }
        return hash;
    }

};
HashTable::HashTable(int c)
{
    this->m = c;
    line = new HashTableLine[m];
}
void HashTable::insertItem(int key, int data)
{
    if (Count() == m && type == 1) {
        cout << "Таблица заполнена.\n";
        return;
    }
    int index = hashFunction(key);
    if (line[index].key != 0) {
        if (type == 1) {
            cout << "Коллизия. Невозможно вставить.\n";
            return;
        }
        else if (type == 2) {
            index = linealHash(key);
        }
        else if (type == 3) {
            if (Count() == m) {
                HashTable* temp = this;
                HashTable* h1 = new HashTable(this->m + 1);
                for (int i = 0; i < m; i++) {
                    h1->line[i].key = temp->line[i].key;
                    h1->line[i].data = temp->line[i].data;
                }
                *this = *h1;
            }
            index = squareHash(key);
        }
        else if (type == 4) {
            if (Count() == m) {
                HashTable* temp = this;
                HashTable* h1 = new HashTable(this->m + 1);
                for (int i = 0; i < m; i++) {
                    h1->line[i].key = temp->line[i].key;
                    h1->line[i].data = temp->line[i].data;
                }
                *this = *h1;
            }
            index = doubleHash(key);
        }
    }
    if (type == 2) {
        if (index >= m) {
            HashTable* temp = this;
            HashTable* h1 = new HashTable(this->m + 1);
            for (int i = 0; i < m; i++) {
                h1->line[i].key = temp->line[i].key;
                h1->line[i].data = temp->line[i].data;
            }
            *this = *h1;
            h1->line[temp->m - 1].key = key;
            h1->line[temp->m - 1].data = data;
            //delete temp;
        }
        else {
            line[index].key = key;
            line[index].data = data;
        }
        return;
    }
    line[index].key = key;
    line[index].data = data;
}

void HashTable::deleteItem(int key)
{
    int index = hashFunction(key);
    if (line[index].key == key) {
    line[index].key = 0;
    line[index].data = 0;
    }
    else {
        while (line[index].key != key) {
            index++;
            if (index >= m) {
                cout << "Такого элемента нет.\n";
                return;
            }
        }
        line[index].key = 0;
        line[index].data = 0;
    }
}

void HashTable::displayHash()
{
    cout << "Hash Table:\n";
    for (int i = 0; i < m; i++)
    {
        if (line[i].key == 0)
            continue;
        cout << "[" << i << "] -> " << line[i].key << " -> " << line[i].data << endl;
    }
}



class HashTableList {
public:
    int key;
    int data;
    HashTableList* next;

    HashTableList() {
        key = 0;
        data = 0;
        next = NULL;
    }
};






class HashTableChains
{
    int m;
    HashTableList* list;

public:
    HashTableChains(int c) {
        this->m = c;
        list = new HashTableList[m];
    }
    void insertItem(int key, int data) {
        if (Count() == m) {
            cout << "Таблица заполнена.\n";
            return;
        }
        int index = hashFunction(key);
        if (list[index].key != 0) {
            HashTableList* temp = &list[index];
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = new HashTableList;
            temp->next->key = key;
            temp->next->data = data;
            return;
        }
        list[index].key = key;
        list[index].data = data;
    }
    void deleteItem(int key) {
        int index = hashFunction(key);
        if (list[index].key == 0)
            return;
        if (list[index].next == NULL) {
            list[index].key = 0;
            list[index].data = 0;
            return;
        }
        if (list[index].key != key) {
            HashTableList* temp = list[index].next;
            while (temp->next != NULL) {
                if (temp->key == key) {
                    temp->key = temp->next->key;
                    temp->data = temp->next->data;
                }
                temp = temp->next; //последний
            }
            HashTableList* temp1 = &list[index];
            while (temp1->next->next != NULL) {
                temp1 = temp1->next;
            }
            temp1->next = NULL;
            delete temp;
            return;
        }


        HashTableList* temp = &list[index];
        list[index].key = temp->next->key;
        list[index].data = temp->next->data;

        while (temp->next->next != NULL) {
            temp->key = temp->next->key;
            temp->data = temp->next->data;
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;


    }

    ~HashTableChains() {
        delete[] list;
    }

    int Count() {
        int k = 0;
        for (int i = 0; i < m; i++)
            if (list[i].key != 0)
                k++;
        return k;
    }

    int findItem(int key) {
        int index = hashFunction(key);
        if (list[index].key == 0) {
            cout << "Такого значения нет.\n";
            return -1;
        }
        if (list[index].key == key) {
            cout << "Line:\n";
            cout << "[" << index << "] -> " << list[index].key << " -> " << list[index].data << endl;
            return index;
        }
        cout << "Line:\n";
        HashTableList* temp = &list[index];
        while (temp->next != NULL) {
            if (temp->key == key) {
                cout << "[" << index << "] -> " << temp->key << " -> " << temp->data << endl;
                return index;
            }
            temp = temp->next;
        }
        if (temp->key != key) {
            cout << "Такого значения нет.\n";
            return -1;
        }
        cout << "[" << index << "] -> " << temp->key << " -> " << temp->data << endl;
    }



    int hashFunction(int key)
    {
        return (key % 9);
    }
    void displayHash() {
        cout << "Hash Table:\n";
        HashTableList* temp;
        for (int i = 0; i < m; i++)
        {
            if (list[i].key == 0)
                continue;
            cout << "[" << i << "] -> " << list[i].key << " -> " << list[i].data;
            if (list[i].next == NULL) {
                cout << endl;
                continue;
            }
            temp = list[i].next;
            while (temp != NULL) {
                cout << " -> " << temp->key << " -> " << temp->data;
                temp = temp->next;
            }
            cout << endl;

            
        }
    }
};

void Menu1(HashTable*);
void Menu2(HashTableChains*);
void Menu3(HashTable*);


void Menu() {
    system("cls");
    int ch;
    cout << "1 - Задание 1\n";
    cout << "2 - Задание 2\n";
    cout << "3 - Задание 3\n";
    cout << "4 - Выход\n";
    cin >> ch;
    if (ch == 1) {
        system("cls");
        type = 1;
        HashTable* h = new HashTable(20);
        cout << "Создаем таблицу на 20 записей\n";
        cout << "Добавляем значения с ключами: 36, 37, 38, 39, 40\n";
        h->insertItem(36, 1);
        h->insertItem(37, 2);
        h->insertItem(38, 3);
        h->insertItem(39, 4);
        h->insertItem(40, 5);
        Menu1(h);
        delete h;
    }
    else if (ch == 2) {
        system("cls");
        HashTableChains* h = new HashTableChains(9);
        cout << "Создаем таблицу на 9 записей\n";
        cout << "Добавляем значения с ключами: 56, 18, 55, 9, 50, 1, 10, 88, 27\n";
        h->insertItem(56, 1);
        h->insertItem(18, 2);
        h->insertItem(55, 3);
        h->insertItem(9, 4);
        h->insertItem(50, 5);
        h->insertItem(1, 6);
        h->insertItem(10, 7);
        h->insertItem(88, 8);
        h->insertItem(27, 9);

        Menu2(h);
        delete h;
    }
    else if (ch == 3) {
        system("cls");
        int t;
        cout << "1 - Линейное хеширование\n";
        cout << "2 - Квадратичное хеширование\n";
        cout << "3 - Двойное хеширование\n";
        cin >> t;
        type = t + 1;
        HashTable* h = new HashTable(11);
        cout << "Создаем таблицу на 11 записей\n";
        cout << "Добавляем значения с ключами: 56, 18, 55, 9, 50, 1, 10, 88, 27\n";
        h->insertItem(56, 1);
        h->insertItem(18, 2);
        h->insertItem(55, 3);
        h->insertItem(9, 4);
        h->insertItem(50, 5);
        h->insertItem(1, 6);
        h->insertItem(10, 7);
        h->insertItem(88, 8);
        h->insertItem(27, 9);

        Menu3(h);
        delete h;
    }
    else if (ch == 4) {
        return;
    }


    system("pause");
    Menu();
}

void Menu1(HashTable* h) {
    h->displayHash();
    cout << "\n\n";
    int ch;
    cout << "1 - Добавить элемент\n";
    cout << "2 - Удалить элемент\n";
    cout << "3 - Найти элемент\n";
    cout << "4 - Выход\n";
    cin >> ch;
    if (ch == 1) {
        int key, data;
        cout << "Ключ: ";
        cin >> key;
        cout << "Значение: ";
        cin >> data;
        h->insertItem(key, data);
    }
    else if (ch == 2) {
        int key;
        cout << "Ключ: ";
        cin >> key;
        h->deleteItem(key);
    }
    else if (ch == 3) {
        int key;
        cout << "Ключ: ";
        cin >> key;
        h->findItem(key);
    }
    else if (ch == 4) {
        return;
    }

    system("pause");
    Menu1(h);
}


void Menu2(HashTableChains* h) {
    h->displayHash();
    cout << "\n\n";
    int ch;
    cout << "1 - Добавить элемент\n";
    cout << "2 - Удалить элемент\n";
    cout << "3 - Найти элемент\n";
    cout << "4 - Выход\n";
    cin >> ch;
    if (ch == 1) {
        int key, data;
        cout << "Ключ: ";
        cin >> key;
        cout << "Значение: ";
        cin >> data;
        h->insertItem(key, data);
    }
    else if (ch == 2) {
        int key;
        cout << "Ключ: ";
        cin >> key;
        h->deleteItem(key);
    }
    else if (ch == 3) {
        int key;
        cout << "Ключ: ";
        cin >> key;
        h->findItem(key);
    }
    else if (ch == 4) {
        return;
    }

    system("pause");
    Menu2(h);

}


void Menu3(HashTable* h) {


    h->displayHash();
    cout << "\n\n";
    int ch;
    cout << "1 - Добавить элемент\n";
    cout << "2 - Удалить элемент\n";
    cout << "3 - Найти элемент\n";
    cout << "4 - Выход\n";
    cin >> ch;
    if (ch == 1) {
        int key, data;
        cout << "Ключ: ";
        cin >> key;
        cout << "Значение: ";
        cin >> data;
        h->insertItem(key, data);
    }
    else if (ch == 2) {
        int key;
        cout << "Ключ: ";
        cin >> key;
        h->deleteItem(key);
    }
    else if (ch == 3) {
        int key;
        cout << "Ключ: ";
        cin >> key;
        h->findItem(key);
    }
    else if (ch == 4) {
        return;
    }

    system("pause");
    Menu3(h);

}


