#include "functions.h"


  struct meas {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
  };


void read_and_process_file(char *strdir, bool all, int monthNumber)
  {
    
    char *file = strdir;

    FILE *f = fopen(file, "r");
    if (!f) {
      printf("Error opening file\n");
    }
 
    static int meas_count = 1; 
    static int meas_error = 0;
    static int meas_size = 100;
    struct meas *m;
    char *line;
    float averageTemp = 0;
    float averageTempMonth[12] = {0};
    int minYearTemp = 0;
    int minYearTempRow = 999;
    int maxYearTemp = -99;
    int maxYearTempRow = 0;
    int minMonthTemp[12] = {999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 999, 999};
    int maxMonthTemp[12] = {-99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99, -99,};
    int minMonthTempRow[12] = {0};
    int maxMonthTempRow[12] = {0};

    m = malloc(sizeof(struct meas) * meas_size);

    while (!feof(f)) {                    // Reading file, creating structure with data from file
      
      int scanfret = fscanf(f, "%d;%d;%d;%d;%d;%d\n",
                  &m->year,
                  &m->month,
                  &m->day,
                  &m->hour,
                  &m->minute,
                  &m->temp);

      if (scanfret != 6) {
        printf("Line %d is corrupted, it was skipped\n", meas_count);
        fscanf(f, "%*[^\n]\n");
        meas_count++;
        continue;
      }

      if (scanfret == 6) {
        m[meas_count].year = m->year;
        m[meas_count].month = m->month;
        m[meas_count].day = m->day;
        m[meas_count].hour = m->hour;
        m[meas_count].minute = m->minute;
        m[meas_count].temp = m->temp;  
      } 
      
      if (meas_count + 1 == meas_size) {
        meas_size *= 2;
        m = realloc(m, sizeof(struct meas) * meas_size);
      }
      meas_count++;
    }

    fclose(f);

    for(int i=1; i < meas_count; ++i) {             // Counting average, min, max temp
      averageTemp = averageTemp + m[i].temp;
      if(minYearTemp > m[i].temp) { minYearTemp = m[i].temp; minYearTempRow = i; }
      if(maxYearTemp < m[i].temp) { maxYearTemp = m[i].temp; maxYearTempRow = i; }
      
        if(i <= 43200) { 
          averageTempMonth[0] = averageTempMonth[0] + m[i].temp;
          if(minMonthTemp[0] > m[i].temp) { minMonthTemp[0] = m[i].temp; minMonthTempRow[0] = i;}
          if(maxMonthTemp[0] < m[i].temp) { maxMonthTemp[0] = m[i].temp; maxMonthTempRow[0] = i;} 
        }
        if((i > 43200) && (i <= 86400)) { 
          averageTempMonth[1] = averageTempMonth[1] + m[i].temp;
          if(minMonthTemp[1] > m[i].temp) { minMonthTemp[1] = m[i].temp; minMonthTempRow[1] = i;}
          if(maxMonthTemp[1] < m[i].temp) { maxMonthTemp[1] = m[i].temp; maxMonthTempRow[1] = i;}  
        }
        if((i > 86400) && (i <= 129600)) { 
          averageTempMonth[2] = averageTempMonth[2] + m[i].temp; 
          if(minMonthTemp[2] > m[i].temp) { minMonthTemp[2] = m[i].temp; minMonthTempRow[2] = i;}
          if(maxMonthTemp[2] < m[i].temp) { maxMonthTemp[2] = m[i].temp; maxMonthTempRow[2] = i;} 
        }
        if((i > 129600) && (i <= 172800)) { 
          averageTempMonth[3] = averageTempMonth[3] + m[i].temp; 
          if(minMonthTemp[3] > m[i].temp) { minMonthTemp[3] = m[i].temp; minMonthTempRow[3] = i;}
          if(maxMonthTemp[3] < m[i].temp) { maxMonthTemp[3] = m[i].temp; maxMonthTempRow[3] = i;} 
        }
        if((i > 172800) && (i <= 216000)) { 
          averageTempMonth[4] = averageTempMonth[4] + m[i].temp;
          if(minMonthTemp[4] > m[i].temp) { minMonthTemp[4] = m[i].temp; minMonthTempRow[4] = i;}
          if(maxMonthTemp[4] < m[i].temp) { maxMonthTemp[4] = m[i].temp; maxMonthTempRow[4] = i;}  
        }
        if((i > 216000) && (i <= 259200)) { 
          averageTempMonth[5] = averageTempMonth[5] + m[i].temp; 
          if(minMonthTemp[5] > m[i].temp) { minMonthTemp[5] = m[i].temp; minMonthTempRow[5] = i;}
          if(maxMonthTemp[5] < m[i].temp) { maxMonthTemp[5] = m[i].temp; maxMonthTempRow[5] = i;} 
        }
        if((i > 259200) && (i <= 302400)) { 
          averageTempMonth[6] = averageTempMonth[6] + m[i].temp; 
          if(minMonthTemp[6] > m[i].temp) { minMonthTemp[6] = m[i].temp; minMonthTempRow[6] = i;}
          if(maxMonthTemp[6] < m[i].temp) { maxMonthTemp[6] = m[i].temp; maxMonthTempRow[6] = i;} 
        }
        if((i > 302400) && (i <= 345600)) { 
          averageTempMonth[7] = averageTempMonth[7] + m[i].temp; 
          if(minMonthTemp[7] > m[i].temp) { minMonthTemp[7] = m[i].temp; minMonthTempRow[7] = i;}
          if(maxMonthTemp[7] < m[i].temp) { maxMonthTemp[7] = m[i].temp; maxMonthTempRow[7] = i;} 
        }
        if((i > 345600) && (i <= 388800)) { 
          averageTempMonth[8] = averageTempMonth[8] + m[i].temp; 
          if(minMonthTemp[8] > m[i].temp) { minMonthTemp[8] = m[i].temp; minMonthTempRow[8] = i;}
          if(maxMonthTemp[8] < m[i].temp) { maxMonthTemp[8] = m[i].temp; maxMonthTempRow[8] = i;} 
        }
        if((i > 388800) && (i <= 432000)) { 
          averageTempMonth[9] = averageTempMonth[9] + m[i].temp; 
          if(minMonthTemp[9] > m[i].temp) { minMonthTemp[9] = m[i].temp; minMonthTempRow[9] = i;}
          if(maxMonthTemp[9] < m[i].temp) { maxMonthTemp[9] = m[i].temp; maxMonthTempRow[9] = i;} 
        }
        if((i > 432000) && (i <= 475200)) { 
          averageTempMonth[10] = averageTempMonth[10] + m[i].temp; 
          if(minMonthTemp[10] > m[i].temp) { minMonthTemp[10] = m[i].temp; minMonthTempRow[10] = i;}
          if(maxMonthTemp[10] < m[i].temp) { maxMonthTemp[10] = m[i].temp; maxMonthTempRow[10] = i;} 
        }
        if((i > 475200)) { 
          averageTempMonth[11] = averageTempMonth[11] + m[i].temp; 
          if(minMonthTemp[11] > m[i].temp) { minMonthTemp[11] = m[i].temp; minMonthTempRow[11] = i;}
          if(maxMonthTemp[11] < m[i].temp) { maxMonthTemp[11] = m[i].temp; maxMonthTempRow[11] = i;} 
        }
    }

    if (monthNumber == 13) {
      printf("average temp in a year = %0.1f\n", averageTemp/meas_count);
      printf("min year temp = %d (%d), max year temp = %d (%d)\n", 
      minYearTemp, minYearTempRow,
      maxYearTemp, maxYearTempRow);

      for(int i = 0; i < 12; i++) {
        averageTempMonth[i] = averageTempMonth[i]/43200;
        
          printf("average temp in %d month = %0.1f, min temp = %d(%d), max temp = %d(%d)\n", 
          i+1, averageTempMonth[i], 
          minMonthTemp[i], minMonthTempRow[i],
          maxMonthTemp[i], maxMonthTempRow[i]);
      }
    } else {
        averageTempMonth[monthNumber] = averageTempMonth[monthNumber]/43200;
        printf("average temp in %d month = %0.1f, min temp = %d(%d), max temp = %d(%d)\n",
        monthNumber+1, averageTempMonth[monthNumber],
        minMonthTemp[monthNumber], minMonthTempRow[monthNumber],
        maxMonthTemp[monthNumber], maxMonthTempRow[monthNumber]);
       
    }
  }
