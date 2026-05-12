#ifndef PASSWORDGENERATOR_H
#define PASSWORDGENERATOR_H

#include <QMainWindow>
#include <QApplication>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QClipboard>
#include <QRandomGenerator>
#include <QString>
#include <QWidget>

class PasswordGeneratorWindow : public QWidget {
    Q_OBJECT

private:
    QSpinBox *lengthSpinBox;
    QCheckBox *uppercaseCheckBox;
    QCheckBox *lowercaseCheckBox;
    QCheckBox *numbersCheckBox;
    QCheckBox *specialCheckBox;
    QPushButton *generateButton;

    QString generatePassword(int length, bool useUpper, bool useLower, bool useNumbers, bool useSpecial);
    QString getCharacterPool(bool useUpper, bool useLower, bool useNumbers, bool useSpecial);

public:
    PasswordGeneratorWindow(QWidget *parent = nullptr);
    ~PasswordGeneratorWindow();

private slots:
    void onGenerateClicked();
};

#endif
