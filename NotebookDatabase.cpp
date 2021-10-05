#pragma warning(disable : 4996)
// NotebookDatabase.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
// Проект Notebook Explorer.

/* Техническое задание на проект Notebook Explorer
   1 этап.
   1. Написать функцию, которая записывает в бинарный файл данные о ноутбуке из приведенной структуры.
   Структура файла: в первых двух байтах размещается значение типа int, определяющее количество сделанных в файл записей;
   далее без пропусков размещаются записи о ноутбуках.
   2. Написать функцию, которая извлекает из этого файла данные о ноутбуке в структуру типа NOTEBOOK. Обязательный параметр — номер требуемой записи.
   Функция должна возвращать нулевое значение, если чтение прошло успешно, и -1 в противном случае.
   3. Привести пример программы, создающей файл с данными о ноутбуках (данные вводятся с клавиатуры) — 6-8 записей и выводящей на дисплей данные
   о запрошенной записи. Все необходимые данные для функций должны передаваться им в качестве параметров.
   Использование глобальных переменных в функциях не допускается.
*/

#include <cstdio>
#include <conio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct screen {
    // разрешающая способность дисплея
    int х; //по горизонтали
    int у; //по вертикали
    };

struct COMPUTER {
    std::string model[25];     // наименование
    std::string CPU[10];       // процессор
    int  RAM;           // объем памяти
    float hddVol;       // объем диска
    screen screenRes;
    };

struct DATAFILE {       // заполняется при открытии файла
    std::string name = "";   // имя файла без расширения
    int fileRecQty = 0;     // количество записей в файле 
};


char command = '\0';
DATAFILE workFileInfo;
std::vector<COMPUTER> workTable;
COMPUTER workRecord;
FILE* workFile;
int fileRecs = 0;

void viewTable() {
    for (auto i : workTable) {
        std::cout << i.model << '\t|' << i.CPU << '\t|' << i.hddVol << '\t|' << i.RAM << '\t|' << i.screenRes.х << 'x' << i.screenRes.у << std::endl;
    }
};

void addRecord() { //F
    std::cout << "\nFill data fields to add record:";
    std::cout << "\nModel: "; std::cin >> workRecord.model;
    std::cout << "\nCPU model: "; std::cin >> workRecord.CPU;
    std::cout << "\nDisk volume: "; std::cin >> workRecord.hddVol;
    std::cout << "\nScreen resolution x: "; std::cin >> workRecord.screenRes.х; std::cout << " y: "; std::cin >> workRecord.screenRes.у;
    std::cout << "Save (y/n)? ";
    command = '\0';
    command = getche();
    command = toupper(command);
    if (command == 'Y') {
        workTable.push_back(workRecord);
        std::cout << "\nData saved";
        workFileInfo.fileRecQty++;
    }
    else {
        std::cout << "\nData not saved";
    }
};

void viewHelp() { //C
    std::cout << "\n";
    std::cout << "    Table operations:\n";
    std::cout << "A - Add record to table\n";
    std::cout << "V - View table\n";
    std::cout << "\n";
    std::cout << "    File operations:\n";
    std::cout << "C - Create new empty data file on disk\n";
    std::cout << "O - Open data file from disk\n";
    std::cout << "S - Save data file to disk\n";
    std::cout << "I - View data file info\n";
    std::cout << "H - View help\n";
    std::cout << "\n";
    std::cout << "\n";
    std::cout << "Q - Quit program\n";
};

void createEmpty(FILE* _workFile) { //FC
    std::string name;
    int value = 0 ;
    std::cout << "\nFile name to create (\".\" to cancel operation): "; std::cin >> name;
    if (name != ".") {
        name = name + ".dat";
        _workFile = fopen(name.c_str(), "wb");
        if (ferror(_workFile)) {
            fclose(_workFile);
            std::cout << "\nFile creating error";
        }
        else {
            fwrite(&value, sizeof value, 1, _workFile);
            fclose(_workFile);
            std::cout << "\nFile created succesfully";
        }
    }
};
void readDataFile(FILE * _workFile) {

};
int main()
{ 
    std::cout << "NoteBook Explorer v 1.0\n";
    do  {
        command = '\0';
        std::cout << "\n>";
        command = getche();
        command = toupper(command);
        std::cout << "\nExecuting " << command <<'\n';
        switch (command) {
        case 'A':
            addRecord();
            break;
        case 'C':
            createEmpty(workFile);
            break;
        case 'H':
            viewHelp();
            break;
        case 'I':
            break;
        case 'O':
            break;
        case 'Q':
            break;
        case 'S':
            break;
        case 'V':
            viewTable();
            break;
        default:
            viewHelp();
            break;
        };
    } while (!(command == 'Q'));
    return 0;
}

