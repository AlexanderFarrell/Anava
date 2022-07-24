//
// Created by Alexander Farrell on 6/18/22.
//

#ifndef ANAVA_T_THREE_DATE_TIME_H
#define ANAVA_T_THREE_DATE_TIME_H

#include <cstddef>
#include <sys/time.h>

//Taken from https://www.codegrepper.com/code-examples/c/c+get+time+in+milliseconds
inline long current_timestamp() {
    struct timeval te;
    gettimeofday(&te, NULL);
    long milliseconds = te.tv_sec * 1000L + te.tv_usec / 1000;
    return milliseconds;
}

inline long get_milliseconds_current(long timestamp) {
    return timestamp % 1000;
}

inline long get_seconds_current(long timestamp) {
    return (timestamp / 1000) % 60;
}

inline long get_minutes_current(long timestamp) {
    return (timestamp / (1000 * 60)) % 60;
}

inline long get_hours_current(long timestamp) {
    return (timestamp / (1000 * 60 * 60)) % 24;
}

inline long get_day_current(long timestamp) {
    return (timestamp / (1000 * 60 * 60 * 24)) % 365;
}

inline long get_days_total(long timestamp) {
    return (timestamp / (1000 * 60 * 60 * 24));
}

inline long get_year_current(long timestamp) {
    return (timestamp / (1000L * 60L * 60L * 24L * 365L)) + 1970L;
}

//long get_month_current(long timestamp) {
//    return (timestamp / )
//}

inline int is_leap_year(long year) {
    return (year % 4 == 0 && year % 100 != 0);
}

inline int days_before_month(int month) {
    switch (month) {
        case 1:
            return 0;
        case 2:
            return 31;
        case 3:
            return 59;
        case 4:
            return 90;
        case 5:
            return 120;
        case 6:
            return 151;
        case 7:
            return 181;
        case 8:
            return 212;
        case 9:
            return 243;
        case 10:
            return 273;
        case 11:
            return 304;
        case 12:
            return 334;
        default:
            return -1;
    }
}

inline int days_before_month_leap(int month) {
    switch (month) {
        case 1:
            return 0;
        case 2:
            return 31;
        case 3:
            return 60;
        case 4:
            return 91;
        case 5:
            return 121;
        case 6:
            return 152;
        case 7:
            return 182;
        case 8:
            return 213;
        case 9:
            return 244;
        case 10:
            return 274;
        case 11:
            return 305;
        case 12:
            return 335;
        default:
            return -1;
    }
}

//long get_year_current(long timestamp) {
//    long days = get_days_total(timestamp);
//}

inline long get_day_of_week_current(long timestamp) {
    return (get_days_total(timestamp) - 5L) % 7;
}

static int month_days[] = {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
};

static int month_days_leap[] = {
        31,
        29,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
};

static int month_days_before[] = {
        0,
        31,
        60,
        91,
        121,
        152,
        182,
        213,
        244,
        274,
        305,
        335
};

static int month_days_leap_before[] = {
        0,
        31,
        59,
        90,
        120,
        151,
        181,
        212,
        243,
        273,
        304,
        334
};

inline long get_current_month(long timestamp) {
    long days = get_day_current(timestamp);
    int d = 0;
    int i;

    if (is_leap_year(get_year_current(timestamp) + 70)) {
        for (i = 0; i < 12; i++) {
            d += month_days_leap[i];
            if (days < d) {
                return i + 1;
            }
        }
    } else {
        for (i = 0; i < 12; i++) {
            d += month_days[i];
            if (days < d) {
                return i + 1;
            }
        }
    }
    return -1;
}

#endif //ANAVA_T_THREE_DATE_TIME_H
