#include "QtAudio.h"
#include <qtextcodec.h>


QtAudio::QtAudio(QWidget *parent)
	: QMainWindow(parent)
{ 
	ui.setupUi(this);
	this->setCentralWidget(ui.gridLayoutWidget);
	ui.button_start->hide();
	ui.button_stop->hide();
	ui.button_recognize->hide();
	ui.label->hide();

	addact_wnd.setWindowModality(Qt::ApplicationModal);
	auto menu_settings = ui.menuBar->addMenu("Settings");
	auto action_addaction = menu_settings->addAction("Add voice action");
	connect(action_addaction, SIGNAL(triggered()), &addact_wnd, SLOT(show()));
	connect(this, SIGNAL(sendCommands(std::vector<VoiceAction>*)), &addact_wnd, SLOT(updateList(std::vector<VoiceAction>*)));
	set_audio_config();
	loadFileCfg();
	
}
void QtAudio::onPushButton_startRecord() {
	audioRecorder->record();
	ui.textOut->setText("Recording");
}
void QtAudio::onPushButton_stopRecord() {
	audioRecorder->stop();
	ui.textOut->setText("Stop recording. Recognizing");
}
void QtAudio::onPushButton_recognize() {
	QFile f(audioFilePath);
	if (f.exists()) {
		if (f.size() > 1000000) {
			ui.textOut->setText("Too big file!");
			return;
		}
	}
	else return;
	/*playing
	mPlayer = new QMediaPlayer(this);
	mPlayer->setMedia(QUrl::fromLocalFile(PATH));
	mPlayer->play();*/
	
	auto vc = mr::parseRequest(mr::recognize(audioFilePath.toStdString()));

	if (vc.empty()) {
		ui.textEdit->clear();
		ui.textEdit->setText("Not recognized!");
	}
	else {
		ui.textEdit->clear();
		for (auto it : vc) {
			ui.textEdit->setText(QString::fromStdString(it) + '\n' + ui.textEdit->toPlainText());
		}
	}
	for (auto it_c : commands) {
		for (auto it_vc : vc) {
			for (auto it_c_vc : it_c.getWords()) {
				if (it_vc == it_c_vc) {	
					ui.textEdit->setText(it_c.command().data());
					QProcess* myproc = new QProcess(this);
					myproc->start(it_c.command().data());
				}
			}
		}
	}
}

//stopRecord() + recognize()
void QtAudio::stopAndRecognize() {
	onPushButton_stopRecord();
	onPushButton_recognize();
}

// SOUND FORMAT AND PATH
void QtAudio::set_audio_config() {
	audioFilePath = QApplication::applicationDirPath() + "/speech.wav";

	/*QAudioFormat qaf;
	qaf.setCodec("audio/pcm");
	qaf.setChannelCount(1);
	qaf.setSampleSize(16);
	qaf.setSampleType(QAudioFormat::UnSignedInt);
	qaf.setByteOrder(QAudioFormat::LittleEndian);

	QAudioDeviceInfo infoIn(QAudioDeviceInfo::defaultInputDevice());
	if (!infoIn.isFormatSupported(qaf)) {
	qaf = infoIn.nearestFormat(qaf);
	}
	QAudioDeviceInfo infoOut(QAudioDeviceInfo::defaultOutputDevice());
	if (!infoOut.isFormatSupported(qaf)) {
	qaf = infoOut.nearestFormat(qaf);
	}

	auto aInp = new QAudioInput(infoIn, qaf, this);
	auto aOut = new QAudioOutput(infoOut, qaf, this);

	m_input = aInp->start();
	m_output = aOut->start();



	mbuffer = new char[3200];

	m_input->read(mbuffer, 3200);
	m_output->write(mbuffer, 3200);

	*/
	audioRecorder = new QAudioRecorder(this);

	audioSettings.setCodec("audio/PCM");
	audioSettings.setQuality(QMultimedia::HighQuality);
	audioRecorder->setEncodingSettings(audioSettings);

	audioRecorder->setOutputLocation(QUrl::fromLocalFile(audioFilePath));

}

// FILE ENCODING IS UTF8 (WITHOUT BOM)
void QtAudio::loadFileCfg() {
	QString qs = QApplication::applicationDirPath() + "/data.txt";
	ifstream file(qs.toStdString());
	if (!file) {
		return;
	}
	string name, path, words;
	std::getline(file, name);
	while (!file.eof()) {
		std::getline(file, path);
		std::getline(file, words);
		VoiceAction vc(name, path, words);
		commands.push_back(vc);
		std::getline(file, name);
	}
	file.close();
	emit sendCommands(&commands);
}

void QtAudio::showDebugOptions(int check) {
	if (check) {
		ui.button_start->show();
		ui.button_stop->show();
		ui.button_recognize->show();
		ui.label->show();
	}
	else {
		ui.button_start->hide();
		ui.button_stop->hide();
		ui.button_recognize->hide();
		ui.label->hide();
	}
}