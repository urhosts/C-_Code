/*************************************************************************
	> File Name: GetTop.h
	> Author: hosts
	> Mail: hosts@gsxio.com
	> Created Time: Wed 28 Jun 2017 10:40:28 PM CST
 ************************************************************************/

#ifndef _GETTOP_H
#define _GETTOP_H

#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;

struct Max
{
    bool operator()(pair<string, int> p1, pair<string, int> p2)
    {
        return p1.second > p2.second;
    }
};

void GetTopFruits(vector<string>& fruits)
{
    map<string, int> countMap;
    map<string, int>::iterator countMapIt;

    for(size_t i = 0; i < fruits.size(); ++i)
    {
        countMapIt = countMap.find(fruits[i]);
        if(countMapIt != countMap.end())
        {
            countMapIt->second++;
        }
        else
        {
            countMap.insert(pair<string, int> (fruits[i], 1));
        }
    }

    vector< pair<string, int> > vec;
    vec.insert(vec.begin(), countMap.begin(), countMap.end());

    make_heap(vec.begin(), vec.end(), Max());
    sort_heap(vec.begin(), vec.end(), Max());

    for(size_t i = 0; i < vec.size(); ++i)
    {
        cout<<vec[i].first<<":"<<vec[i].second<<endl;
    }
}

void TestFruitMap()
{
    vector<string> vec;
    vec.push_back("苹果");
    vec.push_back("苹果");
    vec.push_back("西瓜");
    vec.push_back("苹果");
    vec.push_back("草莓");
    vec.push_back("草莓");
    vec.push_back("草莓");
    vec.push_back("草莓");
    vec.push_back("草莓");
    vec.push_back("草莓");
    vec.push_back("香蕉");
    vec.push_back("香蕉");
    GetTopFruits(vec);
}

#endif
