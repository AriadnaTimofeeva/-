#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct Talk {
    string startTime;
    string endTime;
    string authorLastName;
    string authorFirstName;
    string authorMiddleName;
    string topic;
};

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Laboratory work #10. GIT\n";
    cout << "Variant #12(2). Conference Program\n";
    cout << "Author: Ariadna Timofeeva\n" << endl;

    // открытие txt файла
    ifstream inputFile("talks.txt");
    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть файл talks.txt" << endl;
        return 1;
    }

    // Вектор для хранения данных о докладах
    vector<Talk> talks;

    // Читаем данные из файла построчно
    string line;
    while (getline(inputFile, line)) {
        // проходим строку и заполняем структуру Talk
        stringstream ss(line);
        Talk talk;
        ss >> talk.startTime >> talk.endTime >> talk.authorLastName >> talk.authorFirstName >> talk.authorMiddleName >> talk.topic;

        // Добавляем структуру в вектор
        talks.push_back(talk);
    }

    // закрытие файла
    inputFile.close();

    cout << "Доклады Иванова Ивана Ивановича:" << endl;
    for (const Talk& talk : talks) {
        if (talk.authorLastName == "Ivanov" && talk.authorFirstName == "Ivan" && talk.authorMiddleName == "Ivanovich") {
            cout << talk.startTime << " - " << talk.endTime << " " << talk.topic << endl;
        }
    }

    cout << "\nДоклады длительностью больше 15 минут:" << endl;
    for (const Talk& talk : talks) {
        int durationMinutes = stoi(talk.endTime.substr(3)) - stoi(talk.startTime.substr(3));
        if (durationMinutes >= 15) {
            cout << talk.startTime << " - " << talk.endTime << " " << talk.topic << endl;
        }
    }

    return 0;
}