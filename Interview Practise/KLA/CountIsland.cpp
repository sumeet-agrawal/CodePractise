#include <iostream>
#include <queue>
#include <vector>

int countIslands(std::vector<std::vector<int>>& M)
{
    std::vector<std::vector<int>> dir{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
    int count{};
    int n = M.size();
    std::queue<std::pair<int, int>> q{};
    for(int i{};i<n;++i)
    {
        for(int j{};j<n;++j)
        {
            if(M[i][j]!=1)
                continue;
            q.push({i,j});
            M[i][j] = 2;
            count++;
            while(!q.empty())
            {
                auto t = q.front();
                for(int k{};k<dir.size();++k)
                {
                    int nx{t.first+dir[k][0]}, ny{t.second+dir[k][1]};
                    if(nx<0 || ny<0 || nx>=n || ny>=n || M[nx][ny]!=1)
                        continue;
                    q.push({nx, ny});
                    M[nx][ny] = 2;
                }
                q.pop();
            }
        }
    }
    return count;
}

int main()
{
    std::vector<std::vector<int>> M{ { 1, 1, 0, 0, 0 },
                                     { 0, 1, 0, 0, 1 },
                                     { 1, 0, 0, 1, 1 },
                                     { 0, 0, 0, 0, 0 },
                                     { 1, 0, 1, 0, 1 } };
 
    std::cout << "Number of islands is: " << countIslands(M);
 
    return 0;
}