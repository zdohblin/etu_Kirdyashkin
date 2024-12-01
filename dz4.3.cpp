#include "functions.h"
#include <iostream>
#include <fstream>
#include <locale>
#include <codecvt>
#include <chrono>
#include <iomanip>

void readArcanaInfo(const std::wstring& filename, int arcanaNumber) {
    std::wifstream file(filename);
    file.imbue(std::locale("ru_RU.UTF-8"));

    if (!file) {
        std::wcerr << L"Ошибка: Не удалось открыть файл " << filename << std::endl;
        return;
    }

    std::wstring line;
    int currentLine = 1;
    while (std::getline(file, line)) {
        if (currentLine == arcanaNumber) {
            std::wcout << L"Описание аркана #" << arcanaNumber << L": " << line << std::endl;
            return;
        }
        ++currentLine;
    }
    std::wcerr << L"Аркан с номером " << arcanaNumber << L" не найден." << std::endl;
}

void logDate(const std::wstring& filename, const std::wstring& date) {
    std::wofstream file(filename, std::ios::app);
    file.imbue(std::locale("ru_RU.UTF-8"));

    if (!file) {
        std::wcerr << L"Ошибка: Не удалось открыть файл " << filename << std::endl;
        return;
    }

    file << date << std::endl;
    std::wcout << L"Дата " << date << L" записана в лог." << std::endl;
}

void displayLog(const std::wstring& filename) {
    std::wifstream file(filename);
    file.imbue(std::locale("ru_RU.UTF-8"));

    if (!file) {
        std::wcerr << L"Ошибка: Не удалось открыть файл " << filename << std::endl;
        return;
    }

    std::wcout << L"Содержимое лога:" << std::endl;
    std::wstring line;
    while (std::getline(file, line)) {
        std::wcout << line << std::endl;
    }
}

void showMenu(const std::wstring& infoFile, const std::wstring& logFile) {
    while (true) {
        std::wcout << L"\nМеню:\n";
        std::wcout << L"1. Ввести номер аркана\n";
        std::wcout << L"2. Ввести дату\n";
        std::wcout << L"3. Вывести лог\n";
        std::wcout << L"4. Выход\n";
        std::wcout << L"Выберите пункт: ";
        int choice;
        std::wcin >> choice;

        auto start = std::chrono::high_resolution_clock::now();

        if (choice == 1) {
            int arcanaNumber;
            std::wcout << L"Введите номер аркана: ";
            std::wcin >> arcanaNumber;
            readArcanaInfo(infoFile, arcanaNumber);
        }
        else if (choice == 2) {
            std::wstring date;
            std::wcout << L"Введите дату (например, 2024-11-26): ";
            std::wcin >> date;
            logDate(logFile, date);
        }
        else if (choice == 3) {
            displayLog(logFile);
        }
        else if (choice == 4) {
            std::wcout << L"Выход из программы.\n";
            break;
        }
        else {
            std::wcout << L"Некорректный выбор. Попробуйте снова.\n";
        }

        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::wcout << L"Время выполнения действия: " << duration.count() << L" мс" << std::endl;
    }
}
