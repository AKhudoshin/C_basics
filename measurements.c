#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>



  struct meas {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
  };


  int main(int argc, char **argv)
  {
    if (argc < 2) {
      return -1;
    }
    char *file = argv[1];

    FILE *f = fopen(file, "r");
    if (!f) {
      printf("Error opening file\n");
      return -2;
    }

    struct meas *m;  
    static int meas_count = 0; 
    static int meas_error = 0;
    static int meas_size = 100;

    m = malloc(sizeof(struct meas) * meas_size);

    while (!feof(f)) {
      
      int scanfret = fscanf(f, "%d;%d;%d;%d;%d;%d",
                  &m->year,
                  &m->month,
                  &m->day,
                  &m->hour,
                  &m->minute,
                  &m->temp);
      if (scanfret == 6) { 
        meas_count++;
      } else meas_error++;
      if (meas_count + 1 == meas_size) {
        meas_size *= 2;
        m = realloc(m, sizeof(struct meas) * meas_size);
      }
      
    }

    fclose(f);

    printf("number of elements scanned successfully %d\nerror numbers %d\n", meas_count, meas_error);
    for(int i=0; i <= meas_count; i++) {
      printf("%d %d %d %d %d %d in a row %d\n", m[i].year, m[i].month, m[i].day, m[i].hour, m[i].minute, m[i].temp, i);
    }
    return 0;
  }
