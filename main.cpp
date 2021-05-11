#include <QCoreApplication>

#include <private/qutfcodec_p.h>
#include <QTextCodec>
#include <QDebug>

bool isValidUtf8(const QByteArray& data) {
    return QUtf8::isValidUtf8(data.data(), data.size()).isValidUtf8;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QTextCodec* utf8 = QTextCodec::codecForName("UTF-8");
    QTextCodec* cp1251 = QTextCodec::codecForName("CP1251");

    QByteArray utf8data1 = utf8->fromUnicode("Привет мир");
    QByteArray cp1251data1 = cp1251->fromUnicode("Привет мир");

    QByteArray utf8data2 = utf8->fromUnicode("Hello world");
    QByteArray cp1251data2 = cp1251->fromUnicode("Hello world");

    Q_ASSERT(isValidUtf8(utf8data1));
    Q_ASSERT(isValidUtf8(cp1251data1) == false);

    Q_ASSERT(isValidUtf8(utf8data2));
    Q_ASSERT(isValidUtf8(cp1251data2));

    qDebug() << "test passed";

    return 0;
}
