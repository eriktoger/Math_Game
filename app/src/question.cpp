#include "../include/question.h"

#include <QCoreApplication>
Question::Question(QObject *parent) : QObject(parent)
{
    name = QString("Maja");
    operation = QString("addition");
    difficulty = "medium";
    correct = 0;
    errors = 0;

    generateQuestionAndAnswer();

}

QString Question::getQuestion()
{

    return question;
}


void Question::generateQuestionAndAnswer()
{
    if(operation == "addition"){

        if(difficulty == "easy"){
            srand(time(NULL));
            int ans = rand()% 9 +1;
            int term1 = rand() % ans;
            int term2 = ans - term1;
            question = QString::number(term1) + " + " +QString::number(term2) + " =" ;
            answer = QString::number(ans);
            return;
        }

        if(difficulty == "medium"){
            srand(time(NULL));
            int ans = rand()% 10 + 10;
            int last = ans % 10;
            int term1 = last + rand() % (10-last);
            int term2 = ans - term1;
            question = QString::number(term1) + " + " +QString::number(term2) + " =" ;
            answer = QString::number(ans);
            return;
        }

    }

}

void Question::gradeQuestion(QString input)
{
    if(input == answer){
        correct++;
        emit correctIncremented();

        generateQuestionAndAnswer();
        emit questionChanged();

    }else{
        errors++;
        emit errorsIncremented();
    }



}

int Question::getCorrect(){
    return correct;
}

int Question::getErrors(){
    return errors;
}


void Question::setName(const QString &newName)
{
    name = newName;
    emit nameChanged();
}

void Question::newQuestion(){
    generateQuestionAndAnswer();
    emit questionChanged();
}
