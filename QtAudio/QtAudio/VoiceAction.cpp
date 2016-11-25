#include "VoiceAction.h"

VoiceAction::VoiceAction(string name, string path, string words)
{
	this->name = name;
	(path.find(".exe") == string::npos) ? exe = true : exe = false;
	pathToFile = path;
	size_t separator1 = 0;
	auto separator2 = words.find(';');
	while (separator2 != string::npos) {
		string word(words, separator1, separator2 - separator1);
		associateWords.push_back(word);
		separator1 = separator2;
		separator2 = words.find(';', ++separator1);
	}
}

string VoiceAction::command() {
	if (exe) {
		return pathToFile;
	}
	else
	{
		return "explorer " + pathToFile;
	}
}