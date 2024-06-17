#pragma once

/*
convex-hull trick
void add(T a, T b) 直線 ax + b を追加
T get(T x) 最小値を返す
*/
template <typename T>
struct CHT
{
    map<T, T> line, ator, rtoa;
    CHT() {}

    // 傾き l > r で直線 l が直線 r より下にあるのは
    T f(T l, T r)
    {
        // alx + bl <= arx + br
        return (line[r] - line[l]) / (l - r);
    }

    void add(T a, T b)
    {
        // 初めての直線のとき
        if(line.empty())
        {
            line[a] = b, ator[a] = infty<T>, rtoa[infty<T>] = a;
            return;
        }

        // 既に同じ傾きの直線が存在するとき
        if(line.find(a) != line.end()) line[a] = min(line[a], b);
        // 直線 ax + b が必要が判定する
        // もし a が今までの直線で最小値か最大値のときは追加
        else if(a < line.begin()->first || a > line.rbegin()->first) line[a] = b;
        else // それ以外は要確認 al > a > ar
        {
            line[a] = b;
            auto itr = line.find(a);
            if(f(next(itr)->first, a) >= f(a, prev(itr)->first)) { line.erase(a); return; }
        }


        // 直線の追加によって不要になった直線を削除する
        // 左側 all > al > a
        while(1)
        {
            auto itr = line.find(a), itrl = next(itr); if(itrl == line.end()) break;
            auto itrll = next(itrl); if(itrll == line.end()) break;
            if(f(itrll->first, itrl->first) >= f(itrl->first, a))
            {
                T x = itrl->first, y = ator[x];
                line.erase(x), ator.erase(x), rtoa.erase(y);
            }
            else break;
        }
        // 右側 a > ar > arr
        while(1)
        {
            auto itr = line.find(a); if(itr == line.begin()) break;
            auto itrr = prev(itr); if(itrr == line.begin()) break;
            auto itrrr = prev(itrr);
            if(f(a, itrr->first) >= f(itrr->first, itrrr->first))
            {
                T x = itrr->first, y = ator[x];
                line.erase(x), ator.erase(x), rtoa.erase(y);
            }
            else break;
        }

        // 区間を更新する al > a > ar
        auto itr = line.find(a);
        if(next(itr) != line.end())
        {
            T l = next(itr)->first;
            T x = f(l, a); rtoa.erase(ator[l]);
            ator[l] = x, rtoa[x] = l;
        }
        if(itr != line.begin())
        {
            T r = prev(itr)->first;
            T x = f(a, r);
            ator[a] = x, rtoa[x] = a;
        }
        if(itr == line.begin())
        {
            ator[a] = infty<T>, rtoa[infty<T>] = a;
        }
    }

    T get(T x)
    {
        T a = rtoa.lower_bound(x)->second;
        return a * x + line[a];
    }

    void dump()
    {
        cout << "==========line==========" << '\n';
        for(auto [x, y] : line) cout << x << "x + " << y << '\n';
        cout << "==========ator==========" << '\n';
        for(auto [x, y] : ator) cout << x << " : " << y << '\n';
        cout << "==========rtoa==========" << '\n';
        for(auto [x, y] : rtoa) cout << x << " : " << y << '\n';  
        cout << "==========-----END-----==========" << '\n' << '\n';      
    }
};