#include<bits/stdc++.h>
#include<gtest/gtest.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Sample
{
    Node * head;
    public:
    Sample()
    {
        head = NULL;
    }

    void push(int data)
    {
        Node * temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    int getNthNode(int n)
    {
        if(!head) return -1;
        Node * cur = head;
        Node * temp = head;
        int i=1;
        while(i++ < n)
        {
            if(!temp) return -1;
            temp = temp->next;
        }
        while(temp->next)
        {
            temp = temp->next;
            cur = cur->next;
        }
        return cur->data;
    }
};

struct TestClass: public ::testing::TestWithParam<std::tuple<std::vector<int>,int, int>>
{
    Sample *s;
    void SetUp()
    {
        s = new Sample();
        vector<int> a = std::get<0>(GetParam());
        for(int i=0;i<a.size();i++)
        {
            s->push(a[i]);
        }
    }
    
    void TearDown()
    {
        delete s;
    }
};

TEST_P(TestClass, getNthNodeList)
{
    EXPECT_EQ(s->getNthNode(std::get<1>(GetParam())), std::get<2>(GetParam()));
}


INSTANTIATE_TEST_CASE_P(
TestWithParam,
TestClass,
::testing::Values(
                    std::make_tuple(std::vector<int>{1,2,3}, 2, 2), // 3 - 2 - 1
                    std::make_tuple(std::vector<int>{}, 0, -1),
                    std::make_tuple(std::vector<int>{1,2,4,5}, 2, 2),// 5 - 4 - 2 - 1
                    std::make_tuple(std::vector<int>{11,5,14,2}, 3, 14),// 2 - 14 - 5 - 11
                    std::make_tuple(std::vector<int>{1,2,3,4,5}, 4, 4)//5 - 4 - 3 - 2 - 1
                ));

int main(int argc, char **argv)
{
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
