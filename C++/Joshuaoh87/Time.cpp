#include "Time.h"

Time::Time()
{
    m_minutes = 0;
    m_hours = 0;
}

Time::Time(int hours, int minutes)
{
    this-> m_hours = hours;
    this-> m_minutes = minutes;
}

int Time::GetMinutes() const
{
    return m_minutes;
}

int Time::GetHours() const
{
    return m_hours;
}

void Time::SetMinutes(int minutes)
{
    this-> m_minutes = minutes;
}

void Time::SetHours(int hours)
{
    this-> m_hours = hours;
}

istream &operator >>( istream &input, Time &time )
{
    string temp;

    getline(input, temp, ':');
    time.SetHours(stoi(temp));

    getline(input, temp, ',');
    time.SetMinutes(stoi(temp));

    return input;
}
ostream &operator <<( ostream &output, const Time &time )
{
    output << time.GetHours() << ":" << setw(2) << setfill('0') << time.GetMinutes();


    return output;
}
