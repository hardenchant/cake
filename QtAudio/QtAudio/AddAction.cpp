#include "AddAction.h"
#include <qstringlistmodel.h>
#include <qtableview.h>
#include <qjsonobject.h>

AddAction::AddAction(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	
	QStringList numbers;
	numbers << "One" << "Two" << "Three" << "Four" << "Five" << "Six";

	QAbstractItemModel *model = new QStringListModel(numbers);
	
	ui.listView->setModel(model);
	
	this->setCentralWidget(ui.verticalLayoutWidget);
	
}

void AddAction::updateList(std::vector<VoiceAction>* commands) {
	QStringList commandList;
	for (auto i : *commands) {
		commandList << i.getName().data();
	}
	QAbstractItemModel *model = new QStringListModel(commandList);
	ui.listView->setModel(model);
	this->show();
}

AddAction::~AddAction()
{
}
