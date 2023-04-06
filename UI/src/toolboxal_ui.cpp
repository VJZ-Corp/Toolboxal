// toolboxal_ui.cpp

// Copyright (C) 2021 by VJZ Corporation.
// SPDX-License-Identifier: GPL-3.0-only	

#include "toolboxal_ui.h"

Toolboxal_UI::Toolboxal_UI(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    ui.resultValueRadix->setWordWrapMode(QTextOption::WrapMode::WrapAnywhere);
    ui.outputData->setWordWrapMode(QTextOption::WrapMode::WrapAnywhere);
	ui.bitwiseResult->setWordWrapMode(QTextOption::WrapMode::WrapAnywhere);

    connect(ui.inputUseBit, SIGNAL(clicked()), SLOT(input_Bit_Checked()));
    connect(ui.inputUseBinary, SIGNAL(clicked()), SLOT(input_Binary_Checked()));
    connect(ui.outputUseBit, SIGNAL(clicked()), SLOT(output_Bit_Checked()));
    connect(ui.outputUseBinary, SIGNAL(clicked()), SLOT(output_Binary_Checked()));
    connect(ui.inputUseBoth, SIGNAL(clicked()), SLOT(input_Both_Checked()));
    connect(ui.outputUseBoth, SIGNAL(clicked()), SLOT(output_Both_Checked()));
}

void Toolboxal_UI::on_convertRadix_clicked() const
{
	// convert QString to std::string
    const QString num = ui.inputValueRadix->text();
    QByteArray byteArr = num.toLocal8Bit();
    const std::string c_str2 = byteArr.data();

    const int bases[35] = { 
        2,  3,  4,  5,  6,  7,  8, 
        9,  10, 11, 12, 13, 14, 15, 
        16, 17, 18, 19, 20, 21, 22, 
        23, 24, 25, 26, 27, 28, 29, 
        30, 31, 32, 33, 34, 35, 36 
    };
    
    const int currentIRadix = ui.currentRadix->currentIndex();
    const int futureIRadix = ui.futureRadix->currentIndex();
    const std::string result = Core::Radix_Converter(c_str2, bases[currentIRadix], bases[futureIRadix]);

    if (result == "Invalid string literal detected for specified radix.")
        QMessageBox::warning(nullptr, "Warning", QString::fromStdString(result));
    else 
        ui.resultValueRadix->setText(QString::fromStdString(result));
}

void Toolboxal_UI::on_swapRadix_clicked() const
{
    const int tmpIndex = ui.currentRadix->currentIndex();
    ui.inputValueRadix->setText(ui.resultValueRadix->toPlainText());
    ui.currentRadix->setCurrentIndex(ui.futureRadix->currentIndex());
    ui.futureRadix->setCurrentIndex(tmpIndex);
}

void Toolboxal_UI::on_convertMagnitude_clicked() const
{
	const int currentIData = ui.inputMagnitude->currentIndex();
	const int futureIData = ui.outputMagnitude->currentIndex();
	
	const RadioButtonOptions radioOpt = {
		ui.inputUseBit->isChecked(),  ui.inputUseBinary->isChecked(),  ui.inputUseBoth->isChecked(),
		ui.outputUseBit->isChecked(), ui.outputUseBinary->isChecked(), ui.outputUseBoth->isChecked()
	};

	const std::string inputNum = ui.inputData->text().toLocal8Bit().data();
	const std::string result = Core::Magnitude_Converter(inputNum, currentIData, futureIData, radioOpt);

	if (result == "Input can only contain numbers!")
		QMessageBox::warning(0, "Warning", QString::fromStdString(result));
	else
		ui.outputData->setText(QString::fromStdString(result));
}

void Toolboxal_UI::on_swapMagnitude_clicked() const
{
	// make all radio buttons checkable
	ui.inputUseBinary->setCheckable(true);
	ui.inputUseBit->setCheckable(true);
	ui.inputUseBoth->setCheckable(true);
	ui.outputUseBinary->setCheckable(true);
	ui.outputUseBit->setCheckable(true);
	ui.outputUseBoth->setCheckable(true);

	// store check states in bool variable
	const bool tmpinput1 = ui.inputUseBinary->isChecked();
	const bool tmpinput2 = ui.inputUseBit->isChecked();
	const bool tmpinput3 = ui.inputUseBoth->isChecked();
	
	// swap check states
	ui.inputUseBinary->setChecked(ui.outputUseBinary->isChecked());
	ui.inputUseBit->setChecked(ui.outputUseBit->isChecked());
	ui.inputUseBoth->setChecked(ui.outputUseBoth->isChecked());
	ui.outputUseBinary->setChecked(tmpinput1);
	ui.outputUseBit->setChecked(tmpinput2);
	ui.outputUseBoth->setChecked(tmpinput3);

	const int tmpIndex = ui.inputMagnitude->currentIndex();
	ui.inputData->setText(ui.outputData->toPlainText());
	ui.inputMagnitude->setCurrentIndex(ui.outputMagnitude->currentIndex());
	ui.outputMagnitude->setCurrentIndex(tmpIndex);
}

void Toolboxal_UI::on_calculateButton_clicked() const
{
	const int currentIData = ui.operatorCombobox->currentIndex();
	const std::string inputNum = ui.inputNum1->text().toLocal8Bit().data();
	const std::string inputNum2 = ui.inputNum2->text().toLocal8Bit().data();

	if (currentIData <= 6)
	{
		const std::string result = Core::Logic_Gates(inputNum, inputNum2, currentIData);

		if (result == "Toolboxal is currently experiencing some issues. Please try again later.")
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString(result));
		else
			ui.bitwiseResult->setText(QString::fromStdString(result));

		if (result == "Input radices must match!")
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString(result));
		else
			ui.bitwiseResult->setText(QString::fromStdString(result));

		if (result == "Invalid string literal detected for specified radix.")
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString(result));
		else
			ui.bitwiseResult->setText(QString::fromStdString(result));
	}
	else
	{
		const std::string result = Core::Bitshifter(inputNum, inputNum2, currentIData);

		if (result == "Toolboxal is currently experiencing some issues. Please try again later.")
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString(result));
		else
			ui.bitwiseResult->setText(QString::fromStdString(result));

		if (result == "Invalid string literal detected for specified radix.")
			QMessageBox::warning(nullptr, "Warning", QString::fromStdString(result));
		else
			ui.bitwiseResult->setText(QString::fromStdString(result));
	}
}

void Toolboxal_UI::on_operatorCombobox_currentIndexChanged() const
{
	if (ui.operatorCombobox->currentIndex() == 2)
	{
		ui.inputNum2->setDisabled(true);
		ui.inputNum2->clear();
	} 
	else
		ui.inputNum2->setDisabled(false);
}

void Toolboxal_UI::on_searchButton_clicked() const
{
	const std::string query = ui.searchQuery->text().toLocal8Bit().data();
	const std::string size = ui.searchNumber->text().toLocal8Bit().data();
	const std::string results = Core::Search(query, size);
	ui.searchResults->setText(QString::fromStdString(results));
}

void Toolboxal_UI::input_Bit_Checked() const
{
	if (ui.inputUseBit->isCheckable())
	{
		if (ui.inputUseBit->isChecked())
		{
			ui.inputUseBinary->setCheckable(false);
			ui.inputUseBoth->setCheckable(false);

			ui.inputMagnitude->setItemText(0, "Bit (b)");
			ui.inputMagnitude->setItemText(1, "Kilobit (Kb)");
			ui.inputMagnitude->setItemText(2, "Megabit (Mb)");
			ui.inputMagnitude->setItemText(3, "Gigabit (Gb)");
			ui.inputMagnitude->setItemText(4, "Terabit (Tb)");
			ui.inputMagnitude->setItemText(5, "Petabit (Pb)");
			ui.inputMagnitude->setItemText(6, "Exabit (Eb)");
			ui.inputMagnitude->setItemText(7, "Zettabit (Zb)");
			ui.inputMagnitude->setItemText(8, "Yottabit (Yb)");
		}
		else
		{
			ui.inputUseBinary->setCheckable(true);
			ui.inputUseBoth->setCheckable(true);

			ui.inputMagnitude->setItemText(0, "Byte (B)");
			ui.inputMagnitude->setItemText(1, "Kilobyte (KB)");
			ui.inputMagnitude->setItemText(2, "Megabyte (MB)");
			ui.inputMagnitude->setItemText(3, "Gigabyte (GB)");
			ui.inputMagnitude->setItemText(4, "Terabyte (TB)");
			ui.inputMagnitude->setItemText(5, "Petabyte (PB)");
			ui.inputMagnitude->setItemText(6, "Exabyte (EB)");
			ui.inputMagnitude->setItemText(7, "Zettabyte (ZB)");
			ui.inputMagnitude->setItemText(8, "Yottabyte (YB)");
		}
	} 
}

void Toolboxal_UI::input_Binary_Checked() const
{
	if (ui.inputUseBinary->isCheckable())
	{
		if (ui.inputUseBinary->isChecked())
		{
			ui.inputUseBit->setCheckable(false);
			ui.inputUseBoth->setCheckable(false);

			ui.inputMagnitude->setItemText(0, "Byte (B)");
			ui.inputMagnitude->setItemText(1, "Kibibyte (KiB)");
			ui.inputMagnitude->setItemText(2, "Mebibyte (MiB)");
			ui.inputMagnitude->setItemText(3, "Gibibyte (GiB)");
			ui.inputMagnitude->setItemText(4, "Tebibyte (TiB)");
			ui.inputMagnitude->setItemText(5, "Pebibyte (PiB)");
			ui.inputMagnitude->setItemText(6, "Exbibyte (EiB)");
			ui.inputMagnitude->setItemText(7, "Zebibyte (ZiB)");
			ui.inputMagnitude->setItemText(8, "Yobibyte (YiB)");
		}
		else
		{
			ui.inputUseBit->setCheckable(true);
			ui.inputUseBoth->setCheckable(true);

			ui.inputMagnitude->setItemText(0, "Byte (B)");
			ui.inputMagnitude->setItemText(1, "Kilobyte (KB)");
			ui.inputMagnitude->setItemText(2, "Megabyte (MB)");
			ui.inputMagnitude->setItemText(3, "Gigabyte (GB)");
			ui.inputMagnitude->setItemText(4, "Terabyte (TB)");
			ui.inputMagnitude->setItemText(5, "Petabyte (PB)");
			ui.inputMagnitude->setItemText(6, "Exabyte (EB)");
			ui.inputMagnitude->setItemText(7, "Zettabyte (ZB)");
			ui.inputMagnitude->setItemText(8, "Yottabyte (YB)");
		}
	}
}

void Toolboxal_UI::input_Both_Checked() const
{
	if (ui.inputUseBoth->isCheckable())
	{
		if (ui.inputUseBoth->isChecked())
		{
			ui.inputUseBit->setCheckable(false);
			ui.inputUseBinary->setCheckable(false);

			ui.inputMagnitude->setItemText(0, "Bit (b)");
			ui.inputMagnitude->setItemText(1, "Kibibit (Kib)");
			ui.inputMagnitude->setItemText(2, "Mebibit (Mib)");
			ui.inputMagnitude->setItemText(3, "Gibibit (Gib)");
			ui.inputMagnitude->setItemText(4, "Tebibit (Tib)");
			ui.inputMagnitude->setItemText(5, "Pebibit (Pib)");
			ui.inputMagnitude->setItemText(6, "Exbibit (Eib)");
			ui.inputMagnitude->setItemText(7, "Zebibit (Zib)");
			ui.inputMagnitude->setItemText(8, "Yobibit (Yib)");
		}
		else
		{
			ui.inputUseBit->setCheckable(true);
			ui.inputUseBinary->setCheckable(true);

			ui.inputMagnitude->setItemText(0, "Byte (B)");
			ui.inputMagnitude->setItemText(1, "Kilobyte (KB)");
			ui.inputMagnitude->setItemText(2, "Megabyte (MB)");
			ui.inputMagnitude->setItemText(3, "Gigabyte (GB)");
			ui.inputMagnitude->setItemText(4, "Terabyte (TB)");
			ui.inputMagnitude->setItemText(5, "Petabyte (PB)");
			ui.inputMagnitude->setItemText(6, "Exabyte (EB)");
			ui.inputMagnitude->setItemText(7, "Zettabyte (ZB)");
			ui.inputMagnitude->setItemText(8, "Yottabyte (YB)");
		}
	}
}

void Toolboxal_UI::output_Bit_Checked() const
{
	if (ui.outputUseBit->isCheckable())
	{
		if (ui.outputUseBit->isChecked())
		{
			ui.outputUseBinary->setCheckable(false);
			ui.outputUseBoth->setCheckable(false);

			ui.outputMagnitude->setItemText(0, "Bit (b)");
			ui.outputMagnitude->setItemText(1, "Kilobit (Kb)");
			ui.outputMagnitude->setItemText(2, "Megabit (Mb)");
			ui.outputMagnitude->setItemText(3, "Gigabit (Gb)");
			ui.outputMagnitude->setItemText(4, "Terabit (Tb)");
			ui.outputMagnitude->setItemText(5, "Petabit (Pb)");
			ui.outputMagnitude->setItemText(6, "Exabit (Eb)");
			ui.outputMagnitude->setItemText(7, "Zettabit (Zb)");
			ui.outputMagnitude->setItemText(8, "Yottabit (Yb)");
		}
		else
		{
			ui.outputUseBinary->setCheckable(true);
			ui.outputUseBoth->setCheckable(true);

			ui.outputMagnitude->setItemText(0, "Byte (B)");
			ui.outputMagnitude->setItemText(1, "Kilobyte (KB)");
			ui.outputMagnitude->setItemText(2, "Megabyte (MB)");
			ui.outputMagnitude->setItemText(3, "Gigabyte (GB)");
			ui.outputMagnitude->setItemText(4, "Terabyte (TB)");
			ui.outputMagnitude->setItemText(5, "Petabyte (PB)");
			ui.outputMagnitude->setItemText(6, "Exabyte (EB)");
			ui.outputMagnitude->setItemText(7, "Zettabyte (ZB)");
			ui.outputMagnitude->setItemText(8, "Yottabyte (YB)");
		}
	}
}

void Toolboxal_UI::output_Binary_Checked() const
{
	if (ui.outputUseBinary->isCheckable())
	{
		if (ui.outputUseBinary->isChecked())
		{
			ui.outputUseBit->setCheckable(false);
			ui.outputUseBoth->setCheckable(false);

			ui.outputMagnitude->setItemText(0, "Byte (B)");
			ui.outputMagnitude->setItemText(1, "Kibibyte (KiB)");
			ui.outputMagnitude->setItemText(2, "Mebibyte (MiB)");
			ui.outputMagnitude->setItemText(3, "Gibibyte (GiB)");
			ui.outputMagnitude->setItemText(4, "Tebibyte (TiB)");
			ui.outputMagnitude->setItemText(5, "Pebibyte (PiB)");
			ui.outputMagnitude->setItemText(6, "Exbibyte (EiB)");
			ui.outputMagnitude->setItemText(7, "Zebibyte (ZiB)");
			ui.outputMagnitude->setItemText(8, "Yobibyte (YiB)");
		}
		else
		{
			ui.outputUseBit->setCheckable(true);
			ui.outputUseBoth->setCheckable(true);

			ui.outputMagnitude->setItemText(0, "Byte (B)");
			ui.outputMagnitude->setItemText(1, "Kilobyte (KB)");
			ui.outputMagnitude->setItemText(2, "Megabyte (MB)");
			ui.outputMagnitude->setItemText(3, "Gigabyte (GB)");
			ui.outputMagnitude->setItemText(4, "Terabyte (TB)");
			ui.outputMagnitude->setItemText(5, "Petabyte (PB)");
			ui.outputMagnitude->setItemText(6, "Exabyte (EB)");
			ui.outputMagnitude->setItemText(7, "Zettabyte (ZB)");
			ui.outputMagnitude->setItemText(8, "Yottabyte (YB)");
		}
	}
}

void Toolboxal_UI::output_Both_Checked() const
{
	if (ui.outputUseBoth->isCheckable())
	{
		if (ui.outputUseBoth->isChecked())
		{
			ui.outputUseBit->setCheckable(false);
			ui.outputUseBinary->setCheckable(false);

			ui.outputMagnitude->setItemText(0, "Bit (b)");
			ui.outputMagnitude->setItemText(1, "Kibibit (Kib)");
			ui.outputMagnitude->setItemText(2, "Mebibit (Mib)");
			ui.outputMagnitude->setItemText(3, "Gibibit (Gib)");
			ui.outputMagnitude->setItemText(4, "Tebibit (Tib)");
			ui.outputMagnitude->setItemText(5, "Pebibit (Pib)");
			ui.outputMagnitude->setItemText(6, "Exbibit (Eib)");
			ui.outputMagnitude->setItemText(7, "Zebibit (Zib)");
			ui.outputMagnitude->setItemText(8, "Yobibit (Yib)");
		}
		else
		{
			ui.outputUseBit->setCheckable(true);
			ui.outputUseBinary->setCheckable(true);

			ui.outputMagnitude->setItemText(0, "Byte (B)");
			ui.outputMagnitude->setItemText(1, "Kilobyte (KB)");
			ui.outputMagnitude->setItemText(2, "Megabyte (MB)");
			ui.outputMagnitude->setItemText(3, "Gigabyte (GB)");
			ui.outputMagnitude->setItemText(4, "Terabyte (TB)");
			ui.outputMagnitude->setItemText(5, "Petabyte (PB)");
			ui.outputMagnitude->setItemText(6, "Exabyte (EB)");
			ui.outputMagnitude->setItemText(7, "Zettabyte (ZB)");
			ui.outputMagnitude->setItemText(8, "Yottabyte (YB)");
		}
	}
}