#include "../include/list.h"
#include "../include/commands.h"
#include "../include/json.hpp"

int countingLine(string& fin) { // ф-ия подсчёта строк в файле
    ifstream file;
    file.open(fin);
    int countline = 0;
    string line;
    while(getline(file, line)) {
        countline++;
    }
    file.close();
    return countline;
}

string fileread(string& filepath) { // чтение из файла
    string result, str;
    ifstream fileinput;
    fileinput.open(filepath);
    while (getline(fileinput, str)) {
        result += str + '\n';
    }
    result.pop_back();
    fileinput.close();
    return result;
}

void filerec(string& filename, string data) { // запись в файл
    ofstream fileoutput;
    fileoutput.open(filename);
    fileoutput << data;
    fileoutput.close();
}

void BaseDate::checkcommand(string& command) {
    if (command.substr(0, 11) == "INSERT INTO") {
        command.erase(0, 12);
        Insert(command);
    } else if (command.substr(0, 11) == "DELETE FROM") {
        command.erase(0, 12);
        Delete(command);
    } else if (command.substr(0, 6) == "SELECT") {
        command.erase(0, 7);
        Select(command);
    } else if (command == "EXIT") {
        exit(0);
    } else {
        cout << "Ошибка, неизвестная команда!" << endl; 
    }
}

int main() {
    BaseDate shopNet;

    shopNet.parser();
    shopNet.createdirect();
    string command;
    while (true) {
        cout << endl << "Введите команду: ";
        getline(cin, command);
        shopNet.checkcommand(command);
    }

    return 0;
}
