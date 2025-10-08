#include <iostream>
#include <windows.h>
#include "function_Baranov.h"
#include "soldier_Baranov.h"
#include "squad_Baranov.h"
#include "commander_Baranov.h"

using namespace std;

int main()
{
    locale::global(locale("rus_rus.866"));
    wcout.imbue(locale());
    wcin.imbue(locale());

    Squad squad;

    while (true) {
        wcout << L"--- Меню ---\n";
        wcout << L"1. Добавить бойца\n";
        wcout << L"2. Показать взвод\n";
        wcout << L"3. Считать из файла\n";
        wcout << L"4. Записать в файл\n";
        wcout << L"5. Очистить список\n";
        wcout << L"0. Выход\n";
        wcout << L"Выберите пункт: ";

        int choice = readNumber<int>(0, 5);

        switch (choice) {
        case 0:
            wcout << L"Выход из программы." << endl;
            return 0;
        case 1:
            squad.input();
            break;
        case 2:
            squad.showAll();
            break;
        case 3:
            loadSquad(squad);
            break;
        case 4:
            saveSquad(squad);
            break;
        case 5:
            squad.clear();
            wcout << L"Список очищен!" << endl;
            break;
        }
    }
}
