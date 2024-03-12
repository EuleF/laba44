#include "output.h"

void output() {
    system("cls");
    for (int j = 0; j < i; ++j) {
        cout << "Имя: " << japan[j].name << endl;
        cout << "Компоненты: " << japan[j].components << endl;
        cout << "Стоимость: " << japan[j].cost << endl;
        cout << "Калории: " << japan[j].calories << "\n\n";
        system("pause");
        system("cls");
    }
}

void outputtablet() {
    system("cls");
    int maxname = 4, maxcomponents = 10, maxcost = 4, maxcalories = 8; //максимальные длины строк
    int len = 0;
    for (int t = 0; t < i; t++) {
        for (int j = 0; j < japan[t].name.size(); j++)//максимальная длина строки name
            len += ((japan[t].name[j] & 0xc0) != 0x80);
        if (len > maxname)
            maxname = len;
        len = 0;

        for (int j = 0; j < japan[t].components.size(); j++)//максимальная длина строки components
            len += ((japan[t].components[j] & 0xc0) != 0x80);
        if (len > maxcomponents)
            maxcomponents = len;
        len = 0;

        if (japan[t].cost.size() > maxcost) //максимальная длина строки cost
            maxcost = japan[t].cost.size();

        if (japan[t].calories.size() > maxcalories) //максимальная длина строки calories
            maxcalories = japan[t].calories.size();
    }
    cout << '#' << setw(maxname + maxcomponents + maxcost + maxcalories + 4) << setfill('=') << '#' << "\n" << setfill(' ');//верхняя граница таблицы
    cout << '#' << setw(maxname) << "Name" << '|' << setw(maxcomponents) << "Components" << '|' << setw(maxcost) << "Cost" << '|' << setw(maxcalories) << "Calories" << '#' << endl;//шапка таблицы
    cout << '#' << setw(maxname + maxcomponents + maxcost + maxcalories + 4) << setfill('=') << '#' << "\n" << setfill(' ');//нижняя граница шапки
    for (int j = 0; j < i; ++j) {
        cout << '#' << setw(maxname) << japan[j].name << '|' << setw(maxcomponents) << japan[j].components << '|' << setw(maxcost) << japan[j].cost << '|' << setw(maxcalories) << japan[j].calories << '#' << endl;//вывод переменных по максимальной длине
        cout << '#' << setw(maxname + maxcomponents + maxcost + maxcalories + 4) << setfill('=') << '#' << "\n" << setfill(' ');//разделитель строк/нижняя граница таблицы
    }
    system("pause");
    system("cls");
}