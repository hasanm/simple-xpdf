#include <QApplication>
#include <QLocalSocket>

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;


int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QLocalSocket *sock;
    QString sockName;
    // char str[] = "openFile(/data/1.pdf)";
    // char str[] = "openFile(/data/1-84628-168-7.pdf)";
    // char str[] = "openFile(/home/p-hasan/work/fs/stat2780/cheatsheet/cheatsheet.pdf)";
    // char str[] = "openFile(/home/p-hasan/work/fs/stat2780/hw2/stat2780_hw2.pdf)";
    // char str[] = "openFile(/home/p-hasan/work/fs/tikz/apas-deployment.pdf)";
    char str[] = "reload";

    sock = new QLocalSocket(nullptr);
    sockName = "xpdf_test";
    qDebug() << "Connecting to Socket";
    sock->connectToServer(sockName, QIODevice::WriteOnly);
    if (sock->waitForConnected(5000)) {
        qDebug() << "Connected";
        sock->write(str);
        sock->write("\n");
        while (sock->bytesToWrite()) {
            sock->waitForBytesWritten(5000);
	}
    }

    delete sock;
    return 0;
}
