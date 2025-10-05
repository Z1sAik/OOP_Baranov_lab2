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
        wcout << L"1. Добавить солдата\n";
        wcout << L"2. Добавить командира\n";
        wcout << L"3. Показать взвод\n";
        wcout << L"4. Считать из файла\n";
        wcout << L"5. Записать в файл\n";
        wcout << L"6. Очистить список\n";
        wcout << L"0. Выход\n";
        wcout << L"Выберите пункт: ";

        int choice = readNumber<int>(0, 6);

        switch (choice) {
        case 0:
            wcout << L"Выход из программы." << endl;
            return 0;
        case 1:
            squad.addSoldierOnly();
            break;
        case 2:
            squad.addCommanderOnly();
            break;
        case 3:
            squad.showAll();
            break;
        case 4:
            loadSquad(squad);
            break;
        case 5:
            saveSquad(squad);
            break;
        case 6:
            squad.clear();
            wcout << L"Список очищен!" << endl;
            break;
        }
    }
}
