// toolboxal_ui.h

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#ifndef TOOLBOXAL_UI_H
#define TOOLBOXAL_UI_H

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include <QTextOption>
#include "ui_toolboxal_ui.h"
#include "core.h"

class Toolboxal_UI : public QWidget
{
    Q_OBJECT

public:
    Toolboxal_UI(QWidget *parent = Q_NULLPTR);
    virtual ~Toolboxal_UI() = default;

private slots:
    void on_convertRadix_clicked();
    void on_swapRadix_clicked();

    void on_convertMagnitude_clicked();
    void on_swapMagnitude_clicked();

    // methods that change combobox text using radio buttons
    void input_Bit_Checked();
    void input_Binary_Checked();
    void input_Both_Checked();
    void output_Bit_Checked();
    void output_Binary_Checked();
	void output_Both_Checked();

private:
    Ui::Toolboxal_UIClass ui;
};

#endif // TOOLBOXAL_UI_H