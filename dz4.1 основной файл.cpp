#include <iostream>
#include <locale>
#include "functions.h"

int main() {
    // Устанавливаем локаль для работы с кириллицей
    std::locale::global(std::locale("ru_RU.UTF-8"));
    std::wcin.imbue(std::locale("ru_RU.UTF-8"));
    std::wcout.imbue(std::locale("ru_RU.UTF-8"));

    const std::wstring infoFile = L"info.txt";
    const std::wstring logFile = L"log.txt";

    showMenu(infoFile, logFile);

    return 0;
}
