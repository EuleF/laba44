#include "file.h"

string namefile;

void new_DB() {
    system("cls");

    cout << "Нажмите 1 чтобы создать файл.\n";
    cout << "Нажмите 2 чтобы создать умный файл.\n";

    string s;
    cin >> ws; getline(cin, s);
    system("cls");

    int len = 0;
    for (int j = 0; j < s.size(); j++)
        len += ((s[j] & 0xc0) != 0x80);

    if (len > 1) {
        system("cls");
        cout << "#####Неверная команда#####\n\n";
        return;
    }
    if (s[0] == '1') {
        ofstream fl;
        cout << "Введите название файла: ";
        cin >> ws;
        getline(cin, namefile);
        fl.open(namefile + ".txt", ios_base::in);
        system("cls");
        if (!fl.is_open()) {// если файл не открыт
            fl.open(namefile + ".txt");
            cout << "#####Файл  создан#####\n";
        } else cout << "#####Файл не может быть создан!#####\n";
        fl.close();
    }
    else if (s[0] == '2'){
        ofstream fl;
        fl.open("topsave.txt", ios_base::in);
        system("cls");
        if (!fl.is_open()) {// если файл не открыт
            fl.open("topsave.txt");
            cout << "#####Файл создан#####\n";
        } else cout << "#####Файл не может быть создан!#####\n";
        fl.close();
    }
}

void remove_DB() {
    system("cls");

    cout << "Нажмите 1 чтобы удалить файл.\n";
    cout << "Нажмите 2 чтобы удалить умный файл.\n";

    string s;
    cin >> ws; getline(cin, s);
    system("cls");

    int len = 0;
    for (int j = 0; j < s.size(); j++)
        len += ((s[j] & 0xc0) != 0x80);

    if (len > 1) {
        system("cls");
        cout << "#####Неверная команда#####\n\n";
        return;
    }
    if (s[0] == '1') {
        string remnamefile;
        cout << "Введите название файла на удаление: ";
        cin >> ws; getline(cin, remnamefile);
        system("cls");
        if (filesystem::remove(remnamefile + ".txt"))
            cout << "#####Файл удалён#####\n";
        else
            cout << "#####Файл не найден#####\n";
    }
    else if (s[0] == '2'){
        system("cls");
        if (filesystem::remove("topsave.txt"))
            cout << "#####Файл удалён#####\n";
        else
            cout << "#####Файл не найден#####\n";
    }
}

void clear() {
    system("cls");
    delete[] japan;
    i = 0;
    isave = 0;
    cout << "#####Массив очищен#####\n";
}

void save_DB() {
    system("cls");

    cout << "Нажмите 1 чтобы сохранить массив полностью.\n";
    cout << "Нажмите 2 чтобы сохранить массив(умное сохранение).\n";

    string s;
    cin >> ws; getline(cin, s);
    system("cls");

    int len = 0;
    for (int j = 0; j < s.size(); j++)
        len += ((s[j] & 0xc0) != 0x80);

    if (len > 1) {
        system("cls");
        cout << "#####Неверная команда#####\n\n";
        return;
    }
    if (s[0] == '1'){
        fstream fl;
        cout << "Введите название файла: ";
        cin >> ws; getline(cin, namefile);
        fl.open(namefile + ".txt", ios_base::in);
        system("cls");
        if (!fl.is_open()) {// если файл не открыт
            cout << "#####Файл не найден#####\n";
            return;
        }
        fl.close();
        fl.open(namefile + ".txt", ios_base::app);
        for (int j = 0; j < i; j++) {
            fl << japan[j].name << endl;
            fl << japan[j].components << endl;
            fl << japan[j].cost << endl;
            fl << japan[j].calories << endl;
        }
        fl.close();
        cout << "#####Данные сохранены#####\n";
    }
    else if (s[0] == '2'){
        fstream fl;
        fl.open("topsave.txt", ios_base::in);
        system("cls");
        if (!fl.is_open()) {// если файл не открыт
            cout << "#####Файл не найден#####\n";
            return;
        }
        fl.close();
        fl.open("topsave.txt", ios_base::app);
        for (; isave < i; isave++) {
            fl << japan[isave].name << endl;
            fl << japan[isave].components << endl;
            fl << japan[isave].cost << endl;
            fl << japan[isave].calories << endl;
        }
        fl.close();
        cout << "#####Данные сохранены#####\n";
    }
}


void load_DB() {
    system("cls");

    cout << "Нажмите 1 чтобы загрузить массив из файла..\n";
    cout << "Нажмите 2 чтобы загрузить массив из умного файла.\n";

    string s;
    cin >> ws; getline(cin, s);
    system("cls");

    int len = 0;
    for (int j = 0; j < s.size(); j++)
        len += ((s[j] & 0xc0) != 0x80);

    if (len > 1) {
        system("cls");
        cout << "#####Неверная команда#####\n\n";
        return;
    }

    if (s[0] == '1') {
        fstream fl;
        string line;
        i = 0;
        cout << "Введите название файла: ";
        cin >> ws;
        getline(cin, namefile);
        system("cls");
        fl.open(namefile + ".txt", ios_base::in);
        if (!fl.is_open()) {// если файл не открыт
            cout << "#####Файл не найден#####\n";
            return;
        }

        while (getline(fl, line)) i++;//i - количество строк в файле
        i = i / 4;//количество структур

        japan = new japanise[i];

        fl.close();
        fl.open(namefile + ".txt", ios_base::in);
        for (int j = 0; j < i; j++) {
            getline(fl, japan[j].name);
            getline(fl, japan[j].components);
            getline(fl, japan[j].cost);
            getline(fl, japan[j].calories);
        }
        fl.close();
        cout << "#####Данные загружены#####\n";
    }
    else if (s[0] == '2'){
        fstream fl;
        string line;
        i = 0;
        system("cls");
        fl.open("topsave.txt", ios_base::in);
        if (!fl.is_open()) {// если файл не открыт
            cout << "#####Файл не найден#####\n";
            return;
        }

        while (getline(fl, line)) i++;//i - количество строк в файле
        i = i / 4;//количество структур

        japan = new japanise[i];

        fl.close();
        fl.open("topsave.txt", ios_base::in);
        for (int j = 0; j < i; j++) {
            getline(fl, japan[j].name);
            getline(fl, japan[j].components);
            getline(fl, japan[j].cost);
            getline(fl, japan[j].calories);
        }
        fl.close();
        cout << "#####Данные загружены#####\n";
    }
}