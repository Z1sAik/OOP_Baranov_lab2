#include <iostream>
#include <windows.h>
#include "function_Baranov.h"
#include "soldier_Baranov.h"
#include "squad_Baranov.h"
#include "commander_Baranov.h"

using namespace std;

int main()
{
    locale::global(std::locale("rus_rus.866"));
    wcout.imbue(locale());
    wcin.imbue(locale());

    Squad squad;

    while (true) {
        std::wcout << L"--- Меню ---\n";
        std::wcout << L"1. Добавить объект (солдат/командир)\n";
        std::wcout << L"2. Показать взвод\n";
        std::wcout << L"3. Считать из файла\n";
        std::wcout << L"4. Записать в файл\n";
        std::wcout << L"5. Очистить список\n";
        std::wcout << L"0. Выход\n";
        std::wcout << L"Выберите пункт: ";

        int choice = readNumber<int>(0, 5);

        switch (choice) {
        case 0:
            std::wcout << L"Выход из программы." << std::endl;
            return 0;
        case 1:
            squad.addSoldier();
            break;
        case 2:
            squad.showAll();
            break;
        case 3: {
            loadSquad(squad);
            break;
        }
        case 4: {
            saveSquad(squad);
            break;
        }
        case 5:
            squad.clear();
            std::wcout << L"Список очищен!" << std::endl;
            break;
        }
    }
}