#include <bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
int heights[n+1];
int widths[n];
double area = 0;
int areaOfCurrent;
for(int i = 0; i < n+1; i++){
    cin >> heights[i];
}
for(int i = 0; i < n; i++){
    cin >> widths[i];
}
for(int i = 0; i < n; i++){
    area += (heights[i] + heights[i+1]) * (widths[i]/2.0);
}
printf("%.6f", area);
}