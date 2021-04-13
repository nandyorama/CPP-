#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include <boost/range/combine.hpp>
struct Node{ 
    int i;
    int j;
};

struct ContainsData{
    int x, y;
ContainsData(int x_, int y_):
    x(x_),y(y_){}
bool operator()(const Node & data)
{
    return data.i < x && data.j > y;    
}
};
int main() 
{
    const std::vector<int> vec1 = {1, 2, 3, 4, 5};
    const std::vector<int> vec2 = {11, 12, 13, 14, 15};
    const std::vector<Node> input = {{0,12},{3,15},{4,10},{6,16},{7,17}};
    for (const auto & zipped : boost::combine(vec1, vec2)) {
        //int i;int j; 
        //boost::tie(i,j) = zipped;
        //std::cout << "(" << i << ", " << j << ")" << std::endl;
        
        std::cout << boost::get<0>(zipped) <<std::endl;
        std::cout << boost::get<1>(zipped) <<std::endl;
        const auto  it = std::find_if (
                    input.begin(), 
                    input.end(), 
                    ContainsData(boost::get<0>(zipped), boost::get<1>(zipped)));
        if( it != input.end())
        {
            std::cout<<"Found"<<std::endl;
        }
    }
    return 0;
}
