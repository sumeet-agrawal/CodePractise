/*Write the following program: Create a struct that holds a student’s first name and grade (on a scale of 0-100).
Ask the user how many students they want to enter. Create a std::vector to hold all of the students.
Then prompt the user for each name and grade. Once the user has entered all the names and grade pairs,
sort the list by grade (highest first). Then print all the names and grades in sorted order.*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct student_details
{
	std::string name;
	int grade;
};

using vector_type = std::vector<student_details>;

int getNumberOfStudents()
{
	int totalStudents{};
	do
	{
		std::cout << "Enter total number of students: ";
		std::cin >> totalStudents;
	} while (totalStudents <= 0);
	return totalStudents;
}

vector_type getStudents(int totalStudents)
{
	vector_type students(static_cast<vector_type::size_type>(totalStudents));
	for (auto& student : students)
	{
		std::cin >> student.name >> student.grade;
	}
	return students;
}

bool compareStudents(const student_details& a, const student_details& b)
{
	return (a.grade > b.grade);
}

void printStudent(const student_details& student)
{
	std::cout << student.name << " got a grade of " << student.grade << "\n";
}

int main()
{
	int total_students{ getNumberOfStudents() };
	auto students{ getStudents(total_students) };
	std::sort(students.begin(), students.end(), compareStudents);
	std::for_each(students.begin(), students.end(), printStudent);
	return 0;
}