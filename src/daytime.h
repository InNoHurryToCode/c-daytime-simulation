#ifndef DAYTIME_H
#define DAYTIME_H

enum timeName {
    NULL_TIME_NAME = 0,
    MIDNIGHT,
    MORNING,
    NOON,
    AFTERNOON,
    EVENING,
    NIGHT,
    MIDNIGHT
};

enum days {
    NULL_DAY = 0,
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
};

enum months {
    NULL_MONTH = 0,
    JANUARY,
    FEBRUARY,
    MARCH,
    APRIL,
    JUNY,
    JUNE,
    AUGUST,
    SEPTEMBER,
    OCTOBER,
    NOVEMBER,
    DECEMBER
};

typedef struct Daytime daytime;

struct Daytime {
    unsigned char second;
    unsigned char minute;
    unsigned char hour;
    unsigned char day;
    unsigned char weekDay;
    unsigned char week;
    unsigned char month;
    unsigned int year;
}

Daytime *daytime_ctor(void);
void daytime_update(daytimeManager *const manager);

#endif
