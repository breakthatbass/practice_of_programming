/**
 * exercise 2-3: What are some input sequences that might cause a 
 * quicksort implementation to display worst-case behavior?  
 * Try to find some that provoke your library version into 
 * running slowly.  Automate the process so that you can specify 
 * and perform a large number of experiments easily.
 * 
 * sometimes it's hard to measure algorithms in real time
 * unless the arays are massive. so i wrote a python script to make
 * massive arrays to use for qsort to see how they affect the timing
 * of qsort
 * 
 * each array is 900,000 elements long
 * one array is in order from largest to smallest: 900,000, 899,999, 899,998...
 * another is 900,000 5s. 5, 5, 5, 5, 5...
 * there's one that's just random numbers in no order.
 * and lastly, there's one with random ascii characters
 * 
 * the conclusion is that arrays with all the same elements will run 
 * slightly slower but not always...
 * 
 * I couldn't quite get it to slow down much
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/stat.h>
#include <stdbool.h> 

// open a file, count the lines, return count
int count_lines(char *file)
{
  FILE *fp;
  int count = 0;  // Line counter
  char c;  // To store the character read from file

  fp = fopen(file, "r");
  if (fp == NULL) {
      fprintf(stderr, "count_lines: could not open file %s\n", file);
      exit(EXIT_FAILURE);
  }

 // just count the new line characters
  while ((c = getc(fp)) && c != EOF) {
    if (c == '\n') { 
      count++;
    }
  }
  fclose(fp);
  return count;
}


#define MAX_LINE 10

// read from a file of numbers, load them into an array, return that array
int *load_array(char *file, int *file_length)
{
  int i, file_line_count;
  static int *nums; // array to then transfer to

  FILE *fp = fopen(file, "r");
  if (fp == NULL) {
    fprintf(stderr, "load_array: could not open file %s\n", file);
    exit(EXIT_FAILURE);
  }

  file_line_count = count_lines(file); //get the amount of lines from file
  *file_length = file_line_count; 

  nums = (int*)malloc(file_line_count * sizeof(int));
  if (nums == NULL) {
    fprintf(stderr, "Not enough memory. Aborting...\n");
    exit(EXIT_FAILURE);
  }

  char line[MAX_LINE];

  i = 0;
  while (fgets(line, MAX_LINE, fp)) { 
     // convert to int and append to nums array
    *(nums + i) = atoi(line);
    i++;
  }
  fclose(fp);
  
  return nums;
}

// compare function to use with qsort
int cmp(const void *a, const void *b)
{
    if (a < b) return -1;
    else if (a == b) return 0;
    else return 1;
}

// give qsort an array and record the time it takes to sort
void qsort_timer(int *arr, int file_len)
{
    clock_t t;
    // start timing and call algorithm
    t = clock();
    qsort(arr, file_len, sizeof(int), cmp);
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
    // end timing
     printf("sorted %d elements in %f seconds\n", file_len, time_taken);
    free(arr);
}

// check if files exist to prevent rewriting files
bool file_exists (char *filename) {
  struct stat   buffer;   
  return (stat (filename, &buffer) == 0);
}


int main()
{
    // variables for the files
    char *high_to_low = "high_to_low.txt";
    char *the_same = "all_the_same.txt";
    char *rand_nums = "random_nums.txt";
    char *rand_chars = "rand_chars.txt";

    if (file_exists(high_to_low) == false) {
    // if files already exist, don't recreate them
      char command[100] = "python3 file_script.py ";
      // add the files as args, with spaces inbetween each
      strcat(command, high_to_low);
      strcat(command, " ");
      strcat(command, the_same);
      strcat(command, " ");
      strcat(command, rand_nums);
      strcat(command, " ");
      strcat(command, rand_chars);

      // run the python script to get the numbers for the arrays
      system(command);
    }

    // need the number of elements in each of the files
    int high_to_low_count = count_lines(high_to_low);
    int all_the_same_count = count_lines(the_same);
    int random_numbers_count = count_lines(rand_nums);
    int rand_chars_count = count_lines(rand_chars);

    // load files with numbers into arrays
    int *h_l = load_array(high_to_low, &high_to_low_count);
    int *a_s = load_array(the_same, &all_the_same_count);
    int *r_n = load_array(rand_nums, &random_numbers_count);
    int *r_c = load_array(rand_chars, &rand_chars_count);

    printf("sorting high_to_low.txt\n");
    qsort_timer(h_l, high_to_low_count);
    printf("sorting all_the_same.txt\n");
    qsort_timer(a_s, all_the_same_count);
    printf("sorting random_nums.txt\n");
    qsort_timer(r_n, random_numbers_count);
    printf("sorting rand_chars.txt\n");
    qsort_timer(r_c, rand_chars_count);    

    return 0;
}
