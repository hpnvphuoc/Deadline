#ifndef EXAMINEE_H_
#define EXAMINEE_H_
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
struct Examinee
{
	string id;
	float math, literary, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};
Examinee ReadExaminee(string line_info);
vector<Examinee> ReadExamineeList(string file_name);
void WriteSumOfScore(vector<Examinee> examinee_list, string out_file_name);

#endif // !EXAMINEE_H_
