#include <iostream>
using namespace std;

struct Student
{
    int id;
    string name;
    Student *prev, *next;
    Student(int i, string n) : id(i), name(n), prev(nullptr), next(nullptr) {}
};

class ClassList
{
private:
    Student *head = nullptr;

public:
    void addStudent(int id, string name)
    {
        Student *newStudent = new Student(id, name);
        if (!head)
            head = newStudent;
        else
        {
            Student *temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newStudent;
            newStudent->prev = temp;
        }
    }

    void displayStudents()
    {
        for (Student *temp = head; temp; temp = temp->next)
            cout << "ID: " << temp->id << ", Name: " << temp->name << endl;
    }

    int countStudents()
    {
        int count = 0;
        for (Student *temp = head; temp; temp = temp->next)
            count++;
        return count;
    }

    void searchStudent(int id)
    {
        for (Student *temp = head; temp; temp = temp->next)
            if (temp->id == id)
            {
                cout << "Found: " << temp->name << " (ID: " << temp->id << ")\n";
                return;
            }
        cout << "Student not found.\n";
    }

    void deleteStudent(int id)
    {
        Student *temp = head;
        while (temp && temp->id != id)
            temp = temp->next;
        if (!temp)
            return;
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        if (temp == head)
            head = temp->next;
        delete temp;
    }

    ~ClassList()
    {
        while (head)
        {
            Student *temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main()
{
    ClassList classroom;
    classroom.addStudent(1, "Rahul");
    classroom.addStudent(2, "Priya");
    classroom.addStudent(3, "Arjun");
    classroom.addStudent(4, "Neha");

    cout << "Students in class:\n";
    classroom.displayStudents();
    cout << "Total Students: " << classroom.countStudents() << endl;

    classroom.searchStudent(3);
    classroom.deleteStudent(2);

    cout << "After removal:\n";
    classroom.displayStudents();
    return 0;
}
