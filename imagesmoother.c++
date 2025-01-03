class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<vector<int>> ans(m, vector<int>(n, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int sum = img[i][j];
                int count = 9; // Start with 9 possible neighbors

                // Top
                if (i - 1 < 0) {
                    count--;
                } else {
                    sum += img[i - 1][j];
                }

                // Down
                if (i + 1 >= m) {
                    count--;
                } else {
                    sum += img[i + 1][j];
                }

                // Left
                if (j - 1 < 0) {
                    count--;
                } else {
                    sum += img[i][j - 1];
                }

                // Right
                if (j + 1 >= n) {
                    count--;
                } else {
                    sum += img[i][j + 1];
                }

                // Top Left
                if (i - 1 < 0 || j - 1 < 0) {
                    count--;
                } else {
                    sum += img[i - 1][j - 1];
                }

                // Top Right
                if (i - 1 < 0 || j + 1 >= n) {
                    count--;
                } else {
                    sum += img[i - 1][j + 1];
                }

                // Down Left
                if (i + 1 >= m || j - 1 < 0) {
                    count--;
                } else {
                    sum += img[i + 1][j - 1];
                }

                // Down Right
                if (i + 1 >= m || j + 1 >= n) {
                    count--;
                } else {
                    sum += img[i + 1][j + 1];
                }

                // Calculate average
                ans[i][j] = sum / count;
            }
        }

        return ans;
    }
};
