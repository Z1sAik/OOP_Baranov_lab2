#include "function_Baranov.h"
#include "squad_Baranov.h"
#include "soldier_Baranov.h"
#include "commander_Baranov.h"
#include <boost/archive/text_woarchive.hpp>
#include <boost/archive/text_wiarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <boost/serialization/export.hpp>
#include <fstream>
#include <locale>

using namespace std;

BOOST_CLASS_EXPORT(Soldier)
BOOST_CLASS_EXPORT(Commander)

void saveSquad(const Squad& squad) {
    wcout << L"Введите имя файла для сохранения (без расширения): ";
    wstring filename_w;
    getline(wcin >> ws, filename_w);
    if (filename_w.empty()) return;

    wstring file_full = filename_w + L".txt";
    wofstream ofs(file_full.c_str());
    boost::archive::text_woarchive(ofs) << squad.getSoldiers();
    wcout << L"Сохранение выполнено: " << filename_w << L".txt\n";
}

void loadSquad(Squad& squad) {
    wcout << L"Введите имя файла для загрузки (без расширения): ";
    wstring filename_w;
    getline(wcin >> ws, filename_w);
    if (filename_w.empty()) return;

    wstring file_full = filename_w + L".txt";
    wifstream ifs(file_full.c_str());
    squad.getSoldiers().clear();
    boost::archive::text_wiarchive(ifs) >> squad.getSoldiers();
    squad.updateNextIDAfterLoad();
    wcout << L"Загрузка выполнена: " << filename_w << L".txt\n";
}
