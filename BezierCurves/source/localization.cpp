#include "pch.h"

#include "localization.h"

namespace localization
{
	const char* const language_list[] = {"English", "Russian"};
	vector<string> labels = {};
	vector<map<string, string>> locales = {};

	void initLocale()
	{
		labels = {
			"title",
			"save",
			"load",
			"control",
			"settings",
			"saveIn",
			"fileName",
			"errorSave",
			"loadFrom",
			"errorLoad",
			"controlPanel",
			"curveType",
			"normal",
			"square",
			"cubic",
			"subcurves",
			"showSubcurves",
			"navigation",
			"home",
			"toCurve",
			"showGrid",
			"showBase",
			"erase",
			"gridColor",
			"precision",
			"apply",
			"reset",
			"lang"
		};

		locales.resize(2);

		locales[0] = {
			{labels[0], "Bezier curves"},
			{labels[1], "Save"},
			{labels[2], "Load"},
			{labels[3], "Control"},
			{labels[4], "Settings"},
			{labels[5], "Save in file"},
			{labels[6], "File name"},
			{labels[7], "Error while saving!"},
			{labels[8], "Load from file"},
			{labels[9], "Error while loading from file!\nVerify file name\nand save format"},
			{labels[10], "Control panel"},
			{labels[11], "Curve type:"},
			{labels[12], "Normal"},
			{labels[13], "Square"},
			{labels[14], "Cubic"},
			{labels[15], "Subcurves:"},
			{labels[16], "Show subcurves"},
			{labels[17], "Navigation:"},
			{labels[18], "Home"},
			{labels[19], "To curve"},
			{labels[20], "Show grid"},
			{labels[21], "Show base points"},
			{labels[22], "Erase all"},
			{labels[23], "Grid color"},
			{labels[24], "Precision"},
			{labels[25], "Apply"},
			{labels[26], "Reset"},
			{labels[27], "Language"}
		};

		locales[1] = {
			{labels[0], u8"������ �����"},
			{labels[1], u8"���������"},
			{labels[2], u8"���������"},
			{labels[3], u8"����������"},
			{labels[4], u8"���������"},
			{labels[5], u8"��������� � ����"},
			{labels[6], u8"��� �����"},
			{labels[7], u8"������ ��� ���������� � ����!"},
			{labels[8], u8"��������� �� �����"},
			{labels[9], u8"������ ��� �������� �� �����!\n��������� ��������\n� ������������ �������"},
			{labels[10], u8"������ ����������"},
			{labels[11], u8"��� ������:"},
			{labels[12], u8"�������"},
			{labels[13], u8"������������"},
			{labels[14], u8"����������"},
			{labels[15], u8"���������:"},
			{labels[16], u8"�������� ���������"},
			{labels[17], u8"���������:"},
			{labels[18], u8"�����"},
			{labels[19], u8"� ������"},
			{labels[20], u8"�������� �����"},
			{labels[21], u8"�������� ������� �����"},
			{labels[22], u8"������� ��"},
			{labels[23], u8"���� �����"},
			{labels[24], u8"��������"},
			{labels[25], u8"���������"},
			{labels[26], u8"�����"},
			{labels[27], u8"����"}
		};
	}

	const char* getLocStr(string name)
	{
		auto locale_string = locales[language].find(name);
		return (locale_string != locales[language].end() ? locale_string->second.c_str() : nullptr);
	}
} //namespace localization
