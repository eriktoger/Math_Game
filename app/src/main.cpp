#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickView>
#include <QQmlContext>
#include "../include/question.h"
#include "../include/randomgenerator.h"
#include <memory>
#include <QDir>

int main(int argc, char *argv[]) {
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    QQmlContext *context = engine.rootContext();

    engine.addImportPath(":/resources");

    QDir dir(":/resources/images/quiz");
    auto *imageInfo = new ImageInfo;
    QFileInfoList list = dir.entryInfoList();

    for (auto &fileInfo : list) {
        std::string url = "images/quiz/" + fileInfo.fileName().toStdString();
        imageInfo->addUrl(url);
    }
    imageInfo->setRandomUrl();
    context->setContextProperty("imageInfo", imageInfo);

    //instead of //import io.qt.examples.question 1.0
    qmlRegisterType<Question>("Question", 1, 0, "Question");

    engine.addImportPath(app.applicationDirPath() + "/include");
    engine.load(QUrl(QStringLiteral("qrc:/resources/main.qml")));

    return app.exec();
}
