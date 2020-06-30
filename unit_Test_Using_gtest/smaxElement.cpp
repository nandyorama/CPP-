#include<bits/stdc++.h>
#include<gtest/gtest.h>
using namespace std;

class Sample{
 vector<int> vec;
 int n; 
public:
Sample(vector<int> vInput):vec(vInput)
{
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

TEST(TestClass, checkPivot_1){
  //Arrange
  vector<int> vec={5,1,2,3,4};
  Sample obj(vec);
  //Action
  EXPECT_EQ(obj.smax_element(),4);
}
TEST(TestClass, checkPivot_2){
  //Arrange
  vector<int> vec={4,5,1,6,3};
  Sample obj(vec);
  //Action
  EXPECT_EQ(obj.smax_element(),5);
}

int main(int argc, char **argv){
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}

/*
//Driver Function
int main()
{
vector<int> a={5,1,2,3,4};
Sample s(a);
cout<<s.smax_element();
return 0;
}
*/


