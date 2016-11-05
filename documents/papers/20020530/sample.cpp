#include <vector>
#include <iostream>

main()
{
  int array[] = {1,3,5,7,9,11,13,15};
  vector<int> v(array,&array[8]);
  vector<int>::iterator Ite;

  // initalize
  Ite = v.begin();
  // put array
  Ite ++;
 
  // test for vector class iterator 
  cout << "test printing \"pointer\"" << endl;
  cout << *Ite << endl;

  // delete an element
  v.erase(v.begin());
  cout << *Ite << endl;

  // test 'for' word 
  cout << "test printing \"for\"" << endl;
  for (Ite = v.begin(); Ite != v.end(); Ite++) {
    cout << *Ite << endl;
  }
}
