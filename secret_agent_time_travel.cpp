/*
5 kyu
Secret Agent Time Travel Calculations
https://www.codewars.com/kata/5c1556f37f0627f75b0000d5

The date is March 24, 2437 and the the Earth has been nearly completely destroyed by the actions of its inhabitants. Our last hope in this disaster lies in a shabby time machine built 
from old toasters and used microwave parts.
The World Time Agency requires you to travel back in time to prevent disaster. You are ordered to "remove" certain babies from the timeline.
Historical newspapers and records provide the Date, Month, and Year for each mission. Unfortunately the time machine takes input only as the number of days to travel back in time. 
It is your job to calculate how many days you will need to travel back from today's date (March 24, 2437) for each mission.
For example, if a historical newspaper says a dangerous baby was born on: Date = 21, Month = 3, Year = 2437 Then your function must compute that it was 3 Days ago.
Another example would be that a baby born on Date = 24, Month = 3, Year = 2436 would have been born 365 days ago.
You will not have time travel past the year 0.
Note that while this is a fairly simple task, it is complicated by the fact that newspapers used the Julian calendar instead of the current Gregorian calendar prior to September 14, 1752. In 1752, 
it was declared that Sep 2, 1752 was proceeded immediately by September 14, 1752, entirely omitting September 3-13. Furthermore, the rules for leap years changed on that date.
After 1752, leap years are on any year divisible by four, except for years which are divisible by 100. An exception to that exception is that years divisible by 400 are 
always leap years. For example, 1803, 1900, 2001, 2019, and 2100 are not leap years, but 1804, 2000 and 2020 are leap years. However in the Julian calander prior to and including 1752, 
leap years were on every year divisible by 4, without the exception of years divisible by 100. The years 1752, 1700, 1600, and 0 were all leap years.
*/
bool leap_year(int year)
{
    bool leap;
    if (year <= 1752)
    {
        if (year % 4 == 0) leap = true;
        else leap = false;
    }
    else
    {
        if ((year % 4 == 0) && (!(year % 100 == 0) || (year % 400 == 0))) leap = true;
        else leap = false;
    }
    return leap;
}
int days_of_month(int month, int year)
{
    int days;
    if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12)) days = 31;
    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) days = 30;
    if (month == 2)
    {
        if (leap_year(year)) days = 29;
        else days = 28;
    }
    return days;
}
int days(int date, int month, int year) {
    int TotalDays = 0;
    const int FinalDays = 890182;
    int TravelDays;
    for (int y = 0; y < year; y++)
    {
        if (leap_year(y)) TotalDays += 366;
        else TotalDays += 365;
    }
    for (int m = 1; m < month; m++)
    {
        TotalDays += days_of_month(m, year);
    }
    TotalDays += date;
    if ((year < 1752)||(year == 1752)&&(month<9)||(year == 1752)&&(month==9)&&(date<3))
    {
        TotalDays += 11;
    }
    TravelDays = FinalDays - TotalDays;
    return TravelDays;
}