#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include "imageInfo.h"
class Question : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ getName)
    Q_PROPERTY(QString difficulty READ getDifficulty WRITE setDifficulty NOTIFY difficultyChanged)
    Q_PROPERTY(int correct READ getCorrect NOTIFY correctIncremented)
    Q_PROPERTY(int errors READ getErrors NOTIFY errorsIncremented)
    Q_PROPERTY(QString question READ getQuestion NOTIFY questionChanged)
    QML_ELEMENT

private:
    QString question;
    QString answer;
    QString operation;
    QString difficulty;
    int correct;
    int errors;
    void generateQuestionAndAnswer();

public:
    QString name;
//    virtual ~Question()=default;
    Q_INVOKABLE void gradeQuestion(QString input);
    explicit Question(QObject *parent = nullptr);
    QString getQuestion();
    QString getName(){return name;}
    QString getDifficulty(){return difficulty;}
    void setDifficulty(QString newDiff){
        if(difficulty != newDiff){
             difficulty = newDiff;
            emit difficultyChanged();
        }
       }
    int getCorrect();
    int getErrors();
    void setName(const QString &newName);
public slots:
    void newQuestion();
signals:
    void nameChanged();
    void correctIncremented();
    void errorsIncremented();
    void difficultyChanged();
    void questionChanged();
    //question answerd
    //correct/errors should update
};

#endif // QUESTION_H
