
class Student
{
private:
    int roll;
    char* name;

};

auto comp = [](const Student& s1, const Student& s2){
    return s1.roll<s2.roll;
};

map<Student, vector<Student>, decltype(comp)> mp(comp);