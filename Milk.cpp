//problem link: http://www.usaco.org/index.php?page=viewproblem2&cpid=855

#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int pour(int& c_1 , int& c_2 , int& m_1 , int& m_2)
{
  if(m_1 + m_2 <= c_2)
  {
    m_2 = m_1 + m_2;
    m_1 = 0;
  }
  else if(m_1 + m_2 > c_2)
  {
    m_1 = m_1 - c_2 + m_2;
    m_2 = c_2;
  }
}

int main()
{
  int c_1 , c_2 , c_3;
  int m_1 , m_2 , m_3;
  ifstream fin("mixmilk.in");
  ofstream fout("mixmilk.out");
  fin >> c_1 >> m_1;
  fin >> c_2 >> m_2;
  fin >> c_3 >> m_3;
  
  for(int i = 0 ; i < 33 ; i++)
  {
    pour(c_1, c_2, m_1, m_2);
    pour(c_2, c_3, m_2, m_3);
    pour(c_3, c_1, m_3, m_1);
  }
  pour(c_1, c_2, m_1, m_2);
  fout << m_1 << endl;
  fout << m_2 << endl;
  fout << m_3 << endl;
  return 0;
}
