#include <stdio.h>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

string sa, sb;
vector<pair<int, int> > hash_table[3000089];
int prime1[26] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 
                  47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101};
int prime2[26] = {211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313, 317, 331, 337, 347, 349, 353, 359};
const int mod = 3000089;
int max_length = 0;

void input()
{
	cin >> sa >> sb;
}

void run()
{
	int sa_length = (int)sa.length();
	int hash_value1 = 1, hash_value2 = 1, tmp;
	for(int i = 0; i < sa_length; ++i) {
		for(int j = i; j < sa_length; ++j) {
			tmp = (int)sa[j];
			hash_value1 = (hash_value1 * prime1[sa[j] - 'a']) % mod;
			hash_value2 = (hash_value2 * prime2[sa[j] - 'a']) % mod;		
			hash_table[hash_value1].push_back(make_pair(hash_value2, j - i + 1));
		}
		hash_value1 = 1;
		hash_value2 = 1;
	}

	int sb_length = (int)sb.length(), bucket_size;
	hash_value1 = 1, hash_value2 = 1;
	for(int i = 0; i < sb_length; ++i) {
		for(int j = i; j < sb_length; ++j) {
			tmp = (int)sb[j];
			hash_value1 = (hash_value1 * prime1[sb[j] - 'a']) % mod;
			hash_value2 = (hash_value2 * prime2[sb[j] - 'a']) % mod;
			bucket_size = (int)hash_table[hash_value1].size();
			for(int k = 0; k < bucket_size; ++k) {
				if(hash_table[hash_value1][k].first == hash_value2 && hash_table[hash_value1][k].second == j - i + 1)
					max_length = max(max_length, j - i + 1);
			}
		}
		hash_value1 = 1;
		hash_value2 = 1;
	}

	printf("%d\n", max_length);
}

int main()
{
	input();
	run();
	
	return 0;
}