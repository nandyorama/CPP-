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
    void print()
    {
        Node * cur = head;//
        while(cur)
        {
        cout<<cur->data<<"--";
        cur = cur->next;
        }
    cout<<endl;
    }
    
    int countNode()
    {
        int count = 0;
        Node * cur = head;//
        while(cur)
        {
            count++;
            cur = cur->next;
        }
        return count;
    }
    
    int middleElement()
    {
        if(!head) return -1;
        Node * f = head;
        Node * s = head;
        while(f && f->next)
        {
            s = s->next;
            f = f->next->next;
        }
        return s->data;
    }
};

struct TestClass: public ::testing::TestWithParam<std::tuple<std::vector<int>,int, int>>
{
    Sample *s;
    void SetUp(){s = new Sample();}
    void TearDown(){delete s;}
};
TEST_P(TestClass, countNodes)
{
    vector<int> a = std::get<0>(GetParam());
    for(int i=0;i<a.size();i++)
    {
        s->push(a[i]);
    }
    EXPECT_EQ(s->countNode(), std::get<1>(GetParam()));
}
TEST_P(TestClass, middleList)
{
    vector<int> a = std::get<0>(GetParam());
    for(int i=0;i<a.size();i++)
    {
        s->push(a[i]);
    }
    EXPECT_EQ(s->middleElement(), std::get<2>(GetParam()));
}

INSTANTIATE_TEST_CASE_P(
TestWithParam,
TestClass,
::testing::Values(
                    std::make_tuple(std::vector<int>{1,2,3}, 3, 2),
                    std::make_tuple(std::vector<int>{}, 0, -1),
                    std::make_tuple(std::vector<int>{1,2,4,5}, 4, 2),
                    std::make_tuple(std::vector<int>{11,5,14,2}, 4, 5),
                    std::make_tuple(std::vector<int>{1,2,3,4,5}, 5, 3)
                ));

int main(int argc, char **argv){
testing::InitGoogleTest(&argc, argv);
return RUN_ALL_TESTS();
}
//DRIVER Code
/*
int main()
{
Sample s;
s.push(10);
s.push(12);
s.push(14);
s.push(16);
s.print();
s.push(18);
cout<<s.countNode()<<endl;
cout<<s.middleElement()<<endl;
return 0;
}
*/
