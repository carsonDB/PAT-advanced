/*
思路：
1. 题目给的是先序遍历，那么给定的第一个是子树的根节点。后面分成两部分，分别为左子树和
右子树。并且检查左子树是否都比根节点小，右子树是否都比根节点大或等于。然后递归检查。同时，
也开始构造tree。
2. 然后再检查镜像子树，方法同上，只是方向相反。
*/
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef struct Node Node;
struct Node {
  int id;
  Node *l, *r;
  Node(int i) :id(i), l(0), r(0) {};
};

int N;
vector<int> ls, ans;

// try to build BST
bool build1(Node*& root, int begin, int end)
{
  int rNum = ls[begin], i;
  root = new Node(rNum);
  for (i = begin+1; i < end && ls[i]<rNum; i++);
  int mid = i;
  for (; i < N; i++)
    if (ls[i] < rNum)
      return false;
  bool lOK = true, rOK = true;
  // build left
  if (mid > begin+1)
    lOK = build1(root->l, begin+1, mid);
  if (mid < end)
    rOK = build1(root->r, mid, end);
  return lOK && rOK;
}

// try to build mirror of BST
bool build2(Node*& root, int begin, int end)
{
  int rNum = ls[begin], i;
  root = new Node(rNum);
  for (i = begin+1; i < end && ls[i] >= rNum; i++);
  int mid = i;
  for (; i < N; i++)
    if (ls[i] >= rNum)
      return false;
  bool lOK = true, rOK = true;
  // build left
  if (mid > begin+1)
    lOK = build2(root->l, begin+1, mid);
  if (mid < end)
    rOK = build2(root->r, mid, end);
  return lOK && rOK;
}

void postTree(Node* root)
{
  if (root->l)
    postTree(root->l);
  if (root->r)
    postTree(root->r);
  ans.push_back(root->id);
}

int main()
{
  // input
  cin >> N;
  ls.resize(N);
  for (int i = 0; i < N; i++)
    cin >> ls[i];
  // assume it is a BST
  Node* root;
  bool isTree = build1(root, 0, ls.size());
  // assume it is a mirror of a BST
  if (!isTree)
    isTree = build2(root, 0, ls.size());
  // output
  if (isTree)
  {
    cout << "YES" << endl;
    postTree(root);
    cout << ans.front();
    for (int i = 1; i < ans.size(); i++)
      printf(" %d", ans[i]);
    cout << endl;
  }
  else
    cout << "NO" << endl;
  return 0;
}
