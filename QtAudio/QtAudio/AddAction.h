#pragma once

#include <qmainwindow.h>
#include "ui_AddAction.h"
#include <vector>
#include "VoiceAction.h"

class AddAction : public QMainWindow
{
	Q_OBJECT

public:
	AddAction(QWidget *parent = Q_NULLPTR);
	~AddAction();
private:
	Ui::AddAction ui;
public slots:
	void updateList(std::vector<VoiceAction>* commands);
};
