                                        #include <bits/stdc++.h> 
inline void fast_io() { std::ios::sync_with_stdio(false); std::cin.tie(nullptr); } double distance(int/**/
x1,int y1,int x2, int y2){return sqrt(pow((x1-x2), 2) + pow((y1-y2), 2));} int32_t main() { fast_io();/**/
int test; std::cin >> test; while (test--) { int px, py, ax, ay, bx, by; std::cin >> px >> py >> ax >>/**/
ay >> bx >> by; double ab = distance(ax, ay, bx, by); double ap = distance( ax, ay, px, py); double bp/**/
= distance(px, py, bx, by); double porg = distance(px, py, 0, 0);double aorg = distance(ax, ay, 0, 0);/**/
double borg = distance(bx, by, 0, 0) ; double final_dist = 0 ; bool intersect=true;if ((std::min(ap, aorg)
>= std::max(bp, borg))||(std::min(bp, borg) >= std::max(ap, aorg))) { intersect = false ;} if (intersect==
false){ final_dist = std::min( std::max(ap, aorg), std :: max(bp, borg)) ; } else { final_dist = std::max(
{ab/2, std::min(ap, bp), std::min(aorg, borg)}) ;}std::cout<<std::fixed<<std::setprecision(10)<<final_dist
<<std::endl;}return 0;}/***************************1886/B. Fear of the Dark******************************/


// LACKS perfection NEED some other thing that supports my prowess come on
// I need to improve more on this fact