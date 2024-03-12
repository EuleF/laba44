#include "menu.h"
void menu() {
    cout << "Нажмите 0 для выхода." << endl;
    cout << "Нажмите 1 для ввода данных." << endl;
    cout << "Нажмите 2 для вывода данных." << endl;
    cout << "Нажмите 3 для вывода данных в виде таблицы.\n\n";

    cout << "Нажмите 4 для создания файла." << endl;
    cout << "Нажмите 5 для удаления файла." << endl;
    cout << "Нажмите 6 для очищения массива." << endl;
    cout << "Нажмите 7 для сохранения данных в файл." << endl;
    cout << "Нажмите 8 для загрузки данных из файла в массив." << endl;

    string s;
    cin >> ws; getline(cin, s);

    int len = 0;
    for (int j = 0; j < s.size(); j++)
        len += ((s[j] & 0xc0) != 0x80);

    if (len > 1) {
        system("cls");
        cout << "#####Неверная команда#####\n\n";
        return;
    }
    switch (s[0]) {
        case('0'): exit(0);
        case('1'): input(); break;
        case('2'): output(); break;
        case('3'): outputtablet(); break;
        case('4'): new_DB(); break;
        case('5'): remove_DB(); break;
        case('6'): clear(); break;
        case('7'): save_DB(); break;
        case('8'): load_DB(); break;
        default: {system("cls"); cout << "#####Неверная команда#####\n\n";}
    }
}