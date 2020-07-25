#include<bits/stdc++.h>
#include<gtest/gtest.h>
using namespace std;
struct sides{
    int a;int b;int c;
};

struct compareclass
{
    bool operator()(struct sides na,struct sides nb)
    {
        if(na.a == nb.a && na.b == nb.b)
        {
            return na.c < nb.c;
        }
        else if(na.a == nb.a)
        {
            return na.b < nb.b;
        }
    }
} compareObject;

class Sample
{
    vector<sides> arr;
    public:
    Sample()
    {
        arr = {};
    }
    
    void setMember(vector<sides> s)
    {
        arr = s;
    }
    
    bool compare(sides na, sides nb)
    {
        if(na.a == nb.a && na.b == nb.b && na.c == nb.c)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int countDistinctStructurs()
    {
        int n = arr.size();
        for(int i=0;i<n;i++)
        {
            vector<int> v={};
            v.push_back(arr[i].a);
            v.push_back(arr[i].b);
            v.push_back(arr[i].c);
            sort(v.begin(),v.end());
            arr[i].a = v[0];
            arr[i].b = v[1];
            arr[i].c = v[2];
        }
        sort(arr.begin(),arr.end(),compareObject);
        int count = 1;
        for(int i=1;i<n;i++)
        {
            if(!compare(arr[i],arr[i-1]))
            {
                count++;
            }
        }
        return count;
    }
    };

struct TestClass: public ::testing::TestWithParam<std::tuple<std::vector<sides>,int>>
{
    Sample *s;
    void SetUp()
    {
        s = new Sample();
    }
    void TearDown(){delete s;}
    };
    
    TEST_P(TestClass, countDistinctTriangles){
    vector<sides> a;
    a = std::get<0>(GetParam());
    s->setMember(a);
    EXPECT_EQ(s->countDistinctStructurs(), std::get<1>(GetParam()));
    }
    
    INSTANTIATE_TEST_CASE_P(
    TestWithParam,
    TestClass,
    ::testing::Values(
                        std::make_tuple(std::vector<sides>{{1,2,3},{2,1,3},{3,2,4}}, 2),
                        std::make_tuple(std::vector<sides>{{1,1,3},{2,1,3},{3,2,4}}, 3),
                        std::make_tuple(std::vector<sides>{{1,2,3},{2,1,3},{3,2,1}}, 1))
                     );
    
    
int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
/*
int main()
{
vector<sides> a={{1,2,3},{2,1,3},{3,2,4}};
Sample s;
s.setMember(a);
cout<<s.countDistinctStructurs();
return 0;
}
*/
