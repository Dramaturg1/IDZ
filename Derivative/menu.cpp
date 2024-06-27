#include "menu.h"
#include "ui_menu.h"
#include <QString>
#include <QStringList>
#include <QChar>
#include <QVariant>
#include <QMessageBox>
#include <QRegularExpression>

bool isCorrect(QString str);

QString deriveTerm(QString term) {
    if (term.contains('x')) {
        if (term.contains('^')) {
            QStringList parts = term.split("x^");
            int coeff = parts[0].isEmpty() ? 1 : (parts[0] == "+" ? 1 : (parts[0] == "-" ? -1 : parts[0].toInt()));
            int power = parts[1].toInt();
            coeff *= power;
            power--;
            if (power == 0) {
                return QString::number(coeff);
            } else if (power == 1) {
                return QString::number(coeff) + "x";
            } else {
                return QString::number(coeff) + "x^" + QString::number(power);
            }
        } else {
            QString coeffStr = term.left(term.indexOf('x'));
            int coeff = coeffStr.isEmpty() ? 1 : (coeffStr == "+" ? 1 : (coeffStr == "-" ? -1 : coeffStr.toInt()));
            return QString::number(coeff) + "x";
        }
    } else {
        return "0";
    }
}

QString string_parcing(QString str) {
    QString temp = str;
    temp.replace(" ", "");
    temp.replace("*", "");
    QString result;

    if (!isCorrect(temp)) {
        QMessageBox msgBox;
        msgBox.setText("Некорректный ввод");
        msgBox.exec();
        return "";
    }

    QRegularExpression termRegex("([+-]?[^-+]+)");
    QRegularExpressionMatchIterator i = termRegex.globalMatch(temp);
    while (i.hasNext()) {
        QRegularExpressionMatch match = i.next();
        QString term = match.captured(1);
        QString derivedTerm = deriveTerm(term);

        if (!result.isEmpty() && !derivedTerm.startsWith('-')) {
            result.append('+');
        }
        result.append(derivedTerm);
    }

    return result;
}

bool isCorrect(QString str) {
    if (str.contains("--") || str.contains("++") || str.contains("^^") || str.contains("xx") || str.contains("^-") || str.contains("-^")) {
        return false;
    }
    if (str.contains('^') && !str.contains("x^")) {
        return false;
    }
    for (int i = 0; i < str.size(); ++i) {
        if ((str.at(i) < QChar('0') || str.at(i) > QChar('9')) && str.at(i) != QChar('^') && str.at(i) != QChar('x') && str.at(i) != QChar('+') && str.at(i) != QChar('-')) {
            return false;
        }
    }
    return true;
}

Menu::Menu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    QString str = ui->lineEdit->text();
    ui->lineEdit_2->setText(string_parcing(str));
}
