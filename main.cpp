#include <QApplication>
#include <QQmlApplicationEngine>

#include <framelesswindow.h>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Test test;

    QQmlApplicationEngine engine;

    qmlRegisterType<FramelessWindow>("Frameless", 1, 0, "FramelessWindow");

    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qDebug() << app.primaryScreen()->devicePixelRatio();

    QObject::connect (app.primaryScreen(), &QScreen::refreshRateChanged, &test, &Test::handleRefreshRate);

    return app.exec();
}
