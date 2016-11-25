#pragma once

#include <QWidget>
#include "ui_AddAction.h"

class AddAction : public QWidget
{
	Q_OBJECT

public:
	AddAction(QWidget *parent = Q_NULLPTR);
	~AddAction();
private:
	Ui::AddAction ui;
};
