/*Створіть клас Passport (паспорт), який буде містити паспортну інформацію про громадянина України.За допомогою механізму успадкування, реалізуйте клас ForeignPassport
(закордонний паспорт) похідний від Passport. Нагадаємо, що закордонний паспорт містить крім паспортних даних, також дані про візи, номер закордонного паспорта.*/
#include <iostream>
#include <string>
using namespace std;
class Passport// клас Passport (паспорт)
{
protected:
    string name;//ім'я
    string surname;//прізвище
    string dateOfBirthday;//дата народження
    string placeOfBirth;//місце народження
    string passport_series;// серія паспорта
    int passport_number = 0;//номер паспорта
    int personal_number = 0;//ідентифікаційний код
    string citizenship_country;//громадянство
    string gender;//стать
public:
    Passport() {}
    void Input() {//метод класу  для вводу даних 
        cout << "Name- "; getline(cin, name);
        cout << "Surname- "; getline(cin, surname);
        cout << "Date of birthday- "; getline(cin, dateOfBirthday);
        cout << "Place of birth- "; getline(cin, placeOfBirth);
        cout << "Passport series- "; getline(cin, passport_series);
        cout << "Passport number- "; cin >> passport_number;
        cout << "Personal number- "; cin >> personal_number; cin.ignore(32767, '\n');//використовуємо cin.ignore для видалення пробілу з пам'яті
        cout << "Citizenship country- "; getline(cin, citizenship_country);
        cout << "Gender- "; getline(cin, gender);
    }


    void Output() {//метод класу  для виводу даних 
        cout << "Name- " << name << endl;
        cout << "Surname- " << surname << endl;
        cout << "Date of birthday- " << dateOfBirthday << endl;
        cout << "Place of birth- " << placeOfBirth << endl;
        cout << "Passport series- " << passport_series << endl;
        cout << "Passport number- " << passport_number << endl;
        cout << "Identification code- " << personal_number << endl;
        cout << "Citizenship country- " << citizenship_country << endl;
        cout << "Gender- " << gender << endl;
    }


    ~Passport() {}
};


class ForeignPassport : protected Passport//клас ForeignPassport (закордонний паспорт) похідний від Passport
{
protected:
    string dataVisa;//дані про візи
    int foreignNum = 0;//номер закордонного паспорта
public:
    ForeignPassport() {}
    void Input() {//метод класу  для вводу даних 
        Passport::Input();
        cout << "Visa's data- "; cin >> dataVisa;
        cout << "Passport foreign number- "; cin >> foreignNum;
    }


    void Output() {//метод класу  для виводу даних 
        Passport::Output();
        cout << "Visa's data- " << dataVisa << endl;
        cout << "Passport foreign number- " << foreignNum << endl;
    }


    ~ForeignPassport() {}
};


int main()
{
    ForeignPassport A;//об'єкт класу  ForeignPassport
    A.Input();
    A.Output();
}