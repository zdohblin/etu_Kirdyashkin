#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

// Чтение строки из файла по номеру
void readArcanaInfo(const std::wstring& filename, int arcanaNumber);

// Запись даты в лог
void logDate(const std::wstring& filename, const std::wstring& date);

// Вывод содержимого лога
void displayLog(const std::wstring& filename);

// Меню программы
void showMenu(const std::wstring& infoFile, const std::wstring& logFile);

#endif // FUNCTIONS_H
