#include "input.h"

void input() {
    system("cls");
    string name, components, cost, calories;
    cout << "Введите название еды:" << endl; cin >> ws; getline(cin, name);
    system("cls");
    cout << "Введите компоненты еды:" << endl; cin >> ws; getline(cin, components);
    system("cls");
    do {
        cout << "Введите стоимость еды:" << endl; cin >> ws; getline(cin, cost);
        for (int r = 0; r < cost.size(); r++) {//проверка на цифру
            if (((int) cost[r] < 48) or (((int) cost[r] > 57))) {
                system("cls");
                cout << "Неверные данные в cost\n";
                cost.clear();
            }
        }
    }while(cost.empty());
    system("cls");
    do {
        cout << "Введите калории еды:" << endl; cin >> ws; getline(cin, calories);
        for (int r = 0; r < calories.size(); r++) {//проверка на цифру
            if (((int) calories[r] < 48) or (((int) calories[r] > 57))) {
                system("cls");
                cout << "Неверные данные в calories\n";
                calories.clear();
            }
        }
    }while(calories.empty());
    system("cls");

    auto zone = new japanise[i];//создание буферного массива
    for (int j = 0; j < i; ++j) {//передача данных в буферный массив
        zone[j] = japan[j];
    }
    japan = new japanise[i + 1];//память для основного массива
    for (int j = 0; j < i; ++j) {//передача данных в основной массив
        japan[j] = zone[j];
    }
    japan[i].name = name;
    japan[i].components = components;
    japan[i].cost = cost;
    japan[i].calories = calories;
    i++;
    system("cls");
}