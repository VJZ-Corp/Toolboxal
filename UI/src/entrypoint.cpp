// entrypoint.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only

#include "toolboxal_ui.h"
#include <QtWidgets/QApplication>

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    Toolboxal_UI w;
    w.show();
    return QApplication::exec();
}