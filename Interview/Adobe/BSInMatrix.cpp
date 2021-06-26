#include <iostream>
#include <utility>

#define R 5
#define C 4

int bs_row(int start, int end, int mat[R][C], int num)
{
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	if (mat[mid][0] <= num && mat[mid + 1][0] > num)
	{
		return mid;
	}
	else if (mat[mid][0] > num)
		return bs_row(start, mid - 1, mat, num);
	else
		return bs_row(mid + 1, end, mat, num);
}
int bs_column(int start, int end, int mat[R][C], int num, int r)
{
	if (start == end)
		return start;
	int mid = (start + end) / 2;
	if (mat[r][mid] == num)
		return mid;
	else if (mat[r][mid] < num)
		return bs_column(mid + 1, end, mat, num, r);
	else
		return bs_column(start, mid - 1, mat, num, r);
}
std::pair<int, int> search(int arr[R][C], int num)
{
	int r = bs_row(0, R - 1, arr, num);
	int c = bs_column(0, C - 1, arr, num, r);
	return { r,c };
}

std::ostream& operator<<(std::ostream& out, const std::pair<int, int>& p)
{
	out << p.first << " " << p.second << "\n";
	return out;
}

int main()
{
	int arr[R][C] = {
		{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}, {17, 18, 19, 20}
	};
	std::cout << search(arr, 14) << "\n";
	return 0;
}