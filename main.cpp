#pragma region ���������� � �������������� ���
#include <iostream>
#include <string>
#define co cout<<
#define ci cin>>
using namespace std;

Prod tovar[100];
int kol = 0;
#pragma endregion
#pragma region ��������� � ��������� �������
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
    co "������� ���, �������������, ����, ��� ��������, ����, ����\n";
    while (vib == 1) {
        kol++;
        ci tovar[kol].name >> tovar[kol].dev >> tovar[kol].price >> tovar[kol].type >> tovar[kol].data >> tovar[kol].srok;
        co "������ ���������� ������� ������?\n[1]��\n[2]���\n��� �����? ";
        ci vib;
        if (vib == 2) {
            co "��� ������ �������:" << endl;
            while (a < kol) {
                co "���: " << tovar[a].name << endl;
                co "�������������: " << tovar[a].dev << endl;
                co "����: " << tovar[a].price << endl;
                co "��� ��������: " << tovar[a].type << endl;
                co "����: " << tovar[a].data << endl;
                co "����: " << tovar[a].srok << endl << endl;
                a++;
            }
        }
    }
}

void Del() {
    int num;
    co "������� ����� ������, ������� �� ������ �������: ";
    ci num;
    if (num < 1 || num > kol) {
        co "����������� �����" << endl;
    }
    for (int a = num; a < kol; a++) {
        tovar[a] = tovar[a + 1];
    }
    kol--;
    co "����� ������� ������" << endl;
}

void Rep() {
    int num;
    co "������� ����� ������, ������� �� ������ ��������: ";
    ci num;
    if (num < 1 || num > kol) {
        co "����������� �����" << endl;
        return;
    }

    co "������� ����� ���������� � ������: ";
    ci tovar[num].name >> tovar[num].dev >> tovar[num].price >> tovar[num].type >> tovar[num].data >> tovar[num].srok;

    co "����� ������� �������" << endl;
}

void Fin() {
    string findname;
    co "������� ��� ������ ��� ������: ";
    ci findname;
    bool found = false;
    for (int a = 1; a <= kol; a++) {
        if (tovar[a].name == findname) {
            co "���������� � ������:" << endl;
            co "���: " << tovar[a].name << endl;
            co "�������������: " << tovar[a].dev << endl;
            co "����: " << tovar[a].price << endl;
            co "��� ��������: " << tovar[a].type << endl;
            co "����: " << tovar[a].data << endl;
            co "����: " << tovar[a].srok << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        co "����� �� ������" << endl;
    }
}
#pragma endregion
#pragma region ������� �������
int main() {
    setlocale(LC_ALL, "Rus");
    int choice;
    do {
        co "\n\t\t\t������� ����\n\t\t[1]���������� ������\n\t\t[2]�������� ������\n\t\t[3]������ ������\n\t\t[4]�����\n\t\t[5]�����\n��� �����? ";
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