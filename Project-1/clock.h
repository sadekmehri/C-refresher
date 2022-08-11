#ifndef CLOCK_H_INCLUDED
#define CLOCK_H_INCLUDED

using namespace std;

class Clock {
    private:
        int hr;
        int min;
        int sec;
    public:
        Clock();
        Clock(int hours, int minutes, int seconds);
        void setTime(int hours, int minutes, int seconds);
        void printTime() const;
        void incrementSeconds();
        void incrementMinutes();
        void incrementHours();
        bool equalTime(const Clock& otherClock) const;
        virtual ~Clock();
};


#endif
