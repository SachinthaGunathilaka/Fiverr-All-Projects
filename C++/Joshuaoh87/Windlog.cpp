#include "Windlog.h"

WindLogType::WindLogType()
{
    m_speed = 0;
    m_solarRadiation = 0;
    m_temperature = 0;
}

WindLogType::WindLogType(Date &date, Time &time, float speed, float sr, float temp)
{
    this->m_date = date;
    this->m_time = time;
    this->m_speed = speed;
    this->m_solarRadiation = sr;
    this->m_temperature = temp;
}

// GETTERS
void WindLogType::GetDate(Date &date) const
{
    date = m_date;
}

void WindLogType::GetTime(Time &time) const
{
    time = m_time;
}

float WindLogType::GetSpeed() const
{
    return m_speed;
}

float WindLogType::GetSolarRadiation() const
{
    return m_solarRadiation;
}

float WindLogType::GetTemperature() const
{
    return m_temperature;
}

// SETTERS
void WindLogType::SetDate(Date &date)
{
    this->m_date = date;
}

void WindLogType::SetTime(Time &time)
{
    this->m_time = time;
}

void WindLogType::SetSpeed(float speed)
{
    this->m_speed = speed;
}

void WindLogType::SetSolarRadiation (float solarRadiation)
{
    this->m_solarRadiation = solarRadiation;
}
void WindLogType::SetTemperature (float temperature)
{
    this->m_temperature = temperature;
}

// OPERATOR OVERLOAD
ostream & operator <<(ostream &output, const WindLogType &wl)
{

Date date;
wl.GetDate(date);

Time time;
wl.GetTime(time);

output << date << "," << time << "," << wl.GetSpeed() << "," << wl.GetSolarRadiation() << "," << wl.GetTemperature() << endl;

return output;
}

istream &operator >>(istream &input, WindLogType &wl)
{
string temp;



//input date
Date date;
input >> date;
wl.SetDate(date);


//input time
Time time;
input >> time;

wl.SetTime(time);

// skip columns to get to speed
for(int i = 0; i < 9; i++)
    {
        getline(input, temp, ',');
    }

getline(input, temp, ',');
wl.SetSpeed(stof(temp));

// solar radiation
getline(input, temp, ',');
wl.SetSolarRadiation(stof(temp));

// skip columns to get to temperature
for(int j = 0; j < 5; j++)
    {
        getline(input, temp, ',');
    }

// ambient temperature
getline(input, temp);
wl.SetTemperature(stof(temp));

return input;
}
