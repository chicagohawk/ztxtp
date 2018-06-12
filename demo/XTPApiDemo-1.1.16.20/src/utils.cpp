#include "xtp_api_struct_common.h"

void uint64ToDateTime(uint64_t datetime, int & year, int & mon, int & day, int & hour, int & min, int & sec, int & msec){
    year = datetime / 10000000000000;  datetime %= 10000000000000;
    mon  = datetime / 100000000000;    datetime %= 100000000000;
    day  = datetime / 1000000000;      datetime %= 1000000000;
    hour = datetime / 10000000;        datetime %= 10000000;
    min  = datetime / 100000;          datetime %= 100000;
    sec  = datetime / 1000;
    msec = datetime % 1000;
}