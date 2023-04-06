// toolboxal_ui.h

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

#pragma once

#ifndef TOOLBOXAL_UI_H
#define TOOLBOXAL_UI_H

#include <QtWidgets/QWidget>
#include <QMessageBox>
#include "ui_toolboxal_ui.h"
#include "core.h"

class Toolboxal_UI final : public QWidget
{
    Q_OBJECT

public:
    Toolboxal_UI(QWidget *parent = Q_NULLPTR);
    ~Toolboxal_UI() override = default;

private slots:
    void on_convertRadix_clicked() const;
    void on_swapRadix_clicked() const;

    void on_convertMagnitude_clicked() const;
    void on_swapMagnitude_clicked() const;

    void on_calculateButton_clicked() const;
    void on_operatorCombobox_currentIndexChanged() const;

    void on_searchButton_clicked() const;

    // methods that change combobox text using radio buttons
    void input_Bit_Checked() const;
    void input_Binary_Checked() const;
    void input_Both_Checked() const;
    void output_Bit_Checked() const;
    void output_Binary_Checked() const;
	void output_Both_Checked() const;

private:
    Ui::Toolboxal_UIClass ui{};
};

#endif // TOOLBOXAL_UI_H