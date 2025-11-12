#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <utility>
#include <algorithm>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

const string ascii = "@%#*+=-:.?[]{}<>^";
const vector<char> ascii_L = {65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90};

const pair<char, char>randomizeAscii(int fade)
{
  int index_0 = fade * ascii.size() / 256;
  int index_1 = fade * ascii_L.size() / 256;

  index_0 += rand() % 3 - 1;
  index_0 = max(0, min((int)ascii.size() - 1, index_0));
  index_1 += rand() % 3 - 1;
  index_1 = max(0, min((int)ascii_L.size() - 1, index_1));
    
  return {ascii[index_0], ascii_L[index_1]};
}

string color(char c, int b)
{
  int c_code;

  if (b < 64)
  {
    c_code = 30;
  } 
  else if (b < 128)
  {
    c_code = 31;
  }
  else if (b < 192)
  {
    c_code = 30;
  }
  else
  {
    c_code = 31;
  }
  return "\033[" + to_string(c_code) + "m" + c + "\033[0m";
}

int main()
{   
  srand((unsigned)time(0));

  Mat img = imread("C:\\Users\\hamst\\OneDrive\\Desktop\\Lunatic Laboratory\\ICONS\\about.png", IMREAD_GRAYSCALE);
  if (img.empty())
  {
    cout << "Image not found" << endl;
    return -1;
  }
  // ( x, y )
  resize(img, img, Size(), 2.5, 1);

  printf("Image loaded: %d x %d\n", img.cols, img.rows);
  ofstream out("output.txt");
  for (int o = 0; o < img.rows; ++o)
  {
    for (int i = 0; i < img.cols; ++i)
    {
      int b = img.at<uchar>(o, i);
      auto [s, _] = randomizeAscii(b);
      cout << color(s, b);
      out << s;
    }
    cout << endl;
    out <<'\n';
  }
  

    

    //for (char ascii_string : ascii){
      //  cout << ascii_string << " ";
    //}
    //for (char ascii_character : ascii_L){
      //  cout << ascii_character << " ";
    //}
  out.close();
  system("pause");
  system("start output.txt");
  return 0;
}
