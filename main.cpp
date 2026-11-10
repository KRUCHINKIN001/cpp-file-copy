#include <iostream>
#include <fstream>
#include <string>
#include <clocale>

using namespace std;

// Docstring: Копирует содержимое исходного файла в целевой файл построчно.
bool copyFile(const string& sourcePath, const string& destPath) {
    // Открываем исходный файл для чтения
    ifstream sourceFile(sourcePath);

    // Проверяем, удалось ли открыть файл для чтения
    if (!sourceFile.is_open()) {
        cout << "Ошибка: не удалось открыть исходный файл '" << sourcePath << "' для чтения." << endl;
        return false;
    }

    // Открываем целевой файл для записи (создается заново или перезаписывается)
    ofstream destFile(destPath);

    // Проверяем, удалось ли создать файл для записи
    if (!destFile.is_open()) {
        cout << "Ошибка: не удалось создать или открыть целевой файл '" << destPath << "' для записи." << endl;
        sourceFile.close();
        return false;
    }

    string line;
    // Читаем исходный файл построчно, пока не достигнем конца
    while (getline(sourceFile, line)) {
        destFile << line << "\n"; // Записываем прочитанную строку в новый файл
    }

    // Закрываем оба файла после завершения работы
    sourceFile.close();
    destFile.close();

    return true;
}

int main() {
    // Жесткая установка русской кодировки для корректного вывода в консоль
    setlocale(LC_ALL, "Russian");

    string sourceFile, destFile;

    cout << "=== ПРОГРАММА КОПИРОВАНИЯ ФАЙЛОВ ===" << endl;

    cout << "Введите имя исходного файла (откуда читать): ";
    cin >> sourceFile;

    cout << "Введите имя целевого файла (куда записать): ";
    cin >> destFile;

    // Вызываем функцию копирования
    if (copyFile(sourceFile, destFile)) {
        cout << "Успех! Содержимое файла успешно скопировано." << endl;
    } else {
        cout << "Копирование не удалось." << endl;
    }

    return 0;
}
