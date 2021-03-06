#include <iostream>

void swap_long (long *arr, long element1, long element2);
void swap_double (double *arr, long element1, long element2);
void buble(long *arr, double *weight, long start, long end);
long linear_find_mid(long *arr, double *weight, long start, long end);
long partitions(long *arr, double *weight, long  start, long end, long index_of_pivot);
int check(double *weight, long position, long end);

int main (){
  long number_of_array, mid_element, position, start , end, index_mid_element;
  std::cout<<"please input the number of array"<<std::endl;
  std::cin>>number_of_array;
  start =0;
  end = number_of_array - 1;
  double weight[number_of_array];
  long element[number_of_array];

  std::cout<<"please input elements of the array"<<std::endl;
  for (long i = 0; i < number_of_array; i++ )
    std::cin>>element[i];

  std::cout<<"please input weight of each element in the array"<<std::endl;
  for (long i = 0 ;i < number_of_array ; i++ )
    std::cin>>weight[i];

while(1){
index_mid_element = linear_find_mid(element, weight, start, end);
position = partitions(element, weight, start, end, index_mid_element);
int chk = check(weight, position, number_of_array);

if (!chk) break;
if (chk < 0) end = position - 1;
if (chk > 0) start = position + 1;
}
std::cout<<element[position]<<std::endl;
}

//find the n/2th largest element and return element
long linear_find_mid(long *arr, double *weight, long start, long end){
if (end - start +1 <= 5){
long mid = (end + start)/2;
  buble(arr, weight, start, end);
  // The n/2th largest number is in the first place
  return mid;
  }

long loop_times = (end -start + 1)/5;
long i;
for ( i = 0; i < loop_times; i++){
buble(arr, weight, 5*i + start ,  start + 5*i + 4);
swap_long(arr, i+start, start + 5*i + 2 );
swap_double(weight, start+i, 5*i + 2 + start );
}
return linear_find_mid(arr, weight, start, start+loop_times-1);
}


long partitions(long *arr, double *weight, long  start, long end, long index_of_pivot){
long pivot = *(arr+index_of_pivot);
double weight_of_standard = *(weight+index_of_pivot); 
swap_long(arr, index_of_pivot, end);
swap_double(weight, index_of_pivot, end);

long pos = start;
while(start<=end){
if (arr[start]<=pivot){
  swap_long(arr, pos, start);
  swap_double(weight, pos, start);
  pos++;
  }
start++;
 }
return pos-1;
}

int check(double *weight, long position, long end){
double sum_former = 0, sum_latter = 0;
for (long i =0; i < position; i++)
  sum_former += *(weight+i);

for (long i = position + 1; i < end; i++)
   sum_latter += *(weight+i);

double diff_former = double(0.5) - sum_former, diff_latter =double(0.5) - sum_latter; 

if (diff_former < 0 ) return -1;
if (diff_latter < 0 ) return 1;
return 0;
}

void swap_long (long *arr, long element1, long element2){
    long num = *(arr + element1);
     *(arr + element1) = *(arr + element2);
     *(arr + element2) = num;
  }
 
  void swap_double (double *arr, long element1, long element2){
    double num = *(arr + element1);
    *(arr + element1) = *(arr + element2);
    *(arr + element2) = num;
  }
 
  void buble(long *arr, double *weight, long start, long end){
          for (long i=start;i<=end;i++){
            for (long j=i+1;j<=end;j++){
              if (*(arr+i)>*(arr+j)){
                swap_long(arr, i, j);
                swap_double(weight, i, j);
              }
            }
          }
  }

