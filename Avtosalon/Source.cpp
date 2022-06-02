
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<conio.h>
#include<string>
#include<vector>
#include<Windows.h>

using namespace std;

class Car
{
public:
    string name;
    uint32_t age;
    double engine;
    double price;

    Car()
    {
        this->name = "";
        this->age = 0;
        this->engine = 0;
        this->price = 0;
    }

    Car(string name, uint32_t age, double engine, double price) :Car()
    {
        this->name = name;
        this->age = age;
        this->engine = engine;
        this->price = price;
    }

    string GetName() {
        return this->name;
    }

    friend istream& operator >> (istream& in, Car& object)
    {
        cout << "Name: ";
        in >> object.name;
        cout << "Age: ";
        in >> object.age;
        cout << "Engine: ";
        in >> object.engine;
        cout << "Price: ";
        in >> object.price;
        return in;
    }

    friend ostream& operator << (ostream& out, Car object)
    {
        out << "Name: " << object.name << endl;
        out << "Age: " << object.age << endl;
        out << "Engine: " << object.engine << endl;
        out << "Price: " << object.price << endl << endl;
        return out;
    }

    ~Car()
    {
        this->name.clear();
        this->age = 0;
        this->engine = 0;
        this->price = 0;
    }
};

class Avtosalon
{
public:
    vector<Car> cars;
    size_t length = 0;
    int num = 0;

    void AddCar(Car car)
    {
        cars.push_back(car);
    }

    void Show()
    {
        for (auto& item : cars)
        {
            cout << item << endl;
        }
    }

    void SortCarsDown() {
        sort(cars.begin(), cars.end(), [](Car const& с1, Car const& с2) { return с1.name < с2.name; });
    }

    void SortCarsUp() {
        sort(cars.begin(), cars.end(), [](Car const& с1, Car const& с2) { return с2.name < с1.name; });
    }

    void Find(string name)
    {
        auto iter = std::find_if(cars.begin(), cars.end(), [=](Car& s) { return s.name == name; });
        if (iter != cars.end())
            cout << *iter << endl;
        else
            cout << "Object not found!.\n";
    }

    void DeleteCar(string name)
    {
        auto iter = std::find_if(cars.begin(), cars.end(), [=](Car& s) { return s.name == name; });
        if (iter != cars.end())
            cars.erase(iter);
        else
            cout << "Object not found!.\n";
    }
};

int main()
{
    Avtosalon avtosalon;

    while (true)
    {
        system("cls");
        cout << "MENU" << endl << endl;
        cout << "1 - Add car" << endl;
        cout << "2 - Show cars" << endl;
        cout << "3 - Sort cars(up)" << endl;
        cout << "4 - Sort cars(down)" << endl;
        cout << "5 - Find" << endl;
        cout << "6 - Delete car" << endl;
        cout << "7 - Exit" << endl << endl;
        cout << "Enter: ";
        int menu;
        cin >> menu;

        switch (menu)
        {
        case 1:
        {
            system("cls");
            Car car;
            cin >> car;
            avtosalon.AddCar(car);
        }break;

        case 2:
        {
            avtosalon.Show();
        }break;

        case 3:
        {
            avtosalon.SortCarsUp();
            avtosalon.Show();
        }break;

        case 4:
        {
            avtosalon.SortCarsDown();
            avtosalon.Show();
        }break;

        case 5:
        {
            string name;
            cout << "Enter>";
            cin >> name;
            avtosalon.Find(name);
        }break;

        case 6:
        {
            string name;
            cout << "Enter>";
            cin >> name;
            avtosalon.DeleteCar(name);
        }break;
        }

        system("pause");
    }

    return 0;
}