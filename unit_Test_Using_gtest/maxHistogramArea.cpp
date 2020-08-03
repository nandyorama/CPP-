#include<bits/stdc++.h>
#include<gtest/gtest.h>
using namespace std;
class Sample
{
    vector<int> arr;
    public:
    Sample()
    {
        arr = {};
    }
    void setMember(vector<int> s)
    {
        arr = s;
    }
    int maxArea()
    {
        int n = arr.size();
        int i = 0;
        int result = INT_MIN, cur = 0;
        list<int> l;
        while(i<n)
        {
            if(l.empty() || arr[i]>=arr[l.back()])
            {
                l.push_back(i++);
            }
            else
            {
                int temp = l.back();
                l.pop_back();
                cur = arr[temp] *(l.empty()?i:i-l.back()-1);
                if(cur>result)
                {
                    result = cur;
                }
            }
        }
        while(!l.empty())
        {
            int temp = l.back();
            l.pop_back();
            cur = arr[temp] *(l.empty()?i:i-l.back()-1);
            if(cur>result)
            {
                result = cur;
            }
        }
        return result;
    }
};

std::vector<int> input{4,2,2,5};
struct TestClass: public ::testing::TestWithParam<std::tuple<int,int,int,int>>
{
    Sample *s;
    void SetUp(){s = new Sample();}
    void TearDown(){delete s;}
};

TEST_P(TestClass, maxArea)
{
    vector<int> input;
    input.push_back(std::get<0>(GetParam()));
    input.push_back(std::get<1>(GetParam()));
    input.push_back(std::get<2>(GetParam()));
    input.push_back(std::get<3>(GetParam()));
    s->setMember(input);
    //cout<<std::get<0>(GetParam())<<"--"<<std::get<1>(GetParam())<<"--";
    //cout<<std::get<2>(GetParam())<<"--"<<std::get<3>(GetParam())<<"--";
    //cout<<s->maxArea()<<endl;
    EXPECT_GE(s->maxArea(), 8);
}

INSTANTIATE_TEST_CASE_P(
TestWithParam,
TestClass,
::testing::Combine(::testing::ValuesIn(input),
                   ::testing::ValuesIn(input),
                   ::testing::ValuesIn(input),
                   ::testing::ValuesIn(input)));

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*
int main()
{
    vector<int> a={4,2,2,5};
    Sample s;
    s.setMember(a);
    cout<<s.maxArea();
    return 0;
}
*/
