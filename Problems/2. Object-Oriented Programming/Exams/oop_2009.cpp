#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/*
Да се реализира абстрактен базов клас, представящ обект от файловата система. Този обект се характеризира с име.
Класът да предоставя метод за определяне на заеманото от обекта дисково пространство.
    − Да се реализира наследник на този клас представящ файл. Файлът трябва да пази информация за размера си.
    − Да се реализира наследник на този клас представящ директория. Директорията съхранява масив от обекти от файловата система.
    − Напишете кратка програма, която да създаде директория, съдържаща поне една поддиректория и поне един файл и след това
      да изведе на екрана размера на тази директория
*/

class FileSystemObject {
    public:
        FileSystemObject(const char* n) {
            name = new char[strlen(n) + 1];
            strcpy(name, n);
        }

        virtual double disk_usage() const = 0;
        
        virtual ~FileSystemObject() {
            delete[] name;
        }
    
    protected:
        char* name;
};

class File : public FileSystemObject {
    public:
        File(const char* n, int s) : FileSystemObject(n) {
            size = s;
        }

        double disk_usage() const override {
            return size;
        }

    private:
        int size;
};

class Directory : public FileSystemObject {
    public:
        Directory(const char* n) : FileSystemObject(n) {}

        void add(FileSystemObject* obj) {
            contents.push_back(obj);
        }

        double disk_usage() const override {
            double sum = 0.0;
            
            for (const auto& obj : contents) {
                sum += obj->disk_usage();
            }

            return sum;
        }

        ~Directory() override {
            for (auto obj : contents) {
                delete obj;
            }
        }

    private:
        vector<FileSystemObject*> contents;
};

int main() {

    Directory* dir = new Directory("root");

    FileSystemObject* file1 = new File("notes.txt", 100);
    FileSystemObject* file2 = new File("image.png", 250);

    Directory* subdir = new Directory("tmp");
    FileSystemObject* file3 = new File("data.csv", 300);
    subdir->add(file3);

    dir->add(file1);
    dir->add(file2);
    dir->add(subdir);

    cout << "Disk usage of root: " << dir->disk_usage() << " KB" << endl;

    delete dir; // освобождава и всички вложени елементи

    return 0;
}