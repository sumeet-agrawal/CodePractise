#include <iostream>
#include <vector>
#include <queue>

int countdfs(std::vector<std::vector<int>>& M, const std::vector<std::vector<int>>& dir, int i, int j)
{
    std::queue<std::pair<int ,int>> q{};
    q.push({i,j});
    M[i][j] = 2;
    int cnt{1};
    while(!q.empty())
    {
        auto t = q.front();
        for(const auto &x: dir)
        {
            int nx{t.first + x[0]}, ny{t.second + x[1]};
            if(nx<0 || ny<0 || nx>=M.size() || ny>=M[nx].size() || M[nx][ny]!=1)
                continue;
            M[nx][ny] = 2;
            cnt++;
            q.push({nx,ny});
        }
        q.pop();
    }
    return cnt;
}

int largestRegion(std::vector<std::vector<int>>& M)
{
    std::vector<std::vector<int>> dir{{-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}, {-1,-1}};
    int ans{INT_MIN};
    for(int i{};i<M.size();++i)
    {
        for(int j{};j<M[i].size();++j)
        {
            if(M[i][j] != 1)
                continue;
            int cnt{countdfs(M, dir, i, j)};
            ans = std::max(ans, cnt);
        }
    }
    return ans;
}

int main()
{
    std::vector<std::vector<int>> M{ { 0, 0, 1, 1, 0 },
                                     { 1, 0, 1, 1, 0 },
                                     { 0, 1, 0, 0, 0 },
                                     { 0, 0, 0, 0, 1 } };
 
    // Function call
    std::cout << largestRegion(M);
 
    return 0;
}