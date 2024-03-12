#include <windows.h>
#include "menu.h"

int i = 0, isave = 0;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);
    while(1) {
        menu();
    }
}