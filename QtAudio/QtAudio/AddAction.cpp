#include "AddAction.h"
#include <qstringlistmodel.h>
AddAction::AddAction(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QAction *qac = new QAction("text", ui.listView);
	QStringList numbers;
	numbers << "One" << "Two" << "Three" << "Four" << "Five" << "Six";
	
	QAbstractItemModel *model = new QStringListModel(numbers);
	ui.listView->setModel(model);
	
}

AddAction::~AddAction()
{
}
