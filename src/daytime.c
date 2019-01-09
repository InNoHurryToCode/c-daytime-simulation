#include <stddef.h>
#include "daytime.h"

static void daytime_updateSecond(Daytime *const manager) {
    if (!manager) {
        return;
    }

    ++manager->second;
}

static void daytime_updateMinute(Daytime *const manager) {
    if (!manager) {
        return;
    }

    if (manager->second > 59) {
        ++manager->minute;
        manager->second = 0;
    }
}

static void daytime_updateHour(Daytime *const manager) {
    if (!manager) {
        return;
    }

    if (manager->minute > 59) {
        ++manager->hour;
        manager->minute = 0;
    }
}

static void daytime_updateDay(Daytime *const manager) {
    if (!manager) {
        return;
    }

    if (manager->hour > 23) {
        ++manager->day;
        ++manager->weekDay;
        manager->hour = 0;
    }
}

static void daytime_updateWeek(Daytime *const manager) {
    if (!manager) {
        return;
    }

    if (manager->weekDay > SUNDAY) {
        ++manager->week;
        manager->weekDay = 1;
    }
}

static void daytime_updateMonth(Daytime *const manager) {
    if (!manager) {
        return;
    }

    if (manager->day > daytime_getDaysOfMonth(manager->month, manager->year)) {
        ++manager->month;
        manager->day = 1;
    }
}

static void daytime_updateYear(Daytime *const manager) {
    if (!manager) {
        return;
    }

    if (manager->month > DECEMBER) {
        ++manager->year;
        manager->month = 1;
        manager->week = 1;
    }
}

static Daytime initDaytime = {
    0,  /* second */
    0,  /* minute */
    0,  /* hour */
    1,  /* day */
    1,  /* weekDay */
    1,  /* week */
    1,  /* month */
    1   /* year */
};

Daytime *daytime_ctor(void) {
    return &initDaytime;
}

void daytime_update(Daytime *const manager) {
    if (!manager) {
        return;
    }
    
    daytime_updateSecond(manager);
    daytime_updateMinute(manager);
    daytime_updateHour(manager);
    daytime_updateDay(manager);
    daytime_updateWeek(manager);
    daytime_updateMonth(manager);
    daytime_updateYear(manager);
}

const char *daytime_getTimeName(const unsigned char hour) {
    switch (hour) {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            return "Midnight";

        case 6:
        case 7:
        case 8:
        case 9:
        case 10:
        case 11:
            return "Morning";

        case 12:
        case 13:
        case 14:
            return "Noon";

        case 15:
        case 16:
        case 17:
            return "Afternoon";

        case 18:
        case 19:
        case 20:
            return "Evening";

        case 21:
        case 22:
        case 23:
            return "Night";
    }

    return NULL;
}

const char *daytime_getDayName(const unsigned char weekDay) {
    switch (weekDay) {
        case MONDAY:
            return "Monday";

        case TUESDAY:
            return "Tuesday";

        case WEDNESDAY:
            return "Wednesday";

        case THURSDAY:
            return "Thursday";

        case FRIDAY:
            return "Friday";

        case SATURDAY:
            return "Saturday";

        case SUNDAY:
            return "Sunday";
    }
    
    return NULL;
}

const char *daytime_getMonthName(const unsigned char month) {
    switch (month) {
        case JANUARY:
            return "January";

        case FEBRUARY:
            return "Februari";

        case MARCH:
            return "March";

        case APRIL:
            return "April";

        case MAY:
            return "May";

        case JULY:
            return "July";

        case JUNE:
            return "June";

        case AUGUST:
            return "August";

        case SEPTEMBER:
            return "September";

        case OCTOBER:
            return "October";

        case NOVEMBER:
            return "November";

        case DECEMBER:
            return "December";
    }

    return NULL;
}

unsigned char daytime_getDaysOfMonth(const unsigned char month, const unsigned int year) {
    switch (month) {
        case JANUARY:
        case MARCH:
        case MAY:
        case JULY:
        case AUGUST:
        case OCTOBER:
        case DECEMBER:
            return 31;

        case APRIL:
        case JUNE:
        case SEPTEMBER:
        case NOVEMBER:
            return 30;

        case FEBRUARY:
            if (year % 4 == 0) {
                /* leap year */
                return 28;
            } else {
                return 27;
            }
    }

    return 0;
}
