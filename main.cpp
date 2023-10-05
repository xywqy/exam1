#pragma region Библиотеки и предпроцессоры итд
#include <iostream>
#include <string>
#define co cout<<
#define ci cin>>
using namespace std;

Prod tovar[100];
int kol = 0;
#pragma endregion
#pragma region Структура и вторичные функции
struct Prod {
    string name;
    string dev;
    double price;
    string type;
    string data;
    string srok;
};

void Add() {
    int vib = 1;
    int a = 0;
    co "Введите имя, производителя, цену, тип продукта, дату, срок\n";
    while (vib == 1) {
        kol++;
        ci tovar[kol].name >> tovar[kol].dev >> tovar[kol].price >> tovar[kol].type >> tovar[kol].data >> tovar[kol].srok;
        co "Хотите продолжить вводить данные?\n[1]Да\n[2]Нет\nВаш выбор? ";
        ci vib;
        if (vib == 2) {
            co "Ваш список товаров:" << endl;
            while (a < kol) {
                co "Имя: " << tovar[a].name << endl;
                co "Производитель: " << tovar[a].dev << endl;
                co "Цена: " << tovar[a].price << endl;
                co "Тип продукта: " << tovar[a].type << endl;
                co "Дата: " << tovar[a].data << endl;
                co "Срок: " << tovar[a].srok << endl << endl;
                a++;
            }
        }
    }
}

void Del() {
    int num;
    co "Введите номер товара, который вы хотите удалить: ";
    ci num;
    if (num < 1 || num > kol) {
        co "Неизвестный товар" << endl;
    }
    for (int a = num; a < kol; a++) {
        tovar[a] = tovar[a + 1];
    }
    kol--;
    co "Товар успешно удален" << endl;
}

void Rep() {
    int num;
    co "Введите номер товара, который вы хотите заменить: ";
    ci num;
    if (num < 1 || num > kol) {
        co "Неизвестный товар" << endl;
        return;
    }

    co "Введите новую информацию о товаре: ";
    ci tovar[num].name >> tovar[num].dev >> tovar[num].price >> tovar[num].type >> tovar[num].data >> tovar[num].srok;

    co "Товар успешно заменен" << endl;
}

void Fin() {
    string findname;
    co "Введите имя товара для поиска: ";
    ci findname;
    bool found = false;
    for (int a = 1; a <= kol; a++) {
        if (tovar[a].name == findname) {
            co "Информация о товаре:" << endl;
            co "Имя: " << tovar[a].name << endl;
            co "Производитель: " << tovar[a].dev << endl;
            co "Цена: " << tovar[a].price << endl;
            co "Тип продукта: " << tovar[a].type << endl;
            co "Дата: " << tovar[a].data << endl;
            co "Срок: " << tovar[a].srok << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        co "Товар не найден" << endl;
    }
}
#pragma endregion
#pragma region Главная функция
int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    do {
        co "\n\t\t\tГлавное меню\n\t\t[1]Добавление товара\n\t\t[2]Удаление товара\n\t\t[3]Замена товара\n\t\t[4]Поиск\n\t\t[5]Выход\nВаш выбор? ";
        ci choice;
        switch (choice) {
        case 1: {
            Add();
            break;
        }
        case 2: {
            Del();
            break;
        }
        case 3: {
            Rep();
            break;
        }
        case 4: {
            Fin();
            break;
        }
        case 5: {
            return 1;
        }
        }
    }
         while(choice != 5);
              return 0;
}
#pragma endregion