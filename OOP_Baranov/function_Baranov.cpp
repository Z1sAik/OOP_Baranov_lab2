#include "function_Baranov.h"
#include "squad_Baranov.h"
#include "soldier_Baranov.h"
#include "commander_Baranov.h"
#include "exports_Baranov.h"
#include <boost/archive/text_woarchive.hpp>
#include <boost/archive/text_wiarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/export.hpp>
#include <fstream>
#include <locale>

using namespace std;

void saveSquad(const Squad& squad) {
    wcout << L"Введите имя файла для сохранения (без расширения): ";
    wstring filename_w;
    getline(wcin >> ws, filename_w);
    if (filename_w.empty()) return;

    wstring file_full = filename_w + L".txt";
    wofstream ofs(file_full.c_str());
    if (!ofs) {
        wcout << L"Не удалось открыть файл для записи: " << file_full << endl;
        return;
    }

    boost::archive::text_woarchive oa(ofs);
    oa << squad.getSoldiers();

    wcout << L"Сохранение выполнено: " << file_full << endl;
}

void loadSquad(Squad& squad) {
    wcout << L"Введите имя файла для загрузки (без расширения): ";
    wstring filename_w;
    getline(wcin >> ws, filename_w);
    if (filename_w.empty()) return;

    wstring file_full = filename_w + L".txt";
    wifstream ifs(file_full.c_str());
    if (!ifs) {
        wcout << L"Не удалось открыть файл для чтения: " << file_full << endl;
        return;
    }

    squad.getSoldiers().clear();

    boost::archive::text_wiarchive ia(ifs);
    ia >> squad.getSoldiers();

    squad.updateNextIDAfterLoad();

    wcout << L"Загрузка выполнена: " << file_full << endl;
}
