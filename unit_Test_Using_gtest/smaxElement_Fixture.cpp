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

struct TestClass: public testing::Test{
Sample *s;
void SetUp(){s = new Sample();}
void TearDown(){delete s;}
};

TEST_F(TestClass, checkPivot_1){
  vector<int> a={-5,1,2,3,4};
  s->setMember(a);
  EXPECT_EQ(s->smax_element(),3);
}
TEST_F(TestClass, checkPivot_2){
  vector<int> a={4,5,11,12,3};
  s->setMember(a);
  EXPECT_EQ(s->smax_element(),11);
}
TEST_F(TestClass, checkPivot_3){
  vector<int> a={13,4,5,-1,12};
  s->setMember(a);
  EXPECT_EQ(s->smax_element(),12);
}
TEST_F(TestClass, checkPivot_4){
  vector<int> a={2,3,4,5,11};
  s->setMember(a);
  EXPECT_EQ(s->smax_element(),5);
}
TEST_F(TestClass, checkPivot_5){
  vector<int> a={1,2,3,4,5};
  s->setMember(a);
  EXPECT_EQ(s->smax_element(),4);
}


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


