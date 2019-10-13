#include "Examinee.h"
string cutstring(string& s) {
	int pos = s.find(',');
	string a;
	string b = "0";
	a = s.substr(0, pos);
	s.erase(0, pos + 1);
	if (a == "") return b;
	return a;
}
Examinee ReadExaminee(string line_info) {
		Examinee temp;
		temp.id = cutstring(line_info);
		temp.math = stof(cutstring(line_info));
		temp.literary = stof(cutstring(line_info));
		temp.physic = stof(cutstring(line_info));
		temp.chemistry = stof(cutstring(line_info));
		temp.biology = stof(cutstring(line_info));
		temp.history = stof(cutstring(line_info));
		temp.geography = stof(cutstring(line_info));
		temp.civic_education = stof(cutstring(line_info));
		temp.natural_science = stof(cutstring(line_info));
		temp.social_science = stof(cutstring(line_info));
		temp.foreign_language = stof(cutstring(line_info));
		return temp;
}

vector<Examinee> ReadExamineeList(string file_name) {
	vector<Examinee> t;
	fstream f;
	string temp;
	f.open(file_name, ios::in);
	getline(f, temp);
	while (!f.eof())
	{
		getline(f, temp);		
		cout << temp << endl;
		t.push_back(ReadExaminee(temp));
	}
	f.close();
	return t;
}
void WriteSumOfScore(vector<Examinee> examinee_list, string out_file_name) {
	fstream f;
	f.open(out_file_name, ios::out);
	//duyet mang
	vector<Examinee>::iterator i; // Khai báo con trỏ để duyệt
	for (i = examinee_list.begin(); i != examinee_list.end(); i++) {
		i->natural_science = i->physic + i->chemistry + i->biology;
		i->social_science = i->history + i->geography + i->civic_education;
		f << i->id << " " << i->math + i->literary + i->foreign_language + i->natural_science + i->social_science << endl;
	}
	f.close();
}

