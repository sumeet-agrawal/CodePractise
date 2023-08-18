#include <iostream>
#include <vector>
#include <queue>

int minStepToReachTarget(const std::vector<int>& knightPos, const std::vector<int>& targetPos, int N)
{
    std::vector<std::vector<int>> dir{{-2,1}, {-1,2}, {1,2}, {2,1},{2,-1},{1,-2},{-2,-1},{-1,-2}};
    std::vector<std::vector<bool>> vis(N+1, std::vector<bool>(N+1, false));
    std::queue<std::pair<int ,int>> q;
    q.push({knightPos[0], knightPos[1]});
    vis[knightPos[0]][knightPos[1]]=true;
    int cnt{};
    while(!q.empty())
    {
        int n{static_cast<int>(q.size())};
        cnt++;
        while(n--)
        {
            auto t = q.front();
            q.pop();
            for(int i{};i<dir.size();i++)
            {
                int nx{t.first+dir[i][0]}, ny{t.second+dir[i][1]};
                if(nx<1 || ny<1 || nx>N || ny>N || vis[nx][ny])
                    continue;
                if(nx==targetPos[0] && ny==targetPos[1])
                    return cnt;
                q.push({nx,ny});
                vis[nx][ny] = true;
            }
        }
    }
    return -1;
}

int main()
{
    int N = 30;
    std::vector<int> knightPos{ 1, 1 };
    std::vector<int> targetPos{ 30, 30 };
 
    // Function call
    std::cout << minStepToReachTarget(knightPos, targetPos, N);
    return 0;
}