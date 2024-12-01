#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>


// функция для изменения цвета текста, фона текста и фона консоли
; void set_colors(int textColor, int bgColor, int consoleBgColor) {
    // цвет фона консоли
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BACKGROUND_BLUE);
    system("cls"); // очищаем консольный экран с новым фоном

    // сет цвет текста и фона текста
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | (BACKGROUND_BLUE << 4));
}

// функция для проверки корректности ввода даты
int is_valid_date(char* date) {
    int day, month, year;
    return sscanf_s(date, "%d.%d.%d", &day, &month, &year) == 3 && day >= 1 && day <= 31 && month >= 1 && month <= 12 && year > 0;
}

// функция для вычисления старшего аркана по дате рождения
int get_major_arcana(int day, int month, int year) {
    // суммируем цифры ddmmyyyy
    int sum = 0;
    while (day > 0) {
        sum += day % 10;
        day /= 10;
    }
    while (month > 0) {
        sum += month % 10;
        month /= 10;
    }
    while (year > 0) {
        sum += year % 10;
        year /= 10;
    }

    // приводим сумму к диапазону от 1 до 22 (старшие арканы)
    while (sum > 22) {
        sum -= 22;
    }

    return sum == 0 ? 22 : sum;  // если ноль — это 22-й аркан
}

int main() {
    char date[11];
    int day, month, year;

    // установка цветов цветов: текст зеленый, фон текста черный, фон консоли синий
    set_colors(15, 0, 1);

    // запрос даты рождения
    printf("day mne datu rozhdeniya v formate DD.MM.YYYY: ");
    fgets(date, sizeof(date), stdin); // fgets вместо scanf во избежании проблем с буфером

    // убираем символ новой строки, если он есть
    date[strcspn(date, "\n")] = 0;

    // проверка ввода на корректную дату
    if (is_valid_date(date)) {
        // извлеч ddmmyyyy из даты
        sscanf_s(date, "%d.%d.%d", &day, &month, &year);

        // вычисл старш аркана
        int arcana = get_major_arcana(day, month, year);

        //// сет текста (зеленый)
        //set_colors(10, 0, 1);\
        
        // Вывод реза
        printf("vasha data rozhdeniya: %s\n", date);
        printf("nomer starshego arcana: %d\n", arcana);
    }
    else {
        // Некорректна дата - ошибка
        set_colors(12, 0, 1);
        printf("neverni vvod dannih\n");
    }

    return 0;
}