// toolboxal_ui.h

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#ifndef TOOLBOXAL_UI_H
#define TOOLBOXAL_UI_H

#include <QtWidgets/QWidget>
#include "ui_toolboxal_ui.h"
#include "databus.h"

class Toolboxal_UI : public QWidget
{
    Q_OBJECT

public:
    Toolboxal_UI(QWidget *parent = Q_NULLPTR);
    virtual ~Toolboxal_UI() {}

private slots:
    void convert_Radix();
    void swap_Radix();

private:
    Ui::Toolboxal_UIClass ui;
};

#endif // TOOLBOXAL_UI_H