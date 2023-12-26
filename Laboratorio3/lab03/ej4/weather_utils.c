#include "weather.h"
#include "array_helpers.h"

int min_min_temp(WeatherTable a){
    int min;
    for (unsigned int year = 0u; year < YEARS; year = year + 1) {
        for (month_t month = january; month <= december; ++month) {
            for(unsigned int day = 0u; day < DAYS; day = day + 1){

                // En este if falta agregar el primer anio
                if(month==january && day==0){   
                    min = a[year][month][day]._min_temp;
                } else {

                    if(min > a[year][month][day]._min_temp){
                      min = a[year][month][day]._min_temp;
                    }
                }
            }
        }
    }
    return min;
}


int max_temp_for_year(WeatherTable a, int year){
    int max;
    for (month_t month = january; month <= december; ++month) {
        for(unsigned int day = 0u; day < DAYS; ++day){

        if(month==january && day==0){
            max = a[year][month][day]._max_temp;
        } else {

            if(max < a[year][month][day]._max_temp){
            max = a[year][month][day]._max_temp;
            }
        }
        }
    }
    return max;
}


void max_per_year(WeatherTable a, int output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++) {
      output[year] = max_temp_for_year(a, year);
    }
}


unsigned int total_rainfall_for_month(WeatherTable a, int year, month_t month) {
    unsigned int sum = 0u;
    for(unsigned int day = 0u; day < DAYS; day = day + 1){
      sum += a[year][month][day]._rainfall;
    }
    return sum;
  }

month_t month_of_max_rainfall_for_year(WeatherTable a, int year){
    unsigned int max;
    month_t max_month;
    for (month_t month = january; month <= december; ++month) {
        
        unsigned int total_rainfall = total_rainfall_for_month(a, year, month);

        if(month == january){
        max = total_rainfall;
        max_month = month;
        } else {

        if(max < total_rainfall){
            max = total_rainfall;
            max_month = month;
        }
        }
    }

    return max_month;
}

void month_of_max_rainfall_per_year(WeatherTable a, month_t output[YEARS]) {
    for (unsigned int year = 0; year < YEARS; year++){
        output[year] = month_of_max_rainfall_for_year(a, year);
    }
}
