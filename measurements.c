#include <stdio.h>
#include <unistd.h>

  struct meas {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int temp;
    int count;
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

    struct meas m;  
    m.count = 0;
    while (!feof(f)) {
     
      fscanf(f, "%d;%d;%d;%d;%d;%d",
                  &m.year,
                  &m.month,
                  &m.day,
                  &m.hour,
                  &m.minute,
                  &m.temp);
      m.count++;
      //printf("temp = %d count =%d\n", m.temp, m.count);
      
    }
    printf("%d %d\n", m.temp, m.count);
    for(int i=1; i<m.count;i++) {
      if(i==2) {printf("temp of 2 add = %d\n", m.temp);}
    }
//    printf("max temp was %d\n", maxTemp(m));
    fclose(f);

    return 0;
  }
