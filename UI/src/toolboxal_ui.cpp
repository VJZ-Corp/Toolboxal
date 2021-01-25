// toolboxal_ui.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "toolboxal_ui.h"

Toolboxal_UI::Toolboxal_UI(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    connect(ui.convertRadix, SIGNAL(clicked()), SLOT(convert_Radix()));
    connect(ui.swapRadix, SIGNAL(clicked()), SLOT(swap_Radix()));
}

void Toolboxal_UI::convert_Radix()
{
    QString num = ui.inputValueRadix->text();
    QByteArray byteArr = num.toLocal8Bit();

    std::string c_str2 = byteArr.data();
    const int bases[36] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36 };
    
    int currentIRadix = ui.currentRadix->currentIndex();
    int futureIRadix = ui.futureRadix->currentIndex();

    std::string result = Core::Radix_Converter(c_str2, bases[currentIRadix], bases[futureIRadix]);
    ui.resultValueRadix->setText(QString::fromStdString(result));
}

void Toolboxal_UI::swap_Radix()
{
    int tmpIndex = ui.currentRadix->currentIndex();
    ui.currentRadix->setCurrentIndex(ui.futureRadix->currentIndex());
    ui.futureRadix->setCurrentIndex(tmpIndex);
}
