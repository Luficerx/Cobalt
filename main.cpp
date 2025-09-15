#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>

void say(QString text);

int main(int argc, char *argv[])
{
    say("Hello from Qt Application!");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("Cobalt", "Main");

    return app.exec();
}

void say(QString text)
{
    qInfo() << text;
}
