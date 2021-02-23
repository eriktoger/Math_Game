#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "../include/question.h"
#include "../include/randomgenerator.h"
#include <memory>
int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext* context = engine.rootContext();

    auto *imageInfo = new ImageInfo;
    imageInfo->initializeUrls();

    context->setContextProperty("imageInfo",imageInfo);

    //instead of //import io.qt.examples.question 1.0
    qmlRegisterType<Question>("Question", 1,0, "Question");
    std::cout << app.applicationDirPath().toStdString()<<std::endl;
    engine.addImportPath(app.applicationDirPath() + "/include");
    const QUrl url(QStringLiteral("qml/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    engine.load(url);

    return app.exec();
}
