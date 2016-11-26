#include "AddAction.h"


AddAction::AddAction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	

	this->setCentralWidget(ui.verticalLayoutWidget);
	
}

void AddAction::updateList(std::vector<VoiceAction>* commands) {
	QStringList commandList;
	for (auto i : *commands) {
		commandList << i.getName().data();
	}
	model = new QStringListModel(commandList);
	ui.listView->setModel(model);
	this->commands = commands;
}

void AddAction::chooseCom(QModelIndex mInd) {
	QMessageBox q;
	q.setText(mInd.data().toString());
	q.exec();

	q.setText(commands->at(0).getName().data());
	q.exec();

	ui.lineEdit_command->clear();
	ui.lineEdit_path->clear();
	for (auto i : *commands) {
		q.setText(i.getName().data());
		q.exec();
		if (i.getName() == mInd.data().toString().toStdString()) {
			ui.lineEdit_path->setText(i.getPath().data());
			for (auto j : i.getWords()) {
				ui.lineEdit_command->setText(ui.lineEdit_command->text() + j.data() + ";");
			}
			break;
		}
	}
}

AddAction::~AddAction()
{
}
