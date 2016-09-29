#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

void initializeArray(double (&array)[20][20]){
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      if (i == 0 || i == 19) {
        if (j == 0 || j == 19) {
          array[i][j] = 0.0;
        } else {
          array[i][j] = 100.0;
        }
      } else {
        array[i][j] = 0.0;
      }
    }
  }
}

void printArray(double (&array)[20][20]){
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < 20; j++) {
      cout<<array[i][j]<<"\t";
    }
    cout<<endl;
  }
  cout<<endl;
}

void updateArray(double (&array)[20][20], double old[20][20], double &change){
  for (int i = 1; i < 19; i++) {
    for (int j = 0; j < 20; j++) {
      if (j == 0) {
        array[i][j] = (old[i-1][j] + old[i+1][j] + old[i][j+1]) / 3;
      } else if (j == 19) {
        array[i][j] = (old[i-1][j] + old[i+1][j] + old[i][j-1]) / 3;
      }else {
        array[i][j] = (old[i-1][j] + old[i+1][j] + old[i][j-1] + old[i][j+1]) / 4;
      }
      if (change < (abs(old[i][j]-array[i][j]))) {
        change = abs(old[i][j] - array[i][j]);
      }
    }
  }
}

void exportArray(double (&array)[20][20]){
  ofstream out ("output.csv");
  if(out.is_open()) {
   for (int i = 0; i < 20; i++) {
     for (int j = 0; j < 20; j++) {
      //  out << fixed << setprecision(4) << array[i][j]<<", ";
      out<<array[i][j]<<", ";
     }
     out<<endl;
   }
   out.close();
 }
}

int main(int argc, char const *argv[]) {
  double change = 100;
  double array[20][20];
  initializeArray(array);
  printArray(array);
  updateArray(array, array, change);
  printArray(array);
  while (change > 0.1) {
    change = 0.1;
    updateArray(array, array, change);
  }
  printArray(array);
  exportArray(array);
  return 0;
}
