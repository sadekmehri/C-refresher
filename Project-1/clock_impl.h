#ifndef CLOCK_IMPL_H_INCLUDED
#define CLOCK_IMPL_H_INCLUDED
#include "clock.h"


Clock::Clock() {
  hr = 0;
  min = 0;
  sec = 0;
}

Clock::Clock(int hours, int minutes, int seconds) {
  setTime(hours, minutes, seconds);
}

void Clock::setTime(int hours, int minutes, int seconds) {
  bool isValidHour = (0 <= hours && hours < 24);
  bool isValidMinute = (0 <= minutes && minutes < 60);
  bool isValidSecond = (0 <= seconds && seconds < 60);

  hr = isValidHour ? hours : 0;
  min = isValidMinute ? minutes : 0;
  sec = isValidSecond ? seconds : 0;
}

void Clock::printTime() const {
    if (hr < 10) cout << "0";
    cout << hr << ":";

    if (min < 10) cout << "0";
    cout << min << ":";

    if (sec < 10) cout << "0";
    cout << sec << endl;
}

void Clock::incrementHours() {
    hr++;
    if (hr > 23) hr = 0;
}

void Clock::incrementMinutes() {
    min++;
    if (min > 59) {
        min = 0;
        incrementHours();
    }
}

void Clock::incrementSeconds() {
    sec++;
    if (sec > 59) {
        sec = 0;
        incrementMinutes();
    }
}

bool Clock::equalTime(const Clock& otherClock) const {
    return (hr == otherClock.hr &&
            min == otherClock.min &&
            sec == otherClock.sec);
}

Clock::~Clock(){}

#endif // CLOCK_IMPL_H_INCLUDED
