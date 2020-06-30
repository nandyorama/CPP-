#include<bits/stdc++.h>
#include<gtest/gtest.h>
using namespace std;

class Sample{
 vector<int> vec;
 int n; 
public:
Sample()
{
	vec = {};
	n = 0;
}
void setMember(vector<int> v)
{
	vec = v;
	n = vec.size();
}
int smax_element()
{  
	int max_1 = 0, max_2 = 0;
	for(int i=0;i<n;i++)
	{
		if(vec[i]>max_1)
		{
			max_2 = max_1;
			max_1 = vec[i];
		}
		else if(vec[i] > max_2)
		{
			max_2 = vec[i];
		}
	} 
	return max_2;
}
};

struct TestClass: public ::testing::TestWithParam<std::tuple<std::vector<int>,int>>{

Sample *s;
void SetUp(){s = new Sample();}
void TearDown(){delete s;}
};

TEST_P(TestClass, checkPivot){
  auto a = std::get<0>(GetParam());
  auto val = std::get<1>(GetParam());
  s->setMember(a);
  EXPECT_EQ(s->smax_element(), val);
}

INSTANTIATE_TEST_CASE_P(
        TestWithParam,
        TestClass,
        ::testing::Values(
                std::make_tuple(std::vector<int>{-5,1,2,3,4}, 3),
                std::make_tuple(std::vector<int>{4,5,11,2,13}, 11),
                std::make_tuple(std::vector<int>{3,4,-5,-1,2}, 3),
                std::make_tuple(std::vector<int>{2,3,4,5,1}, 4),
                std::make_tuple(std::vector<int>{11,2,3,4,15}, 11)));

int main(int argc, char **argv){
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
/*
int main()
{
vector<int> a={5,1,2,3,4};
Sample s;
s.setMember(a);
cout<<s.smax_element();
return 0;
}
*/


