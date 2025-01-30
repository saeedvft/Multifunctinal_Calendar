#include <SFML\Graphics.hpp>
#include <iostream> 
#include <ctime>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <SFML\Network.hpp>
#include <sstream>

using namespace std;

struct timeset
{
    int year;
    int month;
    int monthday;
    int weekday;
    int hour;
    int min;
    int second;
};

struct  timeset getCurrentTime() {
    struct tm newtime;
    time_t now = time(0);
    localtime_s(&newtime, &now);
    int Month = 1900 + newtime.tm_year;
    timeset t;
    t.year = 1900 + newtime.tm_year;
    t.month = 1 + newtime.tm_mon;
    t.monthday = newtime.tm_mday;
    t.weekday = newtime.tm_wday + 1;
    t.hour = newtime.tm_hour;
    t.min = newtime.tm_min;
    t.second = newtime.tm_sec;
    return t;
};



int main()
{


    sf::RenderWindow window(sf::VideoMode(1120, 970), "Project", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
    window.setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width * 0.5 - window.getSize().x * 0.5,
        sf::VideoMode::getDesktopMode().height * 0.45 - window.getSize().y * 0.5));

    struct  timeset currenttime = getCurrentTime();


    sf::Font f;
    f.loadFromFile("Dana-Bold.ttf");
    sf::Font f2;
    f2.loadFromFile("Dana-DemiBold.ttf");
    sf::Font f3;
    f3.loadFromFile("Dana-ExtraBold.ttf");
    sf::Font f4;
    f4.loadFromFile("Dana-Regular.ttf");

    sf::Text Calendar;
    Calendar.setFont(f4);
    ostringstream oss;
    oss << "Calendar " << currenttime.year;
    Calendar.setString(oss.str());
    Calendar.setFillColor(sf::Color(255, 255, 255));
    Calendar.setCharacterSize(70);
    Calendar.setPosition(sf::Vector2f(340, 20));

    string Months[12] = { "JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE",
                          "JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER" };
    int MonthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    string Weekdaynames[7] = { "Su","Mo","Tu","We","Th","Fr","Sa" };
    int StartList[12] = { 0,3,3,6,1,4,6,2,5,0,3,5 };

    sf::CircleShape circle(12);
    sf::RectangleShape OrangeRect[12];
    sf::Text MonthTexts[12];
    sf::Text WeekDays[12][7];
    sf::Text MonthNums[12][31];
    int x1 = 32;
    int y1 = 173;

    for (int i = 1; i <= 12; i++)
    {
        OrangeRect[i - 1].setSize(sf::Vector2f(250, 2));
        OrangeRect[i - 1].setPosition(sf::Vector2f(x1, y1));
        OrangeRect[i - 1].setFillColor(sf::Color(255, 176, 2));
        x1 += 270;
        if (!(i % 4))
        {
            x1 = 20;
            y1 += 270;
        }

        MonthTexts[i - 1].setFont(f);
        MonthTexts[i - 1].setString((Months[i - 1]));
        MonthTexts[i - 1].setCharacterSize(25);
        MonthTexts[i - 1].setLetterSpacing(3);

        int x2 = OrangeRect[i - 1].getPosition().x + 14;
        int y2 = OrangeRect[i - 1].getPosition().y + 10;
        for (int j = 1; j <= 7; j++)
        {
            WeekDays[i - 1][j - 1].setFont(f2);
            WeekDays[i - 1][j - 1].setString(Weekdaynames[j - 1]);
            WeekDays[i - 1][j - 1].setCharacterSize(15);
            WeekDays[i - 1][j - 1].setPosition(x2, y2);
            /*if (j == 1)
            {
                WeekDays[i - 1][j - 1].setFillColor(sf::Color(255, 255, 255, 100));
            }*/
            x2 += 34;
        }

        int startDay = StartList[i - 1];
        int counter = startDay + 1;
        int x3 = WeekDays[i - 1][startDay].getPosition().x;
        int y3 = WeekDays[i - 1][startDay].getPosition().y + 30;
        int daynum = MonthDays[i - 1];
        for (int j = 1; j <= daynum; j++)
        {
            MonthNums[i - 1][j - 1].setFont(f2);
            MonthNums[i - 1][j - 1].setString(to_string(j));
            MonthNums[i - 1][j - 1].setCharacterSize(15);
            MonthNums[i - 1][j - 1].setPosition(x3, y3);
            x3 += 34;
            if (!(counter % 7))
            {
                x3 = WeekDays[i - 1][0].getPosition().x;
                y3 += 30;
                counter = 0;
            }
            counter++;
            if (i < currenttime.month)
            {
                sf::Color gc = MonthNums[i - 1][j - 1].getFillColor();
                MonthNums[i - 1][j - 1].setFillColor(sf::Color(255, 255, 255, 100));
            }
            else if (currenttime.month == i)
            {
                if (j < currenttime.monthday - 1)
                {
                    sf::Color gc = MonthNums[i - 1][j - 1].getFillColor();
                    MonthNums[i - 1][j - 1].setFillColor(sf::Color(255, 255, 255, 55));
                }
                else if (j == currenttime.monthday)
                {
                    MonthNums[i - 1][j - 1].setFillColor(sf::Color(219, 90, 66));
                    MonthNums[i - 1][j - 1].setFont(f3);
                    circle.setPosition(MonthNums[i - 1][j - 1].getPosition().x - 3.5,
                        MonthNums[i - 1][j - 1].getPosition().y - 2);
                    circle.setFillColor(sf::Color(134, 187, 216, 0));
                    circle.setOutlineColor(sf::Color(255, 176, 2));
                    circle.setOutlineThickness(3);
                }
                else if (j == currenttime.monthday + 1)
                {
                    MonthNums[i - 1][j - 1].setFillColor(sf::Color(84, 186, 129));
                }
                else if (j == currenttime.monthday - 1)
                {
                    MonthNums[i - 1][j - 1].setFillColor(sf::Color(164, 44, 214));
                }

            }
        }
    }
    //setting the positions of Month Text
    {
        MonthTexts[0].setPosition(80, 125);
        MonthTexts[1].setPosition(345, 125);
        MonthTexts[2].setPosition(640, 125);
        MonthTexts[3].setPosition(915, 125);

        MonthTexts[4].setPosition(110, 396);
        MonthTexts[5].setPosition(380, 396);
        MonthTexts[6].setPosition(650, 396);
        MonthTexts[7].setPosition(903, 396);

        MonthTexts[8].setPosition(70, 665);
        MonthTexts[9].setPosition(355, 665);
        MonthTexts[10].setPosition(615, 665);
        MonthTexts[11].setPosition(885, 665);
    }

    window.clear(sf::Color(44, 47, 51)); //windows BG color
    window.draw(Calendar);
    window.draw(circle);
    int notes_freq[12][31];
    int tmp[12][31] = { 0 };


    string notes[12][31];

    for (int i = 0; i < 12; i++)
    {
        window.draw(OrangeRect[i]);
        window.draw(MonthTexts[i]);
        for (int j = 0; j < 7; j++)
        {
            window.draw(WeekDays[i][j]);
        }
        for (int j = 0; j < MonthDays[i]; j++)
        {
            window.draw(MonthNums[i][j]);
            notes_freq[i][j] = 0;
        }
    }
    window.display();

    char base[150];
    fstream myfile("Notes.txt");
    if (!myfile.is_open()) {
        ofstream o("Notes.txt");
        o.close();
    }
    myfile.close();
    myfile.open("Notes.txt");
    while (!myfile.eof()) {
        myfile.getline(base, 250, '\n');
        char* p;
        int month = (int)strtol(base, &p, 10);
        int day = (int)strtol(p, &p, 10);
        if (month != 0 && day != 0) {
            notes[month - 1][day - 1] = p;
            notes_freq[month - 1][day - 1]++;
        }
    }
    myfile.close();
    myfile.open("Flags.txt");
    if (!myfile.is_open()) {
        ofstream o("Flags.txt");
        o.close();
    }
    myfile.close();
    myfile.open("Flags.txt");
    while (!myfile.eof()) {
        myfile.getline(base, 250, '\n');
        char* p;
        int month = (int)strtol(base, &p, 10);
        int day = (int)strtol(p, &p, 10);
        if (month != 0 && day != 0) {
            tmp[month - 1][day - 1]++;
        }
    }
    myfile.close();
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear(sf::Color(44, 47, 51)); //windows BG color
        window.draw(Calendar);
        window.draw(circle);
        for (int i = 0; i < 12; i++)
        {
            window.draw(OrangeRect[i]);
            window.draw(MonthTexts[i]);
            for (int j = 0; j < 7; j++)
            {
                window.draw(WeekDays[i][j]);
            }
            for (int j = 0; j < MonthDays[i]; j++)
            {
                if (tmp[i][j]) {
                    MonthNums[i][j].setFillColor(sf::Color(0, 255, 255));
                }
                window.draw(MonthNums[i][j]);
            }
        }

        string A; //commands
        string B; //note
        getline(cin, A);
        transform(A.begin(), A.end(), A.begin(), ::toupper);
        int month;
        int day;
        if (A == "FLAG") {
            cout << "Please insert month:";
            cin >> month;
            cout << "Please insert day:";
            cin >> day;
            MonthNums[month - 1][day - 1].setFillColor(sf::Color(0, 255, 255));
            MonthNums[month - 1][day - 1].setFont(f3);
            tmp[month - 1][day - 1]++;
            window.clear(sf::Color(44, 47, 51));
            window.draw(Calendar);
            window.draw(circle);
            for (int i = 0; i < 12; i++)
            {
                window.draw(OrangeRect[i]);
                window.draw(MonthTexts[i]);
                for (int j = 0; j < 7; j++)
                {
                    window.draw(WeekDays[i][j]);
                }
                for (int j = 0; j < MonthDays[i]; j++)
                {
                    window.draw(MonthNums[i][j]);
                }
            }
            window.display();
        }

        else if (A == "UNFLAG") {
            cout << "Please insert month:";
            cin >> month;
            cout << "Please insert day:";
            cin >> day;
            MonthNums[month - 1][day - 1].setFillColor(sf::Color(255, 255, 255));
            MonthNums[month - 1][day - 1].setFont(f3);
            window.clear(sf::Color(44, 47, 51));
            window.draw(Calendar);
            window.draw(circle);
            for (int i = 0; i < 12; i++)
            {
                window.draw(OrangeRect[i]);
                window.draw(MonthTexts[i]);
                for (int j = 0; j < 7; j++)
                {
                    window.draw(WeekDays[i][j]);
                }
                for (int j = 0; j < MonthDays[i]; j++)
                {
                    window.draw(MonthNums[i][j]);
                }
            }
            window.display();
        }


        else if (A == "ADD NOTE") {
            int monthN;
            int dayN;
            cout << "Please insert month:";
            cin >> monthN;
            cout << "Please insert day:";
            cin >> dayN;
            getchar(); //gets Enter after monthN input
            getline(cin, B);
            notes[monthN - 1][dayN - 1] += B;
            notes_freq[monthN - 1][dayN - 1]++;
        }

        else if (A == "DELETE NOTE") {
            int monthD;
            int dayD;
            cout << "Please insert month:";
            cin >> monthD;
            cout << "Please insert day:";
            cin >> dayD;
            notes[monthD - 1][dayD - 1] = "";
            notes_freq[monthD - 1][dayD - 1] = 0;
        }

        else if (A == "SHOW") {
            int monthS;
            int dayS;
            cout << "Please insert month:";
            cin >> monthS;
            cout << "Please insert day:";
            cin >> dayS;
            cout << notes[monthS - 1][dayS - 1];
            getchar();
            getchar();
        }

        else if (A == "SHOW ALL") {
            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < MonthDays[i]; j++) {
                    if (notes_freq[i][j]) {
                        cout << i + 1 << "/" << j + 1 << " " << notes[i][j] << "\n";

                    }
                }
            }
            getchar();
        }

        else if (A == "SAVE") {
            ofstream myfile("Notes.txt");
            ofstream myflag("flags.txt");

            for (int i = 0; i < 12; i++) {
                for (int j = 0; j < MonthDays[i]; j++) {
                    if (notes_freq[i][j]) {
                        myfile << i + 1 << " " << j + 1 << " " << notes[i][j] << "\n";
                    }
                    if (tmp[i][j]) {
                        myflag << i + 1 << " " << j + 1 << "\n";
                    }
                }
            }
            myfile.close();
        }

        else if (A == "ADD REMINDER") {
            /*sf::Http http("http://parsamabani.pythonanywhere.com/");
            sf::Http::Request request;
            request.setMethod(sf::Http::Request::Post);
            request.setUri("http://parsamabani.pythonanywhere.com/reminder/check/?student_id={401522196}");
            sf::Http::Response response = http.sendRequest(request);

            if (response.getStatus() == sf::Http::Response::Ok) {
                cout << "Done!";
            }
            else {
                cout << "Failed!";
            }*/

        }

        else if (A == "EXIT") {
            exit(0);
        }
        //system("CLS");

    }


}

