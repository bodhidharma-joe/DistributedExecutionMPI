#include<stdio.h>
#include<sys/time.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void start();
void stop();

double * matrixMult(int N, double array[]);
int palindrome(char array[]);
int armstrong(int n);
long long factorial(long long n);
char * reverseString(char array[]);
int stringLength(char array[]);
long long power(int a, int b);
int compareString(char a1[], char a2[]);
double findMaximum(int size, double array[]);
int linearSearch(int size, double d, double array[]);
void bubbleSort(int n, double array[]);


struct timeval tm1, tm2;
void start()
{
gettimeofday(&tm1, NULL);
}

void stop()
{
gettimeofday(&tm2, NULL);
unsigned long long t = ((tm2.tv_sec - tm1.tv_sec)*1000000) + (tm2.tv_usec - tm1.tv_usec);
printf("\n%llu microseconds occured\n",t);
}

// Given a matrix, return the product of the matrix with itself
double * matrixMult(int N, double array[]){
double * res = (double *) malloc(N*N*sizeof(double));
int i, j, m, n, q, row;
double mat[N][N];
double p[N][N];
row = 0;
for (i=0; i<N; i++){
 for (j=0; j<N; j++){
  mat[i][j] = array[(i*N)+j];
 }
 row++;
}

for (m=0; m<N; m++){
 for (n=0; n<N; n++){
  p[m][n] = 0;
  for (q=0; q<N; q++){
   p[m][n] = p[m][n] + (mat[m][q]*mat[q][n]);
  }
 }
}

row = 0;
for (i=0; i<N; i++){
 for (j=0; j<N; j++){
  res[i*N + j] = p[i][j];
 }
 row++;
}
return res;
}

// Give a string, check if it is reversible. Return 0 for false or 1 for true.
int palindrome(char array[]){
int size = strlen(array);
int l = 0;
int r = size - 1;
while (l < r){
 if (array[l] != array[r]){
  //printf("%s has the following not matching: %c, %c\n",array, array[l], array[r]);
  return 0;
 }
 l++;
 r--;
}
return 1;
}

// Given a integer check if it is an armstrong number. Return 0 for false or 1 for true.
int armstrong(int n){
 int m = n;
 int sum = 0;
 int temp;
 while (m!=0){
  temp = m % 10;
  sum = (temp * temp * temp) + sum;
  m = m / 10;
 }
 if (n == sum) return 1;
 return 0;
}

// Return the fatorical of a given long long integer.
long long factorial(long long n){
long long res = 1;
while (n>1){
 res = res * n;
 n--;
}
return res;
}

// Reverse a given string and return the result.
char * reverseString(char array[]){
int size;
size = strlen(array);
int r = size;
char * res = (char*) malloc(size*sizeof(char));
while ( r > 0 ){
 res[size - r] = array[r-1];
 r--;
}
return res;
}

// Return the length of a give string.
int stringLength(char array[]){
int length = strlen(array);
return length;
}
// Return result of a^b.
long long power(int a, int b){
long long res = 1;
while (b){
 if (b & 1) res *= a;
 b >>= 1;
 a *= a;
}
return res;
}

// Given two strings, compare to see if they are the same. Return 1 for same or 0 for not.
int compareString(char a1[], char a2[]){
int i, s1, s2;
s1 = strlen(a1);
s2 = strlen(a2);
if (s1 != s2) return 0;
for (i = 0; i < s1; i++){
 if (a1[i] != a2[i]) return 0;
}
return 1;
}

// Given an array of doubles and return the max.
double findMaximum(int size, double array[]){
double res = array[0];
int i;
for (i = 0; i<size; i++){
 //printf("now comparing %lf and %lf\n",res,array[i]);
 if (array[i]>res) res = array[i];
}

return res;
}

// Given an array of doubles, do a linear search and find the given number. Return position of number else -1.
int linearSearch(int size, double d, double array[]){
int pos;
for (pos=0; pos < size; pos++){
 if (d == array[pos]) return pos;
}
return -1;
}

// sort the given double array using bubble sort. 
void bubbleSort(int n, double array[]){
int i, j;
double temp;
for (i = 0; i<n-1; i++){
 for (j = 0; j<n-i-1; j++){
  if (array[j] > array[j+1]){
   temp = array[j];
   array[j] = array[j+1];
   array[j+1] = temp;
  }
 }
}
}

// Sort the given double array using merge sort.


// A dummy function which is given in a .c file.
void comp(){}

// Breadth first search on a binary tree.

// Depth first search on a binary tree.

int main(int arc, char *argv[]){

start();

char inputfile[] = "commands.txt";
char outputfile[] = "output.txt";
FILE * input = fopen(inputfile, "r");
FILE * output = fopen(outputfile, "w");
char line[BUFSIZ];
char * comArr;
int iid = 0;
if (input!=NULL){
 while (fgets(line, sizeof(line), input)){
  char array[10000][255];
  char com[255];
  int count = 0;
  line[strcspn(line, "\n")] = 0;
  comArr = strtok(line, " ");
  while (comArr!=NULL){
   strcpy(array[count], comArr);
   comArr = strtok (NULL, " ");
   count++;
  }
  
  //printf("command is %s, and next item is %s\n", array[0], array[1]);

  if(strcmp(array[0],"mergeSort")==0||strcmp(array[0],"comp")==0||strcmp(array[0],"bfs")==0||strcmp(array[0],"dfs")==0){
   strcpy(com,array[0]);
   printf("ans to %s is %s\n",com,"Command not found");
   fprintf(output, "%d %s %s\n",iid,com,"Command not found");
   iid++;
  }
  else if(strcmp(array[0],"palindrome")==0){
   strcpy(com, array[0]);
   char string[BUFSIZ];
   strcpy(string, array[1]);
   int respalin = palindrome(string);
   printf("ans to %s is %d\n",com,respalin);
   fprintf(output, "%d %s %d\n",iid,com,respalin);
   iid++;
  }
  else if(strcmp(array[0],"matrixMult")==0){
   strcpy(com, array[0]);
   int size;
   size = atoi(array[1]);
   int i, j;
   double mat[size*size];
   double res[size][size];
   for (i=2;i<size*size+2;i++){
    sscanf(array[i], "%lf", &mat[i-2]);
   }
   double * resmm = (double*) malloc(size*size*sizeof(double));
   resmm = matrixMult(size, mat);
   printf("ans to %s is starting with %lf\n",com,resmm[0]);
   
   fprintf(output, "%d %s",iid,com);
   for (i=0;i<size*size;i++){
    fprintf(output, " %lf",resmm[i]);
   }
   fprintf(output, "\n");
   iid++;
  }
  else if(strcmp(array[0],"armstrong")==0){
   strcpy(com, array[0]);
   int num, resam;
   num = atoi(array[1]);
   resam = armstrong(num);
   printf("ans to %s is %d\n",com,resam);
   fprintf(output, "%d %s %d\n",iid,com,resam);
   iid++;
  }
  else if(strcmp(array[0],"factorial")==0){
   strcpy(com, array[0]);
   long num, resfac;
   num = atoi(array[1]);
   resfac = factorial(num);
   printf("ans to %s is %d\n",com,resfac);
   fprintf(output, "%d %s %d\n",iid,com,resfac);
   iid++;
  }
  else if(strcmp(array[0],"reverseString")==0){
   strcpy(com, array[0]);
   char string[BUFSIZ];
   strcpy(string, array[1]);
   char * resrev;
   resrev = reverseString(string);
   printf("ans to %s is %s\n",com,resrev);
   fprintf(output, "%d %s %s\n",iid,com,resrev);
   iid++;
  }
  else if(strcmp(array[0],"stringLength")==0){
   strcpy(com, array[0]);
   char string[BUFSIZ];
   strcpy(string, array[1]);
   int resstr;
   resstr = stringLength(string);
   printf("ans to %s is %d\n",com,resstr);
   fprintf(output, "%d %s %d\n",iid,com,resstr);
   iid++;
  }
  else if(strcmp(array[0],"power")==0){
   strcpy(com, array[0]);
   long a,b;
   long long respow;
   a = atoi(array[1]);
   b = atoi(array[2]);
   respow = power(a,b);
   printf("ans to %s is %lld\n",com,respow);
   fprintf(output, "%d %s %lld\n",iid,com,respow);
   iid++;
  }
  else if(strcmp(array[0],"compareString")==0){
   strcpy(com, array[0]);
   char s1[BUFSIZ],s2[BUFSIZ];
   strcpy(s1, array[1]);
   strcpy(s2, array[2]);
   int rescomp;
   rescomp = compareString(s1, s2);
   printf("ans to %s is %d\n",com,rescomp);
   fprintf(output, "%d %s %d\n",iid,com,rescomp);
   iid++;
  }
  else if(strcmp(array[0],"findMaximum")==0){
   strcpy(com, array[0]);
   double resfindM;
   int i,size=count-1;
   double list[size];
   for (i=0;i<size;i++){
    //printf("converting %s into double\n",array[i+1]);
    sscanf(array[i+1], "%lf",&list[i]);
   }
   resfindM = findMaximum(size, list);
   printf("ans to %s is %lf\n",com,resfindM);
   fprintf(output, "%d %s %lf\n",iid,com,resfindM);
   iid++;
  }
  else if(strcmp(array[0],"linearSearch")==0){
   strcpy(com, array[0]);
   int reslin, i,size = count-2;
   double d, list[size];
   sscanf(array[1], "%lf", &d);
   for (i=0;i<size;i++){
    sscanf(array[i+2], "%lf", &list[i]);
   }
   reslin = linearSearch(size, d, list);
   printf("ans to %s is %d\n",com,reslin);
   fprintf(output, "%d %s %d\n",iid,com,reslin);
   iid++;
  }
  else if(strcmp(array[0],"bubbleSort")==0){
   strcpy(com, array[0]);
   int size = count-1,i;
   double list[size];
   for (i=0;i<size;i++)sscanf(array[i+1], "%lf", &list[i]);
   bubbleSort(size, list);
   
   printf("ans to bubbleSort is: \n");
   /*for (i=0;i<size;i++){
    printf("%lf\n",list[i]);
   }*/
   
   fprintf(output,"%d %s",iid,com);
   for (i=0;i<size;i++){
    fprintf(output," %lf",list[i]);
   }
   fprintf(output, "\n");
   iid++;
  }
 }
}
fclose(input);
fclose(output);

stop();

return 0;
}





