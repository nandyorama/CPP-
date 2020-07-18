#include<bits/stdc++.h>
#include<gtest/gtest.h>
using namespace std;
class Sample{
    vector<int> arr;
    int n;
    int givenSum;

    public:
    Sample()
    {
        arr = {};
        n = 0;
        givenSum = 0;
    }
    void setMember(vector<int> v,int k)
    {
        arr = v;
        n = arr.size();
        givenSum = k;
    }
    int numberOfPairWithGivenSum() {
        int H[256]={0,};
        int count = 0;
        if(n==0 || n==1) return 0;
        
        for(int i=0;i<n;i++)
        {
            if(H[abs(givenSum-arr[i])])
            {
                count+=H[abs(givenSum-arr[i])];
            }
            H[arr[i]]++;
        }
        return count;
    }
};

struct TestClass: public ::testing::TestWithParam<std::tuple<std::vector<int>,int, int>>{
Sample *s;
void SetUp(){s = new Sample();}
void TearDown(){delete s;}
};

TEST_P(TestClass, numberOfPairWithGivenSum){
auto arr = std::get<0>(GetParam());
auto sum = std::get<1>(GetParam());
auto expect = std::get<2>(GetParam());
s->setMember(arr,sum);
EXPECT_EQ(s->numberOfPairWithGivenSum(), expect);
}

INSTANTIATE_TEST_CASE_P(
TestWithParam,
TestClass,
::testing::Values(
                    std::make_tuple(std::vector<int>{1,2,3,4,3}, 6, 2),
                    std::make_tuple(std::vector<int>{5,3,3,1,3}, 6, 4),
                    std::make_tuple(std::vector<int>{5,3,7,2,2}, 6, 0),
                    std::make_tuple(std::vector<int>{1}, 6, 0),
                    std::make_tuple(std::vector<int>{}, 6, 0),
                    std::make_tuple(std::vector<int>{3,5,1,3,3}, 6, 4)
                ));

int main(int argc, char **argv){
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
