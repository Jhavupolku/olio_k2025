#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "student.h"

using namespace std;

int main ()
{
    int selection =0;
    vector<Student>studentList;

    do
    {
        cout<<endl;
        cout<<"Select"<<endl;
        cout<<"Add students = 0"<<endl;
        cout<<"Print all students = 1"<<endl;
        cout<<"Sort and print students according to Name = 2"<<endl;
        cout<<"Sort and print students according to Age = 3"<<endl;
        cout<<"Find and print student = 4"<<endl;
        cin>>selection;

        switch(selection)
        {
        case 0:
            // Kysy käyttäjältä uuden opiskelijan nimi ja ikä
            string Name;
            int Age;
            cout << "Anna opiskelijan nimi: ";
            cin >> Name;
            cout << "Anna opiskelijan ika: ";
            cin >> Age;

            // Lisää uusi student StudentList vektoriin.
            studentList.push_back(Student(Name, Age));
            break;

        case 1:
            // Tulosta StudentList vektorin kaikkien opiskelijoiden nimet.
            if (studentList.empty()) {
                cout << "Ei oppilaita" << endl;
            } else {
                for (const auto& student : studentList) {
                    student.printStudentInfo();
                }
            }
            break;

        case 2:
            // Järjestä StudentList vektorin Student oliot nimen mukaan algoritmikirjaston sort funktion avulla
            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getName() < b.getName();
            });
            // ja tulosta printStudentInfo() funktion avulla järjestetyt opiskelijat
            cout << "Oppilaat nimen mukaan jarjestettyna" << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 3:
            // Järjestä StudentList vektorin Student oliot iän mukaan algoritmikirjaston sort funktion avulla
            sort(studentList.begin(), studentList.end(), [](const Student& a, const Student& b) {
                return a.getAge() < b.getAge();
            });
            // ja tulosta printStudentInfo() funktion avulla järjestetyt opiskelijat
            cout << "Oppilaat ian mukaan jarjestettyna" << endl;
            for (const auto& student : studentList) {
                student.printStudentInfo();
            }
            break;

        case 4:
            // Kysy käyttäjältä opiskelijan nimi
            string nameToFind;
            cout << "Anna opiskelijan nimi: ";
            cin >> nameToFind;

            // Etsi studentListan opiskelijoista algoritmikirjaston find_if funktion avulla löytyykö käyttäjän antamaa nimeä
            auto it = find_if(studentList.begin(), studentList.end(), [&nameToFind](const Student& s) {
                return s.getName() == nameToFind;
            });

            // listalta. Jos löytyy, niin tulosta opiskelijan tiedot.
            if (it != studentList.end()) {
                cout << "Opiskelija loytynyt:" << endl;
                it->printStudentInfo(); // Correct way to call the method for the found student
            } else {
                cout << "Opiskelijaa ei loytynyt" << endl;
            }
            break;
        }
        default:
            cout<< "Wrong selection, stopping..."<<endl;
            break;
        }
    } while (selection < 5);

return 0;
