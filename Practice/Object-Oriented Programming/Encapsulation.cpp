#include <iostream>
using namespace std;

class Server {
public:
    virtual ~Server() = default;

    // Pure virtual function to start the server
    virtual void start() const = 0;

    // Pure virtual function to get the type of server
    virtual string getType() const = 0;
};

class WebServer : public Server {
    private:
        string ipAddress;
        int port;

    public:
        WebServer(const string& ip, int p) : ipAddress(ip), port(p) {}

        void start() const override {
            cout << "Starting the web server at " << ipAddress << ":" << port << endl;
        }

        string getType() const override {
            return "Web Server";
        }

        // Getter for IP address
        string getIpAddress() const {
            return ipAddress;
        }

        // Setter for IP address
        void setIpAddress(const string& ip) {
            ipAddress = ip;
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
        string dbName;
        int port;

    public:
        DatabaseServer(const string& db, int p) : dbName(db), port(p) {}

        void start() const override {
            cout << "Starting the database server for " << dbName << " at port " << port << endl;
        }

        string getType() const override {
            return "Database Server";
        }

        // Getter for database name
        string getDbName() const {
            return dbName;
        }

        // Setter for database name
        void setDbName(const string& db) {
            dbName = db;
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