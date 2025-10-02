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
        wcout << L"\n--- Меню ---" << endl;
        wcout << L"1. Добавить солдата" << endl;
        wcout << L"2. Показать взвод (всех солдат)" << endl;
        wcout << L"3. Считать из файла" << endl;
        wcout << L"4. Записать в файл" << endl;
        wcout << L"5. Очистить список" << endl;
        wcout << L"0. Выход" << endl;
        wcout << L"Выберите пункт: ";

        int choice = readNumber<int>(0, 5);

        switch (choice) {
        case 0:
            wcout << L"Выход из программы." << endl;
            return 0;
        case 1:
            squad.addSoldier();
            wcout << L"Солдат добавлен!" << endl;
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
