#include <vector>
#include <boost/range/algorithm.hpp>
#include <boost/range/algorithm_ext.hpp>

#include <boost/range/counting_range.hpp>
#include <boost/range/irange.hpp>

#include <boost/range/combine.hpp>
#include <boost/foreach.hpp>

#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_io.hpp>

#include "bits/stdc++.h"
#include <iostream>
using namespace std;
void irange_demo() {
    for (int i : boost::irange(0, 10)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i : boost::irange(1, 10, 2)) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}
struct Sample
{
    vector<int> values;
    vector<int> indexes;
};
int main() {
    std::vector<int> src = {3, 4, 5};
    std::vector<int> target = {95, 96, 97, 98, 99};

    // Copy values from a range to a container, inserting them with push_back().
    // Returns a reference to the target container.
    boost::range::push_back(target, src);

    boost::copy(target, std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    for(auto item : target)
    {
        cout<<item<<"---";
    }
    cout<<endl;
    
    //boost::range example
    irange_demo();
    
    std::vector<int> vec1 = {11, 12, 13, 14, 15};
    std::vector<int> vec2 = {6, 7, 8, 9, 10};
    //boost::combine(boost::irange(boost::irange(static_cast<size_t>(0), vec.size()),
    //               boost::combine(str, vec));
    for (const auto & zipped : boost::combine(vec1, vec2))
    {
        int i; int j; 
        boost::tie(i, j) = zipped;
        std::cout << "(" << i << ", " << j <<")" << std::endl;
    }
    
  typedef boost::tuple<int, boost::tuple<double, double>> sample;
  sample a{1, {5.4, 6.5}};
  std::cout << std::boolalpha << a << '\n';
  std::cout << boost::get<0>(a)<<endl;//accesses the first element of the tuple 
  
  vector d{5, 1, 2, 3, 2, 5};
  std::unordered_set<int> ds(std::begin(d), std::end(d));
  std::vector<int> index;
  index.reserve(std::distance(std::begin(d), std::end(d)));
  std::transform(std::begin(d), std::end(d), std::back_inserter(index),
  [&](double el)
  {
		return std::distance(std::begin(ds), ds.find(el));
  });
  struct Sample output = {{std::begin(ds),std::end(ds)}, index};
  for(auto item: output.values)
  {
    cout<<item;
  }
  cout<<endl;
  for(auto item: output.indexes)
  {
    cout<<item;
  }
  cout<<endl;
  
  return 0;
}
