/*

Reversed Linked List
You are given a linked list that contains  integers. You have performed the following reverse operation on the list:

Select all the subparts of the list that contain only even integers. For example, if the list is , then the selected subparts will be , .
Reverse the selected subpart such as  and .
Now, you are required to retrieve the original list.

Note: You should use the following definition of the linked list for this problem:

class Node {
    Object data;
    Node next;
}
Input format

First line:  
Next line:  space-separated integers that denote elements of the reverse list
Output format

Print the  elements of the original list.

Constraints



SAMPLE INPUT 
9
2 18 24 3 5 7 9 6 12
SAMPLE OUTPUT 
24 18 2 3 5 7 9 12 6
Explanation
In the sample, the original list is  which when reversed according to the operations will result in the list given in the sample input.

Time Limit:	1.0 sec(s) for each input file.
Memory Limit:	256 MB
Source Limit:	1024 KB
Marking Scheme:	Marks are awarded when all the testcases pass.
Allowed Languages:	Bash, C, C++, C++14, Clojure, C#, D, Erlang, F#, Go, Groovy, Haskell, Java, Java 8, JavaScript(Rhino), JavaScript(Node.js), Julia, Kotlin, Lisp, Lisp (SBCL), Lua, Objective-C, OCaml, Octave, Pascal, Perl, PHP, Python, Python 3, R(RScript), Racket, Ruby, Rust, Scala, Swift, Swift-4.1, TypeScript, Visual Basic

*/



#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb(x) push_back(x)
#define sz(x)((int)(x).size())
#define rep(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define all(x)(x).begin(), (x).end()
#define ldb ldouble
#define MAX 1000000007
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<db, db> pdd;

class node
{
	public:
		int data;
	node * next;
	node(ll data)
	{
		this->data = data;
		this->next = NULL;
	}
};

int main()
{
	fast
	ll n;
	cin >> n;
	node *head = NULL;
	node *tail = NULL;
	rep(i, n)
	{
		ll tmp;
		cin >> tmp;
		if (head == NULL)
		{
			head = new node(tmp);
			tail = head;
		}
		else
		{
			tail->next = new node(tmp);
			tail = tail->next;
		}
	}

	node *p = head;
	/*
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}

	cout << "\n";
	*/
	stack<ll> stk;
	p = head;
	node *rhead = NULL;
	node *rtail = NULL;

	while (p != NULL)
	{
		if (!(p->data &1))
		{
			stk.push(p->data);
		}
		else
		{
			while (!stk.empty())
			{
				if (rhead == NULL)
				{
					rhead = new node(stk.top());
					rtail = rhead;
					stk.pop();
				}
				else
				{
					rtail->next = new node(stk.top());
					stk.pop();
					rtail = rtail->next;
				}
			}

			if (rhead == NULL)
			{
				rhead = new node(p->data);
				rtail = rhead;
			}
			else
			{
				rtail->next = new node(p->data);
				rtail = rtail->next;
			}
		}

		p = p->next;
	}

	while (!stk.empty())
	{
		if(rhead==NULL)
		{
			rhead = new node(stk.top());
			stk.pop();
			rtail = rhead;
		}
		else
		{
			rtail->next = new node(stk.top());
			rtail = rtail->next;
			stk.pop();
		}
	}

	p = rhead;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}

	return 0;
}
