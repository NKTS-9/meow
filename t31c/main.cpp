#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include <cstdlib>
#include <math.h>

using namespace std;

struct Kino
{
int id;
string name;
int year;
string genre;
string director;
int length;
};


void Read(Kino kin[]);
void Display(Kino kin[], int r);
void Edit(Kino kin[]);
int Search(Kino kin[]);
void Save(Kino kin[], int maxhp);


int Menu()
{
    system("cls");

    cout << endl;
    cout << "1: Read" << endl
        << "2: Display" << endl
        << "3: Edit" << endl
        << "4: Search" << endl
        << "5: Save" << endl


        << "0: Exit" << endl
        << endl << "Enter code: ";
    char ch;
    ch = _getch();
    return ch;
}
int main()
{
    Kino *kin = new  Kino[30];
    int i = 1, maxyear = -1, r=1; int R;

    while (i == 1) {
        char ch = Menu();
        switch (ch) {
        case '1': Read(kin); break;
        case '2': Display(kin, r); break;
        case '3': Edit(kin); break;
        case '4': maxyear = Search(kin); break;
		case '5': if (maxyear>=0)
		{
		    Save(kin, maxyear);
		}
		  else
          {
            cout << " Access denied " << endl;
            cout << "Press any key." << endl;
            _getch();
            }
          break;
        case '7': {delete[]kin; kin = NULL; exit(1); } break;
        }
    }

}

void Read(Kino kin[]) {

	ifstream Input;
	Input.open("kino.txt");
	if (!Input) {
		cout << "Read: Error " << endl
			<< "Press any key" << endl;
		_getch();
	}
	else {
		for (int i = 0; i <= 10; i++) {
			kin[i].id = i + 1;
			Input >> kin[i].name
				>> kin[i].year
				>> kin[i].genre
				>> kin[i].director
                >> kin[i].length;
		}
		Input.close();
		cout << "Read: Success!" << endl << "Press any key.";
		_getch();
	}
}


void Display(Kino kin[], int r)
{
    if (r == 1){
    cout << "\n Mooovies: \n" << endl;
    cout.setf(std::ios::left);
    cout.fill('_'); cout.width(30); cout << "|1.ID|";
    cout.fill('_'); cout.width(30); cout << "|2.Name|";
    cout.fill('_'); cout.width(30); cout << "|3.Year|";
    cout.fill('_'); cout.width(30); cout << "|4.Genre|";
    cout.fill('_'); cout.width(30); cout << "|5.Director|";
    cout.fill('_'); cout.width(30); cout << "|6.Length|" << endl;


    for (int i = 0; i < 10; i++) {
        cout.fill('_'); cout.width(30); cout << kin[i].id;
        cout.fill('_'); cout.width(30); cout << kin[i].name;
        cout.fill('_'); cout.width(30); cout << kin[i].year;
        cout.fill('_'); cout.width(30); cout << kin[i].genre;
        cout.fill('_'); cout.width(30); cout << kin[i].director;
        cout.fill('_'); cout.width(30); cout << kin[i].length << endl;
    }

        cout << endl <<"Press any key.";
        _getch();
    }
    else {
        cout << endl <<"Error! Read data first.";
        cout << endl <<"Press any key.";
        _getch();
    }
}
void Edit(Kino kin[]) {
    int line;
    do {
        cout << "\nNumber of line ";
        cin >> line;
        line = line - 1;
    } while (line < 0 || line >= 6);

    int i = 1;
    while (i == 1) {
        cout << "\nNumber of column ";
        int column;
        cin >> column;

        cout << "Change ";

        switch (column) {
        case 1: {cout << kin[line].id << ": "; cin >> kin[line].id; i=0;                            i = 0; } break;
        case 2: {cout << kin[line].name << ": "; cin >> kin[line].name; i=0;                            i = 0; } break;
        case 3: {cout << kin[line].year << ": "; cin >> kin[line].year; i = 0;                             } break;
        case 4: {cout << kin[line].genre << ": "; cin >> kin[line].genre; i = 0;
                            } break;
        case 5: {cout << kin[line].director << ": "; cin >> kin[line].director; i = 0;
        case 6: {cout << kin[line].length << ": "; cin >> kin[line].length; i = 0;                           } break;
        default: cout << "Error!";
        }
    }
}
}

int Search (Kino kin[])
{
    int maxyear = 0;
    int Z = kin[0].year;
    for (int i=1;i <=13;i++)
    {
        if (Z<= kin[i].year)
        {
            Z = kin[i].year;
            maxyear=i;
        }
    }

    cout << "\n \t The most recent movie: " << endl;
    cout << kin[maxyear].name << " |"
         << kin[maxyear].year << " |"
         << kin[maxyear].genre << " |"
         << kin[maxyear].director << " |"
         << kin[maxyear].length << " |" << endl << "Press any key.";

         _getch();
         return maxyear;

}

void Save(Kino kin[], int maxyear) {


	string outputfilename;
	cout << "\nOut.txt?" << "\n\ty - Yeep\n\t0. 							Nope\n";
	char ch;
	ch = _getch();
	if (ch == 'y') outputfilename = "Out.txt";
	if (ch != 'y') {
		cout << "Enter a output file name\n";
		cin >> outputfilename;
	}

	ofstream Output;
	Output.open(outputfilename.c_str());
	Output.setf(std::ios::left);
	Output.fill(' '); Output.width(15); Output << "##";
	Output.fill(' '); Output.width(15); Output << "1. name";
	Output.fill(' '); Output.width(15); Output << "2. year";
	Output.fill(' '); Output.width(15); Output << "3. genre";
	Output.fill(' '); Output.width(15); Output << "4. director";
	Output.fill(' '); Output.width(15); Output << "4. length"<< endl;

	for (int i = 0; i <= 9; i++) {
		Output.fill(' '); Output.width(15); Output << 					kin[i].id;
		Output.fill('_'); Output.width(15); Output << 					kin[i].name;
		Output.fill('_'); Output.width(15); Output << 					kin[i].year;
		Output.fill('_'); Output.width(15); Output << 					kin[i].genre;
		Output.fill('_'); Output.width(15); Output << 					kin[i].director;
		Output.fill('_'); Output.width(15); Output << 					kin[i].length << endl;
	}
Output << "\nThe most recent movie:" << endl;
	Output.fill(' '); Output.width(15); Output << 			kin[maxyear].id;
	Output.fill('_'); Output.width(15); Output << 			kin[maxyear].name;
	Output.fill('_'); Output.width(15); Output << 			kin[maxyear].year;
	Output.fill('_'); Output.width(15); Output << 			kin[maxyear].genre;
	Output.fill('_'); Output.width(15); Output << 			kin[maxyear].director;
	Output.fill('_'); Output.width(15); Output << 			kin[maxyear].length<< endl;

	Output.close();

	cout << "Save: Success!" << "\nPress any key.";
	_getch();
}
