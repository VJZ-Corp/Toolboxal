// toolboxal_ui.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "toolboxal_ui.h"

Toolboxal_UI::Toolboxal_UI(QWidget *parent)
    : QWidget(parent)
{
    //sep: 82 char
    ui.setupUi(this);

    connect(ui.convertRadix, SIGNAL(clicked()), SLOT(convert_Radix()));
    connect(ui.swapRadix, SIGNAL(clicked()), SLOT(swap_Radix()));
}

void Toolboxal_UI::convert_Radix()
{
    QString num = ui.inputValueRadix.text();
    QByteArray byteArr = num.toLocal8Bit();
    const char* c_str2 = byteArr.data();
    Core::Radix::Converter(c_str2, ui.currentRadix.value(), ui.futureRadix.value());
}
