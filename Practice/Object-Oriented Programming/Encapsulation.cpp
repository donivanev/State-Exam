#include <iostream>
using namespace std;

class Server {
public:
    virtual ~Server() = default;

    // Pure virtual function to start the server
    virtual void start() const = 0;

    // Pure virtual function to get the type of server
    virtual const char* getType() const = 0;
};

class WebServer : public Server {
    private:
        char* ipAddress;
        int port;

    public:
        WebServer(const char* ip, int p) : port(p) {
            ipAddress = new char[strlen(ip) + 1];
            strcpy(ipAddress, ip);
        }

        ~WebServer() {
            delete[] ipAddress;
        }

        void start() const override {
            cout << "Starting the web server at " << ipAddress << ":" << port << endl;
        }

        const char* getType() const override {
            return "Web Server";
        }

        // Getter for IP address
        const char* getIpAddress() const {
            return ipAddress;
        }

        // Setter for IP address
        void setIpAddress(const char* ip) {
            delete[] ipAddress;
            ipAddress = new char[strlen(ip) + 1];
            strcpy(ipAddress, ip);
        }

        // Getter for port
        int getPort() const {
            return port;
        }

        // Setter for port
        void setPort(int p) {
            port = p;
        }
};

class DatabaseServer : public Server {
    private:
        char* dbName;
        int port;

    public:
        DatabaseServer(const char* db, int p) : port(p) {
            dbName = new char[strlen(db) + 1];
            strcpy(dbName, db);
        }

        void start() const override {
            cout << "Starting the database server for " << dbName << " at port " << port << endl;
        }

        const char* getType() const override {
            return "Database Server";
        }

        // Getter for database name
        const char* getDbName() const {
            return dbName;
        }

        // Setter for database name
        void setDbName(const char* db) {
            delete[] dbName;
            dbName = new char[strlen(db) + 1];
            strcpy(dbName, db);
        }

        // Getter for port
        int getPort() const {
            return port;
        }

        // Setter for port
        void setPort(int p) {
            port = p;
        }
};

int main() {

    WebServer wb("192.168.1.1", 80);
    DatabaseServer db("my_database", 5432);

    wb.start();
    db.start();

    cout << "Web Server IP Address: " << wb.getIpAddress() << endl;
    cout << "Database Server Name: " << db.getDbName() << endl;

    // Modifying server properties using setters
    wb.setIpAddress("192.168.1.2");
    wb.setPort(8080);
    db.setDbName("new_database");
    db.setPort(3306);

    cout << "Updated Web Server IP Address: " << wb.getIpAddress() << endl;
    cout << "Updated Web Server Port: " << wb.getPort() << endl;
    cout << "Updated Database Server Name: " << db.getDbName() << endl;
    cout << "Updated Database Server Port: " << db.getPort() << endl;

    return 0;
}