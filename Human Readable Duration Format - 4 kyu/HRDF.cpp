#include <string>
#include <vector>
#define SECONDS_IN_YEAR 31536000
#define SECONDS_IN_DAY 86400
#define SECONDS_IN_HOUR 3600
#define SECONDS_IN_MINUTE 60

std::string format_duration(int seconds) {

    if (seconds == 0) return "now";
    
    std::string answer;
    std::vector<std::string> units;
    int year(0), day(0), hour(0), minute(0), second(0), remainingSeconds(seconds), size(0);

    if (remainingSeconds >= SECONDS_IN_YEAR) {
        year =  remainingSeconds / SECONDS_IN_YEAR ;
        remainingSeconds %= SECONDS_IN_YEAR;
    }
    if (remainingSeconds >= SECONDS_IN_DAY) {
        day = remainingSeconds / SECONDS_IN_DAY;
        remainingSeconds %= SECONDS_IN_DAY;
    }
    if (remainingSeconds >= SECONDS_IN_HOUR) {
        hour = remainingSeconds/SECONDS_IN_HOUR;
        remainingSeconds %= SECONDS_IN_HOUR;
    }
    if (remainingSeconds >= SECONDS_IN_MINUTE) {
        minute = remainingSeconds / SECONDS_IN_MINUTE;
        remainingSeconds %= SECONDS_IN_MINUTE;
    }
    if (remainingSeconds >= 1) {
        second = remainingSeconds;
        remainingSeconds %= second;
    }
    if (year >= 1) units.push_back(std::to_string(year) + ((year == 1) ? " year" : " years"));
    if (day >= 1) units.push_back(std::to_string(day)+ ((day == 1) ? " day" : " days"));
    if (hour >= 1) units.push_back(std::to_string(hour)+ ((hour == 1) ? " hour" : " hours"));
    if (minute >= 1) units.push_back(std::to_string(minute) + ((minute == 1) ? " minute" : " minutes"));
    if (second >= 1) units.push_back(std::to_string(second)+ ((second == 1) ? " second" : " seconds"));
    size = (int)units.size();
    
    for (int i = 0; i < size; i++) {
        answer.append(units[i]);
        if (i >= 0 && i <= size - 3) answer.append(", ");
        else if (i == size - 2) answer.append (" and ");
    }
    return answer;
}



int main() {
    format_duration(94820438);
    format_duration(0);// Equals("now"));
    format_duration(1);// Equals("1 second"));
    format_duration(62);// Equals("1 minute and 2 seconds"));
    format_duration(120);// Equals("2 minute"));
    format_duration(3662);// Equals("1 hour, 1 minute and 2 seconds"));
    return 0;
}