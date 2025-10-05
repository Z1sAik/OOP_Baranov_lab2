#include "function_Baranov.h"
#include <boost/archive/text_woarchive.hpp>
#include <boost/archive/text_wiarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/shared_ptr.hpp>
#include <fstream>
#include <locale>
#include <codecvt>
#include "soldier_Baranov.h"
#include "commander_Baranov.h"
#include <boost/serialization/export.hpp>

BOOST_CLASS_EXPORT(Soldier)
BOOST_CLASS_EXPORT(Commander)

static std::string wstring_to_utf8(const std::wstring& wstr) {
    std::wstring_convert<std::codecvt_utf8<wchar_t>> conv;
    return conv.to_bytes(wstr);
}

void saveSquad(const Squad& squad) {
    std::wcout << L"Введите имя файла для сохранения (без расширения): ";
    std::wstring filename_w;
    std::getline(std::wcin >> std::ws, filename_w);
    if (filename_w.empty()) return;

    std::string filename = wstring_to_utf8(filename_w) + ".txt";
    std::wofstream ofs(filename);
    if (!ofs.is_open()) {
        std::wcout << L"Не удалось открыть файл для записи: " << filename_w << L"\n";
        return;
    }

    try {
        boost::archive::text_woarchive oa(ofs);
        oa << squad.getSoldiers();
        std::wcout << L"Сохранение выполнено: " << filename_w << L".txt\n";
    }
    catch (const boost::archive::archive_exception& ex) {
        std::wcout << L"Ошибка архивирования при сохранении: " << ex.what() << L"\n";
    }
}

void loadSquad(Squad& squad) {
    std::wcout << L"Введите имя файла для загрузки (без расширения): ";
    std::wstring filename_w;
    std::getline(std::wcin >> std::ws, filename_w);
    if (filename_w.empty()) return;

    std::string filename = wstring_to_utf8(filename_w) + ".txt";
    std::wifstream ifs(filename);
    if (!ifs.is_open()) {
        std::wcout << L"Не удалось открыть файл для чтения: " << filename_w << L"\n";
        return;
    }

    try {
        squad.getSoldiers().clear();
        boost::archive::text_wiarchive ia(ifs);
        ia >> squad.getSoldiers();
        squad.updateNextIDAfterLoad();
        std::wcout << L"Загрузка выполнена: " << filename_w << L".txt\n";
    }
    catch (const boost::archive::archive_exception& ex) {
        std::wcout << L"Ошибка архивирования при загрузке: " << ex.what() << L"\n";
    }
}
