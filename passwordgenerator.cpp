#include "passwordgenerator.h"

PasswordGeneratorWindow::PasswordGeneratorWindow(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("密码生成器");
    setFixedSize(400, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout();

    QLabel *titleLabel = new QLabel("密码生成器");
    titleLabel->setStyleSheet("font-size: 24px; font-weight: bold;");
    titleLabel->setAlignment(Qt::AlignCenter);
    mainLayout->addWidget(titleLabel);

    QHBoxLayout *lengthLayout = new QHBoxLayout();
    QLabel *lengthLabel = new QLabel("密码长度:");
    lengthSpinBox = new QSpinBox();
    lengthSpinBox->setMinimum(8);
    lengthSpinBox->setMaximum(128);
    lengthSpinBox->setValue(16);
    lengthSpinBox->setFixedWidth(100);
    lengthLayout->addWidget(lengthLabel);
    lengthLayout->addWidget(lengthSpinBox);
    lengthLayout->addStretch();
    mainLayout->addLayout(lengthLayout);

    QGroupBox *charTypeGroup = new QGroupBox("字符类型");
    QVBoxLayout *charTypeLayout = new QVBoxLayout();

    uppercaseCheckBox = new QCheckBox("大写字母 (A-Z)");
    uppercaseCheckBox->setChecked(true);
    charTypeLayout->addWidget(uppercaseCheckBox);

    lowercaseCheckBox = new QCheckBox("小写字母 (a-z)");
    lowercaseCheckBox->setChecked(true);
    charTypeLayout->addWidget(lowercaseCheckBox);

    numbersCheckBox = new QCheckBox("数字 (0-9)");
    numbersCheckBox->setChecked(true);
    charTypeLayout->addWidget(numbersCheckBox);

    specialCheckBox = new QCheckBox("特殊字符 (!@#$%^&*)");
    specialCheckBox->setChecked(true);
    charTypeLayout->addWidget(specialCheckBox);

    charTypeGroup->setLayout(charTypeLayout);
    mainLayout->addWidget(charTypeGroup);

    mainLayout->addStretch();

    generateButton = new QPushButton("生成并复制到剪切板");
    generateButton->setFixedHeight(50);
    generateButton->setStyleSheet("QPushButton { background-color: #4CAF50; color: white; font-size: 16px; border-radius: 5px; } QPushButton:hover { background-color: #45a049; }");
    mainLayout->addWidget(generateButton);

    connect(generateButton, &QPushButton::clicked, this, &PasswordGeneratorWindow::onGenerateClicked);

    setLayout(mainLayout);
}

PasswordGeneratorWindow::~PasswordGeneratorWindow() {
}

QString PasswordGeneratorWindow::getCharacterPool(bool useUpper, bool useLower, bool useNumbers, bool useSpecial) {
    QString pool;
    if (useUpper) pool += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if (useLower) pool += "abcdefghijklmnopqrstuvwxyz";
    if (useNumbers) pool += "0123456789";
    if (useSpecial) pool += "!@#$%^&*()-_=+[]{}|;:,.<>?";
    return pool;
}

QString PasswordGeneratorWindow::generatePassword(int length, bool useUpper, bool useLower, bool useNumbers, bool useSpecial) {
    QString pool = getCharacterPool(useUpper, useLower, useNumbers, useSpecial);
    if (pool.isEmpty()) {
        return "";
    }

    QString password;

    if (useUpper) {
        password += "ABCDEFGHIJKLMNOPQRSTUVWXYZ"[QRandomGenerator::global()->bounded(26)];
    }
    if (useLower) {
        password += "abcdefghijklmnopqrstuvwxyz"[QRandomGenerator::global()->bounded(26)];
    }
    if (useNumbers) {
        password += "0123456789"[QRandomGenerator::global()->bounded(10)];
    }
    if (useSpecial) {
        password += QString("!@#$%^&*()")[QRandomGenerator::global()->bounded(10)];
    }

    while (password.length() < length) {
        int index = QRandomGenerator::global()->bounded(pool.length());
        password += pool[index];
    }

    for (int i = password.length() - 1; i > 0; --i) {
        int j = QRandomGenerator::global()->bounded(i + 1);
        QChar temp = password[i];
        password[i] = password[j];
        password[j] = temp;
    }

    return password;
}

void PasswordGeneratorWindow::onGenerateClicked() {
    int length = lengthSpinBox->value();
    bool useUpper = uppercaseCheckBox->isChecked();
    bool useLower = lowercaseCheckBox->isChecked();
    bool useNumbers = numbersCheckBox->isChecked();
    bool useSpecial = specialCheckBox->isChecked();

    if (!useUpper && !useLower && !useNumbers && !useSpecial) {
        QMessageBox::warning(this, "错误", "请至少选择一种字符类型！");
        return;
    }

    QString password = generatePassword(length, useUpper, useLower, useNumbers, useSpecial);

    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(password);

    QMessageBox::information(this, "成功", "密码已生成并复制到剪切板！\n\n密码长度: " + QString::number(password.length()) + " 位");
}
