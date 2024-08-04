#include <iostream>
using namespace std;

// Abstract base class for files
class File {
public:
    virtual ~File() = default;

    // Pure virtual function to open the file
    virtual void open() const = 0;

    // Pure virtual function to read the file
    virtual void read() const = 0;

    // Pure virtual function to close the file
    virtual void close() const = 0;

    // Pure virtual function to get the type of file
    virtual string getType() const = 0;
};

class TextFile : public File {
    private:
        string fileName;

    public:
        TextFile(const string& name) : fileName(name) {}

        void open() const override {
            cout << "Opening text file: " << fileName << endl;
        }

        void read() const override {
            cout << "Reading text file: " << fileName << endl;
        }

        void close() const override {
            cout << "Closing text file: " << fileName << endl;
        }

        string getType() const override {
            return "Text File";
        }
};

class AudioFile : public File {
    private:
        string fileName;

    public:
        AudioFile(const string& name) : fileName(name) {}

        void open() const override {
            cout << "Opening audio file: " << fileName << endl;
        }

        void read() const override {
            cout << "Playing audio file: " << fileName << endl;
        }

        void close() const override {
            cout << "Stopping audio file: " << fileName << endl;
        }

        string getType() const override {
            return "Audio File";
        }
};

void processFile(const File& file) {
    cout << "File type: " << file.getType() << endl;
    file.open();
    file.read();
    file.close();
}

int main() {

    TextFile t("example.txt");
    AudioFile a("song.mp3");

    processFile(t);
    processFile(a);

    return 0;
}
