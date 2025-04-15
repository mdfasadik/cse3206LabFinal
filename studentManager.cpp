#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <gtest/gtest.h>

using namespace std;

class StudentManager
{
private:
    vector<string> students;
    StudentManager() {}

public:
    static StudentManager &getInstance()
    {
        static StudentManager instance;
        return instance;
    }

    void addStudent(string name)
    {
        students.push_back(name);
    }

    bool removeStudent(string name)
    {
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i] == name)
            {
                students.erase(students.begin() + i);
                return true;
            }
        }
        return false;
    }

    vector<string> getStudents()
    {
        return students;
    }

    void clear()
    {
        students.clear();
    }

    void displayStudents()
    {
        cout << "Student List:\n";
        for (string name : students)
        {
            cout << "- " << name << "\n";
        }
    }
};

// -------------------- GTest Cases --------------------

TEST(StudentManagerTest, AddStudent)
{
    StudentManager::getInstance().clear();
    StudentManager::getInstance().addStudent("Sadik");
    vector<string> list = StudentManager::getInstance().getStudents();
    EXPECT_EQ(list.size(), 1);
    EXPECT_EQ(list[0], "Sadik");
}

TEST(StudentManagerTest, DisplayStudents)
{
    StudentManager::getInstance().clear();
    StudentManager::getInstance().addStudent("Tom");
    StudentManager::getInstance().addStudent("Jerry");
    vector<string> list = StudentManager::getInstance().getStudents();
    EXPECT_EQ(list.size(), 2);
    EXPECT_EQ(list[0], "Tom");
    EXPECT_EQ(list[1], "Jerry");
}

int main(int argc, char **argv)
{
    cout << "Running tests...\n";
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
