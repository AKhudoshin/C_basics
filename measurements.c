#include <stdio.h>
#include <unistd.h>



  struct meas {
    
    int year[518400];
    int month[518400];
    int day[518400];
    int hour[518400];
    int minute[518400];
    int temp[518400];
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
//    m.count = 0;
    int max;
    int i = 0;
    
    while (!feof(f)) {
      
      fscanf(f, "%d;%d;%d;%d;%d;%d",
                  &m.year[i],
                  &m.month[i],
                  &m.day[i],
                  &m.hour[i],
                  &m.minute[i],
                  &m.temp[i]);
      i++;
      //printf("temp = %d count =%d\n", m.temp, m.count);
      
    }
    max = i - 1;

//    printf("%d %d\n", m.temp, m.count);

    for(i = 1; i < max; i++) {
      printf("temp of %d row = %d\n", i, m.temp[i]);
    }
//    printf("max temp was %d\n", maxTemp(m));
    fclose(f);

    return 0;
  }
